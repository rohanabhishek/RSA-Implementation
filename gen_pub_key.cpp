#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

int range = 4;
int rand_max = 2147483647;
long gcd(long a, long h) 
{ 
    long temp; 
    while (1) 
    { 
        temp = a%h; 
        if (temp == 0) 
          return h; 
        a = h; 
        h = temp; 
    } 
} 
bool millerTest(long, long);
long modulo(long,long,long);

bool isprime(long t,int a){
	if(t <= 1 | t == 4) return false;
	if(t<=3) return true;

	long d = t-1;
	while(d%2 == 0) d /=2;

	for(int i=0;i<a;i++){
		if(!millerTest(d,t)) return false;
	}
	return true;
}

bool millerTest(long d,long n){
	long a;
	long lb = pow(10,range-1);
	long up = pow(10,range)-1;
	a = (double) rand() * up / rand_max;
	a = 2 + a % (n-4);
	// cout<<"a "<<a<<endl;
	long rem = modulo(a,d,n);

	if(rem == 1 || rem == n-1) return true;

	while(d != n-1){
		rem  = (rem * rem) % n;
		d *= 2;
		if(rem==1) return false;
		if(rem == n-1) return true;
	}
	return false;
}

long modulo(long b,long e,long mod){
	long ans=1;
	b = b % mod;

	while(e > 0){
		if (e & 1) ans = (ans * b ) % mod;
		e= e>>1;
		b = (b * b )% mod;
	}

	return ans;

}

int main(int argc, char** argv){
	if(argc == 2){
		long x;
		int acc = 4;
		int count =0;
		long lb = pow(10,range-1);
		long up = pow(10,range)-1;
		long* n = new long[2];
		// cout<<"good"<<endl;

		double b;
		int ni;
		ni = remove(argv[1]);
		ofstream myfile(argv[1], ios::out | ios::app);
		while(count!=2){
			ni++;
			b = rand() * (up - lb) * 1.0/ rand_max;	
			x = lb  + b;
			if(isprime(x,acc)){
				myfile<<x<<endl;
				n[count] = x;
				count++;
			}

		}
		long fi_n = (n[0] -1) * (n[1] -1);
		long exp =0;
		long max_exp = fi_n;
		lb = n[0]*n[1];
		while(exp == 0){
			up = 2 + (double) rand() * min(max_exp , fi_n -3)/ rand_max;
			if(lb % up != 0 && gcd(up,fi_n) == 1) exp = up;
		}
		myfile<<exp<<endl;



		myfile.close();
	}
	else{
		cout<<"Please give one argument (filename) to save public keys.";
	}
	
	return 0;

}
