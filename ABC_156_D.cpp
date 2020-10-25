#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <functional>
#include <cstdlib>
#include <list>
#define ll long long
#define MOD 1000000007
using namespace std;

ll _pow(ll p, ll e) {
	ll ret = 1;
	while (e) {
		if (e & 1) ret = ret*p %MOD;
		p = (p * p) % MOD;
		e /= 2;
	}
	return ret;
}

ll comb(ll r, ll n) {
	ll numOfANumer = 1;
	for (int i = 0; i < r; i++) {
		numOfANumer = numOfANumer * (n - i) % MOD;
	}
	ll numOfADen = 1;
	for (int i = 1; i <= r; i++) {
		numOfADen = numOfADen * i % MOD;
	}
	return numOfANumer * _pow(numOfADen, MOD - 2) % MOD;
}

int main() {
	ll n, a, b;

	cin >> n >> a >> b;

	ll ans = _pow(2, n) - 1;

	cout << (2*MOD + ans - comb(a,n)- comb(b,n))%MOD << endl;
}