#include <unity.h>
#include <stdbool.h>
#include "reloj.h"

#define MINUTO TICKS_SEG*60
#define HORA TICKS_SEG*3600
#define HORAS 10
#define MINUTOS 20
#define TICKS TICKS_SEG*60*(HORAS*60+MINUTOS)

static bool estado = 0;
void alarma(bool estado_n){
    estado = estado_n;
}

bool alarmacheck(void){
    return estado;
}




void test_reloj_init(void){
    Reloj * reloj = relojInit(alarma);
}


void test_reloj_corriendo(){
    uint8_t ESPERADO[6] = {1,0,2,0,0,0};
    uint8_t RESULTADO[6];
    Reloj * reloj = relojInit(alarma);
    relojConfig(reloj,0,0,0);
    for (double i=0; i<=TICKS; i++) relojTick(reloj);
    relojTime(reloj,RESULTADO);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERADO,RESULTADO,6);
    relojKill(reloj);
}


void test_alarm_set(){
    Reloj * reloj = relojInit(alarma);
    alarma(0);
    relojConfig(reloj,0,0,0);
    for (double i=0; i<=TICKS; i++) relojTick(reloj);
    TEST_ASSERT_EQUAL(0,alarmacheck());
    relojAlarmConfig(reloj,9,25);
    for (double i=0; i<=HORA; i++) relojTick(reloj);
    TEST_ASSERT_EQUAL(1,alarmacheck());
    relojAlOff(reloj);
    TEST_ASSERT_EQUAL(0,alarmacheck());
    relojKill(reloj);
}   


void test_snooze(){
    Reloj * reloj = relojInit(alarma);
    alarma(0);
    relojConfig(reloj,0,0,0);
    for (double i=0; i<=TICKS; i++) relojTick(reloj);
    TEST_ASSERT_EQUAL(0,alarmacheck());
    relojAlarmConfig(reloj,9,25);
    for (double i=0; i<=HORA; i++) relojTick(reloj);
    TEST_ASSERT_EQUAL(1,alarmacheck());
    relojSnooze(reloj,5);
    for (double i=0; i<=2*MINUTO; i++) relojTick(reloj);
    TEST_ASSERT_EQUAL(0,alarmacheck());
    for (double i=0; i<=3*MINUTO; i++) relojTick(reloj);
    TEST_ASSERT_EQUAL(1,alarmacheck());
    relojAlOff(reloj);
    TEST_ASSERT_EQUAL(0,alarmacheck());
    relojKill(reloj);
}