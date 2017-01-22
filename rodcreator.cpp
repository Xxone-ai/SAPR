#include "rodcreator.h"

RodCreator::RodCreator(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("Rod Creator");

    regExp.setPattern("([0-9]+)((\\.)?)([0-9]+)([e]{1})((\\+|-)?)([0-9]{2})");
    regExp1.setPattern("[0-9]+((\\.)?)([0-9]?)");
    ok = new QPushButton("OK");
    lEdit = new QLineEdit("3");
    aEdit = new QLineEdit("3");
    eEdit = new QLineEdit("1");
    sigmaEdit = new QLineEdit("1");
    a_lbl = new QLabel("A:");
    l_lbl = new QLabel("L:");
    e_lbl = new QLabel("E:");
    sigma_lbl = new QLabel("σ:");
    q_lbl = new QLabel("q");
    qValueBox = new QDoubleSpinBox;
    qValueBox->setMinimum(-100.0);


    a_lbl->setAlignment(Qt::AlignRight);
    l_lbl->setAlignment(Qt::AlignRight);
    e_lbl->setAlignment(Qt::AlignRight);
    sigma_lbl->setAlignment(Qt::AlignRight);

    lEdit->setValidator(new QRegExpValidator(regExp1));
    aEdit->setValidator(new QRegExpValidator(regExp1));
    eEdit->setValidator(new QRegExpValidator(regExp));
    sigmaEdit->setValidator(new QRegExpValidator(regExp));

    QGridLayout* gridlayout = new QGridLayout;
    gridlayout->addWidget(a_lbl,0,0);
    gridlayout->addWidget(aEdit,0,1);
    gridlayout->addWidget(l_lbl,0,2);
    gridlayout->addWidget(lEdit,0,3);
    gridlayout->addWidget(e_lbl,1,0);
    gridlayout->addWidget(eEdit,1,1);
    gridlayout->addWidget(sigma_lbl,1,2);
    gridlayout->addWidget(sigmaEdit,1,3);

    gridlayout->addWidget(qValueBox,2,1);
    gridlayout->addWidget(q_lbl,2,2);
    gridlayout->addWidget(ok,3,3);
    setLayout(gridlayout);

    connect(ok, SIGNAL(clicked(bool)), this, SLOT(okSlot()));
    connect(lEdit, SIGNAL(textChanged(QString)), this, SLOT(foo(QString)));
}

RodCreator::~RodCreator()
{

}

void RodCreator::okSlot()
{
    double l = double();
    double a = double();
    double e = double();
    double sigma = double();
    double q = double();


    if(!lEdit->text().isEmpty() && !aEdit->text().isEmpty()
    && !eEdit->text().isEmpty() && !sigmaEdit->text().isEmpty())
    {
        l = lEdit->text().toDouble();
        a = aEdit->text().toDouble();
        e = eEdit->text().toDouble();
        sigma = sigmaEdit->text().toDouble();
        q = qValueBox->value();
        if(l && a && e && sigma)
        {
            emit sendRodData(l, a, e, sigma, q);
            this->close();
        }
        else
        {
            QMessageBox msgBox;
            msgBox.setWindowTitle("Ошибка!");
            msgBox.setText("Поля не должны содержать нулевых значений!");
            msgBox.exec();
        }
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Ошибка!");
        msgBox.setText("Заполните пустые поля!");
        msgBox.exec();
    }
}

void RodCreator::foo(QString str)
{
    qDebug() << str;
}
