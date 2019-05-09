/* ADC1 lecture
	Medición de un sensor analogo de temperatura LM35, haciendo uso del ADC del ESP32
*/
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>
#include <driver/adc.h>

void delay_ms(int ms){
	vTaskDelay(ms/portTICK_PERIOD_MS);
}

void app_main(){
	gpio_set_direction(36, GPIO_MODE_INPUT);
	float temp;
	adc1_config_width(ADC_WIDTH_BIT_10);
	adc1_config_channel_atten(ADC1_CHANNEL_0, ADC_ATTEN_DB_0);
	while(1){
		int val = adc1_get_raw(ADC1_CHANNEL_0);
		temp = (100*val/1023)*1.3;
		printf("El valor leido por el ADC es %d, y el valor de temperatura es %f °C\r\n", val, temp);
		delay_ms(1000);
	}
}
