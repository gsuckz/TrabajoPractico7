#include <unity.h>
#include <stddef.h>
#include "reloj.h"
#include "stdio.h"

static Reloj *reloj;

void setUp(void){
    reloj = NULL;
    reloj = relojCrear();
}

void tearDown(void){
    relojKill(reloj);
    reloj = (Reloj*)0;
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





