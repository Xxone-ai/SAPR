#ifndef RODCREATOR_H
#define RODCREATOR_H

#include <QtWidgets>
#include "rod.h"

class RodCreator : public QWidget
{
    Q_OBJECT
public:
    explicit RodCreator(QWidget *parent = 0);
    ~RodCreator();
private:
    QPushButton* ok;
    QLineEdit* aEdit;
    QLineEdit* eEdit;
    QLineEdit* lEdit;
    QLineEdit* sigmaEdit;
    QLabel* a_lbl;
    QLabel* e_lbl;
    QLabel* l_lbl;
    QLabel* sigma_lbl;
    QLabel* q_lbl;
    QRegularExpression regExp;
    QRegularExpression regExp1;
    QDoubleSpinBox* qValueBox;

signals:
    void sendRodData(const double& L, const double& A, const double& E, const double& sigma, const double& Q);
public slots:
    void okSlot();
    void foo(QString);
};

#endif // RODCREATOR_H
