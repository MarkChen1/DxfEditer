#ifndef DXFREADER_H
#define DXFREADER_H

#include <QObject>
#include "dxflib/dl_dxf.h"
#include "dxflib/dl_creationadapter.h"
#include <QLineF>

class DxfReader : public DL_CreationAdapter
{
public:
    explicit DxfReader();
    ~DxfReader();

    virtual void addLayer(const DL_LayerData& data) override;
    virtual void addPoint(const DL_PointData& data) override;
    virtual void addLine(const DL_LineData& data) override;
    virtual void addArc(const DL_ArcData& data) override;
    virtual void addCircle(const DL_CircleData& data) override;
    virtual void addPolyline(const DL_PolylineData& data) override;
    virtual void addVertex(const DL_VertexData& data) override;

    void clear();

    QList<QLineF> &getLines();
private:
    QList<QLineF> _lines;
//    QList<QPol> _polyLines;

};

#endif // DXFREADER_H
