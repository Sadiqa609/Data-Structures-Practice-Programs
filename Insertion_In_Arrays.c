#include<stdio.h>
#include<stdlib.h>
void display(int array[],int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", array[i]);
    }
}
int indinsertion(int array[], int size, int element,int capacity, int index)
{
    if (size>=capacity)
    {
        return -1;
    }
    for (int i = size-1; i >= index; i--)
    {
        array[i+1]=array[i];
    }
    array[index]=element;
    return 1;
    
}

int main(){
    printf("The array traversal is shown below %d\n");
    int array[100] = {7,8,12,27,88};
    int size = 5 , element=45, index=3;
    display(array, 4);
    indinsertion(array, size, element, 100, index);
    size+=1;
    printf("The array Indexed Insertion is shown below : %d\n");
    display(array, size);
    return 0;
}