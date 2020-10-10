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
    string S;

    cin >> S;

    int multTen = 1;
    int num = 0;
    int ans = 0;
    map<int, int> m;
    m[0] = 1;
    for (int i = S.size() - 1; i >= 0; i--) {
        num += multTen * (S[i] - '0');
        num %= 2019;
        ans += m[num];
        m[num]++;
        multTen *= 10;
        multTen %= 2019;
    }

    cout << ans << endl;
}