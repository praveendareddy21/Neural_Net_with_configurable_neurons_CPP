/*
main driver function
 */


#include <bitset>
#include<iostream>
#include<exception>
#include<vector>
#include<sstream>
#include<map>
#include<math.h>

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include"ann.h"



using namespace std;




 int main(int argc, char* argv[]){



	 //Ann a;
	 //cout<<endl<<"out in main at the end"<<endl;

	 //return 0;

	 filebuf fb;
	 fb.open("acc_out.txt", ios::out);
	 ostream os(&fb);

	 for (int i=0; i < 5 ; i ++){
		 Ann b;// other constructor
		 b.trainWeightsModel(500);
		 b.validateTestInputToFile(os);

	 }
	 fb.close();

	 return 0;
}

