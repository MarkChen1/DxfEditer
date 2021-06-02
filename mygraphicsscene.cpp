#include "mygraphicsscene.h"

MyGraphicsScene::MyGraphicsScene(QWidget *parent)
    :QGraphicsScene(parent)
{
}

MyGraphicsScene::~MyGraphicsScene()
{

}

void MyGraphicsScene::addLines(QList<QLineF> &lines)
{
    for(auto &line : lines)
    {
        addLine(line, QPen(QColor(200,0,0)));
    }
}
