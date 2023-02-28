# From "Thinking in C++, 2nd Edition, Volume 1, 
# Annotated Solutions Guide" by Chuck Allison
# At http://www.BruceEckel.com
# (c)2001 MindView Inc. Copyright notice in Copyright.txt
# Automatically-generated MAKEFILE 
# For examples in directory .\S05
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
	MapMembers.exe \
	MyFriends.exe \
	NestedFriends.exe \
	PointToMeAndYou.exe \
	StackOfInt1.$(OBJEXT) \
	StackOfInt2.$(OBJEXT) \
	StackOfIntTest.exe

Microsoft:  \
	MapMembers.exe \
	MyFriends.exe \
	NestedFriends.exe \
	PointToMeAndYou.exe \
	StackOfInt1.$(OBJEXT) \
	StackOfInt2.$(OBJEXT) \
	StackOfIntTest.exe

g++295:  \
	MapMembers.exe \
	MyFriends.exe \
	NestedFriends.exe \
	PointToMeAndYou.exe \
	StackOfInt1.$(OBJEXT) \
	StackOfInt2.$(OBJEXT) \
	StackOfIntTest.exe

g++3:  \
	MapMembers.exe \
	MyFriends.exe \
	NestedFriends.exe \
	PointToMeAndYou.exe \
	StackOfInt1.$(OBJEXT) \
	StackOfInt2.$(OBJEXT) \
	StackOfIntTest.exe

edg:  \
	MapMembers.exe \
	MyFriends.exe \
	NestedFriends.exe \
	PointToMeAndYou.exe \
	StackOfInt1.$(OBJEXT) \
	StackOfInt2.$(OBJEXT) \
	StackOfIntTest.exe

clean:
ifeq ($(notdir $(SHELL)),COMMAND.COM)
	del *.obj
	del *.exe
	del *.tds
	del *.o
else
	rm -f *.o *.obj *.exe *.tds
endif


MapMembers.exe: MapMembers.cpp

MyFriends.exe: MyFriends.cpp

NestedFriends.exe: NestedFriends.cpp

PointToMeAndYou.exe: PointToMeAndYou.cpp

StackOfInt1.$(OBJEXT): StackOfInt1.cpp

StackOfInt2.$(OBJEXT): StackOfInt2.cpp

StackOfIntTest.exe: StackOfInt2.$(OBJEXT) StackOfIntTest.$(OBJEXT)
	$(CPP) $(CPPFLAGS) $(EXEFLAG)StackOfIntTest.exe StackOfIntTest.$(OBJEXT) StackOfInt2.$(OBJEXT)

StackOfIntTest.$(OBJEXT): StackOfIntTest.cpp
