#include <stdlib.h>
#include <stdio.h>

int values[] = {40,10,100,90,20,25};

int compare(const void *a, const void *b){
    return (*(int*)a - *(int*)b);   //��С����
    //return (*(int*)b - *(int*)a);   //�ɴ�С
}

int main()
{
    int n;
    qsort (values, 6, sizeof(int), compare);
    for (n = 0; n < 6; n++){
        printf("%d ", values[n]);
    }
    return 0;
}