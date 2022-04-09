Ialways following some step that always works.

I install OpenCV with opencv_contrib ( some extra module for OpenCV)

Open terminal and run following command

To install opencv dependency

$ sudo apt-get install build-essential

$ sudo apt-get install cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev

$ sudo apt-get install python-dev python-numpy libtbb2 libtbb-dev libjpeg-dev libpng-dev libtiff-dev libjasper-dev libdc1394-22-dev

$ sudo apt-get install libxvidcore-dev libx264-dev
To install opencv

cd /opt/

$ sudo git clone https://github.com/opencv/opencv.git

$ sudo git clone https://github.com/opencv/opencv_contrib.git

$ cd opencv

$ sudo mkdir release

$ cd release

$ sudo cmake -D CMAKE_INSTALL_PREFIX=/usr/local -D INSTALL_C_EXAMPLES=ON -D INSTALL_PYTHON_EXAMPLES=ON -D OPENCV_EXTRA_MODULES_PATH=/opt/opencv_contrib/modules -D WITH_LIBV4L=ON -D WITH_V4L=ON -D BUILD_EXAMPLES=ON /opt/opencv/

(!) WITH_V4L=ON is important! Because our camera streaming application will need it. If we set WITH_V4L=OFF, we see in the cmake summary that:

   Video I/O:
     DC1394:                      YES (2.2.6)
     FFMPEG:                      YES
       avcodec:                   YES (58.91.100)
       avformat:                  YES (58.45.100)
       avutil:                    YES (56.51.100)
       swscale:                   YES (5.7.100)
       avresample:                NO
     GStreamer:                   NO

If we set WITH_V4L=ON, we see in the cmake summary, that:
    Video I/O:
    DC1394:                      YES (2.2.6)
    FFMPEG:                      YES
      avcodec:                   YES (58.91.100)
      avformat:                  YES (58.45.100)
      avutil:                    YES (56.51.100)
      swscale:                   YES (5.7.100)
      avresample:                NO
    GStreamer:                   NO
    v4l/v4l2:                    YES (linux/videodev2.h)





$ sudo make

$ sudo make install

$ pkg-config --modversion opencv # check version installed

When in the qt-creator, we will compile with the default Desktop configuration. 

  In Tools > Options > Kits > Manual > Desktop (default)

    Compiler: C: GCC (C, arm 64bit in /usr/bin)
            C++: GCC (C++,arm 64bit in /usr/bin)



