/* 
 * File:   application.c
 * Author: AyaAli
 * Created on September 22, 2023, 10:24 AM
 */
#include "application.h"

timer2_config_t timer2;
ccp_t ccp1_obj;
ccp_t ccp2_obj;

int main() {
   
Std_ReturnType ret = E_NOT_OK;

ccp1_obj.CCP1_Interrupt_Hundeler = NULL;
ccp1_obj.ccp_mode = CCP_PWM_MODE_SELECTED;
ccp1_obj.PWM_Freq = 20000;
ccp1_obj.ccp_pin.port = PORTC_INDEX;
ccp1_obj.ccp_pin.pin = PIN2;
ccp1_obj.ccp_pin.direction = Output;
ccp1_obj.ccp_module_type = CCP1_Module;
ccp1_obj.timer2_prescaler_value = TIMER2_POSTSCALLER_DIV_BY_1;
ccp1_obj.timer2_postscaler_value= TIMER2_PRESCALLER_DIV_BY_1;
ret = CCP_PWM_Init(&ccp1_obj);


ccp2_obj.CCP1_Interrupt_Hundeler = NULL;
ccp2_obj.ccp_mode = CCP_PWM_MODE_SELECTED;
ccp2_obj.PWM_Freq = 20000;
ccp2_obj.ccp_pin.port = PORTC_INDEX;
ccp2_obj.ccp_pin.pin = PIN1;
ccp2_obj.ccp_pin.direction = Output;
ccp2_obj.ccp_module_type = CCP2_Module;
ccp2_obj.timer2_prescaler_value = TIMER2_POSTSCALLER_DIV_BY_1;
ccp2_obj.timer2_postscaler_value= TIMER2_PRESCALLER_DIV_BY_1;
ret = CCP_PWM_Init(&ccp2_obj);

ret = Timer2_Init(&timer2);



while(1){
ret = CCP_PWM_Set_Duty(&ccp1_obj ,25);
ret = CCP_PWM_Start(&ccp1_obj);
ret = CCP_PWM_Set_Duty(&ccp2_obj ,25);
ret = CCP_PWM_Start(&ccp2_obj);
__delay_ms(2000);
ret = CCP_PWM_Set_Duty(&ccp1_obj , 50);
ret = CCP_PWM_Start(&ccp1_obj);
ret = CCP_PWM_Set_Duty(&ccp2_obj , 50);
ret = CCP_PWM_Start(&ccp2_obj);
__delay_ms(2000);
ret = CCP_PWM_Set_Duty(&ccp1_obj , 75);
ret = CCP_PWM_Start(&ccp1_obj);
ret = CCP_PWM_Set_Duty(&ccp2_obj , 75);
ret = CCP_PWM_Start(&ccp2_obj);
__delay_ms(2000);

}
 return (EXIT_SUCCESS);
}
void application_initialize(void){
   Std_ReturnType ret = E_NOT_OK;

}
