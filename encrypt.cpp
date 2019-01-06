#include <bits/stdc++.h>

using namespace std;


long modulo(long b,long e,long mod){
	long ans=1;
	b = b % mod;
	
	while(e > 0){
		if (e & 1) ans = (ans * b ) % mod;
		e/=2;
		b = (b * b)% mod;
	}

	return ans;

}


int main(int argc, char** argv){
	if(argc == 4){
		ifstream myfile(argv[1],ios::in);
		int count = 0;
		
	    string line;
	    while (getline(myfile, line)) count++;
    	myfile.close();
    	ifstream myfile1(argv[1],ios::in);
    	int now =1;
    	long temp;

    	fstream file; 
	    string word,filename; 
	  
	    // filename of the file 
	    filename = argv[3]; 
	  
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
	    long n = p*q;
	    // cout<<"p "<<p<<endl;
	    // cout<<"q "<<q<<endl;
	    // cout<<"n "<<n<<endl;
	    // cout<<"e "<<e<<endl;
	    // cout<<"fi_n "<<(p-1)*(q-1)<<endl;
	    // cout<<"e divides fi_n "<<((p-1)*(q-1) % e == 0)<<endl;
	    file.close();
	    long res;
    	ofstream outfile(argv[2], ios::out);
		while(getline(myfile1, line)){
			if(now != count) line += "\n";
			now++;
			for(int i=0;i<line.length();i++){
				temp = long(line[i]);
				// outfile<<modulo(temp,e,n)<<endl;
				res = modulo(temp,e,n);
				outfile<<res<<endl;
			}
		}
		// temp = 82;
		// for(int i=0;i<10;i++){
		// 	res = modulo(temp,e,n);
		// 	cout<<temp<<" "<<res<<endl;
		// }
		myfile1.close();
	}
	else{
		cout<<"Please provide three arguments."<<endl;
		cout<<"First: File to be encrypted"<<endl;
		cout<<"Second: Encrypted file name"<<endl;
		cout<<"Third: Public Keys File"<<endl;
	}
	return 0;
}