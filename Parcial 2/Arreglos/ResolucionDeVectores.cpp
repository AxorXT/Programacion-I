#include <stdio.h>
int main(){
    int vector[4], i;
    for(i = 0; i < 4; i++){
        printf("Escribe el 1vector %d: ", i+1);
        scanf("%d", &vector[i]);
    }
    int vector2[4];
    for(i = 0; i < 4; i++){
        printf("Escribe el 2vector %d: ", i+1);
        scanf("%d", &vector2[i]);
    }
    i=0;
    int vect[4];
    while(i<4){
        vect[i] = vector[i] + vector2[i];
        printf("vect %d \n", vect[i]);
        i++;
    }
}
