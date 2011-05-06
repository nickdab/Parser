test:test.o parserdef.h overloaded-operators.o ReadNextWord.o open.o accessors.o mutators.o constructors.o 
	g++ ReadNextWord.o overloaded-operators.o open.o accessors.o mutators.o constructors.o test.o -o test 
	
test.o:test.cpp
	g++ test.cpp -c -o test.o

ReadNextWord.o: ReadNextWord.cpp
	g++ ReadNextWord.cpp -c -o ReadNextWord.o

overloaded-operators.o: overloaded-operators.cpp
	g++ overloaded-operators.cpp -c -o overloaded-operators.o

open.o: open.cpp
	g++ open.cpp -c -o open.o

accessors.o: accessors.cpp
	g++ accessors.cpp -c -o accessors.o

mutators.o: mutators.cpp
	g++ mutators.cpp -c -o mutators.o

constructors.o: constructors.cpp
	g++ constructors.cpp -c -o constructors.o

clean:
	rm ReadNextWord.o overloaded-operators.o open.o accessors.o constructors.o mutators.o 
