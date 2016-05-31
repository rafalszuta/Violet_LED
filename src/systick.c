
#include "board.h"
#include <stdio.h>

/*****************************************************************************
 * Private types/enumerations/variables
 ****************************************************************************/
/* SysTick rate in Hz */
#define TICKRATE_HZ (400)

 /* LED NUMBERS */
#define RED_LED 0
#define BLUE_LED 2

 /* TIME LIGHTING LED */
#define BLUE_DELAY 1200
#define RED_DELAY 10000
/*****************************************************************************
 * Public types/enumerations/variables
 ****************************************************************************/

/*****************************************************************************
 * Private functions
 ****************************************************************************/

/*****************************************************************************
 * Public functions
 ****************************************************************************/

/**
 * @brief	Handle interrupt from SysTick timer
 * @return	Nothing
 */
void SysTick_Handler(void)
{
	static int ticks = 0;

	ticks++;
	if (ticks > TICKRATE_HZ) {
		ticks = 0;
	}
}

/**
 * @brief		Function delay
 * @param[in]	delay - delay time
 */
static void delay(uint32_t delay) {
	while (delay--) {
	}
}


/**
 * @brief	main routine for blinky example
 * @return	Function should not exit.
 */
int main(void)
{
	SystemCoreClockUpdate();
	Board_Init();

	/* Enable SysTick Timer */
	SysTick_Config(SystemCoreClock / TICKRATE_HZ);

	/* Loop forever */
	while (1) {

		Board_LED_Set(RED_LED, true);
		Board_LED_Set(BLUE_LED, false);
		delay(RED_DELAY);

		Board_LED_Set(RED_LED, false);
		Board_LED_Set(BLUE_LED, true);
		delay(BLUE_DELAY);

		Board_LED_Set(RED_LED, false);
		Board_LED_Set(BLUE_LED, false);

		__WFI();
	}
}
