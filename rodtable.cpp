#include "rodtable.h"

RodTable::RodTable(): QTableWidget()
{
    createActions();
}

void RodTable::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    menu.addAction(addAct);
    menu.addAction(removeAct);
    menu.addSeparator();
    menu.addAction(removeAllAct);
    menu.exec(event->globalPos());
}

void RodTable::add()
{
    emit addRodSignal();
}

void RodTable::remove()
{
    emit removeRodSignal();
}

void RodTable::removeAll()
{
    emit removeAllSignal();
}

void RodTable::createActions()
{
    addAct = new QAction(QIcon(":/resources/images/addIcon.png"),"Add rod", this);
    connect(addAct, SIGNAL(triggered()), this, SLOT(add()));
    removeAct = new QAction(QIcon(":/resources/images/removeIcon.png"),"Remove select rod", this);
    connect(removeAct, SIGNAL(triggered()), this, SLOT(remove()));
    removeAllAct = new QAction(QIcon(""),"Remove all rods", this);
    connect(removeAllAct, SIGNAL(triggered()), this, SLOT(removeAll()));
}
