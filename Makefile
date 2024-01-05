CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -pedantic
LDFLAGS = -lcheck -lm -lpthread -lrt

all: main tests

main: main.c price_calculator.c
    $(CC) $(CFLAGS) -o $@ $^

tests: tests.c price_calculator.c
    $(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

check: tests
    ./tests

clean:
    rm -f main tests
