CC = gcc
CFLAGS = -std=c99 -Wall -Werror -pedantic -Wfloat-conversion -Wvla -Wfloat-equal -Wpedantic -Wextra -Iinc -g3
.PHONY = clean

app.exe: out/main.o out/matrix_io.o out/matrix_operations.o
	$(CC) -o $@ $^ -lm

out/main.o: src/main.c inc/constants.h inc/matrix.h inc/matrix_io.h inc/matrix_operations.h
	$(CC) $(CFLAGS) -o $@ -c $<

out/matrix_io.o: src/matrix_io.c inc/matrix_io.h inc/constants.h inc/matrix.h
	$(CC) $(CFLAGS) -o $@ -c $<

out/matrix_operations.o: src/matrix_operations.c inc/matrix.h inc/constants.h inc/matrix_io.h
	$(CC) $(CFLAGS) -o $@ -c $<

unit_tests.exe: out/test_main.o out/test_operations.o out/matrix_operations.o out/matrix_io.o
	$(CC) -o $@ $^ -lm

out/test_main.o: unit_tests/test_main.c unit_tests/test_operations.h
	$(CC) $(CFLAGS) -o $@ -c $<

out/test_operations.o: unit_tests/test_operations.c inc/matrix_operations.h inc/matrix.h
	$(CC) $(CFLAGS) -o $@ -c $<

unit: unit_tests.exe
	./unit_tests.exe

clean:
	rm out/*.o log/*