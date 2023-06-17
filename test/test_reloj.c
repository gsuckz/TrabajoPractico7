#include <unity.h>
#include <stddef.h>
#include "reloj.h"
#include "stdio.h"

static Reloj *reloj;

bool ALARMA_ESTADO = 0;
void ctrlAlarm(bool estado){
    ALARMA_ESTADO = estado;
}

void setUp(void){
    reloj = NULL;
    reloj = relojCrear(1,ctrlAlarm);
}

void tearDown(void){
    relojKill(reloj);
    reloj = (Reloj*)0;
    ALARMA_ESTADO = 0;
}

/**
 * @brief La librería deberá informar que la hora actual es inválida hasta 
 * que se llama a la función para ajustar la hora por primera vez.
 * 
 */
void test_un_reloj_sin_poner_en_hora_debe_informar_error_al_pedirle_la_hora(void){
    TEST_ASSERT_NOT_NULL(reloj);
    uint8_t resultado[6]={0};
    const bool horaRecuperada = relojHorario(reloj, resultado);
    TEST_ASSERT_FALSE_MESSAGE(horaRecuperada,"relojHorario debe fallar");
}
/**
 * @brief La librería deberá informar que la hora actual es inválida hasta 
 * que se llama a la función para ajustar la hora por primera vez.
 * 
 */

void test_reloj_debe_almacenar_la_hora_101220(void){
    const uint8_t ESPERADO[6] = {1,0, 1,2, 2,0};
    uint8_t resultado[6]={0};
    const bool horaGuardada = relojGuardarHora(reloj, ESPERADO);
    TEST_ASSERT_TRUE_MESSAGE(horaGuardada, "relojGuardarHora debe tener exito");
    const bool horaRecuperada = relojHorario(reloj, resultado);
    TEST_ASSERT_TRUE_MESSAGE(horaRecuperada, "relojHorario debe tener exito");
    TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERADO,resultado,6);    

}
/**
 * @brief La librería deberá informar que la hora actual es inválida hasta 
 * que se llama a la función para ajustar la hora por primera vez.
 * 
 */

void test_reloj_no_debe_alamacenar_hora_invalida_hora(void){
    const uint8_t ESPERADO[6] = {2,4, 1,2, 2,0};
    uint8_t resultado[6]={0};
    const bool horaGuardada = relojGuardarHora(reloj, ESPERADO);
    TEST_ASSERT_FALSE_MESSAGE(horaGuardada, "relojGuardarHora debe fallar");
    const bool horaRecuperada = relojHorario(reloj, resultado);
    TEST_ASSERT_FALSE_MESSAGE(horaRecuperada, "relojHorario debe fallar");
}
/**
 * @brief La librería deberá informar que la hora actual es inválida hasta 
 * que se llama a la función para ajustar la hora por primera vez.
 * 
 */

void test_reloj_no_debe_alamacenar_hora_invalida_minutos(void){
    const uint8_t ESPERADO[6] = {2,3, 6,2, 2,0};
    uint8_t resultado[6]={0};
    const bool horaGuardada = relojGuardarHora(reloj, ESPERADO);
    TEST_ASSERT_FALSE_MESSAGE(horaGuardada, "relojGuardarHora debe fallar");
    const bool horaRecuperada = relojHorario(reloj, resultado);
    TEST_ASSERT_FALSE_MESSAGE(horaRecuperada, "relojHorario debe fallar");
}
/**
 * @brief La librería deberá informar que la hora actual es inválida hasta 
 * que se llama a la función para ajustar la hora por primera vez.
 * 
 */

void test_reloj_no_debe_alamacenar_hora_invalida_segundos(void){
    const uint8_t ESPERADO[6] = {2,3, 5,9, 6,0};
    uint8_t resultado[6]={0};
    const bool horaGuardada = relojGuardarHora(reloj, ESPERADO);
    TEST_ASSERT_FALSE_MESSAGE(horaGuardada, "relojGuardarHora debe fallar");
    const bool horaRecuperada = relojHorario(reloj, resultado);
    TEST_ASSERT_FALSE_MESSAGE(horaRecuperada, "relojHorario debe fallar");
}
/**
 * @brief La librería deberá informar que la hora actual es inválida hasta 
 * que se llama a la función para ajustar la hora por primera vez.
 * 
 */

void test_reloj_debe_incrementar_segundos_09(void){
    const uint8_t HORA_PREVIA[6] = {0,0, 0,0, 0,9};
    const uint8_t HORA_ESPERADA[6] = {0,0, 0,0, 1,0};
    uint8_t resultado[6]={0};
    relojGuardarHora(reloj, HORA_PREVIA);
    relojTick(reloj);
    relojHorario(reloj,resultado);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(HORA_ESPERADA,resultado,6);
}
/**
 * @brief La librería deberá informar que la hora actual es inválida hasta 
 * que se llama a la función para ajustar la hora por primera vez.
 * 
 */

void test_reloj_debe_incrementar_segundos_10(void){
    const uint8_t HORA_PREVIA[6] = {0,0, 0,0, 1,0};
    const uint8_t HORA_ESPERADA[6] = {0,0, 0,0, 1,1};
    uint8_t resultado[6]={0};
    relojGuardarHora(reloj, HORA_PREVIA);
    relojTick(reloj);
    relojHorario(reloj,resultado);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(HORA_ESPERADA,resultado,6);
}

/**
 * @brief La librería deberá informar que la hora actual es inválida hasta 
 * que se llama a la función para ajustar la hora por primera vez.
 * 
 */

void test_reloj_debe_incrementar_minutos_00(void){
    const uint8_t HORA_PREVIA[6] = {0,0, 0,0, 5,9};
    const uint8_t HORA_ESPERADA[6] = {0,0, 0,1, 0,0};
    uint8_t resultado[6]={0};
    relojGuardarHora(reloj, HORA_PREVIA);
    relojTick(reloj);
    relojHorario(reloj,resultado);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(HORA_ESPERADA,resultado,6);
}
/**
 * @brief La librería deberá informar que la hora actual es inválida hasta 
 * que se llama a la función para ajustar la hora por primera vez.
 * 
 */

void test_reloj_debe_incrementar_minutos_09(void){
    const uint8_t HORA_PREVIA[6] = {0,0, 0,9, 5,9};
    const uint8_t HORA_ESPERADA[6] = {0,0, 1,0, 0,0};
    uint8_t resultado[6]={0};
    relojGuardarHora(reloj, HORA_PREVIA);
    relojTick(reloj);
    relojHorario(reloj,resultado);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(HORA_ESPERADA,resultado,6);
}
/**
 * @brief La librería deberá informar que la hora actual es inválida hasta 
 * que se llama a la función para ajustar la hora por primera vez.
 * 
 */

void test_reloj_debe_incrementar_hora_00(void){
    const uint8_t HORA_PREVIA[6] = {0,0, 5,9, 5,9};
    const uint8_t HORA_ESPERADA[6] = {0,1, 0,0, 0,0};
    uint8_t resultado[6]={0};
    relojGuardarHora(reloj, HORA_PREVIA);
    relojTick(reloj);
    relojHorario(reloj,resultado);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(HORA_ESPERADA,resultado,6);
}
/**
 * @brief La librería deberá informar que la hora actual es inválida hasta 
 * que se llama a la función para ajustar la hora por primera vez.
 * 
 */

void test_reloj_debe_incrementar_hora_09(void){
    const uint8_t HORA_PREVIA[6] = {0,9, 5,9, 5,9};
    const uint8_t HORA_ESPERADA[6] = {1,0, 0,0, 0,0};
    uint8_t resultado[6]={0};
    relojGuardarHora(reloj, HORA_PREVIA);
    relojTick(reloj);
    relojHorario(reloj,resultado);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(HORA_ESPERADA,resultado,6);
}
/**
 * @brief La librería deberá informar que la hora actual es inválida hasta 
 * que se llama a la función para ajustar la hora por primera vez.
 * 
 */

void test_reloj_debe_incrementar_hora_19(void){
    const uint8_t HORA_PREVIA[6] = {1,9, 5,9, 5,9};
    const uint8_t HORA_ESPERADA[6] = {2,0, 0,0, 0,0};
    uint8_t resultado[6]={0};
    relojGuardarHora(reloj, HORA_PREVIA);
    relojTick(reloj);
    relojHorario(reloj,resultado);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(HORA_ESPERADA,resultado,6);
}
/**
 * @brief La librería deberá informar que la hora actual es inválida hasta 
 * que se llama a la función para ajustar la hora por primera vez.
 * 
 */

void test_reloj_debe_incrementar_hora_23(void){
    const uint8_t HORA_PREVIA[6] = {2,3, 5,9, 5,9};
    const uint8_t HORA_ESPERADA[6] = {0,0, 0,0, 0,0};
    uint8_t resultado[6]={15,15,15,15};
    relojGuardarHora(reloj, HORA_PREVIA);
    relojTick(reloj);
    relojHorario(reloj,resultado);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(HORA_ESPERADA,resultado,6);
}

/**
 * @brief La librería deberá informar que la hora actual es inválida hasta 
 * que se llama a la función para ajustar la hora por primera vez.
 * 
 */
void test_un_reloj_sin_poner_en_hora_no_debe_correr(void){
    uint8_t anterior[6]={0};
    uint8_t posterior[6]={1,1,1,1};
    relojHorario(reloj, anterior);
    relojTick(reloj);
    relojHorario(reloj, posterior);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(anterior,posterior,6);
}


///////////MISMOS TEST CON OTRO TICKS///////////////
void ticks2_test_reloj_debe_incrementar_segundos_09(void){
    relojKill(reloj);
    reloj = relojCrear(2,ctrlAlarm);
    const uint8_t HORA_PREVIA[6] = {0,0, 0,0, 0,9};
    const uint8_t HORA_ESPERADA[6] = {0,0, 0,0, 1,0};
    uint8_t resultado[6]={0};
    relojGuardarHora(reloj, HORA_PREVIA);
    relojTick(reloj);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(HORA_PREVIA,resultado,6);    
    relojTick(reloj);  
    relojHorario(reloj,resultado);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(HORA_ESPERADA,resultado,6);
}
/**
 * @brief La librería deberá informar que la hora actual es inválida hasta 
 * que se llama a la función para ajustar la hora por primera vez.
 * 
 */

void ticks2_test_reloj_debe_incrementar_segundos_10(void){
    relojKill(reloj);
    reloj = relojCrear(2,ctrlAlarm);
    const uint8_t HORA_PREVIA[6] = {0,0, 0,0, 1,0};
    const uint8_t HORA_ESPERADA[6] = {0,0, 0,0, 1,1};
    uint8_t resultado[6]={0};
    relojGuardarHora(reloj, HORA_PREVIA);
    relojTick(reloj);
    TEST_ASSERT_EQUAL_UINT8_ARRAY( HORA_PREVIA,resultado,6);    
    relojTick(reloj);    
    relojHorario(reloj,resultado);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(HORA_ESPERADA,resultado,6);
}

/**
 * @brief La librería deberá informar que la hora actual es inválida hasta 
 * que se llama a la función para ajustar la hora por primera vez.
 * 
 */

void ticks2_test_reloj_debe_incrementar_minutos_00(void){
    relojKill(reloj);
    reloj = relojCrear(2,ctrlAlarm);
    const uint8_t HORA_PREVIA[6] = {0,0, 0,0, 5,9};
    const uint8_t HORA_ESPERADA[6] = {0,0, 0,1, 0,0};
    uint8_t resultado[6]={0};
    relojGuardarHora(reloj, HORA_PREVIA);
    relojTick(reloj);
    TEST_ASSERT_EQUAL_UINT8_ARRAY( HORA_PREVIA,resultado,6);    
    relojTick(reloj);  
    relojHorario(reloj,resultado);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(HORA_ESPERADA,resultado,6);
}
/**
 * @brief La librería deberá informar que la hora actual es inválida hasta 
 * que se llama a la función para ajustar la hora por primera vez.
 * 
 */

void ticks2_test_reloj_debe_incrementar_minutos_09(void){
    relojKill(reloj);
    reloj = relojCrear(2,ctrlAlarm);
    const uint8_t HORA_PREVIA[6] = {0,0, 0,9, 5,9};
    const uint8_t HORA_ESPERADA[6] = {0,0, 1,0, 0,0};
    uint8_t resultado[6]={0};
    relojGuardarHora(reloj, HORA_PREVIA);
    relojTick(reloj);
    TEST_ASSERT_EQUAL_UINT8_ARRAY( HORA_PREVIA,resultado,6);    
    relojTick(reloj);  
    relojHorario(reloj,resultado);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(HORA_ESPERADA,resultado,6);
}
/**
 * @brief La librería deberá informar que la hora actual es inválida hasta 
 * que se llama a la función para ajustar la hora por primera vez.
 * 
 */

void ticks2_test_reloj_debe_incrementar_hora_00(void){
    relojKill(reloj);
    reloj = relojCrear(2,ctrlAlarm);
    const uint8_t HORA_PREVIA[6] = {0,0, 5,9, 5,9};
    const uint8_t HORA_ESPERADA[6] = {0,1, 0,0, 0,0};
    uint8_t resultado[6]={0};
    relojGuardarHora(reloj, HORA_PREVIA);
    relojTick(reloj);
    TEST_ASSERT_EQUAL_UINT8_ARRAY( HORA_PREVIA,resultado,6);    
    relojTick(reloj);  
    relojHorario(reloj,resultado);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(HORA_ESPERADA,resultado,6);
}
/**
 * @brief La librería deberá informar que la hora actual es inválida hasta 
 * que se llama a la función para ajustar la hora por primera vez.
 * 
 */

void ticks2_test_reloj_debe_incrementar_hora_09(void){
    relojKill(reloj);
    reloj = relojCrear(2,ctrlAlarm);
    const uint8_t HORA_PREVIA[6] = {0,9, 5,9, 5,9};
    const uint8_t HORA_ESPERADA[6] = {1,0, 0,0, 0,0};
    uint8_t resultado[6]={0};
    relojGuardarHora(reloj, HORA_PREVIA);
    relojTick(reloj);
    TEST_ASSERT_EQUAL_UINT8_ARRAY( HORA_PREVIA,resultado,6);    
    relojTick(reloj);  
    relojHorario(reloj,resultado);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(HORA_ESPERADA,resultado,6);
}
/**
 * @brief La librería deberá informar que la hora actual es inválida hasta 
 * que se llama a la función para ajustar la hora por primera vez.
 * 
 */

void ticks2_test_reloj_debe_incrementar_hora_19(void){
    relojKill(reloj);
    reloj = relojCrear(2,ctrlAlarm);
    const uint8_t HORA_PREVIA[6] = {1,9, 5,9, 5,9};
    const uint8_t HORA_ESPERADA[6] = {2,0, 0,0, 0,0};
    uint8_t resultado[6]={0};
    relojGuardarHora(reloj, HORA_PREVIA);
    relojTick(reloj);
    TEST_ASSERT_EQUAL_UINT8_ARRAY( HORA_PREVIA,resultado,6);    
    relojTick(reloj);  
    relojHorario(reloj,resultado);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(HORA_ESPERADA,resultado,6);
}
/**
 * @brief La librería deberá informar que la hora actual es inválida hasta 
 * que se llama a la función para ajustar la hora por primera vez.
 * 
 */

void ticks2_test_reloj_debe_incrementar_hora_23(void){
    relojKill(reloj);
    reloj = relojCrear(2,ctrlAlarm);
    const uint8_t HORA_PREVIA[6] = {2,3, 5,9, 5,9};
    const uint8_t HORA_ESPERADA[6] = {0,0, 0,0, 0,0};
    uint8_t resultado[6]={15,15,15,15};
    relojGuardarHora(reloj, HORA_PREVIA);
    relojTick(reloj);
    TEST_ASSERT_EQUAL_UINT8_ARRAY( HORA_PREVIA,resultado,6);    
    relojTick(reloj);  
    relojHorario(reloj,resultado);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(HORA_ESPERADA,resultado,6);
}

/**
 * @brief La librería deberá informar que la hora actual es inválida hasta 
 * que se llama a la función para ajustar la hora por primera vez.
 * 
 */
void ticks2_test_un_reloj_sin_poner_en_hora_no_debe_correr(void){
    relojKill(reloj);
    reloj = relojCrear(2,ctrlAlarm);
    uint8_t anterior[6]={0};
    uint8_t posterior[6]={1,1,1,1};
    relojHorario(reloj, anterior);
    relojTick(reloj);
    relojTick(reloj);  
    relojHorario(reloj, posterior);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(anterior,posterior,6);
}





void test_reloj_debe_informar_estado_de_la_alarma(void){
    TEST_ASSERT_EQUAL(OFF,getEstadoAlarma(reloj));
}


void test_reloj_debe_devolver_la_alarma_0000_si_no_se_ajusto(void){
    uint8_t alarma[4];
    uint8_t CERO[4] = {0,0, 0,0};
    getAlarmaHora(reloj,alarma);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(CERO,alarma,4);
}

void test_reloj_debe_fijar_alarma(void){
    uint8_t hora [6] = {1,2, 2,2, 5,9}; 
    relojGuardarHora(reloj,hora);
    uint8_t alarma[4] = {1,0, 2,0};
    uint8_t alarmaReloj[4];
    setAlarmaHora(reloj,alarma);
    getAlarmaHora(reloj,alarmaReloj);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(alarma,alarmaReloj,4);

}

void test_reloj_debe_poder_prender_la_alarma_con_cambio_en_un_minuto(void){
    uint8_t alarma[4] = {1,2, 2,3};
    uint8_t hora [6] = {1,2, 2,2, 5,9}; 
    relojGuardarHora(reloj,hora);
    setAlarmaHora(reloj,alarma);
    TEST_ASSERT_FALSE(ALARMA_ESTADO);
    relojTick(reloj);
    TEST_ASSERT_TRUE(ALARMA_ESTADO); 
}

void test_reloj_debe_poder_prender_la_alarma_con_cambio_en_dec_min(void){
    uint8_t alarma[4] = {1,0, 2,0};
    uint8_t hora [6] = {1,0, 1,9, 5,9}; 
    relojGuardarHora(reloj,hora);
    setAlarmaHora(reloj,alarma);
    TEST_ASSERT_FALSE(ALARMA_ESTADO);
    relojTick(reloj);
    TEST_ASSERT_TRUE(ALARMA_ESTADO); 
}
void test_reloj_debe_poder_prender_la_alarma_con_cambio_en_un_hor(void){
    uint8_t alarma[4] = {1,8, 0,0};
    uint8_t hora [6] = {1,7, 5,9, 5,9}; 
    relojGuardarHora(reloj,hora);
    setAlarmaHora(reloj,alarma);
    TEST_ASSERT_FALSE(ALARMA_ESTADO);
    relojTick(reloj);
    TEST_ASSERT_TRUE(ALARMA_ESTADO); 
}

void test_reloj_debe_poder_prender_la_alarma_con_cambio_en_cada_digito(void){
    uint8_t alarma[4] = {2,0, 0,0};
    uint8_t hora [6] = {1,9, 5,9, 5,9}; 
    relojGuardarHora(reloj,hora);
    setAlarmaHora(reloj,alarma);
    TEST_ASSERT_FALSE(ALARMA_ESTADO);
    relojTick(reloj);
    TEST_ASSERT_TRUE(ALARMA_ESTADO); 
    TEST_ASSERT_EQUAL(ON,getEstadoAlarma(reloj));
}


void test_reloj_debe_poder_apagar_la_alarma(void){
    uint8_t alarma[4] = {1,0, 2,0};
    uint8_t hora [6] = {1,2,  1,9, 5,9};
    relojHorario(reloj,hora);
    setAlarmaHora(reloj,alarma);
    relojTick(reloj);
    callarAlarma(reloj);
    TEST_ASSERT_FALSE(ALARMA_ESTADO);
    TEST_ASSERT_EQUAL(READY,getEstadoAlarma(reloj));
}
void test_no_debe_poder_desactivar_la_alarma_encendida(void){
    uint8_t alarma[4] = {1,0, 2,0};
    uint8_t hora [6] = {1,0, 1,9, 5,9}; 
    relojGuardarHora(reloj,hora);
    setAlarmaHora(reloj,alarma);
    relojTick(reloj);
    setAlarmaEstado(reloj,OFF);
    TEST_ASSERT_EQUAL(ON,getEstadoAlarma(reloj));
}

void test_debe_poder_desactivar_la_alarma_apagada(void){
    uint8_t alarma[4] = {1,0, 2,0};
    uint8_t hora [6] = {1,0,  1,9, 5,9};
    relojGuardarHora(reloj,hora);
    setAlarmaHora(reloj,alarma);
    relojTick(reloj);
    callarAlarma(reloj);
    setAlarmaEstado(reloj,OFF);
    TEST_ASSERT_EQUAL(OFF,getEstadoAlarma(reloj));
}
void test_puede_activar_la_alarma_con_hora_ya_fijada(void){
    uint8_t alarma[4] = {1,0, 2,0};
    uint8_t hora [6] = {1,0,  1,9, 5,9};
    relojGuardarHora(reloj,hora);
    setAlarmaHora(reloj,alarma);
    TEST_ASSERT_EQUAL(READY,getEstadoAlarma(reloj));
    setAlarmaEstado(reloj,OFF);
    setAlarmaEstado(reloj,READY);
    TEST_ASSERT_EQUAL(READY,getEstadoAlarma(reloj));

}
void test_reloj_no_debe_poder_activar_la_alarma_sin_la_hora_fijada(void){
    uint8_t alarma[4] = {1,0, 2,0};
    setAlarmaHora(reloj,alarma);
    TEST_ASSERT_EQUAL(OFF,getEstadoAlarma(reloj));
    setAlarmaEstado(reloj,READY);
    TEST_ASSERT_EQUAL(OFF,getEstadoAlarma(reloj));    
}
void test_la_alarma_esta_activada_despues_de_ajustarla(void){
    uint8_t hora [6] = {1,2, 2,2, 5,9}; 
    relojGuardarHora(reloj,hora);
    uint8_t alarma[4] = {1,0, 2,0};
    uint8_t alarmaReloj[4];
    setAlarmaHora(reloj,alarma);
    getAlarmaHora(reloj,alarmaReloj);
    TEST_ASSERT_EQUAL(READY,getEstadoAlarma(reloj));
}
void test_reloj_debe_posponer_alarma(void){

}
void test_reloj_no_debe_posponer_la_alarma_si_no_se_activo(void){

}
void test_reloj_debe_volver_a_activar_alarma_en_el_horario_fijado_aunque_haya_sido_pospuesta_el_dia_anterior(void){

}

