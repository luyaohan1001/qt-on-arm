# Download opencv 3.4.1 source:
		https://github.com/opencv/opencv/releases/tag/3.4.1

		$ tar xf opencv-3.4.1.tar.gz

		$ cd opencv-3.4.1

		$ sudo apt-get install cmake

		$ mkdir build && cd build


		# cmake will look for stuff on the last level directory and make into 'build' folder
		$ cmake..

			Expect the following:

				...... 
				--   Matlab:                        NO
				-- 
				--   Install to:                    /usr/local
				-- -----------------------------------------------------------------
				-- 
				-- Configuring done
				-- Generating done
				-- Build files have been written to: /home/luyaohan1001/Projects/qt-on-arm/opencv-source/opencv-3.4.1/build

		$ make -j 16
	
			Expect the following:
				......
				[ 97%] Building CXX object modules/imgproc/CMakeFiles/opencv_perf_imgproc.dir/perf/perf_phasecorr.cpp.o
				[ 97%] Linking CXX executable ../../bin/opencv_test_features2d
				......
				[ 97%] Building CXX object modules/imgproc/CMakeFiles/opencv_test_imgproc.dir/test/test_resize_bitexact.cpp.o
				......
				[ 98%] Building CXX object modules/imgproc/CMakeFiles/opencv_perf_imgproc.dir/perf/opencl/perf_accumulate.cpp.o
				[ 99%] Building CXX object modules/imgproc/CMakeFiles/opencv_test_imgproc.dir/test/test_canny.cpp.o
				......
				[100%] Built target opencv_perf_core
				[100%] Linking CXX shared module ../../lib/python3/cv2.cpython-35m-x86_64-linux-gnu.so
				[100%] Built target opencv_python3

		$ sudo make install 

			Expect the following

				......
				-- Installing: /usr/local/share/OpenCV/lbpcascades/lbpcascade_frontalface_improved.xml
				-- Installing: /usr/local/share/OpenCV/lbpcascades/lbpcascade_frontalface.xml
				-- Installing: /usr/local/bin/opencv_traincascade
				-- Set runtime path of "/usr/local/bin/opencv_traincascade" to "/usr/local/lib"
				-- Installing: /usr/local/bin/opencv_createsamples
				-- Set runtime path of "/usr/local/bin/opencv_createsamples" to "/usr/local/lib"
				-- Installing: /usr/local/bin/opencv_annotation
				-- Set runtime path of "/usr/local/bin/opencv_annotation" to "/usr/local/lib"
				-- Installing: /usr/local/bin/opencv_visualisation
				-- Set runtime path of "/usr/local/bin/opencv_visualisation" to "/usr/local/lib"
				-- Installing: /usr/local/bin/opencv_interactive-calibration
				-- Set runtime path of "/usr/local/bin/opencv_interactive-calibration" to "/usr/local/lib"
				-- Installing: /usr/local/bin/opencv_version
				-- Set runtime path of "/usr/local/bin/opencv_version" to "/usr/local/lib"


		# The opencv related library is installed in /usr/local/lib and /usr/local/include for any purpose of QT.



	
