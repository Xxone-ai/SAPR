#ifndef VERTEXFORCECREATOR_H
#define VERTEXFORCECREATOR_H

#include <QtWidgets>

class VertexForceCreator : public QWidget
{
    Q_OBJECT
private:
    QLabel* lbl;
    QComboBox* vertexBox;
    QDoubleSpinBox* forceBox;
    QLabel* lbl1;
    QLabel* lbl2;
    QPushButton* okBtn;
public:
    explicit VertexForceCreator(QWidget *parent = 0);
    ~VertexForceCreator();
    void setVertices(const QStringList& verticesList);
signals:
    void sendForce(int vertex, double force);
public slots:
    void createForceSlot();
};

#endif // VERTEXFORCECREATOR_H
