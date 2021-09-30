
.SUFFIXES: .cxx .o .x .hxx

NAME1 = Intersection
NAME2 = KnightsTour

CXX1 = $(NAME1).cxx
CXX2 = $(NAME2).cxx

EXEC1 = $(NAME1).x
EXEC2 = $(NAME2).x


CO=g++
FLAGS= -std=c++17 -Wall -O3


.PHONY: all
all: $(EXEC1) $(EXEC2)


$(EXEC1):
	$(CO) -o $@ $(CXX1) $(FLAGS) 

$(EXEC2): 
	$(CO) -o $@ $(CXX2) $(FLAGS)



##Intersection##
A: $(EXEC1) 

.PHONY: Intersection
Intersection: A
	@echo "\n*Intersection*\n"
	@./$(EXEC1) 

##KnightsTour##
B: $(EXEC2) 
.PHONY: KnightsTour
KnightsTour: B
	@echo "\n*KnightsTour*\n"
	@./$(EXEC2) 





.PHONY: clean
clean:                                                     
	rm -f *.o  *~ *.a *.so *.x *.txt graphs.pdf *.dat core core* a.out; rm -rf ${LIB_DIR}