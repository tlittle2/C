#include <stdio.h>
#include <stdbool.h>

int main(){
    int a,b,c,d,e;
    int g;
    scanf("%d%d%d%d%d\n", &a,&b,&c,&d,&e);
    scanf("%d\n", &g);

    printf("Grade is %d", g);

    if(&g <= &e){
        printf("F");
    }

    else if(&g >= &a){
        printf("A");
    }




}
