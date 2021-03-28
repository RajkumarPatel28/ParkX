//Name: Rajkumar Patel

#include <FreeRTOS.h>
#include <task.h>

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/cm3/nvic.h>

#include "usbcdc.h"

static void gpio_clean(void)
{
    //Makes all segments off
    gpio_set(GPIOA,GPIO1);
    gpio_set(GPIOA,GPIO2);
    gpio_set(GPIOA,GPIO3);
    gpio_set(GPIOA,GPIO4);
    gpio_set(GPIOA,GPIO5);
    gpio_set(GPIOA,GPIO6);
    gpio_set(GPIOA,GPIO7);
}

static void display(void *args __attribute__((unused)))
{
    char spots;

    rcc_periph_clock_enable(RCC_GPIOA);

    gpio_set_mode(GPIOA,GPIO_MODE_OUTPUT_50_MHZ,GPIO_CNF_OUTPUT_PUSHPULL,GPIO1);

    gpio_set_mode(GPIOA,GPIO_MODE_OUTPUT_50_MHZ,GPIO_CNF_OUTPUT_PUSHPULL,GPIO2);

    gpio_set_mode(GPIOA,GPIO_MODE_OUTPUT_50_MHZ,GPIO_CNF_OUTPUT_PUSHPULL,GPIO3);

    gpio_set_mode(GPIOA,GPIO_MODE_OUTPUT_50_MHZ,GPIO_CNF_OUTPUT_PUSHPULL,GPIO4);

    gpio_set_mode(GPIOA,GPIO_MODE_OUTPUT_50_MHZ,GPIO_CNF_OUTPUT_PUSHPULL,GPIO5);

    gpio_set_mode(GPIOA,GPIO_MODE_OUTPUT_50_MHZ,GPIO_CNF_OUTPUT_PUSHPULL,GPIO6);

    gpio_set_mode(GPIOA,GPIO_MODE_OUTPUT_50_MHZ,GPIO_CNF_OUTPUT_PUSHPULL,GPIO7);

    gpio_clean();

    for (;;)
    {
        spots = usb_getc();

        switch (spots)
        {
        case '0':
            gpio_clean();

            //Displays number 0
            gpio_clear(GPIOA,GPIO1);
            gpio_clear(GPIOA,GPIO2);
            gpio_clear(GPIOA,GPIO3);
            gpio_clear(GPIOA,GPIO4);
            gpio_clear(GPIOA,GPIO5);
            gpio_clear(GPIOA,GPIO6);
            break;
        case '1':
            gpio_clean();

            //Displays number 1
            gpio_clear(GPIOA,GPIO2);
            gpio_clear(GPIOA,GPIO3);
            break;
        case '2':
            gpio_clean();

            //Displays number 2
            gpio_clear(GPIOA,GPIO1);
            gpio_clear(GPIOA,GPIO2);
            gpio_clear(GPIOA,GPIO7);
            gpio_clear(GPIOA,GPIO5);
            gpio_clear(GPIOA,GPIO4);
            break;
        case '3':
            gpio_clean();

            //Displays number 3
            gpio_clear(GPIOA,GPIO1);
            gpio_clear(GPIOA,GPIO2);
            gpio_clear(GPIOA,GPIO7);
            gpio_clear(GPIOA,GPIO3);
            gpio_clear(GPIOA,GPIO4);
            break;
        case '4':
            gpio_clean();

            //Displays number 4
            gpio_clear(GPIOA,GPIO6);
            gpio_clear(GPIOA,GPIO7);
            gpio_clear(GPIOA,GPIO2);
            gpio_clear(GPIOA,GPIO3);
            break;
        case '5':
            gpio_clean();

            //Displays number 5
            gpio_clear(GPIOA,GPIO1);
            gpio_clear(GPIOA,GPIO6);
            gpio_clear(GPIOA,GPIO7);
            gpio_clear(GPIOA,GPIO3);
            gpio_clear(GPIOA,GPIO4);
            break;
        case '6':
            gpio_clean();

            //Displays number 6
            gpio_clear(GPIOA,GPIO1);
            gpio_clear(GPIOA,GPIO6);
            gpio_clear(GPIOA,GPIO7);
            gpio_clear(GPIOA,GPIO3);
            gpio_clear(GPIOA,GPIO4);
            gpio_clear(GPIOA,GPIO5);
            break;
        case '7':
            gpio_clean();

            //Displays number 7
            gpio_clear(GPIOA,GPIO1);
            gpio_clear(GPIOA,GPIO2);
            gpio_clear(GPIOA,GPIO3);
            break;
        case '8':
            gpio_clean();

            //Displays number 8
            gpio_clear(GPIOA,GPIO1);
            gpio_clear(GPIOA,GPIO2);
            gpio_clear(GPIOA,GPIO3);
            gpio_clear(GPIOA,GPIO4);
            gpio_clear(GPIOA,GPIO5);
            gpio_clear(GPIOA,GPIO6);
            gpio_clear(GPIOA,GPIO7);
            break;
        case '9':
            gpio_clean();

            //Displays number 9
            gpio_clear(GPIOA,GPIO1);
            gpio_clear(GPIOA,GPIO2);
            gpio_clear(GPIOA,GPIO3);
            gpio_clear(GPIOA,GPIO4);
            gpio_clear(GPIOA,GPIO6);
            gpio_clear(GPIOA,GPIO7);
            break;
        }
    }
}

int main(void)
{
    rcc_clock_setup_pll(&rcc_hse_configs[RCC_CLOCK_HSE8_72MHZ]);

    usb_start();

    xTaskCreate(display, "display", 100, NULL, configMAX_PRIORITIES-1, NULL);

    vTaskStartScheduler();
    for (;;);
    return 0;
}
