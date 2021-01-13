// Rotate_Image.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;
int main()
{
    Mat image, rotate;

    image = imread("Resources/image.jpg", 1);
    if (image.empty())
    {
        cout << "Image not found" << endl;
        return -1;
    }

    Point2f center(image.cols / 2.0F, image.rows / 2.0f);
    double angle;
    cout << "Enter the angle" << endl;
    cin >> angle;
    warpAffine(image, rotate, getRotationMatrix2D(center, angle, 0.5), Size(520, 480));

    imshow("Image", image);
    imshow("Rotated", rotate);

    waitKey(0);
    destroyAllWindows();
}