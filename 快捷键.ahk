#NoEnv  ; Recommended for performance and compatibility with future AutoHotkey releases.
; #Warn  ; Enable warnings to assist with detecting common errors.
SendMode Input  ; Recommended for new scripts due to its superior speed and reliability.
SetWorkingDir %A_ScriptDir%  ; Ensures a consistent starting directory.

^m::    ;;^+m 最小化当前窗口					
WinMinimize,A    ;;最小化当前窗口		
return	   ;;结束代码段

!k::   ;; !->alt键   k->字母键k
Send {Up}   ;;输入 上 键
return
!j::
Send {Down}
return
!h::
Send {Left}
return
!l::
Send {Right}
return

;;;;;;;;;;;;;删除一整行
!d::   ;alt+d
Send {Home}   ;输出回车
Send +{End}   ;输入shitf键+end键
Send {delete}	;输入delete键
return 
;;;;;;;;;;;;;复制一整行
!y::
send {home}
send +{end}
send ^c   ;输出ctrl+c,复制一整行
return
;;;;;;;;;;;;;另起一行粘贴内容																	
!p::																						
send {end}																					
send {enter}																				
send %clipboard%	;将剪贴板的内容输出													
return

;;;;;;;;;;;;跳转行首行尾
!a::
send {home}
return
!e::
send {end}
return
