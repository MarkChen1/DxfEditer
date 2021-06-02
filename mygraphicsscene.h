#ifndef MYGRAPHICSSCENE_H
#define MYGRAPHICSSCENE_H

#include <QWidget>
#include <QGraphicsScene>

class MyGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    MyGraphicsScene(QWidget* parent = nullptr);
    ~MyGraphicsScene();

    void addLines(QList<QLineF> &lines);
};

#endif // MYGRAPHICSSCENE_H
