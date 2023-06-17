#include "src/reloj.h"
#include "C:/Ruby27-x64/lib/ruby/gems/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"




static Reloj *reloj;





_Bool 

    ALARMA_ESTADO = 0;

void ctrlAlarm(

              _Bool 

                   estado){

    ALARMA_ESTADO = estado;

}



void setUp(void){

    reloj = 

           ((void *)0)

               ;

    reloj = relojCrear(1,ctrlAlarm);

}



void tearDown(void){

    relojKill(reloj);

    reloj = (Reloj*)0;

    ALARMA_ESTADO = 0;

}













void test_un_reloj_sin_poner_en_hora_debe_informar_error_al_pedirle_la_hora(void){

    do {if ((((reloj)) != 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(30))));}} while(0);

    uint8_t resultado[6]={0};

    const 

         _Bool 

              horaRecuperada = relojHorario(reloj, resultado);

    do {if (!(horaRecuperada)) {} else {UnityFail( ((("relojHorario debe fallar"))), (UNITY_UINT)((UNITY_UINT)(33)));}} while(0);

}













void test_reloj_debe_almacenar_la_hora_101220(void){

    const uint8_t ESPERADO[6] = {1,0, 1,2, 2,0};

    uint8_t resultado[6]={0};

    const 

         _Bool 

              horaGuardada = relojGuardarHora(reloj, ESPERADO);

    do {if ((horaGuardada)) {} else {UnityFail( ((("relojGuardarHora debe tener exito"))), (UNITY_UINT)((UNITY_UINT)(45)));}} while(0);

    const 

         _Bool 

              horaRecuperada = relojHorario(reloj, resultado);

    do {if ((horaRecuperada)) {} else {UnityFail( ((("relojHorario debe tener exito"))), (UNITY_UINT)((UNITY_UINT)(47)));}} while(0);

    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((resultado)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(48), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);



}













void test_reloj_no_debe_alamacenar_hora_invalida_hora(void){

    const uint8_t ESPERADO[6] = {2,4, 1,2, 2,0};

    uint8_t resultado[6]={0};

    const 

         _Bool 

              horaGuardada = relojGuardarHora(reloj, ESPERADO);

    do {if (!(horaGuardada)) {} else {UnityFail( ((("relojGuardarHora debe fallar"))), (UNITY_UINT)((UNITY_UINT)(61)));}} while(0);

    const 

         _Bool 

              horaRecuperada = relojHorario(reloj, resultado);

    do {if (!(horaRecuperada)) {} else {UnityFail( ((("relojHorario debe fallar"))), (UNITY_UINT)((UNITY_UINT)(63)));}} while(0);

}













void test_reloj_no_debe_alamacenar_hora_invalida_minutos(void){

    const uint8_t ESPERADO[6] = {2,3, 6,2, 2,0};

    uint8_t resultado[6]={0};

    const 

         _Bool 

              horaGuardada = relojGuardarHora(reloj, ESPERADO);

    do {if (!(horaGuardada)) {} else {UnityFail( ((("relojGuardarHora debe fallar"))), (UNITY_UINT)((UNITY_UINT)(75)));}} while(0);

    const 

         _Bool 

              horaRecuperada = relojHorario(reloj, resultado);

    do {if (!(horaRecuperada)) {} else {UnityFail( ((("relojHorario debe fallar"))), (UNITY_UINT)((UNITY_UINT)(77)));}} while(0);

}













void test_reloj_no_debe_alamacenar_hora_invalida_segundos(void){

    const uint8_t ESPERADO[6] = {2,3, 5,9, 6,0};

    uint8_t resultado[6]={0};

    const 

         _Bool 

              horaGuardada = relojGuardarHora(reloj, ESPERADO);

    do {if (!(horaGuardada)) {} else {UnityFail( ((("relojGuardarHora debe fallar"))), (UNITY_UINT)((UNITY_UINT)(89)));}} while(0);

    const 

         _Bool 

              horaRecuperada = relojHorario(reloj, resultado);

    do {if (!(horaRecuperada)) {} else {UnityFail( ((("relojHorario debe fallar"))), (UNITY_UINT)((UNITY_UINT)(91)));}} while(0);

}













void test_reloj_debe_incrementar_segundos_09(void){

    const uint8_t HORA_PREVIA[6] = {0,0, 0,0, 0,9};

    const uint8_t HORA_ESPERADA[6] = {0,0, 0,0, 1,0};

    uint8_t resultado[6]={0};

    relojGuardarHora(reloj, HORA_PREVIA);

    relojTick(reloj);

    relojHorario(reloj,resultado);

    UnityAssertEqualIntArray(( const void*)((HORA_ESPERADA)), ( const void*)((resultado)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(106), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}













void test_reloj_debe_incrementar_segundos_10(void){

    const uint8_t HORA_PREVIA[6] = {0,0, 0,0, 1,0};

    const uint8_t HORA_ESPERADA[6] = {0,0, 0,0, 1,1};

    uint8_t resultado[6]={0};

    relojGuardarHora(reloj, HORA_PREVIA);

    relojTick(reloj);

    relojHorario(reloj,resultado);

    UnityAssertEqualIntArray(( const void*)((HORA_ESPERADA)), ( const void*)((resultado)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(121), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}















void test_reloj_debe_incrementar_minutos_00(void){

    const uint8_t HORA_PREVIA[6] = {0,0, 0,0, 5,9};

    const uint8_t HORA_ESPERADA[6] = {0,0, 0,1, 0,0};

    uint8_t resultado[6]={0};

    relojGuardarHora(reloj, HORA_PREVIA);

    relojTick(reloj);

    relojHorario(reloj,resultado);

    UnityAssertEqualIntArray(( const void*)((HORA_ESPERADA)), ( const void*)((resultado)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(137), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}













void test_reloj_debe_incrementar_minutos_09(void){

    const uint8_t HORA_PREVIA[6] = {0,0, 0,9, 5,9};

    const uint8_t HORA_ESPERADA[6] = {0,0, 1,0, 0,0};

    uint8_t resultado[6]={0};

    relojGuardarHora(reloj, HORA_PREVIA);

    relojTick(reloj);

    relojHorario(reloj,resultado);

    UnityAssertEqualIntArray(( const void*)((HORA_ESPERADA)), ( const void*)((resultado)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(152), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}













void test_reloj_debe_incrementar_hora_00(void){

    const uint8_t HORA_PREVIA[6] = {0,0, 5,9, 5,9};

    const uint8_t HORA_ESPERADA[6] = {0,1, 0,0, 0,0};

    uint8_t resultado[6]={0};

    relojGuardarHora(reloj, HORA_PREVIA);

    relojTick(reloj);

    relojHorario(reloj,resultado);

    UnityAssertEqualIntArray(( const void*)((HORA_ESPERADA)), ( const void*)((resultado)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(167), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}













void test_reloj_debe_incrementar_hora_09(void){

    const uint8_t HORA_PREVIA[6] = {0,9, 5,9, 5,9};

    const uint8_t HORA_ESPERADA[6] = {1,0, 0,0, 0,0};

    uint8_t resultado[6]={0};

    relojGuardarHora(reloj, HORA_PREVIA);

    relojTick(reloj);

    relojHorario(reloj,resultado);

    UnityAssertEqualIntArray(( const void*)((HORA_ESPERADA)), ( const void*)((resultado)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(182), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}













void test_reloj_debe_incrementar_hora_19(void){

    const uint8_t HORA_PREVIA[6] = {1,9, 5,9, 5,9};

    const uint8_t HORA_ESPERADA[6] = {2,0, 0,0, 0,0};

    uint8_t resultado[6]={0};

    relojGuardarHora(reloj, HORA_PREVIA);

    relojTick(reloj);

    relojHorario(reloj,resultado);

    UnityAssertEqualIntArray(( const void*)((HORA_ESPERADA)), ( const void*)((resultado)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(197), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}













void test_reloj_debe_incrementar_hora_23(void){

    const uint8_t HORA_PREVIA[6] = {2,3, 5,9, 5,9};

    const uint8_t HORA_ESPERADA[6] = {0,0, 0,0, 0,0};

    uint8_t resultado[6]={15,15,15,15};

    relojGuardarHora(reloj, HORA_PREVIA);

    relojTick(reloj);

    relojHorario(reloj,resultado);

    UnityAssertEqualIntArray(( const void*)((HORA_ESPERADA)), ( const void*)((resultado)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(212), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}













void test_un_reloj_sin_poner_en_hora_no_debe_correr(void){

    uint8_t anterior[6]={0};

    uint8_t posterior[6]={1,1,1,1};

    relojHorario(reloj, anterior);

    relojTick(reloj);

    relojHorario(reloj, posterior);

    UnityAssertEqualIntArray(( const void*)((anterior)), ( const void*)((posterior)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(226), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}







void ticks2_test_reloj_debe_incrementar_segundos_09(void){

    relojKill(reloj);

    reloj = relojCrear(2,ctrlAlarm);

    const uint8_t HORA_PREVIA[6] = {0,0, 0,0, 0,9};

    const uint8_t HORA_ESPERADA[6] = {0,0, 0,0, 1,0};

    uint8_t resultado[6]={0};

    relojGuardarHora(reloj, HORA_PREVIA);

    relojTick(reloj);

    UnityAssertEqualIntArray(( const void*)((HORA_PREVIA)), ( const void*)((resultado)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(239), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

    relojTick(reloj);

    relojHorario(reloj,resultado);

    UnityAssertEqualIntArray(( const void*)((HORA_ESPERADA)), ( const void*)((resultado)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(242), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}













void ticks2_test_reloj_debe_incrementar_segundos_10(void){

    relojKill(reloj);

    reloj = relojCrear(2,ctrlAlarm);

    const uint8_t HORA_PREVIA[6] = {0,0, 0,0, 1,0};

    const uint8_t HORA_ESPERADA[6] = {0,0, 0,0, 1,1};

    uint8_t resultado[6]={0};

    relojGuardarHora(reloj, HORA_PREVIA);

    relojTick(reloj);

    UnityAssertEqualIntArray(( const void*)((HORA_PREVIA)), ( const void*)((resultado)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(258), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

    relojTick(reloj);

    relojHorario(reloj,resultado);

    UnityAssertEqualIntArray(( const void*)((HORA_ESPERADA)), ( const void*)((resultado)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(261), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}















void ticks2_test_reloj_debe_incrementar_minutos_00(void){

    relojKill(reloj);

    reloj = relojCrear(2,ctrlAlarm);

    const uint8_t HORA_PREVIA[6] = {0,0, 0,0, 5,9};

    const uint8_t HORA_ESPERADA[6] = {0,0, 0,1, 0,0};

    uint8_t resultado[6]={0};

    relojGuardarHora(reloj, HORA_PREVIA);

    relojTick(reloj);

    UnityAssertEqualIntArray(( const void*)((HORA_PREVIA)), ( const void*)((resultado)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(278), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

    relojTick(reloj);

    relojHorario(reloj,resultado);

    UnityAssertEqualIntArray(( const void*)((HORA_ESPERADA)), ( const void*)((resultado)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(281), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}













void ticks2_test_reloj_debe_incrementar_minutos_09(void){

    relojKill(reloj);

    reloj = relojCrear(2,ctrlAlarm);

    const uint8_t HORA_PREVIA[6] = {0,0, 0,9, 5,9};

    const uint8_t HORA_ESPERADA[6] = {0,0, 1,0, 0,0};

    uint8_t resultado[6]={0};

    relojGuardarHora(reloj, HORA_PREVIA);

    relojTick(reloj);

    UnityAssertEqualIntArray(( const void*)((HORA_PREVIA)), ( const void*)((resultado)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(297), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

    relojTick(reloj);

    relojHorario(reloj,resultado);

    UnityAssertEqualIntArray(( const void*)((HORA_ESPERADA)), ( const void*)((resultado)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(300), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}













void ticks2_test_reloj_debe_incrementar_hora_00(void){

    relojKill(reloj);

    reloj = relojCrear(2,ctrlAlarm);

    const uint8_t HORA_PREVIA[6] = {0,0, 5,9, 5,9};

    const uint8_t HORA_ESPERADA[6] = {0,1, 0,0, 0,0};

    uint8_t resultado[6]={0};

    relojGuardarHora(reloj, HORA_PREVIA);

    relojTick(reloj);

    UnityAssertEqualIntArray(( const void*)((HORA_PREVIA)), ( const void*)((resultado)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(316), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

    relojTick(reloj);

    relojHorario(reloj,resultado);

    UnityAssertEqualIntArray(( const void*)((HORA_ESPERADA)), ( const void*)((resultado)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(319), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}













void ticks2_test_reloj_debe_incrementar_hora_09(void){

    relojKill(reloj);

    reloj = relojCrear(2,ctrlAlarm);

    const uint8_t HORA_PREVIA[6] = {0,9, 5,9, 5,9};

    const uint8_t HORA_ESPERADA[6] = {1,0, 0,0, 0,0};

    uint8_t resultado[6]={0};

    relojGuardarHora(reloj, HORA_PREVIA);

    relojTick(reloj);

    UnityAssertEqualIntArray(( const void*)((HORA_PREVIA)), ( const void*)((resultado)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(335), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

    relojTick(reloj);

    relojHorario(reloj,resultado);

    UnityAssertEqualIntArray(( const void*)((HORA_ESPERADA)), ( const void*)((resultado)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(338), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}













void ticks2_test_reloj_debe_incrementar_hora_19(void){

    relojKill(reloj);

    reloj = relojCrear(2,ctrlAlarm);

    const uint8_t HORA_PREVIA[6] = {1,9, 5,9, 5,9};

    const uint8_t HORA_ESPERADA[6] = {2,0, 0,0, 0,0};

    uint8_t resultado[6]={0};

    relojGuardarHora(reloj, HORA_PREVIA);

    relojTick(reloj);

    UnityAssertEqualIntArray(( const void*)((HORA_PREVIA)), ( const void*)((resultado)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(354), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

    relojTick(reloj);

    relojHorario(reloj,resultado);

    UnityAssertEqualIntArray(( const void*)((HORA_ESPERADA)), ( const void*)((resultado)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(357), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}













void ticks2_test_reloj_debe_incrementar_hora_23(void){

    relojKill(reloj);

    reloj = relojCrear(2,ctrlAlarm);

    const uint8_t HORA_PREVIA[6] = {2,3, 5,9, 5,9};

    const uint8_t HORA_ESPERADA[6] = {0,0, 0,0, 0,0};

    uint8_t resultado[6]={15,15,15,15};

    relojGuardarHora(reloj, HORA_PREVIA);

    relojTick(reloj);

    UnityAssertEqualIntArray(( const void*)((HORA_PREVIA)), ( const void*)((resultado)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(373), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

    relojTick(reloj);

    relojHorario(reloj,resultado);

    UnityAssertEqualIntArray(( const void*)((HORA_ESPERADA)), ( const void*)((resultado)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(376), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}













void ticks2_test_un_reloj_sin_poner_en_hora_no_debe_correr(void){

    relojKill(reloj);

    reloj = relojCrear(2,ctrlAlarm);

    uint8_t anterior[6]={0};

    uint8_t posterior[6]={1,1,1,1};

    relojHorario(reloj, anterior);

    relojTick(reloj);

    relojTick(reloj);

    relojHorario(reloj, posterior);

    UnityAssertEqualIntArray(( const void*)((anterior)), ( const void*)((posterior)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(393), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}

void test_reloj_debe_informar_estado_de_la_alarma(void){

    UnityAssertEqualNumber((UNITY_INT)((OFF)), (UNITY_INT)((getEstadoAlarma(reloj))), (

   ((void *)0)

   ), (UNITY_UINT)(396), UNITY_DISPLAY_STYLE_INT);

}

void test_reloj_debe_devolver_la_alarma_0000_si_no_se_ajusto(void){

    uint8_t alarma[4];

    uint8_t CERO[4] = {0,0, 0,0};

    getAlarmaHora(reloj,alarma);

    UnityAssertEqualIntArray(( const void*)((CERO)), ( const void*)((alarma)), (UNITY_UINT32)((4)), (

   ((void *)0)

   ), (UNITY_UINT)(402), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}

void test_reloj_debe_fijar_alarma(void){

    uint8_t hora [6] = {1,2, 2,2, 5,9};

    relojGuardarHora(reloj,hora);

    uint8_t alarma[4] = {1,0, 2,0};

    uint8_t alarmaReloj[4];

    setAlarmaHora(reloj,alarma);

    getAlarmaHora(reloj,alarmaReloj);

    UnityAssertEqualIntArray(( const void*)((alarma)), ( const void*)((alarmaReloj)), (UNITY_UINT32)((4)), (

   ((void *)0)

   ), (UNITY_UINT)(411), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);



}

void test_reloj_debe_poder_prender_la_alarma_con_cambio_en_un_minuto(void){

    uint8_t alarma[4] = {1,2, 2,3};

    uint8_t hora [6] = {1,2, 2,2, 5,9};

    relojGuardarHora(reloj,hora);

    setAlarmaHora(reloj,alarma);

    do {if (!(ALARMA_ESTADO)) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(419)));}} while(0);

    relojTick(reloj);

    do {if ((ALARMA_ESTADO)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(421)));}} while(0);

}

void test_reloj_debe_poder_prender_la_alarma_con_cambio_en_dec_min(void){

    uint8_t alarma[4] = {1,0, 2,0};

    uint8_t hora [6] = {1,0, 1,9, 5,9};

    relojGuardarHora(reloj,hora);

    setAlarmaHora(reloj,alarma);

    do {if (!(ALARMA_ESTADO)) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(428)));}} while(0);

    relojTick(reloj);

    do {if ((ALARMA_ESTADO)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(430)));}} while(0);

}

void test_reloj_debe_poder_prender_la_alarma_con_cambio_en_un_hor(void){

    uint8_t alarma[4] = {1,8, 0,0};

    uint8_t hora [6] = {1,7, 5,9, 5,9};

    relojGuardarHora(reloj,hora);

    setAlarmaHora(reloj,alarma);

    do {if (!(ALARMA_ESTADO)) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(437)));}} while(0);

    relojTick(reloj);

    do {if ((ALARMA_ESTADO)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(439)));}} while(0);

}

void test_reloj_debe_poder_prender_la_alarma_con_cambio_en_cada_digito(void){

    uint8_t alarma[4] = {2,0, 0,0};

    uint8_t hora [6] = {1,9, 5,9, 5,9};

    relojGuardarHora(reloj,hora);

    setAlarmaHora(reloj,alarma);

    do {if (!(ALARMA_ESTADO)) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(446)));}} while(0);

    relojTick(reloj);

    do {if ((ALARMA_ESTADO)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(448)));}} while(0);

    UnityAssertEqualNumber((UNITY_INT)((ON)), (UNITY_INT)((getEstadoAlarma(reloj))), (

   ((void *)0)

   ), (UNITY_UINT)(449), UNITY_DISPLAY_STYLE_INT);

}

void test_reloj_debe_poder_apagar_la_alarma(void){

    uint8_t alarma[4] = {1,0, 2,0};

    uint8_t hora [6] = {1,0, 1,9, 5,9};

    relojGuardarHora(reloj,hora);

    setAlarmaHora(reloj,alarma);

    relojTick(reloj);

    UnityAssertEqualNumber((UNITY_INT)((ON)), (UNITY_INT)((getEstadoAlarma(reloj))), (

   ((void *)0)

   ), (UNITY_UINT)(457), UNITY_DISPLAY_STYLE_INT);

    relojApagarAlarma(reloj);



    do {if (!(ALARMA_ESTADO)) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(460)));}} while(0);

    UnityAssertEqualNumber((UNITY_INT)((READY)), (UNITY_INT)((getEstadoAlarma(reloj))), (

   ((void *)0)

   ), (UNITY_UINT)(461), UNITY_DISPLAY_STYLE_INT);

}



void test_debe_poder_desactivar_la_alarma_apagada(void){

    uint8_t alarma[4] = {1,0, 2,0};

    uint8_t hora [6] = {1,0, 1,9, 5,9};

    relojGuardarHora(reloj,hora);

    setAlarmaHora(reloj,alarma);

    relojTick(reloj);

    relojApagarAlarma(reloj);

    setAlarmaEstado(reloj,OFF);

    UnityAssertEqualNumber((UNITY_INT)((OFF)), (UNITY_INT)((getEstadoAlarma(reloj))), (

   ((void *)0)

   ), (UNITY_UINT)(472), UNITY_DISPLAY_STYLE_INT);

}

void test_puede_activar_la_alarma_con_hora_ya_fijada(void){

    uint8_t alarma[4] = {1,0, 2,0};

    uint8_t hora [6] = {1,0, 1,9, 5,9};

    relojGuardarHora(reloj,hora);

    setAlarmaHora(reloj,alarma);

    UnityAssertEqualNumber((UNITY_INT)((READY)), (UNITY_INT)((getEstadoAlarma(reloj))), (

   ((void *)0)

   ), (UNITY_UINT)(479), UNITY_DISPLAY_STYLE_INT);

    setAlarmaEstado(reloj,OFF);

    setAlarmaEstado(reloj,READY);

    UnityAssertEqualNumber((UNITY_INT)((READY)), (UNITY_INT)((getEstadoAlarma(reloj))), (

   ((void *)0)

   ), (UNITY_UINT)(482), UNITY_DISPLAY_STYLE_INT);



}

void test_reloj_no_debe_poder_activar_la_alarma_sin_la_hora_fijada(void){

    uint8_t alarma[4] = {1,0, 2,0};

    setAlarmaHora(reloj,alarma);

    UnityAssertEqualNumber((UNITY_INT)((OFF)), (UNITY_INT)((getEstadoAlarma(reloj))), (

   ((void *)0)

   ), (UNITY_UINT)(488), UNITY_DISPLAY_STYLE_INT);

    setAlarmaEstado(reloj,READY);

    UnityAssertEqualNumber((UNITY_INT)((OFF)), (UNITY_INT)((getEstadoAlarma(reloj))), (

   ((void *)0)

   ), (UNITY_UINT)(490), UNITY_DISPLAY_STYLE_INT);

}

void test_la_alarma_esta_activada_despues_de_ajustarla(void){

    uint8_t hora [6] = {1,2, 2,2, 5,9};

    relojGuardarHora(reloj,hora);

    uint8_t alarma[4] = {1,0, 2,0};

    uint8_t alarmaReloj[4];

    setAlarmaHora(reloj,alarma);

    getAlarmaHora(reloj,alarmaReloj);

    UnityAssertEqualNumber((UNITY_INT)((READY)), (UNITY_INT)((getEstadoAlarma(reloj))), (

   ((void *)0)

   ), (UNITY_UINT)(499), UNITY_DISPLAY_STYLE_INT);

}

void test_reloj_debe_posponer_alarma(void){

    uint8_t hora [6] = {1,2, 2,2, 5,9};

    uint8_t alarma[4] = {1,0, 2,0};

    relojGuardarHora(reloj,hora);

    setAlarmaHora(reloj,alarma);

    relojTick(reloj);

    relojSnooze(reloj,3);

    do {if (!(ALARMA_ESTADO)) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(508)));}} while(0);

    UnityAssertEqualNumber((UNITY_INT)((SNOOZE)), (UNITY_INT)((getEstadoAlarma(reloj))), (

   ((void *)0)

   ), (UNITY_UINT)(509), UNITY_DISPLAY_STYLE_INT);

    for (int i = 0; i<(60*3);i++) relojTick(reloj);

    do {if ((ALARMA_ESTADO)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(511)));}} while(0);

    UnityAssertEqualNumber((UNITY_INT)((ON)), (UNITY_INT)((getEstadoAlarma(reloj))), (

   ((void *)0)

   ), (UNITY_UINT)(512), UNITY_DISPLAY_STYLE_INT);

}

void test_alarma_funciona_al_otro_dia(void){

    uint8_t hora [6] = {1,2, 2,2, 5,9};

    uint8_t alarma[4] = {1,2, 2,3};

    relojGuardarHora(reloj,hora);

    setAlarmaHora(reloj,alarma);

    relojTick(reloj);

    relojSnooze(reloj,3);

    for (int i = 0; i<(60*3);i++) relojTick(reloj);

    relojApagarAlarma(reloj);

    relojGuardarHora(reloj,hora);

    relojTick(reloj);

    do {if ((ALARMA_ESTADO)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(525)));}} while(0);



}
