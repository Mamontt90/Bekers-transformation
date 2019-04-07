#include<stdio.h>
int main()
{
    int n = 4,k=1;
    int tab0[n][n];
    for(int i=0;i<n;i++)
    {
        for(int b=0;b<n;b++)
        {
            tab0[b][i] = k;
            k++;
        }
    }

    int pr[2*n][n];

    for(int i=0;i<n/2;i++)
    {
        for(int b=0;b<n*2;b++)
        {
            if(b%2 == 0)
            {
                pr[b][i] = tab0[b][i];
            }else
            {
                pr[b][i] = tab0[b][i+2];
            }
        }
    }


    for(int i=0;i<n/2;i++)
    {
        for(int b=0;b<n*2;b++)
        {
            tab0[
        }
    }
}
