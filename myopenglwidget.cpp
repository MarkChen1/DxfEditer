#include "myopenglwidget.h"
#include <QDebug>
#include <QtOpenGL>
#include <QSurfaceFormat>


MyOpenGlWidget::MyOpenGlWidget(QWidget *parent)
    :QOpenGLWidget(parent)
{
    QSurfaceFormat format;
    format.setVersion(3, 3);
    format.setProfile(QSurfaceFormat::CoreProfile);
    setFormat(format);
}

MyOpenGlWidget::~MyOpenGlWidget()
{

}

void MyOpenGlWidget::initializeGL()
{
    QOpenGLFunctions::initializeOpenGLFunctions();
    glClearColor(.5,.5,.8,1);
}

void MyOpenGlWidget::paintGL()
{
    QPainter painter(this);

//     使用OpenGL渲染
    painter.beginNativePainting();
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//    // 绑定着色器程序
//    m_shader->bind();

//    // 设置模型矩阵
//    m_model.setToIdentity();
//    m_model.rotate(m_angle, 0.0f, 1.0f, 0.0f);
//    m_shader->setUniformValue("model", m_model);

//    // 渲染
//    m_texture->bind();
//    m_vao.bind();
    glDrawArrays(GL_TRIANGLES, 0, 36);

    glDisable(GL_DEPTH_TEST);
    painter.endNativePainting();

    // 使用QPainter绘制
    painter.setPen(Qt::green);
    painter.drawText(rect(), QString("Rotation Angle: %1").arg(0));
//    m_angle += 1.5f;

    update();
}

void MyOpenGlWidget::resizeGL(int w, int h)
{

}

void MyOpenGlWidget::paintEvent(QPaintEvent *e)
{
    paintGL();
}
