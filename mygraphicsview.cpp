#include "mygraphicsview.h"
#include <QResizeEvent>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QPainter>
#include <QMessageBox>

MyGraphicsView::MyGraphicsView(QWidget *parent)
    :QGraphicsView(parent)
    ,_scale(1.0)
    ,_zoomDelta(0.1)
    ,_moveSpeed(1.0)
    ,_bLbtnDown(false)
    ,_wid(new MyOpenGlWidget(this))
{
    //去掉滚动条
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setRenderHint(QPainter::Antialiasing);

    centerOn(0,0);

    _wid->makeCurrent();
    QSurfaceFormat format;
    format.setSamples(4);
    _wid->setFormat(format);

    setViewport(_wid);
}

void MyGraphicsView::resizeEvent(QResizeEvent *pEvent)
{
    scene( )->setSceneRect( 0.0,
                            0.0,
                            pEvent->size( ).width( ),
                            pEvent->size( ).height( ) );
    pEvent->accept( );
}


void MyGraphicsView::mousePressEvent( QMouseEvent* pEvent )
{
    QGraphicsView::mousePressEvent( pEvent );

    if(pEvent->button() == Qt::LeftButton)
    {
        if(scene()->itemAt(mapToScene(pEvent->pos()), transform()) == nullptr) // 没有点中图元
        {
            _lBtnDownPos = pEvent->pos();
            _bLbtnDown = true;
        }
    }
}
/*---------------------------------------------------------------------------*/
void MyGraphicsView::mouseMoveEvent( QMouseEvent* pEvent )
{
    QGraphicsView::mouseMoveEvent( pEvent );

    if(_bLbtnDown)
    {
        QPointF ptMoveStart = mapToScene(_lBtnDownPos);
        QPointF ptMoveTo = mapToScene(pEvent->pos());
        QPointF moveDelta = ptMoveStart - ptMoveTo;
        translate(moveDelta);
    }
}
/*---------------------------------------------------------------------------*/
void MyGraphicsView::mouseReleaseEvent( QMouseEvent* pEvent )
{
    if(pEvent->button() == Qt::LeftButton)
    {
        _bLbtnDown = false;
    }

    QGraphicsView::mouseReleaseEvent( pEvent );
}
/*---------------------------------------------------------------------------*/
void MyGraphicsView::wheelEvent( QWheelEvent* pEvent )
{
    QPoint scrollAmount = pEvent->angleDelta(); //鼠标滚动量
    scrollAmount.y() > 0 ? zoomIn() :zoomOut();
}

void MyGraphicsView::drawBackground(QPainter *pPainter, const QRectF &rect)
{

}

void MyGraphicsView::drawForeground(QPainter *painter, const QRectF &rect)
{

}

void MyGraphicsView::zoomIn()
{
    zoom(1 + _zoomDelta);
}

void MyGraphicsView::zoomOut()
{
    zoom(1 - _zoomDelta);
}

void MyGraphicsView::zoom(double scaleFactor)
{
    double factor = transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0,0,1,1)).width();
    if(factor<0.07 || factor>100)
        return;

    scale(scaleFactor, scaleFactor);
    _scale *= scaleFactor;
}

void MyGraphicsView::translate(QPointF delta)
{
    delta *= _scale;
    delta *= _moveSpeed;

    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);

    QPoint newCenter(viewport()->rect().width()/2 - delta.x(), viewport()->rect().height()/2 - delta.y());
    centerOn(mapToScene(newCenter));

    setTransformationAnchor(QGraphicsView::AnchorViewCenter);
}
