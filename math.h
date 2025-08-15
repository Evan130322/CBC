#include<bits/stdc++.h>
#include"Micro.h"
using namespace std;
struct power{
	long long a;int b;
	power(long long a=1,int b=0):a(a),b(b){}
	void output(){
		cout<<a<<"^"<<b;
	}
};
struct Math{
	private: 
		bitset<Prime_max+9> Prime; 
		vector<int> prime;
		int prime_long;
	public:
		Math(){
			Prime.set();
			Prime[0]=0;
			Prime[1]=0;
			prime_long=1;
		}
		char initialize_prime(int x){
			if(x>Prime_max) return ErrArgTooLarge; 
			if(x<=0) return ErrInvArg;
			for(int i=prime_long+1;i<=x;i++){
				if(Prime[i]==1) prime.push_back(i);
				for(int j=0;j<prime.size()&&i*prime[j]<=x;j++){
					Prime[i*prime[j]]=0;
					if(i%prime[j]==0)break;
				}
			}
			prime_long=max(prime_long,x);
			return ErrNoErr;
		}
		char gcd(int x,int y,int& res){
			if(x==0&&y==0) return ErrNan;
			if(y==0){
				res=x;
				return 0;
			}
			return gcd(y,x%y,res);
		}
		char lcm(int x,int y,int& res){
			int pres;
			int g=gcd(x,y,pres);
			if(g!=0) return g;
			else{
				if(pres==0)return ErrDivZero;
				res=(int)((long long)(x*y)/pres);
				return 0;
			}
		}
		char int_power(long long x,vector<power>& res){
			if(x<=0) return ErrInvArg;
			res.clear();
			for(int i=0;prime[i]<=sqrt(x)&&i<prime.size();i++){
				if(x%prime[i]==0){
					power p(prime[i]);
					while(x%prime[i]==0){
						x=x/prime[i];p.b++;
					}
					res.push_back(p);
				}
			}
			for(int i=prime_long+1;i<=sqrt(x);i++){
				if(i>Prime_max) return ErrTimeExceed; 
				if(x%i==0){
					power p(i);
					while(x%i==0){
						x=x/i;p.b++;
					}
					res.push_back(p);
				}	
		 	}
			power p(x,1);
			res.push_back(p);
			return ErrNoErr;
		}
};
