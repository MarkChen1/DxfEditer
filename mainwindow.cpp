#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsView>
#include <QLine>
#include <QGLWidget>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    :QMainWindow(parent)
    ,ui(new Ui::MainWindow)
    ,_dxfReader(new DxfReader())
    ,_pSense(new MyGraphicsScene(this))
{
    ui->setupUi(this);

    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    ui->graphicsView->setScene(_pSense);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnBrowseDxf_clicked()
{
    QString dxfPath = QFileDialog::getOpenFileName(0,
                                                   QObject::tr(u8"图纸选择"),
                                                   QObject::tr("./"),
                                                   "DXF Files(*.dxf)");//图片格式
    if( dxfPath.isEmpty() ) return;

    ui->lineEdit->setText(dxfPath);

    _dxfReader->clear();
    DL_Dxf* dxf = new DL_Dxf();
    if (!dxf->in(dxfPath.toStdString(), _dxfReader)) { // if file open failed
        std::cerr << dxfPath.toStdString() << " could not be opened.\n";
        return;
    }
    delete dxf;

    _pSense->addLines(_dxfReader->getLines());
    _pSense->update();
}
