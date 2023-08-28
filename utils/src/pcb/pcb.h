#ifndef PCB_H_
#define PCB_H_

#include <commons/collections/dictionary.h>
#include <commons/collections/list.h>

typedef struct pcb t_pcb;

/**
 * @NAME: pcb_create
 * @DESC: Crea una instancia de "t_pcb".
 */
t_pcb *pcb_create(int);

t_dictionary* cpu_registers_create();

/**
 * Getters & Setters of PCB
 */
int pcb_get_pid(t_pcb*);
int pcb_get_program_counter(t_pcb*);
int pcb_get_priority(t_pcb*);
t_dictionary* pcb_get_cpu_registers(t_pcb*);
t_list* pcb_get_table_open_files(t_pcb*);
void pcb_set_program_counter(t_pcb*, int);
void pcb_set_priority(t_pcb*, int);
void pcb_set_cpu_registers(t_pcb*, t_dictionary*);
void pcb_set_table_open_files(t_pcb*, t_list*);


/**
 * @NAME: pcb_destroy
 * @DESC: Libera la memoria ocupada por una instancia de "t_pcb".
 */
void pcb_destroy(t_pcb *pcb);


#endif