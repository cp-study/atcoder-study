#include <iostream>
#include <math.h>
using namespace std;
long long n,ans;
int main()
{
	cin>>n;
	for(long long i=2;i<=sqrt(n);i++){
		long long x=i;
		while(n%x==0){
			n/=x;
			x*=i;
			ans++;
		}
		while(n%i==0){
          		n/=i;
        	}
	}
	if(n!=1){
      ans++;
    }
	cout<<ans;
}
