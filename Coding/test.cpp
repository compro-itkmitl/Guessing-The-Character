#include "opencv2/opencv.hpp"
#include <opencv2/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/ml/ml.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace cv;

int main(){
    static const int intValidChars[] = { '0', '1', '2', '3', '4', '5', '6', '7',
    '8', '9', 'A', 'B', 'C', 'D', 'E', 'F',
    'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
    'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
    'W', 'X', 'Y', 'Z' };
    int n = sizeof(intValidChars) / sizeof(intValidChars[0]);
    vector<int> vect(intValidChars, intValidChars + n);
    VideoCapture cap(0);
    while(1){
        Mat frame, a;
        Mat thresh, threshCopy;
        vector<std::vector<cv::Point> > ptContours;
        std::vector<cv::Vec4i> v4iHierarchy;
        cap >> frame;
        Mat gray;
        cvtColor(frame, gray, CV_RGB2GRAY);
        GaussianBlur(gray, gray, Size(5, 5), 0, 0);
        adaptiveThreshold(gray, thresh, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 11, 2);
        threshCopy = thresh.clone();
        findContours(threshCopy, ptContours, v4iHierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point(0,0));
        for(int i=0;i < ptContours.size();i++){
            if(contourArea(ptContours[i])>100){
                Rect bounding  = boundingRect(ptContours[i]);
                rectangle(frame, bounding, Scalar(0, 0, 255), 2);
                Mat matROI = thresh(bounding);
                Mat matROIResized;
                resize(matROI, matROIResized, Size(20, 30));
            }
        }
        putText(frame, format("Fighting!!"), Point(10, 50), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255), 4);
        imshow("frame", frame);
        char c = (char)waitKey(1);
        if( c == 27 )
            break;
    }
    destroyAllWindows();
    return 0;
}
