#include "reloj.h"
#include <stdio.h>

#define HORA TICKS_SEG*3600
#define  TICKS_SEG  1000
void alarma(bool a){;;}

void main (void){

    Reloj * reloj = relojCrear(alarma);
    uint8_t res[10];
    printf("\n");
    relojConfig(reloj,10,23,45);
    for (uint8_t i=0; i<6;i++) printf("Elemento reloj (%d)  %d \n",i,*((uint8_t*)(reloj) + i));
    relojTime(reloj,res);
    printf("\n");
    printf("Despues de 1 hora\n");

    for (double i=0; i<=25610; i++) relojTick(reloj);
    for (uint8_t i=0; i<6;i++) printf("Elemento reloj (%d)  %d \n",i,*((uint8_t*)(reloj) + i));
    relojTime(reloj,res);
    printf("\n");
    printf("\n");
}