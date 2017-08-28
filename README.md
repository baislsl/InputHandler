# InputHandler
A terminal IO, solving Tab, Shift, Ctrl

### 
读入esc时， 冲洗缓冲区到



Buffer -> input buffer缓冲区
    当前字段
    选中字段

Terminal ->
 

 InputEngine -> 读入引擎

- Tab -> 在当前目录下搜索输入字段开头的文件名并补全
- 方向左/右 -> 移动光标
- Ctrl+ 左/右 -> 以单词为单位移动光标
- Shift -> 选/解选中字段
- Home/End -> 跳到开头和末尾

---------------------------------

' 和 " 关闭后输入回车键才会冲洗缓冲区
Ctrl + c/v 复制粘贴


