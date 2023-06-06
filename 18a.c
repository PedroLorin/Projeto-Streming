#include <stdio.h>
#include <string.h>

int main() {
    char origem[20] = "Hello, world!";
    char destino[20]="sua maen";
    
    strcpy( origem,destino);
    
    printf("String de origem: %s\n", origem);
    printf("String de destino: %s\n", destino);
    
    return 0;
}