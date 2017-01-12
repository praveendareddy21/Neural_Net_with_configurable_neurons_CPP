/*
 * ann.h
 *
 *  Created on: Oct 19, 2016
 *      Author: Praveen
 */

#ifndef ANN_H_
#define ANN_H_

#include<vector>
#include"type_defs.h"
#include<iostream>
#include<math.h>
#include<iomanip>
#include<stdlib.h>
#include<fstream>
#include<stdio.h>
#include<time.h>
#include"neuron.h"
using namespace std;



class Ann{
public:
	std::vector<int> structure;
	std::vector< std::vector<float_data_type> > *weightTable;
	std::vector<std::vector<float_data_type> > *outputTable;
	std::vector<std::vector<float_data_type> > *errorTable;
	std::vector<std::vector< int> > *Node_;


	std::vector< Neuron> neuronList;
	std::vector< NeuronTypeEnum> neuronEnumList;


	std::vector< std::vector<float_data_type> > train_inputTable;
	std::vector< std::vector<float_data_type> > test_inputTable;

	std::vector< int> train_output;
	std::vector< int> test_output;

	float_data_type alpha;
	std::vector<std::vector<float_data_type> > digit_encoding;

	float_data_type getEuclideanDistance(float_data_type x1, float_data_type y1, float_data_type x2, float_data_type y2);
	float_data_type getEuclideanDistance(std::vector<float_data_type> X, std::vector<float_data_type> Y);

	float_data_type getFSigmoid(float_data_type in);

	float_data_type getSigmoid(float_data_type in);
	float_data_type getSigmoidError(float_data_type out, float_data_type error);

	float_data_type getRectifier(float_data_type in);
	float_data_type getRectifierError(float_data_type out);


	void initStructure(char *);
	void initweight_Table(char *);
	void initOutput();
	void initError();
	void initNode();
	void initNeuronList();
	void initDigitEncoding();
	void initTrainInput(char *);
	void initTrainOutput(char *);
	void initTestInput(char *);
	void initTestOutput(char *);


	virtual void calculateValueAt(int layer, int nodeNum);
	virtual void calculateErrorAt(int layer, int nodeNum);
	virtual void calculateErrorAtOutputLayer(int layer, int nodeNum, float_data_type output);
	void updateValuesInForwardPass();
	void updateErrorsInBackwardPass();
	void doForwardPassIteration(std::vector< std::vector<float_data_type> > ,int);
	void doBackwardPassIteration(std::vector< int> , int);
	virtual void updateWeights();
	int findDigit();



	Ann();
	Ann( char *, char *, char *, char *, char *, char *);
	~Ann();

	void trainWeightsModel(int);
	void validateTestInput();
	void validateTestInputToFile(ostream &f);


	void showOutput();
	void showError();
	void showNode();
	void showWeight();

};




#endif /* ANN_H_ */
