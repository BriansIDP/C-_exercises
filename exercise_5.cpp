#include <iostream>
using namespace std;

const int NUM_COINS = 8;
const int coins[NUM_COINS] = {1, 2, 5, 10, 20, 50, 100, 200};

int ways(int X, int C) 
{
	if (X>coins[C] && C>=0) return ways(X-coins[C], C)+ways(X, C-1);
	else if (X==coins[C] && C>=0) return 1+ways(X, C-1);
	else if(X<coins[C] && C>=0) return ways(X, C-1);
	else return 0;
}

int main()
{
	int X;
	cin >> X;
	cout<<ways(X, 7);
}
