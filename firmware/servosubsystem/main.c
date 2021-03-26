/*
 * Warren Gay   Sat Dec 30 11:59:39 2017
 * Modified by: Amit Sharma 
 */

#include <string.h>

#include "FreeRTOS.h"
#include "task.h"

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/timer.h>
#include <libopencm3/cm3/nvic.h>

#include "usbcdc.h"

static void gate(void *args __attribute__((unused))) {

	char state;

	rcc_periph_clock_enable(RCC_TIM2); // Need TIM2 clock
	rcc_periph_clock_enable(RCC_AFIO); // Need AFIO clock

	// PA1 == TIM2.CH2	
	rcc_periph_clock_enable(RCC_GPIOA); // Need GPIOA clock	
	rcc_periph_clock_enable(RCC_GPIOC);
	
	gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_50_MHZ, GPIO_CNF_OUTPUT_ALTFN_PUSHPULL, GPIO1); // High speed, GPIOA1 = TIM2.CH2
	gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_2_MHZ, GPIO_CNF_OUTPUT_PUSHPULL, GPIO13);

	// TIM2:
	timer_disable_counter(TIM2);
	rcc_periph_reset_pulse(RST_TIM2);

	timer_set_mode(TIM2, TIM_CR1_CKD_CK_INT, TIM_CR1_CMS_EDGE, TIM_CR1_DIR_UP);
	timer_set_prescaler(TIM2, 72-1); // See https://github.com/ve3wwg/stm32f103c8t6/pull/12/

	timer_enable_preload(TIM2);
	timer_continuous_mode(TIM2);
	timer_set_period(TIM2, 33333-1);

	timer_disable_oc_output(TIM2, TIM_OC2);
	timer_set_oc_mode(TIM2, TIM_OC2, TIM_OCM_PWM1);
	timer_enable_oc_output(TIM2, TIM_OC2);

	timer_set_oc_value(TIM2, TIM_OC2, 1725);
	gpio_set(GPIOC, GPIO13);

	timer_enable_counter(TIM2);

	for (;;)
	{
		state = usb_getc();
		
		if (state == 'o') // Open
		{
			timer_set_oc_value(TIM2, TIM_OC2, 850);
			gpio_clear(GPIOC, GPIO13);
		}


		if (state == 'c') // Close
		{
			timer_set_oc_value(TIM2, TIM_OC2, 1725);
			gpio_set(GPIOC, GPIO13);
		}
	}
}

int main(void) {

	rcc_clock_setup_pll(&rcc_hse_configs[RCC_CLOCK_HSE8_72MHZ]);

	usb_start();

	xTaskCreate(gate, "gate", 100, NULL, configMAX_PRIORITIES-1, NULL);
	vTaskStartScheduler();
	
	for (;;);
	return 0;
}
