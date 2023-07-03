#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(){
    int n;
    int arr[n];
    
    scanf("%d", &n);

    int initialTime;
    int initialDistance;

    scanf("%d %d", &initialTime, &initialDistance);

    for(int i = 0; i < n-1; i ++){
        int newTime;
        int newDistance;

    scanf("%d %d", &newTime, &newDistance);
    int speed;

    speed = (newDistance - initialDistance) / (newTime - initialTime);

    arr[i] = speed;
    
    initialDistance = newDistance;
    initialTime= newTime;

    }

    int max;
    max = 0;

    for(int i = 0 ; i < n; i++){
        if (arr[i] > max){
            max = arr[i];
        }
    }

    printf("%i\n", max);



    return 0;
}