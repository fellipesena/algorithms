#include <bits/stdc++.h>
using namespace std;

int umAlgarismo(int x){
    int total = 0;
    while (x / 10 != 0 || x % 10 != 0){
        int y = x % 10;
        total = y + total;
        x = x / 10;
    }
    if(total > 9){
        umAlgarismo(total);
    }
    else {
        return total;
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    while (n != 0 && m != 0){
        int totalN = umAlgarismo(n);
        int totalM = umAlgarismo(m);
        if (totalN > totalM){
            cout << 1 << endl;
        }
        else if (totalN < totalM){
            cout << 2 << endl;
        }
        else {
            cout << 0 << endl;
        }
        cin >> n >> m;
    }
    return 0;
}