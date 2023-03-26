#include<stdio.h>
#include<stdlib.h>



int linearSearch(int array[],int length,int target){
    int i;
    for ( i = 0; i < length; i++)
    {
        if (array[i]== target) return i;
    }
    
    return -1;
}

int main(){
    int length,i;
    printf("enter the length of your array");
    scanf("%d",&length);
    int array[length];
    for(i=0;i<length;i++) {
        printf("array[%d]= ",i);
        scanf("%d",&array[i]);
    }
    int target;
    printf("enter the element you're looking for: ");
    scanf("%d",&target);
    printf("%d",linearSearch(array,length,target));

    return 0;
}
