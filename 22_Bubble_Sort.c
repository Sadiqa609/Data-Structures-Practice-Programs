#include<stdio.h>
void printArray(int*Array,int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ",Array[i]);
    }
    printf("\n");
}
void bubblesort(int *Array, int size)
{
    int isSorted=0;
    int temp;
    for (int i = 0; i < size-1; i++) // this is for number of passes 
    {
       printf("The pass number of the given array is %d\n", i+1);
       for (int j = 0; j < size-1-i; j++) // this is for no. of comparisons in each pass
       {
        isSorted=1;
          if(Array[j]>Array[j+1])
          {
            temp= Array[j];//just for swaping concept consider swaping of(1,3) we have 1,2,3 =>> 1=2
            Array[j]=Array[j+1]; // 2=3
            Array[j+1]=temp;    // 3=1
            isSorted=0;
          }
       }
       if (isSorted==1)
       {
        return;
       } 
    }
    
}
int main()
{
    int Array1[]={1,2,3,4,5,6};
    int Array[]={9,1,20,12,18,16};
    int size=6;
    printf("Array before sorting\n");
    printArray(Array1,size); // Array before sorting 
    bubblesort(Array1,size); // bubble sort function
    printf("Array before sorting\n"); 
    printArray(Array1,size); // printing the array after sorting 
    return 0;
}