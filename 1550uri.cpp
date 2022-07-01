#include <bits/stdc++.h>

#define pi pair<int, int>
#define mp(x,y) make_pair(x,y)
using namespace std;

vector <int> inversos[10001];

// Função que retorna o inverso de um inteiro
int inverso(int a){
	int r, inv = 0;
	while (a)
	{
		r = a % 10;
		a = a / 10;
		inv = inv * 10 + r;
	}
	return inv;
}

// Função para preencher o "grafo"
void inverter(){
    for(int i = 0; i < 10001; i++){
        inversos[i].push_back(i + 1);
        inversos[i].push_back(inverso(i));
    }
}

int bfs(int a, int b){
    int next, invs;
    bool visitados[10001];
    for (int i = 0; i < 10001; i++){
        visitados[i] = false;
    }
    queue <pi> fila;

    fila.push(mp(a, 0));
    visitados[a] = true;
    
    while(!fila.empty()){
        pi aux;
        aux = fila.front();
        fila.pop();

        for(int i = 0; i < inversos[aux.first].size(); i++){
            if(visitados[inversos[aux.first][i]] == false){
                if(inversos[aux.first][i] == b){
                    return aux.second + 1;
                }
                visitados[inversos[aux.first][i]] = true;
                fila.push(mp(inversos[aux.first][i], aux.second + 1));
            }
        }
    }
    return 0;
}

int main(){ 
    int t, result; 
    inverter();
    cin >> t; 
    while(t > 0){
        int a, b;
        cin >> a >> b;
        result = bfs(a, b);
        cout << result << endl;

        t--;
    }
    for (int i = 0; i < 10001; i++){
        inversos[i].clear();
    }
    return 0;
}