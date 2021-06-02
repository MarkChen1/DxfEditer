#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H
#include <QGraphicsView>
#include "myopenglwidget.h"

class MyGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    MyGraphicsView(QWidget *parent = nullptr);

protected:
    void resizeEvent( QResizeEvent* pEvent ) override;
    void mousePressEvent( QMouseEvent* pEvent ) override;
    void mouseReleaseEvent( QMouseEvent* pEvent ) override;
    void mouseMoveEvent( QMouseEvent* pEvent ) override;
    void wheelEvent( QWheelEvent* pEvent ) override;

    void drawBackground( QPainter* pPainter, const QRectF& rect ) override;
    void drawForeground(QPainter *painter, const QRectF &rect) override;

public slots:
    void zoomIn();
    void zoomOut();
    void zoom(double scaleFactor);
    void translate(QPointF delta);

private:
    double _zoomDelta;
    double _scale;
    double _moveSpeed;
    QPoint _lBtnDownPos;
    bool   _bLbtnDown;
    MyOpenGlWidget *_wid;
};

#endif // MYGRAPHICSVIEW_H
