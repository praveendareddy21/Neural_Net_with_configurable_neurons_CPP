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
	
	/*
	virtual void processInput();
	virtual void applyActivation();
	virtual void updateOutput();

	virtual void processError();
	virtual void applyActivationError();
	virtual void updateError();
	*/
};

#endif /* NEURON_H_ */

