#include <stdio.h>
#include <stdbool.h>
#include <pcb/pcb.h>
#include <cspecs/cspec.h>

context (pcb) {
    t_pcb* pcb = pcb_create(1);
    t_pcb* pcb2 = pcb_create(2);

    describe("PCB") {
        it("program counter should be 1 and 2"){
            should_int(pcb_get_pid(pcb)) be equal to(1);
            should_int(pcb_get_pid(pcb2)) be equal to(2);
        } end
    } end
}