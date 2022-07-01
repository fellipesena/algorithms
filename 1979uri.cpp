#include<bits/stdc++.h>
using namespace std;

vector<int> adjList[101];
vector<int> cor;
queue<int> fila;

bool bipartido(){
	cor[1] = 0;
    fila.push(1);
    bool ehbipartido = true;
    while (!fila.empty() && ehbipartido){
    	int x = fila.front();
    	fila.pop();
    	for(int i = 0; i < adjList[x].size(); ++i){
    		if(cor[adjList[x][i]] != -1 && cor[adjList[x][i]] == cor[x]){
    			ehbipartido = false;
    			break;
    		}
    		else if (cor[adjList[x][i]] == -1){
    			cor[adjList[x][i]] = cor[x] ^ 1;
    			fila.push(adjList[x][i]);
    		}
    	}
    }
    while(!fila.empty()){
    	fila.pop();
    }
    cor.clear();
    return ehbipartido;
}

int main(){
	int n;
	cin >> n;
    while (n != 0){
        int x, y;
        string linha;

		for(int i = 0; i < n; i++){
			cin >> x;
			cin.ignore();
			getline (cin, linha);
			stringstream adj(linha);
			while (adj >> y){
				adjList[x].push_back(y);
			}
			adj.clear();
		}
		cor.assign(n+1, -1);

		if(bipartido()){
			cout << "SIM" << endl;
		}
		else{
			cout << "NAO" << endl;
		}
		for(int i = 1; i <= n; i++){
			adjList[i].clear();
		}
		cin >> n;
    }
}
