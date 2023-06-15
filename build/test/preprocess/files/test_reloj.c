#include "src/reloj.h"
#include "C:/msys64/ucrt64/lib/ruby/gems/3.1.0/gems/ceedling-0.32.0/vendor/unity/src/unity.h"
static 

      _Bool 

           estado = 0;

void alarma(

           _Bool 

                estado_n){

    estado = estado_n;

}













void test_reloj_init(void){

    Reloj * reloj = relojInit(alarma);

}





void test_reloj_config(){

    uint8_t CERO[6] = {0,0,0,0,0,0};

    uint8_t ESPERADO[6] = {1,0,2,0,0,0};

    uint8_t RESULTADO[6];

    Reloj * reloj = relojInit(alarma);

    relojConfig(reloj,10,20,0);

    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((RESULTADO)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(33), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

    relojConfig(reloj,0,0,0);

    UnityAssertEqualIntArray(( const void*)((CERO)), ( const void*)((RESULTADO)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(35), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

    relojKill(reloj);

}



void test_reloj_corriendo(){

    uint8_t CERO[6] = {0,0,0,0,0,0};

    uint8_t ESPERADO[6] = {1,0,2,0,0,0};

    uint8_t RESULTADO[6];

    Reloj * reloj = relojInit(alarma);

    relojConfig(reloj,(uint8_t)10,(uint8_t)20,00);

    for (double i=0; i<=1000*60*(10*60+20); i++) relojTick(reloj);

    relojTime(reloj,RESULTADO);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((RESULTADO[5])), (

   ((void *)0)

   ), (UNITY_UINT)(47), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((RESULTADO[4])), (

   ((void *)0)

   ), (UNITY_UINT)(48), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((RESULTADO[3])), (

   ((void *)0)

   ), (UNITY_UINT)(49), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((RESULTADO[2])), (

   ((void *)0)

   ), (UNITY_UINT)(50), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((RESULTADO[1])), (

   ((void *)0)

   ), (UNITY_UINT)(51), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((RESULTADO[0])), (

   ((void *)0)

   ), (UNITY_UINT)(52), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((RESULTADO)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(53), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

    relojKill(reloj);

}





void test_alarm_set(){

    Reloj * reloj = relojInit(alarma);

    alarma(0);

    relojConfig(reloj,0,0,0);

    for (double i=0; i<=1000*60*(10*60+20); i++) relojTick(reloj);

    do { if (!(estado)) { } else { UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(63))); } } while (0);

    relojAlarmConfig(reloj,9,25);

    for (double i=0; i<=1000*3600; i++) relojTick(reloj);

    do { if ((estado)) { } else { UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(66))); } } while (0);

    relojAlOff(reloj);

    do { if (!(estado)) { } else { UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(68))); } } while (0);

    relojKill(reloj);

}





void test_snooze(){

    Reloj * reloj = relojInit(alarma);

    alarma(0);

    relojConfig(reloj,0,0,0);

    for (double i=0; i<=1000*60*(10*60+20); i++) relojTick(reloj);

    do { if (!(estado)) { } else { UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(78))); } } while (0);

    relojAlarmConfig(reloj,9,25);

    for (double i=0; i<=1000*3600; i++) relojTick(reloj);

    do { if ((estado)) { } else { UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(81))); } } while (0);

    relojSnooze(reloj,5);

    for (double i=0; i<=2*1000*60; i++) relojTick(reloj);

    do { if (!(estado)) { } else { UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(84))); } } while (0);

    for (double i=0; i<=3*1000*60; i++) relojTick(reloj);

    do { if ((estado)) { } else { UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(86))); } } while (0);

    relojAlOff(reloj);

    do { if (!(estado)) { } else { UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(88))); } } while (0);

    relojKill(reloj);

}
