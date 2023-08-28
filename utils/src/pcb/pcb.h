#ifndef PCB_H_
#define PCB_H_

#include <commons/collections/dictionary.h>
#include <commons/collections/list.h>

typedef struct pcb t_pcb;

/**
 * @NAME: pcb_new
 * @DESC: Crea una instancia de "t_pcb".
 */
t_pcb *pcb_new(int);

t_dictionary* cpu_registers_create();

/**
 * @NAME: pcb_destroy
 * @DESC: Libera la memoria ocupada por una instancia de "t_pcb".
 */
void pcb_destroy(t_pcb *pcb);


#endif