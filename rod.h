#ifndef ROD_H
#define ROD_H

#include <QtWidgets>


class Rod
{

private:
    double L_;
    double A_;
    double sigma_;
    double E_;
    QGraphicsRectItem* item_;

    double Q_;

public:
    Rod();
    Rod(QGraphicsRectItem* item,const double& L,const double& A,const double& E,const double& sigma, const double& Q);
    ~Rod();
    double L() const;
    double A() const;
    double sigma() const;
    double E() const;
    double Q() const;
    QGraphicsRectItem* item() const;
    void setL(const double& L);
    void setA(const double& A);
    void setSigma(const double& sigma);
    void setE(const double& E);
    void setQ(const double& Q);
    void setItem(QGraphicsRectItem* item);
    void moveAboutX(const double& shift);
};

#endif // ROD_H
