#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair <int, int> ii;
typedef vector<int> vi;
typedef vector<vector<ii>> vvii;
#define FOR(a, b, i) for (int i = a; i<b; ++i)
#define INF 10000000

int V, s, T, E;
vvii AdjList;


// Dijkstra, O((V+E)logV)
int dijkstra() {
	vi dist(V, INF); dist[s] = 0;
	priority_queue< ii, vector<ii>, greater<ii> > pq; // functional
	pq.push(ii(0, s));
	while (!pq.empty()) {
		ii front = pq.top(); pq.pop();
		int d = front.first, u = front.second;
		if (d > dist[u]) continue; // important check
		for (int j = 0; j < (int)AdjList[u].size(); j++) {
			ii v = AdjList[u][j]; //Adjlist: (node, weight)
			if (dist[u] + v.second < dist[v.first]) {
				dist[v.first] = dist[u] + v.second;
				pq.push(ii(dist[v.first], v.first));
			}
		}
	}

	int sol = 0;
	FOR(0, V, i) {
		if (dist[i] <= T)++sol;
	}
	return sol;
}

int main() {

	while (cin >> V) {

		cin >> s; cin >> T; cin >> E;
		--s;
		AdjList.clear();
		AdjList.resize(V);

		int a, b, x;
		while (E--) {
			cin >> a; cin >> b; cin >> x;

			//change E direction when filling the AdjList
			AdjList[b - 1].push_back({ a - 1, x });
		}

		cout << dijkstra() - 1 << "\n";
	}

	return 0;
}

