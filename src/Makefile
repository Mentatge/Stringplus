CC = gcc -Wall -Werror -Wextra -g -std=c11
SRC= $(wildcard s21_*.c)
OBJ= $(patsubst %.c, %.o, ${SRC})
LFLAGS= -lcheck -lm -lpthread 
GCF= -ftest-coverage -fprofile-arcs --coverage

ifeq ($(shell uname -s), Linux)
	LFLAGS += -lrt -lsubunit
endif



all: clean s21_string.a 


rebuild: clean s21_string.a main

clean:
	rm -rf *.o && rm -rf *.gcno
	rm -rf *.a && rm -rf *.gcda
	rm -rf *.info && rm -rf *.gcov
	rm -rf ./test && rm -rf ./gcov_report
	rm -rf ./report/

s21_string.o:
	$(CC) -c ${SRC} -lm

s21_string.a: s21_string.o
	ar rcs s21_string.a ${OBJ} 
	ranlib s21_string.a
	rm *.o

test: unit_tests.c s21_string.a
	$(CC)  -o test $^ ${LFLAGS}
	./test

gcov_report: test
# $(CC) $(GCF) -c unit_tests.c
	$(CC) $(GCF) $(SRC) unit_tests.c $(LFLAGS) -o gcov_report
	./gcov_report
	lcov -t "test" -o gcov_report.info -c -d .
	genhtml -o test_output gcov_report.info
	open ./test_output/index.html\

style:
	cp ../materials/linters/.clang-format ./
	clang-format -style=Google -i *.c

add_coverage:
	$(eval CC += --coverage)