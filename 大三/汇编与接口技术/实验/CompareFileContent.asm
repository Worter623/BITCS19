.386
.model flat,stdcall
option casemap:none

include masm32rt.inc
includelib masm32rt.lib
includelib user32.lib
includelib kernel32.lib
includelib gdi32.lib
includelib Comdlg32.lib
includelib msvcrt.lib

include windows.inc
include user32.inc
include kernel32.inc
include gdi32.inc
include Comdlg32.inc
include	msvcrt.inc

sprintf	PROTO C :ptr sbyte, :ptr sbyte, :VARARG

.data
_processHandle	DD	?							;EXE句柄
_appClassName	DB	'CompareFileClass',0		;注册窗口类名字
screenHandle	DD	?							;屏幕句柄，用于画图
Button			DB	'button',0
_windowHandle	DD	?							;程序主窗口句柄
DiffNum			DD	?							;不一样的行数量
Difference		DB	2000 dup(0)					;不一样的行
FileName1		DB	MAX_PATH	dup(?)
FileName2		DB	MAX_PATH	dup(?)
Buffer1			DB	1024 dup(?)
Buffer2			DB	1024 dup(?)
Chose1			DB	0
Chose2			DB	0
;--------------提示消息-------------
AppCaption		DB	'Compare2Files!',0			;窗口标题
Button1Text		DB	'Choose File1',0
Button2Text		DB	'Choose File2',0
Button3Text		DB	'Begin Comparation',0
CompareTitle	DB	'Comparation Result',0
SameContentHint	DB	'There is no different line between two files!', 0
MyFilter		DB	'Text Files(*.txt) ',0,'*.txt',0
				DB	'Doc Files(*.doc) ',0,'*.doc',0
				DB	'Docx Files(*.docx) ',0,'*.docx',0,0
FileChosenHint	DB	'You have chosen the file:',0
DifferenceHint	DB	'Different line: %d',0AH,0
TextNotChosen	DB	'Empty'
TextChosen		DB	'                      ',0
;--------------提示消息-------------


.code
;-----------------使用文件句柄读一行---------------------
ReadOneLine	proc	uses EBX,filehandle:HANDLE,buffer:PTR	BYTE
	LOCAL	fileptr:		DWORD					;
	LOCAL	input_char:		BYTE					;读入数据

	MOV		EBX,buffer
	.while TRUE
		invoke	ReadFile,filehandle,addr	input_char,1,addr	fileptr,NULL
		.break	.if	!fileptr
		.break	.if	input_char==10

		MOV		AL,input_char						;循环将读入的字符传进buffer
		MOV		[EBX],AL
		INC		EBX
	.endw

	MOV		AL,0									;最后一位0
	MOV		[EBX],AL
	invoke	lstrlen,buffer							;调用strlen，结果存到eax中并返回
	ret

ReadOneLine	endp
;-----------------使用文件句柄读一行---------------------

;-----------------文件比较---------------------
CompareFile	proc
	LOCAL	filehandle1:	HANDLE					;文件句柄
	LOCAL	filehandle2:	HANDLE
	LOCAL	ptr1:			DWORD					;文件指针
	LOCAL	ptr2:			DWORD
	LOCAL	_line:			DWORD					;行数
	LOCAL	differenceline[1000]:	BYTE			

	MOV		_line,0									;初始化并获得文件句柄
	MOV		DiffNum,0								
	invoke	CreateFile,offset	FileName1,GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL
	MOV		filehandle1,EAX
	invoke	CreateFile,offset	FileName2,GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL
	MOV		filehandle2,EAX

READ_LINE_START:
	INC		_line
	invoke	RtlZeroMemory,offset	Buffer1,sizeof	Buffer1
	invoke	ReadOneLine,filehandle1,offset	Buffer1
	MOV		ptr1,EAX								;长度存于EAX
	invoke	RtlZeroMemory,offset	Buffer2,sizeof	Buffer2
	invoke	ReadOneLine,filehandle2,offset	Buffer2
	MOV		ptr2,EAX								;长度存于EAX

	CMP		ptr1,0									;ptr1=0,已读到文件结束
	JNE		FILE1_NOT_EMPTY
	CMP		ptr2,0									;两个文件都读完，结束循环
	JE		COMPARE_END
	JMP		DIFFERENCE_LINE_EXIST

FILE1_NOT_EMPTY:									;文件1 2如果不为空，就用strcmp比较
	CMP		ptr2,0
	JNE		BOTH_NOT_EMPTY
	JMP		DIFFERENCE_LINE_EXIST

BOTH_NOT_EMPTY:
	invoke	lstrcmp,offset	Buffer1,offset Buffer2
	CMP		EAX,0
	JE		READ_LINE_START
	JMP		DIFFERENCE_LINE_EXIST

COMPARE_END:
	invoke	CloseHandle,filehandle1
	invoke	CloseHandle,filehandle2
	ret

DIFFERENCE_LINE_EXIST:								;两行不同，打印行号
	invoke	sprintf,addr	differenceline,offset	DifferenceHint,_line
	invoke	lstrcat,addr	Difference,addr	differenceline
	INC		DiffNum
	JMP		READ_LINE_START
CompareFile	endp
;-----------------文件比较---------------------

;-----------------打开文件选择窗口---------------------
_OpenFile	proc	flag:dword
	LOCAL	filehandle:OPENFILENAME					;要打开的文件名

	invoke	RtlZeroMemory,addr filehandle,sizeof filehandle
	MOV		filehandle.lStructSize,sizeof filehandle;初始化文件句柄
	PUSH	_windowHandle
	POP		filehandle.hwndOwner
	MOV		filehandle.lpstrFilter,offset	MyFilter

	MOV		EAX,flag								;通过flag标记打开的是文件1/2
	CMP		EAX,1
	JNE		FILE_NOT_1
	MOV		filehandle.lpstrFile,offset	FileName1
	JMP		MARK_FILE_DONE
FILE_NOT_1:
	MOV		EAX,flag
	CMP		EAX,2
	JNE		MARK_FILE_DONE
	MOV		filehandle.lpstrFile,offset	FileName2
MARK_FILE_DONE:
	MOV		filehandle.nMaxFile,MAX_PATH
	MOV		filehandle.Flags,OFN_FILEMUSTEXIST OR OFN_PATHMUSTEXIST

	invoke	GetOpenFileName,addr filehandle			;打开一个窗口选择文件
	CMP		EAX,1
	JNE		OPEN_FILE_END
	MOV		EAX,flag
	CMP		EAX,1
	JNE		NOT_1
	invoke	MessageBox,_windowHandle,offset FileName1,\
			offset FileChosenHint,MB_OK
	JMP		OPEN_FILE_END
NOT_1:
	invoke	MessageBox,_windowHandle,offset FileName2,\
			offset FileChosenHint,MB_OK
OPEN_FILE_END:
	ret
_OpenFile	endp
;-----------------打开文件选择窗口---------------------


;-----------------程序主窗口的消息处理窗口过程函数---------------------
_ProcWinMain proc uses ebx edi esi,hWnd:HWND,uMsg:UINT,wParam:WPARAM,lParam:LPARAM
    LOCAL	PaintInfo:	PAINTSTRUCT
	LOCAL	hDc:		HDC

	MOV		EAX,uMsg								;uMsg消息类型
	.if		EAX == WM_PAINT
		invoke	BeginPaint,hWnd,addr PaintInfo		;绘制窗口
		MOV		hDc,EAX
		MOV		screenHandle,EAX
		invoke	TextOut,hDc,250,15,addr TextNotChosen,5
		invoke	TextOut,hDc,250,55,addr TextNotChosen,5
		invoke	EndPaint,hWnd,addr PaintInfo
	.elseif	EAX == WM_CLOSE
		invoke	DestroyWindow,_windowHandle			;关闭窗口
		invoke	PostQuitMessage,NULL
	.elseif	EAX == WM_CREATE						;创建窗口，3个按钮赋句柄
		invoke CreateWindowEx,NULL,offset Button,offset Button1Text,\
			WS_CHILD or WS_VISIBLE,10,10,200,30,\ 
			hWnd,1,_processHandle,NULL				;1表示该按钮的句柄是1
		invoke CreateWindowEx,NULL,offset Button,offset Button2Text,\
			WS_CHILD or WS_VISIBLE,10,50,200,30,\  
			hWnd,2,_processHandle,NULL
		invoke CreateWindowEx,NULL,offset Button,offset Button3Text,\
			WS_CHILD or WS_VISIBLE,10,90,200,30,\ 
			hWnd,3,_processHandle,NULL
	.elseif	EAX == WM_COMMAND						;点击事件
		MOV		EAX,wParam							;如果点击按钮，wParam是按钮句柄
		.if	EAX == 1
			invoke	_OpenFile,1
			invoke	GetDC, hWnd
			MOV		Chose1,1
			MOV		hDc,EAX
			invoke	TextOut,hDc,250,15,addr TextChosen,13
			invoke	TextOut,hDc,250,15,addr FileName1,30
			.if		Chose2 == 1
				invoke	TextOut,hDc,250,55,addr TextChosen,13
				invoke	TextOut,hDc,250,55,addr FileName2,30
			.else
				invoke	TextOut,hDc,250,55,addr TextNotChosen,5
			.endif
			invoke	ReleaseDC, hWnd, hDc 
		.elseif	EAX == 2
			invoke	_OpenFile,2
			invoke	GetDC, hWnd
			MOV		Chose2,1
			MOV		hDc,EAX
			invoke	TextOut,hDc,250,55,addr TextChosen,13
			invoke	TextOut,hDc,250,55,addr FileName2,30
			.if		Chose1 == 1
				invoke	TextOut,hDc,250,15,addr TextChosen,13
				invoke	TextOut,hDc,250,15,addr FileName1,30
			.else
				invoke	TextOut,hDc,250,15,addr TextNotChosen,5
			.endif
			invoke	ReleaseDC, hWnd, hDc 
		.elseif	EAX == 3
			invoke	CompareFile
			.if	DiffNum == 0
				invoke	MessageBox,hWnd,offset SameContentHint,offset CompareTitle,MB_OK+MB_ICONQUESTION
			.else
				invoke	MessageBox,hWnd,offset Difference,offset CompareTitle,MB_OK+MB_ICONQUESTION
				invoke	RtlZeroMemory,addr Difference,sizeof Difference
			.endif
		.endif
	.else											;默认方式处理
		invoke DefWindowProc,hWnd,uMsg,wParam,lParam
		ret
	.endif

	XOR		EAX,EAX
	ret	
_ProcWinMain endp
;-----------------程序主窗口的消息处理窗口过程函数---------------------

;-----------------打开一个windows风格的程序主窗口---------------------
_WinMain	proc	C
	LOCAL	_windowsClass:	WNDCLASSEX				;窗口类 定义主要属性 eg图标 光标 背景色
	LOCAL	_windowsMsg:	MSG						;窗口类传递消息的结构体

	invoke	GetModuleHandle,NULL					;获取当前exe句柄，存于eax
	MOV		_processHandle,EAX

	invoke	RtlZeroMemory,addr _windowsClass,sizeof _windowsClass  ;初始化全0
	invoke	LoadCursor,0,IDC_ARROW
	MOV		_windowsClass.hCursor,EAX
	PUSH	_processHandle
	POP		_windowsClass.hInstance
	MOV		_windowsClass.cbSize,sizeof	WNDCLASSEX
	MOV		_windowsClass.style,CS_HREDRAW or CS_VREDRAW
	MOV		_windowsClass.lpfnWndProc,offset	_ProcWinMain	;SengMessage(hWnd,uMsg,wParam,lParam)
	MOV		_windowsClass.hbrBackground,COLOR_WINDOW+1
	MOV		_windowsClass.lpszClassName,offset	_appClassName
	invoke	RegisterClassEx,addr	_windowsClass	;注册窗口类

	invoke	CreateWindowEx,WS_EX_CLIENTEDGE,\		;新建窗口，句柄放eax
			offset _appClassName,offset AppCaption,\ ;注册类  窗口名称/button（按钮）
			WS_OVERLAPPEDWINDOW,100,100,600,180,\	;左上角xy坐标+宽+长
			NULL,NULL,_processHandle,NULL		
	MOV		_windowHandle,EAX
	invoke	ShowWindow,_windowHandle,SW_SHOWNORMAL	;显示窗口
	invoke	UpdateWindow,_windowHandle				;刷新窗口
		
APP_PROCESS_MESSAGE:								;循环消息队列处理消息
	invoke	GetMessage,addr _windowsMsg,NULL,0,0	;从消息队列中取消息
	CMP		EAX,0									;退出消息则EAX=0
	JE		APP_END
	invoke	TranslateMessage,addr _windowsMsg		;把基于键盘扫描码的按键信息转换成对应的ASCII码，如果消息不是通过键盘输入的这步无效
	invoke	DispatchMessage,addr _windowsMsg		;找到该窗口程序的窗口过程，处理消息
	JMP		APP_PROCESS_MESSAGE
APP_END:
	ret
_WinMain endp
;-----------------打开一个windows风格的程序主窗口---------------------

;----------------------主函数------------------------------
main proc
	CALL	_WinMain
	invoke	ExitProcess,NULL
	ret
main	endp
end	main
;----------------------主函数------------------------------