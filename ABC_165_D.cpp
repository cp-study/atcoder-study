#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
using namespace std;


int main() {
	long long A, B, N;
	cin >> A >> B >> N;

	long long x1 = min(B - 1, N);

	long long ans1 = floor((A * x1) / B);

	cout << ans1 << endl;
}