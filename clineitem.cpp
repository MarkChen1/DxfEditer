#include "clineitem.h"

CLineItem::CLineItem(const QLineF &line, const QPen &pen)
    : m_line(line)
    , m_pen(pen)
{
    init();
}

CLineItem::CLineItem(const QPointF &p1, const QPointF &p2, const QPen &pen)
    : m_line(p1, p2)
    , m_pen(pen)
{
    init();
}

CLineItem::CLineItem(qreal x1, qreal y1, qreal x2, qreal y2, const QPen &pen)
    : m_line(x1, y1, x2, y2)
    , m_pen(pen)
{
    init();
}

void CLineItem::init()
{
    calcuateRect();
}

QRectF CLineItem::boundingRect() const
{
    return m_rectf;
}

QPainterPath CLineItem::shape() const
{
    QPainterPath path;
    path.addRect(m_rectf);
    return path;
}

void CLineItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->setClipRect( option->exposedRect );
    painter->setPen(m_pen);
    painter->drawLine(m_line);
}

void CLineItem::updateLines()
{
    update();
}

void CLineItem::calcuateRect()
{
    // 计算画线所占矩形坐标
    m_rectf.setWidth(fabs(m_line.x2() - m_line.x1()));
    m_rectf.setHeight(fabs(m_line.y2() - m_line.y1()));
}

void CLineItem::setPen(const QPen &pen)
{
    m_pen = pen;
}

QPen CLineItem::pen() const
{
    return m_pen;
}

void CLineItem::setColor(const QColor &color)
{
    m_pen.setColor(color);
}

QColor CLineItem::color() const
{
    return m_pen.color();
}

void CLineItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mousePressEvent(event);
    update();
}

void CLineItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseMoveEvent(event);
    update();
}

void CLineItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseReleaseEvent(event);
    update();
}
