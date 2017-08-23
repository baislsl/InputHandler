

#include <termios.h>
#include <zconf.h>
#include <stdexcept>
#include <fcntl.h>
#include "InputEngine.h"
#include <error.h>

InputEngine::InputEngine() {

}

InputEngine::~InputEngine() {

}

int InputEngine::open() {
    if(ttyRaw(STDIN_FILENO) != 0)
        return 1;
    return 0;
}


int InputEngine::close() {
    if(ttyReset(STDIN_FILENO) != 0)
        return 1;
    return 0;
}

KeyCode InputEngine::next() {
    if(!isRunning())
        throw std::runtime_error("Can not read while the input engine is not open");
    char cc;
    if(read(STDIN_FILENO, &cc, 1) == -1){
        throw std::runtime_error("Error when read from stdin");
    }
    char input[MAX_INPUT];
    size_t inputIndex = 0;
    switch (cc){
        case 033: // Esc
            setNoBlock();

            input[inputIndex++] = cc;

            while(read(STDIN_FILENO, &cc, 1) == 1){
                input[inputIndex++] = cc;
            }
            input[inputIndex] = 0;

            resetNoBlock();

            return KeyCode(input);

        default:
            return KeyCode(cc);
    }

}

void InputEngine::flush() {

}

int InputEngine::ttyRaw(int fd) {
    int				err;
    struct termios	buf;

    if (ttystate != RESET) {
        errno = EINVAL;
        return(-1);
    }
    if (tcgetattr(fd, &buf) < 0)
        return(-1);
    save_termios = buf;	/* structure copy */

    /*
     * Echo off, canonical mode off, extended input
     * processing off, signal chars off.
     */
    buf.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);

    /*
     * No SIGINT on BREAK, CR-to-NL off, input parity
     * check off, don't strip 8th bit on input, output
     * flow control off.
     */
    buf.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);

    /*
     * Clear size bits, parity checking off.
     */
    buf.c_cflag &= ~(CSIZE | PARENB);

    /*
     * Set 8 bits/char.
     */
    buf.c_cflag |= CS8;

    /*
     * Output processing off.
     */
    buf.c_oflag &= ~(OPOST);

    /*
     * Case B: 1 byte at a time, no timer.
     */
    buf.c_cc[VMIN] = 1;
    buf.c_cc[VTIME] = 0;
    if (tcsetattr(fd, TCSAFLUSH, &buf) < 0)
        return(-1);

    /*
     * Verify that the changes stuck.  tcsetattr can return 0 on
     * partial success.
     */
    if (tcgetattr(fd, &buf) < 0) {
        err = errno;
        tcsetattr(fd, TCSAFLUSH, &save_termios);
        errno = err;
        return(-1);
    }
    if ((buf.c_lflag & (ECHO | ICANON | IEXTEN | ISIG)) ||
        (buf.c_iflag & (BRKINT | ICRNL | INPCK | ISTRIP | IXON)) ||
        (buf.c_cflag & (CSIZE | PARENB | CS8)) != CS8 ||
        (buf.c_oflag & OPOST) || buf.c_cc[VMIN] != 1 ||
        buf.c_cc[VTIME] != 0) {
        /*
         * Only some of the changes were made.  Restore the
         * original settings.
         */
        tcsetattr(fd, TCSAFLUSH, &save_termios);
        errno = EINVAL;
        return(-1);
    }

    ttystate = RAW;
    ttysavefd = fd;
    return(0);
}

int InputEngine::ttyReset(int fd) {
    if (ttystate == RESET)
        return(0);
    if (tcsetattr(fd, TCSAFLUSH, &save_termios) < 0)
        return(-1);
    ttystate = RESET;
    return(0);
}

bool InputEngine::isRunning() {
    return ttystate != RESET;
}

int InputEngine::setNoBlock() {
    int flag = fcntl(STDIN_FILENO, F_GETFL);
    return fcntl(STDIN_FILENO, F_SETFL, flag | O_NONBLOCK);
}


int InputEngine::resetNoBlock() {
    int flag = fcntl(STDIN_FILENO, F_GETFL);
    return fcntl(STDIN_FILENO, F_SETFL, flag & ~O_NONBLOCK);
}







