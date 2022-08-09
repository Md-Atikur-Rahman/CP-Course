#include<bits/stdc++.h>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

VVI matrix_mul(VVI& mat1, VVI& mat2)
{
    int r1=mat1.size(),c1=mat1[0].size();
    int r2=mat2.size(),c2=mat2[0].size();

    VVI res(r1,VI(c2));

    for(int i=0; i<r1; i++)
    {
        for(int j=0; j<c2; j++)
        {
            res[i][j]=0;

            for(int k=0; k<c1; k++)
            {
                res[i][j]+=mat1[i][k]*mat2[k][j];
            }
        }
    }
    return res;
}

void matrix_exp(VVI& mat, int p, VVI& ans)
{
    while(p>0)
    {
        if(p%2==1)ans=matrix_mul(ans,mat);

        mat=matrix_mul(mat,mat);
        p/=2;
    }
}

int main()
{
    VVI mat(2,VI(2));
    mat[0][0]=0;
    mat[0][1]=1;
    mat[1][0]=1;
    mat[1][1]=1;

    cout<<"enter n: ";
    int n; cin>>n;

    VVI ans(2,VI(2));
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            if(i==j)ans[i][j]=1;
            else ans[i][j]=0;
        }
    }

    matrix_exp(mat,n,ans);

    VVI fib(1,VI(2));
    fib[0][0]=0;
    fib[0][1]=1;

    fib=matrix_mul(fib,ans);
    
    cout<<fib[0][0]<<"\n";

    return 0;
}