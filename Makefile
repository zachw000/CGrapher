CC=gcc
CFLAGS=-I.
DEPS = lib/%.h lib/ImagMathLib/%.h
OBJ = bin/Init.o bin/ImagMathLib.o
bin/Init.o: src/Init.c
	$(CC) -c -o bin/Init.o src/Init.c -I. -lm
bin/ImagMathLib.o: src/ImagMathLib/ImagMathLib.c
	$(CC) -c -o bin/ImagMathLib.o src/ImagMathLib/ImagMathLib.c -I. -lm
ComplexGrapher: $(OBJ)
	$(CC) -o bin/$@ $^ $(CFLAGS) -lm
%.o: %.c ImagMathLib/%.c $(DEPS)
	$(CC) -c -o bin/$@ $< $(CFLAGS)
ComplexGrapher.exe: $(OBJ)
	$(CC) -o .\bin\$@ $^ $(CFLAGS) -lm
