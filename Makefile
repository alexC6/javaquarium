CC = g++-9
STD = -std=c++2a
CPPFLAGS = -pedantic -Wall -Wextra -Wold-style-cast -Woverloaded-virtual -Wfloat-equal \
           -Wwrite-strings -Wpointer-arith -Wcast-qual -Wcast-align -Wconversion \
           -Wshadow -Weffc++ -Wredundant-decls -Wdouble-promotion -Winit-self -Wswitch-default \
           -Wswitch-enum -Wundef -Wlogical-op -Winline -Weffc++ -g
EXEC = test.out
RM = rm -fv

.PHONY: all clean

all: $(EXEC)

$(EXEC): test.cpp vivant.o algue.o poisson.o herbivore.o carnivore.o aquarium.o
	$(CC) $(STD) $(CPPFLAGS) $^ -o $@

vivant.o: vivant.cpp
	$(CC) $(STD) $(CPPFLAGS) -c -o $@ $<

algue.o: algue.cpp
	$(CC) $(STD) $(CPPFLAGS) -c -o $@ $<

poisson.o: poisson.cpp
	$(CC) $(STD) $(CPPFLAGS) -c -o $@ $<

herbivore.o: herbivore.cpp
	$(CC) $(STD) $(CPPFLAGS) -c -o $@ $<

carnivore.o: carnivore.cpp
	$(CC) $(STD) $(CPPFLAGS) -c -o $@ $<

aquarium.o: aquarium.cpp
	$(CC) $(STD) $(CPPFLAGS) -c -o $@ $<

clean:
	$(RM) *.o $(EXEC)