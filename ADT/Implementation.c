#include <stdio.h>
#include <stdlib.h>
struct array
{
    int tSize;
    int uSize;
    int* ptr;
};
struct array* creatArray(struct array *p, int used_size, int total_size){
    p->ptr = (int*)malloc(used_size*sizeof(int));
    return p->ptr;
}
void setVal(struct array *m, int used_size, int item){
    
}
int main()
{
    struct array *myArray;
    int used_size = 4;
    int total_size = 10;
    creatArray(myArray, used_size, total_size);
    return 0;
}