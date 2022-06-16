#ifndef MAINWINDOW_H
#define MAINWINDOW_H
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)

#include <QtWidgets/QMainWindow>
#include "qcustomplot.h" 

enum shape_enum {None, MaxflatFIR, GaussianFIR, RemezFIR, SincFIR,
								 RaisedCosine, RootRaisedCosine};

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT
  
public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  
  void setup(QCustomPlot *customPlot);
  void plot2(QCustomPlot *customPlot);
  void plot3(QCustomPlot *customPlot);
  
private:
  Ui::MainWindow *ui;
  QString demoName;
  QCPItemTracer *itemDemoPhaseTracer;

public slots:
  void BoxChecked(bool);
  void BChanged();
  void CChanged(); 
  void GChanged(); 
  void EChanged(); 
  void FChanged(); 
  void FHChanged(); 
  void RCChanged(); 
  void RRCChanged(); 
  void RChanged(); 
  void SChanged(); 
  void CBChanged(); 
  void graphPressEvent(QMouseEvent *event);
  void graphMoveEvent(QMouseEvent *event);
  void updatePlot();

private:
  int pts;
  std::string shape;
  double* w;

  QCPGraph*  MaxflatFIR_on;
  QCPGraph*  RaisedCosine_on;
  QCPGraph*  RootRaisedCosine_on;
  QCPGraph*  Remez_on;
  QCPGraph*  Gaussian_on;
  QCPGraph*  Sinc_on;
  int graph_counter;

  QPoint dragStartPosition;
  QCPGraph* GetPtr();

};

#endif // MAINWINDOW_H
