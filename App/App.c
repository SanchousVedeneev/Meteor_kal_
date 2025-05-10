#include "App.h"

// #include "usart.h"

#include "ProtocolMbRtuSlaveCtrl.h"

void app_main()
{
    protocolMbRtuSlaveCtrl_init(1);
    while (1)
    {
        if (HAL_GPIO_ReadPin(USER_BUTTON_GPIO_Port, USER_BUTTON_Pin))
        {
            BSP_LED_ON(BSP_LED_1);
        }
        else
        {
            BSP_LED_OFF(BSP_LED_1);
        }
        HAL_Delay(100);
        protocolMbRtuSlaveCtrl_update_tables();
        // BSP_USART_RX_E_ON(USART2_RX_E);
        // bsp_rs485_sendTestBlock(1);
    }

}

//#define BLINK_PERIOD_RS485
// void bsp_sys_tick_1k_callback()
// {

//     //static int led485counter = 0;
//     protocolMbRtuSlaveCtrl_update_tables();
//     //BSP_LED_TOGGLE(BSP_LED_RS485);
//     asm("NOP");
// }

