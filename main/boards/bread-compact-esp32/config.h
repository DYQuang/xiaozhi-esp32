#ifndef _BOARD_CONFIG_H_
#define _BOARD_CONFIG_H_

#include <driver/gpio.h>

/**
 * =========================================
 *  AUDIO CONFIGURATION
 * =========================================
 */
#define AUDIO_INPUT_SAMPLE_RATE  16000
#define AUDIO_OUTPUT_SAMPLE_RATE 24000

// Dùng Simplex mode (mic và loa riêng biệt)
#define AUDIO_I2S_METHOD_SIMPLEX

#ifdef AUDIO_I2S_METHOD_SIMPLEX

// Mic I2S (ví dụ: INMP441 hoặc SPH0645)
#define AUDIO_I2S_MIC_GPIO_WS   GPIO_NUM_25   // LRCLK / WS
#define AUDIO_I2S_MIC_GPIO_SCK  GPIO_NUM_26   // BCLK / SCK
#define AUDIO_I2S_MIC_GPIO_DIN  GPIO_NUM_34   // SD (input from mic)

// Speaker I2S (ví dụ: MAX98357A)
#define AUDIO_I2S_SPK_GPIO_DOUT GPIO_NUM_22   // SD (output to amp)
#define AUDIO_I2S_SPK_GPIO_BCLK GPIO_NUM_27   // BCLK
#define AUDIO_I2S_SPK_GPIO_LRCK GPIO_NUM_14   // LRCLK

#else  // Duplex mode
#define AUDIO_I2S_GPIO_WS   GPIO_NUM_25
#define AUDIO_I2S_GPIO_BCLK GPIO_NUM_26
#define AUDIO_I2S_GPIO_DIN  GPIO_NUM_34
#define AUDIO_I2S_GPIO_DOUT GPIO_NUM_22
#endif


/**
 * =========================================
 *  BUTTONS & LED
 * =========================================
 */
#define BUILTIN_LED_GPIO        GPIO_NUM_2     // LED onboard
#define BOOT_BUTTON_GPIO        GPIO_NUM_0     // Boot / Flash button
#define TOUCH_BUTTON_GPIO       GPIO_NUM_4     // Tùy chọn nút cảm ứng
#define VOLUME_UP_BUTTON_GPIO   GPIO_NUM_16
#define VOLUME_DOWN_BUTTON_GPIO GPIO_NUM_17


/**
 * =========================================
 *  DISPLAY (OLED SSD1306 / SH1106)
 * =========================================
 */
#define DISPLAY_SDA_PIN GPIO_NUM_21
#define DISPLAY_SCL_PIN GPIO_NUM_22
#define DISPLAY_WIDTH   128

#if CONFIG_OLED_SSD1306_128X32
    #define DISPLAY_HEIGHT  32
#elif CONFIG_OLED_SSD1306_128X64
    #define DISPLAY_HEIGHT  64
#elif CONFIG_OLED_SH1106_128X64
    #define DISPLAY_HEIGHT  64
    #define SH1106
#else
    #error "Chưa chọn loại OLED trong menuconfig"
#endif

#define DISPLAY_MIRROR_X false
#define DISPLAY_MIRROR_Y false


/**
 * =========================================
 *  GPIO TEST
 * =========================================
 */
#define LAMP_GPIO GPIO_NUM_23   // GPIO điều khiển đèn hoặc relay

#endif // _BOARD_CONFIG_H_
