final: m1.o Hashmap.o
	g++ -o plagiarismCatcher m1.o Hashmap.o
m1.o: m1.cpp Hashmap.h
	g++ -c m1.cpp Hashmap.h
Hashmap.o: Hashmap.cpp Hashmap.h
	g++ -c Hashmap.cpp Hashmap.h
