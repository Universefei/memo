Code Fold
=========


# references:
* [vim保存折叠信息的方法](http://techbbs.zol.com.cn/1/60_1387.html)

```
vim里有一项功能是折叠，你可以将大段文本进行折叠从而使整个文件的结构看起来很清晰，vim常用的折叠命令如下：
zf:折叠选定的行
zo:打开折叠
zR:打开所有折叠
zM:关闭所有折叠
zd:删除折叠
更多关于折叠的命令，可以通过:help zf找到
起初困扰新手的一个问题是，你打开了一个文件，做了很多折叠然后关闭文件，再次打开之后这些折叠信息都不见了，很令人恼火吧。
其实只需要在关闭之前用:mkview保存当前的view即可，下次打开文件之后用:loadview即可恢复你之前做过的折叠记录。当你敲下:mkview之后，view实际会在你home目录下.vim/view/目录下保存信息，例如下面这个文件：
-rw-rw-r-- 1 leconte leconte 2591 03-01 16:24 /home/leconte/.vim/view/~=+a.php=
如果你查看这个文件的话会发现里面不仅保存有折叠信息，而且还有当前vim环境下的很多变量值，说白了就是你当前的vim工作环境。
但是每次都要手工执行:mkview和:loadview仍然是一个很繁琐的操作，你可以在.vimrc中进行如下配置：
au BufWinLeave * silent mkview
au BufWinEnter * silent loadview
这样以来在每次文件关闭的时候都会自动执行:mkview，而每次文件打开的时候都会自动执行:loadview。
```
