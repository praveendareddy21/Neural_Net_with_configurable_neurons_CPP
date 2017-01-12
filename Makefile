main: main.o ann.o neuron.o
	g++ -g  main.o ann.o neuron.o -o main

main.o: main.cpp ann.h
	g++ -g -c  main.cpp

ann.o: ann.h ann.cpp neuron.h
	g++ -g -c ann.cpp

neuron.o: neuron.cpp neuron.h
	g++ -g -c  neuron.cpp

clean:
	rm -rf *.o
