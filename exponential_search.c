#include<stdio.h>
#include<stdlib.h>

// we first define the binary search to be applied when needed

int binarySearch(int myList[], int target, int start, int end)
{
  if (start > end)
    return -1;
  else
  {
    int middle = (start + end) / 2;
    if (myList[middle] == target)
      return middle;
    else if (myList[middle] > target)
      return binarySearch(myList, target, start, middle - 1);
    else
      return binarySearch(myList, target, middle + 1, end);
  }
}
//  we'll need min function to reduce the size of the potential suspects to check

int min(int num1, int num2)
{
  if (num1 > num2)
    return num2;
  return num1;
}

int exponentialSearch(int array[],int target,int start,int end){
  int i= 1;

  while (i<end && array[i]<= target)
  {
    i*=2;
  }

  return binarySearch(array,target,i/2,min(i,end));
}

int main()
{

  int array[1000];
  for (int i = 0; i < 1000; i++)
  {
    array[i] = i;
  }

  // the sizeof function return the size in bytes of all the array so we divided by individual size (4 IN THIS CASE SINCE IT'S AN INTEGER ARRAY AND THE SIZE OF AN INTEGER ON C IS 4 BYTES) to get the number of elements
  
  int length = sizeof(array) / 4;

  printf("the target is on the position %d  ", exponentialSearch(array, 888, 0, length-1));
  

  return 0;
}
