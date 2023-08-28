#include <stdlib.h>
#include <stdio.h>
#include <commons/string.h>
#include <commons/collections/list.h>
#include <commons/collections/dictionary.h>
#include <pcb/pcb.h>

struct pcb {
    int pid;
    int program_counter;
    int priority;
    t_dictionary* cpu_registers;
    t_list* table_open_files;
};

static int global_pid = 0;

/**
 * @NAME: pcb_create
 * @DESC: Crea una instancia de "t_pcb".
 */
t_pcb* pcb_create(int priority){
    t_pcb* new_pcb = malloc(sizeof(t_pcb));
    new_pcb->pid = ++global_pid;
    new_pcb->program_counter = 0;
    new_pcb->priority = priority;
    new_pcb->cpu_registers = cpu_registers_create();
    new_pcb->table_open_files = list_create();

    return new_pcb;
}

t_dictionary* cpu_registers_create(){
    t_dictionary *cpu_registers = dictionary_create();
    char register_4_bytes[4] = {'\0'};
    char register_8_bytes[8] = {'\0'};
    char register_16_bytes[16] = {'\0'}; 
    dictionary_put(cpu_registers, "AX", register_4_bytes);
    dictionary_put(cpu_registers, "BX", register_4_bytes);
    dictionary_put(cpu_registers, "CX", register_4_bytes);
    dictionary_put(cpu_registers, "DX", register_4_bytes);
    dictionary_put(cpu_registers, "EAX", register_8_bytes);
    dictionary_put(cpu_registers, "EBX", register_8_bytes);
    dictionary_put(cpu_registers, "ECX", register_8_bytes);
    dictionary_put(cpu_registers, "EDX", register_8_bytes);
    dictionary_put(cpu_registers, "RAX", register_16_bytes);
    dictionary_put(cpu_registers, "RBX", register_16_bytes);
    dictionary_put(cpu_registers, "RCX", register_16_bytes);
    dictionary_put(cpu_registers, "RDX", register_16_bytes);

    return cpu_registers;
}

/**
 * Getters & Setters of PCB
 */
int pcb_get_pid(t_pcb* pcb){
    return pcb->pid;
}
int pcb_get_program_counter(t_pcb* pcb){
    return pcb->program_counter;
}
int pcb_get_priority(t_pcb* pcb){
    return pcb->priority;
}
t_dictionary* pcb_get_cpu_registers(t_pcb* pcb){
    return pcb->cpu_registers;
}
t_list* pcb_get_table_open_files(t_pcb* pcb){
    return pcb->table_open_files;
}
void pcb_set_program_counter(t_pcb* pcb, int value){
    pcb->program_counter = value;
}
void pcb_set_priority(t_pcb* pcb, int value){
    pcb->priority = value;
}
void pcb_set_cpu_registers(t_pcb* pcb, t_dictionary* dictionary){
    pcb->cpu_registers = dictionary;
}
void pcb_set_table_open_files(t_pcb* pcb, t_list* list){
    pcb->table_open_files = list;
}


/**
 * @NAME: pcb_destroy
 * @DESC: Libera la memoria ocupada por una instancia de "t_pcb".
 */
void pcb_destroy(t_pcb *pcb){
    list_clean(pcb->table_open_files);
    dictionary_destroy(pcb->cpu_registers);
    free(pcb);
}