/********************************************************************************
** Form generated from reading ui file 'MainWindow.ui'
**
** Created: Thu 9. Apr 12:31:32 2009
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QAction *actionConfiguraci_n;
    QAction *actionSalir;
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *inDirLedt;
    QPushButton *browseInBtn;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_3;
    QLabel *label_3;
    QLineEdit *outDirLedt;
    QPushButton *browseOutBtn;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_4;
    QPushButton *executeBtn;
    QPushButton *exitBtn;
    QSpacerItem *horizontalSpacer;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridLayout_5;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *vitrinitaColorBtn;
    QPushButton *leptinitaColorBtn;
    QPushButton *inertinitaColorBtn;
    QLabel *label_7;
    QPushButton *piritaColorBtn;
    QMenuBar *menuBar;
    QMenu *menuArchivo;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
    if (MainWindowClass->objectName().isEmpty())
        MainWindowClass->setObjectName(QString::fromUtf8("MainWindowClass"));
    MainWindowClass->resize(470, 456);
    actionConfiguraci_n = new QAction(MainWindowClass);
    actionConfiguraci_n->setObjectName(QString::fromUtf8("actionConfiguraci_n"));
    actionSalir = new QAction(MainWindowClass);
    actionSalir->setObjectName(QString::fromUtf8("actionSalir"));
    centralWidget = new QWidget(MainWindowClass);
    centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
    gridLayoutWidget = new QWidget(centralWidget);
    gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
    gridLayoutWidget->setGeometry(QRect(10, 10, 441, 51));
    gridLayout = new QGridLayout(gridLayoutWidget);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(11);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    gridLayout->setContentsMargins(0, 0, 0, 0);
    label = new QLabel(gridLayoutWidget);
    label->setObjectName(QString::fromUtf8("label"));

    gridLayout->addWidget(label, 0, 0, 1, 1);

    inDirLedt = new QLineEdit(gridLayoutWidget);
    inDirLedt->setObjectName(QString::fromUtf8("inDirLedt"));

    gridLayout->addWidget(inDirLedt, 1, 0, 1, 1);

    browseInBtn = new QPushButton(gridLayoutWidget);
    browseInBtn->setObjectName(QString::fromUtf8("browseInBtn"));

    gridLayout->addWidget(browseInBtn, 1, 1, 1, 1);

    gridLayoutWidget_2 = new QWidget(centralWidget);
    gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
    gridLayoutWidget_2->setGeometry(QRect(10, 80, 441, 51));
    gridLayout_3 = new QGridLayout(gridLayoutWidget_2);
    gridLayout_3->setSpacing(6);
    gridLayout_3->setMargin(11);
    gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
    gridLayout_3->setContentsMargins(0, 0, 0, 0);
    label_3 = new QLabel(gridLayoutWidget_2);
    label_3->setObjectName(QString::fromUtf8("label_3"));

    gridLayout_3->addWidget(label_3, 0, 0, 1, 1);

    outDirLedt = new QLineEdit(gridLayoutWidget_2);
    outDirLedt->setObjectName(QString::fromUtf8("outDirLedt"));

    gridLayout_3->addWidget(outDirLedt, 1, 0, 1, 1);

    browseOutBtn = new QPushButton(gridLayoutWidget_2);
    browseOutBtn->setObjectName(QString::fromUtf8("browseOutBtn"));

    gridLayout_3->addWidget(browseOutBtn, 1, 1, 1, 1);

    gridLayoutWidget_3 = new QWidget(centralWidget);
    gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
    gridLayoutWidget_3->setGeometry(QRect(10, 360, 441, 31));
    gridLayout_4 = new QGridLayout(gridLayoutWidget_3);
    gridLayout_4->setSpacing(6);
    gridLayout_4->setMargin(11);
    gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
    gridLayout_4->setContentsMargins(0, 0, 0, 0);
    executeBtn = new QPushButton(gridLayoutWidget_3);
    executeBtn->setObjectName(QString::fromUtf8("executeBtn"));

    gridLayout_4->addWidget(executeBtn, 0, 1, 1, 1);

    exitBtn = new QPushButton(gridLayoutWidget_3);
    exitBtn->setObjectName(QString::fromUtf8("exitBtn"));

    gridLayout_4->addWidget(exitBtn, 0, 2, 1, 1);

    horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    gridLayout_4->addItem(horizontalSpacer, 0, 0, 1, 1);

    gridLayoutWidget_4 = new QWidget(centralWidget);
    gridLayoutWidget_4->setObjectName(QString::fromUtf8("gridLayoutWidget_4"));
    gridLayoutWidget_4->setGeometry(QRect(10, 150, 179, 136));
    gridLayout_5 = new QGridLayout(gridLayoutWidget_4);
    gridLayout_5->setSpacing(6);
    gridLayout_5->setMargin(11);
    gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
    gridLayout_5->setContentsMargins(0, 0, 0, 0);
    label_4 = new QLabel(gridLayoutWidget_4);
    label_4->setObjectName(QString::fromUtf8("label_4"));

    gridLayout_5->addWidget(label_4, 0, 0, 1, 1);

    label_5 = new QLabel(gridLayoutWidget_4);
    label_5->setObjectName(QString::fromUtf8("label_5"));

    gridLayout_5->addWidget(label_5, 1, 0, 1, 1);

    label_6 = new QLabel(gridLayoutWidget_4);
    label_6->setObjectName(QString::fromUtf8("label_6"));

    gridLayout_5->addWidget(label_6, 2, 0, 1, 1);

    vitrinitaColorBtn = new QPushButton(gridLayoutWidget_4);
    vitrinitaColorBtn->setObjectName(QString::fromUtf8("vitrinitaColorBtn"));

    gridLayout_5->addWidget(vitrinitaColorBtn, 0, 1, 1, 1);

    leptinitaColorBtn = new QPushButton(gridLayoutWidget_4);
    leptinitaColorBtn->setObjectName(QString::fromUtf8("leptinitaColorBtn"));

    gridLayout_5->addWidget(leptinitaColorBtn, 1, 1, 1, 1);

    inertinitaColorBtn = new QPushButton(gridLayoutWidget_4);
    inertinitaColorBtn->setObjectName(QString::fromUtf8("inertinitaColorBtn"));

    gridLayout_5->addWidget(inertinitaColorBtn, 2, 1, 1, 1);

    label_7 = new QLabel(gridLayoutWidget_4);
    label_7->setObjectName(QString::fromUtf8("label_7"));

    gridLayout_5->addWidget(label_7, 3, 0, 1, 1);

    piritaColorBtn = new QPushButton(gridLayoutWidget_4);
    piritaColorBtn->setObjectName(QString::fromUtf8("piritaColorBtn"));

    gridLayout_5->addWidget(piritaColorBtn, 3, 1, 1, 1);

    MainWindowClass->setCentralWidget(centralWidget);
    menuBar = new QMenuBar(MainWindowClass);
    menuBar->setObjectName(QString::fromUtf8("menuBar"));
    menuBar->setGeometry(QRect(0, 0, 470, 21));
    menuArchivo = new QMenu(menuBar);
    menuArchivo->setObjectName(QString::fromUtf8("menuArchivo"));
    MainWindowClass->setMenuBar(menuBar);
    mainToolBar = new QToolBar(MainWindowClass);
    mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
    MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
    statusBar = new QStatusBar(MainWindowClass);
    statusBar->setObjectName(QString::fromUtf8("statusBar"));
    MainWindowClass->setStatusBar(statusBar);

    menuBar->addAction(menuArchivo->menuAction());
    menuArchivo->addAction(actionConfiguraci_n);
    menuArchivo->addAction(actionSalir);

    retranslateUi(MainWindowClass);

    QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
    MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", 0, QApplication::UnicodeUTF8));
    actionConfiguraci_n->setText(QApplication::translate("MainWindowClass", "Configuraci\303\263n", 0, QApplication::UnicodeUTF8));
    actionSalir->setText(QApplication::translate("MainWindowClass", "Salir", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("MainWindowClass", "Directorio de entrada:", 0, QApplication::UnicodeUTF8));
    browseInBtn->setText(QApplication::translate("MainWindowClass", "Buscar ...", 0, QApplication::UnicodeUTF8));
    label_3->setText(QApplication::translate("MainWindowClass", "Directorio de salida:", 0, QApplication::UnicodeUTF8));
    browseOutBtn->setText(QApplication::translate("MainWindowClass", "Buscar ...", 0, QApplication::UnicodeUTF8));
    executeBtn->setText(QApplication::translate("MainWindowClass", "Ejecutar", 0, QApplication::UnicodeUTF8));
    exitBtn->setText(QApplication::translate("MainWindowClass", "Salir", 0, QApplication::UnicodeUTF8));
    label_4->setText(QApplication::translate("MainWindowClass", "Vitrinita", 0, QApplication::UnicodeUTF8));
    label_5->setText(QApplication::translate("MainWindowClass", "Leptinita", 0, QApplication::UnicodeUTF8));
    label_6->setText(QApplication::translate("MainWindowClass", "Inertinita", 0, QApplication::UnicodeUTF8));
    vitrinitaColorBtn->setText(QApplication::translate("MainWindowClass", "Seleccionar ...", 0, QApplication::UnicodeUTF8));
    leptinitaColorBtn->setText(QApplication::translate("MainWindowClass", "Seleccionar ...", 0, QApplication::UnicodeUTF8));
    inertinitaColorBtn->setText(QApplication::translate("MainWindowClass", "Seleccionar ...", 0, QApplication::UnicodeUTF8));
    label_7->setText(QApplication::translate("MainWindowClass", "Minerales, pirita", 0, QApplication::UnicodeUTF8));
    piritaColorBtn->setText(QApplication::translate("MainWindowClass", "Seleccionar ...", 0, QApplication::UnicodeUTF8));
    menuArchivo->setTitle(QApplication::translate("MainWindowClass", "Archivo", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
