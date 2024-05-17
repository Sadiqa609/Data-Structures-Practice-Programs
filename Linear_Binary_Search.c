#include<stdio.h>
#include<stdlib.h>
int linearSearch(int arr[], int size, int element){
    for (int i = 0; i < size; i++)
    {
        if(arr[i]==element){
            return i;
        }
    }
    return -1;
}
int binarySearch(int arr[], int size, int element){
    int low,mid,high;
    low=0;
    high=size-1;
    while (low<=high){
    //Searching start from here 
    mid=(low+high)/2;
    if (arr[mid]==element)
    {
        return mid;
    }
    if (arr[mid]<element)
    {
        low=mid+1;
    }
    else{
        high=mid-1;
    }
    //Searching end here 
    }
    return -1;
}
int main(){
    //unsorted array for linear search but we can also take sorted aray too
    int arr[] = {1,3,5,56,84,93,123,225,334,54634};
    int size = sizeof(arr)/sizeof(int);
    //int element = 56;
    //int searchIndex = linearSearch(arr, size, element);
    //printf("The element %d was found at index %d \n", element, searchIndex);
    //Sorted array for binary search and we can only take sorted arry in binary search
    int element = 54634;
    int searchIndex = binarySearch(arr, size, element);
    printf("The element %d was found at index %d \n", element, searchIndex);

    return 0;
}