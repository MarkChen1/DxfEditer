#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dxfreader.h"
#include "mygraphicsscene.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnBrowseDxf_clicked();

private:
    Ui::MainWindow *ui;
    DxfReader *_dxfReader;
    MyGraphicsScene *_pSense;
};

#endif // MAINWINDOW_H
