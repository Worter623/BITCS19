# From "Thinking in C++, 2nd Edition, Volume 1, 
# Annotated Solutions Guide" by Chuck Allison
# At http://www.BruceEckel.com
# (c)2001 MindView Inc. Copyright notice in Copyright.txt
# Automatically-generated MAKEFILE 
# For examples in directory .\S06
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
	Announce.exe \
	ArrayInit.exe \
	forScope.exe

Microsoft:  \
	Announce.exe \
	ArrayInit.exe \
	forScope.exe

g++295:  \
	Announce.exe \
	ArrayInit.exe \
	forScope.exe

g++3:  \
	Announce.exe \
	ArrayInit.exe \
	forScope.exe

edg:  \
	Announce.exe \
	ArrayInit.exe \
	forScope.exe

clean:
ifeq ($(notdir $(SHELL)),COMMAND.COM)
	del *.obj
	del *.exe
	del *.tds
	del *.o
else
	rm -f *.o *.obj *.exe *.tds
endif


Announce.exe: Announce.cpp

ArrayInit.exe: ArrayInit.cpp

forScope.exe: forScope.cpp

