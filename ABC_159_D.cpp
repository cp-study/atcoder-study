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
#define ll long long
using namespace std;

int main() {
	int N;
	cin >> N;
	ll sum = 0;
	map<int, int> numCnt;
	vector<int> v;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		sum += numCnt[num];
		numCnt[num]++;
		v.push_back(num);
	}

	for (int i = 0; i < N; i++) {
		cout << sum - (numCnt[v[i]] - 1) << endl;
	}
}