#include <bits/stdc++.h>
using namespace std;
const int NN = 2001;
int res[NN] = { 0 };
void bfs(vector<int> g[],int start) {
	queue<pair<int,int>> q;
	q.push(make_pair(start, 0));
	bool visited[NN] = {false};
	visited[start] = true;
	//cout << "시작노드" << start << "\n";
	while (!q.empty()) {
		auto item = q.front();
		int cur = item.first;
		int d = item.second;
		q.pop();
		if (d != 0) {
			res[d] += 1;
			//cout << "현재노드" << cur << " 거리 " << d << "\n";
		}
		for (int i = 0; i<g[cur].size(); i++) {
			int node = g[cur][i];
			if (!visited[node]) {
				q.push(make_pair(node, d + 1));
				visited[node] = true;
			}
		}
	}
}

int main() {
	int N, X, Y;
	cin >> N >> X >> Y;
	vector<int> g[NN];
	for (int i = 1; i < N; i++) {
		g[i].push_back(i + 1);
		g[i + 1].push_back(i);
	}
	g[X].push_back(Y);
	g[Y].push_back(X);

	for (int i = 1; i < N+1; i++) {
		bfs(g, i);
	}
	for (int i = 1; i <N; i++) {
		cout << res[i]/2 << "\n";
	}
}