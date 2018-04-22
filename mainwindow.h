    #ifndef MAINWINDOW_H
    #define MAINWINDOW_H

    #include <QMainWindow>
    #include <QTimer>
    #include <stdio.h>
    #include <leptonica/allheaders.h>
    #include <tesseract/capi.h>
    #include <opencv2/opencv.hpp>
    #include <opencv2/core.hpp>
    #include <opencv2/highgui/highgui.hpp>
    #include <opencv2/imgproc/imgproc.hpp>
    #include <iostream>

    namespace Ui {
    class MainWindow;
    }

    class MainWindow : public QMainWindow
    {
        Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = 0);
        TessBaseAPI *handle;
        PIX *img;
        int count = 0;
        ~MainWindow();

    private slots:
        void on_PauseOrResumeBtn_clicked();

    public slots:
        void processFrameAndUpdateGUI();

    private:
        Ui::MainWindow *ui;
        cv::VideoCapture capWebcam;
        cv::Mat frame;

        QTimer* timer;
        char* text;
    };

    #endif // MAINWINDOW_H
