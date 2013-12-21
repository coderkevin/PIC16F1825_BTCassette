/*******************************************************************************
  Generated Main File 

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using MPLAB® Code Configurator

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI. 
    Generation Information : 
        Product Revision  :  MPLAB® Code Configurator - v1.0
        Device            :  PIC16F1825
        Version           :  1.1
    The generated drivers are tested against the following:
        Compiler          :  XC8 v1.21
        MPLAB             :  MPLAB X 1.90
*******************************************************************************/

/*******************************************************************************
Copyright (c) 2013 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*******************************************************************************/

#define _XTAL_FREQ 500000
#define MAIN_LOOP_DELAY 50
#define MAX_IDLE_TICS 100

#include "CM_Generated_Files/mcc.h"
#include "CM_Generated_Files/pin_manager.h"

int sense = 0;

/****************************************************************************
 *
 *                        Main application
 *
****************************************************************************/
void main(void)
{
    unsigned int on = 0;
    unsigned int running = 0;
    unsigned long idle_tics = 0;

    // initialize the device
    SYSTEM_Initializer();

    IO_RA2_SetDigitalInput();

    // enable interrupts, even while asleep.
    INTCONbits.GIE = 1;
    INTCONbits.IOCIE = 1;

    while (1)
    {
        __delay_ms(50);

	if (sense > 0)
	{
	    sense = 0;
	    idle_tics = 0;
	}
	else
	{
	    idle_tics++;
	}

	on = IO_RA2_GetValue();
	running = idle_tics < MAX_IDLE_TICS;

	if (IO_RC0_LAT != on)
	{
	    IO_RC0_LAT = on;
	}

	if (IO_RC1_LAT != running)
	{
	    IO_RC1_LAT = running;
	}

	if (!running)
	{
	    SLEEP();
	}
    }
}
