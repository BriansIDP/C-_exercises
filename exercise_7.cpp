#include <iostream>
#include <cmath>
using namespace std;

class Body
{
public:
    double x, y;    // position
    double dx, dy;  // velocity
    double mass;    // mass
    double ax, ay;  // computed acceleration for Euler
};

void calculate_accel(Body b[], int n)
{
	for (int i=0;i<n;i++)
	{
		b[i].ax = 0.0;
		b[i].ay = 0.0;
	}
	double dist[2]={0, 0};
	double dist_abs = 0.0;
	double ax=0.0;
	double ay=0.0;
	for (int i=0;i<n;i++)
	{
		for (int j=i+1; j<n; j++)
		{
			dist[0] = b[j].x - b[i].x;
			dist[1] = b[j].y - b[i].y;
			dist_abs = sqrt(dist[0]*dist[0]+dist[1]*dist[1]);
			ax = b[i].mass*b[j].mass*dist[0]/(dist_abs*dist_abs*dist_abs);
			ay = b[i].mass*b[j].mass*dist[1]/(dist_abs*dist_abs*dist_abs);
			b[i].ax += ax/b[i].mass;
			b[i].ay += ay/b[i].mass;
			b[j].ax -= ax/b[j].mass;
			b[j].ay -= ay/b[j].mass;
		}
	}
}

void update_pos_velocity(Body b[], int n, double h)
{
	for(int i=0;i<n;i++)
	{
		b[i].x = b[i].x+h*b[i].dx;
		b[i].y = b[i].y+h*b[i].dy;
		b[i].dx = b[i].dx+h*b[i].ax;
		b[i].dy = b[i].dy+h*b[i].ay;
	}
}

int main()
{
	int n;
	cin>>n;
	Body b[n];
	double numer=0.0;
	double denom=0.0;
	double arccos=0.0;
	for (int i=0;i<n;i++)
	{
		cin>>b[i].x;
		cin>>b[i].y;
		cin>>b[i].dx;
		cin>>b[i].dy;
		cin>>b[i].mass;
		b[i].ax = 0.0;
		b[i].ay = 0.0;
	}
	double h=0.01;
	double time=0.0;
	while(time<10.0)
	{
		calculate_accel(b, n);
		update_pos_velocity(b, n, h);
		if (n==3)
		{
			numer = (b[2].x-b[0].x)*(b[1].x-b[0].x)+(b[2].y-b[0].y)*(b[1].y-b[0].y);
			denom = sqrt((b[2].x-b[0].x)*(b[2].x-b[0].x)+(b[2].y-b[0].y)*(b[2].y-b[0].y))*
					sqrt((b[1].x-b[0].x)*(b[1].x-b[0].x)+(b[1].y-b[0].y)*(b[1].y-b[0].y));
			arccos = acos(numer/denom);
		}
		if (arccos<0.01) cout<<time<<endl;
		/*for (int i=0; i<n; ++i) 
		{
			cout << b[i].dx << " " << b[i].dy << endl;
		}*/
		time+=h;
	}
}
