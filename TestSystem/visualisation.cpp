#include "testui.h"

Visualisation::Visualisation(shared_ptr<DataStorage> strg)
    :IWidget(strg)
{
    shared_ptr<QLabel> txtedit = make_shared<QLabel>("График синуса");
    addWidget(txtedit,QRect(0,0,100,60));
    addLayout(make_shared<QGridLayout>());
    shared_ptr<QCustomPlot> cplot = make_shared<QCustomPlot>();
    cplot.get()->addGraph();
    cplot->graph(0)->setPen(QPen(Qt::blue));
    cplot->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));
    QVector<double> x(251), y(251);
    for (int i=0; i<251; ++i)
    {
      x[i] = i;
      y[i] = sin(qRadiansToDegrees((double)i));
    }
    cplot->xAxis2->setVisible(true);
    cplot->yAxis2->setVisible(true);
    cplot->graph(0)->setData(x, y);
    cplot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    cplot->graph(0)->rescaleAxes(true);
    cplot->setMinimumSize(QSize(300,280));
    cplot->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    addWidget(cplot,QRect(0,0,100,60),0,0,2);
}
