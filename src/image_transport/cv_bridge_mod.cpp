#include "boost/endian/conversion.hpp"
#include <boost/make_shared.hpp>
#include <boost/regex.hpp>

#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <sensor_msgs/image_encodings.h>



sensor_msgs::ImagePtr toImageMsg(const std_msgs::Header& header,const std::string& encoding,const cv::Mat& imag) const
{
  sensor_msgs::ImagePtr ptr = boost::make_shared<sensor_msgs::Image>();
  toImageMsg(*ptr);
  return ptr;
}

void toImageMsg(const std_msgs::Header& header,const std::string& encoding,const cv::Mat& image, sensor_msgs::Image& ros_image) const
{
  ros_image.header = header;
  ros_image.height = image.rows;
  ros_image.width = image.cols;
  ros_image.encoding = encoding;
  ros_image.is_bigendian = (boost::endian::order::native == boost::endian::order::big);
  ros_image.step = image.cols * image.elemSize();
  size_t size = ros_image.step * image.rows;
  ros_image.data.resize(size);

  if (image.isContinuous())
  {
    memcpy((char*)(&ros_image.data[0]), image.data, size);
  }
  else
  {
    // Copy by row by row
    uchar* ros_data_ptr = (uchar*)(&ros_image.data[0]);
    uchar* cv_data_ptr = image.data;
    for (int i = 0; i < image.rows; ++i)
    {
      memcpy(ros_data_ptr, cv_data_ptr, ros_image.step);
      ros_data_ptr += ros_image.step;
      cv_data_ptr += image.step;
    }
  }
}