#include<bits/stdc++.h>
using namespace std;

vector <string> labirinto;
int altura;
pair <int, int> ultVertice;

void bfsAltura(int i, int j, int n, int m){
    if (labirinto[i][j] != '.'){
        return;
    }
    altura = 0;
    ultVertice = {i, j};
    vector <string> labirintoAux = labirinto;
    queue <pair<pair<int, int>, int>> fila;
    fila.push(make_pair(make_pair(i, j), 0));

    while(!fila.empty()){
        pair <pair<int, int>, int> aux;
        aux = fila.front();
        fila.pop();
        if(aux.first.first > 0){
            if(labirintoAux[aux.first.first - 1][aux.first.second] == '.'){
                labirintoAux[aux.first.first][aux.first.second] = '#';
                fila.push(make_pair(make_pair(aux.first.first - 1, aux.first.second), aux.second + 1));
            }
        }
        if(aux.first.first < n - 1){
            if(labirintoAux[aux.first.first + 1][aux.first.second] == '.'){
                labirintoAux[aux.first.first][aux.first.second] = '#';
                fila.push(make_pair(make_pair(aux.first.first + 1, aux.first.second), aux.second + 1));
            }
        }
        if(aux.first.second > 0){
            if(labirintoAux[aux.first.first][aux.first.second - 1] == '.'){
                labirintoAux[aux.first.first][aux.first.second] = '#';
                fila.push(make_pair(make_pair(aux.first.first, aux.first.second - 1), aux.second + 1));
            }
        }
        if(aux.first.second < m - 1){
            if(labirintoAux[aux.first.first][aux.first.second + 1] == '.'){
                labirintoAux[aux.first.first][aux.first.second] = '#';
                fila.push(make_pair(make_pair(aux.first.first, aux.first.second + 1), aux.second + 1));
            }
        }
        if (aux.second > altura){
            ultVertice = make_pair(aux.first.first, aux.first.second);
            altura = aux.second;
        }
    }
}

int main (){
    int n, m;
    string aux;
    cin >> n >> m;
    //inclui toda a entrada em labirinto (matriz de adjacencia)
    while (n != 0 && m != 0){
        int distMax = 0;
        for (int i = 0; i < n; i++){
            cin >> aux;
            labirinto.push_back(aux);
            aux.clear();
        }
        // roda a matriz de adjacencia até achar um . (caminho vazio) para fazer o bfs, que vai setar
        // a altura máxima desse ponto em altura e vai retornar o ultimo nó (folha) dessa árvore
        int i = 0;
        bool achou = false;
        while (!achou){
            for(int j = 0; j < m; j++){
                if(labirinto[i][j] == '.'){
                    bfsAltura(i, j, n, m);
                    achou = true;
                    break;
                }
            }
            i++;
        }
        // executa agora novamente bfs, mas dessa vez do ultimo nó que foi retornado na primeira bfs, para
        // assim ter a certeza de que a altura máxima é aquela inicial, caso não seja, atualiza para depois retornar
        bfsAltura(ultVertice.first, ultVertice.second, n, m);
        cout << altura << endl;       
        labirinto.clear();
        cin >> n >> m;
    }
    return 0;
}