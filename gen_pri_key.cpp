#include <bits/stdc++.h>
#include <string>
using namespace std;

int main(int argc, char** argv){
	if(argc == 3){

		fstream file; 
	    string word,filename; 
	  
	    // filename of the file 
	    filename = argv[1]; 
	  
	    // opening file 
	    file.open(filename);
	    
	    long p,q,e;
	    
	    int c =0;
	    while(file >> word){
	    	if(c == 0) p = stol(word);
	    	else if(c==1) q = stol(word);
	    	else e = stol(word);
	    	c++;

	    }
	    
	    file.close();
	    ofstream myfile(argv[2], ios::out);
	    long fi_n  = (p -1)*(q -1);
	    long double d; 	
	    // d = (rand() * fi_n + 1) * 1.0/e;
	    int k=1;
	    if((fi_n % e) != 0){
	    	cout<<"not case"<<endl;
	    	while(1){
	    	if ((k * fi_n + 1) % e == 0) {d = (k*fi_n + 1) * 1.0/e;break;}
	    	k++;
	    	}	
	    }
	    else{
	    	d = (fi_n + 1) * 1.0/e;	
	    }
	    myfile << std::fixed << std::setprecision(15) << d;
	}
	else{
		cout<<"Please provide two arguments (filenames). First (Public Key file) Second(To save Private Key)";
	}
	return 0;
}