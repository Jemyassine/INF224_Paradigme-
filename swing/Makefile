PROG = Main
PACKAGE = src
BIN = bin

# List Java source files with relative paths
SOURCES = $(PACKAGE)/swing/Window.java $(PACKAGE)/swing/Client.java $(PACKAGE)/Main.java

# Java compiler and flags
JC = javac
JFLAGS = -g -d $(BIN)

ifeq ($(OS),Windows_NT)
RM = del /Q
NULL = NUL
RMDIR = rmdir /S /Q
else
RM = rm -f
RMDIR = rm -rf
NULL = /dev/null
endif

all: classes

run: all
	java -cp $(BIN) javaswing.src.Main

classes:
	$(JC) $(JFLAGS) $(PACKAGE)/*.java $(PACKAGE)/swing/*.java

clean:
	$(RMDIR) $(BIN) 

tar:
	tar cvf $(PROG).tar.gz $(PACKAGE)/*.java $(PACKAGE)/swing/*.java Makefile