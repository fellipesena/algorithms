#include<bits/stdc++.h>
using namespace std;

int main (){
    int n, matriz[101][101];
    cin >> n;
    while (n != 0){
        int aux = 1, m = n;
        while(m > 0){
            for(int i = aux-1; i <= n-aux; i++){
                for(int j = aux-1; j <= n-aux; j++){
                    matriz[i][j] = aux;
                }
            }
            aux++;
            m--;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if (j == 0){
                    printf("%3d", matriz[i][j]);
                }
                else {
                    printf(" %3d", matriz[i][j]);
                }
            } printf("\n");
        }
        printf("\n");
        cin >> n;
    }
    return 0;
}