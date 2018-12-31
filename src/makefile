CXX = gcc

run: main.c
		${CXX} -o shell main.c && ./shell 

test: test_strmatch.c
		${CXX} -o test test_strmatch.c && ./test
clean:
		rm -f shell test

