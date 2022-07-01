#include<bits/stdc++.h>
using namespace std;

vector <int> subset;
vector <pair<int, int> > coord;
vector <pair<double, pair<int, int> > > arestas;
// o vetor arestas recebe o peso (distancia) e o par de vertices que faz parte
// ex: seja a aresta com peso 10 pertencente aos vertices 2, 4, então:
// arestas = { 10, (2, 4)}

void setSet(int n){
    subset.assign(n, -1);
}

int busca(int v){
    if (subset[v] == -1)
        return v;
    return busca(subset[v]);
}

void uniao(int v1, int v2){
    int v1set = busca(v1);
    int v2set = busca(v2);
    subset[v1set] = v2set;
}

bool ciclo(int v1, int v2){
    if (busca(v1) == busca(v2))
        return true;
    else return false;
}

double distancia(double x1, double y1, double x2, double y2){
    double res;
    res = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    return res;
}

void kruskal(){
    int v1, v2;
    double menorDistancia = 0;
    for(int i = 0; i < arestas.size(); i++){
        v1 = arestas[i].second.first;
        v2 = arestas[i].second.second;
        if (!ciclo(v1, v2)){
            uniao(v1, v2);
            menorDistancia = menorDistancia + arestas[i].first;
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << menorDistancia << endl;
}

int main (){
    int C, n, v1, v2;
    cin >> C;
    while(C--){
        cin >> n;
        setSet(n);
        for (int i = 0; i < n; i++){
            cin >> v1 >> v2;
            coord.push_back(make_pair(v1, v2));
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (i != j){
                    double dist = 0, x1, y1, x2, y2;
                    x1 = coord[i].first;
                    y1 = coord[i].second;
                    x2 = coord[j].first;
                    y2 = coord[j].second;
                    dist = distancia(x1, y1, x2, y2) / 100;
                    arestas.push_back(make_pair(dist, make_pair(i, j)));
                }
            }
        }
        sort(arestas.begin(), arestas.end());
        kruskal();
        arestas.clear();
        coord.clear();
        subset.clear();
    }
    return 0;
}