/*
    Author: Akhil Suresh
    Q : Matrix multiplication
    features:
        checks if the rows and columns are positive integers
        check if multiplication condition is there
*/
#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{   

    int r1,c1,r2,c2;
    int **Mat1,**Mat2,**Mat3;
    do{
    cout<<"Enter dimensions of matrix 1 :";
    cin>>r1>>c1;
    }while (r1>0 && c1>0);

    Mat1 = new int* [r1];
    for(int i=0;i<r1;i++)
        Mat1[i] = new int[c1];

    cout<<"Enter matrix 1";
    for(int i =0;i<r1;i++)
        for(int j=0;j<c1;j++)
            cin>>Mat1[i][j];
    cout<<"Matrix 1:\n";
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c1;j++)
            cout<<Mat1[i][j]<<" ";
        cout<<endl;
    }
    do{
    cout<<"Enter dimensions of matrix 2 :";
    cin>>r2>>c2;
    }while(r2>0&&c2>0);

    Mat2 = new int* [r2];
    for(int i=0;i<r2;i++)
        Mat2[i] = new int[c2];
    cout<<"Enter matrix 2";
    for(int i =0;i<r2;i++)
        for(int j=0;j<c2;j++)
            cin>>Mat2[i][j];
    
    cout<<"Matrix 2 :";
    for(int i=0;i<r2;i++)
    {
        for(int j=0;j<c2;j++)
            cout<<Mat2[i][j]<<" ";
        cout<<endl;
    }

    if(c1 != r1)
    {
        cout<<"no. of columns of M1 not same as no. of row of M2 , Multiplication not possible";
        return 0;
    }

    Mat3 = new int* [r1];
    for(int i=0;i<r1;i++)
        Mat3[i] = new int[c2];
    for(int i=0;i<r1;i++)
        for(int j=0;j<c2;j++)
        {
            Mat3[i][j]=0;
            for (int k = 0; k < c1; k++)
            {
                Mat3[i][j]+=Mat1[i][k]*Mat2[k][j];
            }
            
        }
    cout<<"MUltiplication matrix is  :\n";
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c2;j++)
            cout<<Mat3[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
