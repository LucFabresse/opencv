/*
/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ \
-m32 \
-I./include/ \
-L ./lib/ \
-lopencv_core \
-lopencv_imgproc \
-lopencv_imgcodecs \
test.cpp
*/

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include <iostream>

int main( int argc, char** argv )
{
    char* filename = (char*) "lenna.png";
    cv::Mat gray, image = cv::imread(filename, 1);

    if( image.empty() )
    {
        std::cout << "Image empty not found\n";
        return 0;
    }

	 std::cout << sizeof(image) << std::endl;
	 
    cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);

	 std::cout << sizeof(gray) << std::endl;
	 
    cv::imwrite("lenna_gray.jpg",gray);
	 
    return 0;
}
