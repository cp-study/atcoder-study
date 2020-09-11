#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <functional>
using namespace std;
typedef long long ll;

int arr[5001];
int points[5001];
pair<int, ll> memo[5001]; // {횟수,총점수}

int main() {

	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> points[i];
	}

	for (int i = 1; i <= N; i++) {
		vector<int> nodes;
		int initIdx = i;
		if (memo[i].first != 0) continue;

		int currIdx = i;
		ll point_sum = 0;
		int cnt = 0;
		do {
			cnt++;
			currIdx = arr[currIdx];
			point_sum += points[currIdx];
			nodes.push_back(currIdx);
		} while (currIdx != initIdx);

		for (int i = 0; i < nodes.size(); i++) {
			memo[nodes[i]] = { cnt, point_sum };
		}
	}

	ll maxim = -10e20;
	for (int i = 1; i <= N; i++) {
		int tempK = K;
		ll sum = 0;
		double multiple = (double)tempK / memo[i].first;
		if (multiple > 2) {
			if (memo[i].second > 0) {
				sum += ((int)multiple - 1) * memo[i].second;
			}
			tempK -= ((int)multiple - 1)*memo[i].first;
		}

		int currIdx = i;
		for (int j = 0; j < tempK; j++) {
			currIdx = arr[currIdx];
			sum += points[currIdx];
			maxim = max(maxim, sum);
		}
	}

	cout << maxim << endl;
}
