CC := gcc
CFLAGS := -Wall -Werror
SRCS := src/signals.c src/panel.c src/util.c src/term.c src/text.c
OBJF := signals.o panel.o util.o term.o text.o

ifndef VERBOSE
.SILENT:
endif

all: example.out

example.out: example.o $(OBJF)
	@$(CC) $^ -o $@

$(OBJF): $(SRCS)
	@$(CC) -c $^

clean:
	@rm *.o example.out