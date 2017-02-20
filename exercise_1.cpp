#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int N=1;
	double total=0.0;
	while(sqrt(total*6.0)<3.14)
	{
		total+=1.0/(N*N);
		N++;
		cout<<total<<endl;
	}
	cout<<N<<endl;
	cout<<sqrt(total*6.0);
}
