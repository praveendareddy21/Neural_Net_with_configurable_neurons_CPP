/*
 * ann.cpp
 *
 *  Created on: Oct 19, 2016
 *      Author: Praveen
 */
#include"ann.h"
#include<iostream>
#include<math.h>
#include<iomanip>
#include<stdlib.h>
#include<fstream>
#include<stdio.h>
#include<time.h>
using namespace std;



float_data_type Ann::getEuclideanDistance(vector<float_data_type> X, vector<float_data_type> Y)
{
	float_data_type X_test, Y_test;
	float_data_type squareddist = 0.0;
	float_data_type result=0.0;
	for(unsigned i=0; i<X.size();i++){
		X_test = X[i];
		Y_test = Y[i];
		squareddist += pow(X[i] - Y[i], 2);
	}
	result = sqrt(squareddist);
	return result;
}

int Ann::findDigit(){
	float_data_type minDistance = -1;
	int minDigit = -1;
	float_data_type tempDistance = 0.0;
	std::vector<float_data_type> X;
	std::vector<float_data_type> Y;


	for(int i=0; i < structure[structure.size() -1]; i++){
		X.push_back((*outputTable)[structure.size() -1][i]);
	}
	for(int i=0; i < structure[structure.size() -1]; i++){
		Y.clear();
		for(int j=0; j < structure[structure.size() -1]; j++){
			Y.push_back(digit_encoding[i][j]);
		}
		tempDistance = getEuclideanDistance(X, Y);
		//cout<<"X size : "<<X.size()<<" Y size : "<<Y.size()<<endl;
		if(minDistance == -1){
			minDistance = tempDistance;
			minDigit = i;
		}
		else if(tempDistance < minDistance){
			minDistance = tempDistance;
			minDigit = i;
		}
	}

	return minDigit;
}

float_data_type Ann::getSigmoid(float_data_type in){
	float_data_type exp_value;
	float_data_type return_value;
	exp_value = exp(-in);
	return_value = ((float_data_type)1) / (1 + exp_value);
	 return return_value;
}

float_data_type Ann::getFSigmoid(float_data_type in){
	float_data_type exp_value;
	float_data_type return_value;
	exp_value = abs(in);
	return_value = ((float_data_type)in) / (1 + exp_value);
	 return return_value;
}

float_data_type Ann::getSigmoidError(float_data_type out, float_data_type error){
	return out * (1-out) * error;

}

float_data_type Ann::getRectifier(float_data_type in){
	return in==0 ? (0.01 * in ): in;
}
float_data_type Ann::getRectifierError(float_data_type in){
		return in==0 ? 0.01: 1;
	}


void Ann::initStructure(char * filename){
	fstream inFile;   // input file
	int z;

	inFile.open(filename);
	if (!inFile)
	{
	   cout << "The input file could not be opened."<<endl;
	}
	while(true){
		inFile>>z;
		if(inFile.eof())
			break;
		//cout<<" :"<<z<<endl;
		structure.push_back(z);
		neuronEnumList.push_back(SIGMOID);
		}


	std::cout<<"structure matrix"<<std::endl;
	for(unsigned i=0;i<structure.size();i++){
			std::cout<<structure[i]<<" "<<std::endl;
	}
	std::cout<<"--------------"<<std::endl;
}


void Ann::initTrainInput(char * filename){

	vector<float_data_type> temp;
	fstream inFile;   // input file
	float_data_type z;

	inFile.open(filename);
	if (!inFile)
	{
	   cout << "The input file could not be opened."<<endl;
	}

	while(true){
		if(inFile.peek() == EOF){
			break;
		}
	    //while (inFile.peek() != '\n')
	    for(int k=0; k<structure[0]; k++)
		{
			inFile>>z;
			temp.push_back(z);
	    }
		if(inFile.peek() == EOF){
			break;
		}
	    train_inputTable.push_back(temp);
	    temp.clear();

		}
	std::cout<<"Train input matrix"<<std::endl;
	for(unsigned i=0;i<train_inputTable.size();i++){
		for(unsigned j=0;j<train_inputTable[i].size();j++){
			std::cout<<train_inputTable[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"--------------"<<std::endl;


}

void Ann::initTrainOutput(char * filename){
	fstream inFile;   // input file
	int z;

	inFile.open(filename);
	if (!inFile)
	{
	   cout << "The input file could not be opened."<<endl;
	}

	while(!inFile.eof()){
		inFile>>z;
		train_output.push_back(z);
		}

	std::cout<<"train_output matrix"<<std::endl;
	for(unsigned i=0;i<train_output.size();i++){
			std::cout<<train_output[i]<<" "<<std::endl;
	}
	std::cout<<"--------------"<<std::endl;

}

void Ann::initTestInput(char * filename){
	vector<float_data_type> temp;
	fstream inFile;   // input file
	float_data_type z;

	inFile.open(filename);
	if (!inFile)
	{
	   cout << "The input file could not be opened."<<endl;
	}

	while(true){
		if(inFile.peek() == EOF){
			break;
		}
	    for(int k=0; k<structure[0]; k++)
		{
			inFile>>z;
			temp.push_back(z);
	    }
		if(inFile.peek() == EOF){
			break;
		}
	    test_inputTable.push_back(temp);
	    temp.clear();


		}
	std::cout<<"test_inputTable matrix"<<std::endl;
	for(unsigned i=0;i<test_inputTable.size();i++){
		for(unsigned j=0;j<test_inputTable[i].size();j++){
			std::cout<<test_inputTable[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"--------------"<<std::endl;


}

void Ann::initTestOutput(char * filename){
	fstream inFile;   // input file
	int z;

	inFile.open(filename);
	if (!inFile)
	{
	   cout << "The input file could not be opened."<<endl;
	}

	while(!inFile.eof()){
		inFile>>z;
		test_output.push_back(z);
		}

	std::cout<<"test_output matrix"<<std::endl;
	for(unsigned i=0;i<test_output.size();i++){
			std::cout<<test_output[i]<<" "<<std::endl;
	}
	std::cout<<"--------------"<<std::endl;

}

void Ann::initweight_Table(char * filename){

	int nodes = 1;
	fstream inFile;   // input file
	float_data_type z;
	for(unsigned i=0;i<structure.size();i++){
		nodes += structure[i];
	}
	weightTable = new vector<vector<float_data_type> > (nodes, vector<float_data_type>(nodes, 0) );

	inFile.open(filename);
	if (!inFile)
	{
	   cout << "The input file could not be opened."<<endl;
	}

	int irand;
	float_data_type wt;

	srand(time(NULL));

	irand = (rand() % 20) -10 ;

	wt = (float_data_type) irand / 1.0;
	cout<<"rand wt : "<<wt;


	for(int j=0; j<structure.size()-1;j++){
		for(int i=0;i<structure[j];i++){
			for(int k=0; k< structure[j+1]; k++){
				irand = (rand() % 20) -10 ;

				wt = (float_data_type) irand / 100.0;
				//cout<<"rand wt : "<<wt;
				//inFile>>z;
				(*weightTable)[(*Node_)[j][i]][(*Node_)[j+1][k]] = ( (float_data_type) irand / 100.0 );// z;
				//cout<<"setting (*weightTable) ["<<node[j][i]<<"]["<<node[j+1][k]<<"] as : "<< (*weightTable)[node[j][i]][node[j+1][k]] <<endl;//(*weightTable)[node[j][i]][node[j+1][k]]<<endl;
			}
		}
	}

	for(int j=1; j<structure.size();j++){
		for(int i=0;i<structure[j];i++){
			//cout<<"initializing (*weightTable) ["<<0<<"]["<<node[j][i]<<"] as : "<<0.01<<endl;
			(*weightTable)[0][(*Node_)[j][i]] = 0.01;  // weights from dummy to all nodes is 0.01
		}
	}
}

void Ann::initOutput(){
	outputTable = new vector<vector<float_data_type> > ();
	std::vector <int > :: iterator struct_iter;

	for(struct_iter=structure.begin();struct_iter!=structure.end();struct_iter++){
		(*outputTable).push_back(vector<float_data_type>(*(struct_iter), 0));
	}

}

void Ann::initDigitEncoding(){

	std::vector<std::vector<float_data_type> > out(10, std::vector<float_data_type>(10, 0.9));
	std::vector <int > :: iterator struct_iter;

	for(int i=0;i<10;i++){
		out[i][i] = 0.1;
	}
	digit_encoding = out;

	std::cout<<"digit_encoding matrix"<<std::endl;
	for(unsigned i=0;i<digit_encoding.size();i++){
		for(unsigned j=0;j<digit_encoding[i].size();j++){
			std::cout<<digit_encoding[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"--------------"<<std::endl;
}

void Ann::initError(){

	errorTable = new vector<vector<float_data_type> > ();
	std::vector <int > :: iterator struct_iter;

	for(struct_iter=structure.begin();struct_iter!=structure.end();struct_iter++){
		(*errorTable).push_back(vector<float_data_type>(*(struct_iter), 0));
	}
}

void Ann::initNode(){

	Node_ = new vector<vector<int> > ();

	std::vector<std::vector< int> > out;
	std::vector <int > :: iterator struct_iter;
	int nodenum=1;
	for(struct_iter=structure.begin();struct_iter!=structure.end();struct_iter++){
		vector<int> temp;
		for(int i=0;i<*(struct_iter);i++){
			temp.push_back(nodenum);
			nodenum++;
		}
		(*Node_).push_back(temp);
	}
	//(*Node_) = out;
}

void Ann::initNeuronList(){

	Neuron temp;
	int layer = 0;
	std::vector<std::vector< int> > out;
	std::vector <NeuronTypeEnum > :: iterator struct_iter;
	for(struct_iter=neuronEnumList.begin();struct_iter!=neuronEnumList.end();struct_iter++){
		if(*struct_iter == SIGMOID){
			temp = SigmoidNeuron(weightTable, errorTable, outputTable, Node_, layer);
		}
		else if(*struct_iter == INVSQUARE){
			temp = SigmoidNeuron(weightTable, errorTable, outputTable, Node_, layer);
		}



		neuronList.push_back(temp);
		layer++;
	}
}

void Ann::calculateValueAt(int layer, int nodeNum){

	neuronList[layer].doForwardPass(nodeNum);

	//SigmoidNeuron n(weightTable, errorTable, outputTable, Node_, layer);
	//n.doForwardPass(nodeNum);
	/*
	float_data_type value = (*weightTable)[0][(*Node_)[layer][nodeNum]];
	int input_node = 0;

	for(int i=0;i < (*outputTable)[layer-1].size();i++ ){
		input_node = (*Node_)[layer-1][i];
		value += (*outputTable)[layer-1][i]* (*weightTable)[input_node][(*Node_)[layer][nodeNum]];
	}


	(*outputTable)[layer][nodeNum] = getSigmoid(value);
	*/
	//output[layer][nodeNum] = getFSigmoid(value);

	//output[layer][nodeNum] = getRectifier(value);
}

void Ann::calculateErrorAt(int layer, int nodeNum){

	neuronList[layer].doBackwardPass(nodeNum, false, 0);

	//SigmoidNeuron n(weightTable, errorTable, outputTable, Node_, layer);
	//n.doBackwardPass(nodeNum, false, 0);

	/*
	int input_node = 0;
	float_data_type calculatedValue = (*outputTable)[layer][nodeNum];
	float_data_type errorV = 0.0;

	for(int i=0;i < (*outputTable)[layer+1].size();i++ ){
		//matError.set(0,i, error[layer+1][i]);
		input_node = (*Node_)[layer][nodeNum];


		errorV += (*errorTable)[layer+1][i] *  (*weightTable)[input_node][(*Node_)[layer+1][i]];
	}

	(*errorTable)[layer][nodeNum] = getSigmoidError(calculatedValue , errorV);

	//error[layer][nodeNum] = getRectifierError(errorV);

	 */
}

void Ann::calculateErrorAtOutputLayer(int layer, int nodeNum, float_data_type outputLayerValue){

	neuronList[layer].doBackwardPass(nodeNum, true, outputLayerValue);

	//SigmoidNeuron n(weightTable, errorTable, outputTable, Node_, layer);
	//n.doBackwardPass(nodeNum, true, outputLayerValue);

	//float_data_type calculatedValue = (*outputTable)[layer][nodeNum];
	//(*errorTable)[layer][nodeNum] =  getSigmoidError(calculatedValue, outputLayerValue - calculatedValue );
}

void Ann::updateErrorsInBackwardPass(){

	for(int j=structure.size()-2; j>=0;j--){
		for(int i=0;i<structure[j];i++){
			//cout<<"invoking updateError for "<<node[j][i]<<endl;
			calculateErrorAt(j,i);
		}
	}
}

void Ann::updateValuesInForwardPass(){

	for(int j=1; j<structure.size();j++){
		for(int i=0;i<structure[j];i++){
			//cout<<"invoking updateValue for "<<node[j][i]<<endl;
			calculateValueAt(j,i);
		}
	}
}

void Ann::updateWeights(){

	for(int j=1; j<structure.size();j++){
		vector<int> temp;
		for(int i=0;i<structure[j];i++){

			//cout<<"current node : "<<node[j][i]<<endl;
			(*weightTable)[0][(*Node_)[j][i]] =  (*weightTable)[0][(*Node_)[j][i]] + alpha * 1 * (*errorTable)[j][i] ;
			//cout<<"setting  ["<<0<<"]["<<node[j][i]<<"] as : "<<(*weightTable)[0][node[j][i]]<<endl;
		}
	}

	for(int j=0; j<structure.size()-1;j++){
		vector<int> temp;
		for(int i=0;i<structure[j];i++){

			for(int k=0; k< structure[j+1]; k++){

				(*weightTable)[(*Node_)[j][i]][(*Node_)[j+1][k]] =  (*weightTable)[(*Node_)[j][i]][(*Node_)[j+1][k]] + alpha * (*outputTable)[j][i] * (*errorTable)[j+1][k] ;

				//cout<<"setting  ["<<node[j][i]<<"]["<<node[j+1][k]<<"] as : "<<(*weightTable)[node[j][i]][node[j+1][k]]<<endl;
			}
		}
	}

}

void Ann::doForwardPassIteration(std::vector< std::vector<float_data_type> > inputlayer, int number){

	for(int j=0; j<structure[0];j++){
		(*outputTable)[0][j] = inputlayer[number][j];
	}
	updateValuesInForwardPass();

}

void Ann::doBackwardPassIteration(std::vector< int> outputlayer,int number){
	int digit = outputlayer[number];

	for(int j=0; j<structure[structure.size()-1];j++){
		calculateErrorAtOutputLayer(structure.size()-1, j, digit_encoding[digit][j]);
	}
	updateErrorsInBackwardPass();

}

void Ann::validateTestInput(){
	int total_tests = test_inputTable.size(), digit = -1;
	int correctly_validated = 0;
	float_data_type accuracy = 0.0;
	for(int i=0;i<total_tests;i++){
		doForwardPassIteration(test_inputTable,i);
		digit = findDigit();
		cout<<"digit : "<<digit<<endl;

		if(digit == test_output[i]){
			correctly_validated++;
		}
	}
	accuracy = ((float_data_type) correctly_validated  )/ total_tests;

	cout<<"total : "<<total_tests<<" validated : "<<correctly_validated<<endl;
	cout<<"accuracy : ";
	cout << showpoint << fixed << setprecision(12) << accuracy << endl;

}

void Ann::trainWeightsModel(int iteration_count){

	for(int j=0;j<iteration_count;j++){

		for(int i=0;i<train_inputTable.size();i++){
			doForwardPassIteration(train_inputTable,i);
			//showOutput();
			doBackwardPassIteration(train_output,i);
			//showError();
			updateWeights();
			//showWeight();
		}
	}

}

Ann::Ann(){


	alpha= 0.01;
	initStructure("structure.txt");
	initDigitEncoding();
	initNode();
	initOutput();
	initError();


	//showNode();

	initTrainInput("train_input.txt");
	initTrainOutput("train_output.txt");
	initTestInput("test_input.txt");
	initTestOutput("test_output.txt");
	initweight_Table("weights.txt");
	initNeuronList();

	cout<<"Sizes : "<<train_inputTable.size()<<" : "<<train_output.size() <<" : "<< test_inputTable.size() <<" : "<<test_output.size()<<endl;






	trainWeightsModel(500);
	validateTestInput();



	/*

	updateValuesInForwardPass();


	cout<<"#######################################"<<endl;


	updateErrorsInBackwardPass();

	showError();


	cout << showpoint << fixed << setprecision(12) << error[0][0] << endl;
	cout << showpoint << fixed << setprecision(12) << error[0][1] << endl;

	updateWeights();
	*/

}































Ann::Ann(  char * train_input_file, char *train_output_file, char * test_input_file, char *test_output_file,
		char * structure_file, char * weight_file){

	alpha= 0.01;
	initStructure("structure.txt");
	initDigitEncoding();
	initNode();
	initOutput();
	initError();


	initTrainInput("train-input.txt");
	initTrainOutput("train-output.txt");
	initTestInput("test-input.txt");
	initTestOutput("test-output.txt");
	initweight_Table("weights.txt");

	initNeuronList();

}




void Ann::showOutput(){
	std::cout<<"output matrix"<<std::endl;
	for(unsigned i=0;i<(*outputTable).size();i++){
		for(unsigned j=0;j<(*outputTable)[i].size();j++){
			std::cout<<(*outputTable)[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"--------------"<<std::endl;
}

void Ann::showError(){
	std::cout<<"Error matrix"<<std::endl;
	for(unsigned i=0;i<(*errorTable).size();i++){
		for(unsigned j=0;j<(*errorTable)[i].size();j++){
			std::cout<<(*errorTable)[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"--------------"<<std::endl;

}

void Ann::showNode(){
	std::cout<<"Node matrix"<<std::endl;
	for(unsigned i=0;i<(*Node_).size();i++){
		for(unsigned j=0;j<(*Node_)[i].size();j++){
			std::cout<<(*Node_)[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"--------------"<<std::endl;
}

void Ann::showWeight(){
	std::cout<<"Weight matrix"<<std::endl;
	for(unsigned i=0;i<(*weightTable).size();i++){
		for(unsigned j=0;j<(*weightTable)[i].size();j++){
			std::cout<<(*weightTable)[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"--------------"<<std::endl;
}



