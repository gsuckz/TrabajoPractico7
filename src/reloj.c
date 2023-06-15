#include "reloj.h"
#include <stdint.h>


#define POS_MAX 6
#define POS_MAX_AL 4
#define SEG_U 5
#define SEG_D 4
#define MIN_U 3
#define MIN_D 2
#define HOR_U 1
#define HOR_D 0



typedef struct Reloj {
  uint8_t time[POS_MAX];
  uint8_t alarm[POS_MAX_AL];
  AlarmState estadoAlarma;
  void (*ctrlAlarma)(bool);
  uint32_t  snooze;
} Reloj;

/**
 * @brief Escribe en un arreglo de (size) bytes en la posicion
 * (base) un numero
 * Se escribe en formato BCD rellenando con 0 el arreglo. Ej:
 * toBCD(23,base,6);
 * →base[6] = [0,0,0,0,2,3]
 * @param numero Numero que se escribe
 * @param base Posicion del primer elemento
 * @param size Tamaño del arreglo
 */
static void toBCD(uint8_t numero, uint8_t *base, uint8_t size) {
  for (uint8_t i = size - 1; i > 0; i--) {
    base[i] = numero % 10;
    numero = numero / 10;
  }
}

static void checkAlarm(Reloj * reloj){

  switch (reloj->estadoAlarma){
    case READY:
      for (uint8_t i=0; i< 4;i++){
        if(reloj->alarm[i] != reloj->time[i]){
          reloj->estadoAlarma = ON;
          reloj->ctrlAlarma(1);          
          break;
        }
      } 
    break;

    case SNOOZE:      
      if (!--reloj->snooze) {
        reloj->ctrlAlarma(1);
        reloj->estadoAlarma = ON;
        }
    break;
    
    default:
      break;
  }
  return;
}

Reloj *relojInit( void (*ctrlAlarma)(bool)){
  Reloj *reloj = malloc(sizeof(Reloj));
  *(uint8_t*)reloj = 0xF;
  reloj->ctrlAlarma = ctrlAlarma;
  return reloj;
}

void relojKill(Reloj * reloj){
  free(reloj);
}

void relojConfig(Reloj *reloj, uint8_t hora, uint8_t minutos, uint8_t segundos) {
  toBCD(hora, (HOR_D + reloj->time), 2);
  toBCD(minutos, (MIN_D + reloj->time), 2);
  toBCD(segundos, (SEG_D + reloj->time), 2);
  return;
}

void relojAlarmConfig(Reloj *reloj, uint8_t hora, uint8_t minutos) {
  toBCD(hora, (HOR_D + reloj->alarm), 2);
  toBCD(minutos, (MIN_D + reloj->alarm), 2);
  return;
}

void relojAlarmSet(Reloj *reloj, AlarmState mode) {
  reloj->estadoAlarma = mode;
  return;
}

bool relojTime(Reloj * reloj, uint8_t *resultado) {
  bool hora_config;
  if ((hora_config = (  *(uint8_t*)reloj == 0xF))) 
  for (uint8_t i = 0; i < 6; i++) resultado[i] = reloj->time[i];
  return hora_config;
}

AlarmState relojAlarm(Reloj *reloj, uint8_t *resultado,uint8_t size) {
    for (uint8_t i = 0; i < size; i++) resultado[i] = reloj->alarm[i];
    return reloj->estadoAlarma;
}

void relojSnooze(Reloj * reloj, int snooze){
  if (reloj->estadoAlarma == ON || reloj->estadoAlarma == SNOOZE){  
    reloj->snooze = reloj->snooze + snooze;
    reloj->estadoAlarma = SNOOZE;}
}

void relojAlOff(Reloj * reloj){
  reloj->ctrlAlarma(0);
}
void relojTick(Reloj * reloj){
  static double ticks = 0;
  ticks++;
  if (ticks == TICKS_SEG){
      ticks=0;
      if(10 == ++reloj->time[SEG_U]){
          reloj->time[SEG_U] =0;
          if (6 == ++reloj->time[SEG_D]){
              reloj->time[SEG_D] =0;
              if(10 == ++reloj->time[MIN_U]){
                  reloj->time[MIN_U]=0;
                  checkAlarm(reloj);
                  if(6 == ++reloj->time[MIN_D]){
                      reloj->time[MIN_D]=0;
                      if(10==++reloj->time[HOR_U] || (4==reloj->time[HOR_U] && 2==reloj->time[HOR_D])){
                          reloj->time[HOR_U]=0;
                          if(3==++reloj->time[HOR_D]){
                              reloj->time[HOR_D]=0;
                          }
                      }
                  }
              }  
          }            
      }    
  }  
}