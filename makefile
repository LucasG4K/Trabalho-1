output: main.o cases.o BST.o AVL.o RB.o
	g++ main.cpp BST.cpp AVL.cpp RB.cpp -o output

BST.o: BST.cpp BST.hpp
	g++ -c BST.cpp

AVL.o: AVL.cpp AVL.hpp
	g++ -c AVL.cpp

RB.o: RB.cpp RB.hpp
	g++ -c RB.cpp

cases.o: cases.cpp
	g++ -c cases.cpp

main.o: main.cpp
	g++ -c main.cpp

gen:
	g++ generate_data.cpp AVL.cpp -o genData
	./genData

run:
	./output

remove:
	rm -f *.o

clean:
	rm -f *.o output genData