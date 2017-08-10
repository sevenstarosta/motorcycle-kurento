/* Autogenerated with kurento-module-creator */

#ifndef __OPENCV_ALGORITHM_OPENCV_IMPL_HPP__
#define __OPENCV_ALGORITHM_OPENCV_IMPL_HPP__

#include <OpenCVProcess.hpp>
#include "OpencvAlgorithm.hpp"
#include <EventHandler.hpp>
#include <queue>
#include <fstream>
#include <iostream>
#include <time.h>

#define TRANSIENT_FRAME 50


namespace kurento
{
namespace module
{
namespace opencvalgorithm
{

struct vehicle
{
  //can infer last x and last y during loop, thus do not need to save.
  int initial_y;
  int initial_x;
  int second_x;
  bool type; //default not motorcycle
  bool over_line; //default to already over the line
  vehicle(int y =0, int x=0, int x2=0, bool t=false, bool over=true) : initial_y(y), initial_x(x), second_x(x2), type(t), over_line(over)
  {     
  }
};

class OpencvAlgorithmOpenCVImpl : public virtual OpenCVProcess
{

public:
    //------------------------------PUBLIC METHODS---------------------------
    
    OpencvAlgorithmOpenCVImpl ();
    ~OpencvAlgorithmOpenCVImpl ();
    virtual void process (cv::Mat &mat);
    void setOpencvAlgorithmType(int type);
    void setMaxBufferSize(int size);
    void dealoc();
    void setMaxTimeToRec(int time);
    void setPoints(int x0, int x1,int x2,int x3,int y0,int y1,int y2,int y3, int start);
    
    //------------------------------PUBLIC VARIABLES---------------------------
    
    CodeFound *event;
    bool eventEnable;
    sigc::signal<void, CodeFound> signalCodeFound;
    int timeToRec;
    int TIME_TO_REC;
  
private:

//------------------------------PRIVATE VARIABLES---------------------------
  
  //Variables to controll the buffer
  int MAX_BUFF_SIZE;
  bool recording;
  int start;
  std::queue<cv::Mat*> imgBuffer;
  int transientFrame;
    
  
  //variables to control opencv data
  float frameRate;
  int filter_type, frameCounter, motoCount, zigzagcount, carcount, X_SIZE, Y_SIZE, MAX_WIDTH, MAX_HEIGHT, MIN_HEIGHT, MIN_WIDTH, DETECT_RATE, MAX_ITER, MS_EPSILON, SAVE_RATE, MIN_THRESH, INIT_IMAGES, MIN_VELOCITY;
  time_t _time;
  //double duration;
  double length_kmeters;
  double average_moto_velocity;
  double average_car_velocity;
  std::vector<double> initial_pos, final_pos, moto_velocities, car_velocities, initial_x;
  std::vector<bool> passedVehicles, previousVehicles, vehicleType;
  std::vector<vehicle> vehicles;
  cv::Mat average, frame, dst, fgMask, transform_matrix, inverse_matrix;
  std::vector <cv::Rect> objects;
  std::vector <cv::Point2f> prohibitedAreas;
  
  unsigned char *image_values;
  //may need to be put in process
  cv::TermCriteria criteria;
  int setPointsCounter;
  
    
  //------------------------------PRIVATE METHODS---------------------------
  
  //Methods for manage Events
  void callEvent(std::string type,std::string value);
  bool stopRecord();
  bool startRecord();
  
  //Methods to manage opencv
  void Erosion(cv::Mat &img, int radius);
  void Dilation(cv::Mat &img, int radius);
  void Contours(cv::Mat &img);
  
};

} /* opencvalgorithm */
} /* module */
} /* kurento */

#endif /*  __OPENCV_ALGORITHM_OPENCV_IMPL_HPP__ */
