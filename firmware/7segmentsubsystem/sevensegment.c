//Name: Rajkumar Patel

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

static void gpio_setup(void)
{
    /* Enable GPIOC clock. */
    rcc_periph_clock_enable(RCC_GPIOA);

    gpio_set_mode(GPIOA,GPIO_MODE_OUTPUT_50_MHZ,
                  GPIO_CNF_OUTPUT_PUSHPULL,GPIO1);

    gpio_set_mode(GPIOA,GPIO_MODE_OUTPUT_50_MHZ,
                  GPIO_CNF_OUTPUT_PUSHPULL,GPIO2);

    gpio_set_mode(GPIOA,GPIO_MODE_OUTPUT_50_MHZ,
                  GPIO_CNF_OUTPUT_PUSHPULL,GPIO3);

    gpio_set_mode(GPIOA,GPIO_MODE_OUTPUT_50_MHZ,
                  GPIO_CNF_OUTPUT_PUSHPULL,GPIO4);

    gpio_set_mode(GPIOA,GPIO_MODE_OUTPUT_50_MHZ,
                  GPIO_CNF_OUTPUT_PUSHPULL,GPIO5);

    gpio_set_mode(GPIOA,GPIO_MODE_OUTPUT_50_MHZ,
                  GPIO_CNF_OUTPUT_PUSHPULL,GPIO6);

    gpio_set_mode(GPIOA,GPIO_MODE_OUTPUT_50_MHZ,
                  GPIO_CNF_OUTPUT_PUSHPULL,GPIO7);
}

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

static void number_zero(void)
{
    int i;

    //Displays number 0
    gpio_clear(GPIOA,GPIO1);
    gpio_clear(GPIOA,GPIO2);
    gpio_clear(GPIOA,GPIO3);
    gpio_clear(GPIOA,GPIO4);
    gpio_clear(GPIOA,GPIO5);
    gpio_clear(GPIOA,GPIO6);
    for (i = 0; i < 7500000; i++)
        __asm__("nop");

    gpio_set(GPIOA,GPIO1);
    gpio_set(GPIOA,GPIO2);
    gpio_set(GPIOA,GPIO3);
    gpio_set(GPIOA,GPIO4);
    gpio_set(GPIOA,GPIO5);
    gpio_set(GPIOA,GPIO6);
    for (i = 0; i < 500000; i++)
        __asm__("nop");

    gpio_clean();
}

static void number_one(void)
{
    int i;

    //Displays number 1
    gpio_clear(GPIOA,GPIO2);
    gpio_clear(GPIOA,GPIO3);
    for (i = 0; i < 7500000; i++)
        __asm__("nop");

    gpio_set(GPIOA,GPIO2);
    gpio_set(GPIOA,GPIO3);
    for (i = 0; i < 500000; i++)
        __asm__("nop");

    gpio_clean();
}

static void number_two(void)
{
    int i;

    //Displays number 2
    gpio_clear(GPIOA,GPIO1);
    gpio_clear(GPIOA,GPIO2);
    gpio_clear(GPIOA,GPIO7);
    gpio_clear(GPIOA,GPIO5);
    gpio_clear(GPIOA,GPIO4);
    for (i = 0; i < 7500000; i++)
        __asm__("nop");

    gpio_set(GPIOA,GPIO1);
    gpio_set(GPIOA,GPIO2);
    gpio_set(GPIOA,GPIO7);
    gpio_set(GPIOA,GPIO5);
    gpio_set(GPIOA,GPIO4);
    for (i = 0; i < 500000; i++)
        __asm__("nop");

    gpio_clean();
}

static void number_three(void)
{
    int i;

    //Displays number 3
    gpio_clear(GPIOA,GPIO1);
    gpio_clear(GPIOA,GPIO2);
    gpio_clear(GPIOA,GPIO7);
    gpio_clear(GPIOA,GPIO3);
    gpio_clear(GPIOA,GPIO4);
    for (i = 0; i < 7500000; i++)
        __asm__("nop");

    gpio_set(GPIOA,GPIO1);
    gpio_set(GPIOA,GPIO2);
    gpio_set(GPIOA,GPIO7);
    gpio_set(GPIOA,GPIO3);
    gpio_set(GPIOA,GPIO4);
    for (i = 0; i < 500000; i++)
        __asm__("nop");

    gpio_clean();
}

static void number_four(void)
{
    int i;

    //Displays number 4
    gpio_clear(GPIOA,GPIO6);
    gpio_clear(GPIOA,GPIO7);
    gpio_clear(GPIOA,GPIO2);
    gpio_clear(GPIOA,GPIO3);
    for (i = 0; i < 7500000; i++)
        __asm__("nop");

    gpio_set(GPIOA,GPIO6);
    gpio_set(GPIOA,GPIO7);
    gpio_set(GPIOA,GPIO2);
    gpio_set(GPIOA,GPIO3);
    for (i = 0; i < 500000; i++)
        __asm__("nop");

    gpio_clean();
}

static void number_five(void)
{
    int i;

    //Displays number 5
    gpio_clear(GPIOA,GPIO1);
    gpio_clear(GPIOA,GPIO6);
    gpio_clear(GPIOA,GPIO7);
    gpio_clear(GPIOA,GPIO3);
    gpio_clear(GPIOA,GPIO4);
    for (i = 0; i < 7500000; i++)
        __asm__("nop");

    gpio_set(GPIOA,GPIO1);
    gpio_set(GPIOA,GPIO6);
    gpio_set(GPIOA,GPIO7);
    gpio_set(GPIOA,GPIO3);
    gpio_set(GPIOA,GPIO4);
    for (i = 0; i < 500000; i++)
        __asm__("nop");

    gpio_clean();
}

static void number_six(void)
{
    int i;

    //Displays number 6
    gpio_clear(GPIOA,GPIO1);
    gpio_clear(GPIOA,GPIO6);
    gpio_clear(GPIOA,GPIO7);
    gpio_clear(GPIOA,GPIO3);
    gpio_clear(GPIOA,GPIO4);
    gpio_clear(GPIOA,GPIO5);
    for (i = 0; i < 7500000; i++)
        __asm__("nop");

    gpio_set(GPIOA,GPIO1);
    gpio_set(GPIOA,GPIO6);
    gpio_set(GPIOA,GPIO7);
    gpio_set(GPIOA,GPIO3);
    gpio_set(GPIOA,GPIO4);
    gpio_set(GPIOA,GPIO5);
    for (i = 0; i < 500000; i++)
        __asm__("nop");

    gpio_clean();
}

static void number_seven(void)
{
    int i;

    //Displays number 7
    gpio_clear(GPIOA,GPIO1);
    gpio_clear(GPIOA,GPIO2);
    gpio_clear(GPIOA,GPIO3);
    for (i = 0; i < 7500000; i++)
        __asm__("nop");

    gpio_set(GPIOA,GPIO1);
    gpio_set(GPIOA,GPIO2);
    gpio_set(GPIOA,GPIO3);
    for (i = 0; i < 500000; i++)
        __asm__("nop");

    gpio_clean();
}

static void number_eight(void)
{
    int i;

    //Displays number 8
    gpio_clear(GPIOA,GPIO1);
    gpio_clear(GPIOA,GPIO2);
    gpio_clear(GPIOA,GPIO3);
    gpio_clear(GPIOA,GPIO4);
    gpio_clear(GPIOA,GPIO5);
    gpio_clear(GPIOA,GPIO6);
    gpio_clear(GPIOA,GPIO7);
    for (i = 0; i < 7500000; i++)
        __asm__("nop");

    gpio_set(GPIOA,GPIO1);
    gpio_set(GPIOA,GPIO2);
    gpio_set(GPIOA,GPIO3);
    gpio_set(GPIOA,GPIO4);
    gpio_set(GPIOA,GPIO5);
    gpio_set(GPIOA,GPIO6);
    gpio_set(GPIOA,GPIO7);
    for (i = 0; i < 500000; i++)
        __asm__("nop");

    gpio_clean();
}

static void number_nine(void)
{
    int i;

    //Displays number 9
    gpio_clear(GPIOA,GPIO1);
    gpio_clear(GPIOA,GPIO2);
    gpio_clear(GPIOA,GPIO3);
    gpio_clear(GPIOA,GPIO4);
    gpio_clear(GPIOA,GPIO6);
    gpio_clear(GPIOA,GPIO7);
    for (i = 0; i < 7500000; i++)
        __asm__("nop");

    gpio_set(GPIOA,GPIO1);
    gpio_set(GPIOA,GPIO2);
    gpio_set(GPIOA,GPIO3);
    gpio_set(GPIOA,GPIO4);
    gpio_set(GPIOA,GPIO6);
    gpio_set(GPIOA,GPIO7);
    for (i = 0; i < 500000; i++)
        __asm__("nop");

    gpio_clean();
}

int main(void)
{
    gpio_setup();

    for (;;)
    {
        //Makes all segments off
        gpio_clean();

        //Displays number 0
        number_zero();

        //Displays number 1
        number_one();

        //Displays number 2
        number_two();

        //Displays number 3
        number_three();

        //Displays number 4
        number_four();

        //Displays number 5
        number_five();

        //Displays number 6
        number_six();

        //Displays number 7
        number_seven();

        //Displays number 8
        number_eight();

        //Displays number 9
        number_nine();
    }
    return 0;
}
