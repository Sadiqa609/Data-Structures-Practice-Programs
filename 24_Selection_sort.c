#include <stdio.h>
void printArray(int *Array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", Array[i]);
    }
    printf("\n");
}
int selectionSort(int *array, int size)
{
    int minimum_index;
    int temp;
    printf("Running Selection Sort .. \n");
    for (int i = 0; i < size - 1; i++)
    {
        minimum_index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[minimum_index])
            {
                minimum_index = j;
            }
        }
        // swaping array[i] && array[minimum_index]
        temp = array[i];
        array[i] = array[minimum_index];
        array[minimum_index] = temp;
    }
}
int main()
{
    int array[] = {2, 5, 4, 9, 1};
    int size = 5;
    printArray(array, size);
    selectionSort(array, size);
    printArray(array, size);
    return 0;
}