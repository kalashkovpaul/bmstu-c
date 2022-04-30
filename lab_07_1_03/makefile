CFLAGS = -std=c99 -Wall -Werror -pedantic -Wfloat-conversion -Wvla -Wfloat-equal -Wpedantic -Wextra -Iinc -g3
CC = gcc
RESULTS = 0
.PHONY: clean

app.exe: out/app.o out/functions.o out/arguments.o
	$(CC) -o $@ $^

out/app.o: src/main.c inc/functions.h inc/constants.h inc/arguments.h
	$(CC) $(CFLAGS) -c $< -o $@

out/functions.o: src/functions.c inc/constants.h
	$(CC) $(CFLAGS) -c $< -o $@

out/arguments.o: src/arguments.c inc/constants.h
	$(CC) $(CFLAGS) -c $< -o $@

unit_tests.exe: out/unit_tests.o out/check_key.o out/check_mysort.o out/functions.o
	$(CC) -o $@ $^

out/unit_tests.o: unit_tests/unit_main.c unit_tests/check_key.h unit_tests/check_mysort.h
	$(CC) $(CFLAGS) -c $< -o $@

out/check_key.o: unit_tests/check_key.c inc/functions.h
	$(CC) $(CFLAGS) -c $< -o $@

out/check_mysort.o: unit_tests/check_mysort.c inc/functions.h
	$(CC) $(CFLAGS) -c $< -o $@

timer.exe: out/timer.o out/functions.o
	$(CC) -o $@ $^

out/timer.o: unit_tests/timer.c inc/functions.h inc/constants.h
	$(CC) $(CFLAGS) -c $< -o $@

unit:
	./unit_tests.exe

func: test.sh
	./test.sh

clean:
	rm out/*.o
