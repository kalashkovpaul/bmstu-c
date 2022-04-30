CFLAGS = -std=c99 -Wall -Werror -pedantic -Wfloat-conversion -Wvla -Wfloat-equal -Wpedantic -Wextra -Iinc -g3
CC = gcc
RESULTS = 0
.PHONY: clean

libarray.so: out/array.o
	$(CC) -shared -o $@ $<

out/array.o: src/array.c inc/constants.h
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

clean:
	rm out/*.o
