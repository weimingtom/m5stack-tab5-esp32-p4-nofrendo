# m5stack-tab5-esp32-p4-nofrendo
[WIP] My fork of nofrendo on M5Stack Tab5 (M5Tab5) ESP32-P4, based on AndyAiCardputer/nes-tab5-usb-host  
Adding support for M5Stack Tab5 Keyboard (M5Tab5 Keyboard).  

## Ref
* https://github.com/AndyAiCardputer/nes-tab5-usb-host
* https://github.com/m5stack/M5Tab5-Keyboard-UserDemo

## Other Ref
* https://github.com/m5stack/M5Tab5-UserDemo
* https://github.com/espressif/esp-bsp
* https://github.com/espressif/esp-board-manager
* (TODO) https://github.com/andjiang0083/retro-go-tab5
* (TODO, not p4) https://github.com/mliangquan/esp32-nesgameconsole
* (TODO, not p4) https://github.com/44670/44vba
* https://gitee.com/weidongshan/rpi_pico_100ask_infones
* (TODO, need LVGL port) https://gitee.com/weidongshan/esp32_100ask_project/tree/master/lib/nofrendo/src
* (TODO, not p4) https://gitee.com/weidongshan/retro-go-yao-mio
* (TODO, not p4) https://gitee.com/mirrors/esplay-retro-emulation
* https://www.oschina.net/p/esplay-retro-emulation
* https://github.com/pebri86/esplay-retro-emulation  
* https://hackaday.io/project/166707-esplay-micro
* (TODO, not p4) https://github.com/fffonion/retro-go
* (TODO, not p4, s31 tested) https://github.com/PIGEON-SOFT/retro-go-s31
* (TODO, not p4) ESP32 esplay_micro游戏机全套资料.rar  
开源ESP32模块游戏机《ESPlay Micro》刷引导程序教程（刷Bootloader教程）  
https://www.bilibili.com/video/BV1254y1U7Kf/  
* (TODO, not p4) ESPLAY_Micro.zip
* (TODO, not p4) https://github.com/UF-Evan/DIJI-NES  
https://www.bilibili.com/video/BV1qsc2z1Eo1/  
https://gitee.com/esp32-g/DIJI-NES  
https://www.bilibili.com/video/BV1qKDPBaEcU/  
* https://github.com/weimingtom/wmt_link_collections_in_Chinese/blob/master/emulator.md  
* (TODO, Arduino, not p4) https://gitee.com/weimingtom2000/infones
* (private) https://gitee.com/weimingtom2000/InfoNES-1
* (v3s) https://github.com/weimingtom/nofrendo_fork
* (v3s) https://github.com/weimingtom/infones_fork
* (v3s) https://github.com/weimingtom/gpsp_fork  
* (stm32) https://github.com/Woody00h/InfoNES
* (linux) https://github.com/yongzhena/infoNES
* (linux) https://github.com/nejidev/arm-NES-linux
* https://burner.m5stack.com/device/tab5
* https://github.com/gywan94/m5stack-tab5-nc1020
* (TODO) https://github.com/georgik/esp-idf-component-SDL/blob/main/sdl/examples/bubble/sdkconfig.defaults.m5stack_tab5
* (TODO) https://github.com/georgik/esp-idf-component-SDL_bsp/blob/main/src/boards/esp_bsp_sdl_m5stack_tab5.c
* HZK Chinese Font, simplewindow_v4.rar, HZK16, ASC, asc16, gb16song    
```
以前模仿嵌入式课老师给的代码改的效果，simplewindow（我改的名字），亮点是——
可以显示小型字体库，俗称HZK或ASC点阵字库，其实就是以前搞16位操作系统时候的古老显示字体方法——
虽然对于嵌入式来说这种做法一点都不古老，毕竟嵌入式对内存要求更高 ​​​

【UCDOS中的点阵字库HZK12,HZK16,HZK24,ASC12,ASC16(转)】 

原文：
http://cache.baidu.com/c?m=9f65cb4a8c8507ed4fece7631046893b4c4380147780914c34c3933fc239045c3738beee3a241706d9c67d6606ab540faaa16c2973543db799ca8c57dfbf8f2b2f9524367a1c874316c419d891007a9f
http://zaazbb.blog.163.com/blog/static/1689785592013101842118932/​​
```
* (gd32) https://wiki.lckfb.com/zh-hans/lspi/project/game-machine.html
* (gd32) https://gitee.com/lcsc/game-ex-base-code
* (gd32) https://gitee.com/lcsc/liangshan-pi-nes-game-console
* (TODO) https://github.com/ducalex/retro-go
* (TODO) https://sourceforge.net/projects/retro-go.mirror

## tf card, roms/
* Put .nes file into FAT32 sdcard:\roms\  
* Sometimes, you need to use PSP2000 to format the tfcard    

## Input, Key Map
* main/app_main.cpp, physical_keyboard_callback()
* Up, Down, Left, Right
* Space = Select
* Enter = Start
* Z = A button = Z
* X = B button = X

## How to build with ESP-IDF 5.4.4
* cmd
* cd m5stack-tab5-esp32-p4-nofrendo/
* idf.py build
* idf.py build flash monitor  

## ESP-IDF 5.4.4, for Win10 and Win11
* https://dl.espressif.cn/dl/esp-idf/
* https://dl.espressif.com/dl/idf-installer/esp-idf-tools-setup-offline-5.4.4.exe
* https://github.com/espressif/idf-installer/releases/download/offline-5.4.4/esp-idf-tools-setup-offline-5.4.4.exe
* https://github.com/espressif/esp-bsp/tree/master/examples
* https://github.com/m5stack/M5Tab5-UserDemo
* NOTE, not need ESP-IDF v5.4.2 (https://docs.espressif.com/projects/esp-idf/en/v5.4.2/esp32s3/index.html), ESP-IDF 5.4.4 is also good
```
我测试过可以运行在m5stack tab5上运行的esp-idf示例代码有：
espressif/esp-bsp的examples和m5stack/M5Tab5-UserDemo。
另外我发现不必装ESP-IDF v5.4.2，只需要装5.4.4，效果是一样的，
只是5.4.4的安装程序没有显示ESP32P4的勾选，但不用管，
默认安装就可以，是可以设置目标板为esp32p4的 ​​​
```
* You should install ONLY ONE ESP-IDF instance on your computer at the same time, otherwise when you uninstall one of the ESP-IDF instances, the other instances will be unavailable (the shortcut will be deleted). It is recommended to reinstall the other ESP-IDF instances if you encounter similar situations
```
你应该在电脑上同时安装不多于一个ESP-IDF实例，
否则当你卸载其中一个ESP-IDF实例，
其他实例就不可用（快捷方式被删除），
建议如果遇到类似的情况最好重新安装其他ESP-IDF实例
```

## weibo record
```
我找到一个m5stack tab5 esp32-p4的nes模拟器开源项目AndyAiCardputer/nes-tab5-usb-host，
我测试过用esp-idf v5.4可以编译，运行也可以（可以魔改代码跳过手柄输入，
直接进入指定的nes后缀文件路径），运行效果不错，有声音输出，但无法输入，
不支持官方的键盘，所以我打算看能不能融合M5Tab5-Keyboard-UserDemo的代码。
原作者可能是故意不支持M5Tab5-Keyboard的

AndyAiCardputer/nes-tab5-usb-host研究，我把这个nes模拟器改成用m5tab5的i2c键盘输入，
但其实手感其实不是很好，还不如原版的usb-host手柄。需要解决几个问题：
（1）怎么用m5_tab5_keyboard_component？放入components，
修改CMakeLists.txt添加子目录，至于用法，其实类似于i2c，
不过我用的是setKeyCallback传入callback函数
（2）文件浏览器的按键，可以通过nes_input_state变量
（3）nofrendo的按键，可以通过event_get()函数输入。
有时间我会开源，作为研究其他esp32-p4模拟器的参考，
因为它的声音按键屏幕都是齐全的
```

## Original README.md

-----------------------------

# NES Emulator for M5Stack Tab5 with File Browser

NES emulator for M5Stack Tab5 with built-in file browser for selecting ROM files.

## Features

- **File Browser**: Browse and select NES ROM files from SD card
- **USB Host Support**: Use USB gamepad (PS5 DualSense only) for navigation
- **I2C Input Support**: Joystick2, Scroll buttons, CardKeyBoard
- **Display**: 1280×720 landscape orientation
- **Audio**: ES8388 codec support

## Hardware Requirements

- M5Stack Tab5 (ESP32-P4)
- SD Card (FAT32) with ROM files in `/sd/roms/` folder
- USB gamepad (optional, for navigation)

## ROM Files

Place your `.nes` ROM files in `/sd/roms/` folder on the SD card.

Example:
```
/sd/roms/
  ├── super_mario.nes
  ├── zelda.nes
  └── metroid.nes
```

## Building

```bash
cd nes_tab5_usb_host
export IDF_PATH=/path/to/esp-idf
source $IDF_PATH/export.sh
idf.py build
```

## Flashing

### Option 1: Flash from Source (Recommended)

```bash
cd nes_tab5_usb_host
export IDF_PATH=/path/to/esp-idf
source $IDF_PATH/export.sh
idf.py -p /dev/cu.usbmodemXXXX flash
```

### Option 2: Flash from GitHub Release

Download all three files from the release:
- `bootloader.bin`
- `partition-table.bin`
- `nes_tab5_file_browser.bin`

Then flash them using esptool:

```bash
# Make sure ESP-IDF environment is loaded
export IDF_PATH=/path/to/esp-idf
source $IDF_PATH/export.sh

# Flash all three files
esptool --chip esp32p4 --port /dev/cu.usbmodemXXXX --baud 921600 write_flash \
  0x0 bootloader.bin \
  0x8000 partition-table.bin \
  0x10000 nes_tab5_file_browser.bin
```

**Important:** All three files are required! Flashing only the main binary will result in "invalid header" errors.

## Usage

1. Insert SD card with ROM files in `/sd/roms/` folder
2. Connect USB gamepad (optional)
3. Power on Tab5
4. File browser will appear showing available ROM files
5. Navigate with D-Pad Up/Down
6. Press Start or A to launch selected game
7. To return to file browser, restart Tab5

## Controls

### File Browser
- **D-Pad Up/Down**: Navigate file list
- **Start or A**: Launch selected game

### In-Game (PS5 DualSense)
- **Cross (PS5)**: NES B
- **Circle (PS5)**: NES A
- **Square**: Turbo B
- **Triangle**: Turbo A
- **Create**: Select
- **Options**: Start
- **D-Pad / Left Stick**: D-Pad

## Project Structure

```
nes_tab5_usb_host/
├── main/
│   └── app_main.cpp          # Main application with file browser
├── components/
│   ├── m5stack_tab5/         # BSP for Tab5
│   └── nes_emulator/         # NES emulator (nofrendo)
│       ├── include/
│       │   └── nes_osd.h     # OSD functions
│       └── src/
│           └── nes_osd.c     # OSD implementation
├── CMakeLists.txt
├── sdkconfig.defaults
└── partitions.csv
```

## License

See component licenses.

