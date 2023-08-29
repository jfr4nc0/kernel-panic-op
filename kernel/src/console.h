#ifndef CONSOLE_H_
#define CONSOLE_H_

void initialize_console();

void create_process();

void kill_process();

void create_scheduler();

void stop_scheduler();

void change_multiprogramming_degree();

void* list_process_by_pid(int);

#endif