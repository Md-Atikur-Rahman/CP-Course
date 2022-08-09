#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"matrix A\n";
    cout<<"enter row and column: ";
    int row1,col1; cin>>row1>>col1;
    int mat1[row1][col1];
    for(int i=0; i<row1; i++)
    {
        for(int j=0; j<col1; j++)
        {
            cin>>mat1[i][j];
        }
    }

    cout<<"matrix B\n";
    cout<<"enter row and column: ";
    int row2,col2; cin>>row2>>col2;
    int mat2[row2][col2];
    for(int i=0; i<row2; i++)
    {
        for(int j=0; j<col2; j++)
        {
            cin>>mat2[i][j];
        }
    }

    if(col1!=row2)
    {
        cout<<"matrix can not be multiplied\n";
        return 0;
    }

    int ans[row1][col2]={};

    for(int i=0; i<row1; i++)
    {
        for(int j=0; j<col2; j++)
        {
            for(int k=0; k<col1; k++)
            {
                ans[i][j]+=mat1[i][k]*mat2[k][j];
            }
        }
    }

    cout<<"matrix AXB:\n";
    for(int i=0; i<row1; i++)
    {
        for(int j=0; j<col2; j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
    
    return 0;
}