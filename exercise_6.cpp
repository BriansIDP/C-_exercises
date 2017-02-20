#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int escape_iterations(double c_real, double c_imag, int max_iterations)
{
	double c_mag = c_real*c_real+c_imag*c_imag;
	int count = 0;
	double c_r = c_real;
	double c_i = c_imag;
	double c_temp = 0.0;
	while(c_mag<4 && count<max_iterations)
	{
		c_temp = c_r;
		c_r = c_real + (c_r*c_r - c_i*c_i);
		c_i = c_imag +2.0*c_temp*c_i;
		cout<<c_i<<endl;
		c_mag = c_r*c_r+c_i*c_i;
		cout<<c_r<<' '<<c_i<<' '<<c_mag<<endl;
		count++;
	}
	return count+1;
}

int main()
{
	/*double c_real, c_imag;
	cin>>c_real;
	cin>>c_imag;
	cout<<escape_iterations(c_real, c_imag, 5);*/
	int column=0, row=0;
	cin>>column;
	cin>>row;
	double x_space = 4.0/(column-1);
	double y_space = 4.0/(row-1);
	double sample_y[row];
	double sample_x[column];
	for (int i=0;i<column;i++)
	{
		sample_x[i] = -2+x_space*i*1.0;
	}
	for (int i=0;i<row;i++)
	{
		sample_y[i] = -2+y_space*i*1.0;
	}
	
	ofstream file("test.pgm");
    const int max_intensity = 255;
    // Write the PGM header
    file << "P2" << endl << column << " " << row << endl << max_intensity << endl;
    for (int i=0; i<row; ++i) 
    {
        for (int j=0; j<column; ++j)
        {
            // Output the intensity value of the pixel at row, col
            file << escape_iterations(sample_x[j], sample_y[i], 250) << " ";
        }
		file << endl;
    }
    cout << "This text will appear on the console" << endl;
}
