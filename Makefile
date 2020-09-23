CC = g++
CFLAGS = -g -c -Wall -std=c++11 -Og
OBJ = Tools.o Memory.o GBLoader.o Registers.o Pixel.o gb.o

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

gb: $(OBJ)

Tools.o: Tools.h

Memory.o: Tools.h Memory.h Sim.h

Registers.o: Registers.h Sim.h

GBLoader.o: gb.h GBLoader.h

Pixel.o: Sim.h Pixel.h

gb.o: Tools.h Memory.h Registers.h Pixel.h

clean:
	rm $(OBJ) gb || true

run:
	make clean
