#include<stdio.h>

int main()
{
    int e,a[10];
    printf("Enter array elements \n");
    for(int i = 0; i < 5; i++)
    {
        scanf("%d",&a[i]);
    }
    
    printf("Enter an element\n");
    scanf("%d",&e);
    int flag=0;
    for(int i=0;i<5;i++)
    {
        if(a[i]==e)
        {
            printf("Element exits at position %d\n",i+1);
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("Element not found\n");
    }
    return 0;
}