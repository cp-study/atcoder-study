#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int main() {
	int N;
	cin >> N;

	int dp[2001];
	dp[0] = 1;

	for (int i = 1; i <= N; i++) {
		dp[i] = 0;
	}

	for (int i = 3; i <= N; i++) {
		for (int j = 3; j <= i; j++) {
			dp[i] = (dp[i]+ (dp[i - j]))%1000000007;
		}
	}
	cout << dp[N] << endl;
}