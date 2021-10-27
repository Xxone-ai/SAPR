#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->rodDataTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->focusedForces->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->distributedForces->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::validateRodData(QString data)
{
    if(data.toDouble() && data.toDouble() >= 0)
        return true;
    else
        return false;
}

bool MainWindow::validateForceData(QString data)
{
    if(data.toDouble())
        return true;
    else
        return false;
}

void MainWindow::addRow(QTableWidget* wgt)
{
    QTableWidgetItem* tmp = new QTableWidgetItem();
    wgt->insertRow(wgt->rowCount());
    for(int i = 0; i <  wgt->columnCount(); ++i)
    {
        continue;
        wgt->setItem(ui->rodDataTable->rowCount() - 1, i, tmp);
    }
    delete tmp;
}

void MainWindow::on_addRodButton_clicked()
{
    addRow(ui->rodDataTable);
    addRow(ui->focusedForces);
    addRow(ui->distributedForces);
    if(ui->rodDataTable->rowCount() == 1)
        ui->deleteRodButton->setEnabled(false);
    else
       ui->deleteRodButton->setEnabled(true);
}

void MainWindow::on_deleteRodButton_clicked()
{
    if(rods.size() == ui->rodDataTable->rowCount())
        rods.removeLast();
    if(focusedForcesList.size() == ui->focusedForces->rowCount())
        focusedForcesList.removeLast();
    if(distributedForces.size() == ui->distributedForces->rowCount())
        distributedForces.removeLast();
    ui->rodDataTable->removeRow((ui->rodDataTable->rowCount())-1);
    ui->focusedForces->removeRow(ui->focusedForces->rowCount()-1);
    ui->distributedForces->removeRow(ui->distributedForces->rowCount()-1);
    if(ui->rodDataTable->rowCount() == 1)
        ui->deleteRodButton->setEnabled(false);
    else
       ui->deleteRodButton->setEnabled(true);
    draw();
}


void MainWindow::on_rodDataTable_itemChanged(QTableWidgetItem *item)
{
    QString data = item->text();
    if(validateRodData(data))
        item->setBackground(Qt::green);
    else
    {
        item->setBackground(Qt::red);
        item->setText("1");
    }
   if(checkTable(this->ui->rodDataTable))
   {
       rods.clear();
       for(int i = 0; i < ui->rodDataTable->rowCount(); i++)
       {
            for(int j = 0; j < ui->rodDataTable->columnCount(); j++)
            {
                    this->rodParams.push_back(ui->rodDataTable->item(i,j)->text().toDouble());
            }
            if(rodParams.size() == 4)
                this->rods.push_back(rodParams);
            rodParams.clear();
       }
   }
}

bool MainWindow::checkTable(QTableWidget *wgt)
{
    for(int i = 0; i < wgt->rowCount(); i++)
    {
        for(int j = 0; j < wgt->columnCount(); j++)
        {
           if(wgt->item(i, j)!=nullptr)
           {
                if(wgt->item(i, j)->text().isEmpty())
                     return false;
           }
           else return false;
        }
    }
    return true;
}

void MainWindow::on_focusedForces_itemChanged(QTableWidgetItem *item)
{
    QString data = item->text();
    if(validateForceData(data) == true)
    {
        item->setBackground(Qt::green);
    }
    else
    {
        //item->setBackground(Qt::red);
        item->setData(0, QString::number(0));
    }
    if(checkTable(this->ui->focusedForces))
    {
        focusedForcesList.clear();
        for(int i = 0; i < ui->focusedForces->rowCount(); i++)
        {
             for(int j = 0; j < ui->focusedForces->columnCount(); j++)
             {
                 this->focusedForcesList.push_back(ui->focusedForces->item(i,j)->text().toDouble());
             }
        }
    }

}

void MainWindow::on_distributedForces_itemChanged(QTableWidgetItem *item)
{
    QString data = item->text();
    if(validateForceData(data) == true)
    {
        item->setBackground(Qt::green);
    }
    else
    {
        item->setBackground(Qt::red);
        item->setData(0, QString::number(0));
    }
    if(checkTable(ui->distributedForces))
    {
        distributedForces.clear();
        for(int i = 0; i < ui->distributedForces->rowCount(); i++)
        {
            for(int j = 0; j < ui->distributedForces->columnCount(); j++)
            {
                     this->distributedForces.push_back(ui->distributedForces->item(i,j)->text().toDouble());
            }
        }
    }
}



void MainWindow::draw()
{
    QGraphicsScene *scene = new QGraphicsScene(this);
    QList<QRect> rects;
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);

    double x = 0;
    double y = 0;
    double height = 40;
    double widht = 150;
    for(int i = 0; i < this->rods.size(); i++)
    {
         if(i == 0)
         {
             QRect rect = QRect(x, y, widht*rods[i][0], height*rods[i][1]);
             rects.push_back(rect);
             scene->addRect(rect, QPen(Qt::black, 4));
             x+=widht*rods[i][0];

         }
         else
         {
             y= rects[i-1].center().y()-height*rods[i][1]/2;
             QRect rect = QRect(x, y, widht*rods[i][0], height*rods[i][1]);
             rects.push_back(rect);
             scene->addRect(rect, QPen(Qt::black, 4));
             x+=widht*rods[i][0];
         }
    }
    ui->graphicsView->setScene(scene);
    if(ui->leftTerm->isChecked())
    {
        QGraphicsPixmapItem* leftTerm = scene->addPixmap(QPixmap("C:/Qt/SAPR/res/images/leftTerm.png"));
        leftTerm->setPos(rects.first().bottomLeft().x()-leftTerm->pixmap().width(), rects.first().center().y()-leftTerm->pixmap().height()/2);
        leftTerm->show();
    }
    if(ui->rightTerm->isChecked())
    {
        QGraphicsPixmapItem* rightTerm = scene->addPixmap(QPixmap("C:/Qt/SAPR/res/images/rightTerm.png"));
        rightTerm->setPos(rects.last().bottomRight().x(), rects.first().center().y()-rightTerm->pixmap().height()/2);
        rightTerm->show();
    }


    for(int i = 0; i < focusedForcesList.size(); i++)
    {
        if (i!=rods.size())
        {
            if(focusedForcesList[i] < 0)
            {
                QGraphicsPixmapItem* focusedForceLeft = scene->addPixmap(QPixmap("C:/Qt/SAPR/res/images/focusedForceLeft.png"));
                focusedForceLeft->setPos(rects[i].bottomLeft().x(), rects[i].center().y()-focusedForceLeft->pixmap().height()/2);
            }
            else if(focusedForcesList[i] > 0)
            {
                QGraphicsPixmapItem* focusedForceRight = scene->addPixmap(QPixmap("C:/Qt/SAPR/res/images/focusedForceRight.png"));
                focusedForceRight->setPos(rects[i].bottomLeft().x(), rects[i].center().y()-focusedForceRight->pixmap().height()/2);
            }
        }
        else
        {
            if(focusedForcesList[i] < 0)
            {
                QGraphicsPixmapItem* focusedForceLeft = scene->addPixmap(QPixmap("C:/Qt/SAPR/res/images/focusedForceLeft.png"));
                focusedForceLeft->setPos(rects.last().bottomRight().x()-focusedForceLeft->pixmap().width(), rects.last().center().y()-focusedForceLeft->pixmap().height()/2);
            }
            else if(focusedForcesList[i] > 0)
            {
                QGraphicsPixmapItem* focusedForceRight = scene->addPixmap(QPixmap("C:/Qt/SAPR/res/images/focusedForceRight.png"));
                focusedForceRight->setPos(rects.last().bottomRight().x()-focusedForceRight->pixmap().width(), rects.last().center().y()-focusedForceRight->pixmap().height()/2);
            }
        }
    }
    for(int i = 0; i < distributedForces.size(); i++)
    {
        if(distributedForces[i]!=0)
        {
            if(distributedForces[i] < 0)
            {
                QGraphicsPixmapItem* distributedForceLeft = scene->addPixmap(QPixmap("C:/Qt/SAPR/res/images/distributedForceLeft.png"));
                distributedForceLeft->setPos(rects[i].center().x()-distributedForceLeft->pixmap().width()/2, rects[i].center().y()-distributedForceLeft->pixmap().height()/2);
            }
            else
            {
                QGraphicsPixmapItem* distributedForceRight = scene->addPixmap(QPixmap("C:/Qt/SAPR/res/images/distributedForceRight.png"));
                distributedForceRight->setPos(rects[i].center().x()-distributedForceRight->pixmap().width()/2, rects[i].center().y()-distributedForceRight->pixmap().height()/2);
            }
        }
    }
}




void MainWindow::on_drawButton_clicked()
{
    draw();
}
