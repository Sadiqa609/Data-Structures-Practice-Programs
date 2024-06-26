#include<stdio.h>
void printArray(int*array,int size){
    for (int i = 0; i < size; i++)
    {
        printf(" %d",array[i]);
    }
    printf("\n");
}
// writing merge procedure
void mergeProcedure(int array[],int mid,int low,int high){
    int i,j,k;
    int array2[100];
    i=low;
    j=mid+1;
    k=low;
    while (i<=mid && j<=high)
    {
        if (array[i]<array[j])
        {
            array2[k]=array[i];
            i++;
            k++;
        }
        else
        {
            array2[k]=array[j];
            j++;
            k++;
        }
    }
    //copying all left over elements from array to array2
    while (i<=mid)
    {
        array2[k]=array[i];
        i++,k++;
    }
    while (j<=high)
    {
        array2[k]=array[j];
        j++,k++;
    }   
    for (int i = 0; i <=high; i++)
    {
       array[i]=array2[i];
    }
}
void mergSort(int array[],int low,int high){
    int mid;
    if (low<high)
    {
        mid=(low+high)/2;
        mergSort(array,low,mid);//left half array
        mergSort(array,mid+1,high);//right half array
        mergeProcedure(array,mid,low,high);
    }
    
}
int main(){
    int array[]={1,3,6,2,8,33,99,2,0};
    int size =9;
    printArray(array,size);
    mergSort(array,0,8);
    printArray(array,size);
    return 0;
}