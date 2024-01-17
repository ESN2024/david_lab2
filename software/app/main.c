#include "system.h"
#include "altera_avalon_pio_regs.h"
#include "sys/alt_stdio.h"
#include "sys/alt_sys_init.h"
#include "alt_types.h"
#include "io.h"
#include "unistd.h"
#include "stdio.h"
#include "sys/alt_irq.h"


int main() {
    __uint8_t i =0;

    while(1) {
	if (i==16)
	    i= 0;

	IOWR_ALTERA_AVALON_PIO_DATA(PIO_1_BASE, i);

	usleep(50000);
	usleep(50000);

	usleep(50000);
	usleep(50000);

	usleep(50000);
	usleep(50000);

	usleep(50000);
	usleep(50000);

	usleep(50000);
	usleep(50000);

	i++;
    }
    return 0;
}