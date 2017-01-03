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
float_data_type getSigmoidError_(float_data_type out, float_data_type error){
	return out * (1-out) * error;

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

	float_data_type value = processInput(nodeNum);
	float_data_type activated_value =  applyActivation(value);
	updateOutput(nodeNum, activated_value);

}
		
void Neuron::doBackwardPass(int nodeNum, bool isOuputLayer, float_data_type OutputValue){

	float_data_type error_value = processError(nodeNum, isOuputLayer, OutputValue  );
	float_data_type calculatedValue = (*output)[layer][nodeNum];
	float_data_type activated_error =  applyActivationError(calculatedValue, error_value);
	updateError(nodeNum, activated_error);

}

float_data_type Neuron::processInput(int nodeNum){
	float_data_type value = (*weightTable)[0][(*Node_)[layer][nodeNum]];
	int input_node = 0;

	for(int i=0;i < (*output)[layer-1].size();i++ ){
		input_node = (*Node_)[layer-1][i];
		value += (*output)[layer-1][i]* (*weightTable)[input_node][(*Node_)[layer][nodeNum]];
	}

	return value;
}
float_data_type Neuron::applyActivation(float_data_type in){
	float_data_type exp_value;
	float_data_type return_value;
	exp_value = exp(-in);
	return_value = ((float_data_type)1) / (1 + exp_value);
	return return_value;
}
void Neuron::updateOutput(int nodeNum, float_data_type activated){
	(*output)[layer][nodeNum] =activated;
}

float_data_type Neuron::processError(int nodeNum, bool isOuputLayer, float_data_type OutputValue){
	if(isOuputLayer){
		float_data_type calculatedValue = (*output)[layer][nodeNum];
		return OutputValue - calculatedValue;
	}
	else{
		int input_node = 0;
		float_data_type calculatedValue = (*output)[layer][nodeNum];
		float_data_type errorV = 0.0;

		for(int i=0;i < (*output)[layer+1].size();i++ ){
			//matError.set(0,i, error[layer+1][i]);
			input_node = (*Node_)[layer][nodeNum];
			errorV += (*error)[layer+1][i] *  (*weightTable)[input_node][(*Node_)[layer+1][i]];
		}
		return errorV;
	}
}
float_data_type Neuron::applyActivationError(float_data_type out, float_data_type error){
	return out * (1-out) * error;
}
void Neuron::updateError(int nodeNum, float_data_type activated_error){
	(*error)[layer][nodeNum] = activated_error;
}




SigmoidNeuron::SigmoidNeuron(vector<vector< float_data_type> > *w , vector<vector< float_data_type> > *e,
		 vector<vector< float_data_type> > *o , vector<vector< int> > *n , int l): Neuron(w, e, o, n, l){

}

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
