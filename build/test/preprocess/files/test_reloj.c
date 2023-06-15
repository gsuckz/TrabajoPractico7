#include "src/reloj.h"
#include "C:/msys64/ucrt64/lib/ruby/gems/3.1.0/gems/ceedling-0.32.0/vendor/unity/src/unity.h"




static Reloj *reloj;



void setUp(void){

    reloj = 

           ((void *)0)

               ;

    reloj = relojCrear();

}



void tearDown(void){

    relojKill(reloj);

    reloj = (Reloj*)0;

}



void test_un_reloj_sin_poner_en_hora_debe_informar_error_al_pedirle_la_hora(void){

    do { if ((((reloj)) != 

   ((void *)0)

   )) { } else { UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(19)))); } } while (0);

    uint8_t resultado[6]={0};

    const 

         _Bool 

              horaRecuperada = relojHorario(reloj, resultado);

    do { if (!(horaRecuperada)) { } else { UnityFail( ((("relojHorario debe fallar"))), (UNITY_UINT)((UNITY_UINT)(22))); } } while (0);

}



void test_reloj_debe_almacenar_la_hora_101220(void){

    const uint8_t ESPERADO[6] = {1,0, 1,2, 2,0};

    uint8_t resultado[6]={0};

    const 

         _Bool 

              horaGuardada = relojGuardarHora(reloj, ESPERADO);

    do { if ((horaGuardada)) { } else { UnityFail( ((("relojGuardarHora debe tener exito"))), (UNITY_UINT)((UNITY_UINT)(29))); } } while (0);

    const 

         _Bool 

              horaRecuperada = relojHorario(reloj, resultado);

    do { if ((horaRecuperada)) { } else { UnityFail( ((("relojHorario debe tener exito"))), (UNITY_UINT)((UNITY_UINT)(31))); } } while (0);

    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((resultado)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(32), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);



}



void test_reloj_no_debe_alamacenar_hora_invalida_hora(void){

    const uint8_t ESPERADO[6] = {2,4, 1,2, 2,0};

    uint8_t resultado[6]={0};

    const 

         _Bool 

              horaGuardada = relojGuardarHora(reloj, ESPERADO);

    do { if (!(horaGuardada)) { } else { UnityFail( ((("relojGuardarHora debe fallar"))), (UNITY_UINT)((UNITY_UINT)(40))); } } while (0);

    const 

         _Bool 

              horaRecuperada = relojHorario(reloj, resultado);

    do { if (!(horaRecuperada)) { } else { UnityFail( ((("relojHorario debe fallar"))), (UNITY_UINT)((UNITY_UINT)(42))); } } while (0);

}



void test_reloj_no_debe_alamacenar_hora_invalida_minutos(void){

    const uint8_t ESPERADO[6] = {2,3, 6,2, 2,0};

    uint8_t resultado[6]={0};

    const 

         _Bool 

              horaGuardada = relojGuardarHora(reloj, ESPERADO);

    do { if (!(horaGuardada)) { } else { UnityFail( ((("relojGuardarHora debe fallar"))), (UNITY_UINT)((UNITY_UINT)(49))); } } while (0);

    const 

         _Bool 

              horaRecuperada = relojHorario(reloj, resultado);

    do { if (!(horaRecuperada)) { } else { UnityFail( ((("relojHorario debe fallar"))), (UNITY_UINT)((UNITY_UINT)(51))); } } while (0);

}



void test_reloj_no_debe_alamacenar_hora_invalida_segundos(void){

    const uint8_t ESPERADO[6] = {2,3, 5,9, 6,0};

    uint8_t resultado[6]={0};

    const 

         _Bool 

              horaGuardada = relojGuardarHora(reloj, ESPERADO);

    do { if (!(horaGuardada)) { } else { UnityFail( ((("relojGuardarHora debe fallar"))), (UNITY_UINT)((UNITY_UINT)(58))); } } while (0);

    const 

         _Bool 

              horaRecuperada = relojHorario(reloj, resultado);

    do { if (!(horaRecuperada)) { } else { UnityFail( ((("relojHorario debe fallar"))), (UNITY_UINT)((UNITY_UINT)(60))); } } while (0);

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

   ), (UNITY_UINT)(70), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

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

   ), (UNITY_UINT)(80), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

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

   ), (UNITY_UINT)(91), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

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

   ), (UNITY_UINT)(101), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

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

   ), (UNITY_UINT)(111), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

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

   ), (UNITY_UINT)(121), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

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

   ), (UNITY_UINT)(131), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

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

   ), (UNITY_UINT)(141), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}



void test_un_reloj_sin_poner_en_hora_no_debe_correr(void){

    uint8_t anterior[6]={0};

    uint8_t posterior[6]={1,1,1,1};

    relojHorario(reloj, anterior);

    relojTick(reloj);

    relojHorario(reloj, posterior);

    UnityAssertEqualIntArray(( const void*)((anterior)), ( const void*)((posterior)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(150), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}
