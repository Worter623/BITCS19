# From "Thinking in C++, 2nd Edition, Volume 1, 
# Annotated Solutions Guide" by Chuck Allison
# At http://www.BruceEckel.com
# (c)2001 MindView Inc. Copyright notice in Copyright.txt
# Automatically-generated MAKEFILE 
# For examples in directory .\S16
# Invoke with: make

CPP = bcc32
OFLAGS = -c
EXEFLAG = -e
OBJEXT = obj
.SUFFIXES : .cpp .$(OBJEXT) .exe
.cpp.$(OBJEXT) :
	$(CPP) $(OFLAGS) $<
.cpp.exe :
	$(CPP) $< $(EXEFLAG)$@

Borland:  \
	fibonacci.exe \
	NestedSmartPointerTemplate.exe \
	PointerToMemberOperatorTemplate.exe \
	SafeVector.exe \
	SelfCounter.$(OBJEXT) \
	SpecializeReturn.exe \
	TemplateArray.exe \
	VectorTest.exe

Microsoft:  \
	fibonacci.exe \
	NestedSmartPointerTemplate.exe \
	PointerToMemberOperatorTemplate.exe \
	SelfCounter.$(OBJEXT) \
	SpecializeReturn.exe \
	TemplateArray.exe \
	VectorTest.exe

g++295:  \
	fibonacci.exe \
	NestedSmartPointerTemplate.exe \
	PointerToMemberOperatorTemplate.exe \
	SafeVector.exe \
	SelfCounter.$(OBJEXT) \
	SpecializeReturn.exe \
	TemplateArray.exe \
	VectorTest.exe

g++3:  \
	fibonacci.exe \
	NestedSmartPointerTemplate.exe \
	PointerToMemberOperatorTemplate.exe \
	SafeVector.exe \
	SelfCounter.$(OBJEXT) \
	SpecializeReturn.exe \
	TemplateArray.exe \
	VectorTest.exe

edg:  \
	fibonacci.exe \
	NestedSmartPointerTemplate.exe \
	PointerToMemberOperatorTemplate.exe \
	SafeVector.exe \
	SelfCounter.$(OBJEXT) \
	SpecializeReturn.exe \
	TemplateArray.exe \
	VectorTest.exe

clean:
ifeq ($(notdir $(SHELL)),COMMAND.COM)
	del *.obj
	del *.exe
	del *.tds
	del *.o
else
	rm -f *.o *.obj *.exe *.tds
endif


fibonacci.exe: fibonacci.cpp

NestedSmartPointerTemplate.exe: NestedSmartPointerTemplate.cpp

PointerToMemberOperatorTemplate.exe: PointerToMemberOperatorTemplate.cpp

SafeVector.exe: SafeVector.cpp

SelfCounter.$(OBJEXT): SelfCounter.cpp

SpecializeReturn.exe: SpecializeReturn.cpp

TemplateArray.exe: TemplateArray.cpp

VectorTest.exe: SelfCounter.$(OBJEXT) VectorTest.$(OBJEXT)
	$(CPP) $(CPPFLAGS) $(EXEFLAG)VectorTest.exe VectorTest.$(OBJEXT) SelfCounter.$(OBJEXT)

VectorTest.$(OBJEXT): VectorTest.cpp
