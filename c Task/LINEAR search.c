#include <stdio.h>
int liner_search(int arr[10],int n,int targ);
int main() {
    // Write C code here
    printf("Hello world");
    int n=10;
    int  arr[10]={1,5,9,3,7,4,6,8,55,10};
    int targ=0,ind=0;
   printf ("\n search for:");
    scanf("%d",&targ);
   ind= liner_search(arr,n,targ);
   if (ind>=0)
  {
      printf ("\n the target index is : %d",ind+1);
  }
  else 
  {
       printf ("\n the target not found");
  }

    return 0;
}
int liner_search(int arr[10],int n,int targ)
{int ind=-1;
    for(int i=0 ;i<n;i++)
    {
        if (arr[i]==targ)
        ind=i;
    }
    return ind;
}