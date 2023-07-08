#include<stdio.h>

int a[10][10],b[10][10],s[10][10],m[10][10];

main()
{
    void read(int, int);
    void display(int, int);
    void sum(int, int);
    void mul(int, int);
    void inverse(int, int);

    int r,c,ch;

    printf("enter the no of row and columns\n");
    scanf("%d%d",&r,&c);

    read(r,c);
    display(r,c);

    while(1)
    {
        printf("\n1--Sum\n");
        printf("2--Product\n");
        printf("3--Inverse\n");
        printf("4--Exit\n");

        scanf("%d",&ch);

        switch(ch)
       {
           case 1: sum(r,c);
             break;
           case 2: mul(r,c);
             break;
           case 3: inverse(r,c);
             break;
           case 4: exit(0);
             break;

       }
    }
}

void read(int  r, int c)
{
    int i,j;

    printf("Enter the elements of the 1st matrix\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    printf("Enter the elements of the 2nd matrix\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
}

void display(int  r, int c)
{
    int i,j;

    printf("\n1st matrix is\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

    printf("\n2nd matrix is\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
}

void sum(int  r, int c)
{
    int i,j;

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            s[i][j]=a[i][j]+b[i][j];
        }
    }

    printf("\nSum of matrices is\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d ",s[i][j]);
        }
        printf("\n");
    }
}

void mul(int  r, int c)
{
    int i,j;

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            m[i][j]=a[i][j]*b[i][j];
        }
    }

    printf("\nProduct of matrices is\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d ",m[i][j]);
        }
        printf("\n");
    }
}

void inverse(int  r, int c)
{
    int i,j;

    printf("\Inverse of both matrices is\n");
    for(i=r-1;i>=0;i--)
    {
        for(j=c-1;j>=0;j--)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for(i=r-1;i>=0;i--)
    {
        for(j=c-1;j>=0;j--)
        {
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
