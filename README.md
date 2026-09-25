# m5stack-tab5-esp32-p4-nofrendo
[WIP] My fork of nofrendo on M5Stack Tab5 (M5Tab5) ESP32-P4, based on AndyAiCardputer/nes-tab5-usb-host  
Adding support for M5Stack Tab5 Keyboard (M5Tab5 Keyboard).  

## Ref
* https://github.com/AndyAiCardputer/nes-tab5-usb-host
* https://github.com/m5stack/M5Tab5-Keyboard-UserDemo

## roms/
* Put .nes file into FAT32 sdcard:\roms\  
* You need to use PSP2000 to format upan  

## Input, Key Map
* main/app_main.cpp, physical_keyboard_callback()
* Up, Down, Left, Right
* Space = Select
* Enter = Start
* Z = A button = Z
* X = B button = X

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

