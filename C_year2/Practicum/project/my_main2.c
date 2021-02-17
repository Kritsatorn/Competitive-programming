#include <avr/io.h>
#include <avr/interrupt.h>  /* for sei() */
#include <util/delay.h>     /* for _delay_ms() */
#include <avr/pgmspace.h>   /* required by usbdrv.h */

#include "peri.h"
#include "usbdrv.h"


#define RQ_SET_MOTOR      0
#define RQ_GET_LIGHT1     1
#define RQ_GET_LIGHT2     2

/* ------------------------------------------------------------------------- */
/* ----------------------------- USB interface ----------------------------- */
/* ------------------------------------------------------------------------- */
usbMsgLen_t usbFunctionSetup(uint8_t data[8])
{
    usbRequest_t *rq = (void *)data;

    /* declared as static so they stay valid when usbFunctionSetup returns */
    // static uint8_t switch_state;
    static uint16_t light1 ,light2;
    if (rq->bRequest == RQ_SET_MOTOR )
    {
        uint8_t led_state = rq->wValue.bytes[0];
        uint8_t led_no  = rq->wIndex.bytes[0];
        set_led(led_no, led_state);
        return 0;
    }

    else if (rq->bRequest == RQ_GET_LIGHT1)
    {
        light1 = read_adc(PC3);
        usbMsgPtr = &light1;
        return 2;
    }
    else if (rq->bRequest == RQ_GET_LIGHT2)
    {
        light2 = read_adc(PC4);
        usbMsgPtr = &light2;
        return 2;
    }
    /* default for not implemented requests: return no data back to host */
    return 0;
}

/* ------------------------------------------------------------------------- */
int main(void)
{
    init_peri();

    usbInit();

    /* enforce re-enumeration, do this while interrupts are disabled! */
    usbDeviceDisconnect();
    _delay_ms(300);
    usbDeviceConnect();

    /* enable global interrupts */
    sei();

    /* main event loop */
    for(;;)
    {
        usbPoll();
    }

    return 0;
}