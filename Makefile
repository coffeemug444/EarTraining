CC=g++
CFLAGS = -g -std=c++20 -Wall -Wextra -Wpedantic
LIBS=-lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

main: src/main.cpp src/guessingPage.cpp src/settingsPage.cpp
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f main