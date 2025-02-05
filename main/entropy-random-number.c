#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_adc/adc_oneshot.h"
#include "esp_log.h"

#define ADC_CHANNEL	ADC_CHANNEL_3
#define ADC_UNIT	ADC_UNIT_1

uint8_t get_random_byte(adc_oneshot_unit_handle_t adc_handle) {
	uint8_t rand_val = 0;
	for (int i = 0; i < 8; i++) {
		int adc_value = 0;
		adc_oneshot_read(adc_handle, ADC_CHANNEL, &adc_value);
		rand_val ^= (uint8_t)(adc_value & 0xFF);
	}
	return rand_val;
}


void app_main() {
	adc_oneshot_unit_handle_t adc1_handle;
	adc_oneshot_unit_init_cfg_t init_config = {
		.unit_id = ADC_UNIT
	};

	adc_oneshot_new_unit(&init_config, &adc1_handle);
	adc_oneshot_chan_cfg_t config = {
		.bitwidth = ADC_BITWIDTH_DEFAULT,
		.atten = ADC_ATTEN_DB_12
	};
	    
	adc_oneshot_config_channel(adc1_handle, ADC_CHANNEL, &config);

	while (1) {
		uint8_t random_value = get_random_byte(adc1_handle);
		ESP_LOGI("RAND", "Random number: %d", random_value);

		vTaskDelay(pdMS_TO_TICKS(1000));
	}
}
