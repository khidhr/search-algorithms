#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "omp.h"

// number of elements of the array
int length;

// number of threads set to 4 but can be changed  
#define numberOfThreads 4

// function to set the array length
void setArrayLength() {
    printf("enter the length of your array:\n");
    scanf("%d",&length);
}


// function that return a pointer to the array after setting its values
int* setArrayValues(){
    setArrayLength();
    static int* data;
    data = (int*) malloc(length * sizeof(int));
    for (int i = 0; i < length ; i++)
    {
        printf("enter the value of data[%d]:",i);
        scanf("%d",data+i);
    }
    return data;
}

// vanilla recursive binary search

int binarySearch(int array[],int target, int start, int end){
    if (start>end) return -1;
    else
    {
        int middle =(start+end)/2;
        if (array[middle] == target) return middle;
        else if (array[middle]>target) return binarySearch(array,target,start,middle-1);
        else return binarySearch(array,target,middle+1,end);
    }
    
}

// function to set the target
int target;
void defineTarget() {
    printf("enter the number you are looking for : ");
    scanf("%d",&target);
}


// multithreaded binary search
void multiThreadedBS (){
    int* p = setArrayValues();
    defineTarget();
    int sublength = (int) ceil((double)length/(double)numberOfThreads);
    printf("\nthe length of the subarray is:%d\n",sublength);
    #pragma parallel for
    {
        for (int i = 0; i < numberOfThreads; i++)
        {
            printf("%d for thread %d\n",binarySearch(p,target,i * sublength,sublength*(i + 1)-1),i);
        }
        
    }
}

// main function

int main(){

    // one line of code in the main function
    multiThreadedBS ();
}
