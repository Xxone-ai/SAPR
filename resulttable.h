#ifndef RESULTTABLE_H
#define RESULTTABLE_H

#include <QtWidgets>
#include "rod.h"
class ResultTable : public QWidget
{
    Q_OBJECT
public:
    explicit ResultTable(QWidget *parent = 0);
    ~ResultTable();
private:
    QTableWidget* table;
    QComboBox* rodBox;
    QLabel* rodLbl;
    QLabel* sectionLbl;
private:
    QVector<QVector<double> > Nx_;
    QVector<QVector<double> > Ux_;
    QVector<QVector<double> > sigmaX_;
    QVector<Rod*> rods_;
signals:
    void deleteSignal();
public slots:
    void setRodFilter(int rodIndex);
public:
    void setRodList(const QStringList& list);
    void setData(const QVector<QVector<double> > &Nx, const QVector<QVector<double> > &Ux, const QVector<QVector<double> > &sigmaX, const QVector<Rod*>& rods);
protected:
    virtual void closeEvent(QCloseEvent*);

};

#endif // RESULTTABLE_H
