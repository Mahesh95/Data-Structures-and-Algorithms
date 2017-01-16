#include <iostream>
using namespace std;

// m is the number of coins, and a change of n is to be made
int countSol(int coins[], int m, int n){
	int table[m+1][n+1];
	for(int i = 0; i <= m; i++){
		table[i][0] = 1;
	}

	for(int i = 0; i <= n; i++){
		table[0][i] = 0;
	}

	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			// x no of ways to produce change of j excluding coins[i] + y no of ways of producing change of j-coins[i]
			int x = table[i-1][j];
			int y = ((j-coins[i]>=0) ? table[i][j-coins[i]] : 0);
			table[i][j] = x + y;
		}
	}

	return table[m][n];
}

int main(){
	int coins[] = {0,2,5,3,6};
	cout << countSol(coins,4,10);
}