# nofrendo_fork
[WIP] My nofrendo fork

## Ref
* (origin) https://web.archive.org/web/20210419085348/http://www.baisoku.org
* (origin) https://web.archive.org/web/20210419085348/http://www.baisoku.org/nofrendo-2.0pre1.zip
* (origin, dead) http://www.baisoku.org/nofrendo-2.0pre1.zip
* https://github.com/weimingtom/wmt_stm32_study/?tab=readme-ov-file#nofrendo-stm32f4
* (origin) https://github.com/rickyzhang82/nofrendo   
Sometimes it can run ./configure better than nofrendo-2.0pre1.zip  
```
nofrendo-2.0pre1.zip  
nofrendo_linux_v2_ubuntu_run_uintptr_t.tar.gz  
nofrendo_vc6_v9_min.rar  
(for ./configure) nofrendo_linux_v2_ubuntu.tar.gz
nofrendo_linux_v1.tar.gz
```

## How to build for Xubuntu 20.04 64bit (x86_64, amd64)  
* $ cd src/xubuntu
* $ make clean
* $ make -j8
* Copy file "DEMO.NES" to ~/.
* $ ./nofrendo ~/DEMO.NES

## (WIP) (TODO) How to build for LiuLianPi V3S (Allwinner v3s, ARM 32bit Cortex-A7)  
* Get toolchain gcc-linaro-6.3.1-2017.05-x86_64_arm-linux-gnueabihf.tar.xz  
https://w.electrodragon.com/w/ARM_GCC  
https://releases.linaro.org/components/toolchain/binaries/6.3-2017.05/arm-linux-gnueabihf/  
https://releases.linaro.org/components/toolchain/binaries/6.3-2017.05/arm-linux-gnueabihf/gcc-linaro-6.3.1-2017.05-x86_64_arm-linux-gnueabihf.tar.xz  
* Cross compile static libs libSDL.a and libz.a, see  
https://github.com/weimingtom/nofrendo_fork/blob/master/vendor/v3s/work_v3s_readme.txt  
* See src/liulianpi_v3s/Makefile, tar xf gcc-linaro-6.3.1-2017.05-x86_64_arm-linux-gnueabihf.tar.xz to /home/wmt/work_v3s/gcc-linaro-6.3.1-2017.05-x86_64_arm-linux-gnueabihf
* $ cd src/liulianpi_v3s  
* $ make clean
* $ make -j8
* Copy file "nofrendo" and "DEMO.NES" to tf card
* Login UART (COMx) console with Putty
* \# mkdir /mnt/SDCARD
* \# mount /dev/mmcblk0p1 /mnt/SDCARD/
* \# cd /mnt/SDCARD/nofrendo/
* \# SDL_NOMOUSE=1 ./nofrendo ./DEMO.NES

## uintptr_t problem (NOTE: this is not the only resolution)
* https://github.com/weimingtom/nofrendo_fork/blob/master/src/bitmap.c#L72  
```
上次我用xubuntu 20编译运行nofrendo闪退crash的问题修复了，其实很容易改，
虽然crash的地方是vid_drv.c（这个文件的代码写得比较高手），
但出问题的地方是bitmap_t结构体的line指针数组被截断成32位，
如果要改这个bug，只需要把bitmap.c里面的uint32改成uintptr_t并且包含stdint.h头文件，
然后重新编译就能解决这个截断指针值的bug，至于为什么需要先转换成uintptr_t？
因为C语言里面的指针不能直接做按位操作，需要先转换成整数型，
而指针转换成uintptr_t不会丢失数据，可以重新转换回去
```
