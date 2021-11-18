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
    ui->leftTerm->setEnabled(false);
    ui->rightTerm->setEnabled(false);
    ui->saveFile->setEnabled(false);
    ui->clearAll->setEnabled(false);
    for(int i = 0; i < ui->rodDataTable->rowCount(); i++)
    {
         for(int j = 0; j < ui->rodDataTable->columnCount(); j++)
         {
                 this->rodParams.push_back(ui->rodDataTable->item(i,j)->text().toDouble());
         }
         if(rodParams.size() == 4)
         {
             this->rods.push_back(rodParams);
             ui->leftTerm->setEnabled(1);
             ui->rightTerm->setEnabled(1);
         }
         rodParams.clear();
    }
    for(int i = 0; i < ui->distributedForces->rowCount(); i++)
    {
        for(int j = 0; j < ui->distributedForces->columnCount(); j++)
        {
                 this->distributedForces.push_back(ui->distributedForces->item(i,j)->text().toDouble());
        }
    }
    for(int i = 0; i < ui->focusedForces->rowCount(); i++)
    {
         for(int j = 0; j < ui->focusedForces->columnCount(); j++)
         {
             this->focusedForcesList.push_back(ui->focusedForces->item(i,j)->text().toDouble());
         }
    }
    draw();
    QAction::connect(ui->saveFileAs, &QAction::triggered, this, &MainWindow::saveFileAs);
    QAction::connect(ui->saveFile, &QAction::triggered, this, &MainWindow::saveFile);
    QAction::connect(ui->exit, &QAction::triggered, this, &MainWindow::close);
    QAction::connect(ui->loadFromFile, &QAction::triggered, this, &MainWindow::readFromFile);
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
    wgt->insertRow(wgt->rowCount());
}

void MainWindow::on_addRodButton_clicked()
{
    addRow(ui->rodDataTable);
    addRow(ui->focusedForces);
    addRow(ui->distributedForces);
    for(int i = 0; i < ui->rodDataTable->columnCount(); ++i)
    {
        ui->rodDataTable->setItem(ui->rodDataTable->rowCount()-1, i, new QTableWidgetItem());
    }

    for(int j = 0; j < ui->focusedForces->columnCount(); ++j)
    {
        ui->focusedForces->setItem(ui->focusedForces->rowCount()-1, j, new QTableWidgetItem());
    }
    ui->distributedForces->setItem(ui->distributedForces->rowCount()-1, 0, new QTableWidgetItem());
    if(ui->rodDataTable->rowCount() == 1)
        ui->deleteRodButton->setEnabled(false);
    else
    {
       ui->deleteRodButton->setEnabled(true);
       ui->clearAll->setEnabled(true);
    }
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
    if(!validateRodData(data))
    {
        item->setText("1");
    }
   ui->clearAll->setEnabled(true);
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
            {
                this->rods.push_back(rodParams);
                ui->leftTerm->setEnabled(1);
                ui->rightTerm->setEnabled(1);
            }
            rodParams.clear();
       }
   }
   draw();
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
                {
                     return false;
                }
           }
           else return false;
        }
    }
    return true;
}

void MainWindow::on_focusedForces_itemChanged(QTableWidgetItem *item)
{
    QString data = item->text();
    if(!validateForceData(data))
    {
        item->setData(0, QString::number(0));
    }
    ui->clearAll->setEnabled(true);
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
    draw();
}

void MainWindow::on_distributedForces_itemChanged(QTableWidgetItem *item)
{
    QString data = item->text();
    if(!validateForceData(data))
    {
        item->setData(0, QString::number(0));
    }
    ui->clearAll->setEnabled(true);
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
    draw();
}

void MainWindow::draw()
{
    QGraphicsScene *scene = new QGraphicsScene(this);
    QList<QRect> rects;
    QString dir = QApplication::applicationDirPath();
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    if(rods.empty())
    {
        return;
    }
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
             scene->addRect(rect, QPen(Qt::black, 2));
             x+=widht*rods[i][0];

         }
         else
         {
             y= rects[i-1].center().y()-height*rods[i][1]/2+1;
             QRect rect = QRect(x, y, widht*rods[i][0], height*rods[i][1]);
             rects.push_back(rect);
             scene->addRect(rect, QPen(Qt::black, 2));
             x+=widht*rods[i][0];
         }
    }

    if(ui->leftTerm->isChecked())
    {
        QGraphicsPixmapItem* leftTerm = scene->addPixmap(QPixmap(dir+"/res/images/leftTerm.png"));
        leftTerm->setPos(rects.first().bottomLeft().x()-leftTerm->pixmap().width(), rects.first().center().y()-leftTerm->pixmap().height()/2);
        leftTerm->show();
    }
    if(ui->rightTerm->isChecked())
    {
        QGraphicsPixmapItem* rightTerm = scene->addPixmap(QPixmap(dir+"/res/images/rightTerm.png"));
        rightTerm->setPos(rects.last().bottomRight().x(), rects.first().center().y()-rightTerm->pixmap().height()/2);
        rightTerm->show();
    }
    ui->graphicsView->setScene(scene);
    if(!focusedForcesList.empty())
    {
        for(int i = 0; i < focusedForcesList.size(); i++)
    {
        if (i!=rods.size())
        {

                if(focusedForcesList[i] < 0)
                {
                    QGraphicsPixmapItem* focusedForceLeft = scene->addPixmap(QPixmap(dir+"/res/images/focusedForceLeft.png"));
                    focusedForceLeft->setPos(rects[i].bottomLeft().x(), rects[i].center().y()-focusedForceLeft->pixmap().height()/2);
                }
                else if(focusedForcesList[i] > 0)
                {
                    QGraphicsPixmapItem* focusedForceRight = scene->addPixmap(QPixmap(dir+"/res/images/focusedForceRight.png"));
                    focusedForceRight->setPos(rects[i].bottomLeft().x(), rects[i].center().y()-focusedForceRight->pixmap().height()/2);
                }

        }
        else
        {

                if(focusedForcesList[i] < 0)
                {
                    QGraphicsPixmapItem* focusedForceLeft = scene->addPixmap(QPixmap(dir+"/res/images/focusedForceLeft.png"));
                    focusedForceLeft->setPos(rects.last().bottomRight().x()-focusedForceLeft->pixmap().width(), rects.last().center().y()-focusedForceLeft->pixmap().height()/2);
                }
                else if(focusedForcesList[i] > 0)
                {
                    QGraphicsPixmapItem* focusedForceRight = scene->addPixmap(QPixmap(dir+"/res/images/focusedForceRight.png"));
                    focusedForceRight->setPos(rects.last().bottomRight().x()-focusedForceRight->pixmap().width(), rects.last().center().y()-focusedForceRight->pixmap().height()/2);
                }

        }
    }
    }
    if(!distributedForces.empty())
    {
     for(int i = 0; i < distributedForces.size(); i++)
        {
          if(distributedForces[i]!=0)
        {
            if(distributedForces[i] < 0)
            {
                QGraphicsPixmapItem* distributedForceLeft = scene->addPixmap(QPixmap(dir+"/res/images/distributedForceLeft.png"));
                distributedForceLeft->setPos(rects[i].center().x()-distributedForceLeft->pixmap().width()/2, rects[i].center().y()-distributedForceLeft->pixmap().height()/2);
            }
            else
            {
                QGraphicsPixmapItem* distributedForceRight = scene->addPixmap(QPixmap(dir+"/res/images/distributedForceRight.png"));
                distributedForceRight->setPos(rects[i].center().x()-distributedForceRight->pixmap().width()/2, rects[i].center().y()-distributedForceRight->pixmap().height()/2);
            }
        }
        }
    }
}

void MainWindow::on_leftTerm_clicked()
{
    if(ui->leftTerm->isChecked())
    {
        ui->focusedForces->item(0,0)->setText("0");
        ui->focusedForces->item(0, 0)->setFlags(ui->focusedForces->item(0, 0)->flags() & ~Qt::ItemIsEditable);
        ui->focusedForces->item(0, 0)->setBackground(Qt::gray);
    }
    else
    {
        ui->focusedForces->item(0, 0)->setFlags(ui->focusedForces->item(0, 0)->flags() | Qt::ItemIsEditable);
        ui->focusedForces->item(0, 0)->setBackground(Qt::white);
    }
    draw();
}

void MainWindow::on_rightTerm_clicked()
{
    if(ui->rightTerm->isChecked())
    {
        ui->focusedForces->item(ui->focusedForces->rowCount()-1, 0)->setText("0");
        ui->focusedForces->item(ui->focusedForces->rowCount()-1, 0)->setFlags(ui->focusedForces->item(ui->focusedForces->rowCount()-1, 0)->flags() & ~Qt::ItemIsEditable);
        ui->focusedForces->item(ui->focusedForces->rowCount()-1, 0)->setBackground(Qt::gray);
        ui->addRodButton->setEnabled(0);
        ui->deleteRodButton->setEnabled(0);
    }
    else
    {
        ui->focusedForces->item(ui->focusedForces->rowCount()-1, 0)->setFlags(ui->focusedForces->item(ui->focusedForces->rowCount()-1, 0)->flags() | Qt::ItemIsEditable);
        ui->focusedForces->item(ui->focusedForces->rowCount()-1, 0)->setBackground(Qt::white);
        ui->addRodButton->setEnabled(1);
        ui->deleteRodButton->setEnabled(1);
    }

    draw();
}

void MainWindow::scaleView(qreal scaleFactor)
{
    qreal factor = ui->graphicsView->transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
    if (factor < 0.1 || factor > 100)
        return;

    ui->graphicsView->scale(scaleFactor, scaleFactor);
}

void MainWindow::wheelEvent(QWheelEvent *event)
{
    scaleView(pow(2., -event->angleDelta().y() / 240.0));
}

void MainWindow::saveFile()
{
    QFile file(usingFile);
    if(!file.open(QFile::WriteOnly|QFile::Text))
    {
        QMessageBox::warning(this, "Непредвиденная ошибка!","Невозможно открыть файл: " + file.errorString());
        return;
    }
    QTextStream loadTo(&file);
    QString fileText;
    loadTo<<"Количество стержней: ";
    loadTo<<rods.size()<<"\n";
    loadTo<<"Параметры стержней\n";
    loadTo<<"L  A  σ  E\n";
    for(int i = 0; i<rods.size();++i)
    {
        for(int j = 0; j < rods[i].size(); ++j)
        {
            loadTo<<QString::number(rods[i][j])<<"  ";
        }
        loadTo<<"\n";
    }
    loadTo<<"Сосредоточенные нагрузки\n";
    for(int i = 0; i < focusedForcesList.size(); ++i)
    {
        loadTo<<QString::number(focusedForcesList[i])<<"\n";
    }
    loadTo<<"Распределенные нагрузки\n";
    for(int i = 0; i < distributedForces.size(); ++i)
    {
        loadTo<<QString::number(distributedForces[i])<<"\n";
    }
    loadTo<<"Информация о заделках\n";
    loadTo<<"Заделка слева: ";
    loadTo<<QString::number(ui->leftTerm->isChecked())<<"\n";
    loadTo<<"Заделка справа: ";
    loadTo<<QString::number(ui->rightTerm->isChecked())<<"\n";
    ui->saveFile->setEnabled(true);
}

void MainWindow::saveFileAs()
{
    usingFile = QFileDialog::getSaveFileName(this, "Сохранить как");
    saveFile();
}

void MainWindow::readFromFile()
{
    QString fileName = QFileDialog::getOpenFileName(this,"Open file");
    QFile in(fileName);
    usingFile = fileName;
    if(!in.open(QIODevice::ReadOnly|QFile::Text))
    {
        QMessageBox::warning(this,"Непредвиденная ошибка!","Невозможно открыть файл: " + in.errorString());
        return;
    }

    QString line;
    int rodAmount = 0;
    QList<QStringList> rodData;
    QStringList focusedForcesData;
    QStringList distributedForcesData;
    int leftTerm = 0;
    int rightTerm = 0;
    while(!in.atEnd())
    {
        line = in.readLine();
        if(line.contains("Количество стержней"))
        {
            QStringList tmp = line.split(' ', Qt::SkipEmptyParts);
            rodAmount = tmp[2].trimmed().toInt();
        }
        if(line.contains("L"))
        {
            for(int i = 0; i < rodAmount; i++)
            {
                line = in.readLine();
                rodData.push_back(line.split(' ', Qt::SkipEmptyParts));

            }
        }
        if(line.contains("Сосредоточенные нагрузки"))
        {
            for(int i = 0; i <= rodAmount; i++)
            {
                line = in.readLine().trimmed();
                focusedForcesData.push_back(line);
            }
        }
        if(line.contains("Распределенные нагрузки"))
        {
            for(int i = 0; i < rodAmount; i++)
            {
                line = in.readLine().trimmed();
                distributedForcesData.push_back(line);
            }
        }

        if(line.contains("Заделка слева"))
         {
                    QStringList tmp = line.split(' ', Qt::SkipEmptyParts);
                    leftTerm = tmp[2].trimmed().toInt();
         }
         if(line.contains("Заделка справа"))
         {
                    QStringList tmp = line.split(' ', Qt::SkipEmptyParts);
                    rightTerm = tmp[2].trimmed().toInt();
         }
    }
    if(!rodAmount)
    {
        QMessageBox::warning(this,"Непредвиденная ошибка!","Ошибка в данных" + in.errorString());
        return;
    }
    if(focusedForcesData.size() != rodAmount + 1||distributedForcesData.size() != rodAmount||rodData.size() != rodAmount)
    {
        QMessageBox::warning(this,"Непредвиденная ошибка!","Ошибка в данных" + in.errorString());
        return;
    }
    on_clearAll_clicked();
    while(ui->rodDataTable->rowCount() != rodAmount)
    {
        on_addRodButton_clicked();
    }
    for(int i = 0; i < ui->rodDataTable->rowCount(); ++i)
    {
        for(int j = 0; j < ui->rodDataTable->columnCount(); ++j)
        {
            ui->rodDataTable->item(i,j)->setText(rodData[i][j]);
        }
    }
    for(int i = 0; i < ui->focusedForces->rowCount(); ++i)
    {
        for(int j = 0; j < ui->focusedForces->columnCount(); ++j)
        {
            ui->focusedForces->item(i,j)->setText(focusedForcesData[i]);
        }
    }
    for(int i = 0; i < ui->distributedForces->rowCount(); ++i)
    {
        for(int j = 0; j < ui->distributedForces->columnCount(); ++j)
        {
            ui->distributedForces->item(i,j)->setText(distributedForcesData[i]);
        }
    }
    while(ui->rodDataTable->rowCount()!=rodAmount)
    {
        on_addRodButton_clicked();
    }

    ui->leftTerm->setChecked(leftTerm);
    ui->rightTerm->setChecked(rightTerm);
    if(ui->leftTerm->isChecked())
    {
        ui->focusedForces->item(0,0)->setText("0");
        ui->focusedForces->item(0, 0)->setFlags(ui->focusedForces->item(0, 0)->flags() & ~Qt::ItemIsEditable);
        ui->focusedForces->item(0, 0)->setBackground(Qt::gray);
    }
    else
    {
        ui->focusedForces->item(0, 0)->setFlags(ui->focusedForces->item(0, 0)->flags() | Qt::ItemIsEditable);
        ui->focusedForces->item(0, 0)->setBackground(Qt::white);
    }
    if(ui->rightTerm->isChecked())
    {
        ui->focusedForces->item(ui->focusedForces->rowCount()-1, 0)->setText("0");
        ui->focusedForces->item(ui->focusedForces->rowCount()-1, 0)->setFlags(ui->focusedForces->item(ui->focusedForces->rowCount()-1, 0)->flags() & ~Qt::ItemIsEditable);
        ui->focusedForces->item(ui->focusedForces->rowCount()-1, 0)->setBackground(Qt::gray);
        ui->addRodButton->setEnabled(0);
        ui->deleteRodButton->setEnabled(0);
    }
    else
    {
        ui->focusedForces->item(ui->focusedForces->rowCount()-1, 0)->setFlags(ui->focusedForces->item(ui->focusedForces->rowCount()-1, 0)->flags() | Qt::ItemIsEditable);
        ui->focusedForces->item(ui->focusedForces->rowCount()-1, 0)->setBackground(Qt::white);
        ui->addRodButton->setEnabled(1);
        ui->deleteRodButton->setEnabled(1);
    }
    draw();
}

void MainWindow::on_clearAll_clicked()
{
    while(ui->rodDataTable->rowCount()!=1)
        on_deleteRodButton_clicked();
    rods.clear();
    focusedForcesList.clear();
    distributedForces.clear();
    for(int i = 0; i < ui->rodDataTable->columnCount(); ++i)
    {
        ui->rodDataTable->setItem(ui->rodDataTable->rowCount()-1, i, new QTableWidgetItem());
    }
    for(int i = 0; i < ui->focusedForces->rowCount(); ++i)
    {
        for(int j = 0; j < ui->focusedForces->columnCount(); ++j)
        {
            ui->focusedForces->setItem(i, j, new QTableWidgetItem());
        }
    }
    ui->distributedForces->setItem(0, 0, new QTableWidgetItem());
    ui->leftTerm->setChecked(false);
    ui->rightTerm->setChecked(false);
    ui->deleteRodButton->setEnabled(false);
    ui->leftTerm->setEnabled(false);
    ui->rightTerm->setEnabled(false);
    ui->graphicsView->scene()->clear();
    ui->clearAll->setEnabled(false);
    draw();
}

void MainWindow::calculate()
{
    const int STEP = 50;
    QVector<double> EAVector;
    for(int i = 0; i < rods.size(); ++i)
    {
        EAVector.push_back(rods[i][1]*rods[i][3]/rods[i][0]);
    }
    QVector<QVector<double>> EAMatrix;
    for(int i = 0; i < focusedForcesList.size(); ++i)
    {
        for(int j = 0; j < focusedForcesList.size(); ++j)
        {
            EAMatrix[i].push_back(0);
        }
    }
    for(int i = 0; i < EAMatrix.size(); ++i)
    {
        for(int j = 0; j < EAMatrix[i].size(); ++j)
        {
            if(i == 0)
            {
                if(ui->leftTerm->isChecked())
                {
                   EAMatrix[i][i] = 1;
                }
                else
                {
                    EAMatrix[i][i] = EAVector[i];
                    EAMatrix[i][i+1] = -EAVector[i];
                    EAMatrix[i+1][i] = -EAVector[i];
                }
            }
            else if(i < EAMatrix.size()-1)
            {
                EAMatrix[i][i] = EAVector[i] + EAVector[i-1];
                EAMatrix[i][i+1] = -EAVector[i];
                EAMatrix[i+1][i] = -EAVector[i];
            }
            else
            {
                if(ui->rightTerm->isChecked())
                {
                    EAMatrix[i][i] = 1;
                }
                else
                {
                    EAMatrix[i][i] = EAVector[i-1];
                }
            }

        }
    }

    QVector<double> b;
    for(int i = 0; i < rods.size() + 1; ++i)
    {
        if(i==0)
        {
            if(ui->leftTerm->isChecked())
            {
                b.push_back(0);
            }
        }
        if(i != rods.size())
        {
            b.push_back(rods[i][0]*distributedForces[i]/2 + b[i-1]);
        }
        else
        {
            if(ui->rightTerm->isChecked())
            {
                b.push_back(0);
            }
            else
            {
                b.push_back(rods[i][0]*distributedForces[i]/2 + b[i-1]);
            }
        }
    }
    QVector<double> delta = gauss(EAMatrix, b);
    QVector<QVector<double>> resultNX;
    for(int i = 0; i < rods.size(); ++i)
    {
        QVector<double> NX;
        for(int j = 0; j < STEP*rods[i][0]; ++j)
        {
            double nxTmp = rods[i][3]*rods[i][1]/rods[i][0] *
                    (delta[i+1] - delta[i]) + distributedForces[i]*rods[i][0]/2 * (1-2*(j*rods[i][0]/(pow(rods[i][0], 2)*STEP)));
            NX.push_back(nxTmp);
        }
        resultNX.push_back(NX);
    }
    QVector<QVector<double>> resultSigma;
    for(int i = 0; i < rods.size(); ++i)
    {
       QVector<double> sigma;
        for(int j = 0; j < STEP*rods[i][0]; ++j)
        {
            double sigmaTmp = resultNX[i][j]/rods[i][1];
            sigma.push_back(sigmaTmp);
        }
        resultSigma.push_back(sigma);
    }
    QVector<QVector<double>> resultUX;
    for(int i = 0; i < rods.size(); ++i)
    {
        QVector<double> UX;
        for(int j = 0; j < STEP*rods[i][0]; ++j)
        {
            double uxTmp = delta[i] + (j*rods[i][0]/(pow(rods[i][0], 2)*STEP))*(delta[i+1] - delta[i]) + (distributedForces[i]*pow(rods[i][0], 2))
                    /(2*rods[i][3]*rods[i][1]) * (j*rods[i][0]/(pow(rods[i][0], 2)*STEP)) * (1 - 2*(j*rods[i][0]/(pow(rods[i][0], 2)*STEP)));
            UX.push_back(uxTmp);
        }
        resultUX.push_back(UX);
    }
 }

QVector<double> MainWindow::gauss(QVector<QVector<double>> EAMatrix, QVector<double> b) //Взято с progcpp.ru
{
    QVector<double> delta;
    for(int i = 0 ; i < EAMatrix.size(); ++i)
        delta.push_back(0);
    double max;
    const double eps = 0.00001;
    int index;
    int k = 0;
    while (k < EAMatrix.size())
    {
        max = abs(EAMatrix[k][k]);
        index = k;
        for(int i = ++k; i < EAMatrix.size(); ++i)
        {
            if(abs(EAMatrix[i][k]) > max)
            {
                max = abs(EAMatrix[i][k]);
                index = i;
            }
        }
        if(max < eps)
        {
            QMessageBox::warning(this,"Непредвиденная ошибка!","Ошибка в расчетах");
            return delta;
        }
        for(int i = 0; i < EAMatrix.size(); ++i)
        {
            double tmp = EAMatrix[k][i];
            EAMatrix[k][i] = EAMatrix[index][i];
            EAMatrix[index][i] = tmp;
        }
        double tmp = b[k];
        b[k] = b[index];
        b[index] = tmp;
        for (int i = k; i < EAMatrix.size(); i++)
            {
              double temp = EAMatrix[i][k];
              if (abs(temp) < eps)
                  continue;
              for (int j = 0; j < EAMatrix.size(); j++)
                EAMatrix[i][j] = EAMatrix[i][j] / temp;
              b[i] = b[i] / temp;
              if (i == k)
                  continue;
              for (int j = 0; j < EAMatrix.size(); j++)
                EAMatrix[i][j] = EAMatrix[i][j] - EAMatrix[k][j];
              b[i] = b[i] - b[k];
            }
            k++;
       }
    for (k = EAMatrix.size() - 1; k >= 0; k--)
     {
       delta[k] = b[k];
       for (int i = 0; i < k; i++)
         b[i] = b[i] - EAMatrix[i][k] * delta[k];
     }
    return delta;
}


