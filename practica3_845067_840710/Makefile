# //---------------------------------------------------------------------------
# // File: Makefile
# // Authors: Javier Julve Yubero (840710) y Jorge Jaime Modrego(845067)
# // Date: Marzo 2024
# //---------------------------------------------------------------------------
PROG:=main
SRCS:=main.cc

CXX:=g++ -Wall

OBJS:=$(SRCS:.cc=.o)
DEPS:=$(SRCS:.cc=.d)

all: $(PROG)

$(PROG): $(OBJS)
	$(CXX) -o $@ $^

.cc.o:
	$(CXX) -c -MMD $<

.PHONY: edit go

go: $(PROG)
	$(PROG)

edit:
	@geany -s -i $(SRCS) *.h &

clean:
	@rm -f $(PROG) $(OBJS) $(DEPS) *.gch core tags

main.o: main.cc practica3.h

