/*
 * neuron.cpp
 *
 *  Created on: Feb 18, 2016
 *      Author: Praveen
 */

#include"neuron.h"
#include<math.h>


GatedSigmodNeuron::GatedSigmodNeuron(vector<vector< float_data_type> > *w , vector<vector< float_data_type> > *e,
		 vector<vector< float_data_type> > *o , vector<vector< int> > *n , int l): Neuron(w, e, o, n, l){

}

float_data_type GatedSigmodNeuron::applyActivation(float_data_type in){
  // activation code here
}

float_data_type GatedSigmodNeuron::applyActivationError(float_data_type out, float_data_type error){
      // Error calculation code here
}
