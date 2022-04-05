# OS: Ubuntu 16.04


# Complie tslib

	1. Get tslib source, switch to version 1.21

		$ git clone https://github.com/kergoth/tslib

		# switch to version 1.21
	
		$ git checkout -b 1.21

	2. Install dependencies

		$ sudo apt update

		$ sudo apt install autoconf automake libtool	

	3. Install the tslib library

		$ sudo chmod +x ./autogen.sh

		$ ./autogen.sh

	4. Change the output directory of the arm-linux-gcc-gnueabi cross-compiler

		$ ./configure --host=arm-linux-gnueabihf ac_cv_func_malloc_0_nonnull=yes --cache-file=arm-linux.cache -prefix=/home/luyaohan1001/Projects/qt/tslib>arm-tslib

	Expect:
				......
				checking whether arctic2 module is requested... no
				checking whether dmc_dus3000 module is requested... no
				checking whether one-wire-ts-input module is requested... no
				......
				checking where to place modules... ${libdir}/ts
				......
				config.status: creating Makefile
				config.status: creating etc/Makefile
				......

	5. Compile!

		$ make 

		Expect:
	
				CC       ts_harvest.o
				CCLD     ts_harvest
				CC       ts_finddev.o
				CCLD     ts_finddev
				CC       ts_verify.o
				CCLD     ts_verify
				......
				......
				make[2]: Entering directory '/home/luyaohan1001/Projects/qt/tslib'
				make[2]: Leaving directory '/home/luyaohan1001/Projects/qt/tslib'
				make[1]: Leaving directory '/home/luyaohan1001/Projects/qt/tslib

		$ make install 

				# We don't need to care about the warning messages. When install finished there will be an arm-tslib directory. 

				# But if the directory arm-tslib did not appear. The compilation is unsuccessful.

	6. Check the compile result

	1. $ file bin/ts_calibrate

		expect something like bin/ts_calibrate: ELF 32-bit LSB execution, ARM...

		if it shows x86 then the compilation is wrong. 


# Compile QT Qmake 

	7. Download QT source from: https://download.qt.io/archive/qt/5.12/5.12.9/single/	

		$ tar -xvf qt-everywhere-src-5.12.9.tar.xz

	  $ cd qt-everywhere-src-5.12.9 

	8. Change qmake.conf

		$ vim qtbase/mkspecs/linux-arm-gnueabi-g++/qmake.conf	


		Change to the following:
	
				#
				# qmake configuration for building with arm-linux-gnueabi-g++
				#
				MAKEFILE_GENERATOR = UNIX
				CONFIG += incremental
				QMAKE_INCREMENTAL_STYLE = sublib
				QT_QPA_DEFAULT_PLATFORM = linuxfb
				QMAKE_CFLAGS += -O2 -march=armv7-a -mtune=cortex-a7 -mfpu=neon -mfloat-abi=hard
				QMAKE_CXXFLAGS += -O2 -march=armv7-a -mtune=cortex-a7 -mfpu=neon -mfloat-abi=hard
				include(../common/linux.conf)
				include(../common/gcc-base-unix.conf)
				include(../common/g++-unix.conf)
				# modifications to g++.conf
				QMAKE_CC = arm-linux-gnueabihf-gcc
				QMAKE_CXX = arm-linux-gnueabihf-g++
				QMAKE_LINK = arm-linux-gnueabihf-g++
				QMAKE_LINK_SHLIB = arm-linux-gnueabihf-g++
				# modifications to linux.conf
				QMAKE_AR = arm-linux-gnueabihf-ar cqs
				QMAKE_OBJCOPY = arm-linux-gnueabihf-objcopy
				QMAKE_NM = arm-linux-gnueabihf-nm -P
				QMAKE_STRIP = arm-linux-gnueabihf-strip
				load(qt_config)

	9. We make an autoconfig.sh script to help the compilation process:
		
			$ touch autoconfigure.sh

			$ vim autoconfigure.sh

		Add the following content. (!) Do no include space at the head of each line:
				
				(!) substitue for <parent-directory> first!

				./configure -prefix <parent-directory>/qt-everywhere-src-5.12.9/arm-qt \
				-opensource \
				-confirm-license \
				-release \
				-strip \
				-shared \
				-xplatform linux-arm-gnueabi-g++ \
				-optimized-qmake \
				-c++std c++11 \
				--rpath=no \
				-pch \
				-skip qt3d \
				-skip qtactiveqt \
				-skip qtandroidextras \
				-skip qtcanvas3d \
				-skip qtconnectivity \
				-skip qtdatavis3d \
				-skip qtdoc \
				-skip qtgamepad \
				-skip qtlocation \
				-skip qtmacextras \
				-skip qtnetworkauth \
				-skip qtpurchasing \
				-skip qtremoteobjects \
				-skip qtscript \
				-skip qtscxml \
				-skip qtsensors \
				-skip qtspeech \
				-skip qtsvg \
				-skip qttools \
				-skip qttranslations \
				-skip qtwayland \
				-skip qtwebengine \
				-skip qtwebview \
				-skip qtwinextras \
				-skip qtx11extras \
				-skip qtxmlpatterns \
				-make libs \
				-make examples \
				-nomake tools -nomake tests \
				-gui \
				-widgets \
				-dbus-runtime \
				--glib=no \
				--iconv=no \
				--pcre=qt \
				--zlib=qt \
				-no-openssl \
				--freetype=qt \
				--harfbuzz=qt \
				-no-opengl \
				-linuxfb \
				--xcb=no \
				-tslib \
				--libpng=qt \
				--libjpeg=qt \
				--sqlite=qt \
				-plugin-sql-sqlite \
				-I<parent-directory>/tslib/arm-tslib/include \
				-L<parent-directory>/tslib/arm-tslib/lib \
				-recheck-all
	
	10. compile qmake!

		$ sudo apt install g++

		$ sudo chmod +x autoconfigure.sh

		$ ./autoconfigure.sh

		We should expect 
		......
		Creating qmake..........................
		QT is now configured for building. Just run 'make'...

		$ make -j4

		$ make install

	11. Check the compiled results.

		$ ls arm-qt

		# We should expect directories including: bin / doc / examples / include / lib / mkspecs / plugins / qml.

# Migrate the compiled arm-tslib and arm-qt to IMX6ULL file system ----

	1. Go to the arm-tslib folder

		$ tar -jcf ./arm-tslib.tar.bz2 arm-tslib

		Copy this file to a USB disk, plug in to the development board.

		In the putty terminal:

		-> mkdir mnt
	
		-> mount /dev/sda1 /mnt

		$ tar -xvf arm-tslib.tar.bz2 -C /usr/lib


	2. Check if the file is there:

		$ cd /usr/lib

		$ ls

		We should expect arm-tslib to be there

	3. Change environment path

		$ vi /etc/profile
		$ export TSLIB_CALIBFILE=/etc/pointercal
		$ export TSLIB_ROOT=/usr/lib/arm-tslib
		$	export TSLIB_CONSOLEDEVICE=none
		$	export TSLIB_FBDEVICE=/dev/fb0
		$	export TSLIB_TSDEVICE=/dev/input/event1
		$	export TSLIB_CONFFILE=$TSLIB_ROOT/etc/ts.conf
		$	export TSLIB_PLUGINDIR=$TSLIB_ROOT/lib/ts
		$	export TSLIB_CALIBFILE=/etc/pointercal
		$	export LD_PRELOAD=$TSLIB_ROOT/lib/libts.so
		$ source /etc/profile

		Now we can test the touch screen
		
		$ /usr/lib/arm-tslib/bin/ts_test




				

		


					

	

	

	
