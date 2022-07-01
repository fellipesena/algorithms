#include<bits/stdc++.h>
using namespace std;

vector<int> adjList[2001];
stack<int> pilha;

int compNo, num;
int high[2001];
int PE[2001];
int comp[2001];

void componente(int v){
	PE[v] = num;
	num++;
	pilha.push(v);
	high[v] = PE[v];

	for(int i = 0; i < adjList[v].size(); i++){
		int w = adjList[v][i];
		if(PE[w] == 0){

			componente(w);
			high[v] = min(high[v], high[w]);
		}
		else {
			if(PE[w] < PE[v] && comp[w] == 0){
				high[v] = min(high[v], PE[w]);
			}
		}
	}
	if(high[v] == PE[v]){
		compNo++;
		int aux;
		do{
			aux = pilha.top();
			pilha.pop();
			comp[aux] = compNo;
		} while (aux != v);
	}
}

int main(){
	int m, n, v, w, p;
    cin >> n >> m;
    while (n != 0 && m != 0){
    	for(int i = 0; i <= n; i++){
    		PE[i] = 0;
    		comp[i] = 0;
    		adjList[i].clear();
    	}
		for(int i = 0; i < m; i++){
			cin >> v >> w >> p;
			adjList[v].push_back(w);
			if (p == 2){
				adjList[w].push_back(v);
			}
		}
		compNo = 0;
		num = 1;

		componente(1);

		int aux = 0;
		for (int k = 1; k <= n; k++){
		    if (comp[k] == 1){
		    	aux ++;
		    }
		}

		if (aux == n){
		    cout << "1" << endl;
		}
		else {
		    cout << "0" << endl;
		}
		cin >> n >> m;
    }

}
