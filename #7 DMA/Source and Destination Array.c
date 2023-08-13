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
#include "driverlib/udma.h"

/* Allocate the channel control table , must be 1024 */

uint8_t dmaControlTable[1024];

/* Source and Destination buffers for DMA transfer */

uint8_t sourceBuffer[256] = "DMA TEST";
uint8_t desBuffer[256];

//uint8_t sourceBuffer[256] ;

int main(void)
{

    /* Enable the DMA Peripheral */

    SysCtlPeripheralEnable(SYSCTL_PERIPH_UDMA);

    /* Check is DMA module is ready */

    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_UDMA));

    /* Enable the DMA */

    uDMAEnable();

    /* Set the base for the channel control table */

    uDMAControlBaseSet(&dmaControlTable[0]);

    /* Clear the Attributes */

    uDMAChannelAttributeDisable(UDMA_CHANNEL_SW, UDMA_PRI_SELECT);

    /* 8-bit data size , bitwise buffer copy & bus arbitration size of 8 */

    uDMAChannelControlSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_SIZE_8 | UDMA_SRC_INC_8 | UDMA_DST_INC_8
                          | UDMA_ARB_8 );

    /* DMA transfer uses AUTO mode */

    uDMAChannelTransferSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_MODE_AUTO ,
                           sourceBuffer, desBuffer, sizeof(desBuffer));

    /* Channel is enable for software transfer , a request must also be made */

    uDMAChannelEnable(UDMA_CHANNEL_SW);

    uDMAChannelRequest(UDMA_CHANNEL_SW);

    while(1)
    {

    }

    return 0;
}
