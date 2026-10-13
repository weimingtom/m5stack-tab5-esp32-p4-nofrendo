cd SDL-1.2.15/

PATH=/home/wmt/work_v3s/gcc-linaro-6.3.1-2017.05-x86_64_arm-linux-gnueabihf/bin:$PATH  ./configure --host=arm-linux-gnueabihf  --prefix=/home/wmt/work_v3s --disable-shared --enable-static --disable-pulseaudio


PATH=/home/wmt/work_v3s/gcc-linaro-6.3.1-2017.05-x86_64_arm-linux-gnueabihf/bin:$PATH  make -j8


PATH=/home/wmt/work_v3s/gcc-linaro-6.3.1-2017.05-x86_64_arm-linux-gnueabihf/bin:$PATH  make install


---

cd freetype-2.3.12/


PATH=/home/wmt/work_v3s/gcc-linaro-6.3.1-2017.05-x86_64_arm-linux-gnueabihf/bin:$PATH  ./configure --host=arm-linux-gnueabihf  --prefix=/home/wmt/work_v3s --disable-shared --enable-static 



PATH=/home/wmt/work_v3s/gcc-linaro-6.3.1-2017.05-x86_64_arm-linux-gnueabihf/bin:$PATH  make -j8


PATH=/home/wmt/work_v3s/gcc-linaro-6.3.1-2017.05-x86_64_arm-linux-gnueabihf/bin:$PATH  make install

---

cd SDL_ttf-2.0.9/

PATH=/home/wmt/work_v3s/gcc-linaro-6.3.1-2017.05-x86_64_arm-linux-gnueabihf/bin:/home/wmt/work_v3s/bin:$PATH  ./configure --host=arm-linux-gnueabihf  --prefix=/home/wmt/work_v3s --disable-shared --enable-static 


PATH=/home/wmt/work_v3s/gcc-linaro-6.3.1-2017.05-x86_64_arm-linux-gnueabihf/bin:/home/wmt/work_v3s/bin:$PATH make -j8


PATH=/home/wmt/work_v3s/gcc-linaro-6.3.1-2017.05-x86_64_arm-linux-gnueabihf/bin:/home/wmt/work_v3s/bin:$PATH make install



---

cd zlib-1.2.11/

PATH=/home/wmt/work_v3s/gcc-linaro-6.3.1-2017.05-x86_64_arm-linux-gnueabihf/bin:$PATH ./configure --static --prefix=/home/wmt/work_v3s

PATH=/home/wmt/work_v3s/gcc-linaro-6.3.1-2017.05-x86_64_arm-linux-gnueabihf/bin:$PATH make CC=arm-linux-gnueabihf-gcc AR=arm-linux-gnueabihf-ar -j8

PATH=/home/wmt/work_v3s/gcc-linaro-6.3.1-2017.05-x86_64_arm-linux-gnueabihf/bin:$PATH  make install

----


(x) cd libpng-1.2.24/
cd libpng-1.6.8/


PATH=/home/wmt/work_v3s/gcc-linaro-6.3.1-2017.05-x86_64_arm-linux-gnueabihf/bin:/home/wmt/work_v3s/bin:$PATH LDFLAGS=-L/home/wmt/work_v3s/lib CFLAGS=-I/home/wmt/work_v3s/include CPPFLAGS=-I/home/wmt/work_v3s/include ./configure --host=arm-linux-gnueabihf --prefix=/home/wmt/work_v3s --disable-shared --enable-static 


PATH=/home/wmt/work_v3s/gcc-linaro-6.3.1-2017.05-x86_64_arm-linux-gnueabihf/bin:/home/wmt/work_v3s/bin:$PATH LDFLAGS=-L/home/wmt/work_v3s/lib CFLAGS=-I/home/wmt/work_v3s/include CPPFLAGS=-I/home/wmt/work_v3s/include make -j8

PATH=/home/wmt/work_v3s/gcc-linaro-6.3.1-2017.05-x86_64_arm-linux-gnueabihf/bin:/home/wmt/work_v3s/bin:$PATH LDFLAGS=-L/home/wmt/work_v3s/lib CFLAGS=-I/home/wmt/work_v3s/include CPPFLAGS=-I/home/wmt/work_v3s/include make install





