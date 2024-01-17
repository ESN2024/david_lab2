#include "system.h"
#include "altera_avalon_pio_regs.h"
#include "sys/alt_stdio.h"
#include "sys/alt_sys_init.h"
#include "alt_types.h"
#include "io.h"
#include "unistd.h"
#include "stdio.h"
#include "sys/alt_irq.h"
#include "altera_avalon_timer.h"
#include "altera_avalon_timer_regs.h"


volatile alt_u16 i =0;


alt_u16 bin_to_bcd(alt_u16 bin){
    alt_u16 local_bin=bin;
    alt_u8 unites, dixaines, centaines;

    unites= local_bin%10;
    dixaines= (local_bin/10)%10;
    centaines= (local_bin/100)%10;

    return (centaines<<8) + (dixaines<<4) + (unites);
}


static void irq_handler_tim(void* context, alt_u32 id) {
    IOWR_ALTERA_AVALON_TIMER_STATUS(TIMER_0_BASE, 0b00);

    IOWR_ALTERA_AVALON_PIO_DATA(PIO_1_BASE, bin_to_bcd(i));
    i++;
}


int main() {
    IOWR_ALTERA_AVALON_TIMER_PERIODH(TIMER_0_BASE, 0x02FA);
    IOWR_ALTERA_AVALON_TIMER_PERIODL(TIMER_0_BASE, 0xF07F);
    IOWR_ALTERA_AVALON_TIMER_CONTROL(TIMER_0_BASE, 0b0111);
    alt_irq_register(TIMER_0_IRQ, NULL, (void*)irq_handler_tim);

    while(1) {
    }
    return 0;
}
