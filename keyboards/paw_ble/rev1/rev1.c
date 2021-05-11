/*
 * rev1.c
 */

#include "matrix.h"
#include "quantum.h"
#include "nrf.h"
#include "nrf_gpio.h"
#include "app_ble_func.h"

#include "rgblight.h"
extern rgblight_config_t rgblight_config;

#define BLUE_LED GPIO(1,10)

void nrfmicro_blink(int times, int delay) {
  for (int i=0; i<times*2; i++) {
    nrf_gpio_pin_write(BLUE_LED, i%2==0 ? 1 : 0);
    nrf_delay_ms(delay);
  }
}

void matrix_init_user() {
  set_usb_enabled(true);

  nrf_gpio_cfg_output(BLUE_LED);

  nrfmicro_blink(2, 100);

  nrf_gpio_pin_write(BLUE_LED, false);
}


void matrix_scan_kb(void) {
  matrix_scan_user();
}
