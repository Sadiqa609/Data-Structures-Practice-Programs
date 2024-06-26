#include<stdio.h>
void printArray(int*Array,int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ",Array[i]);
    }
    printf("\n");
}
int insertionSort(int*array, int size){
    //This loop is for passes
    
    for (int  i = 1; i <= size-1; i++)
    {
        int key , j;
        //This loop is for each pass or each comparison of array element until sort
        key=array[i]; // element to be inserted in the array
        j=i-1;  // element right before the inserted element
       while (j>=0 && array[j]>key)
       {
          array[j+1]=array[j];
          j--;
       }
       array[j+1]=key;
    }
    
}
int main()
{
    // 12,65,3,6,99,18
    int array[]={12,65,3,6,99,18};
    int size = 6;
    printf("Array before Insertion Sort\n");
    printArray(array,size);
    insertionSort(array,size);
    printf("Array after Insertion Sort\n");
    printArray(array,size);
    return 0;
}