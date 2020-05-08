#ifndef CV_BRIDGE_CV_BRIDGE_H
#define CV_BRIDGE_CV_BRIDGE_H

#include <sensor_msgs/Image.h>
#include <sensor_msgs/CompressedImage.h>
#include <sensor_msgs/image_encodings.h>
#include <ros/static_assert.h>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgproc/types_c.h>
#include <stdexcept>

sensor_msgs::ImagePtr toImageMsg(const std_msgs::Header& header,const std::string& encoding,const cv::Mat& imag);

void toImageMsg(const std_msgs::Header& header,const std::string& encoding,const cv::Mat& image, sensor_msgs::Image& ros_image);

#endif