#include<iostream>
#include<cstring>
using namespace std;

#define MAX 10000000

long long divisors[MAX + 1] = { 0, };
int n;
long long sum = 0;

int main() {
	cin >> n;

	memset(divisors, 0, sizeof(divisors));

	for (int i = 1; i <= MAX; i++) {
		for (int j = i; j <= MAX; j += i) {
			++divisors[j];
		}
	}
	
	for (int i = 1; i <= n; i++) {
		sum += divisors[i]*i;
	}

	cout << sum;
}
