/*
 * neuron.cpp
 *
 *  Created on: Dec 27, 2016
 *      Author: Consumer
 */

#include"neuron.h"
#include<math.h>


TanhNeuron::TanhNeuron(vector<vector< float_data_type> > *w , vector<vector< float_data_type> > *e,
		 vector<vector< float_data_type> > *o , vector<vector< int> > *n , int l): Neuron(w, e, o, n, l){

}

float_data_type TanhNeuron::applyActivation(float_data_type in){
	float_data_type exp_value;
	float_data_type return_value;
	return_value = ((float_data_type) tanh(in));
	 return return_value;
}

float_data_type TanhNeuron::applyActivationError(float_data_type out, float_data_type error){
	return out * (1-(tanh(error) * tanh(error))) ;
}
