#ifndef CGRAPHICSLINEITEM_H
#define CGRAPHICSLINEITEM_H

#include <QGraphicsLineItem>

class CGraphicsLineItem : public QGraphicsLineItem
{
public:
    explicit CGraphicsLineItem(QLineF line);
};

#endif // CGRAPHICSLINEITEM_H
