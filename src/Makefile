CFLAGS=-c -Wall -Werror -Wextra -std=c11 -g

ifeq ($(shell uname), Linux)
	LINUX_LIBS=-lsubunit -lrt -lpthread -lm
endif

all: clean s21_string.a

s21_string.a:
	rm -rf *.o
	rm -rf s21_string.a
	gcc $(CFLAGS) s21_*.c
	ar r s21_string.a s21_*.o
	ranlib s21_string.a

s21_string_o: s21_*.c s21_string.h
	gcc $(CFLAGS) s21_*.c

test: clean s21_string.a
	gcc test_string.c s21_string.a -o check.out -lcheck $(LINUX_LIBS)
	./check.out

gcov_report: test_string.c s21_*.c
	clear
	gcc test_string.c s21_*.c -o coverage.o -lcheck $(LINUX_LIBS) -fprofile-arcs -ftest-coverage  
	./coverage.o
	lcov -c -d . -o coverage.info
	genhtml coverage.info -o coverage
	open coverage/index.html

	
clean:
	rm -rf *.o *.out
	rm -rf *.gcda *.gcno
	rm -rf coverage coverage.info CPPLINT.cfg cpplint.py valgrind-out.txt s21_string.a

leaks: test
	gcc -g test_string.c s21_string.a -o check.out -lcheck $(LINUX_LIBS)
	valgrind --leak-check=full --show-leak-kinds=all --show-reachable=no --quiet --track-origins=yes  --log-file=valgrind-out.txt ./check.out


leaks2: test
	CK_FORK=no leaks --atExit -- ./check.out

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem ./*.c

lint:
	cp ./../materials/linters/CPPLINT.cfg ./
	cp ./../materials/linters/cpplint.py ./
	python3 cpplint.py --extensions=c *.c *.h
