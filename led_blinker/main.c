#include "stm32wbxx.h"

int main()
{
  // enable GPIOB
  RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN_Msk;

  // configure PB0 as output
  GPIOB->MODER &= ~GPIO_MODER_MODE0_1;

  // enable LSI
  RCC->CSR |= RCC_CSR_LSI1ON_Msk;

  // set LPTIM1 clock source to LSI
  RCC->CCIPR |= RCC_CCIPR_LPTIM1SEL_0;

  // enable clock for LPTIM1
  RCC->APB1ENR1 |= RCC_APB1ENR1_LPTIM1EN_Msk;

  // enable ARRM interrupt
  LPTIM1->IER |= LPTIM_IER_ARRMIE_Msk;

  // enable LPTIM1
  LPTIM1->CR |= LPTIM_CR_ENABLE_Msk;

  // enable Stop 1 mode
  PWR->CR1 |= PWR_CR1_LPMS_0;
  SCB->SCR |= SCB_SCR_SEVONPEND_Msk | SCB_SCR_SLEEPDEEP_Msk;

  // set LPTIM1 autoreload register
  LPTIM1->ARR = 16000;

  // start LPTIM1 counter
  LPTIM1->CR |= LPTIM_CR_CNTSTRT_Msk;

  while(1)
  {
    __WFE();
    if(LPTIM1->ISR & LPTIM_ISR_ARRM_Msk)
    {
      LPTIM1->ICR |= LPTIM_ICR_ARRMCF_Msk;
      // toggle PB0
      GPIOB->ODR ^= GPIO_ODR_OD0_Msk;
      // clear interrupt pending bit
      NVIC_ClearPendingIRQ(LPTIM1_IRQn);
    }
  }
}
