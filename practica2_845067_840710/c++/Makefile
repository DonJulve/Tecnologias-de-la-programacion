PROG:=main
SRCS:=instruccion.cc main.cc

CXX:= g++ -march=native -O3 -std=c++11

all: $(PROG)

OBJS:=$(SRCS:.cc=.o)

$(PROG): $(OBJS)
	$(CXX) -o $@ $(OBJS)

.cc.o:
	$(CXX) -c $< 

.cc.s:
	$(CXX) -c -S $<

edit:
	geany -s *.h *.cc &

#Compilacion
instruccion.o: instruccion.cc
main.o: main.cc 

clean:
	@rm -f $(PROG) $(OBJS) core *.s

descompilar:
	@rm -f $(PROG) $(OBJS) core *.s main.exe