/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : pin_mux.c
**     Project     : flexio_i2c_s32k144
**     Processor   : S32K144_100
**     Component   : PinSettings
**     Version     : Component 1.2.0, Driver 1.4, CPU db: 3.00.000
**     Repository  : SDK_S32K14x_07
**     Compiler    : GNU C Compiler
**     Date/Time   : 2023-06-19, 16:02, # CodeGen: 0
**     Abstract    :
**
**
**     Copyright 1997 - 2015 Freescale Semiconductor, Inc.
**     Copyright 2016-2017 NXP
**     All Rights Reserved.
**     
**     THIS SOFTWARE IS PROVIDED BY NXP "AS IS" AND ANY EXPRESSED OR
**     IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
**     OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
**     IN NO EVENT SHALL NXP OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
**     INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
**     SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
**     HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
**     STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
**     IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
**     THE POSSIBILITY OF SUCH DAMAGE.
** ###################################################################*/
/*!
** @file pin_mux.c
** @version 1.4
** @brief
**
*/
/*!
**  @addtogroup pin_mux_module pin_mux module documentation
**  @{
*/

/* MODULE pin_mux. */
#include "device_registers.h"
#include "pin_mux.h"

/**
 * @page misra_violations MISRA-C:2012 violations
 *
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 11.4, A conversion should not be performed
 * between a pointer to object and an integer type.
 * The cast is required to initialize a pointer with an unsigned int define,
 * representing an address.
 *
 * @section [global]
 * Violates MISRA 2012 Required Rule 11.6, A cast shall not be performed
 * between pointer to void and an arithmetic type.
 * The cast is required to initialize a pointer with an unsigned int define,
 * representing an address.
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 8.7, External variable could be made static.
 * The external variables will be used in other source files in application code.
 *
 */

/*! @brief Array of pin configuration structures */
pin_settings_config_t g_pin_mux_InitConfigArr[NUM_OF_CONFIGURED_PINS] = {
    {
           .base          = PORTD,
           .pinPortIdx    = 0u,
           .pullConfig    = PORT_INTERNAL_PULL_NOT_ENABLED,
           .passiveFilter = false,
           .driveSelect   = PORT_LOW_DRIVE_STRENGTH,
           .mux           = PORT_MUX_ALT6,
           .pinLock       = false,
           .intConfig     = PORT_DMA_INT_DISABLED,
           .clearIntFlag  = false,
           .gpioBase      = NULL,
    },
    {
           .base          = PORTE,
           .pinPortIdx    = 5u,
           .pullConfig    = PORT_INTERNAL_PULL_NOT_ENABLED,
           .passiveFilter = false,
           .driveSelect   = PORT_LOW_DRIVE_STRENGTH,
           .mux           = PORT_MUX_ALT5,
           .pinLock       = false,
           .intConfig     = PORT_DMA_INT_DISABLED,
           .clearIntFlag  = false,
           .gpioBase      = NULL,
    },
    {
           .base          = PORTE,
           .pinPortIdx    = 4u,
           .pullConfig    = PORT_INTERNAL_PULL_NOT_ENABLED,
           .passiveFilter = false,
           .driveSelect   = PORT_LOW_DRIVE_STRENGTH,
           .mux           = PORT_MUX_ALT5,
           .pinLock       = false,
           .intConfig     = PORT_DMA_INT_DISABLED,
           .clearIntFlag  = false,
           .gpioBase      = NULL,
    },
    {
           .base          = PORTC,
           .pinPortIdx    = 3u,
           .pullConfig    = PORT_INTERNAL_PULL_NOT_ENABLED,
           .passiveFilter = false,
           .driveSelect   = PORT_LOW_DRIVE_STRENGTH,
           .mux           = PORT_MUX_AS_GPIO,
           .pinLock       = false,
           .intConfig     = PORT_DMA_INT_DISABLED,
           .clearIntFlag  = false,
           .gpioBase      = PTC,
           .direction     = GPIO_OUTPUT_DIRECTION,
    },
    {
           .base          = PORTC,
           .pinPortIdx    = 2u,
           .pullConfig    = PORT_INTERNAL_PULL_NOT_ENABLED,
           .passiveFilter = false,
           .driveSelect   = PORT_LOW_DRIVE_STRENGTH,
           .mux           = PORT_MUX_AS_GPIO,
           .pinLock       = false,
           .intConfig     = PORT_DMA_INT_DISABLED,
           .clearIntFlag  = false,
           .gpioBase      = PTC,
           .direction     = GPIO_OUTPUT_DIRECTION,
    },
    {
           .base          = PORTC,
           .pinPortIdx    = 1u,
           .pullConfig    = PORT_INTERNAL_PULL_NOT_ENABLED,
           .passiveFilter = false,
           .driveSelect   = PORT_LOW_DRIVE_STRENGTH,
           .mux           = PORT_MUX_AS_GPIO,
           .pinLock       = false,
           .intConfig     = PORT_DMA_INT_DISABLED,
           .clearIntFlag  = false,
           .gpioBase      = PTC,
           .direction     = GPIO_OUTPUT_DIRECTION,
    },
    {
           .base          = PORTC,
           .pinPortIdx    = 0u,
           .pullConfig    = PORT_INTERNAL_PULL_NOT_ENABLED,
           .passiveFilter = false,
           .driveSelect   = PORT_LOW_DRIVE_STRENGTH,
           .mux           = PORT_MUX_AS_GPIO,
           .pinLock       = false,
           .intConfig     = PORT_DMA_INT_DISABLED,
           .clearIntFlag  = false,
           .gpioBase      = PTC,
           .direction     = GPIO_OUTPUT_DIRECTION,
    },
    {
           .base          = PORTA,
           .pinPortIdx    = 3u,
           .pullConfig    = PORT_INTERNAL_PULL_NOT_ENABLED,
           .passiveFilter = false,
           .driveSelect   = PORT_LOW_DRIVE_STRENGTH,
           .mux           = PORT_MUX_ALT3,
           .pinLock       = false,
           .intConfig     = PORT_DMA_INT_DISABLED,
           .clearIntFlag  = false,
           .gpioBase      = NULL,
    },
    {
           .base          = PORTA,
           .pinPortIdx    = 2u,
           .pullConfig    = PORT_INTERNAL_PULL_NOT_ENABLED,
           .passiveFilter = false,
           .driveSelect   = PORT_LOW_DRIVE_STRENGTH,
           .mux           = PORT_MUX_ALT3,
           .pinLock       = false,
           .intConfig     = PORT_DMA_INT_DISABLED,
           .clearIntFlag  = false,
           .gpioBase      = NULL,
    },
    {
           .base          = PORTA,
           .pinPortIdx    = 11u,
           .pullConfig    = PORT_INTERNAL_PULL_UP_ENABLED,
           .passiveFilter = false,
           .driveSelect   = PORT_LOW_DRIVE_STRENGTH,
           .mux           = PORT_MUX_ALT4,
           .pinLock       = false,
           .intConfig     = PORT_DMA_INT_DISABLED,
           .clearIntFlag  = false,
           .gpioBase      = NULL,
    },
    {
           .base          = PORTA,
           .pinPortIdx    = 10u,
           .pullConfig    = PORT_INTERNAL_PULL_UP_ENABLED,
           .passiveFilter = false,
           .driveSelect   = PORT_HIGH_DRIVE_STRENGTH,
           .mux           = PORT_MUX_ALT7,
           .pinLock       = false,
           .intConfig     = PORT_DMA_INT_DISABLED,
           .clearIntFlag  = false,
           .gpioBase      = NULL,
    },
    };


/* END pin_mux. */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.1 [05.21]
**     for the Freescale S32K series of microcontrollers.
**
** ###################################################################
*/
