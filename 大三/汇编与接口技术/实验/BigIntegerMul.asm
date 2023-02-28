.386				;程序使用80386指令集
.model flat,stdcall	;内存模式为flat模式，指定调用规则为stdcall
option casemap:none	;Win32的函数是大小写敏感的

includelib msvcrt.lib
include msvcrt.inc
scanf	PROTO C:ptr sbyte, :VARARG
printf	PROTO C:ptr sbyte, :VARARG


.data
divu	dword	10

numCharA	byte	150	dup(0)									;用字符数组存输入，大小为100个字节
numCharB	byte	150	dup(0)									;使用dup将其初始化为0
resultChar	byte	300	dup(0)

numIntA		dword	150	dup(0)
numIntB		dword	150 dup(0)
resultInt	dword	300 dup(0)

lengthA			dword	0
lengthB			dword	0
lengthResult	dword	0

InputMsg	byte	"Please input a multiplier: ",0				;输入输出字符串
OutputMsg	byte	"The result of %s * %s is %s",0DH,0AH,0
OutputMsgN	byte	"The result of %s * %s is %s%s",0DH,0AH,0
Fmts		byte	"%s", 0
Fmtd		byte	"%d", 0

NegativeFlag		byte	0												;符号标志位，0正1负	
NegativeSymbol		byte	"-"

.code

;-------------------int数组倒序转字符数组-------------------
int2str proc	C
	MOV		ecx,	lengthResult
	MOV		esi,	0 

LOOP_IN:							;循环将resultint数组中数字0-9+‘0’转字符0-9入栈
	MOV		eax,	dword ptr resultInt[4 * esi] 
	ADD		eax,	30H 
	PUSH	eax
	INC		esi
	LOOP	LOOP_IN

	MOV		ecx,	lengthResult
	MOV		esi,	0

LOOP_OUT:							;循环出栈，将eax的最低字节al存在resultchar中
	POP		eax
	MOV		byte ptr resultChar[esi], al 
	INC		esi
	LOOP	LOOP_OUT
	ret
int2str endp
;-------------------int数组倒序转字符数组-------------------


;-------------------字符数组倒序转int数组-------------------
str2int	proc	C	CharNumber:ptr byte,	IntNumber:ptr dword,	len:dword
	MOV		ecx,	len						;字符串长度为循环的次数，ecx控制循环次数
	MOV		esi,	CharNumber				;esi是位置指针

LOOP_IN:									;循环每次拿取字符数组中一个字节的字符0-9转数字0-9并入栈
	MOVZX	eax,	byte ptr[esi]			;在指针处取一个字节的字符，扩展成32位，高位填0
	SUB		eax,	30H						;30H是字符0的Ascii码
	PUSH	eax 
	INC		esi
	LOOP	LOOP_IN

	MOV		ecx,	len						;字符数组：高位先入栈 int数组：低位先出栈，放在高位
	MOV		esi,	IntNumber
	
LOOP_OUT:
	POP		eax
	MOV		dword ptr[esi], eax
	ADD		esi, 4							;int双字，四个字节
	LOOP	LOOP_OUT	
	ret
str2int endp
;-------------------字符数组倒序转int数组-------------------

;--------------------数组A倒序，字符数组转intA数组，记录A长度------------------------
ConvertStringA	proc	C
	CMP		numCharA,	2DH						;2DH是符号的ascii码，检查A是否是负数
	JNE		APositive
	XOR		NegativeFlag,1						;A是负数，改标志，求字符串长度时跳过负号
	invoke	crt_strlen,	offset(numCharA + 1)	;调用strlen函数求字符串长度，结果存在eax中
	MOV		lengthA,	eax
	invoke	str2int, offset(numCharA + 1),	offset numIntA, lengthA 
	ret
APositive:										;A是正数
	invoke	crt_strlen, offset numCharA
	MOV		lengthA,	eax
	invoke	str2int, offset numCharA,	offset numIntA, lengthA
	ret
ConvertStringA endp
;--------------------数组A倒序，字符数组转intA数组，记录A长度------------------------


;--------------------数组B倒序，字符数组转intB数组，记录B长度------------------------
ConvertStringB	proc	C
	CMP		numCharB,	2DH      
	JNE		BPositive
	XOR		NegativeFlag, 1 
	invoke	crt_strlen, offset (numCharB + 1) 
	MOV		lengthB,	eax
	invoke	str2int, offset (numCharB + 1), offset numIntB, lengthB ;字符串反转，且byte数组转dword数组
	ret
BPositive:
	invoke	crt_strlen, offset numCharB ;求字符串长度，结果放在eax中
	MOV		lengthB,	eax
	invoke	str2int, offset numCharB, offset numIntB, lengthB
	ret
ConvertStringB endp
;--------------------数组B倒序，字符数组转intB数组，记录B长度------------------------

;---------------------大数相乘，模拟竖式-----------------
BigIntMultiply	proc	C
	MOV		ebx, -1
ALOOP: 
	INC		ebx
	CMP		ebx, lengthA
	JNB		ENDLOOPMUL				;如果循环次数ebx大于等于A长度结束循环
	XOR		ecx, ecx
BLOOP:
	MOV		eax, dword ptr numIntA[4 * ebx]
	MUL		numIntB[4 * ecx]		;eax存储两个数相乘的结果
	MOV		esi, ecx
	ADD		esi, ebx				;esi存储两个乘数数组下标之和
	ADD		resultInt[4 * esi], eax ;把两个位相乘的结果加到result的相应位上
	INC		ecx
	CMP		ecx, lengthB 
	JNB		ALOOP					;循环次数ecx大于等于B长度时跳出这位循环，进行下一位循环循环
	JMP		BLOOP
ENDLOOPMUL:
	MOV		ecx, lengthA
	ADD		ecx, lengthB
	INC		ecx	
	MOV		[lengthResult], ecx		;结果长度最大为lengthA + lengthB + 1

	XOR		ebx, ebx				;计算进位
CARRYLOOP:
	CMP		ebx, ecx
	JNB		ENDLOOPCARRY			;循环次数ebx大于等于结果长度跳出循环
	MOV		eax, resultInt[4 * ebx]
	XOR		edx, edx
	DIV		divu
	ADD		resultInt[4 * ebx + 4], eax 
	MOV		resultInt[4 * ebx], edx 
	INC		ebx
	JMP		CARRYLOOP
ENDLOOPCARRY:
	MOV		ecx, lengthResult		;除去结果数组首位（目前的末位）多余的0
MOVEZEROLOOP:
	CMP		dword ptr resultInt[4 * ecx], 0
	JNZ		ENDMUL					;result的末位不为0
	DEC		ecx						;每检测到一个0，实际长度减一 
	JMP		MOVEZEROLOOP
ENDMUL:
	INC		ecx						;实际长度：最大下标+1
	MOV		[lengthResult], ecx
	ret
BigIntMultiply endp
;---------------------大数相乘，模拟竖式-----------------

;----------------------主函数------------------------------
main:
	invoke	printf,	offset InputMsg							;输入乘数A和B，存入字符数组
	invoke	scanf,	offset Fmts,	offset numCharA 
	invoke	printf,	offset InputMsg
	invoke	scanf,	offset Fmts,	offset numCharB

	invoke	ConvertStringA									;数组倒序，字符数组转int数组，记录长度
	invoke	ConvertStringB									
	invoke	BigIntMultiply
	
	invoke	int2str											;int数组转字符数组，倒序回来
	CMP		NegativeFlag,0									;打印结果
	JE		Positive
	invoke	printf,	offset OutputMsgN,	offset numCharA,	offset numCharB,	offset NegativeSymbol,	offset resultChar
	ret
Positive:
	invoke	printf,	offset OutputMsg,	offset numCharA,	offset numCharB,	offset resultChar
	ret
;----------------------主函数------------------------------

end main
