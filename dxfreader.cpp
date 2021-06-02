#include "dxfreader.h"
#include <QDebug>


DxfReader::DxfReader()
{

}

DxfReader::~DxfReader()
{

}

void DxfReader::addLayer(const DL_LayerData &data)
{

}

void DxfReader::addPoint(const DL_PointData &data)
{

}

void DxfReader::addLine(const DL_LineData &data)
{
    _lines << QLineF(data.x1, data.y1, data.x2, data.y2);
}

void DxfReader::addArc(const DL_ArcData &data)
{

}

void DxfReader::addCircle(const DL_CircleData &data)
{

}

void DxfReader::addPolyline(const DL_PolylineData &data)
{
//    _polyLines << data;
}

void DxfReader::addVertex(const DL_VertexData &data)
{

}

void DxfReader::clear()
{
    _lines.clear();
    //    _polyLines.clear();
}

QList<QLineF> &DxfReader::getLines()
{
    return _lines;
}
