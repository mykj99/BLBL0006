#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	Mat src1, src2, dst;
	double alpha=0.9, beta=1-alpha;
	double gamma = 1;

	src1=imread("c:/demo/Linuxlogo.jpg");
	src2 = imread("c:/demo/windowslogo.jpg");

	if (!src1.data || !src2.data)
	{
		cout << "cannot open image file" << endl;
		return -1;
	}
	if (src1.size() == src2.size())
	{
		addWeighted(src1, alpha, src2, beta, gamma, dst);
		//dst = saturate_cast(dst);
		imshow("src1", src1);
		imshow("src2", src2);
		imshow("dst", dst);
	}
	else
	{
		cout << "the two images have different size" << endl;
		return -1;
	}
	waitKey(0);
	return 0;
}

