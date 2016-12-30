/*
 * neuron.cpp
 *
 *  Created on: Dec 27, 2016
 *      Author: Consumer
 */

#include"neuron.h"


float_data_type getSigmoid_(float_data_type in){
	float_data_type exp_value;
	float_data_type return_value;
	exp_value = exp(-in);
	return_value = ((float_data_type)1) / (1 + exp_value);
	 return return_value;
}


Neuron::Neuron(){
	weightTable= NULL;
	error= NULL;
	output= NULL;
	Node_ = NULL;
	layer = 0;
}
Neuron::Neuron(vector<vector< float_data_type> > *w , vector<vector< float_data_type> > *e,
		 vector<vector< float_data_type> > *o , vector<vector< int> > *n , int l):weightTable(w), error(e), output(o), Node_(n), layer(l){

}
void Neuron::doForwardPass(int nodeNum){

	float_data_type value = (*weightTable)[0][(*Node_)[layer][nodeNum]];
		int input_node = 0;

		for(int i=0;i < (*output)[layer-1].size();i++ ){
			input_node = (*Node_)[layer-1][i];
			value += (*output)[layer-1][i]* (*weightTable)[input_node][(*Node_)[layer][nodeNum]];
		}


		(*output)[layer][nodeNum] = getSigmoid_(value);
		//output[layer][nodeNum] = getFSigmoid(value);



}
		
void Neuron::doBackwardPass(int nodeNum, bool isOuputLayer, float_data_type OutputValue){
}
