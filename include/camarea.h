#ifndef CAMAREA_H
#define CAMAREA_H
#include <QtOpenGL>

//Forward declarations
class QTimer;
struct CvCapture;
struct _IplImage;

class CamArea: public QGLWidget
{
        Q_OBJECT;

  private:
        QTimer *m_timer;
        CvCapture *m_capture;
        _IplImage *m_image;

  public:
        CamArea(QWidget *parent=NULL);
        ~CamArea();

  protected:
        void initializeGL();
        void paintGL();


  private slots:
        void captureFrame();
};

#endif
