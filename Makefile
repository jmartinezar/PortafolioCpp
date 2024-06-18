exe: main
	./$<

%.o: %.cpp
	g++ -g -Wall -fsanitize=address,undefined,leak -c $<

%.o: %.cpp %.h
	g++ -g -Wall -fsanitize=address,undefined,leak -c $<

main: main.o node.o tree.o include.o
	g++ -g -Wall -fsanitize=address,undefined,leak $^ -o $@

clean:
	rm *~ *.o main
