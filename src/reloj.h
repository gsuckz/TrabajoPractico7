#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define TICKS_SEG 1000

typedef struct Reloj Reloj;
typedef enum AlarmState { OFF, ON, READY, SNOOZE }AlarmState;


/**
 * @brief Reserva memoria para guardar un reloj
 * 
 * @return Reloj* Puntero al reloj creado
 */
Reloj * relojInit(void (*ctrlAlarma)(bool));
/**
 * @brief Configura la hora del relok
 * 
 * @param reloj 
 * @param hora 
 * @param minutos 
 * @param segundos 
 */
void relojConfig(Reloj * reloj, uint8_t hora, uint8_t minutos, uint8_t segundos);
/**
 * @brief Configura la alarma del Reloj
 * 
 * @param hora 
 * @param minutos 
 */
void relojAlarmConfig(Reloj * reloj, uint8_t hora, uint8_t minutos);
/**
 * @brief Configura el modo de la alarma
 * 
 * @param reloj 
 * @param mode 
 */
void relojAlarmSet(Reloj * reloj, AlarmState mode);
/**
 * @brief Incrementa los ticks del reloj al ser llamada
 * 
 */
void relojTick(Reloj * reloj);
/**
 * @brief Pospone la alarma (snooze) minutos
 * 
 * @param reloj 
 * @param snooze 
 */
void relojSnooze(Reloj * reloj, int snooze);
/**
 * @brief Libera la memoria de (reloj)
 * 
 */
void relojKill(Reloj * reloj);
/**
 * @brief Alamacena la hora de (reloj) en formato BCD
 * en la direccion (resultado).
 * Devuelve false si la hora no fue seteada
 * 
 * @param reloj 
 * @param resultado Debe apuntar a un arreglo de 8 bytes
 */
bool relojTime(Reloj *reloj, uint8_t *resultado);
/**
 * @brief Apaga alarma del reloj
 * 
 * @param reloj 
 */
void relojAlOff(Reloj * reloj);