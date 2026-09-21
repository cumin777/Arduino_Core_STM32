/**
  ******************************************************************************
  * @file    usbd_if.h
  * @author  fpistm
  * @brief   Header file for the usbd_if.c file
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USBD_IF_H
#define __USBD_IF_H

#ifdef USBCON
/* Includes ------------------------------------------------------------------*/
#include "Arduino.h"
#include "usbd_core.h"

/* Re-enumeration handling*/
#ifndef USBD_ENUM_DELAY
  #define USBD_ENUM_DELAY 10
#endif

/*
 * NAK an OUT endpoint so the host retries, until USBD_LL_PrepareReceive()
 * re-arms it. Used by the CDC class for RX queue-full backpressure: PMA based
 * IPs keep the endpoint VALID after a received packet, so not re-arming it
 * still ACKs incoming data into a stale buffer pointer.
 */
USBD_StatusTypeDef USBD_LL_SuspendReceive(USBD_HandleTypeDef *pdev,
                                          uint8_t ep_addr);

#ifdef __cplusplus
extern "C" {
#endif

void USBD_reenumerate(void);
#ifdef USBD_USE_CDC
void USBD_CDC_init(void);
#endif

/* Weaked function */
void USBD_SystemClockConfigFromResume(void);

#ifdef __cplusplus
}
#endif
#endif /* USBCON */
#endif /* __USBD_IF_H */
