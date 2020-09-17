#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;
using graph = vector<vector<int>>;
 
const ll mod = 1000000007;
const int INF = 1001001001;
 
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
 
int main() {
	cin.tie(0);
   	ios::sync_with_stdio(false);
	int h, w; cin >> h >> w;
	vector<string> mp(h);
	int sx, sy, gx, gy;
	cin >> sx >> sy >> gx >> gy;
	--sx; --sy; --gx; --gy;
	for(int i = 0; i < h; i++) cin >> mp[i];
 
	vector<vector<int>> cost(h, vector<int> (w, INF));
	cost[sx][sy] = 0;
 
	deque<pair<int, int>> que;
	que.push_front({sx, sy});
 
	while(!que.empty()){
		auto p = que.front(); que.pop_front();
		int x = p.first, y = p.second;
 
		// using Move A
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			if(mp[nx][ny] == '#') continue;
			if(cost[nx][ny] > cost[x][y]){
				cost[nx][ny] = cost[x][y];
				que.push_front({nx, ny});
			}
		}
		
		// using Move B
		for(int i = -2; i <= 2; i++){
			for(int j = -2; j <= 2; j++){
				if(i == 0 && j == 0) continue;
				int nx = x + i, ny = y + j;
				if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
				if(mp[nx][ny] == '#') continue;
				if(cost[nx][ny] > cost[x][y] + 1){
					cost[nx][ny] = cost[x][y] + 1;
					que.push_back({nx, ny});
				}
			}
		}
	}
	int ans = cost[gx][gy] - cost[sx][sy];
	if(ans == INF) cout << -1 << endl;
	else cout << ans << endl;
} 
