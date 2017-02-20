#include <iostream>
using namespace std;

double my_function(double value, double constant)
{
	return value*value-constant;
}

double square_root(double c)
{
	double a=0.0;
	double b=c;
	double pi=c/2.0;
	while(pi-a > 0.0001)
	{
		if (my_function(pi, c) == 0)
		{
			return pi;
		}
		else if (my_function(a, c)*my_function(pi, c)<0.0)
		{
			b=pi;
		}
		else
		{
			a=pi;
		}
		pi=(a+b)/2.0;
	}
	return pi;
}
int main()
{
	double c=3;
	cout<<square_root(c);
}
