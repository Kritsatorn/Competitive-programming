#include <bits/stdc++.h>
using namespace std;
vector< pair< int, int > > Edge[20010];
int d[20010];

void dijkstra(int start) {
    int u, v, i, c, w;
    priority_queue< pair< int, int >, vector< pair< int, int > >, greater< pair< int, int > > > Q;
    memset(d, INT_MAX, sizeof d);
    Q.push(pair< int, int >(0, start));
    d[start] = 0;

    while(!Q.empty()) {
        u = Q.top().second;
        c = Q.top().first;
        Q.pop();
        if(d[u] < c) continue;
        for(i = 0; i < Edge[u].size(); i++) {
            v = Edge[u][i].first;
            w = Edge[u][i].second;
            if(d[v] > d[u] + w) {
                d[v] = d[u] + w;
                Q.push(pair< int, int >(d[v], v));
            }
        }
    }
}

int main() {
    int T, n, e, i, u, v, w, start, dist, kase = 0;
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d %d %d", &n, &e, &start, &dist);
        for(i = 0; i <= n; i++) Edge[i].clear();
        for(i = 0; i < e; i++) {
            scanf("%d %d %d", &u, &v, &w);
            Edge[u].push_back(pair< int, int >(v, w));
            Edge[v].push_back(pair< int, int >(u, w));
        }

        dijkstra(start);
        if(d[dist] == INT_MAX) printf("Case #%d: unreachable\n", ++kase);
        else printf("Case #%d: %d\n", ++kase, d[dist]);
    }
    return 0;
}