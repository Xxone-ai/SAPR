/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *newFile;
    QAction *saveFile;
    QAction *saveFileAs;
    QAction *exit;
    QAction *action_14;
    QAction *action_15;
    QAction *action_16;
    QAction *action_17;
    QAction *action_18;
    QAction *action_19;
    QAction *action_20;
    QAction *action_21;
    QAction *loadFromFile;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QTableWidget *rodDataTable;
    QVBoxLayout *verticalLayout;
    QCheckBox *leftTerm;
    QCheckBox *rightTerm;
    QPushButton *addRodButton;
    QPushButton *deleteRodButton;
    QPushButton *clearAll;
    QTableWidget *focusedForces;
    QTableWidget *distributedForces;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1126, 654);
        newFile = new QAction(MainWindow);
        newFile->setObjectName(QString::fromUtf8("newFile"));
        saveFile = new QAction(MainWindow);
        saveFile->setObjectName(QString::fromUtf8("saveFile"));
        saveFileAs = new QAction(MainWindow);
        saveFileAs->setObjectName(QString::fromUtf8("saveFileAs"));
        exit = new QAction(MainWindow);
        exit->setObjectName(QString::fromUtf8("exit"));
        action_14 = new QAction(MainWindow);
        action_14->setObjectName(QString::fromUtf8("action_14"));
        action_15 = new QAction(MainWindow);
        action_15->setObjectName(QString::fromUtf8("action_15"));
        action_16 = new QAction(MainWindow);
        action_16->setObjectName(QString::fromUtf8("action_16"));
        action_17 = new QAction(MainWindow);
        action_17->setObjectName(QString::fromUtf8("action_17"));
        action_18 = new QAction(MainWindow);
        action_18->setObjectName(QString::fromUtf8("action_18"));
        action_19 = new QAction(MainWindow);
        action_19->setObjectName(QString::fromUtf8("action_19"));
        action_20 = new QAction(MainWindow);
        action_20->setObjectName(QString::fromUtf8("action_20"));
        action_21 = new QAction(MainWindow);
        action_21->setObjectName(QString::fromUtf8("action_21"));
        loadFromFile = new QAction(MainWindow);
        loadFromFile->setObjectName(QString::fromUtf8("loadFromFile"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        rodDataTable = new QTableWidget(centralwidget);
        if (rodDataTable->columnCount() < 4)
            rodDataTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        rodDataTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        rodDataTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        rodDataTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        rodDataTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (rodDataTable->rowCount() < 1)
            rodDataTable->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        rodDataTable->setVerticalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        rodDataTable->setItem(0, 0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        rodDataTable->setItem(0, 1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        rodDataTable->setItem(0, 2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        rodDataTable->setItem(0, 3, __qtablewidgetitem8);
        rodDataTable->setObjectName(QString::fromUtf8("rodDataTable"));
        rodDataTable->setMinimumSize(QSize(511, 191));

        horizontalLayout->addWidget(rodDataTable);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        leftTerm = new QCheckBox(centralwidget);
        leftTerm->setObjectName(QString::fromUtf8("leftTerm"));

        verticalLayout->addWidget(leftTerm);

        rightTerm = new QCheckBox(centralwidget);
        rightTerm->setObjectName(QString::fromUtf8("rightTerm"));

        verticalLayout->addWidget(rightTerm);

        addRodButton = new QPushButton(centralwidget);
        addRodButton->setObjectName(QString::fromUtf8("addRodButton"));
        addRodButton->setMaximumSize(QSize(127, 25));

        verticalLayout->addWidget(addRodButton);

        deleteRodButton = new QPushButton(centralwidget);
        deleteRodButton->setObjectName(QString::fromUtf8("deleteRodButton"));
        deleteRodButton->setEnabled(false);
        deleteRodButton->setMaximumSize(QSize(127, 25));

        verticalLayout->addWidget(deleteRodButton);

        clearAll = new QPushButton(centralwidget);
        clearAll->setObjectName(QString::fromUtf8("clearAll"));

        verticalLayout->addWidget(clearAll);


        horizontalLayout->addLayout(verticalLayout);

        focusedForces = new QTableWidget(centralwidget);
        if (focusedForces->columnCount() < 1)
            focusedForces->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        focusedForces->setHorizontalHeaderItem(0, __qtablewidgetitem9);
        if (focusedForces->rowCount() < 2)
            focusedForces->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        focusedForces->setVerticalHeaderItem(0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        focusedForces->setVerticalHeaderItem(1, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        focusedForces->setItem(0, 0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        focusedForces->setItem(1, 0, __qtablewidgetitem13);
        focusedForces->setObjectName(QString::fromUtf8("focusedForces"));
        focusedForces->setMaximumSize(QSize(347, 281));

        horizontalLayout->addWidget(focusedForces);

        distributedForces = new QTableWidget(centralwidget);
        if (distributedForces->columnCount() < 1)
            distributedForces->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        distributedForces->setHorizontalHeaderItem(0, __qtablewidgetitem14);
        if (distributedForces->rowCount() < 1)
            distributedForces->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        distributedForces->setVerticalHeaderItem(0, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        distributedForces->setItem(0, 0, __qtablewidgetitem16);
        distributedForces->setObjectName(QString::fromUtf8("distributedForces"));

        horizontalLayout->addWidget(distributedForces);


        verticalLayout_2->addLayout(horizontalLayout);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        verticalLayout_2->addWidget(graphicsView);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1126, 25));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addSeparator();
        menu->addSeparator();
        menu->addAction(loadFromFile);
        menu->addSeparator();
        menu->addAction(saveFile);
        menu->addSeparator();
        menu->addAction(saveFileAs);
        menu->addSeparator();
        menu->addAction(exit);
        menu->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        newFile->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\275\320\276\320\262\321\213\320\271 \321\204\320\260\320\271\320\273", nullptr));
        saveFile->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        saveFileAs->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\272\320\260\320\272", nullptr));
        exit->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\271\321\202\320\270", nullptr));
        action_14->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\201\321\202\320\265\321\200\320\266\320\265\320\275\321\214", nullptr));
        action_15->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\321\213\320\271 \321\201\321\202\320\265\321\200\320\266\320\265\320\275\321\214", nullptr));
        action_16->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\201\320\265 \321\201\321\202\320\265\321\200\320\266\320\275\320\270", nullptr));
        action_17->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\267\320\260\320\264\320\265\320\273\320\272\321\203 \321\201\320\273\320\265\320\262\320\260", nullptr));
        action_18->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\267\320\260\320\264\320\265\320\273\320\272\321\203 \321\201\320\277\321\200\320\260\320\262\320\260", nullptr));
        action_19->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\267\320\260\320\264\320\265\320\273\320\272\321\203 \321\201\320\273\320\265\320\262\320\260", nullptr));
        action_20->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\267\320\260\320\264\320\265\320\273\320\272\321\203 \321\201\320\277\321\200\320\260\320\262\320\260", nullptr));
        action_21->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\201\320\265 \320\267\320\260\320\264\320\265\320\273\320\272\320\270", nullptr));
        loadFromFile->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\270\320\267 \321\204\320\260\320\271\320\273\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem = rodDataTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "L, \320\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = rodDataTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "A, \320\274^2", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = rodDataTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "\317\203, \320\234\320\237\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = rodDataTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "E, \320\234\320\237\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = rodDataTable->verticalHeaderItem(0);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "1", nullptr));

        const bool __sortingEnabled = rodDataTable->isSortingEnabled();
        rodDataTable->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem5 = rodDataTable->item(0, 0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = rodDataTable->item(0, 1);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = rodDataTable->item(0, 2);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = rodDataTable->item(0, 3);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        rodDataTable->setSortingEnabled(__sortingEnabled);

        leftTerm->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\264\320\265\320\273\320\272\320\260 \321\201\320\273\320\265\320\262\320\260", nullptr));
        rightTerm->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\264\320\265\320\273\320\272\320\260 \321\201\320\277\321\200\320\260\320\262\320\260", nullptr));
        addRodButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\201\321\202\320\265\321\200\320\266\320\265\320\275\321\214", nullptr));
        deleteRodButton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\201\321\202\320\265\321\200\320\266\320\265\320\275\321\214", nullptr));
        clearAll->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\201\321\221", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = focusedForces->horizontalHeaderItem(0);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "F, ql", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = focusedForces->verticalHeaderItem(0);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = focusedForces->verticalHeaderItem(1);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "2", nullptr));

        const bool __sortingEnabled1 = focusedForces->isSortingEnabled();
        focusedForces->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem12 = focusedForces->item(0, 0);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = focusedForces->item(1, 0);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        focusedForces->setSortingEnabled(__sortingEnabled1);

        QTableWidgetItem *___qtablewidgetitem14 = distributedForces->horizontalHeaderItem(0);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "q, \320\235/\320\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = distributedForces->verticalHeaderItem(0);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "1", nullptr));

        const bool __sortingEnabled2 = distributedForces->isSortingEnabled();
        distributedForces->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem16 = distributedForces->item(0, 0);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        distributedForces->setSortingEnabled(__sortingEnabled2);

        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
