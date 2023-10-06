CC=g++
CFLAGS = -g -std=c++20
LIBS=-lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

main: src/main.cpp
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f main