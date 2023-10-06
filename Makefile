CC=g++
CFLAGS = -g -std=c++20 -Wall -Wextra -Wpedantic
LIBS=-lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

SRCDIR=src
ODIR=obj

_DEPS = page.hpp guessingPage.hpp settingsPage.hpp button.hpp
DEPS = $(patsubst %,$(SRCDIR)/%,$(_DEPS))

_OBJ = main.o guessingPage.o settingsPage.o button.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SRCDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f main obj/*