#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

int main(int argc, char** argv){
    std::string model_xml = "models/MobileNetVLAD/MobileNetVLAD.xml";
    std::string model_bin = "models/MobileNetVLAD/MobileNetVLAD.bin";
    
    cv::dnn::Net net = cv::dnn::readNetFromModelOptimizer(model_xml,model_bin);
    net.setPreferableBackend(cv::dnn::DNN_BACKEND_INFERENCE_ENGINE);
    net.setPreferableTarget(cv::dnn::DNN_TARGET_CPU);//DNN_TARGET_MYRIAD
    cv::Mat img = cv::imread(argv[1], 1);
/*
  CV_EXPORTS_W Mat blobFromImage(InputArray image, double scalefactor=1.0, const Size& size = Size(),
                                   const Scalar& mean = Scalar(), bool swapRB=true, bool crop=true);
*/
    cv::Mat inputBlob = cv::dnn::blobFromImage(img, 0.01712475f, cv::Size(640,480), cv::Scalar(123.675, 116.28, 103.53), true,false);
    net.setInput(inputBlob,"input");//set the network input, "data" is the name of the input layer     
    cv::Mat pred = net.forward("output");
    double freq = cv::getTickFrequency() / 1000;
    std::vector<double> layersTimes;
    double t = net.getPerfProfile(layersTimes) / freq;
    std::cout << "[INFO] network process took " << t << " ms" << std::endl;
    return 0;
}
