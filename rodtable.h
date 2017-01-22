#ifndef RODTABLE_H
#define RODTABLE_H

#include <QtWidgets>

class RodTable : public QTableWidget
{
    Q_OBJECT
public:
     RodTable();
protected:
     void contextMenuEvent(QContextMenuEvent *event);
private slots:
     void add();
     void remove();
     void removeAll();
private:
     void createActions();
     QAction *addAct;
     QAction *removeAct;
     QAction *removeAllAct;
signals:
     void addRodSignal();
     void removeRodSignal();
     void removeAllSignal();

};

#endif // RODTABLE_H
