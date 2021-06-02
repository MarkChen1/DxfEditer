#ifndef MYOPENGLWIDGET_H
#define MYOPENGLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class MyOpenGlWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    MyOpenGlWidget(QWidget *parent = nullptr);
    ~MyOpenGlWidget();


    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;

protected:

    void paintEvent(QPaintEvent *e) override;

};


#endif // MYOPENGLWIDGET_H
