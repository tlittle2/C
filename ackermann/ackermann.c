#include <stdio.h>


int ackermann(int m, int n){
    int answer;
    if (m == 0){
        answer = n+1;
    }else if (n == 0){
        answer= ackermann(m-1, 1);
    }else{
        answer= ackermann(m-1, ackermann(m, n-1));
    }
    
    
}

void main(){
    while(1){
    int num1;
    int num2;

    printf("Enter a number: ");
    scanf("%d", &num1);

    printf("Enter another number: ");
    scanf("%d", &num2);

    printf("Ackermann: %d\n", ackermann(num1, num2));

    }   


}