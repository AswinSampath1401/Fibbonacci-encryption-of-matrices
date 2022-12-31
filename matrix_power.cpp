#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
double c[3][3];
double b[3][3]={{0,1,0},{1,1,0},{0,0,1}};
double a[3][3]={{0,1,0},{1,1,0},{0,0,1}};
double inva[3][3];
void disp(double x[3][3])
{
    int i,j;
    for (i = 0; i <3; i++)
    {
        for(j=0;j<3;j++)
        {
            cout<<x[i][j]<<" ";
        }
        cout<<"\n";
    }
    
}

void mul(double a[3][3],double b[3][3])
{
    int sum;
    /////////////////////////////////////////
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            c[i][j]=0;
			for(int k=0; k<3; k++)
			{
				c[i][j] = c[i][j] + a[i][k] * b[k][j];
			}
        }
    }
    //disp(c);
    
}
void assign()
{
    int i,j;
    for (i = 0; i <3; i++)
    {
        for(j=0;j<3;j++)
        {
            a[i][j]=c[i][j];
        }
    }
    
}

void powermat(int n)
{
    int l=1;
    while(l<n)
    {
        mul(a,b);
        assign();
        l++;
    }
    disp(a);
}

void invmat()
{
    int i,j;
	double determinant=0;
	for(i = 0; i < 3; i++)
		determinant = determinant + (a[0][i] * (a[1][(i+1)%3] * a[2][(i+2)%3] - a[1][(i+2)%3] * a[2][(i+1)%3]));
	
	//cout<<"determinant: "<<determinant;
	
	//cout<<"\n\nInverse of matrix is: \n";
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++)
			inva[i][j]=((a[(j+1)%3][(i+1)%3] * a[(j+2)%3][(i+2)%3]) - (a[(j+1)%3][(i+2)%3] * a[(j+2)%3][(i+1)%3]))/ determinant;
		
	}
    //disp(inva);
}


int main()
{
    int n=1;
    double private_key=100000;
  time_t start, end; 
  time(&start); 
//disp(a);
    mul(a,a);
	powermat(2);
	powermat(3);
	powermat(4);
	
	//disp(a)
        invmat();
   // auto start = high_resolution_clock::now();
    /*for(double i=0;i<private_key;i=i+1)
    {

		/*if(i>5000)
		{
		cout<<i<<endl;
		break;
		}
    }*/
    //auto end = high_resolution_clock::now();
	
	time(&end); 
	double time_taken = double(end - start); 
    cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(5); 
    cout << " sec " << endl; 
    return 0; 
    /*printf("Time taken %d",end-start);
    return 0;*/
}