/*
 * neuron.cpp
 *
 *  Created on: Dec 27, 2016
 *      Author: Consumer
 */

#include"neuron.h"
#include<math.h>


InvSquareNeuron::InvSquareNeuron(vector<vector< float_data_type> > *w , vector<vector< float_data_type> > *e,
		 vector<vector< float_data_type> > *o , vector<vector< int> > *n , int l): Neuron(w, e, o, n, l){

}

float_data_type InvSquareNeuron::applyActivation(float_data_type in){
	float_data_type exp_value;
	float_data_type return_value;
	return_value = ((float_data_type)1) / (1 + (in * in));
	 return return_value;
}

float_data_type InvSquareNeuron::applyActivationError(float_data_type out, float_data_type error){
	float_data_type a ,b, c;
	a = 2* error;
	b = (error*error +1) * (error * error +1);
	return a/b;
}
