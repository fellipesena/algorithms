#include <bits/stdc++.h>

using namespace std;

int adjList[38][38];
int parent[38];

int mapea(string s){
    if (s == "XXL"){
        return 1;
    }
    if (s == "XL"){
        return 2;
    }
    if (s == "L"){
        return 3;
    }
    if (s == "M"){
        return 4;
    }
    if (s == "S"){
        return 5;
    }
    if (s == "XS"){
        return 6;
    }
    return 0;
}

bool BFS(int s, int t){
    bool visited[38];
    for (int i = 0; i < 38; i++){
        visited[i] = false;
        parent[i] = -1;
    }
            
    queue<int> q;
        
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
            
    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int i = 0; i < 38; i++){
            if(!visited[i] && adjList[u][i] > 0){
            q.push(i);
            parent[i] = u;
            visited[i] = true;
            }
        }
    }        
    return visited[t];
}

int FordFulkerson(int s, int t){
    int maxflow = 0;
    
    while(BFS(s, t)){
        int pathflow = 10000;
        
        for(int v = t; v != s; v = parent[v]){
            int u = parent[v];
            pathflow = min(pathflow, adjList[u][v]);
        }
        
        for(int v = t; v != s; v = parent[v]){
            int u = parent[v];
            adjList[u][v] = adjList[u][v] - pathflow;
            adjList[v][u] = adjList[v][u] + pathflow;
        }       
        maxflow = maxflow + pathflow;
    }
    return maxflow;
}

int main (){
    int casos, n, m;
    cin >> casos;
    while (casos > 0){
        string c1, c2;
        cin >> n >> m;
        int pesoCam = n / 6;

        for(int i = 1; i <= 6; i++){
            adjList[0][i] = pesoCam;
        }

        for(int i = 7; i < 7 + m; i++){
            cin >> c1 >> c2;
            adjList[i][7 + m] = 1;
            adjList[mapea(c1)][i] = 1;
            adjList[mapea(c2)][i] = 1;
        }
        
        int maxFlux = FordFulkerson(0, m + 7);

        //cout << maxFlux << endl;

        if (maxFlux == m){
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }

        for(int i = 0; i < 38; i++){
            for(int j = 0; j < 38; j++){
                adjList[i][j] = 0;
            }
        }
        casos--;
    }
    return 0;
}