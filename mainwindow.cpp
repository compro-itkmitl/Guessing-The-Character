#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QImage>
#include <QPixmap>
#include <stdio.h>
#include <leptonica/allheaders.h>
#include <tesseract/capi.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;

void check(const char *errstr) {
    fputs(errstr, stderr);
    exit(1);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    handle = TessBaseAPICreate();
    if(TessBaseAPIInit3(handle, NULL, "eng") != 0)
        check("Error initialising tesseract\n");

    capWebcam.open(2);


    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(processFrameAndUpdateGUI()));
    timer->start(20);
    cout << "Init Success\n";

}

void MainWindow::processFrameAndUpdateGUI() {
    capWebcam.read(frame);

    if(frame.empty() == true) return;

    cv::imwrite("gray.png", frame);
    //QImage qimage((uchar*)frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);
    QImage qiimage("gray.png");

     ui->cameraFrame->setPixmap(QPixmap::fromImage(qiimage));

    if(count==100){
         if((img = pixRead("gray.png")) == NULL)
            check("Error Reading image\n");

        TessBaseAPISetImage2(handle, img);

        //check recognize
        if(TessBaseAPIRecognize(handle, NULL) != 0)
            check("Error in Tesseract recognition\n");

        //check text
        if((text = TessBaseAPIGetUTF8Text(handle)) == NULL)
            check("Error Getting text\n");

        ui->textBox->setText(text);
        count = 0;
    }
    count++;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_PauseOrResumeBtn_clicked()
{
    if(timer->isActive() == true){
        timer->stop();
        ui->PauseOrResumeBtn->setText("Resume");
    }else{
        timer->start(20);
        ui->PauseOrResumeBtn->setText("Pause");
    }
}
