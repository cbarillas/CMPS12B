#---------------------
# Makefile for lab4 
#---------------------

FLAGS = -std=c99 -Wall
SOURCES = CharType.c
OBJECTS = CharType.o
OUTPUT = out
EXEBIN = ./CharType

all: $(EXEBIN)

$(EXEBIN) : $(OBJECTS)
	gcc -o $(EXEBIN) $(OBJECTS)
$(OBJECTS) : $(SOURCES)
	gcc -c $(FLAGS) $(SOURCES)
clean :
	rm -f $(EXEBIN) $(OBJECTS) $(OUTPUT)
check:
	valgrind --leak-check=full $(EXEBIN) $(SOURCES) $(OUTPUT)
