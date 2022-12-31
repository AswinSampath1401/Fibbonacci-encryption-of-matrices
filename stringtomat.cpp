#include<bits/stdc++.h>
using namespace std;

int mat[3][3];

void tomat(string y)
{
    int sc=0;
    if(y.length()>9)
    {
        cout<<"Not yet planned that much"<<endl;
        exit(1);
    }
    else
    {
        for(int i=0;i<3;i++)
        {   
            for(int j=0;j<3;j++)
            {
                mat[i][j] = y[sc]-'A';
                sc++;     
            }
        }

    }
    
}

void disp(int x[][3])
{
    for(int i=0;i<3;i++)
        {   
            for(int j=0;j<3;j++)
            {
                cout<<mat[i][j]<<" ";
            }
            cout<<"\n";
        }


}

int main()
{
    string s = "professor";
    transform(s.begin(), s.end(), s.begin(), std::ptr_fun<int, int>(std::toupper));
    cout<<s<<"\n";
    tomat(s);
    disp(mat);
    
}