# Makefile for C++ and Java compilation and testing for CST370.

# For C++ compilation.
cpp: main.cpp
	clang++ -o main -std=c++17 main.cpp

# For Java compilation.
java: Main.java
	javac Main.java

# For automatic testing.
test:
	bash test_script.sh

# Clean the directory with only necessary files.
clean:
	rm -f main
	rm -f *.class
	rm -rf ./answer/
	rm -rf ./my_result/
