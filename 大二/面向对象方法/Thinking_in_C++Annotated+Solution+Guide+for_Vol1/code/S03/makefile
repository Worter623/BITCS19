# From "Thinking in C++, 2nd Edition, Volume 1, 
# Annotated Solutions Guide" by Chuck Allison
# At http://www.BruceEckel.com
# (c)2001 MindView Inc. Copyright notice in Copyright.txt
# Automatically-generated MAKEFILE 
# For examples in directory .\S03
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
	AbusingTheLanguage.exe \
	Enum.exe \
	FPtr1.exe \
	IEEEFloat.exe \
	MapFloat.exe \
	MapWords.exe \
	no-trigraph.exe \
	PointerIncrement2.exe \
	prime.exe \
	PrintBinary.$(OBJEXT) \
	PrintBytes.exe \
	ProtoTest.exe \
	Prototypes.$(OBJEXT) \
	StringArray.exe \
	StringRef.exe \
	struct.exe \
	Vampire.exe

Microsoft:  \
	AbusingTheLanguage.exe \
	Enum.exe \
	FPtr1.exe \
	IEEEFloat.exe \
	MapFloat.exe \
	MapWords.exe \
	no-trigraph.exe \
	PointerIncrement2.exe \
	prime.exe \
	PrintBinary.$(OBJEXT) \
	PrintBytes.exe \
	ProtoTest.exe \
	Prototypes.$(OBJEXT) \
	StringArray.exe \
	StringRef.exe \
	struct.exe \
	trigraph.exe \
	Vampire.exe

g++295:  \
	AbusingTheLanguage.exe \
	Enum.exe \
	FPtr1.exe \
	IEEEFloat.exe \
	MapFloat.exe \
	MapWords.exe \
	no-trigraph.exe \
	PointerIncrement2.exe \
	prime.exe \
	PrintBinary.$(OBJEXT) \
	PrintBytes.exe \
	ProtoTest.exe \
	Prototypes.$(OBJEXT) \
	StringArray.exe \
	StringRef.exe \
	struct.exe \
	Vampire.exe

g++3:  \
	AbusingTheLanguage.exe \
	Enum.exe \
	FPtr1.exe \
	IEEEFloat.exe \
	MapFloat.exe \
	MapWords.exe \
	no-trigraph.exe \
	PointerIncrement2.exe \
	prime.exe \
	PrintBinary.$(OBJEXT) \
	PrintBytes.exe \
	ProtoTest.exe \
	Prototypes.$(OBJEXT) \
	StringArray.exe \
	StringRef.exe \
	struct.exe \
	Vampire.exe

edg:  \
	AbusingTheLanguage.exe \
	Enum.exe \
	FPtr1.exe \
	IEEEFloat.exe \
	MapFloat.exe \
	MapWords.exe \
	no-trigraph.exe \
	PointerIncrement2.exe \
	prime.exe \
	PrintBinary.$(OBJEXT) \
	PrintBytes.exe \
	ProtoTest.exe \
	Prototypes.$(OBJEXT) \
	StringArray.exe \
	StringRef.exe \
	struct.exe \
	trigraph.exe \
	Vampire.exe

clean:
ifeq ($(notdir $(SHELL)),COMMAND.COM)
	del *.obj
	del *.exe
	del *.tds
	del *.o
else
	rm -f *.o *.obj *.exe *.tds
endif


AbusingTheLanguage.exe: AbusingTheLanguage.cpp

Enum.exe: Enum.cpp

FPtr1.exe: FPtr1.cpp

IEEEFloat.exe: IEEEFloat.cpp

MapFloat.exe: PrintBinary.$(OBJEXT) MapFloat.$(OBJEXT)
	$(CPP) $(CPPFLAGS) $(EXEFLAG)MapFloat.exe MapFloat.$(OBJEXT) PrintBinary.$(OBJEXT)

MapFloat.$(OBJEXT): MapFloat.cpp
MapWords.exe: MapWords.cpp

no-trigraph.exe: no-trigraph.cpp

PointerIncrement2.exe: PointerIncrement2.cpp

prime.exe: prime.cpp

PrintBinary.$(OBJEXT): PrintBinary.cpp

PrintBytes.exe: PrintBinary.$(OBJEXT) PrintBytes.$(OBJEXT)
	$(CPP) $(CPPFLAGS) $(EXEFLAG)PrintBytes.exe PrintBytes.$(OBJEXT) PrintBinary.$(OBJEXT)

PrintBytes.$(OBJEXT): PrintBytes.cpp
ProtoTest.exe: Prototypes.$(OBJEXT) ProtoTest.$(OBJEXT)
	$(CPP) $(CPPFLAGS) $(EXEFLAG)ProtoTest.exe ProtoTest.$(OBJEXT) Prototypes.$(OBJEXT)

ProtoTest.$(OBJEXT): ProtoTest.cpp
Prototypes.$(OBJEXT): Prototypes.cpp

StringArray.exe: StringArray.cpp

StringRef.exe: StringRef.cpp

struct.exe: struct.cpp

trigraph.exe: trigraph.cpp

Vampire.exe: Vampire.cpp

