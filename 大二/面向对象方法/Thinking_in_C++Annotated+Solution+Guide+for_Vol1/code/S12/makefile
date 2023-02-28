# From "Thinking in C++, 2nd Edition, Volume 1, 
# Annotated Solutions Guide" by Chuck Allison
# At http://www.BruceEckel.com
# (c)2001 MindView Inc. Copyright notice in Copyright.txt
# Automatically-generated MAKEFILE 
# For examples in directory .\S12
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
	Bird.$(OBJEXT) \
	BirdHouse.$(OBJEXT) \
	CopyAssign.exe \
	HasInt.$(OBJEXT) \
	NumberTest.exe \
	Overloaded.exe \
	PointerToMemberOperator.exe \
	ReflexiveAdd.exe \
	TheBirds.exe

Microsoft:  \
	Bird.$(OBJEXT) \
	BirdHouse.$(OBJEXT) \
	CopyAssign.exe \
	HasInt.$(OBJEXT) \
	NumberTest.exe \
	Overloaded.exe \
	PointerToMemberOperator.exe \
	ReflexiveAdd.exe \
	TheBirds.exe

g++295:  \
	Bird.$(OBJEXT) \
	BirdHouse.$(OBJEXT) \
	CopyAssign.exe \
	HasInt.$(OBJEXT) \
	NumberTest.exe \
	Overloaded.exe \
	PointerToMemberOperator.exe \
	ReflexiveAdd.exe \
	TheBirds.exe

g++3:  \
	Bird.$(OBJEXT) \
	BirdHouse.$(OBJEXT) \
	CopyAssign.exe \
	HasInt.$(OBJEXT) \
	NumberTest.exe \
	Overloaded.exe \
	PointerToMemberOperator.exe \
	ReflexiveAdd.exe \
	TheBirds.exe

edg:  \
	Bird.$(OBJEXT) \
	BirdHouse.$(OBJEXT) \
	CopyAssign.exe \
	HasInt.$(OBJEXT) \
	NumberTest.exe \
	Overloaded.exe \
	PointerToMemberOperator.exe \
	ReflexiveAdd.exe \
	TheBirds.exe

clean:
ifeq ($(notdir $(SHELL)),COMMAND.COM)
	del *.obj
	del *.exe
	del *.tds
	del *.o
else
	rm -f *.o *.obj *.exe *.tds
endif


Bird.$(OBJEXT): Bird.cpp

BirdHouse.$(OBJEXT): BirdHouse.cpp

CopyAssign.exe: CopyAssign.cpp

HasInt.$(OBJEXT): HasInt.cpp

NumberTest.exe: NumberTest.cpp

Overloaded.exe: HasInt.$(OBJEXT) Overloaded.$(OBJEXT)
	$(CPP) $(CPPFLAGS) $(EXEFLAG)Overloaded.exe Overloaded.$(OBJEXT) HasInt.$(OBJEXT)

Overloaded.$(OBJEXT): Overloaded.cpp
PointerToMemberOperator.exe: PointerToMemberOperator.cpp

ReflexiveAdd.exe: ReflexiveAdd.cpp

TheBirds.exe: Bird.$(OBJEXT) BirdHouse.$(OBJEXT) TheBirds.$(OBJEXT)
	$(CPP) $(CPPFLAGS) $(EXEFLAG)TheBirds.exe TheBirds.$(OBJEXT) Bird.$(OBJEXT) BirdHouse.$(OBJEXT)

TheBirds.$(OBJEXT): TheBirds.cpp
