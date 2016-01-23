// /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ -m32 -Wall -Werror -fpic testLib4Pharo.cpp -shared -o cv2pharo.dylib

// 

extern "C" {

	int pharocv_test() {
		return 42;
	}

}
