/**
  ******************************************************************************
  * @file    stm8l15x_exti.c
  * @author  MCD Application Team
  * @version V1.3.0
  * @date    07/14/2010
  * @brief   This file provides all the EXTI firmware functions.
  ******************************************************************************
  * @copy
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2010 STMicroelectronics</center></h2>
  */

/* Includes ------------------------------------------------------------------*/
#include "stm8l15x_exti.h"

/** @addtogroup STM8L15x_StdPeriph_Driver
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/


/**
  * @addtogroup EXTI_Public_Functions
  * @{
  */

/**
  * @brief  Deinitializes the EXTI registers to their default reset value.
  * @param  None
  * @retval None
  */
void EXTI_DeInit(void)
{
  EXTI->CR1 = EXTI_CR1_RESET_VALUE;
  EXTI->CR2 = EXTI_CR2_RESET_VALUE;
  EXTI->CR3 = EXTI_CR3_RESET_VALUE;
  EXTI->SR1 = (uint8_t)0xFF;
  EXTI->SR2 = (uint8_t)0xFF;
  EXTI->CONF1 = EXTI_CONF1_RESET_VALUE;
}

/**
  * @brief  Sets the external interrupt sensitivity of the selected port.
  * @note
  *   - The modification of external interrupt sensitivity is only possible when
  *     the interrupts are disabled.
  *   - The normal behavior is to disable the interrupts before calling this
  *     function, and re-enable them after.
  * @param  EXTI_Port : The port number to access.
  *   This parameter can be a value of @ref EXTI_Port_TypeDef
  * @param  EXTI_Trigger : The external interrupt sensitivity value to set.
  *   This parameter can be a value of @ref EXTI_Trigger_TypeDef
  * @retval None
  * @par    Required preconditions:
  *   - Global interrupts must be disabled before calling this function.
  */
void EXTI_SetPortSensitivity(EXTI_Port_TypeDef EXTI_Port, EXTI_Trigger_TypeDef EXTI_Trigger)
{

  /* Check function parameters */
  assert_param(IS_EXTI_PORT(EXTI_Port));
  assert_param(IS_EXTI_TRIGGER(EXTI_Trigger));

  /* Clear EXTI  port sensitivity */
  if (EXTI_Port == EXTI_Port_B)
  {
    EXTI->CR3 &= (uint8_t)(~EXTI_CR3_PBIS);
  }
  else if (EXTI_Port == EXTI_Port_D)
  {
    EXTI->CR3 &= (uint8_t)(~EXTI_CR3_PDIS);
  }
  else  if (EXTI_Port == EXTI_Port_E)
  {
    EXTI->CR3 &= (uint8_t)(~EXTI_CR3_PEIS);
  }
  else /* EXTI_Port == EXTI_Port_PF */
  {
    EXTI->CR3 &= (uint8_t)(~EXTI_CR3_PFIS);
  }

  /* Write EXTI  port sensitivity */
  EXTI->CR3 |= (uint8_t)((uint8_t)(EXTI_Trigger) << EXTI_Port);

}

/**
  * @brief  Sets the external interrupt sensitivity of the selected pin.
  * @note
  *   - The modification of external interrupt sensitivity is only possible when
  *     the interrupts are disabled.
  *   - The normal behavior is to disable the interrupts before calling this
  *     function, and re-enable them after.
  * @param  EXTI_Pin : The pin to configure.
  *   This parameter can be a value of @ref EXTI_Pin_TypeDef
  * @param  EXTI_Trigger : The external interrupt sensitivity value to set.
  *   This parameter can be a value of @ref EXTI_Trigger_TypeDef
  * @retval None
  * @par    Required preconditions:
  *   - Global interrupts must be disabled before calling this function.
  */
void EXTI_SetPinSensitivity(EXTI_Pin_TypeDef EXTI_Pin,
                            EXTI_Trigger_TypeDef EXTI_Trigger)
{

  /* Check function parameters */
  assert_param(IS_EXTI_PINNUM(EXTI_Pin));
  assert_param(IS_EXTI_TRIGGER(EXTI_Trigger));

  /* Clear port sensitivity bits */
  switch (EXTI_Pin)
  {
    case EXTI_Pin_0:
      EXTI->CR1 &=  (uint8_t)(~EXTI_CR1_P0IS);
      EXTI->CR1 |= (uint8_t)((uint8_t)(EXTI_Trigger) << EXTI_Pin);
      break;
    case EXTI_Pin_1:
      EXTI->CR1 &=  (uint8_t)(~EXTI_CR1_P1IS);
      EXTI->CR1 |= (uint8_t)((uint8_t)(EXTI_Trigger) << EXTI_Pin);
      break;
    case EXTI_Pin_2:
      EXTI->CR1 &=  (uint8_t)(~EXTI_CR1_P2IS);
      EXTI->CR1 |= (uint8_t)((uint8_t)(EXTI_Trigger) << EXTI_Pin);
      break;
    case EXTI_Pin_3:
      EXTI->CR1 &=  (uint8_t)(~EXTI_CR1_P3IS);
      EXTI->CR1 |= (uint8_t)((uint8_t)(EXTI_Trigger) << EXTI_Pin);
      break;
    case EXTI_Pin_4:
      EXTI->CR2 &=  (uint8_t)(~EXTI_CR2_P4IS);
      EXTI->CR2 |= (uint8_t)((uint8_t)(EXTI_Trigger) << ((uint8_t)EXTI_Pin & (uint8_t)0xEF));
      break;
    case EXTI_Pin_5:
      EXTI->CR2 &=  (uint8_t)(~EXTI_CR2_P5IS);
      EXTI->CR2 |= (uint8_t)((uint8_t)(EXTI_Trigger) << ((uint8_t)EXTI_Pin & (uint8_t)0xEF));
      break;
    case EXTI_Pin_6:
      EXTI->CR2 &=  (uint8_t)(~EXTI_CR2_P6IS);
      EXTI->CR2 |= (uint8_t)((uint8_t)(EXTI_Trigger) << ((uint8_t)EXTI_Pin & (uint8_t)0xEF));
      break;
    case EXTI_Pin_7:
      EXTI->CR2 &=  (uint8_t)(~EXTI_CR2_P7IS);
      EXTI->CR2 |= (uint8_t)((uint8_t)(EXTI_Trigger) << ((uint8_t)EXTI_Pin & (uint8_t)0xEF));
      break;
    default:
      break;
  }
}

/**
  * @brief  Configures the half port interrupt selection.
  * @param   EXTI_HalfPort : The port part to access (MSB or LSB).
  *   This parameter can be a value of @ref EXTI_HalfPort_TypeDef
  * @param NewState : The external interrupt new state.
  *   This parameter can be a value of @ref FunctionalState.
  * @retval None
  * @par    Required preconditions:
  *   - This function should be called once the port sensitivity configured,
  *     otherwise it will not have any effect on the port external interrupt.
  */
void EXTI_SetHalfPortSelection(EXTI_HalfPort_TypeDef EXTI_HalfPort,
                               FunctionalState NewState)
{
  /* Check function parameters */
  assert_param(IS_EXTI_HALFPORT(EXTI_HalfPort));
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  /* Reset PEFS bit */
  EXTI->CONF1 &= (uint8_t)(~(uint8_t)EXTI_CONF1_PFES);

  if (NewState != DISABLE)
  {
    EXTI->CONF1 |= (uint8_t)EXTI_HalfPort; /* Enable port interrupt selector */
  }
  else /*NewState == DISABLE */
  {
    EXTI->CONF1 &= (uint8_t)(~(uint8_t)EXTI_HalfPort); /* Disable port interrupt selector */
  }
}

/**
  * @brief  Gets the external interrupt sensitivity of the selected port.
  * @param  EXTI_Port : The port number to access.
  *   This parameter can be a value of @ref EXTI_Port_TypeDef
  * @retval EXTI_Trigger_TypeDef : The external interrupt sensitivity of the selected port.
  */
EXTI_Trigger_TypeDef EXTI_GetPortSensitivity(EXTI_Port_TypeDef EXTI_Port)
{
  uint8_t value = 0;
  uint8_t cr3mask = 0;
  /* Check function parameters */
  assert_param(IS_EXTI_PORT(EXTI_Port));

  if (EXTI_Port == EXTI_Port_B)
  {
    cr3mask = EXTI_CR3_PBIS;
  }
  else if (EXTI_Port == EXTI_Port_D)
  {
    cr3mask = EXTI_CR3_PDIS;
  }
  else if (EXTI_Port == EXTI_Port_E)
  {
    cr3mask = EXTI_CR3_PEIS;
  }
  else
  {
    cr3mask = EXTI_CR3_PFIS;
  }

  value = (uint8_t)((uint8_t)(EXTI->CR3 & cr3mask) >> EXTI_Port);
  return((EXTI_Trigger_TypeDef)value);
}

/**
  * @brief  Gets the external interrupt sensitivity of the selected pin.
  * @param  EXTI_Pin : The pin number to access.
  *   This parameter can be a value of @ref EXTI_Pin_TypeDef
  * @retval EXTI_Trigger_TypeDef : The external interrupt sensitivity of the selected port.
  */
EXTI_Trigger_TypeDef EXTI_GetPinSensitivity(EXTI_Pin_TypeDef EXTI_Pin)
{
  uint8_t value = 0;

  /* Check function parameters */
  assert_param(IS_EXTI_PINNUM(EXTI_Pin));

  switch (EXTI_Pin)
  {
    case EXTI_Pin_0:
      value = (uint8_t)(EXTI->CR1 & EXTI_CR1_P0IS);
      break;
    case EXTI_Pin_1:
      value = (uint8_t)((uint8_t)(EXTI->CR1 & EXTI_CR1_P1IS) >> EXTI_Pin_1);
      break;
    case EXTI_Pin_2:
      value = (uint8_t)((uint8_t)(EXTI->CR1 & EXTI_CR1_P2IS) >> EXTI_Pin_2);
      break;
    case EXTI_Pin_3:
      value = (uint8_t)((uint8_t)(EXTI->CR1 & EXTI_CR1_P3IS) >> EXTI_Pin_3);
      break;
    case EXTI_Pin_4:
      value = (uint8_t)(EXTI->CR2 & EXTI_CR2_P4IS);
      break;
    case EXTI_Pin_5:
      value = (uint8_t)((uint8_t)(EXTI->CR2 & EXTI_CR2_P5IS) >> ((uint8_t)EXTI_Pin_5 & (uint8_t)0x0F));
      break;
    case EXTI_Pin_6:
      value = (uint8_t)((uint8_t)(EXTI->CR2 & EXTI_CR2_P6IS) >> ((uint8_t)EXTI_Pin_6 & (uint8_t)0x0F));
      break;
    case EXTI_Pin_7:
      value = (uint8_t)((uint8_t)(EXTI->CR2 & EXTI_CR2_P7IS) >> ((uint8_t)EXTI_Pin_7 & (uint8_t)0x0F));
      break;
    default:
      break;
  }
  return((EXTI_Trigger_TypeDef)value);
}

/**
  * @brief  Gets the external interrupt half port configuration.
  * @param  EXTI_HalfPort : The half port part to get (MSB or LSB).
  *   This parameter can be a value of @ref EXTI_HalfPort_TypeDef
  * @retval FunctionalState : The external interrupt state of the selected port part.
  *   This parameter can be a value of @ref FunctionalState.
  */
FunctionalState EXTI_GetHalfPortSelection(EXTI_HalfPort_TypeDef EXTI_HalfPort)
{
  FunctionalState value = DISABLE;
  /* Check function parameters */
  assert_param(IS_EXTI_HALFPORT(EXTI_HalfPort));
  if ((EXTI->CONF1 & (uint8_t)EXTI_HalfPort) != DISABLE)
  {
    value = ENABLE;
  }
  else
  {
    value = DISABLE;
  }

  return(value);
}

/**
  * @brief  Gets the external interrupt status.
  * @param  EXTI_IT : Specifies the interrupt to read.
  *   This parameter can be a value of @ref EXTI_IT_TypeDef
  * @retval ITStatus : The status of the specified interrupt.
  *   This parameter can be a value of @ref ITStatus.
  */
ITStatus EXTI_GetITStatus(EXTI_IT_TypeDef EXTI_IT)
{
  ITStatus status = RESET;
  /* Check function parameters */
  assert_param(IS_EXTI_ITPENDINGBIT(EXTI_IT));

  if (((uint8_t)EXTI_IT & (uint8_t)0xF0) == 0xF0)
  {
    status = (ITStatus)(EXTI->SR2 & (uint8_t)((uint8_t)EXTI_IT & (uint8_t)0x0F));
  }
  else
  {
    status = (ITStatus)(EXTI->SR1 & (uint8_t)EXTI_IT);
  }
  return((ITStatus)status);
}

/**
  * @brief  Clears the specified interrupt pending bit
  * @param  EXTI_IT : Specifies the interrupt to clear
  *   This parameter can be a value of @ref EXTI_IT_TypeDef
  * @retval None
  */
void EXTI_ClearITPendingBit(EXTI_IT_TypeDef EXTI_IT)
{
  /* Check function parameters */
  assert_param(IS_EXTI_ITPENDINGBIT(EXTI_IT));

  if (((uint8_t)EXTI_IT & (uint8_t)0xF0) == 0xF0)
  {
    EXTI->SR2 = (uint8_t)((uint8_t)EXTI_IT & (uint8_t)0x0F);
  }
  else
  {
    EXTI->SR1 = (uint8_t)EXTI_IT;
  }
}
/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2010 STMicroelectronics *****END OF FILE****/
