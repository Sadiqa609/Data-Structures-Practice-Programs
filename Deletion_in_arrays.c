#include<stdio.h>
#include<stdlib.h>
// This code is for Traversal in Arrays
void display(int array[],int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", array[i]);
    }
}
// This code is for Indexed Deletion in Arrays
int indDelection(int array[], int size, int index)
{
    if (index>=size|| index < 0)
    {
        return -1;
    }
    for (int i = index; i < size; i++)
    {
        array[i]=array[i+1];
    } 
    return 0;
}
// This is main function for calling
int main(){
    printf("The array traversal is shown below %d\n");
    int array[100] = {7,8,12,27,88};
    int size = 5 , index=1; //The index of the element to be deleted
    display(array, size);
    indDelection(array, size, index);
    size-=1; // decrease the size of the array after deletion
    printf("The array Indexed Deletion is shown below : %d\n");
    display(array, size);
    return 0;
}