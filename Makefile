main: main.o ann.o neuron.o TanhNeuron.o InvSquareNeuron.o
	g++ -g  main.o ann.o neuron.o TanhNeuron.o InvSquareNeuron.o -o main

main.o: main.cpp ann.h
	g++ -g -c  main.cpp

ann.o: ann.h ann.cpp neuron.h
	g++ -g -c ann.cpp

neuron.o: neuron.cpp neuron.h
	g++ -g -c  neuron.cpp
TanhNeuron.o: TanhNeuron.cpp neuron.h
	g++ -g -c  TanhNeuron.cpp
InvSquareNeuron.o: InvSquareNeuron.cpp InvSquareNeuron.h
	g++ -g -c  InvSquareNeuron.cpp
clean:
	rm -rf *.o
