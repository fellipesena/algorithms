#include<bits/stdc++.h>
using namespace std;

vector<int>adjList[1000];
int MAX = 0;
int visited[1000], I = 0;

void dfs(int u){
    if(visited[u] == -I) visited[u] = 0;
    for(int j = 0; j < adjList[u].size(); j++){
        int v = adjList[u][j];
        if(visited[v] == -I){
            visited[u] = visited[u]+1;
            visited[v] = -1;
            dfs(v);
        }else{
            visited[u] = visited[u] + 1;
            visited[v] = visited[v] - 1;
        }
    }
}

int main(){

    //lendo
    int n, m, a, b;
    cin>>MAX>>m; //num vertices e num de arestas
    n = MAX;
    I = MAX + 1;
    for(int i = 1; i <= n; i++){
    	visited[i] = -I;
    }

    for(int i = 0; i < m; i++){
        cin>>a>>b;
        adjList[a].push_back(b);
    }

    dfs(1);

    for(int i = 0; i < n; i++){
        if(visited[i] != 0){
            cout<<"N é euleriano\n";
            return 0;
        }
    }

    cout<<"É euleriano\n";
    return 0;
}
