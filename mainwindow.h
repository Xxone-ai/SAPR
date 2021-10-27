#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QListIterator>
#include <QtWidgets>
#include <QRegularExpression>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QDebug>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    bool validateRodData(QString data);

    bool validateForceData(QString data);

    void draw();

    void addRow(QTableWidget* wgt);

    void addForcesDataInList(QTableWidget* wgt);

    void addRodDataInList();

    bool checkTable(QTableWidget* wgt);
public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:
    void on_addRodButton_clicked();

    void on_deleteRodButton_clicked();

    void on_rodDataTable_itemChanged(QTableWidgetItem *item);

    void on_focusedForces_itemChanged(QTableWidgetItem *item);

    void on_distributedForces_itemChanged(QTableWidgetItem *item);

    void on_leftTerm_clicked();

    void on_rightTerm_clicked();

private:
    Ui::MainWindow *ui;
    QVector<double> rodParams;
    QList <QVector<double>> rods;
    QList <QRect> rects;
    QList<double> focusedForcesList;
    QList<double> distributedForces;
};
#endif // MAINWINDOW_H
