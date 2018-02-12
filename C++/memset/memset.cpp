#include <stdio.h>
#include <cstring>
#include <iostream>
int main()
{
    char str[] = "almost every programmer should know memset!";
    memset(str,'-',6);
    puts(str);
    //memset 是以字节为单位计算空间大小的
    int i,j,m,a[20];
    for(j = 0; j < 20; j++){
        a[j] = j;
    }
    memset(a,0,8);      //a[0]=0,a[1]=0,a[2]=2,a[3]=3,……,a[19]=19
    for(i = 0; i < 20; i++){
        printf("a[%d] = %d\n",i,a[i]);
    }
        
    return 0;
}
