#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <deque>
#include <tuple>
#include <map> 
#include <set>
#include <stack>
#include <functional>
#define ll long long
using namespace std;

class StockSpanner {
public:
	vector<int> v;
	StockSpanner() {

	}

	int next(int price) {
		v.push_back(price);
		int cnt = 0;
		for (int i = v.size() - 1; i >= 0; i--) {
			if (v[i] <= price) {
				cnt++;
			}
			else break;
		}
		return cnt;
	}
};

int main() {
}