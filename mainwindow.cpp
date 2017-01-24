#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1150,650);
    this->setWindowTitle("SAPR");
    rodCreator = new RodCreator();
    vertexForceCreator = new VertexForceCreator();

    QWidget* centralWidget = new QWidget(this);
    this->setCentralWidget(centralWidget);
    QStringList listNamesHeaders;
    listNamesHeaders << "L" << "A" << "E" << "σ"<< "q";
    QStringList listNamesHeadersForce;
    listNamesHeadersForce << "Vertex Forces";

    QHBoxLayout* mainLayout = new QHBoxLayout;
    scene = new QGraphicsScene;
    view = new QGraphicsView(scene);

    table = new RodTable();
    table->setColumnCount(5);
    table->verticalHeader()->hide();
    for(int i = 0; i < 5; i++)
    {
        table->setColumnWidth(i,60);
    }
    table->setHorizontalHeaderLabels(listNamesHeaders);
    table->setFixedWidth(300);
    table->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);

    tableForces = new QTableWidget;
    tableForces->setFixedWidth(300);
    tableForces->setColumnCount(1);
    tableForces->setColumnWidth(0, 300);
    tableForces->setHorizontalHeaderLabels(listNamesHeadersForce);
    tableForces->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    tableForces->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableForces->setSelectionMode(QAbstractItemView::NoSelection);


    epureSwitcher = new QComboBox;
    epureSwitcher->addItem(NX);
    epureSwitcher->addItem(UX);
    epureSwitcher->addItem(SIGMAX);
    epureSwitcher->setParent(view);
    epureSwitcher->setFixedSize(80,25);
    epureSwitcher->setGeometry(view->geometry().topRight().rx() + epureSwitcher->width(), view->geometry().topRight().y() + epureSwitcher->height()/2, epureSwitcher->geometry().width(), epureSwitcher->geometry().height());

    QVBoxLayout* vlayout = new QVBoxLayout;
    vlayout->addWidget(table);
    vlayout->addWidget(tableForces);

    mainLayout->addLayout(vlayout);
    mainLayout->addWidget(view);
    centralWidget->setLayout(mainLayout);
    QPixmap leftSupportPix(":/resources/images/leftSupport.png");
    leftSupportItem = scene->addPixmap(leftSupportPix);
    QPixmap rightSupportPix(":/resources/images/rightSupport.png");
    rightSupportItem = scene->addPixmap(rightSupportPix);
    leftSupportItem->hide();
    rightSupportItem->hide();
    addToolBar(Qt::TopToolBarArea, createToolBar());
    epureScale_ = 50;
    resultTable = new ResultTable;

    connect(table, SIGNAL(addRodSignal()), rodCreator, SLOT(show()));
    connect(table, SIGNAL(removeRodSignal()), this, SLOT(deleteSlot()));
    connect(table, SIGNAL(removeAllSignal()), this, SLOT(newConstruction()));
    connect(rodCreator, SIGNAL(sendRodData(double, double, double, double, double)), this, SLOT(addKernelSlot(double, double, double, double, double)));
    connect(vertexForceCreator, SIGNAL(sendForce(int, double)), this, SLOT(setForceSlot(int, double)));
    connect(epureSwitcher, SIGNAL(currentTextChanged(QString)), this, SLOT(epureSwitcherChangedSlot(QString)));
    connect(this, SIGNAL(constructionChanged()), this, SLOT(deleteAllEpures()));
    connect(table, SIGNAL(currentItemChanged(QTableWidgetItem*,QTableWidgetItem*)),this, SLOT(currentRodChanged(QTableWidgetItem*,QTableWidgetItem*)));
    connect(table, SIGNAL(itemSelectionChanged()), this, SLOT(clearColorSelection()));
}
MainWindow::~MainWindow()
{
    delete ui;
    delete table;
    delete rodCreator;
    delete resultTable;
    delete vertexForceCreator;
}

QToolBar *MainWindow::createToolBar()
{
    QToolBar* toolBar = new QToolBar();
    toolBar->addAction(QIcon(":/resources/images/newIcon.png"),"New construction", this, SLOT(newConstruction()));
    toolBar->addAction(QIcon(":/resources/images/saveIcon.png"),"Save File", this, SLOT(save()));
    toolBar->addSeparator();
    toolBar->addAction(QIcon(":/resources/images/addIcon.png"),"Add rod", rodCreator, SLOT(show()));
    toolBar->addSeparator();
    leftSupportAction = toolBar->addAction(QIcon(":/resources/images/leftSupport.png"),"Left support", this, SLOT(setLeftSupport()));
    leftSupportAction->setCheckable(true);
    rightSupportAction = toolBar->addAction(QIcon(":/resources/images/rightSupport.png"),"Right support", this, SLOT(setRightSupport()));
    rightSupportAction->setCheckable(true);
    toolBar->addSeparator();
    toolBar->addAction(QIcon(":/resources/images/vertexPlusForce.png"),"Create vertex force", this, SLOT(openVertexForceCreator()));
    toolBar->addAction(QIcon(":/resources/images/calculateIcon.png"),"Calculate", this, SLOT(calculate()));
    toolBar->addAction(QIcon(":/resources/images/tableIcon.png"), "Result table", this, SLOT(openResultTable()));
    toolBar->addSeparator();
    zoomInAct = toolBar->addAction(QIcon(":/resources/images/zoomPlusIcon.png"), "Zoom In epure", this, SLOT(zoomInEpure()));
    zoomOutAct = toolBar->addAction(QIcon(":/resources/images/zoomMinusIcon.png"), "Zoom Out epure", this, SLOT(zoomOutEpure()));
    toolBar->addSeparator();
    return toolBar;
}

void MainWindow::setPosLeftSupport()
{
    qreal x = rods.at(0)->item()->x() - leftSupportItem->pixmap().width();
    qreal y = (leftSupportItem->pixmap().height() - rods.at(0)->A()*A_SIZE)/(-2);
    leftSupportItem->setPos(x,y);
}

void MainWindow::setPosRightSupport()
{
    qreal x = rods.at(rods.size() - 1)->item()->rect().topRight().x();
    qreal y = (rightSupportItem->pixmap().height() - rods.at(rods.size() - 1)->A()*A_SIZE)/(-2);
    if(leftSupportItem->y() != y)
    {
        y = leftSupportItem->y();
    }
    rightSupportItem->setPos(x,y);
}

void MainWindow::addKernelSlot(const double& L,const double& A, const double& E, const double& sigma, const double& Q)
{
    if(!NxEpureItems.isEmpty())
    {
        deleteAllEpures();
    }
    if(rods.isEmpty())
    {
        QGraphicsRectItem* rectItem = scene->addRect(0,0,L*L_SIZE,A*A_SIZE,QPen(Qt::black, 5));
        lineItem = scene->addLine(-1000, rectItem->rect().center().ry(), 2000, rectItem->rect().center().ry(),QPen(Qt::DashDotLine));
        lineItem->setFlags(QGraphicsItem::ItemStacksBehindParent);

        Rod* rod = new Rod(rectItem,L, A, E, sigma, Q);
        rods.push_back(rod);
        int row = table->rowCount();
        table->setRowCount(table->rowCount() + 1);
        for(int i = 0; i < 5; i++)
        {
            QTableWidgetItem* item = new QTableWidgetItem;
            item->setFlags(item->flags() & ~Qt::ItemIsEditable);
            item->setTextAlignment(Qt::AlignCenter);
            table->setItem(row, i, item);
        }

        table->item(row, 0)->setText(QString::number(L));
        table->item(row, 1)->setText(QString::number(A));
        table->item(row, 2)->setText(QString::number(E));
        table->item(row, 3)->setText(QString::number(sigma));
        table->item(row, 4)->setText(QString::number(Q));
        table->selectRow(0);

        if(Q > 0)
        {
            drawLongForce(rectItem,":/resources/images/longPlusForce.png");
        }
        if(Q < 0)
        {
            drawLongForce(rectItem,":/resources/images/longMinusForce.png");
        }

        for(int i = 0; i < 2; i++)
        {
            if(vertexForces.size() == 0)
            {
                Vertex vertex;
                vertex.value = 0.0;
                QPixmap pix1(":/resources/images/vertexMinusForce.png");
                vertex.minusForce = scene->addPixmap(pix1);
                vertex.minusForce->setParentItem(rods.at(0)->item());
                vertex.minusForce->hide();
                QPixmap pix2(":/resources/images/vertexPlusForce.png");
                vertex.plusForce = scene->addPixmap(pix2);
                vertex.plusForce->setParentItem(rods.at(0)->item());
                vertex.plusForce->hide();
                qreal x = rods.at(0)->item()->rect().topLeft().x();
                qreal y = lineItem->line().y1() - vertex.minusForce->pixmap().size().height()/2;
                vertex.minusForce->setPos(x,y);
                vertex.plusForce->setPos(x,y);
                vertexForces.push_back(vertex);
            }
            else
            {
                Vertex vertex;
                vertex.value = 0.0;
                QPixmap pix1(":/resources/images/vertexMinusForce.png");
                vertex.minusForce = scene->addPixmap(pix1);
                vertex.minusForce->setParentItem(rods.at(0)->item());
                vertex.minusForce->hide();
                QPixmap pix2(":/resources/images/vertexPlusForce.png");
                vertex.plusForce = scene->addPixmap(pix2);
                vertex.plusForce->setParentItem(rods.at(0)->item());
                vertex.plusForce->hide();
                qreal x = rods.at(0)->item()->rect().topRight().x() - vertex.minusForce->pixmap().size().width();
                qreal y = lineItem->line().y1() - vertex.minusForce->pixmap().size().height()/2;
                vertex.minusForce->setPos(x,y);
                vertex.plusForce->setPos(x,y);
                vertexForces.push_back(vertex);
            }

            int rowForces = tableForces->rowCount();
            tableForces->setRowCount(tableForces->rowCount() + 1);

            QTableWidgetItem* item = new QTableWidgetItem;
            item->setFlags(item->flags() & ~Qt::ItemIsEditable);
            item->setTextAlignment(Qt::AlignCenter);
            tableForces->setItem(rowForces, 0, item);
            tableForces->item(rowForces, 0)->setText(QString::number(vertexForces.at(rowForces).value));
        }

        setPosLeftSupport();
        setPosRightSupport();
    }

    else
    {
        double diff_A = A - rods.at(rods.size() - 1)->A();
        double x = rods.at(rods.size() - 1)->item()->rect().topRight().rx();
        double y = rods.at(rods.size() - 1)->item()->rect().topRight().ry() - diff_A*(A_SIZE/2);
        QGraphicsRectItem* rectItem = scene->addRect(x, y, L*L_SIZE, A*A_SIZE,QPen(Qt::black, 5));
        Rod* rod = new Rod(rectItem,L, A, E, sigma, Q);
        rods.push_back(rod);
        int row = table->rowCount();
        table->setRowCount(table->rowCount() + 1);

        for(int i = 0; i < 5; i++)
        {
            QTableWidgetItem* item = new QTableWidgetItem;
            item->setFlags(item->flags() & ~Qt::ItemIsEditable);
            item->setTextAlignment(Qt::AlignCenter);
            table->setItem(row, i, item);
        }

        table->item(row, 0)->setText(QString::number(L));
        table->item(row, 1)->setText(QString::number(A));
        table->item(row, 2)->setText(QString::number(E));
        table->item(row, 3)->setText(QString::number(sigma));
        table->item(row, 4)->setText(QString::number(Q));

        if(Q > 0)
        {
            drawLongForce(rectItem, ":/resources/images/longPlusForce.png");
        }
        if(Q < 0)
        {
            drawLongForce(rectItem, ":/resources/images/longMinusForce.png");
        }

        Vertex vertex;
        vertex.value = 0.0;
        QPixmap pix1(":/resources/images/vertexMinusForce.png");
        vertex.minusForce = scene->addPixmap(pix1);
        vertex.minusForce->setParentItem(rods.at(rods.size() - 1)->item());
        vertex.minusForce->hide();
        QPixmap pix2(":/resources/images/vertexPlusForce.png");
        vertex.plusForce = scene->addPixmap(pix2);
        vertex.plusForce->setParentItem(rods.at(rods.size() - 1)->item());
        vertex.plusForce->hide();
        qreal xPos = rods.at(rods.size() - 1)->item()->rect().topRight().x() - vertex.minusForce->pixmap().size().width();
        qreal yPos = lineItem->line().y1() - vertex.minusForce->pixmap().size().height()/2;
        vertex.minusForce->setPos(xPos, yPos);
        vertex.plusForce->setPos(xPos, yPos);
        vertexForces.push_back(vertex);

        int rowForces = tableForces->rowCount();
        tableForces->setRowCount(tableForces->rowCount() + 1);
        QTableWidgetItem* item = new QTableWidgetItem;
        item->setFlags(item->flags() & ~Qt::ItemIsEditable);
        item->setTextAlignment(Qt::AlignCenter);
        tableForces->setItem(rowForces, 0, item);
        tableForces->item(rowForces, 0)->setText(QString::number(vertexForces.at(rowForces).value));
        setPosRightSupport();
    }

}


void MainWindow::setLeftSupport()
{
    if(!NxEpureItems.isEmpty())
    {
        deleteAllEpures();
    }
    if(leftSupportAction->isChecked())
    {
        leftSupportItem->show();
    }
    else
    {
        leftSupportItem->hide();
    }
}

void MainWindow::setRightSupport()
{
    if(!NxEpureItems.isEmpty())
    {
        deleteAllEpures();
    }
    if(rightSupportAction->isChecked())
    {
        rightSupportItem->show();
    }
    else
    {
        rightSupportItem->hide();
    }
}

void MainWindow::openVertexForceCreator()
{
    QStringList tempList;
    if(!rods.isEmpty())
    {
        for(int i = 0; i < rods.size() + 1; i++)
        {
            tempList << QString::number(i + 1);
        }
    }
    vertexForceCreator->setVertices(tempList);
    vertexForceCreator->show();

}

void MainWindow::openResultTable()
{
    if(NxVectors.isEmpty() && uxVectors.isEmpty() && sigmaXVectors.isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Ошибка!");
        msgBox.setText("Отсутствуют расчеты!");
        msgBox.exec();
    }
    else
    {
        QStringList rodList;
        for(int i = 0; i < rods.size(); i++)
        {
            rodList << QString::number(i + 1);
        }
        resultTable->setRodList(rodList);
        resultTable->setData(NxVectors, uxVectors, sigmaXVectors, rods);

        resultTable->show();
    }
}

void MainWindow::setForceSlot(int vertex, double force)
{
    if(!NxEpureItems.isEmpty())
    {
        deleteAllEpures();
    }

    vertexForces[vertex].value = force;
    if(force > 0)
    {
        vertexForces[vertex].plusForce->show();
        vertexForces[vertex].minusForce->hide();
    }
    else if(force < 0)
    {
        vertexForces[vertex].plusForce->hide();
        vertexForces[vertex].minusForce->show();
    }
    else
    {
        vertexForces[vertex].plusForce->hide();
        vertexForces[vertex].minusForce->hide();
    }
    tableForces->item(vertex, 0)->setText(QString::number(force));

}

void MainWindow::calculate()
{
    if(!leftSupportAction->isChecked() && !rightSupportAction->isChecked())
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Ошибка!");
        msgBox.setText("Отсутствуют опоры!");
        msgBox.exec();
    }
    else
    {
        if(!rods.isEmpty())
        {
            if(!NxEpureItems.isEmpty())
            {
                deleteAllEpures();
            }
            epureScale_ = DEFAULT_EPURE_SCALE;

            m_A = new double*[vertexForces.size()];
            for (int count = 0; count < vertexForces.size(); count++)
            {
                m_A[count] = new double[vertexForces.size()];
            }
            resetA();
            fillingA();
            considerSupportsForA();

            m_b = new double*[vertexForces.size()];
            for (int count = 0; count < vertexForces.size(); count++)
            {
                m_b[count] = new double[1];
            }
            resetB();
            fillingB();
            considerSupportsForB();

            int equationsCount = vertexForces.size();
            int variablesCount = vertexForces.size() + 1;

            double **matrix = new double *[equationsCount]; //общий вид системы уравнений
            for (int i = 0; i < equationsCount; i++)
            {
                matrix[i] = new double [variablesCount];
            }
            resetMatrix(matrix, equationsCount, variablesCount);
            fillingMatrix(matrix, equationsCount, variablesCount);

            delta = new double[variablesCount];
            Gauss(delta, matrix, equationsCount, variablesCount); // Метод Гаусса

            drawGraphicsSeparators();

            countNx();
            drawEpureNx(DEFAULT_EPURE_SCALE);

            countUx();
            drawEpureUx(DEFAULT_EPURE_SCALE);

            countSigmaX();
            drawEpureSigmaX(DEFAULT_EPURE_SCALE);

            delete []delta;
            for(int i = 0; i < vertexForces.size(); i++)
            {
                delete []m_A[i];
                delete []m_b[i];
                delete []matrix[i];
            }
            delete []m_A;
            delete []m_b;
            delete []matrix;
        }
    }
}

void MainWindow::newConstruction()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Сообщение", "Хотите создать новую конструкцию?",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        if(!NxEpureItems.isEmpty())
        {
            deleteAllEpures();
        }
        while(rods.size())
        {
            table->removeRow(0);
            scene->removeItem(rods.at(0)->item());
            rods.remove(0);
        }
        NxVectors.clear();
        uxVectors.clear();
        sigmaXVectors.clear();
        scene->removeItem(lineItem);
        rightSupportItem->hide();
        leftSupportItem->hide();
        leftSupportAction->setChecked(false);
        rightSupportAction->setChecked(false);

        for(int i = 0; i < vertexForces.size(); i++)
        {
            scene->removeItem(vertexForces.at(i).minusForce);
            scene->removeItem(vertexForces.at(i).plusForce);
        }
        vertexForces.clear();


        while(tableForces->rowCount())
        {
            tableForces->removeRow(0);
        }
    }

}

void MainWindow::epureSwitcherChangedSlot(QString epureName)
{
    if(epureName == NX)
    {
        for(int i = 0; i < NxFillingItems.size(); i++)
        {
            NxFillingItems.at(i)->show();
        }
        for(int i = 0; i < NxEpureItems.size(); i++)
        {
            NxEpureItems.at(i)->show();
        }
        for(int i = 0; i < NxTextItems.size(); i++)
        {
            NxTextItems.at(i)->show();
        }

        for(int i = 0; i < uxFillingItems.size(); i++)
        {
            uxFillingItems.at(i)->hide();
        }
        for(int i = 0; i < uxEpureItems.size(); i++)
        {
            uxEpureItems.at(i)->hide();
        }
        for(int i = 0; i < NxTextItems.size(); i++)
        {
            uxTextItems.at(i)->hide();
        }

        for(int i = 0; i < sigmaXFillingItems.size(); i++)
        {
            sigmaXFillingItems.at(i)->hide();
        }
        for(int i = 0; i < sigmaXEpureItems.size(); i++)
        {
            sigmaXEpureItems.at(i)->hide();
        }
        for(int i = 0; i < sigmaXTextItems.size(); i++)
        {
            sigmaXTextItems.at(i)->hide();
        }
    }

    if(epureName == UX)
    {
        for(int i = 0; i < NxFillingItems.size(); i++)
        {
            NxFillingItems.at(i)->hide();
        }
        for(int i = 0; i < NxEpureItems.size(); i++)
        {
            NxEpureItems.at(i)->hide();
        }
        for(int i = 0; i < NxTextItems.size(); i++)
        {
            NxTextItems.at(i)->hide();
        }

        for(int i = 0; i < uxFillingItems.size(); i++)
        {
            uxFillingItems.at(i)->show();
        }
        for(int i = 0; i < uxEpureItems.size(); i++)
        {
            uxEpureItems.at(i)->show();
        }
        for(int i = 0; i < NxTextItems.size(); i++)
        {
            uxTextItems.at(i)->show();
        }

        for(int i = 0; i < sigmaXFillingItems.size(); i++)
        {
            sigmaXFillingItems.at(i)->hide();
        }
        for(int i = 0; i < sigmaXEpureItems.size(); i++)
        {
            sigmaXEpureItems.at(i)->hide();
        }
        for(int i = 0; i < sigmaXTextItems.size(); i++)
        {
            sigmaXTextItems.at(i)->hide();
        }
    }

    if(epureName == SIGMAX)
    {
        for(int i = 0; i < NxFillingItems.size(); i++)
        {
            NxFillingItems.at(i)->hide();
        }
        for(int i = 0; i < NxEpureItems.size(); i++)
        {
            NxEpureItems.at(i)->hide();
        }
        for(int i = 0; i < NxTextItems.size(); i++)
        {
            NxTextItems.at(i)->hide();
        }

        for(int i = 0; i < uxFillingItems.size(); i++)
        {
            uxFillingItems.at(i)->hide();
        }
        for(int i = 0; i < uxEpureItems.size(); i++)
        {
            uxEpureItems.at(i)->hide();
        }
        for(int i = 0; i < NxTextItems.size(); i++)
        {
            uxTextItems.at(i)->hide();
        }

        for(int i = 0; i < sigmaXFillingItems.size(); i++)
        {
            sigmaXFillingItems.at(i)->show();
        }
        for(int i = 0; i < sigmaXEpureItems.size(); i++)
        {
            sigmaXEpureItems.at(i)->show();
        }
        for(int i = 0; i < sigmaXTextItems.size(); i++)
        {
            sigmaXTextItems.at(i)->show();
        }
    }
}

void MainWindow::deleteAllEpures(bool withoutSeparators)
{
    scene->removeItem(epureLineX);
    for(int i = 0; i < NxFillingItems.size(); i++)
    {
        scene->removeItem(NxFillingItems.at(i));
    }

    NxFillingItems.clear();

    for(int i = 0; i < NxEpureItems.size(); i++)
    {
        scene->removeItem(NxEpureItems.at(i));
    }

    NxEpureItems.clear();

    for(int i = 0; i < uxFillingItems.size(); i++)
    {
        scene->removeItem(uxFillingItems.at(i));
    }

    uxFillingItems.clear();

    for(int i = 0; i < uxEpureItems.size(); i++)
    {
        scene->removeItem(uxEpureItems.at(i));
    }

    uxEpureItems.clear();

    for(int i = 0; i < sigmaXFillingItems.size(); i++)
    {
        scene->removeItem(sigmaXFillingItems.at(i));
    }

    sigmaXFillingItems.clear();

    for(int i = 0; i < sigmaXEpureItems.size(); i++)
    {
        scene->removeItem(sigmaXEpureItems.at(i));
    }

    sigmaXEpureItems.clear();

    if(!withoutSeparators)
    {
        for(int i = 0; i < graphicsSeparators.size(); i++)
        {
            scene->removeItem(graphicsSeparators.at(i));
        }
        graphicsSeparators.clear();
        NxVectors.clear();
        uxVectors.clear();
        sigmaXVectors.clear();
    }


    for(int i = 0; i < NxTextItems.size(); i++)
    {
        scene->removeItem(NxTextItems.at(i));
    }
    NxTextItems.clear();
    for(int i = 0; i < uxTextItems.size(); i++)
    {
        scene->removeItem(uxTextItems.at(i));
    }
    uxTextItems.clear();
    for(int i = 0; i < sigmaXTextItems.size(); i++)
    {
        scene->removeItem(sigmaXTextItems.at(i));
    }
    sigmaXTextItems.clear();


}

void MainWindow::currentRodChanged(QTableWidgetItem* curr, QTableWidgetItem* prev)
{
    if(!rods.isEmpty())
    {
        if(curr != NULL)
        {
            rods.at(curr->row())->item()->setPen(SELECTED_PEN);
        }

        if(rods.size() > 1  && prev != NULL)
        {
            rods.at(prev->row())->item()->setPen(USUAL_PEN);
        }
    }
}

void MainWindow::clearColorSelection()
{
    if(table->selectedItems().isEmpty())
    {
        for(int i = 0; i < rods.size(); i++)
        {
            rods.at(i)->item()->setPen(USUAL_PEN);
        }
    }
}

void MainWindow::zoomInEpure()
{
    if(epureScale_ != MAX_EPURE_SCALE && !NxEpureItems.isEmpty())
    {
        if(!NxEpureItems.isEmpty())
        {
            deleteAllEpures(true);
        }
        epureScale_ += 10;
        drawEpureNx(epureScale_);
        drawEpureUx(epureScale_);
        drawEpureSigmaX(epureScale_);
    }
}

void MainWindow::zoomOutEpure()
{
    if(epureScale_ != MIN_EPURE_SCALE && !NxEpureItems.isEmpty())
    {
        if(!NxEpureItems.isEmpty())
        {
            deleteAllEpures(true);
        }
        epureScale_ -= 10;
        drawEpureNx(epureScale_);
        drawEpureUx(epureScale_);
        drawEpureSigmaX(epureScale_);
    }
}
void MainWindow::save()
{
    if(NxVectors.isEmpty() || uxVectors.isEmpty() || sigmaXVectors.isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Ошибка!");
        msgBox.setText("Отсутствуют расчеты!");
        msgBox.exec();
    }
    else
    {
        QByteArray resultsArray = createFile();
        QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),"/Users/uncolor", tr("Text Files (*.txt)"));
        QFile file(fileName);
        file.open(QIODevice::WriteOnly);
        file.write(resultsArray);
        file.close();
    }
}

void MainWindow::drawLongForce(QGraphicsRectItem* rectItem, QString pixName)
{
    QPixmap pix(pixName);
    QGraphicsPixmapItem* pixmapItem = scene->addPixmap(pix);
    pixmapItem->setParentItem(rectItem);
    pixmapItem->setFlags(QGraphicsItem::ItemStacksBehindParent);
    qreal x = rectItem->rect().center().rx() - pixmapItem->pixmap().size().width()/2;
    qreal y = rectItem->rect().center().ry() - pixmapItem->pixmap().size().height()/2;
    pixmapItem->setPos(x,y);
}

void MainWindow::resetA()
{
    for(int i = 0; i < vertexForces.size(); i++)
    {
        for(int j = 0; j < vertexForces.size(); j++)
        {
            m_A[i][j] = 0;
        }
    }
}

void MainWindow::resetB()
{
    for(int i = 0; i < vertexForces.size(); i++)
    {
        m_b[i][0] = 0;
    }
}

void MainWindow::resetMatrix(double **matrix, int equationsCount, int variablesCount)
{
    for (int i = 0; i< equationsCount; i++)
    {
        for (int j = 0; j < variablesCount; j++)
        {
            matrix[i][j] = 0.0;
        }
    }
}

void MainWindow::fillingMatrix(double **matrix, int equationsCount, int variablesCount)
{
    for (int i = 0; i< equationsCount; i++)
    {
        for (int j = 0; j < variablesCount; j++)
        {
            if(j == variablesCount - 1)
            {
                matrix[i][j] = m_b[i][0];
            }
            else
            {
                matrix[i][j] = m_A[i][j];
            }
        }
    }
}

void MainWindow::fillingA()
{
    for(int i = 0; i < vertexForces.size(); i++)
    {
        if(i == 0)
        {
            m_A[i][i] = (rods.at(i)->E() * rods.at(i)->A()) / rods.at(i)->L();
            m_A[i][i+1] = -1 * m_A[i][i];
            m_A[i+1][i] = -1 * m_A[i][i];
        }

        else if(i == vertexForces.size() - 1)
        {
            m_A[i][i] = (rods.at(i-1)->E() * rods.at(i-1)->A()) / rods.at(i-1)->L();
        }

        else
        {
            m_A[i][i] = ((rods.at(i - 1)->E() * rods.at(i - 1)->A()) / rods.at(i - 1)->L()) + ((rods.at(i)->E() * rods.at(i)->A()) / rods.at(i)->L());
            m_A[i][i+1] = -1 * (rods.at(i)->E() * rods.at(i)->A() / rods.at(i)->L());
            m_A[i+1][i] = -1 * (rods.at(i)->E() * rods.at(i)->A() / rods.at(i)->L());

        }
    }
}

void MainWindow::fillingB()
{
    for(int i = 0; i < vertexForces.size(); i++)
    {
        if(i == 0)
        {
            m_b[i][0] = vertexForces.at(i).value + (rods.at(i)->Q() * rods.at(i)->L())/2;
        }
        else if(i == vertexForces.size() - 1)
        {
            m_b[i][0] = vertexForces.at(i).value + (rods.at(i - 1)->Q() * rods.at(i - 1)->L())/2;
        }
        else
        {
            m_b[i][0] = vertexForces.at(i).value + (rods.at(i - 1)->Q() * rods.at(i - 1)->L())/2 + (rods.at(i)->Q() * rods.at(i)->L())/2;
        }
    }
}

void MainWindow::considerSupportsForB()
{
    if(leftSupportAction->isChecked())
    {
        m_b[0][0] = 0;
    }

    if(rightSupportAction->isChecked())
    {
        m_b[vertexForces.size() - 1][0] = 0;
    }
}

void MainWindow::Gauss(double *delta, double** matrix, int equationsCount, int variablesCount)
{
    //Прямой ход, приведение к верхнетреугольному виду
    double tmp = 0;
    for(int i = 0; i < variablesCount; i++)
    {
        delta[i] = 0.0;
    }
    for (int i = 0; i < equationsCount; i++)
    {
        tmp = matrix[i][i];
        for(int j = equationsCount; j >= i; j--)
        {
            matrix[i][j] /= tmp;
        }
        for(int j = i+1; j < equationsCount; j++)
        {
            tmp = matrix[j][i];
            for(int k = equationsCount; k >= i; k--)
            {
                matrix[j][k] -= tmp * matrix[i][k];
            }
        }
    }
    /*обратный ход*/
    delta[equationsCount - 1] = matrix[equationsCount - 1][equationsCount]; // vertexForces - 1 = rods.size;
    for (int i = equationsCount - 2; i >= 0; i--)
    {
        delta[i] = matrix[i][equationsCount];
        for (int j = i+1; j < equationsCount; j++)
        {
            delta[i] -= matrix[i][j]*delta[j];
        }
    }
}

void MainWindow::drawGraphicsSeparators()
{
    for(int i = 0; i < rods.size(); i++)
    {
        if(i == 0)
        {
            QGraphicsLineItem* firstSeparatorItem = scene->addLine(rods.at(i)->item()->rect().topLeft().x(),
                                                                   lineItem->line().y1(),
                                                                   rods.at(i)->item()->rect().topLeft().x(),
                                                                   lineItem->line().y1() + 300);
            graphicsSeparators.push_back(firstSeparatorItem);

            QGraphicsLineItem* separatorItem = scene->addLine(rods.at(i)->item()->rect().topRight().x(),
                                                              lineItem->line().y1(),
                                                              rods.at(i)->item()->rect().topRight().x(),
                                                              lineItem->line().y1() + 300);
            graphicsSeparators.push_back(separatorItem);
        }
        else
        {
            QGraphicsLineItem* separatorItem = scene->addLine(rods.at(i)->item()->rect().topRight().x(),
                                                              lineItem->line().y1(),
                                                              rods.at(i)->item()->rect().topRight().x(),
                                                              lineItem->line().y1() + 300);
            graphicsSeparators.push_back(separatorItem);
        }
    }
    epureLineX = scene->addLine(graphicsSeparators.at(0)->line().x2(),
                                graphicsSeparators.at(0)->line().y2(),
                                graphicsSeparators.at(graphicsSeparators.size() - 1)->line().x2(),
                                graphicsSeparators.at(graphicsSeparators.size() - 1)->line().y2(),
                                QPen(Qt::DashDotLine));
}

void MainWindow::countNx()
{
    for(int i = 0; i < rods.size(); i++)
    {
        QVector <double> NxVector;
        for(int j = 0; j < COUNT_PARTS * rods.at(i)->L(); j++)
        {
            double Nx = ((rods.at(i)->E()*rods.at(i)->A()) / rods.at(i)->L()) * (delta[i + 1] - delta[i]) + ((rods.at(i)->Q() * rods.at(i)->L()) / 2) * (1 - 2 * ( (j * rods.at(i)->L() / (COUNT_PARTS * rods.at(i)->L()) ) / rods.at(i)->L() ));
            NxVector.push_back(Nx);
        }
        NxVectors.push_back(NxVector);
    }
}

void MainWindow::countUx()
{
    for(int i = 0; i < rods.size(); i++)
    {
        QVector <double> uxVector;
        for(int j = 0; j < COUNT_PARTS * rods.at(i)->L(); j++)
        {
            double ux = delta[i] + ((j * rods.at(i)->L() / (COUNT_PARTS * rods.at(i)->L())) / rods.at(i)->L()) * (delta[i + 1] - delta[i]) + ((rods.at(i)->Q() * rods.at(i)->L() * rods.at(i)->L()) / (2 * rods.at(i)->E() * rods.at(i)->A())) * ((j * rods.at(i)->L() / (COUNT_PARTS * rods.at(i)->L())) / rods.at(i)->L()) * (1 - ((j * rods.at(i)->L() / (COUNT_PARTS * rods.at(i)->L())) / rods.at(i)->L()));
            uxVector.push_back(ux);
        }
        uxVectors.push_back(uxVector);
    }
}

void MainWindow::countSigmaX()
{
    for(int i = 0; i < rods.size(); i++)
    {
        QVector <double> sigmaXVector;
        for(int j = 0; j < COUNT_PARTS * rods.at(i)->L(); j++)
        {
            double sigmaX = NxVectors.at(i).at(j) / rods.at(i)->A();
            sigmaXVector.push_back(sigmaX);
        }
        sigmaXVectors.push_back(sigmaXVector);
    }
}

void MainWindow::drawEpureNx(int epureScale)
{
    for(int i = 0; i < rods.size(); i++)
    {
        for(int j = 0; j < COUNT_PARTS * rods.at(i)->L(); j++)
        {
            QGraphicsLineItem* NxfillingItem = scene->addLine(rods.at(i)->item()->rect().topLeft().x() + FILLING_SHIFT * j,
                                                              epureLineX->line().y1(),
                                                              rods.at(i)->item()->rect().topLeft().x() + FILLING_SHIFT * j,
                                                              epureLineX->line().y1() - NxVectors.at(i).at(j) * epureScale);
            NxfillingItem->setFlag(QGraphicsItem::ItemStacksBehindParent);
            if(j == 0 || j == COUNT_PARTS * rods.at(i)->L() - 1)
            {
                QGraphicsTextItem* NxTextItem = scene->addText("N(x) = " + QString::number(NxVectors.at(i).at(j)));
                NxTextItem->setPos(NxfillingItem->line().x2(), NxfillingItem->line().y2());
                NxTextItems.push_back(NxTextItem);
                if(epureSwitcher->currentText() != NX)
                {
                    NxTextItem->hide();
                }
            }
            NxFillingItems.push_back(NxfillingItem);
            if(epureSwitcher->currentText() != NX)
            {
                NxfillingItem->hide();
            }
        }
    }

    for(int i = 0; i < NxFillingItems.size() - 1; i++)
    {
        QGraphicsLineItem* NxEpureItem = scene->addLine(NxFillingItems.at(i)->line().x2(),
                                                        NxFillingItems.at(i)->line().y2(),
                                                        NxFillingItems.at(i+1)->line().x2(),
                                                        NxFillingItems.at(i+1)->line().y2());
        NxEpureItems.push_back(NxEpureItem);
        if(epureSwitcher->currentText() != NX)
        {
            NxEpureItem->hide();
        }
    }
}

void MainWindow::drawEpureUx(int epureScale)
{
    for(int i = 0; i < rods.size(); i++)
    {
        for(int j = 0; j < COUNT_PARTS * rods.at(i)->L(); j++)
        {
            QGraphicsLineItem* uxFillingItem = scene->addLine(rods.at(i)->item()->rect().topLeft().x() + FILLING_SHIFT * j,
                                                              epureLineX->line().y1(),
                                                              rods.at(i)->item()->rect().topLeft().x() + FILLING_SHIFT * j,
                                                              epureLineX->line().y1() - uxVectors.at(i).at(j) * epureScale); // 50 - множитель для нормального отображения(иначе эпюру будет не видно)
            uxFillingItem->setFlag(QGraphicsItem::ItemStacksBehindParent);
            if(j == 0 || j == COUNT_PARTS * rods.at(i)->L() - 1)
            {
                QGraphicsTextItem* uxTextItem = scene->addText("u(x) = " + QString::number(uxVectors.at(i).at(j)));
                uxTextItem->setPos(uxFillingItem->line().x2(), uxFillingItem->line().y2());
                uxTextItems.push_back(uxTextItem);
                if(epureSwitcher->currentText() != UX)
                {
                    uxTextItem->hide();
                }
            }
            uxFillingItems.push_back(uxFillingItem);
            if(epureSwitcher->currentText() != UX)
            {
                uxFillingItem->hide();
            }
        }
    }


    for(int i = 0; i < uxFillingItems.size() - 1; i++)
    {
        QGraphicsLineItem* uxEpureItem = scene->addLine(uxFillingItems.at(i)->line().x2(),
                                                        uxFillingItems.at(i)->line().y2(),
                                                        uxFillingItems.at(i+1)->line().x2(),
                                                        uxFillingItems.at(i+1)->line().y2());
        uxEpureItems.push_back(uxEpureItem);
        if(epureSwitcher->currentText() != UX)
        {
            uxEpureItem->hide();
        }
    }
}

void MainWindow::drawEpureSigmaX(int epureScale)
{
    for(int i = 0; i < rods.size(); i++)
    {
        for(int j = 0; j < COUNT_PARTS * rods.at(i)->L(); j++)
        {
            QGraphicsLineItem* sigmaXFillingItem = scene->addLine(rods.at(i)->item()->rect().topLeft().x() + FILLING_SHIFT * j,
                                                                  epureLineX->line().y1(),
                                                                  rods.at(i)->item()->rect().topLeft().x() + FILLING_SHIFT * j,
                                                                  epureLineX->line().y1() - sigmaXVectors.at(i).at(j) * epureScale);
            sigmaXFillingItems.push_back(sigmaXFillingItem);
            sigmaXFillingItem->setFlag(QGraphicsItem::ItemStacksBehindParent);
            if(j == 0 || j == COUNT_PARTS * rods.at(i)->L() - 1)
            {
                QGraphicsTextItem* sigmaXTextItem = scene->addText("σ(x) = " + QString::number(sigmaXVectors.at(i).at(j)));
                sigmaXTextItem->setPos(sigmaXFillingItem->line().x2(), sigmaXFillingItem->line().y2());
                sigmaXTextItems.push_back(sigmaXTextItem);
                if(epureSwitcher->currentText() != SIGMAX)
                {
                    sigmaXTextItem->hide();
                }
            }
            if(epureSwitcher->currentText() != SIGMAX)
            {
                sigmaXFillingItem->hide();
            }

        }
    }


    for(int i = 0; i < sigmaXFillingItems.size() - 1; i++)
    {
        QGraphicsLineItem* sigmaXEpureItem = scene->addLine(sigmaXFillingItems.at(i)->line().x2(),
                                                            sigmaXFillingItems.at(i)->line().y2(),
                                                            sigmaXFillingItems.at(i+1)->line().x2(),
                                                            sigmaXFillingItems.at(i+1)->line().y2());
        sigmaXEpureItems.push_back(sigmaXEpureItem);
        if(epureSwitcher->currentText() != SIGMAX)
        {
            sigmaXEpureItem->hide();
        }
    }
}

void MainWindow::closeEvent(QCloseEvent *)
{
    rodCreator->close();
    resultTable->close();
    vertexForceCreator->close();
}

void MainWindow::considerSupportsForA()
{
    if(leftSupportAction->isChecked())
    {
        m_A[0][0] = 1;
        for(int i = 1; i < vertexForces.size(); i++)
        {
            m_A[0][i] = 0;
        }
    }

    if(rightSupportAction->isChecked())
    {
        m_A[vertexForces.size() - 1][vertexForces.size() - 1] = 1;
        for(int i = 1; i < vertexForces.size() - 1; i++)
        {
            m_A[vertexForces.size() - 1][i] = 0;
        }
    }
}

QByteArray MainWindow::createFile() // создание файла расчетов(!)
{
    QByteArray result;
    for(int i = 0; i < rods.size(); i++)
    {
        result.append("--------" + QString::number(i + 1) + " стержень" + "--------\n");
        for(int j = 0; j < NxVectors.at(i).size(); j++)
        {
            result.append(QString::number(NxVectors.at(i).at(j)) + " " + QString::number(uxVectors.at(i).at(j)) + " " + QString::number(sigmaXVectors.at(i).at(j)) + "\n");
        }
    }
    return result;
}

void MainWindow::deleteSlot()
{
    QList<QTableWidgetItem*> listItem = table->selectedItems();
    if(!listItem.isEmpty())
    {
        if(!NxEpureItems.isEmpty())
        {
            deleteAllEpures();

        }
        int selectedRow = listItem.at(0)->row();
        if(selectedRow == table->rowCount() - 1)
        {
            table->removeRow(selectedRow);
            scene->removeItem(rods.at(selectedRow)->item());
            rods.remove(selectedRow);
            if(selectedRow)
            {
                table->selectRow(selectedRow - 1);
            }
        }
        else
        {
            table->removeRow(selectedRow);
            for(int i = selectedRow + 1; i <= table->rowCount(); i++)
            {
                qreal shift = rods.at(selectedRow)->L()*L_SIZE;
                rods.at(i)->moveAboutX(shift);
                QList<QGraphicsItem*> childItems = rods.at(i)->item()->childItems();
                for(int j = 0; j < childItems.size(); j++)
                {
                    childItems[j]->setPos(childItems[j]->x() - shift, childItems[j]->y());
                }
            }
            scene->removeItem(rods.at(selectedRow)->item());
            rods.remove(selectedRow);
        }

        tableForces->removeRow(selectedRow + 1);
        scene->removeItem(vertexForces.at(selectedRow + 1).minusForce);
        scene->removeItem(vertexForces.at(selectedRow + 1).plusForce);
        vertexForces.remove(selectedRow + 1);

        if(rods.isEmpty())
        {
            scene->removeItem(lineItem);
            rightSupportItem->hide();
            leftSupportItem->hide();
            leftSupportAction->setChecked(false);
            rightSupportAction->setChecked(false);
            for(int i = 0; i < vertexForces.size(); i++)
            {
                scene->removeItem(vertexForces.at(i).minusForce);
                scene->removeItem(vertexForces.at(i).plusForce);
            }
            vertexForces.clear();
            for(int i = 0; i < tableForces->rowCount(); i++)
            {
                tableForces->removeRow(i);
            }
        }
        else
        {
            setPosLeftSupport();
            setPosRightSupport();
        }

    }
}



