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
class Neuron{
public:
	Neuron();
	void doForwardPass(std::vector<std::vector< int> > node, std::vector< std::vector<float_data_type> > *weightTable,
			std::vector<std::vector<float_data_type> > *output_, int layer, int nodeNum);
	void doBackwardPass(std::vector<std::vector< int> > node, std::vector< std::vector<float_data_type> > *weightTable,
			std::vector<std::vector<float_data_type> > *error_ ,int layer, int nodeNum);
};

#endif /* NEURON_H_ */

