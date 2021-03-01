#include <stm32f4xx.h>
#include <system_clock_config.h>
#include <gpio.h>
#include <main.h>


// Init function required by __libc_init_array
void _init(void) {}

int main(void)
{
    SystemClock_Config();
    init_LED1357(LED7);
    timer7_start();

    // Enable GPIOD peripheral clock


//    init_body_led(BODY_LED);

//    while (1) {
//    	int mode = returnSelector();
//    	if(mode){
//    		gpio_set(LED1);
//    		attente();
//    		gpio_set(LED3);
//    		attente();
//    		gpio_set(LED5);
//    		attente();
//    		gpio_set(LED7);
//    		attente();
//    		gpio_clear(LED1);
//    		attente();
//    		gpio_clear(LED1);
//    		attente();
//    		gpio_clear(LED1);
//    		attente();
//    		gpio_clear(LED1);
//    		attente();
//    	}
//    	else {
//    		gpio_set(LED1);
//    		attente();
//    		gpio_clear(LED1);
//    		attente();
//    		gpio_set(LED3);
//    		attente();
//    		gpio_clear(LED3);
//    		attente();
//    		gpio_set(LED5);
//    		attente();
//    		gpio_clear(LED5);
//    		attente();
//    		gpio_set(LED7);
//    		attente();
//    		gpio_clear(LED7);
//    		attente();
//    	}




//    	attente();
////    	allumer_LED(LED1);
//		//GPIOB->ODR &= ~(0 << 2);
//    	allumer_LED(BODY_LED);
////        ;
////    }
//    }
}

void attente(){
	int i=0;
	while(i<=1000000){
		i++;
	}
}

void init_LED1357(GPIO_TypeDef* LED_on, unsigned int pin){
	// Enable GPIOD peripheral clock
	RCC->AHB1ENR    |= RCC_AHB1ENR_GPIODEN;
    // LED used init
    gpio_config_output_opendrain(LED_on, pin);
}

void init_body_led(GPIO_TypeDef* LED_on, unsigned int pin){
	RCC->AHB1ENR    |= RCC_AHB1ENR_GPIOBEN;
	gpio_set(LED_on,pin);
	gpio_config_output_pushpull(LED_on,pin);
}

void allumer_LED(GPIO_TypeDef* LED_on,unsigned int pin){
	gpio_toggle(LED_on, pin);
}
