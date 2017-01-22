#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include "rod.h"
#include "rodcreator.h"
#include "vertexforcecreator.h"
#include "resulttable.h"
#include "rodtable.h"

namespace Ui {
class MainWindow;
}
const int L_SIZE = 60;
const int A_SIZE = 30;
const int COUNT_PARTS = 20;
const QPen SELECTED_PEN(Qt::blue, 5);
const QPen USUAL_PEN(Qt::black, 5);
const QString NX = "N(x)";
const QString UX = "U(x)";
const QString SIGMAX = "σ(x)";
const double MAX_EPURE_SCALE = 100;
const double MIN_EPURE_SCALE = 10;
const double DEFAULT_EPURE_SCALE = 50;
const qreal FILLING_SHIFT = 3;

struct Vertex
{
    double value;
    QGraphicsPixmapItem* plusForce;
    QGraphicsPixmapItem* minusForce;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    double scale_;
    double epureScale_;
private:
    QToolBar* createToolBar();
    void setPosLeftSupport();
    void setPosRightSupport();
private:
    Ui::MainWindow *ui;
    QVector<Vertex> vertexForces;
    QGraphicsScene* scene;
    QGraphicsView* view;
    QLabel* epureScaleLbl;
    QComboBox* epureSwitcher;
    RodTable* table;
    ResultTable* resultTable;
    QTableWidget* tableForces;
    QVector<Rod*> rods;
    QVector<QGraphicsLineItem*> graphicsSeparators;
    RodCreator* rodCreator;
    VertexForceCreator* vertexForceCreator;
    QGraphicsPixmapItem* leftSupportItem;
    QGraphicsPixmapItem* rightSupportItem;
    QGraphicsLineItem* lineItem;
    QGraphicsLineItem* epureLineX;
    QAction* leftSupportAction;
    QAction* rightSupportAction;
    QAction* zoomInAct;
    QAction* zoomOutAct;
    QToolBar* toolBar;
    QVector<QPoint> vertexForcesPixCoordinates;
    QDir dir;
    QVector< QVector<double> > NxVectors;
    QVector< QVector<double> > uxVectors;
    QVector< QVector<double> > sigmaXVectors;

    QVector< QGraphicsLineItem*> NxFillingItems;
    QVector< QGraphicsLineItem*> NxEpureItems;
    QVector< QGraphicsLineItem*> uxFillingItems;
    QVector< QGraphicsLineItem*> uxEpureItems;
    QVector< QGraphicsLineItem*> sigmaXFillingItems;
    QVector< QGraphicsLineItem*> sigmaXEpureItems;

    QVector< QGraphicsTextItem*> NxTextItems;
    QVector< QGraphicsTextItem*> uxTextItems;
    QVector< QGraphicsTextItem*> sigmaXTextItems;
    double** m_A;
    double** m_b;
    double* delta;
signals:
    void constructionChanged();
public slots:
    void addKernelSlot(const double& L,const double& A, const double& E, const double& sigma, const double& Q);
    void deleteSlot();
    void setLeftSupport();
    void setRightSupport();
    void openVertexForceCreator();
    void openResultTable();
    void setForceSlot(int vertex, double force);
    void calculate();
    void newConstruction();
    void epureSwitcherChangedSlot(QString epureName);
    void deleteAllEpures(bool withoutSeparators = false);
    void currentRodChanged(QTableWidgetItem*, QTableWidgetItem*);
    void clearColorSelection();
    void zoomInEpure();
    void zoomOutEpure();
    QByteArray createFile();
    void save();
private:
    void drawLongForce(QGraphicsRectItem* rectItem ,QString pix);
    void resetA();
    void resetB();
    void resetMatrix(double** matrix, int, int);
    void fillingMatrix(double** matrix, int, int);
    void fillingA();
    void fillingB();
    void considerSupportsForA();
    void considerSupportsForB();
    void Gauss(double* delta, double** matrix, int, int);
    void drawGraphicsSeparators();
    void countNx();
    void countUx();
    void countSigmaX();
    void drawEpureNx(int epureScale);
    void drawEpureUx(int epureScale);
    void drawEpureSigmaX(int epureScale);
protected:
    virtual void closeEvent(QCloseEvent*);
};

#endif // MAINWINDOW_H
