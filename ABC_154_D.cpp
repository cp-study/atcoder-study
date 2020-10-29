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
#include <iomanip>
#define ll long long
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	vector<double> exVal(N);
	double ans = 0;
	double sum = 0;
	for (int i = 0; i < N; i++) {
		exVal[i] = (v[i]*(v[i]+1)/2.0)/v[i];
	}
	for (int i = 0; i < K; i++) {
		sum += exVal[i];
	}
	for (int i = K; i < N; i++) {
		ans = max(ans, sum);
		sum = sum - exVal[i - K] + exVal[i];
	}
	ans = max(ans, sum);
	cout << setprecision(10);
	cout << ans << endl;
}