.386
.model flat,stdcall
option casemap:none

includelib  shell32.lib
includelib  user32.lib
includelib  masm32.lib
includelib  comctl32.lib
includelib  kernel32.lib
includelib  msvcrt.lib
includelib gdi32.lib

include  windows.inc
include  masm32.inc
include  shell32.inc
include  user32.inc
include  comctl32.inc
include  kernel32.inc
include	msvcrt.inc
include gdi32.inc

strcat   PROTO C :ptr sbyte,:ptr sbyte

;界面常量
handleButton0	EQU		0
handleButton1	EQU		1
handleButton2	EQU		2
handleButton3	EQU		3
handleButton4	EQU		4
handleButton5	EQU		5
handleButton6	EQU		6
handleButton7	EQU		7
handleButton8	EQU		8
handleButton9	EQU		9
handleButtonEqu	EQU		10
handleButtonPlus	EQU		11
handleButtonSub		EQU		12
handleButtonMul		EQU		13
handleButtonDiv		EQU		14
handleButtonRight	EQU		15
handleButtonNeg		EQU		16
handleButtonAC		EQU		17
handleButtonSin		EQU		18
handleButtonCos		EQU		19
handleButtonTan		EQU		20
handleButtonLeft	EQU		21
handleButtonDot		EQU		22
handleTextExpression	EQU		23
handleTextResult		EQU		24

.data
     
_windowHandle   DD   ?		            ;程序主窗口句柄
_processHandle  DD   ?                  ;EXE句柄
screenHandle	DD	?					;屏幕句柄，用于画图

isLeft			DD	0 ;是否是当前域的最左数
isStartNum		DB	0;是否开始输入数字
isStart			DB 0 ;是否开始显示
isFloat			DD	0 ;是否是浮点数
isNeg			DD 0 ;是否是负数
curNum			DD	0;当前域的数字数量
tempNum			DD 0
curOp			DD 0 ;当前运算符

optStack		DD 200 dup(0)			;符号栈
opIndex			DD 0					;符号栈下标
numStack		REAL4 50 DUP(0.)		;数字栈   
numIndex		DD 0;数字栈下标

numStrExpression	DB 40 DUP(0) 
numStrResult		DB "0",0,40 DUP(0)

ProgramName     DB  'gxy的计算器',0     ;标题名
_appClassName   DB  'Calculate',0       ;窗口类名
Button			DB	'button',0
Static			DB	'static',0

expressionText	DB	'0',0
resultText		DB	'0',0
equText			DB	'=',0
button0Text		DB	'0',0
button1Text		DB	'1',0
button2Text		DB	'2',0
button3Text		DB	'3',0
button4Text		DB	'4',0
button5Text		DB	'5',0
button6Text		DB	'6',0
button7Text		DB	'7',0
button8Text		DB	'8',0
button9Text		DB	'9',0
buttonPlusText		DB	'+',0
buttonSubText		DB	'-',0
buttonMulText		DB	'*',0
buttonDivText		DB	'/',0
buttonDotText		DB	'.',0
buttonNegText		DB	'+/ -',0
buttonSinText		DB	'sin',0
buttonCosText		DB	'cos',0
buttonTanText		DB	'tan',0
buttonACText		DB	'AC',0
buttonLeftText		DB	'(',0
buttonRightText		DB	')',0
sinText         DB  'sin(',0
cosText         DB  'cos(',0
tanText         DB  'tan(',0

ten				QWORD	10.
dot				QWORD	0.1
tempDot			QWORD	1.			;当前浮点数字的阶
initDot			QWORD	1.
res				real8	?			;临时存储浮点数
op1				real8 ?;临时存储浮点数
op2				real8 ?;临时存储浮点数
.code
;-----------------按下数字键0-9处理---------------------
pressNum	proc	hWnd:HWND,num:DWORD
	XOR		EAX,EAX
	MOV		isLeft,1
	.if	isStartNum == 0
			fldz
			MOV		isStartNum,1
			MOV		EAX,curNum
			INC		EAX
			MOV		curNum,EAX				;数字计数+1
	.endif
	.if	isFloat == 0
			fld		ten						;st[0] = 10
			fmul							;st[0] = st[1]*10
			fild	num						;st[0] = num
			MOV		tempNum,handleButton0
			fisub	tempNum					;st[0] = 当前数
			;fmul							;st[0]=st[0]*当前小数阶
			.if		isNeg == 1
				fchs						;若当前数为负数，st[0]=-st[0]
			.endif
			fadd							;st[0]=st[1]+st[0]
	.else
			fld		tempDot
			fmul	dot
			fst		tempDot
			fild	num
			MOV		tempNum,handleButton0
			fisub	tempNum
			fmul
			.if		isNeg == 1
					fchs
			.endif
			fadd
	.endif
	MOV		EAX,num							;当前数字符显示
	SUB		EAX,handleButton0
	ADD		EAX,'0'
	LEA		ESI,numStrResult
	.if		isStart == 1
			.while	BYTE	PTR[ESI] != 0
					INC		ESI
			.endw
	.else
			MOV		isStart,1
	.endif
	MOV		[ESI],AL
	MOV		BYTE	PTR[ESI+1],0
	invoke	SetDlgItemText,hWnd,handleTextResult,addr numStrResult
	ret
pressNum	endp
;-----------------按下数字键0-9处理---------------------


;-----------------按下AC处理---------------------
initAC	proc	
	MOV		isStart,0
	MOV		isLeft,0
	MOV		isStartNum,0
	MOV		opIndex,0
	MOV		numIndex,0
	MOV		curNum,0

	MOV		[optStack],0
	MOV		ESI,199
	.while	ESI != 1
			MOV		[optStack+ESI*4],0
			DEC		ESI
	.endw
	MOV		[optStack+ESI*4],0

	MOV		ESI,49
	.while	ESI != 1
			MOV		[numStack+ESI*4],0
			DEC		ESI
	.endw
	MOV		[numStack+ESI*4],0
	
	XOR		ESI,ESI
	XOR		EAX,EAX
	XOR		EDI,EDI
	fld		initDot
	fstp	tempDot
	finit
	MOV		[numStrExpression],0
	MOV		[numStrResult],0
	MOV		isNeg,0
	MOV		isFloat,0
	fldz
	ret
initAC	endp
;-----------------按下AC处理---------------------

;-----------------按下加减乘除等于号右括号的处理---------------------
pressOp	proc	hWnd:HWND,num:DWORD
	LOCAL	flag:Byte

	MOV		flag,0
	invoke	strcat,addr	numStrExpression,addr numStrResult
	MOV		isFloat,0
	MOV		isNeg,0
	MOV		isStartNum,0
	MOV		ESI,opIndex
	MOV		EAX,[optStack+ESI*4]
	MOV		curOp,EAX							;获取上一个运算符
	.if		curOp == 0							;前面没有运算符，当前获取符号存入符号栈
			XOR		EAX,EAX
			.if		num == handleButtonPlus
					MOV		EAX,'+'
					MOV		ESI,opIndex
					MOV		[optStack+ESI*4],1
			.elseif	num == handleButtonSub
					MOV		EAX,'-'
					MOV		ESI,opIndex
					MOV		[optStack+ESI*4],2
			.elseif	num == handleButtonMul
					MOV		EAX,'*'
					MOV		ESI,opIndex
					MOV		[optStack+ESI*4],3
			.elseif	num == handleButtonDiv
					MOV		EAX,'/'
					MOV		ESI,opIndex
					MOV		[optStack+ESI*4],4
			.endif
			LEA		ESI,numStrExpression		;符号添加到文本框
			.if		isStart == 1
					.while	BYTE	PTR[ESI] != 0
							INC		ESI
					.endw
			.else
					MOV		isStart,1
			.endif
			MOV		[ESI],AL
			MOV		BYTE	PTR[ESI+1],0
			MOV		isStart,0
	.elseif	(curOp == 1)||(curOp == 2)			;加减
			.if	(num == handleButtonPlus)||(num == handleButtonSub)
				.if		num == handleButtonPlus
					MOV		EAX,'+'
					MOV		ESI,opIndex
					MOV		[optStack+ESI*4],1
				.elseif	num == handleButtonSub
					MOV		EAX,'-'
					MOV		ESI,opIndex
					MOV		[optStack+ESI*4],2
				.endif
				LEA		ESI,numStrExpression
				.if		isStart == 1
						.while	BYTE	PTR[ESI] != 0
								INC		ESI
						.endw
				.else
						MOV		isStart,1
				.endif
				MOV		[ESI],AL
				MOV		BYTE	PTR[ESI+1],0
				fst		res						;执行操作
				.if		curOp == 1
						fadd
				.else
						fsub
				.endif
				MOV		EAX,curNum
				DEC		EAX
				MOV		curNum,EAX
				fst		res
				invoke	FloatToStr,res,addr	numStrResult
				invoke	SetDlgItemText,hWnd,handleTextResult,addr numStrResult
				MOV		isStart,0
			.elseif	(num == handleButtonMul)||(num == handleButtonDiv)
				.if		num == handleButtonMul
					MOV		EAX,'*'
					MOV		ESI,opIndex
					INC		ESI
					MOV		opIndex,ESI
					MOV		[optStack+ESI*4],3
				.elseif	num == handleButtonDiv
					MOV		EAX,'/'
					MOV		ESI,opIndex
					INC		ESI
					MOV		opIndex,ESI
					MOV		[optStack+ESI*4],4
				.endif				
				LEA		ESI,numStrExpression
				.if		isStart == 1
						.while	BYTE	PTR[ESI] != 0
								INC		ESI
						.endw
				.else
						MOV		isStart,1
				.endif
				MOV		[ESI],AL
				MOV		BYTE	PTR[ESI+1],0
				MOV		isStart,0
			.elseif	num == handleButtonEqu
				.if		curOp == 1
					fadd
				.else
					fsub
				.endif
				MOV		EAX,curNum
				DEC		EAX
				MOV		curNum,EAX
				fst		res
				invoke	FloatToStr,res,addr	numStrResult
				invoke	SetDlgItemText,hWnd,handleTextResult,addr numStrResult
				invoke	SetDlgItemText,hWnd,handleTextExpression,addr numStrExpression
				invoke	initAC
				MOV		flag,1
			.elseif	num == handleButtonRight
				.if		curOp ==1
						fadd
				.else
						fsub
				.endif
				MOV		EAX,curNum
				DEC		EAX
				MOV		curNum,EAX
				fst		res
				invoke	FloatToStr,res,addr	numStrResult
				invoke	SetDlgItemText,hWnd,handleTextResult,addr numStrResult
				MOV		ESI,opIndex
				DEC		ESI
				MOV		EAX,[optStack+ESI*4]
				MOV		curNum,EAX			
				.if		EAX == 2
						MOV		EDI,numIndex
						fstp	res
						DEC		EDI
						fld		[numStack+EDI*4]
						fst		op1
						DEC		EDI
						fld		[numStack+EDI*4]
						fst		op1
						fld		res
						MOV		numIndex,EDI
				.elseif	EAX == 1
						MOV		EDI,opIndex
						DEC		EDI
						fstp	res
						fld		[numStack+EDI*4]
						fst		op1
						fld		res
						MOV		numIndex,EDI
				.endif
				INC		EAX
				MOV		curNum,EAX
				DEC		ESI
				MOV		opIndex,ESI
				invoke	strcat,addr	numStrExpression,addr	buttonRightText
				MOV		[numStrResult],0
			.endif
		.elseif	(curOp == 3)||(curOp == 4)
			.if	(num == handleButtonMul)||(num == handleButtonDiv)
				.if		num == handleButtonMul
					MOV		EAX,'*'
					MOV		ESI,opIndex
					MOV		[optStack+ESI*4],3
				.elseif	num == handleButtonDiv
					MOV		EAX,'/'
					MOV		ESI,opIndex
					MOV		[optStack+ESI*4],4
				.endif
				LEA		ESI,numStrExpression
				.if		isStart == 1
						.while	BYTE	PTR[ESI] != 0
								INC		ESI
						.endw
				.else
						MOV		isStart,1
				.endif
				MOV		[ESI],AL
				MOV		BYTE	PTR[ESI+1],0
				fst		res
				.if		curOp == 3
					fmul
				.else
					fdiv
				.endif
				MOV		EAX,curNum
				DEC		EAX
				MOV		curNum,EAX
				fst		res
				invoke	FloatToStr,res,addr	numStrResult
				invoke	SetDlgItemText,hWnd,handleTextResult,addr numStrResult
				MOV		isStart,0
			.elseif	(num == handleButtonPlus)||(num == handleButtonSub)
				.if		curOp == 3
					fmul
				.else
					fdiv
				.endif
				MOV		EAX,curNum
				DEC		EAX
				MOV		curNum,EAX
				MOV		ESI,opIndex
				.if		curNum != 1
						DEC		ESI
						MOV		opIndex,ESI
						MOV		EAX,[optStack+ESI*4]
						MOV		curOp,EAX
						.if		curOp == 1
								fadd
						.else
								fsub
						.endif
						MOV		EAX,curNum
						DEC		EAX
						MOV		curNum,EAX
				.endif
				.if		num == handleButtonPlus
					MOV		EAX,'+'
					MOV		ESI,opIndex
					MOV		[optStack+ESI*4],1
				.elseif	num == handleButtonSub
					MOV		EAX,'-'
					MOV		ESI,opIndex
					MOV		[optStack+ESI*4],2
				.endif
				LEA		ESI,numStrExpression
				.if		isStart == 1
						.while	BYTE	PTR[ESI] != 0
								INC		ESI
						.endw
				.else
						MOV		isStart,1
				.endif
				MOV		[ESI],AL
				MOV		BYTE	PTR[ESI+1],0
				fst		res
				invoke	FloatToStr,res,addr	numStrResult
				invoke	SetDlgItemText,hWnd,handleTextResult,addr numStrResult
				MOV		isStart,0
			.elseif	(num == handleButtonEqu) ||(num == handleButtonRight)
				fst		res
				.if		curOp == 3
						fmul
				.else
						fdiv
				.endif
				MOV		EAX,curNum
				DEC		EAX
				MOV		curNum,EAX
				MOV		ESI,opIndex
				.if		curNum != 1
						DEC		ESI
						MOV		opIndex,ESI
						MOV		EAX,[optStack+ESI*4]
						MOV		curOp,EAX
						.if		curOp == 1
								fadd
						.else
								fsub
						.endif
						MOV		EAX,curNum
						DEC		EAX
						MOV		curNum,EAX
				.endif
				fst		res
				invoke	FloatToStr,res,addr	numStrResult
				invoke	SetDlgItemText,hWnd,handleTextResult,addr numStrResult
				.if		num == handleButtonEqu
						invoke	SetDlgItemText,hWnd,handleTextExpression,addr numStrExpression
						MOV		flag,1
						invoke	initAC
				.else
						MOV		ESI,opIndex
						DEC		ESI
						MOV		EAX,[optStack+ESI*4]
						MOV		curNum,EAX
						.if		EAX == 2
								MOV		EDI,numIndex
								fstp	res
								DEC		EDI
								fld		[numStack+EDI*4]
								fst		op1
								DEC		EDI
								fld		[numStack+EDI*4]
								fst		op1
								fld		res
								MOV		numIndex,EDI
						.elseif	EAX == 1
								MOV		EDI,opIndex
								DEC		EDI
								fstp	res
								fld		[numStack+EDI*4]
								fst		op1
								fld		res
								MOV		numIndex,EDI
						.endif
						INC		EAX
						MOV		curNum,EAX
						DEC		ESI
						MOV		opIndex,ESI
						invoke	strcat,addr	numStrExpression,addr	buttonRightText
						MOV		[numStrResult],0
				.endif
			.endif
		.endif
		.if flag == 0
			invoke	SetDlgItemText,hWnd,handleTextExpression,addr numStrExpression
		.endif
		ret
pressOp	endp
;-----------------按下加减乘除等于号右括号的处理---------------------

;-----------------按下左括号的处理---------------------
pressLeft	proc	hWnd:HWND
	MOV		isStartNum,0
	MOV		ESI,opIndex
	INC		ESI
	MOV		EAX,curNum
	MOV		[optStack+ESI*4],EAX
	.if		EAX == 2
			MOV		EDI,numIndex
			fstp	[numStack+EDI*4]
			INC		EDI
			fstp	[numStack+EDI*4]
			INC		EDI
			MOV		numIndex,EDI
	.elseif EAX == 1
			MOV		EDI,numIndex
			.if isLeft == 0
				fldz
			.endif  
			fstp	[numStack+EDI*4]
			INC		EDI
			MOV		isLeft,0
			MOV		numIndex,EDI
	.endif
	INC		ESI
	MOV		opIndex,ESI
	MOV		curNum,0
	finit
	invoke	strcat,addr numStrExpression,addr buttonLeftText
	invoke	SetDlgItemText,hWnd,handleTextExpression,addr numStrExpression
	ret
pressLeft	endp
;-----------------按下左括号的处理---------------------

;-----------------按下三角函数的处理---------------------
pressTri	proc	hWnd:HWND,msgLeft:DWORD,msgRight:DWORD
	;将下显示框内容加上sin（）添加到上显示框字符串中
    invoke	strcat,addr numStrExpression,msgLeft
    invoke	strcat,addr numStrExpression,addr numStrResult
    invoke	strcat,addr numStrExpression,msgRight
    ;获取三角函数运算结果
    fst		res
    invoke	FloatToStr,res,addr numStrResult
    invoke	SetDlgItemText,hWnd,handleTextExpression,addr numStrExpression
    invoke	SetDlgItemText,hWnd,handleTextResult,addr numStrResult
	MOV		[numStrResult],0
    ret
pressTri	endp
;-----------------按下三角函数的处理---------------------


;-----------------按下.的处理---------------------
pressDot	proc	hWnd:HWND
	;出现点号，则为浮点数
    MOV		isFloat,1
    ;存入1.0用于更新当前数的阶tempdot
    fld		initDot
    fstp	tempDot
    MOV		EAX,'.'
    LEA		ESI,numStrResult
    .if		isStart == 1
			.while BYTE PTR[ESI]!=0
				INC ESI
			.endw
    .else
			MOV		isStart,1
    .endif
    MOV		[ESI],AL
    MOV		BYTE PTR [ESI+1],0
    ;更新下显示框
    invoke	SetDlgItemText,hWnd,handleTextResult,addr numStrResult
    ret
pressDot	endp
;-----------------按下.的处理---------------------


;-----------------程序主窗口的消息处理窗口过程函数---------------------
_ProcWinMain proc uses ebx edi esi,hWnd:HWND,uMsg:UINT,wParam:WPARAM,lParam:LPARAM
    LOCAL	PaintInfo:	PAINTSTRUCT
	LOCAL	hDc:		HDC
									
	.if		uMsg == WM_PAINT						;uMsg消息类型
		invoke	BeginPaint,hWnd,addr PaintInfo		;绘制窗口
		MOV		hDc,EAX
		MOV		screenHandle,EAX
		invoke	TextOut,hDc,470,100,addr equText,1
		invoke	EndPaint,hWnd,addr PaintInfo
	.elseif	uMsg == WM_CLOSE
		invoke	DestroyWindow,_windowHandle			;关闭窗口
		invoke	PostQuitMessage,NULL
	.elseif	uMsg == WM_CREATE						;创建窗口，按钮赋句柄
		invoke CreateWindowEx,NULL,offset Static,offset	expressionText,\
			WS_CHILD or WS_VISIBLE or ES_RIGHT,20,40,460,40,\
			hWnd,handleTextExpression,_processHandle,NULL
		invoke CreateWindowEx,NULL,offset Static,offset	resultText,\
			WS_CHILD or WS_VISIBLE or ES_RIGHT,20,140,460,40,\
			hWnd,handleTextResult,_processHandle,NULL
		invoke CreateWindowEx,NULL,offset Button,offset button1Text,\
			WS_CHILD or WS_VISIBLE,20,200,60,60,\ 
			hWnd,handleButton1,_processHandle,NULL				
		invoke CreateWindowEx,NULL,offset Button,offset button2Text,\
			WS_CHILD or WS_VISIBLE,100,200,60,60,\  
			hWnd,handleButton2,_processHandle,NULL
		invoke CreateWindowEx,NULL,offset Button,offset button3Text,\
			WS_CHILD or WS_VISIBLE,180,200,60,60,\ 
			hWnd,handleButton3,_processHandle,NULL
		invoke CreateWindowEx,NULL,offset Button,offset buttonPlusText,\
			WS_CHILD or WS_VISIBLE,260,200,60,60,\ 
			hWnd,handleButtonPlus,_processHandle,NULL
		invoke CreateWindowEx,NULL,offset Button,offset buttonSinText,\
			WS_CHILD or WS_VISIBLE,340,200,60,60,\ 
			hWnd,handleButtonSin,_processHandle,NULL
		invoke CreateWindowEx,NULL,offset Button,offset button4Text,\
			WS_CHILD or WS_VISIBLE,20,280,60,60,\ 
			hWnd,handleButton4,_processHandle,NULL				
		invoke CreateWindowEx,NULL,offset Button,offset button5Text,\
			WS_CHILD or WS_VISIBLE,100,280,60,60,\  
			hWnd,handleButton5,_processHandle,NULL
		invoke CreateWindowEx,NULL,offset Button,offset button6Text,\
			WS_CHILD or WS_VISIBLE,180,280,60,60,\ 
			hWnd,handleButton6,_processHandle,NULL
		invoke CreateWindowEx,NULL,offset Button,offset buttonSubText,\
			WS_CHILD or WS_VISIBLE,260,280,60,60,\ 
			hWnd,handleButtonSub,_processHandle,NULL
		invoke CreateWindowEx,NULL,offset Button,offset buttonCosText,\
			WS_CHILD or WS_VISIBLE,340,280,60,60,\ 
			hWnd,handleButtonCos,_processHandle,NULL
		invoke CreateWindowEx,NULL,offset Button,offset buttonACText,\
			WS_CHILD or WS_VISIBLE,420,280,60,60,\ 
			hWnd,handleButtonAC,_processHandle,NULL
		invoke CreateWindowEx,NULL,offset Button,offset button7Text,\
			WS_CHILD or WS_VISIBLE,20,360,60,60,\ 
			hWnd,handleButton7,_processHandle,NULL				
		invoke CreateWindowEx,NULL,offset Button,offset button8Text,\
			WS_CHILD or WS_VISIBLE,100,360,60,60,\  
			hWnd,handleButton8,_processHandle,NULL
		invoke CreateWindowEx,NULL,offset Button,offset button9Text,\
			WS_CHILD or WS_VISIBLE,180,360,60,60,\ 
			hWnd,handleButton9,_processHandle,NULL
		invoke CreateWindowEx,NULL,offset Button,offset buttonMulText,\
			WS_CHILD or WS_VISIBLE,260,360,60,60,\ 
			hWnd,handleButtonMul,_processHandle,NULL
		invoke CreateWindowEx,NULL,offset Button,offset buttonTanText,\
			WS_CHILD or WS_VISIBLE,340,360,60,60,\ 
			hWnd,handleButtonTan,_processHandle,NULL
		invoke CreateWindowEx,NULL,offset Button,offset equText,\
			WS_CHILD or WS_VISIBLE,420,360,60,60,\ 
			hWnd,handleButtonEqu,_processHandle,NULL
		invoke CreateWindowEx,NULL,offset Button,offset buttonNegText,\
			WS_CHILD or WS_VISIBLE,20,440,60,60,\ 
			hWnd,handleButtonNeg,_processHandle,NULL				
		invoke CreateWindowEx,NULL,offset Button,offset button0Text,\
			WS_CHILD or WS_VISIBLE,100,440,60,60,\  
			hWnd,handleButton0,_processHandle,NULL
		invoke CreateWindowEx,NULL,offset Button,offset buttonDotText,\
			WS_CHILD or WS_VISIBLE,180,440,60,60,\ 
			hWnd,handleButtonDot,_processHandle,NULL
		invoke CreateWindowEx,NULL,offset Button,offset buttonDivText,\
			WS_CHILD or WS_VISIBLE,260,440,60,60,\ 
			hWnd,handleButtonDiv,_processHandle,NULL
		invoke CreateWindowEx,NULL,offset Button,offset buttonLeftText,\
			WS_CHILD or WS_VISIBLE,340,440,60,60,\ 
			hWnd,handleButtonLeft,_processHandle,NULL
		invoke CreateWindowEx,NULL,offset Button,offset buttonRightText,\
			WS_CHILD or WS_VISIBLE,420,440,60,60,\ 
			hWnd,handleButtonRight,_processHandle,NULL
	.elseif	uMsg == WM_COMMAND						;点击事件 如果点击按钮，wParam是按钮句柄	
		.if		((wParam >= handleButton0) && (wParam<= handleButton9))
			invoke	pressNum,hWnd,wParam
		.elseif	((wParam >= handleButtonEqu) && (wParam<= handleButtonRight))
			invoke	pressOp,hWnd,wParam
		.elseif	wParam == handleButtonAC			
			invoke	initAC
			invoke	SetDlgItemText,hWnd,handleTextExpression,addr numStrExpression
			invoke	SetDlgItemText,hWnd,handleTextResult,addr numStrResult
		.elseif	wParam == handleButtonLeft
			invoke	pressLeft,hWnd
		.elseif	wParam == handleButtonSin
			fsin
			invoke	pressTri,hWnd,addr sinText,addr	buttonRightText
		.elseif	wParam == handleButtonCos
			fcos
			invoke	pressTri,hWnd,addr cosText,addr	buttonRightText
		.elseif	wParam == handleButtonTan
			fst		res
			fsin
			fld		res
			fcos
			fdiv
			invoke	pressTri,hWnd,addr tanText,addr	buttonRightText
		.elseif	wParam == handleButtonNeg
			fchs
			.if		isNeg == 0
					MOV		isNeg,1
			.else
					MOV		isNeg,0
			.endif
			fst		res
			invoke	FloatToStr,res,addr	numStrResult
			invoke	SetDlgItemText,hWnd,handleTextResult,addr numStrResult	
		.elseif	wParam == handleButtonDot
			invoke	pressDot,hWnd
		.endif
	.else											;默认方式处理
		invoke DefWindowProc,hWnd,uMsg,wParam,lParam
		ret
	.endif
	XOR	EAX,EAX
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
	MOV		_windowsClass.lpfnWndProc,offset	_ProcWinMain    ;SengMessage(hWnd,uMsg,wParam,lParam)
	MOV		_windowsClass.hbrBackground,COLOR_WINDOW+1
	MOV		_windowsClass.lpszClassName,offset	_appClassName
    MOV     _windowsClass.cbClsExtra,0              ;窗口类结构后的附加字节数，共享内存
    MOV     _windowsClass.cbWndExtra,DLGWINDOWEXTRA ;窗口实例后的附加字节数
	invoke  LoadCursor,NULL,IDC_ARROW    
    MOV     _windowsClass.hCursor,EAX               ;光标
    MOV     _windowsClass.lpszMenuName,NULL         ;菜单名称指针
    MOV     _windowsClass.hIconSm,0                 ;窗口小图标句柄
    invoke	RegisterClassEx,addr	_windowsClass	;注册窗口类  

    invoke	CreateWindowEx,WS_EX_CLIENTEDGE,\		;新建窗口，句柄放eax
			offset _appClassName,offset ProgramName,\  ;注册类  窗口名称/button（按钮）
			WS_OVERLAPPEDWINDOW,100,100,520,570,\	;左上角xy坐标+宽+长
			NULL,NULL,_processHandle,NULL
    ;invoke  CreateDialogParam,_processHandle,addr _appClassName,0,addr _ProcWinMain,0  ;调用对话框窗口      	
	MOV		_windowHandle,EAX
	invoke	ShowWindow,_windowHandle,SW_SHOWDEFAULT	;显示窗口
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
	finit  
    MOV     isLeft,0
    CALL	_WinMain
	invoke	ExitProcess,NULL
	ret
main	endp
end	main
;----------------------主函数------------------------------
