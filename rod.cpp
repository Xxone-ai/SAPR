#include "rod.h"

Rod::Rod()
{

}

Rod::Rod(QGraphicsRectItem* item, const double &L, const double &A, const double &E, const double &sigma,const double& Q)
{
    item_ = item;
    L_ = L;
    A_ = A;
    E_ = E;
    sigma_ = sigma;
    Q_ = Q;
}

Rod::~Rod()
{

}

double Rod::L() const
{
    return L_;
}

double Rod::A() const
{
    return A_;
}

double Rod::sigma() const
{
    return sigma_;
}

double Rod::E() const
{
    return E_;
}

double Rod::Q() const
{
    return Q_;
}

QGraphicsRectItem *Rod::item() const
{
    return item_;
}

void Rod::setL(const double &L)
{
    L_ = L;
}

void Rod::setA(const double &A)
{
    A_ = A;
}

void Rod::setE(const double &E)
{
    E_ = E;
}

void Rod::setQ(const double &Q)
{
    Q_ = Q;
}

void Rod::setItem(QGraphicsRectItem *item)
{
    item_ = item;
}

void Rod::moveAboutX(const double &shift)
{
    QRectF tempRect;
    tempRect = item_->rect();
    tempRect.moveTo(tempRect.x() - shift, tempRect.y());
    item_->setRect(tempRect);
}

void Rod::setSigma(const double &sigma)
{
    sigma_ = sigma;
}
