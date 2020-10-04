#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#define ll long long
using namespace std;


int main() {
	int N;
	ll K;
	cin >> N >> K;

	vector<int> v(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> v[i];
	}

	int cnt = 0;
	int curr = 1;
	set<int> s;

	do {
		s.insert(curr);
		curr = v[curr];
		K--;
	} while (s.find(curr) == s.end() && K > 0);

	if (K != 0) {
		int cycle = 0;
		int cycleStart = curr;
		do {
			curr = v[curr];
			cycle++;
		} while (curr != cycleStart);
		K %= cycle;
	}

	for (int i = 0; i < K; i++) {
		curr = v[curr];
	}

	cout << curr << endl;
}