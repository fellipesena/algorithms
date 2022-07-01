#include<bits/stdc++.h>
using namespace std;

vector<int> adjList[301];
vector<bool> visitado(301);

vector<int> grafo;

void dfs(int u){
    if(visitado[u]){
    return;
    }
    visitado[u] = true;
    for(auto x:adjList[u]){
        dfs(x);
    }
    grafo.push_back(u);
    return;
}

int main(){
    int n, m;
    cin >> m >> n;
    map<string,int> map;
    for(auto k:visitado){
    	visitado[k] = false;
    }
    string nome1, nome2;
    int i = 1;
    for(int k = 0; k < n; k++){
		cin >> nome1 >> nome2;
		if(!map[nome1]){
			map[nome1] = i;
			i++;
		}
		if(!map[nome2]){
			map[nome2] = i;
			i++;
		}
		adjList[map[nome1]].push_back(map[nome2]);
		adjList[map[nome2]].push_back(map[nome1]);
    }
    int qtdArvores = 0;
    for(int k = 1; k < i; k++){
		if(!visitado[k]){
		dfs(k);
		qtdArvores++;
		for (int k = 0; k < grafo.size(); k++){
			cout << grafo[k] << " - ";
		}
		grafo.clear();
		cout << endl;
		}
    }
     cout << qtdArvores << endl;
}
