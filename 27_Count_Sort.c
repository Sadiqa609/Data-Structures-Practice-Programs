#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
void printArray(int*array,int size){
    for (int i = 0; i < size; i++)
    {
        printf(" %d",array[i]);
    }
    printf("\n");
}
int maximum(int array[],int n){
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
       if (max <array[i])
       {
         max=array[i];
       }  
    }
    return max;
}
void countSort(int *array,int size){
    int max =maximum(array,size);
    int i;
    int j;
    //Creating count array
    int * auxiliary_array = (int *)malloc((max+1)*sizeof(int));
    //initializing the auxiliary_array elements with 0  
    for (i = 0; i < max+1; i++)
    {
      auxiliary_array[i]=0;
    }
    // incrementing the initilized indexes in the auxiliary_array
     for (i = 0; i < size; i++)
    {
      auxiliary_array[array[i]]=auxiliary_array[array[i]]+1;
    }
    i=0;// counter for auxiliary array
    j=0; // counter for given array
    while (i<=max)
    {
        if (auxiliary_array[i]>0)
        {
            array[j]=i;
            auxiliary_array[i]=auxiliary_array[i]-1;
            j++;
        }
        else
        {
            i++;
        }
        
    }
    
}
int main(){
    int array[]={1,3,6,2,8,33,99,2,0};
    int size =9;
    printArray(array,size);
    countSort(array,size);
    printArray(array,size);
    return 0;
}