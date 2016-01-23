// /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ -m32 -Wall -Werror -fpic -I./include/ -L ./lib/ -lopencv_core -lopencv_imgproc -lopencv_imgcodecs cv2pharo.cpp -shared -o cv2pharo.dylib

// 

// #define EXPORT_TO_PHARO	extern "C"
// #define EXPORT_TO_PHARO

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

using namespace cv;
using namespace std;


extern "C" {

cv::Ptr<cv::Mat> pharocv_imread(const char* cfilename, int flags) {
	std::string filename(cfilename);
	
	Mat m = cv::imread(filename,flags);
	
	Mat* temp = new Mat(m);
	
	cv::Ptr<cv::Mat> p_m(temp);
	
	return p_m;
}

//C++: bool imwrite(const string& filename, InputArray img, const vector<int>& params=vector<int>() )
void pharocv_imwrite(const char* cfilename, cv::Ptr<cv::Mat> p_mat) {
	std::string filename(cfilename);
	cv::imwrite(filename,*p_mat);
}

// C++: void cvtColor(InputArray src, OutputArray dst, int code, int dstCn=0 )
// EXPORT_TO_PHARO void pharocv_cvtColor(cv::Ptr<cv::Mat> p_src, cv::Ptr<cv::Mat> p_dst, int code) {
// 	cv::cvtColor(*p_src,*p_dst,code);
// }

cv::Ptr<cv::Mat> pharocv_cvtColor(cv::Ptr<cv::Mat> p_src, int code) {

 	Mat* matres = new Mat();
	cv::cvtColor(*p_src,*matres,code);
	
	cv::Ptr<cv::Mat> res(matres);
	return res;
}

int pharocv_test() {
	return 42;
}

cv::Ptr<cv::Mat> pharocv_testPtr() {
	cv::Ptr<cv::Mat> res;
	return res;
}


}
//
// int main( int argc, char** argv )
// {
// 	 const std::string f("lenna.png");
//
//     cv::Ptr<cv::Mat> m = pharocv_imread(f.c_str(),1);
//
// 	 if(m->empty()) {
//  	 	std::cout << "error imread" << std::endl;
//  	 	return 1;
// 	 }
//
//     cv::Ptr<cv::Mat> gray = pharocv_cvtColor(m, cv::COLOR_BGR2GRAY);
//
// 	 const std::string fd("lenna_gray.jpg");
//     pharocv_imwrite(fd.c_str(),gray);
//
//     return 0;
// }

