#include <stdio.h>
#include <stdlib.h>
 
int f91(int parada){
    if(parada <= 100) return f91(f91(parada + 11));
    if(parada > 100) return parada - 10;
}
 
int main(){
    int parada;
    
    scanf("%d", &parada);
    while(parada){
        printf("f91(%d) = %d\n", parada, f91(parada));
        scanf("%d", &parada);
    }
    return 0;
}
