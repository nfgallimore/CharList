install:
	g++ charList.cpp -c -std=c++11
	g++ -o main charList_main.cpp CharList.o -std=c++11

clean:
	rm -rf *.o main