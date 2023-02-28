# From "Thinking in C++, 2nd Edition, Volume 1, 
# Annotated Solutions Guide" by Chuck Allison
# At http://www.BruceEckel.com
# (c)2001 MindView Inc. Copyright notice in Copyright.txt
# Automatically-generated MAKEFILE 
# For examples in directory .\S10
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
	DifferentStatics.exe \
	Disjoint.exe \
	Fibonacci.exe \
	FileStatic1.$(OBJEXT) \
	FileStatic2.$(OBJEXT) \
	LocalStruct.exe \
	Monitor1.exe \
	Monitor2.exe \
	Monitor3.exe \
	PoliteClient.exe \
	Unnamed1.$(OBJEXT) \
	Unnamed2.$(OBJEXT) \
	UnnamedUnique.exe

Microsoft:  \
	DifferentStatics.exe \
	Disjoint.exe \
	Fibonacci.exe \
	FileStatic1.$(OBJEXT) \
	FileStatic2.$(OBJEXT) \
	LocalStruct.exe \
	Monitor1.exe \
	Monitor2.exe \
	Monitor3.exe \
	PoliteClient.exe \
	Unnamed1.$(OBJEXT) \
	Unnamed2.$(OBJEXT) \
	UnnamedUnique.exe

g++295:  \
	DifferentStatics.exe \
	Disjoint.exe \
	Fibonacci.exe \
	FileStatic1.$(OBJEXT) \
	FileStatic2.$(OBJEXT) \
	LocalStruct.exe \
	Monitor1.exe \
	Monitor2.exe \
	Monitor3.exe \
	PoliteClient.exe \
	Unnamed1.$(OBJEXT) \
	Unnamed2.$(OBJEXT) \
	UnnamedUnique.exe

g++3:  \
	DifferentStatics.exe \
	Disjoint.exe \
	Fibonacci.exe \
	FileStatic1.$(OBJEXT) \
	FileStatic2.$(OBJEXT) \
	LocalStruct.exe \
	Monitor1.exe \
	Monitor2.exe \
	Monitor3.exe \
	PoliteClient.exe \
	Unnamed1.$(OBJEXT) \
	Unnamed2.$(OBJEXT) \
	UnnamedUnique.exe

edg:  \
	DifferentStatics.exe \
	Disjoint.exe \
	Fibonacci.exe \
	FileStatic1.$(OBJEXT) \
	FileStatic2.$(OBJEXT) \
	LocalStruct.exe \
	Monitor1.exe \
	Monitor2.exe \
	Monitor3.exe \
	PoliteClient.exe \
	Unnamed1.$(OBJEXT) \
	Unnamed2.$(OBJEXT) \
	UnnamedUnique.exe

clean:
ifeq ($(notdir $(SHELL)),COMMAND.COM)
	del *.obj
	del *.exe
	del *.tds
	del *.o
else
	rm -f *.o *.obj *.exe *.tds
endif


DifferentStatics.exe: FileStatic1.$(OBJEXT) FileStatic2.$(OBJEXT) DifferentStatics.$(OBJEXT)
	$(CPP) $(CPPFLAGS) $(EXEFLAG)DifferentStatics.exe DifferentStatics.$(OBJEXT) FileStatic1.$(OBJEXT) FileStatic2.$(OBJEXT)

DifferentStatics.$(OBJEXT): DifferentStatics.cpp
Disjoint.exe: Disjoint.cpp

Fibonacci.exe: Fibonacci.cpp

FileStatic1.$(OBJEXT): FileStatic1.cpp

FileStatic2.$(OBJEXT): FileStatic2.cpp

LocalStruct.exe: LocalStruct.cpp

Monitor1.exe: Monitor1.cpp

Monitor2.exe: Monitor2.cpp

Monitor3.exe: Monitor3.cpp

PoliteClient.exe: PoliteClient.cpp

Unnamed1.$(OBJEXT): Unnamed1.cpp

Unnamed2.$(OBJEXT): Unnamed2.cpp

UnnamedUnique.exe: Unnamed1.$(OBJEXT) Unnamed2.$(OBJEXT) UnnamedUnique.$(OBJEXT)
	$(CPP) $(CPPFLAGS) $(EXEFLAG)UnnamedUnique.exe UnnamedUnique.$(OBJEXT) Unnamed1.$(OBJEXT) Unnamed2.$(OBJEXT)

UnnamedUnique.$(OBJEXT): UnnamedUnique.cpp
