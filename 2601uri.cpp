#include<bits/stdc++.h>
using namespace std;

char dado[6];

int main(){
	int c, count1, count2, count3;
	cin >> c;
	for (int i = 0; i < c; i++){
		count1 = count2 = count3 = 0;
		cin >> dado[0];
		cin >> dado[1] >> dado[2] >> dado[3] >> dado[4];
		cin >> dado[5];

		if(dado[0] == '*'){
			//count1++;
		}
		if(dado[5] == '*'){
			count1++;
		}
		if(dado[1] == '*'){
			count2++;
		}
		if(dado[4] == '*'){
			count2++;
		}
		if(dado[2] == '*'){
			count3++;
		}
		if(dado[3] == '*'){
			count3++;
		}
		if (count1 == count2 == 2 || count2 == count3 == 2 || count1 == count3 == 2){
			cout << count1 *count2 *count3 << endl;
		}
		else
		cout << count1 + count2 + count3 << endl;
	}
	return 0;
}
