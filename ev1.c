#include<stdio.h>

int main()
{
    FILE *fp;
    fp = fopen("bubble.txt", "w");
    if(fp == NULL)
    {
        printf("Error opening file\n");
        //exit(1);
    }
    int i=0,num=0,a[5];
    for(i=0;i<5;i++)
    {
        int a;
        scanf("%d",&a);
        fprintf(fp, "%d ",a);
    }

    fclose(fp);


    fp = fopen("bubble.txt", "r");
    if(fp == NULL)
    {
        printf("Error opening file\n");
        //exit(1);
    }
    i=0;
    while(fscanf(fp,"%d",&num)==1)
    {
        a[i]=num;
        i++;
    }
    fclose(fp);
    for(int j=0;j<5;j++)
    {
        printf("%d  ",a[j]);
    }

    fclose(fp);

    for(int g=0;g<5;g++)
    {
        for(int k=0;k<5-g-1;k++)
        {
            if(a[k]>a[k+1])
            {
                int temp;
                temp=a[k];
                a[k]=a[k+1];
                a[k+1]=temp;
            }
        }
    }
    printf("\n");
    for(i=0;i<5;i++)
    {
        printf("%d  ",a[i]);
    }

    fp = fopen("bubble.txt", "w");
    if(fp == NULL)
    {
        printf("Error opening file\n");
        //exit(1);
    }
    for(i=0;i<5;i++)
    {
        fprintf(fp, "%d ",a[i]);
    }
    fclose(fp);


}
