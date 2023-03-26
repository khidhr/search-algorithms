#include <stdlib.h>
#include <stdio.h>

//iterative version of binary search
int iterative_binary_search(int data[],int n,int target){
    int upper=n-1,lower=0;
    while(lower <=upper)
        {
        int mid = (upper+lower)/2;
        if(data[mid]==target)return mid;
        else if(target<data[mid]) upper=mid-1;

        else lower=mid+1;
        }
    return -1;
}
//recursive version of binary search
int recursive_binary_search(int data[],int target,int lower,int upper){
    if(lower>upper)return -1;
    else{
        int mid = (lower+upper)/2;
        if(data[mid]==target) return mid;
        else if(data[mid]>target) return recursive_binary_search(data,target,lower,mid-1);
        else return recursive_binary_search(data,target,mid+1,upper);
        }
}

int main()
{
    int data[]= {5,8,9,11,27,29,31,36,52,65};
    int target;
    printf("enter the number you looking for:\n");
    scanf("%d",&target);
    int index =iterative_binary_search(data,10,target);
    if(index!=-1)printf("the index of  %d is %d",target,index);
    else printf("the number you looking for is not found in the table");
    printf("\n %d\n",recursive_binary_search(data,target,0,9));
    printf("%d",7000%3);
    return 0;
}
