WordBreak: WordBreak.o
	g++ -g -o WordBreak.exe WordBreak.o -pthread    

WordBreak.o: WordBreak/WordBreak.cpp
	g++ -g  -c -pthread WordBreak/WordBreak.cpp
