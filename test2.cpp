#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;

bool ok = false;
int p1 = 0;
int q1 = 0;
int p2 = 0;
int q2 = 0;
int rank = 0;


static void onMouse(int event, int x, int y, int,void*) {
    cout << "gaga";
    if (event != CV_EVENT_LBUTTONDOWN)
		return;
    cout << x << ' ' << y << endl;
    if (rank == 0) {
        p1 = x;
        q1 = y;
        rank ++;
    }
    else if (rank == 1) {
        p2 = x;
        q2 = y;
        rank ++;
    }
    else if (rank >= 2) {
        ok = true;
    }
}


int main() {
    Mat image = imread("left01.jpg");
    namedWindow("image");
    imshow("image", image);
    waitKey(30);
    setMouseCallback("image", onMouse);

    while (!ok) {
        imshow("image", image);
    }
    
    int tmp = 0;
    if (p1 > p2) {
        tmp = p1;
        p1 = p2;
        p2 = tmp;
    }
    if (q1 > q2) {
        tmp = q1;
        q1 = q2;
        q2 = tmp;
    }

    cout << q1 << ' ' << q1 << '\n'
         << q2 << ' ' << q2 << endl;

    cout << image.type() << endl;
    
    /*
    int width = image.width;
    int height = image.height;
    for (int i = 0; i < width; i ++) {
        for (int j = 0; j < height; j ++) {
            if (i >= x1 && i < x2 && j >= y1 && j < y2) 
                continue;
            image.data[i][j] = 
    */
    return 0;
}
    












        
