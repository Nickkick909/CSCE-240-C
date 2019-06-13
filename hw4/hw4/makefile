CC = g++  # use g++ compiler

FLAGS = -std=c++11  # compile with C++ 11 standard
FLAGS += -Wall      # compile with all warnings

LINK = $(CC) $(FLAGS) -o  # final linked build to binary executable

COMPILE = $(CC) $(FLAGS) -c  # compilation to intermediary .o files

test: test1 test2 test3 test4 test5 test6
	./test1
	./test2
	./test3
	./test4
	./test5
	./test6

test1 : test_operator_plus_grade.cc gradebook.o
	$(LINK) $@ $^

test2 : test_operator_plus_gradebook.cc gradebook.o
	$(LINK) $@ $^

test3 : test_operator_equal_to_gpa.cc gradebook.o
	$(LINK) $@ $^

test4 : test_operator_equal_to_gradebook.cc gradebook.o
	$(LINK) $@ $^

test5 : test_operator_less_than_gpa.cc gradebook.o
	$(LINK) $@ $^

test6 : test_operator_less_than_gradebook.cc gradebook.o
	$(LINK) $@ $^

gradebook.o : gradebook.cc gradebook.h
	$(COMPILE) $<

clean:
	rm -f gradebook.o test?
