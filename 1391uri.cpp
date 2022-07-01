#include <bits/stdc++.h>
using namespace std;

//bool arestas[501][501];
vector <pair<int, int>> pesos[501];
int parentes[502][502];
vector <int> distancias;

/*void removeCaminho(int v, int parent[]){
    int remCam = v;
    int antCam = parent[v];
    //verifica o vertice anterior a v (parent[v]), caso seja -1
    //quer dizer que v é o vertice inicial, encerrando a remoção
    //caso não, remove o caminho de parent[v] até v e faz o mesmo
    //para o parent[parent[v]] e parent[v], até que se encontre -1;
    while(antCam != -1){
        /*for(int i = 0; i <= pesos[antCam].size(); i++){
            if(pesos[antCam][i].first == remCam){
                pesos[antCam].erase(pesos[antCam].begin() + i);
            }
        }
        arestas[antCam][remCam] = false;
        remCam = antCam;
        antCam = parent[remCam];
    }
}*/

void dijkstra(int n, int s, int d, int dis[]){
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater <pair<int, int>>> Q;
    Q.push(make_pair(0, s));
    //dis.assign(n, 1001);
    //parent.assign(n, -1);
    for(int i = 0; i < n; i++){
        dis[i] = 1001;
        //parent[i] = -1;
    }
    dis[s] = 0;
    while(!Q.empty()){
        pair<int, int> aux = Q.top();
        Q.pop();
        int v = aux.second;
        for(int j = 0; j < pesos[v].size(); j++){
            int w = pesos[v][j].first;
            int pesoVW = pesos[v][j].second;
            //if (arestas[v][w] == true){
                if (dis[w] > dis[v] + pesoVW){
                    //parent[w] = v;
                    dis[w] = dis[v] + pesoVW;
                    parentes[v][w] = dis[w];
                    Q.push(make_pair(dis[w], w));
                }
            //}
        }
    }
}

int main (){
    int n, m, s, d, u, v, p, menorCam;
    cin >> n >> m;
    while (n != 0 && m != 0){
        cin >> s >> d;
        int dis[n];//, parent[n];
        //Pesos: dígrafo de entrada contendo vertice destino e peso em forma de par
        // ex: pesos[0] = (1, 2)(2,3) ==> de 0 a 1 existe caminho peso 2, de 0 a 2
        // existe caminho peso 3, assim por diante
        for(int i = 0; i < m; i++){
            cin >> u >> v >> p;
            //arestas[u][v] = true;
            pesos[u].push_back(make_pair(v, p));
        }
        //dis.clear();
        //parent.clear();

        //efetua dijkstra para encontrar o menor caminho do dígrafo completo
        dijkstra(n, s, d, dis);

        for(int i = 0; i < n; i++){
            distancias.push_back(parentes[i][n-1]);
        }

        cout << "Parentes:" << endl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << parentes[i][j] << "  ";
            }
            cout << endl;
        }
        sort(distancias.begin(), distancias.end(), greater<int>());
        cout << "Distancias: " << endl;
        for (int i = 0; i < distancias.size(); i++){
            cout << distancias[i] << "  ";
        }
        cout << endl;

        //menorCam = dis[d];

        for(int i = 0; i < distancias.size(); i++){
            if (distancias[i] > dis[d]){
                menorCam = distancias[i];
            }
        }

        cout << "MenorCam: " << menorCam << endl;

        //associa o menor caminho do dígrafo completo a menorCam
        //menorCam = dis[d];
        //remove o menor caminho do dígrafo completo
        //removeCaminho(d, parent);

        //dis.clear();
        //parent.clear();

        //efetua dijkstra no dígrafo sem o menor caminho, assim irá encontrar o 2 menor caminho
        //dijkstra(n, s, d, dis, parent);

        //verifica se o menor caminho é igual menorCam (menor caminho do digrafo completo)
        //caso sim, quer dizer que ainda não encontrou o quase menor caminho, logo, efetua
        //dijkstra até encontrar
        /*while(menorCam == dis[d]){
            dijkstra(n, s, d, dis, parent);
            removeCaminho(d, parent);
        }*/
        //quando encontrar o menor caminho (dis[d] != menorCam) verifica qual o "quase menor caminho"
        //caso seja 1001 (infinito, visto que a maior distancia é 1000), retorna -1 (impossível)
        //caso contrário retorna o "quase menor caminho"
        if (menorCam > 1001){
            cout << "-1" << endl;
        }
        else {
            cout << menorCam << endl;
        } 
        for(int i = 0; i < n; i++){
            pesos[i].clear();
        }
        //dis.clear();2
        //parent.clear();
        distancias.clear();
        cin >> n >> m;
    }
    return 0;
}