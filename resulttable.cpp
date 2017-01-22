#include "resulttable.h"

ResultTable::ResultTable(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("Result Table");
    this->setFixedSize(360, 440);
    table = new QTableWidget();
    table->setColumnCount(3);
    QStringList listNamesHeaders;
    listNamesHeaders << "N(x)" << "U(x)" << "σ(x)";

    for(int i = 0; i < 3; i++)
    {
        table->setColumnWidth(i,100);
    }
    table->setHorizontalHeaderLabels(listNamesHeaders);
    table->setFixedWidth(320);
    table->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);

    sectionLbl = new QLabel("Sections: ");
    rodBox = new QComboBox;
    rodLbl = new QLabel("Rod: ");
    QVBoxLayout* vlayout = new QVBoxLayout;
    vlayout->addWidget(rodLbl);
    vlayout->addWidget(rodBox);
    vlayout->addWidget(sectionLbl);
    vlayout->addWidget(table);
    this->setLayout(vlayout);
    connect(rodBox, SIGNAL(currentIndexChanged(int)), this, SLOT(setRodFilter(int)));
}


ResultTable::~ResultTable()
{
    qDebug() << "was in destructor";
}

void ResultTable::setRodFilter(int rodIndex)
{
    while(table->rowCount())
    {
        table->removeRow(0);
    }
    if(Nx_.size())
    {
        for(int i = 0; i < Nx_.at(rodIndex).size(); i++)
        {
            int row = table->rowCount();
            table->setRowCount(table->rowCount() + 1);
            if(sigmaX_.at(rodIndex).at(i) > rods_.at(rodIndex)->sigma())
            {
                for(int j = 0; j < 2; j++)
                {
                    QTableWidgetItem* item = new QTableWidgetItem;
                    item->setFlags(item->flags() & ~Qt::ItemIsEditable);
                    item->setTextAlignment(Qt::AlignCenter);
                    table->setItem(row, j, item);
                }
                table->item(row, 0)->setText(QString::number(Nx_.at(rodIndex).at(i)));
                table->item(row, 1)->setText(QString::number(Ux_.at(rodIndex).at(i)));
                QLabel *labelItem = new QLabel("<font color = red>" + QString::number(sigmaX_.at(rodIndex).at(i)) + "</font>");
                labelItem->setAlignment(Qt::AlignCenter);
                table->setCellWidget(row, 2, labelItem);
            }
            else
            {
                for(int j = 0; j < 3; j++)
                {
                    QTableWidgetItem* item = new QTableWidgetItem;
                    item->setFlags(item->flags() & ~Qt::ItemIsEditable);
                    item->setTextAlignment(Qt::AlignCenter);
                    table->setItem(row, j, item);
                }
                table->item(row, 0)->setText(QString::number(Nx_.at(rodIndex).at(i)));
                table->item(row, 1)->setText(QString::number(Ux_.at(rodIndex).at(i)));
                table->item(row, 2)->setText(QString::number(sigmaX_.at(rodIndex).at(i)));
            }
        }
    }
}

void ResultTable::setRodList(const QStringList &rodList)
{
    rodBox->clear();
    rodBox->addItems(rodList);
}

void ResultTable::setData(const QVector<QVector<double> > &Nx, const QVector<QVector<double> > &Ux, const QVector<QVector<double> > &sigmaX, const QVector<Rod*>& rods)
{
    Nx_ = Nx;
    Ux_ = Ux;
    sigmaX_ = sigmaX;
    rods_ = rods;
    rodBox->setCurrentIndex(0);
    setRodFilter(0);
}

void ResultTable::closeEvent(QCloseEvent *)
{
    Nx_.clear();
    Ux_.clear();
    sigmaX_.clear();
    rodBox->clear();
}
