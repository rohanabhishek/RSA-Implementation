#include <bits/stdc++.h>

using namespace std;

long double modulo(long b,long double e,long mod){
	long double frac,in,temp;

	long exp,ans =1;
	frac = modf(e,&in);
	temp = pow(b,frac);
	temp = fmod(temp,mod);
	// b = fmod(b,mod);
	// cout<<"temp frac exp "<<temp<<" "<<frac<<" "<<exp<<endl;
	exp = in;
	// cout<<"temp frac exp mod "<<temp<<" "<<frac<<" "<<exp<<" "<<mod<<endl;
	while(exp > 0){
		if (exp & 1) ans = fmod((ans * b ), mod);
		exp= exp>>1;
		b = fmod((b * b ), mod);
	}
	// cout<<"ans temp "<<ans<<" "<<temp<<endl;
	return fmod((ans * temp),mod);

}

int main(int argc, char** argv){
	if(argc == 5){
		// ifstream myfile(argv[1],ios::out);
		string line;double d;
		string file_enc = argv[1];
		string file_pub = argv[3];
		string file_priv  = argv[4];
		fstream file;
		// cout<<"Rohan1"<<endl;
		// long d1;
		file.open(file_priv);
		while(file >> line){
			d = stod(line);
			// d1 = stol(line);
		}
		// cout<<"d "<<d<<endl;
		long n,p,q;
		int c =0;
		file.close();
		file.open(file_pub);
		while(file >> line){
			// cout<<"file yes"<<endl;
			if(c==0) {p = stol(line);}
			else if(c==1) q = stol(line);
			else break;
			c++;
		}
		n = p*q;
		// cout<<"p "<<p<<endl;
		// cout<<"q "<<q<<endl;
		// cout<<"n "<<n<<endl;
		long temp;
		// cout<<"Rohan2"<<endl;
		file.close();
		// file.open(argv[1]);
		ofstream myfile(argv[2], ios::out);
		fstream f1;
		f1.open(file_enc);

		long double ans;
		while(f1 >> line){
			// cout<<"Rohan"<<endl;
			temp = stol(line);
			ans = modulo(temp,d,n);
			// cout<<temp<<" "<<ans<<endl;
			myfile << char(ans);

		}

	}
	else{
		cout<<"Please provide four arguments"<<endl;
		cout<<"First: Filename of encrypted file"<<endl;
		cout<<"Second: Filename of decrypted file"<<endl;
		cout<<"Third: Filename of public key file"<<endl;
		cout<<"Fourth: Filename of private key file"<<endl;
	}
}