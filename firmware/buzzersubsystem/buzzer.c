//Name: Muneeb Ahmed

#include <string.h>

#include "FreeRTOS.h"
#include "task.h"

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/timer.h>
#include <libopencm3/cm3/nvic.h>

#include "usbcdc.h"

static void buzzer(void *args __attribute__((unused))) {

    char state;
    int i, j;

    rcc_periph_clock_enable(RCC_GPIOA);
    rcc_periph_clock_enable(RCC_GPIOC);
    
    gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_2_MHZ, GPIO_CNF_OUTPUT_PUSHPULL, GPIO8); 
    gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_2_MHZ, GPIO_CNF_OUTPUT_PUSHPULL, GPIO13);

    gpio_set(GPIOC, GPIO13);    

    for (;;)
    {
        state = usb_getc();
        
        if (state == 'h')
        {
            for (i = 0; i <= 100; i++)
            {
                gpio_clear(GPIOC, GPIO13);
                gpio_clear(GPIOA, GPIO8);
                for (j = 0; j < 1500; j++)
                    __asm__("nop");

                gpio_set(GPIOC, GPIO13);
                gpio_set(GPIOA, GPIO8);

                for (j = 0; j < 1500; j++)
                    __asm__("nop");
            }
        }
        
        if (state == 's')
        {
            for (i = 0; i <= 10; i++)
            {
                gpio_clear(GPIOC, GPIO13);
                gpio_clear(GPIOA, GPIO8);
                for (j = 0; j < 15000; j++)
                    __asm__("nop");

                gpio_set(GPIOC, GPIO13);
                gpio_set(GPIOA, GPIO8);

                for (j = 0; j < 15000; j++)
                    __asm__("nop");
            }
        }
    }
}

int main(void) {

    rcc_clock_setup_pll(&rcc_hse_configs[RCC_CLOCK_HSE8_72MHZ]);

    usb_start();

    xTaskCreate(buzzer, "buzzer", 100, NULL, configMAX_PRIORITIES-1, NULL);
    vTaskStartScheduler();
    
    for (;;);
    return 0;
}
