#include <iostream>    // for cin, cout, etc.
#include <vector>      // for storing polynomials
using namespace std;   // to refer to the above without 'std::' prefix

// Use this function to test your work as you go
void print_coefficients(const vector<double>& p)
{
    for (unsigned int i=0; i<p.size(); ++i)
        cout << p[i] << " ";

    cout << endl;
}

double eval_poly(const vector<double>& p, double x)
{
	double value=0.0;
    // put code here
    for (int i=p.size()-1;i>=0;i--)
    {
		value = p[i]+value*x;
	}
	return value;
}
// put other function definitions here, before main

int main()
{
    int n;	
    cin >> n;  // read degree

    vector<double> p(n+1);

    for (int i=0; i<n+1; ++i) 
    {
        cin >> p[i];  // read the i^th coefficient
    } 
   
    double x;   // where to evaluate p
    
    cin >> x;  

    // TODO: evaluate p(x), output result
    cout<<eval_poly(p, x)<<endl;

    vector<double> d(n);

    // TODO: compute derivative d
    for(int i=1;i<n+1;i++)
    {
		d[i-1]=p[i]*i*1.0;
	}
	print_coefficients(d);
	cout<<eval_poly(d, x)<<endl;
    // TODO: evaluate d(x), output result
}
