// /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ -m32 -shared -Wall -Werror -fpic -I./include/ -L ./lib/ -lopencv_core -lopencv_imgproc -lopencv_imgcodecs cv2pharo.cpp -o cv2pharo.dylib

#define EXPORT_TO_PHARO	extern "C" 

#include <iostream>
#include <string>

// *******************************************************************************
// TO BE GENERATED
// *******************************************************************************
// Mat& img = *((Mat*)img_nativeObj);

// All parsed include?
#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"

EXPORT_TO_PHARO cv::Mat pharocv_imread(const char* cfilename, const int flags) {
	std::string filename(cfilename);
	return cv::imread(filename,flags);	
}

//C++: bool imwrite(const string& filename, InputArray img, const vector<int>& params=vector<int>() )
EXPORT_TO_PHARO int pharocv_imwrite(const char* cfilename, const cv::Mat p_mat) {
	std::string filename(cfilename);
	std::cout << filename << std::endl;	
	return cv::imwrite(filename,p_mat);
}

// C++: void cvtColor(InputArray src, OutputArray dst, int code, int dstCn=0 )
EXPORT_TO_PHARO void pharocv_cvtColor(const cv::Mat p_src, cv::Mat& p_dst, const int code) {
	cv::cvtColor(p_src,p_dst,code);
}

// *******************************************************************************

struct toto {
	long l;
	long l2;
};

int main( int argc, char** argv )
{
	
	std::cout << "sizeof(cv::Mat) = " << sizeof(cv::Mat) << std::endl; 
	std::cout << "sizeof(cv::Ptr<cv::Mat>) = " << sizeof(cv::Ptr<cv::Mat>) << std::endl; 
	std::cout << "sizeof(cv::Ptr<cv::Point>) = " << sizeof(cv::Ptr<cv::Point>) << std::endl; 
	std::cout << "sizeof(long long) = " << sizeof(long long) << std::endl; 
	std::cout << "sizeof(struct toto) = " << sizeof(struct toto) << std::endl; 
	 
	 
	 const std::string f("lenna.png");
    // cv::Mat m = cv::imread(f,1);
    cv::Mat m = pharocv_imread(f.c_str(),1);
	 
	 if(m.empty()) {
		 std::cout << "error imread" << std::endl; 
		return 1; }
	 
    cv::Mat gray;
	 pharocv_cvtColor(m, gray, cv::COLOR_BGR2GRAY);
	 
	 const std::string fd("lenna_gray.jpg");
    pharocv_imwrite(fd.c_str(),gray);

    return 0;
}
