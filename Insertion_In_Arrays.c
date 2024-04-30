#include<stdio.h>
#include<stdlib.h>
void display(int array[],int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", array[i]);
    }
}
int main(){
    printf("The array traversal is shown below %d\n");
    int array[100] = {1,2,5,79};
    display(array, 4);
    return 0;
}