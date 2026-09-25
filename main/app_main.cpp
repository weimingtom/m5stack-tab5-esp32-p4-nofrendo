/*
 * NES Emulator for M5Stack Tab5 with File Browser
 * ESP-IDF Framework
 */

#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
//#include <stdint.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "nes_osd.h"
#include "bsp/m5stack_tab5.h"
#include "battery_monitor.h"
#include "usb/usb_host.h"
#include "usb/hid_host.h"
#include "usb/hid.h"
#include "m5_tab5_keyboard.h"

//D:\work_m5stack_tab5\rv32ima_test\M5Tab5-Keyboard-UserDemo-main\main\main.cpp
m5::M5Tab5Keyboard device_kb;
m5::M5Tab5Keyboard *g_kb_instance = 0;
static uint8_t kb_firmware_version = 0;  // Keyboard firmware version

// Nofrendo
extern "C" {
    #include "nofrendo.h"
    int nofrendo_main(int argc, char *argv[]);

#include "event.h"
//#include "nes/nesinput.h"
enum
{
   INP_STATE_BREAK,
   INP_STATE_MAKE
};/*
*/	
}

#if 0
#endif

static const char *TAG = "NES_FILE_BROWSER";
















// Display dimensions (landscape: 1280x720)
#define DISPLAY_WIDTH  1280
#define DISPLAY_HEIGHT 720

// File browser state
#define MAX_ROMS 100
static char romFiles[MAX_ROMS][256];
static int romCount = 0;
static int selectedFile = 0;
static const int MAX_VISIBLE_FILES = 16;  // Number of files visible on screen
static bool showBrowser = true;
















// Physical keyboard event callback
//static const char* TAG = "ui_app";
//see kb_event_task()
/*
I (7638) m5_tab5_keyboard: KB_EVT mode=Normal(0) trigger=irq int_sta=0x01 queue=1 normal pressed=1 row=3 col=10 raw=0xBA
I (7638) NES_FILE_BROWSER: ============physical_keyboard_callback
I (7643) NES_FILE_BROWSER: NORMAL mode: row=3, col=10, key_id=52, pressed=1
I (7821) m5_tab5_keyboard: KB_EVT mode=Normal(0) trigger=irq int_sta=0x01 queue=1 normal pressed=0 row=3 col=10 raw=0x3A
I (7821) NES_FILE_BROWSER: ============physical_keyboard_callback
I (7826) NES_FILE_BROWSER: NORMAL mode: row=3, col=10, key_id=52, pressed=0
I (8016) m5_tab5_keyboard: KB_EVT mode=Normal(0) trigger=irq int_sta=0x01 queue=1 normal pressed=1 row=3 col=10 raw=0xBA
I (8016) NES_FILE_BROWSER: ============physical_keyboard_callback
I (8021) NES_FILE_BROWSER: NORMAL mode: row=3, col=10, key_id=52, pressed=1
I (8153) m5_tab5_keyboard: KB_EVT mode=Normal(0) trigger=irq int_sta=0x01 queue=1 normal pressed=0 row=3 col=10 raw=0x3A
I (8154) NES_FILE_BROWSER: ============physical_keyboard_callback
I (8159) NES_FILE_BROWSER: NORMAL mode: row=3, col=10, key_id=52, pressed=0
*/
//see D:\work_m5stack_tab5\rv32ima_test\nes-tab5-usb-host-main\components\m5_tab5_keyboard_component\src\m5_tab5_keyboard.cpp
//see D:\work_m5stack_tab5\rv32ima_test\nes-tab5-usb-host-main\components\nes_emulator\nofrendo\nes\nes.c
//osd_getinput
//see D:\work_m5stack_tab5\rv32ima_test\nes-tab5-usb-host-main\components\nes_emulator\src\nes_osd.c
//Input state
//uint32_t nes_input_state = 0xFFFFFFFF;  // All buttons released
extern uint32_t nes_input_state;
// Map CardKeyBoard keys to NES buttons
#if 1
const int ev[8] = {
	event_joypad1_up, event_joypad1_down,
	event_joypad1_left, event_joypad1_right,
	event_joypad1_select, event_joypad1_start,
	event_joypad1_a, event_joypad1_b
};
#endif
//instead of nes_usb_hid_interface_callback
static void physical_keyboard_callback(m5_tab5_key_event_t event, void* arg)
{	
    (void)arg;
//ESP_LOGI(TAG, "============physical_keyboard_callback");
	// Handle different event types
	if (event.type == M5_TAB5_KB_MODE_NORMAL) {
//FIXME:TODO: normal run here:		
		// Normal Mode: Row/Col events
		uint16_t key_id = event.row * 14 + event.col;
		//ESP_LOGD
		ESP_LOGI(TAG, "NORMAL mode: row=%d, col=%d, key_id=%d, pressed=%d", event.row, event.col, key_id,
				 event.pressed);

#if 0				 
		// Update Log Label with firmware version (Format based on _default_key_callback)
		update_log_label("[FW:%02X] [NORMAL] %s | Row: %d | Col: %d | Raw: 0x%02X", kb_firmware_version,
						 event.pressed ? "PRESSED " : "RELEASED", event.row, event.col, event.raw_data);
#endif
		//see key_id, event.pressed
		
		
		
		uint32_t old_state = nes_input_state;
		uint16_t key = (uint8_t)key_id;
		//uint32_t state = 0xFFFFFFFF;  // All buttons released by default
		if (event.pressed == 1) {
			if (key == 53/*0xB5*/) {  // Up
				nes_input_state &= ~(1UL << 0);
			}
			if (key == 67/*0xB6*/) {  // Down
				nes_input_state &= ~(1UL << 1);
			}
			if (key == 66/*0xB4*/) {  // Left
				nes_input_state &= ~(1UL << 2);
			}
			if (key == 68/*0xB7*/) {  // Right
				nes_input_state &= ~(1UL << 3);
			}
			
			// Control keys
			if (key == 69/*0x20*/) {  // Space = Select
				nes_input_state &= ~(1UL << 4);
			}
			if (key == 55/*0x0D*/) {  // Enter = Start
				nes_input_state &= ~(1UL << 5);
			}
			
			// Symbol keys
			if (key == 58/*0x2F*/) {  // Z = A button = Z
				nes_input_state &= ~(1UL << 6);
			}
			if (key == 59/*0x2E*/) {  // X = B button = X
				nes_input_state &= ~(1UL << 7);
			}
		} else {
			if (key == 53/*0xB5*/) {  // Up
				nes_input_state |= (1UL << 0);
			}
			if (key == 67/*0xB6*/) {  // Down
				nes_input_state |= (1UL << 1);
			}
			if (key == 66/*0xB4*/) {  // Left
				nes_input_state |= (1UL << 2);
			}
			if (key == 68/*0xB7*/) {  // Right
				nes_input_state |= (1UL << 3);
			}
			
			// Control keys
			if (key == 69/*0x20*/) {  // Space = Select
				ESP_LOGI(TAG, "============physical_keyboard_callback, select"); 
				nes_input_state |= (1UL << 4);
			}
			if (key == 55/*0x0D*/) {  // Enter = Start
				ESP_LOGI(TAG, "============physical_keyboard_callback, start"); 
				nes_input_state |= (1UL << 5);
			}
			
			// Symbol keys
			if (key == 58/*0x2F*/) {  // Z = A button = Z
				nes_input_state |= (1UL << 6);
			}
			if (key == 59/*0x2E*/) {  // X = B button = X
				nes_input_state |= (1UL << 7);
			}
		}
		
		// Update nes_input_state
		//nes_input_state = state;
ESP_LOGI(TAG, "============physical_keyboard_callback, nes_input_state == %02X", (uint8_t)nes_input_state);
		
#if 1		
		if (showBrowser) {
			//skip, don't crash in event_get()
		} else {
			// Send events for changed buttons
			uint32_t changed = nes_input_state ^ old_state;
			for (int i = 0; i < 8; i++) {
				if (changed & (1UL << i)) {
					event_t evh = event_get(ev[i]);
					if (evh) {
						bool pressed = (nes_input_state & (1UL << i)) == 0;
						evh(pressed ? INP_STATE_MAKE : INP_STATE_BREAK);
					}
				}
			}
		}
#endif	
		
		
		
		
		
		
		
		
		
		
	} else if (event.type == M5_TAB5_KB_MODE_STRING) {
		// String/Char Mode: String data events
		ESP_LOGI(TAG, "CHAR mode: len=%d, data='%s'", event.str_len, event.str_data);

#if 0
		// Update Log Label with firmware version (Format based on _default_key_callback)
		update_log_label("[FW:%02X] [STRING] Mod: 0x%02X | Len: %d | Data: %s", kb_firmware_version,
						 event.str_modifier, event.str_len, event.str_data);
#endif
						 
		ESP_LOGI(TAG, "[FW:%02X] [STRING] Mod: 0x%02X | Len: %d | Data: %s",
									kb_firmware_version, event.str_modifier, event.str_len, event.str_data);
	} else if (event.type == M5_TAB5_KB_MODE_HID) {
		// HID Mode: HID keycode events
		ESP_LOGI(TAG, "HID mode: modifier=0x%02X, keycode=0x%02X", event.hid_modifier, event.hid_key_code);
#if 0
		// Update Log Label with firmware version (Format based on _default_key_callback)
		update_log_label("[FW:%02X] [HID] Mod: 0x%02X | KeyCode: 0x%02X", kb_firmware_version, event.hid_modifier,
						 event.hid_key_code);
#endif
		//see event.hid_modifier, event.hid_key_code
	}
}


















// Colors (RGB565)
#define COLOR_BLACK   0x0000
#define COLOR_WHITE   0xFFFF
#define COLOR_YELLOW  0xFFE0
#define COLOR_BLUE    0x001F
#define COLOR_GREEN   0x07E0
#define COLOR_RED     0xF800

// USB Host handles
static usb_host_client_handle_t s_usb_client_handle = NULL;

// USB Host client event callback
static void usb_host_event_callback(const usb_host_client_event_msg_t* event_msg, void* arg)
{
    switch (event_msg->event) {
        case USB_HOST_CLIENT_EVENT_NEW_DEV:
            ESP_LOGI(TAG, "USB Host: New device connected on address %d", event_msg->new_dev.address);
            break;
        case USB_HOST_CLIENT_EVENT_DEV_GONE:
            ESP_LOGI(TAG, "USB Host: Device disconnected");
            break;
        default:
            break;
    }
}

// USB Host client event handler task
static void usb_host_client_task(void* arg)
{
    while (1) {
        if (s_usb_client_handle) {
            usb_host_client_handle_events(s_usb_client_handle, portMAX_DELAY);
        } else {
            vTaskDelay(pdMS_TO_TICKS(100));
        }
    }
}

// HID Device event callback
static void hid_host_device_event(hid_host_device_handle_t hid_device_handle,
                                  const hid_host_driver_event_t event,
                                  void* arg)
{
    hid_host_dev_params_t dev_params;
    esp_err_t ret = hid_host_device_get_params(hid_device_handle, &dev_params);
    if (ret != ESP_OK) {
        return;
    }
    
    switch (event) {
        case HID_HOST_DRIVER_EVENT_CONNECTED: {
            hid_host_dev_info_t dev_info;
            ret = hid_host_get_device_info(hid_device_handle, &dev_info);
            
            if (ret == ESP_OK) {
                ESP_LOGI(TAG, "USB Gamepad CONNECTED");
                ESP_LOGI(TAG, "  VID: 0x%04X", dev_info.VID);
                ESP_LOGI(TAG, "  PID: 0x%04X", dev_info.PID);
                
                // Set VID/PID in nes_osd for gamepad parsing
                nes_usb_gamepad_set_vid_pid(dev_info.VID, dev_info.PID);
            }
            
            const hid_host_device_config_t dev_config = {
                .callback = nes_usb_hid_interface_callback,
                .callback_arg = NULL
            };
            
            ESP_ERROR_CHECK(hid_host_device_open(hid_device_handle, &dev_config));
            ESP_ERROR_CHECK(hid_host_device_start(hid_device_handle));
            
            // Wait for device to initialize (as in working nes_tab5_usb_host project)
            vTaskDelay(pdMS_TO_TICKS(100));
            
            ESP_LOGI(TAG, "USB Gamepad ready!");
            break;
        }
        
        default:
            break;
    }
}

// Scan ROM files from /sd/roms/ directory
static void scanROMFiles(void)
{
    ESP_LOGI(TAG, "Scanning /sd/roms/ for .nes files...");
    
    romCount = 0;
    
    DIR* dir = opendir("/sd/roms");
    if (dir == NULL) {
        ESP_LOGE(TAG, "Failed to open /sd/roms directory");
        return;
    }
    
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL && romCount < MAX_ROMS) {
        // Skip hidden files and directories
        if (entry->d_name[0] == '.') {
            continue;
        }
        
        // Check if file has .nes extension (case insensitive)
        const char* name = entry->d_name;
        size_t len = strlen(name);
        if (len >= 4) {
            const char* ext = name + len - 4;
            if (strcasecmp(ext, ".nes") == 0) {
                // Copy filename (without path)
                strncpy(romFiles[romCount], name, sizeof(romFiles[0]) - 1);
                romFiles[romCount][sizeof(romFiles[0]) - 1] = '\0';
                romCount++;
                ESP_LOGI(TAG, "  Found: %s", name);
            }
        }
    }
    
    closedir(dir);
    
    ESP_LOGI(TAG, "Found %d ROM files", romCount);
    
    if (romCount == 0) {
        ESP_LOGW(TAG, "No ROM files found in /sd/roms/");
    }
}

// Draw file browser
static void drawFileBrowser(void)
{
    // Clear screen with black
    nes_display_clear(COLOR_BLACK);
    
    // Title
    nes_display_draw_string(20, 20, "Select NES Game", COLOR_WHITE, 2);
    
    // File counter (e.g., "1/10")
    if (romCount > 0) {
        char counter[32];
        snprintf(counter, sizeof(counter), "%d/%d", selectedFile + 1, romCount);
        // Move counter left to avoid overlap with battery indicator (battery starts at x=1230)
        // Counter width: ~64 pixels, battery width: ~50 pixels + text
        // Position counter at x=1100 to leave ~80 pixels gap
        int counter_x = DISPLAY_WIDTH - strlen(counter) * 8 * 2 - 180;  // Changed from -20 to -180
        nes_display_draw_string(counter_x, 20, counter, COLOR_WHITE, 2);
    }
    
    // Draw battery indicator in top-right corner
    nes_display_draw_battery_indicator();
    
    // File list area (no border)
    int list_x = 20;
    int list_y = 60;
    
    if (romCount == 0) {
        // No ROMs found message
        nes_display_draw_string(40, DISPLAY_HEIGHT / 2 - 20, "No ROM files found", COLOR_RED, 2);
        nes_display_draw_string(40, DISPLAY_HEIGHT / 2 + 20, "Place .nes files in /sd/roms/", COLOR_WHITE, 1);
    } else {
        // Calculate which files to show (keep selected file centered)
        int visibleStart = selectedFile - MAX_VISIBLE_FILES / 2;
        if (visibleStart < 0) {
            visibleStart = 0;
        }
        if (visibleStart + MAX_VISIBLE_FILES > romCount) {
            visibleStart = romCount - MAX_VISIBLE_FILES;
            if (visibleStart < 0) {
                visibleStart = 0;
            }
        }
        
        // Draw file list
        int file_y = list_y;
        for (int i = 0; i < MAX_VISIBLE_FILES && (visibleStart + i) < romCount; i++) {
            int fileIndex = visibleStart + i;
            bool isSelected = (fileIndex == selectedFile);
            
            // File name
            const char* fileName = romFiles[fileIndex];
            
            // Selected file: larger text (1.5x = 3x scale from 2x base), yellow color
            // Unselected files: normal text (2x scale), white color
            if (isSelected) {
                nes_display_draw_string(list_x, file_y, fileName, COLOR_YELLOW, 3);
            } else {
                nes_display_draw_string(list_x, file_y, fileName, COLOR_WHITE, 2);
            }
            
            file_y += 40;  // Spacing between files
        }
    }
    
    // Flush to display
    nes_display_flush();
}

// Handle input for file browser
static void handleFileBrowserInput(void)
{
    // Update input state safely (without nofrendo event system)
    nes_input_update_state_safe();
    
    // Handle navigation (D-Pad up/down)
    static bool up_was_pressed = false;
    static bool down_was_pressed = false;
    static bool start_was_pressed = false;
    static bool a_was_pressed = false;
    
    bool up_pressed = nes_input_is_up_pressed();
    bool down_pressed = nes_input_is_down_pressed();
    bool start_pressed = nes_input_is_start_pressed();
    bool a_pressed = nes_input_is_a_pressed();
    
    // Up button (with edge detection)
    if (up_pressed && !up_was_pressed) {
        if (selectedFile > 0) {
            selectedFile--;
        }
    }
    up_was_pressed = up_pressed;
    
    // Down button (with edge detection)
    if (down_pressed && !down_was_pressed) {
        if (selectedFile < romCount - 1) {
            selectedFile++;
        }
    }
    down_was_pressed = down_pressed;
    
    // Start or A button - launch game
    if ((start_pressed && !start_was_pressed) || (a_pressed && !a_was_pressed)) {
        if (romCount > 0 && selectedFile >= 0 && selectedFile < romCount) {
            showBrowser = false;  // Exit browser loop
        }
    }
    start_was_pressed = start_pressed;
    a_was_pressed = a_pressed;
}

extern "C" void app_main(void)
{
    ESP_LOGI(TAG, "========================================");
    ESP_LOGI(TAG, "NES Emulator for M5Stack Tab5");
    ESP_LOGI(TAG, "With File Browser");
    ESP_LOGI(TAG, "ESP-IDF Framework");
    ESP_LOGI(TAG, "========================================");
    
    // Initialize NVS
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);
    
	
	
	//------------------------
    ESP_LOGI(TAG, "Initializing M5Tab5 Keyboard...");
	g_kb_instance = &device_kb;
	
	m5_tab5_kb_mode_t driver_mode = M5_TAB5_KB_MODE_NORMAL;
	//switch (page_id) {
	//	case PAGE_ID_FACTORY:
	//	case PAGE_ID_NORMAL:
	//		driver_mode = M5_TAB5_KB_MODE_NORMAL;
	//		break;
	//	case PAGE_ID_HID:
	//		driver_mode = M5_TAB5_KB_MODE_HID;
	//		break;
	//	case PAGE_ID_STRING:
	//		driver_mode = M5_TAB5_KB_MODE_STRING;
	//		break;
	//	default:
	//		driver_mode = M5_TAB5_KB_MODE_NORMAL;
	//		break;
	//}

	g_kb_instance->setMode(driver_mode);

	//if (page_id == PAGE_ID_FACTORY) {
	//	g_kb_instance->setRGBMode(M5_TAB5_KB_RGB_MODE_CUSTOM);
	//} else {
	g_kb_instance->setRGBMode(M5_TAB5_KB_RGB_MODE_BINDING);
	//}
	
	if (g_kb_instance) {
		ESP_LOGI(TAG, "============Keyboard initialized 1");
 #if 0       
		if (g_kb_instance->isInitialized()) {
            ESP_LOGI(TAG, "============Keyboard initialized 2");
			if (g_kb_instance->getVersion(&kb_firmware_version) != M5_TAB5_KB_OK) {
                kb_firmware_version = 0x00;
            }
        }
#endif
		//FIXME: be careful, setKeyCallback() will be overwrite by enableNormalMode()
		ESP_LOGI(TAG, "============Keyboard initialized 3");
		g_kb_instance->setKeyCallback(physical_keyboard_callback, nullptr);		
	}
	
	//FIXME:NOTE: Be careful, .begin() or ->begin() must be at the end of the init code
    // Initialize keyboard using standard I2C_NUM_1 and hardware interrupt pin
    m5_tab5_kb_err_t kb_err =
        device_kb.begin(I2C_NUM_1, M5_TAB5_KB_DEFAULT_ADDR, M5_TAB5_KB_DEFAULT_SDA, M5_TAB5_KB_DEFAULT_SCL,
                        M5_TAB5_KB_I2C_FREQ_400K, M5_TAB5_KB_DEFAULT_INT, M5_TAB5_KB_INT_MODE_HARDWARE);

    uint8_t kb_version = 0x00;
    if (kb_err == M5_TAB5_KB_OK) {
        ESP_LOGI(TAG, "Keyboard initialized successfully. Default Normal Mode Enabled.");
        if (device_kb.getVersion(&kb_version) != M5_TAB5_KB_OK) {
            ESP_LOGW(TAG, "Failed to read keyboard firmware version");
            kb_version = 0x00;
        } else {
            ESP_LOGI(TAG, "Keyboard FW: 0x%02X", kb_version);
        }
    } else {
        ESP_LOGW(TAG, "Keyboard not detected at boot, hotplug monitor will handle reconnection");
    }
	
	//physical_keyboard_callback
	//setKeyCallback
#if 0	
	//D:\work_m5stack_tab5\rv32ima_test\M5Tab5-Keyboard-UserDemo-main\main\ui_app.cpp
	// --- Disconnected State ---
    //kb_set_hotplug_state(KB_HOTPLUG_STATE_RECONNECTING);
	m5_tab5_kb_err_t err =
		g_kb_instance->begin(I2C_NUM_1, M5_TAB5_KB_DEFAULT_ADDR, M5_TAB5_KB_DEFAULT_SDA, M5_TAB5_KB_DEFAULT_SCL,
							 M5_TAB5_KB_I2C_FREQ_400K, M5_TAB5_KB_DEFAULT_INT, M5_TAB5_KB_INT_MODE_HARDWARE);

	if (err == M5_TAB5_KB_OK) {
		// Initialization successful, read version and set mode
		g_kb_instance->setKeyCallback(physical_keyboard_callback, nullptr);

		uint8_t ver = 0;
		if (g_kb_instance->getVersion(&ver) == M5_TAB5_KB_OK) {
			kb_firmware_version = ver;
		} else {
			kb_firmware_version = 0;
		}

		kb_connected      = true;
		kb_i2c_fail_count = 0;
		kb_apply_mode_for_current_page();
		kb_set_hotplug_state(KB_HOTPLUG_STATE_STABLE);
		update_log_label("[FW:%02X] Keyboard Connected", kb_firmware_version);
		refresh_factory_version_if_visible();
		ESP_LOGI(TAG, "Keyboard connected! FW: 0x%02X", kb_firmware_version);
	}
#endif			
	
	
	//FIXME: be careful, setKeyCallback() will be overwrite by enableNormalMode(), so executed after .begin() 
	ESP_LOGI(TAG, "============Keyboard initialized 3.1");
	g_kb_instance->setKeyCallback(physical_keyboard_callback, nullptr);	
		
	//------------------------
	
	
	
	
    // Initialize OSD (display, sound, input)
    ESP_LOGI(TAG, "Initializing OSD...");
    ret = nes_osd_init();
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "OSD initialization failed: %s", esp_err_to_name(ret));
        return;
    }
    
    ESP_LOGI(TAG, "NES Emulator initialized successfully!");
    
    // Initialize SD card
    ESP_LOGI(TAG, "Initializing SD card...");
    char mount_point[] = "/sd";
    esp_err_t sd_ret = bsp_sdcard_init(mount_point, 5);
    if (sd_ret != ESP_OK) {
        ESP_LOGE(TAG, "SD card initialization failed: %s", esp_err_to_name(sd_ret));
        ESP_LOGE(TAG, "Please insert SD card and restart");
        
        // Show error on display
        nes_display_clear(COLOR_BLACK);
        nes_display_draw_string(20, DISPLAY_HEIGHT / 2 - 20, "SD Card Error", COLOR_RED, 2);
        nes_display_draw_string(20, DISPLAY_HEIGHT / 2 + 20, "Insert SD card and restart", COLOR_WHITE, 1);
        nes_display_flush();
        
        while (1) {
            vTaskDelay(pdMS_TO_TICKS(1000));
        }
    }
    
    ESP_LOGI(TAG, "SD card initialized and mounted at /sd");
    

	
	
	
	
	
	
	
	
	
	
	
    // Check if USB-C is connected (may conflict with USB Host)
    bool usb_c_connected = bsp_usb_c_detect();
    if (usb_c_connected) {
        ESP_LOGW(TAG, "USB-C cable detected - USB Host may not work");
        ESP_LOGW(TAG, "Disconnect USB-C cable from computer for USB Host to work");
    }
    
    // Start USB Host
    ESP_LOGI(TAG, "Initializing USB Host...");
    esp_err_t usb_host_ret = bsp_usb_host_start(BSP_USB_HOST_POWER_MODE_USB_DEV, true);
    if (usb_host_ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to start USB Host: %s", esp_err_to_name(usb_host_ret));
        ESP_LOGW(TAG, "USB Host disabled - USB gamepad will not work");
        // Continue without USB Host
    } else {
        // Warning: USB Host may not work when device is connected to computer via USB-C
        if (usb_c_connected) {
            ESP_LOGW(TAG, "NOTE: USB Host may not work when connected to computer via USB-C");
            ESP_LOGW(TAG, "Disconnect USB-C cable from computer for USB Host to work");
        }
        
        // Enable USB-A port power
        bsp_set_usb_5v_en(true);
        vTaskDelay(pdMS_TO_TICKS(100));
        
        // Enable USB Host root port power
        ret = usb_host_lib_set_root_port_power(true);
        if (ret == ESP_ERR_INVALID_STATE) {
            ESP_LOGI(TAG, "USB Host root port power already enabled");
        }
        
        // Register USB Host client
        usb_host_client_config_t client_config = {
            .is_synchronous = false,
            .max_num_event_msg = 5,
            .async = {
                .client_event_callback = usb_host_event_callback,
                .callback_arg = NULL
            }
        };
        
        ret = usb_host_client_register(&client_config, &s_usb_client_handle);
        if (ret == ESP_OK) {
            xTaskCreate(usb_host_client_task, "usb_host_client", 4096, NULL, 5, NULL);
            ESP_LOGI(TAG, "USB Host client registered");
        } else {
            ESP_LOGW(TAG, "Failed to register USB Host client: %s", esp_err_to_name(ret));
        }
        
        // Install HID Host driver
        const hid_host_driver_config_t hid_host_driver_config = {
            .create_background_task = true,
            .task_priority = 5,
            .stack_size = 4096,
            .core_id = 0,
            .callback = hid_host_device_event,
            .callback_arg = NULL
        };
        
        ret = hid_host_install(&hid_host_driver_config);
        if (ret == ESP_OK) {
            ESP_LOGI(TAG, "HID Host driver installed");
            ESP_LOGI(TAG, "Waiting for USB gamepad to be connected...");
            ESP_LOGI(TAG, "Connect gamepad to USB-A port on Tab5");
        } else {
            ESP_LOGW(TAG, "Failed to install HID Host driver: %s", esp_err_to_name(ret));
        }
    }
    
    // Initialize battery monitor AFTER USB Host (to avoid conflicts)
    ESP_LOGI(TAG, "Enabling battery charging...");
    bsp_set_charge_en(true);
    ESP_LOGI(TAG, "Battery charging enabled");
    
    ESP_LOGI(TAG, "Initializing battery monitor...");
    i2c_master_bus_handle_t i2c_bus = bsp_i2c_get_handle();
    if (i2c_bus) {
        ret = battery_monitor_init(i2c_bus);
        if (ret == ESP_OK) {
            ESP_LOGI(TAG, "Battery monitor initialized successfully");
            battery_status_t status;
            if (battery_monitor_read(&status) == ESP_OK) {
                ESP_LOGI(TAG, "Battery: %d%%, %dmV, Charging: %s", 
                         status.level, status.voltage_mv, 
                         status.is_charging ? "YES" : "NO");
            }
        } else {
            ESP_LOGW(TAG, "Battery monitor initialization failed: %s", esp_err_to_name(ret));
        }
    } else {
        ESP_LOGW(TAG, "I2C bus not available for battery monitor");
    }
    
    // Scan ROM files
    scanROMFiles();
    
    // File browser loop
    showBrowser = true;
    selectedFile = 0;
    
#if 1    
    while (showBrowser) {
        // Draw file browser
        drawFileBrowser();
        
        // Handle input
        handleFileBrowserInput();
        
        // Small delay
        vTaskDelay(pdMS_TO_TICKS(50));
    }
    // Launch selected ROM
    if (romCount > 0 && selectedFile >= 0 && selectedFile < romCount) {
        // Use static buffer instead of stack variable to prevent stack overflow
        static char rom_path[512];
        snprintf(rom_path, sizeof(rom_path), "/sd/roms/%s", romFiles[selectedFile]);
        
        ESP_LOGI(TAG, "========================================");
        ESP_LOGI(TAG, "Starting NES emulator...");
        ESP_LOGI(TAG, "ROM: %s", rom_path);
        ESP_LOGI(TAG, "========================================");
        
        // Run nofrendo (this is blocking)
        char* argv_[1] = { rom_path };
        nofrendo_main(1, argv_);
        
        ESP_LOGE(TAG, "NES emulator exited unexpectedly!");
    }
#else
	static char rom_path[512];
	snprintf(rom_path, sizeof(rom_path), "/sd/roms/%s", "HDL.NES");
	
	ESP_LOGI(TAG, "========================================");
	ESP_LOGI(TAG, "Starting NES emulator...");
	ESP_LOGI(TAG, "ROM: %s", rom_path);
	ESP_LOGI(TAG, "========================================");
showBrowser = false;	
	// Run nofrendo (this is blocking)
	char* argv_[1] = { rom_path };
	nofrendo_main(1, argv_);
	
	ESP_LOGE(TAG, "NES emulator exited unexpectedly!");
#endif	
    
    // Should not reach here
    while (1) {
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

