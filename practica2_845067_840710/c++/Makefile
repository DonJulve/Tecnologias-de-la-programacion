PROG:=main
SRCS:=main.cc

CXX:= g++ -O2

OBJS:=$(SRCS:.cc=.o)

all: $(PROG) 

$(PROG): $(OBJS)
	$(CXX) -o $@ $(OBJS)

.cc.o:
	$(CXX) -c $<

.cc.s:
	$(CXX) -c -S $<

edit:
	geany -s *.h *.cc &

clean:
	@rm -f $(PROG) $(OBJS) core *.s
	
main.o: sumaProg.h main.cc
read.o: read.h
add.o: add.h
write.o: write.h
programa.o: programa.h
sumaProg.o: sumaProg.h
instruccion.o: instruccion.h