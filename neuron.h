/*
 * neuron.h
 *
 *  Created on: Dec 27, 2016
 *      Author: Consumer
 */

#ifndef NEURON_H_
#define NEURON_H_

#include<vector>
#include"type_defs.h"
#include<iostream>
#include<math.h>
#include<iomanip>

using namespace std;
class Neuron{
public:
	vector<vector< float_data_type> > * weightTable;
	vector<vector< float_data_type> > * error;
	vector<vector< float_data_type> > * output;
	std::vector<std::vector< int> > *Node_;
	int layer;

	Neuron();
	Neuron(vector<vector< float_data_type> > *w , vector<vector< float_data_type> > *e,
	 vector<vector< float_data_type> > *o , vector<vector< int> > *n , int l);
	

	void doForwardPass(int nodeNum);
	void doBackwardPass(int nodeNum, bool isOuputLayer, float_data_type OutputValue);
	

	virtual float_data_type processInput(int nodeNum);
	virtual float_data_type applyActivation(float_data_type in);
	virtual void updateOutput(int nodeNum, float_data_type activated);

	virtual float_data_type processError(int nodeNum, bool isOuputLayer, float_data_type OutputValue);
	virtual float_data_type applyActivationError(float_data_type out, float_data_type error);
	virtual void updateError(int nodeNum, float_data_type activated_error);

};

#endif /* NEURON_H_ */

