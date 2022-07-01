#include <bits/stdc++.h>
using namespace std;

#define LEN(x) (int)x.size()
#define ALL(x) x.begin(), x.end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

const int MOD = 1'000'000'007;
const double EPS = 0.000'000'001;

inline int fcmp(double x, double y)
{ return (x < y + EPS ? (x < y - EPS ? -1 : 0) : 1);}

const int N = 505;
vpii g[N];
int edge[N][N];
int dist[N], n, m, s, d;
vpii be[N];

int dijkstra(){
    for(int i = 0; i < n; i++)    {
        dist[i] = MOD;
        be[i].clear();
    }
    dist[s] = 0;
    set<pii> pq;
    pq.insert(pii(0, s));
    while(!empty(pq)){
        int v, c;
        tie(c, v) = *pq.begin();
        pq.erase(pq.begin());
        if(dist[v] < c) continue;
        for(pii next : g[v]){
            if(dist[next.second] > c + next.first){
                be[next.second].assign(1, pii(v, edge[v][next.second]));
                dist[next.second] = c + next.first;
                pq.insert({dist[next.second], next.second});
            }
            else if(dist[next.second] == c + next.first)
                be[next.second].emplace_back(v, edge[v][next.second]);
		}
    }
    queue<pii> q;
    q.push(pii(d, 0));
    vi aux(n, MOD);
    while(!empty(q)){
        int w, v;
        tie(v, w) = q.front();
        q.pop();
        for(pii u : be[v]){
            q.push(pii(u.first, w + u.second));
            aux[u.first] = w + u.second;
        }
    }
    aux[d] = 0;
    for(int i = 0; i < n; i++)
        for(pii j : be[i])
            if(aux[i] + dist[j.first] + edge[j.first][i] == dist[d])
                edge[j.first][i] = 0;
    return dist[d];
}

int dijkstra2(){
    for(int i = 0; i < n; i++)
        dist[i] = MOD;
    dist[s] = 0;
    set<pii> pq;
    pq.insert(pii(0, s));
    while(!empty(pq)){
        int v, c;
        tie(c, v) = *pq.begin();
        pq.erase(pq.begin());
        if(dist[v] < c) continue;
        for(pii next : g[v]){
            if(edge[v][next.second]){
                if(dist[next.second] > c + next.first){
                    dist[next.second] = c + next.first;
                    pq.insert({dist[next.second], next.second});
                }
            }
        }
    }
    return dist[d];
}

int main(){
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ios_base::sync_with_stdio(false);
    cout.precision(10);

    while(cin >> n >> m && n && m){
        memset(edge, 0, sizeof edge);

        cin >> s >> d;

        for(int i = 0; i < n; i++)
            g[i].clear();

        for(int i = 0; i < m; i++){
            int a, b, c;
            cin >> a >> b >> c;
            
            g[a].emplace_back(c, b);
            edge[a][b] = c;
        }

        int best = dijkstra();
        int now = dijkstra2();

        cout << (now == MOD ? -1 : now) << endl;
    }

    return 0;
}
