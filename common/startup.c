#include "stm32wbxx.h"

extern uint32_t _stack_end;
extern uint32_t _flash_data_start;
extern uint32_t _sram_data_start;
extern uint32_t _sram_data_end;
extern uint32_t _bss_start;
extern uint32_t _bss_end;

extern int main();

void Reset_Handler()
{
  uint32_t *dst, *src;

  // copy .data section to RAM
  dst = &_sram_data_start;
  src = &_flash_data_start;
  while(dst < &_sram_data_end) *dst++ = *src++;

  // fill .bss section with zeros
  dst = &_bss_start;
  while(dst < &_bss_end) *dst++ = 0;

  // call main
  main();

  while(1);
}

void Default_Handler()
{
  while(1);
}

#define DECLARE_HANDLER(name) \
  extern void name() __attribute__((weak, alias("Default_Handler")));

DECLARE_HANDLER(NMI_Handler)
DECLARE_HANDLER(HardFault_Handler)
DECLARE_HANDLER(MemManage_Handler)
DECLARE_HANDLER(BusFault_Handler)
DECLARE_HANDLER(UsageFault_Handler)
DECLARE_HANDLER(SVC_Handler)
DECLARE_HANDLER(DebugMon_Handler)
DECLARE_HANDLER(PendSV_Handler)
DECLARE_HANDLER(SysTick_Handler)
DECLARE_HANDLER(WWDG_IRQHandler)
DECLARE_HANDLER(PVD_PVM_IRQHandler)
DECLARE_HANDLER(TAMP_STAMP_LSECSS_IRQHandler)
DECLARE_HANDLER(RTC_WKUP_IRQHandler)
DECLARE_HANDLER(FLASH_IRQHandler)
DECLARE_HANDLER(RCC_IRQHandler)
DECLARE_HANDLER(EXTI0_IRQHandler)
DECLARE_HANDLER(EXTI1_IRQHandler)
DECLARE_HANDLER(EXTI2_IRQHandler)
DECLARE_HANDLER(EXTI3_IRQHandler)
DECLARE_HANDLER(EXTI4_IRQHandler)
DECLARE_HANDLER(DMA1_Channel1_IRQHandler)
DECLARE_HANDLER(DMA1_Channel2_IRQHandler)
DECLARE_HANDLER(DMA1_Channel3_IRQHandler)
DECLARE_HANDLER(DMA1_Channel4_IRQHandler)
DECLARE_HANDLER(DMA1_Channel5_IRQHandler)
DECLARE_HANDLER(DMA1_Channel6_IRQHandler)
DECLARE_HANDLER(DMA1_Channel7_IRQHandler)
DECLARE_HANDLER(ADC1_IRQHandler)
DECLARE_HANDLER(USB_HP_IRQHandler)
DECLARE_HANDLER(USB_LP_IRQHandler)
DECLARE_HANDLER(C2SEV_PWR_C2H_IRQHandler)
DECLARE_HANDLER(COMP_IRQHandler)
DECLARE_HANDLER(EXTI9_5_IRQHandler)
DECLARE_HANDLER(TIM1_BRK_IRQHandler)
DECLARE_HANDLER(TIM1_UP_TIM16_IRQHandler)
DECLARE_HANDLER(TIM1_TRG_COM_TIM17_IRQHandler)
DECLARE_HANDLER(TIM1_CC_IRQHandler)
DECLARE_HANDLER(TIM2_IRQHandler)
DECLARE_HANDLER(PKA_IRQHandler)
DECLARE_HANDLER(I2C1_EV_IRQHandler)
DECLARE_HANDLER(I2C1_ER_IRQHandler)
DECLARE_HANDLER(I2C3_EV_IRQHandler)
DECLARE_HANDLER(I2C3_ER_IRQHandler)
DECLARE_HANDLER(SPI1_IRQHandler)
DECLARE_HANDLER(SPI2_IRQHandler)
DECLARE_HANDLER(USART1_IRQHandler)
DECLARE_HANDLER(LPUART1_IRQHandler)
DECLARE_HANDLER(SAI1_IRQHandler)
DECLARE_HANDLER(TSC_IRQHandler)
DECLARE_HANDLER(EXTI15_10_IRQHandler)
DECLARE_HANDLER(RTC_Alarm_IRQHandler)
DECLARE_HANDLER(CRS_IRQHandler)
DECLARE_HANDLER(PWR_SOTF_BLEACT_802ACT_RFPHASE_IRQHandler)
DECLARE_HANDLER(IPCC_C1_RX_IRQHandler)
DECLARE_HANDLER(IPCC_C1_TX_IRQHandler)
DECLARE_HANDLER(HSEM_IRQHandler)
DECLARE_HANDLER(LPTIM1_IRQHandler)
DECLARE_HANDLER(LPTIM2_IRQHandler)
DECLARE_HANDLER(LCD_IRQHandler)
DECLARE_HANDLER(QUADSPI_IRQHandler)
DECLARE_HANDLER(AES1_IRQHandler)
DECLARE_HANDLER(AES2_IRQHandler)
DECLARE_HANDLER(RNG_IRQHandler)
DECLARE_HANDLER(FPU_IRQHandler)
DECLARE_HANDLER(DMA2_Channel1_IRQHandler)
DECLARE_HANDLER(DMA2_Channel2_IRQHandler)
DECLARE_HANDLER(DMA2_Channel3_IRQHandler)
DECLARE_HANDLER(DMA2_Channel4_IRQHandler)
DECLARE_HANDLER(DMA2_Channel5_IRQHandler)
DECLARE_HANDLER(DMA2_Channel6_IRQHandler)
DECLARE_HANDLER(DMA2_Channel7_IRQHandler)
DECLARE_HANDLER(DMAMUX1_OVR_IRQHandler)

const void *vector_table[] __attribute__((section(".vector_table"), used)) =
{
  &_stack_end,
  &Reset_Handler,
  &NMI_Handler,
  &HardFault_Handler,
  &MemManage_Handler,
  &BusFault_Handler,
  &UsageFault_Handler,
  0,
  0,
  0,
  0,
  &SVC_Handler,
  &DebugMon_Handler,
  0,
  &PendSV_Handler,
  &SysTick_Handler,
  &WWDG_IRQHandler,
  &PVD_PVM_IRQHandler,
  &TAMP_STAMP_LSECSS_IRQHandler,
  &RTC_WKUP_IRQHandler,
  &FLASH_IRQHandler,
  &RCC_IRQHandler,
  &EXTI0_IRQHandler,
  &EXTI1_IRQHandler,
  &EXTI2_IRQHandler,
  &EXTI3_IRQHandler,
  &EXTI4_IRQHandler,
  &DMA1_Channel1_IRQHandler,
  &DMA1_Channel2_IRQHandler,
  &DMA1_Channel3_IRQHandler,
  &DMA1_Channel4_IRQHandler,
  &DMA1_Channel5_IRQHandler,
  &DMA1_Channel6_IRQHandler,
  &DMA1_Channel7_IRQHandler,
  &ADC1_IRQHandler,
  &USB_HP_IRQHandler,
  &USB_LP_IRQHandler,
  &C2SEV_PWR_C2H_IRQHandler,
  &COMP_IRQHandler,
  &EXTI9_5_IRQHandler,
  &TIM1_BRK_IRQHandler,
  &TIM1_UP_TIM16_IRQHandler,
  &TIM1_TRG_COM_TIM17_IRQHandler,
  &TIM1_CC_IRQHandler,
  &TIM2_IRQHandler,
  &PKA_IRQHandler,
  &I2C1_EV_IRQHandler,
  &I2C1_ER_IRQHandler,
  &I2C3_EV_IRQHandler,
  &I2C3_ER_IRQHandler,
  &SPI1_IRQHandler,
  &SPI2_IRQHandler,
  &USART1_IRQHandler,
  &LPUART1_IRQHandler,
  &SAI1_IRQHandler,
  &TSC_IRQHandler,
  &EXTI15_10_IRQHandler,
  &RTC_Alarm_IRQHandler,
  &CRS_IRQHandler,
  &PWR_SOTF_BLEACT_802ACT_RFPHASE_IRQHandler,
  &IPCC_C1_RX_IRQHandler,
  &IPCC_C1_TX_IRQHandler,
  &HSEM_IRQHandler,
  &LPTIM1_IRQHandler,
  &LPTIM2_IRQHandler,
  &LCD_IRQHandler,
  &QUADSPI_IRQHandler,
  &AES1_IRQHandler,
  &AES2_IRQHandler,
  &RNG_IRQHandler,
  &FPU_IRQHandler,
  &DMA2_Channel1_IRQHandler,
  &DMA2_Channel2_IRQHandler,
  &DMA2_Channel3_IRQHandler,
  &DMA2_Channel4_IRQHandler,
  &DMA2_Channel5_IRQHandler,
  &DMA2_Channel6_IRQHandler,
  &DMA2_Channel7_IRQHandler,
  &DMAMUX1_OVR_IRQHandler
};
