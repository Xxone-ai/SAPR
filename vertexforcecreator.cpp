#include "vertexforcecreator.h"

VertexForceCreator::VertexForceCreator(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("Vertex Force Creator");
    lbl = new QLabel("In vertex #");
    vertexBox = new QComboBox;
    lbl1 = new QLabel(":");
    lbl2 = new QLabel("F");
    forceBox = new QDoubleSpinBox;
    forceBox->setMinimum(-100.0);
    okBtn = new QPushButton("Create");
    QHBoxLayout* hlayout = new QHBoxLayout;
    hlayout->addWidget(lbl);
    hlayout->addWidget(vertexBox);
    hlayout->addWidget(lbl1);
    hlayout->addWidget(forceBox);
    hlayout->addWidget(lbl2);
    QHBoxLayout* btnslayout = new QHBoxLayout;
    QSpacerItem* spacerItem = new QSpacerItem(0,0, QSizePolicy::Expanding,QSizePolicy::Maximum);
    btnslayout->addSpacerItem(spacerItem);
    btnslayout->addWidget(okBtn);
    QVBoxLayout* mainlayout = new QVBoxLayout;
    mainlayout->addLayout(hlayout);
    mainlayout->addLayout(btnslayout);
    this->setLayout(mainlayout);
    connect(okBtn, SIGNAL(clicked()), this, SLOT(createForceSlot()));
}

VertexForceCreator::~VertexForceCreator()
{

}

void VertexForceCreator::setVertices(const QStringList &verticesList)
{
    vertexBox->clear();
    vertexBox->addItems(verticesList);
}

void VertexForceCreator::createForceSlot()
{
    if(!vertexBox->currentText().isEmpty())
    {
       int index = vertexBox->currentText().toInt();
       qDebug() << "index is" << index;
       index--;
       emit sendForce(index, forceBox->value());
       this->close();
    }
}
