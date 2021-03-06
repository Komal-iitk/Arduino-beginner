
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>

#include <stdio.h>
#include <iostream>
#include <pthread.h>

using namespace cv;
using namespace std;

VideoCapture cap0(0);
VideoCapture cap1(1);
VideoCapture cap2(2);
VideoCapture cap3(3);

VideoWriter writer0;
VideoWriter writer1;
VideoWriter writer2;
VideoWriter writer3;

Mat frame0[10], frame1[10], frame2[10], frame3[10];
pthread_mutex_t frameLocker0, frameLocker1, frameLocker2, frameLocker3;
pthread_t ProcThread0, ProcThread1, ProcThread2, ProcThread3;
int a=1, b=1, c=1, d=1;

#include "cam.h"

//////////////////////////////////// CAM 0 /////////////////////////////////////////
void *UpdateFrame0(void *arg)
{
while(1)
cam0all();
}
////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////// CAM 1 /////////////////////////////////////////
void *UpdateFrame1(void *arg)
{
while(1)
cam1all();
}
////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////// CAM 2 /////////////////////////////////////////
void *UpdateFrame2(void *arg)
{
while(1)
cam2all();
}
////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////// CAM 3 /////////////////////////////////////////
void *UpdateFrame3(void *arg)
{
while(1)
cam3all();
}
////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////
int main(int, char**) 
{	

cap0.set(3,320);
cap0.set(4,240);

cap1.set(3,320);
cap1.set(4,240);

cap2.set(3,320);
cap2.set(4,240);

cap3.set(3,320);
cap3.set(4,240);

pthread_mutex_init(&frameLocker0,NULL);	
pthread_mutex_init(&frameLocker1,NULL);	
pthread_mutex_init(&frameLocker2,NULL);
pthread_mutex_init(&frameLocker3,NULL);	

pthread_create(&ProcThread0, NULL, UpdateFrame0, NULL);
pthread_create(&ProcThread1, NULL, UpdateFrame1, NULL);
pthread_create(&ProcThread2, NULL, UpdateFrame2, NULL);
pthread_create(&ProcThread3, NULL, UpdateFrame3, NULL);

namedWindow("CAM 0",1);
namedWindow("CAM 1",1);
namedWindow("CAM 2",1);
namedWindow("CAM 3",1);

string filename0="/home/komal/Desktop/Parallel cameras/cam0.avi";
string filename1="/home/komal/Desktop/Parallel cameras/cam1.avi";
string filename2="/home/komal/Desktop/Parallel cameras/cam2.avi";
string filename3="/home/komal/Desktop/Parallel cameras/cam3.avi";

int fcc=CV_FOURCC('D','I','V','3');
int fps=30;	// video is made at 10fps but data rate is at 30fpss
Size frameSize(320,240);

writer0=VideoWriter(filename0,fcc,fps,frameSize);
writer1=VideoWriter(filename1,fcc,fps,frameSize);
writer2=VideoWriter(filename2,fcc,fps,frameSize);
writer3=VideoWriter(filename3,fcc,fps,frameSize);

while(1)
{

Mat currentFrame0, currentFrame1, currentFrame2, currentFrame3;

pthread_mutex_lock(&frameLocker0);
currentFrame0 = frame0[a-1];
pthread_mutex_unlock(&frameLocker0);

pthread_mutex_lock(&frameLocker1);
currentFrame1 = frame1[b-1];
pthread_mutex_unlock(&frameLocker1);

pthread_mutex_lock(&frameLocker2);
currentFrame2 = frame2[c-1];
pthread_mutex_unlock(&frameLocker2);

pthread_mutex_lock(&frameLocker3);
currentFrame3 = frame3[d-1];
pthread_mutex_unlock(&frameLocker3);

if( !currentFrame0.empty() && !currentFrame1.empty() && !currentFrame2.empty() && !currentFrame3.empty() )
{
imshow("CAM 0", currentFrame0);
imshow("CAM 1", currentFrame1);
imshow("CAM 2", currentFrame2);
imshow("CAM 3", currentFrame3);
}

waitKey(1);

}
}

