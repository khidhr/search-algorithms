#include <stdio.h>
#include <stdlib.h>
// recursive and iterative algorithms for interpolation search that return the position of an element on a given array, if not foud return -1
// the array is supposed to be sorted and uniformly distributed or  fairly distributed (the gap between two adjacent elements are equal or close)



//recursive version

int RecursiveInterpolationSearch(int array[],int target,int start,int end){
    if (start>end) return -1;
    else
    {
        int position = start + ((target-array[start])/(array[end]-array[start]))*(end-start);
        if (array[position]== target) return position;
        else if(array[position]>target) return interpolationSearch(array,target,start,position-1);
        else return interpolationSearch(array,target,position+1,end);
    }
}

// iterative version

int iterativeInterpolationSearch(int array[],int target,int size){
    int start,end,pos;
    start =0;
    end = size-1;
    while (end>= start)
    {
        pos = start + ((target-array[start])/(array[end]-array[start]))*(end-start);
        if (array[pos] ==target)
            return pos;
        else if (array[pos]> target) end = pos-1;
        else start = pos+1;
    }
    return -1;

}

int main(){

    int myArray[10]= {9,21,31,39,51,60,71,82,90,99};
    int position = iterativeInterpolationSearch(myArray,82,10);
    if(position ==-1)
	printf("element not found !");
    else 
	print("target found at position %d",position);

    return 0;
}
