#include<bits/stdc++.h>
using namespace std;

int c1[3][3];
int b[3][3]={{0,1,0},{1,1,0},{0,0,1}};
int a[3][3]={{0,1,0},{1,1,0},{0,0,1}};
int pw[3][3] ;
int inva[3][3];
int mat1[3][3];
int mul3[3][3];
int c[3][3];
string s1;
string dmsg;
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
                mat1[i][j] = y[sc]-'A';
                sc++;     
            }
        }

    }
    
}

string mattostring(int m[][3])
{
    int i,j;
    string converted="";
    for (i = 0; i < 3; i++)
    {
        for(j=0;j<3;j++)
        {
            converted  =converted + (char)(m[i][j]+'A');
        }
    }
    cout<<converted<<endl;
    return converted;
    //for(i=0;i<converted.length();i++)
    //cout<<converted[i]<<endl;
    
}
string encryptMessage(string msg) 
{ int p1=5,p2=17;
	///Cipher Text initially empty 
	string cipher = ""; 
	for (int i = 0; i < msg.length(); i++) 
	{ 
		// Avoid space to be encrypted 
		if(msg[i]!=' ') 
			/* applying encryption formula ( a x + b ) mod m 
			{here x is msg[i] and m is 26} and added 'A' to 
			bring it in range of ascii alphabet[ 65-90 | A-Z ] */
			cipher = cipher + 
						(char) ((((p1 * (msg[i]-'A') ) + p2) % 26) + 'A'); 
		else
			//else simply append space character 
			cipher += msg[i];	 
	} 
	return cipher; 
} 


string decryptCipher(string cipher) 
{ 
    int  p1=5,p2=17;
	string msg = ""; 
	int a_inv = 0; 
	int flag = 0; 
	
	//Find a^-1 (the multiplicative inverse of a 
		//in the group of integers modulo m.) 
	for (int i = 0; i < 26; i++) 
	{ 
		flag = (p1 * i) % 26; 
		
		//Check if (a*i)%26 == 1, 
				//then i will be the multiplicative inverse of a 
		if (flag == 1) 
		{ 
			a_inv = i; 
		} 
	} 
	for (int i = 0; i < cipher.length(); i++) 
	{ 
		if(cipher[i]!=' ') 
			/*Applying decryption formula a^-1 ( x - b ) mod m 
			{here x is cipher[i] and m is 26} and added 'A' 
			to bring it in range of ASCII alphabet[ 65-90 | A-Z ] */
			msg = msg + 
					(char) (((a_inv * ((cipher[i]+'A' - p2)) % 26)) + 'A'); 
		else
			//else simply append space characte 
			msg += cipher[i]; 
	} 

	return msg; 
} 

void mul(int a[3][3],int b[3][3])
{
    int sum;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            c1[i][j]=0;
			for(int k=0; k<3; k++)
			{
				c1[i][j] = c1[i][j] + a[i][k] * b[k][j];
			}
        }
    }
}

void mul2(int t1[3][3],int t2[3][3])
{
    int sum;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            mul3[i][j]=0;
			for(int k=0; k<3; k++)
			{
				mul3[i][j] = mul3[i][j] + t1[i][k] * t2[k][j];
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
                cout<<x[i][j]<<" ";
            }
            cout<<"\n";
        }


}

void invmat()
{
    int i,j,determinant=0;
	for(i = 0; i < 3; i++)
		determinant = determinant + (a[0][i] * (a[1][(i+1)%3] * a[2][(i+2)%3] - a[1][(i+2)%3] * a[2][(i+1)%3]));
	
	//cout<<"determinant: "<<determinant;
	
	cout<<"\n\nInverse of matrix is: \n";
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++)
			inva[i][j]=((a[(j+1)%3][(i+1)%3] * a[(j+2)%3][(i+2)%3]) - (a[(j+1)%3][(i+2)%3] * a[(j+2)%3][(i+1)%3]))/ determinant;
		
	}
    disp(inva);
}
void tomod()
{
    int i,j;
    for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++)
        {
            if(c1[i][j]<0)
            {
                int n = c1[i][j]/26+1;
                c1[i][j] = (26*n + c1[i][j])%26;
            }
            else
            c1[i][j] = c1[i][j]%26;
            //cout<<c1[i][j]<<endl;
        }

}
void assign()
{
    int i,j;
    for (i = 0; i <3; i++)
    {
        for(j=0;j<3;j++)
        {
            a[i][j]=c1[i][j];
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
int main()
{
    string s = "professor";
    transform(s.begin(), s.end(), s.begin(), std::ptr_fun<int, int>(std::toupper));
    cout<<s<<"\n";
    tomat(s);
    disp(mat1);
    powermat(3);
    mul(mat1,a);
    disp(c1);
    s1=mattostring(c1);
    string s2=encryptMessage(s1);
    cout<<s2<<endl;
    dmsg = decryptCipher(s2);
    cout<<dmsg<<endl;
    tomat(dmsg);
    disp(mat1);
    invmat();
    mul(mat1,inva);
    tomod();
    disp(c1);
    mattostring(c1);
    cout<<"ILY MEG!!!"<<endl;
    
}