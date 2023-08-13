#include <stdbool.h>
#include <stdint.h>
#include <stdarg.h>
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_uart.h"
#include "driverlib/debug.h"
#include "driverlib/interrupt.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/eeprom.h"
#include "driverlib/flash.h"

int main(void)
{
    uint32_t Data[2];
    uint32_t Read[2];

    Data[0] = 0x00000001;
    Data[1] = 0x00000002;

    SysCtlClockSet(SYSCTL_SYSDIV_5 | SYSCTL_USE_PLL | SYSCTL_XTAL_16_3MHZ | SYSCTL_OSC_MAIN);

    SysCtlDelay(20000000);

    /* Enable the EEPROM Peripheral */

    SysCtlPeripheralEnable(SYSCTL_PERIPH_EEPROM0);

    /* Enable the EEPROM */

    EEPROMInit();

    /* Erases the EEPROM , will contain 0xFFFFFFFF */

    EEPROMMassErase();

    /* Used to write the data into EEPROM */

    EEPROMProgram(Data, 0x0, sizeof(Data));

    /* Used to read the data from EEPROM */

    EEPROMRead(Read, 0x0, sizeof(Read));

    while(1)
    {

    }
}


