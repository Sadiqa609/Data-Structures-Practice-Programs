#include<stdio.h>
#include<stdlib.h>
/* I have formed the ADT(Abstract data type) Below */
struct myArray
{
    int total_size;
    int used_size;
    int *ptr;

};
/*Function to make changes in marks of type myArray*/
void createArray(struct myArray* a,int tsize, int usize)
{
    /*(*a).total_size= tsize;
    (*a).used_size= usize;
    (*a).ptr= (int*) malloc(tsize*sizeof(int));/*taking dynamic size ...memory from heap*/
/*The above and below code both are same we can get value from address by using arrow operator*/
    a->total_size= tsize;
    a->used_size= usize;
    a->ptr= (int*) malloc(tsize*sizeof(int));/*taking dynamic size ...memory from heap*/
}
void setVal(struct myArray *a)
{
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter Elements %d", i);
        scanf("%d", &n);
        (a->ptr)[i] = n;
    }
    
}
void show(struct myArray *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d", (a->ptr)[i]);
    }
}
int main(){
    struct myArray marks;
    createArray(&marks,100,20);
    printf("We are running setval now");
    setVal(&marks);
    printf("We are running show now");
    show(&marks);
    return 0 ;
}
