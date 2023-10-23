
#include <stdio.h>
int binary_search (int arr[10], int n, int targ);
int main ()
{
  // Write C code here
  printf ("Hello world");
  int n = 10;
  int arr[10] = { 1, 3, 5, 7, 9, 10, 15, 17, 28, 30 };
  int targ = 0, ind = 0;
  printf ("\n search for:");
  scanf ("%d", &targ);
  ind = binary_search (arr, n, targ);
  if (ind >= 0)
    {
      printf ("\n the target index is : %d", ind + 1);
    }
  else
    {
      printf ("\n the target not found");
    }

  return 0;
}

int
binary_search (int arr[10], int n, int targ)
{
  int ind = -1, mid = (n - 1) / 2, start = 0, end = n - 1;
  while (start <= end)
    {
      mid = (end + start) / 2;

      if (arr[mid] == targ)
	{
	  ind = mid;
	  break;

	}
      else if (targ > arr[mid])
	{
	  start = mid + 1;
	}
      else if (targ < arr[mid])
	{
	  end = mid - 1;
	}


    }
  return ind;
}
