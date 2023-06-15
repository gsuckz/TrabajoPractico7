#ifndef RELOJ_H
#define RELOJ_H
#include <stdint.h>
#include <stdbool.h>

typedef struct Reloj Reloj;

/**
 * @brief Crea un objeto reloj en heap y devuelve un puntero a el
 * 
 * 
 * @return Reloj* 
 */
Reloj * relojCrear(void);
/**
 * @brief Libera la memoria reservada para el objeto reloj
 * 
 * @param reloj 
 */
void relojKill(Reloj * reloj);
/**
 * @brief Guarda la hora en el reloj
 * 
 * @param reloj 
 * @param hora Valor de hora en formato BCD sin compactar
 * {<decena de hora>,<unidad de hora>,<d. de minuto>,<u. de minuto>,<d. de segundo>,<u. de segundo>}
 * @return true si se ingresó una hora valida
 * @return false si no se ingresó una hora valida, ademas no tiene efectos secundarios
 */
bool relojGuardarHora(Reloj * reloj,const uint8_t hora[6]);
/**
 * @brief Recupera la hora del reloj. 
 * 
 * 
 * @param reloj
 * @param hora Luego del llamado contiene la hora actual del reloj en formato BCD sin compactar
 * {<decena de hora>,<unidad de hora>,<d. de minuto>,<u. de minuto>,<d. de segundo>,<u. de segundo>}
 * @return true Hora contiene la hora del reloj
 * @return false No fue asignada una hora correcta
 */
bool relojHorario(Reloj * reloj, uint8_t hora[6]);
/**
 * @brief Incrementa los segundos al ser llamada el numero
 * configurado de veces
 * 
 * @param reloj 
 */
void relojTick(Reloj * reloj);

#endif

