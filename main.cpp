#include <QCoreApplication>
#include <opencv2/highgui.hpp>
#include <opencv2/stitching.hpp>
#include <opencv2/imgcodecs.hpp>
#include <QDebug>
#include <QString>
#include <QImage>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cv::Mat result;
    QString dest = "C:/Users/Pawel/Desktop/result.png";
    std::vector<cv::Mat> imgs;
    imgs.push_back(cv::imread("C:/Users/Pawel/Desktop/test5.png"));
    imgs.push_back(cv::imread("C:/Users/Pawel/Desktop/test6.png"));
    imgs.push_back(cv::imread("C:/Users/Pawel/Desktop/test7.png"));
//    imgs.push_back(cv::imread("C:/Users/Pawel/Desktop/test8.png"));
    cv::Ptr<cv::Stitcher> stitcher = cv::Stitcher::create(cv::Stitcher::PANORAMA, false);
    cv::Stitcher::Status status = stitcher->stitch(imgs, result);
    if (status != cv::Stitcher::OK){
        qDebug() << "failure!";
        return -1;
    }
    cv::cvtColor(result, result, CV_BGR2RGB);
    QImage output(result.data, result.cols, result.rows, QImage::Format_RGB888);
    cv::Mat temp = cv::Mat(output.height(), output.width(), CV_8UC(3), output.bits(), output.bytesPerLine());
    cv::cvtColor(temp, temp, CV_RGB2BGR);
//    output.save(dest);
    bool succes = cv::imwrite(dest.toStdString(), temp);
    if (succes){
        qDebug() << "succes!";
    }else{
        qDebug() << "failure!";
    }

    return a.exec();
}
