CFLAGS = -Wall -Wextra -Werror -std=c11
LDFLAGS = -lncurses -lcheck -lm -lrt -pthread -lsubunit -lgcov

SRCS = $(wildcard ./brick_game/tetris/*.c)
FILE = $(wildcard ./gui/cli/*.c)
OBJS = $(SRCS:.c=.o) $(FILE:.c=.o)

all: tetris

s21_tetris.a: $(OBJS)
	ar rcs $@ $(OBJS)

install: 
#	ну я незная для чего мы должны использовать этот цель в makefile

uninstall:
#	ну я незная для чего мы должны использовать этот цель в makefile

dvi:
#	ну я незная для чего мы должны использовать этот цель в makefile

dest:
#	ну я незная для чего мы должны использовать этот цель в makefile

test:
#	ну я незная для чего мы должны использовать этот цель в makefile

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

tetris: $(OBJS) s21_tetris.a
	gcc $(CFLAGS) $(OBJS) -o $@ s21_tetris.a $(LDFLAGS)

gcov_report: test
#	./tetris
#	gcov -f *.c
#	mkdir report
#	~/.local/bin/gcovr -r $(shell pwd) --html --html-details -o report/coverage_report.html $(shell pwd)
#	xdg-open report/coverage_report.html


check: tetris
	valgrind --tool=memcheck --leak-check=yes ./tetris

clean:
	rm -f s21_tetris.a
	rm -f *.o
	rm -f tetris
	rm -f ./brick_game/tetris/*.o
	rm -f ./gui/cli/*.o