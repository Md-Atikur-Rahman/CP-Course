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
    cout<<"enter row and column: ";
    int row,col; cin>>row>>col;
    VVI mat(row,VI(col));
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cin>>mat[i][j];
        }
    }

    if(row!=col)
    {
        cout<<"invalid matrix for exponentiation\n";
        return 0;
    }

    cout<<"enter power: ";
    int p; cin>>p;

    VVI ans(row,VI(col));
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(i==j)ans[i][j]=1;
            else ans[i][j]=0;
        }
    }

    matrix_exp(mat,p,ans);
    
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}