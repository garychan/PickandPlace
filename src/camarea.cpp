#include "camarea.h"

#include <iostream>
#include <QTimer>
#include <QMessageBox>

#include "opencv/highgui.h"

/** \brief Constructor
 *
 * This function initializes the member variables for the CamArea class. In addition
 * the function performs the connection between signals and slots, which in this case is referred
 * to the connection between the timer signal and the capture/drawing slot.
 *
 * \arg parent parent widget.
 *
 */
CamArea::CamArea(QWidget *parent):QGLWidget(parent)
{
    //Initialize variable members
    m_timer = new QTimer();
    m_image = 0;
    m_capture = cvCaptureFromCAM(0);
    if(!m_capture)
        QMessageBox::critical(this,"Error","Error initializing capture from WebCam");

    //Get an initial frame from the webcam
    m_image = cvQueryFrame(m_capture);

    //Connect the timer signal with the capture action
    connect(m_timer, SIGNAL(timeout()), this, SLOT(captureFrame()));

    //Start the timer scheduled for firing every 33ms (30fps)
    m_timer->start(42);
}

/** \brief Destructor
 *
 * This function releases the capture from the webcam by calling
 * the proper OpenCV function.
 */
CamArea::~CamArea()
{
    //Release the capture
    cvReleaseCapture(&m_capture);
}


/** \brief Initialize OpenGL
 *
 * This function is the responsible for setting up the dimensions of the viewport
 * and projection matrix (in this context). Initializes the viewport to the size of
 * the widget and the projection is set up to get a "world" of size 'width' x 'height'
 *
 */
void CamArea::initializeGL()
{
    //Adjust the viewport
    glViewport(0,0,this->width(), this->height());

    //Adjust the projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-this->width()/2, this->width()/2, this->height()/2, -this->height()/2, -1, 1);
}


/** \brief Paint GL
 *
 * This function draws the scene which in this case is the capture from the webcam.
 * in order to adapt the output from the OpenCV's capture, an inversion is needed.
 *
 */
void CamArea::paintGL()
{
    //Clear the color buffer
    glClear(GL_COLOR_BUFFER_BIT);

    //Set the raster position
    /*
      The position seems to be the inverse because the rendering is
      affected by the glPixelZoom call.
     */
    glRasterPos2i(this->width()/2,-this->height()/2);
    //Inver the image (the data coming from OpenCV is inverted)
    glPixelZoom(-1.0f,-1.0f);

    //Draw image from OpenCV capture
    glDrawPixels(m_image->width, m_image->height, GL_BGR_EXT, GL_UNSIGNED_BYTE,m_image->imageData);
}



/** \brief Capture Frame
 *
 * This function performs the capture of a frame from the webcam and
 * calls the function to render the scene.
 *
 */
void CamArea::captureFrame()
{
    //Get an image from the webcam
    m_image = cvQueryFrame(m_capture);

    //Draw horizontal target line
    cvLine(m_image, cvPoint(310,240), cvPoint(330,240), cvScalar(0,0,255), 1);

    //Draw vertical target line
    cvLine(m_image, cvPoint(320,230), cvPoint(320,250), cvScalar(0,0,255), 1);

    //Draw the scene
    glDraw();
}

