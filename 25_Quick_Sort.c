#include <stdio.h>
void printArray(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf(" %d", array[i]);
    }
    printf("\n");
}
int partition(int array[], int low, int high)
{
    int pivot = array[low];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {
        while (array[i] <= pivot)
        {
            i++;
        }
        while (array[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    } while (i < j);
    // swaping array[low] 7 array[j]
    temp = array[low];
    array[low] = array[j];
    array[j] = temp;
    return j;
}
void quickSort(int *array, int low, int high)
{
    int partitionIndex; // pivot index after partitioning of the array
    if (low < high)
    {
        partitionIndex = partition(array, low, high);
        //to know what array is returned after every partition 
        printArray(array,10);
        quickSort(array, low, partitionIndex - 1);  // for all smaller values on the left side of pivot
        quickSort(array, partitionIndex + 1, high); // for all the larger values on the right side of the pivot
    }
}
int main()
{
    int array[] = {3, 6, 9, 2, 6, 19, 27,1,0,99};
    int size = 10;
    printf("Array before running quick sort\n");
    printArray(array, size);
    quickSort(array, 0, size - 1);
    printf("Array after running quick sort\n");
    printArray(array, size);
    return 0;
}