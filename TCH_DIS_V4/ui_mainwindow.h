/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QLabel *proteck_logo_2;
    QSpacerItem *verticalSpacer_13;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_16;
    QSpacerItem *verticalSpacer_12;
    QSpacerItem *verticalSpacer_15;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *cycleStartButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *cycleStopButton;
    QSpacerItem *horizontalSpacer_10;
    QFrame *line;
    QSpacerItem *horizontalSpacer_6;
    QGridLayout *gridLayout_2;
    QPushButton *xButton;
    QPushButton *mdiButton;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_4;
    QPushButton *jogButton;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_5;
    QPushButton *autoButton;
    QPushButton *plusButton;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *dryRunButton;
    QPushButton *zButton;
    QPushButton *minusButton;
    QPushButton *vvvButton;
    QPushButton *yButton;
    QPushButton *zLockButton;
    QPushButton *drvButton;
    QSpacerItem *horizontalSpacer_7;
    QFrame *line_2;
    QSpacerItem *horizontalSpacer_12;
    QGridLayout *gridLayout_3;
    QPushButton *ncRefButton;
    QPushButton *ncOffsetButton;
    QSpacerItem *verticalSpacer_7;
    QPushButton *retRevButton;
    QPushButton *retForButton;
    QSpacerItem *verticalSpacer_8;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *horizontalSpacer_8;
    QFrame *line_3;
    QSpacerItem *horizontalSpacer_13;
    QGridLayout *gridLayout_4;
    QSpacerItem *verticalSpacer_11;
    QSpacerItem *verticalSpacer_10;
    QSpacerItem *verticalSpacer_9;
    QPushButton *lockRstButton;
    QPushButton *almOvrButton;
    QPushButton *prcEndButton;
    QPushButton *almRstButton;
    QSpacerItem *horizontalSpacer_9;
    QFrame *line_4;
    QSpacerItem *horizontalSpacer_11;
    QGridLayout *gridLayout_5;
    QPushButton *laserOnButton;
    QSpacerItem *verticalSpacer_19;
    QSpacerItem *verticalSpacer_18;
    QSpacerItem *verticalSpacer_2;
    QLabel *laserReadyLamp;
    QSpacerItem *horizontalSpacer_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1920, 720);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1920, 720));
        MainWindow->setMaximumSize(QSize(1920, 720));
        QFont font;
        font.setPointSize(8);
        font.setBold(false);
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(48, 48, 48);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 60, 1781, 601));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        proteck_logo_2 = new QLabel(layoutWidget);
        proteck_logo_2->setObjectName(QString::fromUtf8("proteck_logo_2"));
        proteck_logo_2->setMaximumSize(QSize(300, 100));
        proteck_logo_2->setPixmap(QPixmap(QString::fromUtf8("images/proteck.png")));
        proteck_logo_2->setScaledContents(true);

        verticalLayout->addWidget(proteck_logo_2);

        verticalSpacer_13 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_13);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(280, 40));
        label_2->setPixmap(QPixmap(QString::fromUtf8("images/prolaser dyna.png")));
        label_2->setScaledContents(true);

        verticalLayout->addWidget(label_2);

        verticalSpacer_16 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_16);

        verticalSpacer_12 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_12);

        verticalSpacer_15 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_15);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        cycleStartButton = new QPushButton(layoutWidget);
        cycleStartButton->setObjectName(QString::fromUtf8("cycleStartButton"));
        cycleStartButton->setMinimumSize(QSize(120, 120));
        cycleStartButton->setMaximumSize(QSize(120, 120));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Century Gothic"));
        font1.setPointSize(15);
        font1.setBold(true);
        cycleStartButton->setFont(font1);
        cycleStartButton->setStyleSheet(QString::fromUtf8("background-color: rgb(96, 96, 96);\n"
"color: rgb(48, 48, 48);"));
        cycleStartButton->setIconSize(QSize(120, 120));
        cycleStartButton->setCheckable(false);
        cycleStartButton->setFlat(false);

        horizontalLayout_3->addWidget(cycleStartButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        cycleStopButton = new QPushButton(layoutWidget);
        cycleStopButton->setObjectName(QString::fromUtf8("cycleStopButton"));
        cycleStopButton->setMinimumSize(QSize(120, 120));
        cycleStopButton->setMaximumSize(QSize(120, 120));
        cycleStopButton->setFont(font1);
        cycleStopButton->setStyleSheet(QString::fromUtf8("background-color: rgb(96, 96, 96);\n"
"color: rgb(48, 48, 48);"));
        cycleStopButton->setIconSize(QSize(120, 120));
        cycleStopButton->setCheckable(false);
        cycleStopButton->setFlat(false);

        horizontalLayout_3->addWidget(cycleStopButton);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_10);

        line = new QFrame(layoutWidget);
        line->setObjectName(QString::fromUtf8("line"));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setItalic(true);
        line->setFont(font2);
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        xButton = new QPushButton(layoutWidget);
        xButton->setObjectName(QString::fromUtf8("xButton"));
        xButton->setMinimumSize(QSize(120, 120));
        xButton->setMaximumSize(QSize(120, 120));
        xButton->setFont(font1);
        xButton->setAutoFillBackground(false);
        xButton->setStyleSheet(QString::fromUtf8("background-color: rgb(96, 96, 96);\n"
"color: rgb(48, 48, 48);"));
        xButton->setIconSize(QSize(120, 120));
        xButton->setCheckable(false);
        xButton->setChecked(false);
        xButton->setFlat(false);

        gridLayout_2->addWidget(xButton, 4, 0, 1, 1);

        mdiButton = new QPushButton(layoutWidget);
        mdiButton->setObjectName(QString::fromUtf8("mdiButton"));
        mdiButton->setMinimumSize(QSize(120, 120));
        mdiButton->setMaximumSize(QSize(120, 120));
        mdiButton->setFont(font1);
        mdiButton->setAutoFillBackground(false);
        mdiButton->setStyleSheet(QString::fromUtf8("background-color: rgb(96, 96, 96);\n"
"color: rgb(48, 48, 48);"));
        mdiButton->setIconSize(QSize(120, 120));
        mdiButton->setCheckable(false);
        mdiButton->setChecked(false);
        mdiButton->setFlat(false);

        gridLayout_2->addWidget(mdiButton, 2, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 1, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_4, 3, 0, 1, 1);

        jogButton = new QPushButton(layoutWidget);
        jogButton->setObjectName(QString::fromUtf8("jogButton"));
        jogButton->setMinimumSize(QSize(120, 120));
        jogButton->setMaximumSize(QSize(120, 120));
        jogButton->setFont(font1);
        jogButton->setAutoFillBackground(false);
        jogButton->setStyleSheet(QString::fromUtf8("background-color: rgb(96, 96, 96);\n"
"color: rgb(48, 48, 48);"));
        jogButton->setIconSize(QSize(120, 120));
        jogButton->setCheckable(false);
        jogButton->setChecked(false);
        jogButton->setFlat(false);

        gridLayout_2->addWidget(jogButton, 2, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 0, 1, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_5, 5, 0, 1, 1);

        autoButton = new QPushButton(layoutWidget);
        autoButton->setObjectName(QString::fromUtf8("autoButton"));
        autoButton->setMinimumSize(QSize(120, 120));
        autoButton->setMaximumSize(QSize(120, 120));
        autoButton->setFont(font1);
        autoButton->setAutoFillBackground(false);
        autoButton->setStyleSheet(QString::fromUtf8("background-color: rgb(96, 96, 96);\n"
"color: rgb(48, 48, 48);"));
        autoButton->setIconSize(QSize(120, 120));
        autoButton->setCheckable(false);
        autoButton->setChecked(false);
        autoButton->setFlat(false);

        gridLayout_2->addWidget(autoButton, 2, 4, 1, 1);

        plusButton = new QPushButton(layoutWidget);
        plusButton->setObjectName(QString::fromUtf8("plusButton"));
        plusButton->setMinimumSize(QSize(120, 120));
        plusButton->setMaximumSize(QSize(120, 120));
        plusButton->setFont(font1);
        plusButton->setAutoFillBackground(false);
        plusButton->setStyleSheet(QString::fromUtf8("background-color: rgb(96, 96, 96);\n"
"color: rgb(48, 48, 48);"));
        plusButton->setIconSize(QSize(120, 120));
        plusButton->setCheckable(false);
        plusButton->setChecked(false);
        plusButton->setFlat(false);

        gridLayout_2->addWidget(plusButton, 6, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 0, 3, 1, 1);

        dryRunButton = new QPushButton(layoutWidget);
        dryRunButton->setObjectName(QString::fromUtf8("dryRunButton"));
        dryRunButton->setMinimumSize(QSize(120, 120));
        dryRunButton->setMaximumSize(QSize(120, 120));
        dryRunButton->setFont(font1);
        dryRunButton->setAutoFillBackground(false);
        dryRunButton->setStyleSheet(QString::fromUtf8("background-color: rgb(96, 96, 96);\n"
"color: rgb(48, 48, 48);"));
        dryRunButton->setIconSize(QSize(120, 120));
        dryRunButton->setCheckable(false);
        dryRunButton->setChecked(false);
        dryRunButton->setFlat(false);

        gridLayout_2->addWidget(dryRunButton, 0, 4, 1, 1);

        zButton = new QPushButton(layoutWidget);
        zButton->setObjectName(QString::fromUtf8("zButton"));
        zButton->setMinimumSize(QSize(120, 120));
        zButton->setMaximumSize(QSize(120, 120));
        zButton->setFont(font1);
        zButton->setAutoFillBackground(false);
        zButton->setStyleSheet(QString::fromUtf8("background-color: rgb(96, 96, 96);\n"
"color: rgb(48, 48, 48);"));
        zButton->setIconSize(QSize(120, 120));
        zButton->setCheckable(false);
        zButton->setChecked(false);
        zButton->setFlat(false);

        gridLayout_2->addWidget(zButton, 4, 4, 1, 1);

        minusButton = new QPushButton(layoutWidget);
        minusButton->setObjectName(QString::fromUtf8("minusButton"));
        minusButton->setMinimumSize(QSize(120, 120));
        minusButton->setMaximumSize(QSize(120, 120));
        minusButton->setFont(font1);
        minusButton->setAutoFillBackground(false);
        minusButton->setStyleSheet(QString::fromUtf8("background-color: rgb(96, 96, 96);\n"
"color: rgb(48, 48, 48);"));
        minusButton->setIconSize(QSize(120, 120));
        minusButton->setCheckable(false);
        minusButton->setChecked(false);
        minusButton->setFlat(false);

        gridLayout_2->addWidget(minusButton, 6, 4, 1, 1);

        vvvButton = new QPushButton(layoutWidget);
        vvvButton->setObjectName(QString::fromUtf8("vvvButton"));
        vvvButton->setMinimumSize(QSize(120, 120));
        vvvButton->setMaximumSize(QSize(120, 120));
        vvvButton->setFont(font1);
        vvvButton->setAutoFillBackground(false);
        vvvButton->setStyleSheet(QString::fromUtf8("background-color: rgb(96, 96, 96);\n"
"color: rgb(48, 48, 48);"));
        vvvButton->setIconSize(QSize(120, 120));
        vvvButton->setCheckable(false);
        vvvButton->setChecked(false);
        vvvButton->setFlat(false);

        gridLayout_2->addWidget(vvvButton, 6, 2, 1, 1);

        yButton = new QPushButton(layoutWidget);
        yButton->setObjectName(QString::fromUtf8("yButton"));
        yButton->setMinimumSize(QSize(120, 120));
        yButton->setMaximumSize(QSize(120, 120));
        yButton->setFont(font1);
        yButton->setAutoFillBackground(false);
        yButton->setStyleSheet(QString::fromUtf8("background-color: rgb(96, 96, 96);\n"
"color: rgb(48, 48, 48);"));
        yButton->setIconSize(QSize(120, 120));
        yButton->setCheckable(false);
        yButton->setChecked(false);
        yButton->setFlat(false);

        gridLayout_2->addWidget(yButton, 4, 2, 1, 1);

        zLockButton = new QPushButton(layoutWidget);
        zLockButton->setObjectName(QString::fromUtf8("zLockButton"));
        zLockButton->setMinimumSize(QSize(120, 120));
        zLockButton->setMaximumSize(QSize(120, 120));
        zLockButton->setFont(font1);
        zLockButton->setAutoFillBackground(false);
        zLockButton->setStyleSheet(QString::fromUtf8("background-color: rgb(96, 96, 96);\n"
"color: rgb(48, 48, 48);"));
        zLockButton->setIconSize(QSize(120, 120));
        zLockButton->setCheckable(false);
        zLockButton->setChecked(false);
        zLockButton->setFlat(false);

        gridLayout_2->addWidget(zLockButton, 0, 2, 1, 1);

        drvButton = new QPushButton(layoutWidget);
        drvButton->setObjectName(QString::fromUtf8("drvButton"));
        drvButton->setMinimumSize(QSize(120, 120));
        drvButton->setMaximumSize(QSize(120, 120));
        drvButton->setFont(font1);
        drvButton->setAutoFillBackground(false);
        drvButton->setStyleSheet(QString::fromUtf8("background-color: rgb(96, 96, 96);\n"
"color: rgb(48, 48, 48);"));
        drvButton->setIconSize(QSize(120, 120));
        drvButton->setCheckable(false);
        drvButton->setChecked(false);
        drvButton->setFlat(false);

        gridLayout_2->addWidget(drvButton, 0, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout_2);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);

        line_2 = new QFrame(layoutWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFont(font2);
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_2);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_12);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        ncRefButton = new QPushButton(layoutWidget);
        ncRefButton->setObjectName(QString::fromUtf8("ncRefButton"));
        ncRefButton->setMinimumSize(QSize(120, 120));
        ncRefButton->setMaximumSize(QSize(120, 120));
        ncRefButton->setFont(font1);
        ncRefButton->setAutoFillBackground(false);
        ncRefButton->setStyleSheet(QString::fromUtf8("background-color: rgb(96, 96, 96);\n"
"color: rgb(48, 48, 48);"));
        ncRefButton->setIconSize(QSize(120, 120));
        ncRefButton->setCheckable(false);
        ncRefButton->setChecked(false);
        ncRefButton->setFlat(false);

        gridLayout_3->addWidget(ncRefButton, 0, 0, 1, 1);

        ncOffsetButton = new QPushButton(layoutWidget);
        ncOffsetButton->setObjectName(QString::fromUtf8("ncOffsetButton"));
        ncOffsetButton->setMinimumSize(QSize(120, 120));
        ncOffsetButton->setMaximumSize(QSize(120, 120));
        ncOffsetButton->setFont(font1);
        ncOffsetButton->setAutoFillBackground(false);
        ncOffsetButton->setStyleSheet(QString::fromUtf8("background-color: rgb(96, 96, 96);\n"
"color: rgb(48, 48, 48);"));
        ncOffsetButton->setIconSize(QSize(120, 120));
        ncOffsetButton->setCheckable(false);
        ncOffsetButton->setChecked(false);
        ncOffsetButton->setFlat(false);

        gridLayout_3->addWidget(ncOffsetButton, 2, 0, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_7, 3, 0, 1, 1);

        retRevButton = new QPushButton(layoutWidget);
        retRevButton->setObjectName(QString::fromUtf8("retRevButton"));
        retRevButton->setMinimumSize(QSize(120, 120));
        retRevButton->setMaximumSize(QSize(120, 120));
        retRevButton->setFont(font1);
        retRevButton->setAutoFillBackground(false);
        retRevButton->setStyleSheet(QString::fromUtf8("background-color: rgb(96, 96, 96);\n"
"color: rgb(48, 48, 48);"));
        retRevButton->setIconSize(QSize(120, 120));
        retRevButton->setCheckable(false);
        retRevButton->setChecked(false);
        retRevButton->setFlat(false);

        gridLayout_3->addWidget(retRevButton, 6, 0, 1, 1);

        retForButton = new QPushButton(layoutWidget);
        retForButton->setObjectName(QString::fromUtf8("retForButton"));
        retForButton->setMinimumSize(QSize(120, 120));
        retForButton->setMaximumSize(QSize(120, 120));
        retForButton->setFont(font1);
        retForButton->setAutoFillBackground(false);
        retForButton->setStyleSheet(QString::fromUtf8("background-color: rgb(96, 96, 96);\n"
"color: rgb(48, 48, 48);"));
        retForButton->setIconSize(QSize(120, 120));
        retForButton->setCheckable(false);
        retForButton->setChecked(false);
        retForButton->setFlat(false);

        gridLayout_3->addWidget(retForButton, 4, 0, 1, 1);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_8, 5, 0, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_6, 1, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout_3);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        line_3 = new QFrame(layoutWidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFont(font2);
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_3);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_13);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        verticalSpacer_11 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_11, 5, 0, 1, 1);

        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_10, 3, 0, 1, 1);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_9, 1, 0, 1, 1);

        lockRstButton = new QPushButton(layoutWidget);
        lockRstButton->setObjectName(QString::fromUtf8("lockRstButton"));
        lockRstButton->setMinimumSize(QSize(120, 120));
        lockRstButton->setMaximumSize(QSize(120, 120));
        lockRstButton->setFont(font1);
        lockRstButton->setAutoFillBackground(false);
        lockRstButton->setStyleSheet(QString::fromUtf8("background-color: rgb(96, 96, 96);\n"
"color: rgb(48, 48, 48);"));
        lockRstButton->setIconSize(QSize(120, 120));
        lockRstButton->setCheckable(false);
        lockRstButton->setChecked(false);
        lockRstButton->setFlat(false);

        gridLayout_4->addWidget(lockRstButton, 6, 0, 1, 1);

        almOvrButton = new QPushButton(layoutWidget);
        almOvrButton->setObjectName(QString::fromUtf8("almOvrButton"));
        almOvrButton->setMinimumSize(QSize(120, 120));
        almOvrButton->setMaximumSize(QSize(120, 120));
        almOvrButton->setFont(font1);
        almOvrButton->setAutoFillBackground(false);
        almOvrButton->setStyleSheet(QString::fromUtf8("background-color: rgb(96, 96, 96);\n"
"color: rgb(48, 48, 48);"));
        almOvrButton->setIconSize(QSize(120, 120));
        almOvrButton->setCheckable(false);
        almOvrButton->setChecked(false);
        almOvrButton->setFlat(false);

        gridLayout_4->addWidget(almOvrButton, 2, 0, 1, 1);

        prcEndButton = new QPushButton(layoutWidget);
        prcEndButton->setObjectName(QString::fromUtf8("prcEndButton"));
        prcEndButton->setMinimumSize(QSize(120, 120));
        prcEndButton->setMaximumSize(QSize(120, 120));
        prcEndButton->setFont(font1);
        prcEndButton->setAutoFillBackground(false);
        prcEndButton->setStyleSheet(QString::fromUtf8("background-color: rgb(96, 96, 96);\n"
"color: rgb(48, 48, 48);"));
        prcEndButton->setIconSize(QSize(120, 120));
        prcEndButton->setCheckable(false);
        prcEndButton->setChecked(false);
        prcEndButton->setFlat(false);

        gridLayout_4->addWidget(prcEndButton, 0, 0, 1, 1);

        almRstButton = new QPushButton(layoutWidget);
        almRstButton->setObjectName(QString::fromUtf8("almRstButton"));
        almRstButton->setMinimumSize(QSize(120, 120));
        almRstButton->setMaximumSize(QSize(120, 120));
        almRstButton->setFont(font1);
        almRstButton->setAutoFillBackground(false);
        almRstButton->setStyleSheet(QString::fromUtf8("background-color: rgb(96, 96, 96);\n"
"color: rgb(48, 48, 48);"));
        almRstButton->setIconSize(QSize(120, 120));
        almRstButton->setCheckable(false);
        almRstButton->setChecked(false);
        almRstButton->setFlat(false);

        gridLayout_4->addWidget(almRstButton, 4, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout_4);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_9);

        line_4 = new QFrame(layoutWidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFont(font2);
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_4);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_11);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        laserOnButton = new QPushButton(layoutWidget);
        laserOnButton->setObjectName(QString::fromUtf8("laserOnButton"));
        laserOnButton->setMinimumSize(QSize(130, 130));
        laserOnButton->setMaximumSize(QSize(130, 130));
        laserOnButton->setFont(font1);
        laserOnButton->setAutoFillBackground(false);
        laserOnButton->setStyleSheet(QString::fromUtf8("background-color: rgb(96, 96, 96);\n"
"color: rgb(48, 48, 48);"));
        laserOnButton->setIconSize(QSize(130, 130));
        laserOnButton->setCheckable(true);
        laserOnButton->setChecked(false);
        laserOnButton->setFlat(false);

        gridLayout_5->addWidget(laserOnButton, 1, 0, 1, 1);

        verticalSpacer_19 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_19, 4, 0, 1, 1);

        verticalSpacer_18 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_18, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_2, 2, 0, 1, 1);

        laserReadyLamp = new QLabel(layoutWidget);
        laserReadyLamp->setObjectName(QString::fromUtf8("laserReadyLamp"));
        laserReadyLamp->setMinimumSize(QSize(130, 130));
        laserReadyLamp->setMaximumSize(QSize(130, 130));
        laserReadyLamp->setFont(font1);
        laserReadyLamp->setStyleSheet(QString::fromUtf8("background-color: rgb(96, 96, 96);\n"
"color: rgb(48, 48, 48);\n"
"border-radius: 65px;"));
        laserReadyLamp->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(laserReadyLamp, 3, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout_5);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1920, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Machine Control Panel", nullptr));
        proteck_logo_2->setText(QString());
        label_2->setText(QString());
        cycleStartButton->setText(QCoreApplication::translate("MainWindow", "Cycle\n"
"Start", nullptr));
        cycleStopButton->setText(QCoreApplication::translate("MainWindow", "Cycle\n"
"Stop", nullptr));
        xButton->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        mdiButton->setText(QCoreApplication::translate("MainWindow", "Mdi\n"
"Mode", nullptr));
        jogButton->setText(QCoreApplication::translate("MainWindow", "Jog\n"
"Mode", nullptr));
        autoButton->setText(QCoreApplication::translate("MainWindow", "Auto\n"
"Mode", nullptr));
        plusButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        dryRunButton->setText(QCoreApplication::translate("MainWindow", "Dry\n"
"Run", nullptr));
        zButton->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        minusButton->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        vvvButton->setText(QCoreApplication::translate("MainWindow", "Program\n"
"Zero", nullptr));
        yButton->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        zLockButton->setText(QCoreApplication::translate("MainWindow", "Z Axis\n"
"Lock", nullptr));
        drvButton->setText(QCoreApplication::translate("MainWindow", "Drive\n"
"On", nullptr));
        ncRefButton->setText(QCoreApplication::translate("MainWindow", "NC\n"
"Ref", nullptr));
        ncOffsetButton->setText(QCoreApplication::translate("MainWindow", "NC\n"
"Offset", nullptr));
        retRevButton->setText(QCoreApplication::translate("MainWindow", "Retrace\n"
"Reverse", nullptr));
        retForButton->setText(QCoreApplication::translate("MainWindow", "Retrace\n"
"Forward", nullptr));
        lockRstButton->setText(QCoreApplication::translate("MainWindow", "Lock\n"
"Reset", nullptr));
        almOvrButton->setText(QCoreApplication::translate("MainWindow", "Alarm\n"
"Over", nullptr));
        prcEndButton->setText(QCoreApplication::translate("MainWindow", "Piercing\n"
"End", nullptr));
        almRstButton->setText(QCoreApplication::translate("MainWindow", "Alarm\n"
"Reset", nullptr));
        laserOnButton->setText(QCoreApplication::translate("MainWindow", "Laser\n"
"On", nullptr));
        laserReadyLamp->setText(QCoreApplication::translate("MainWindow", "Laser\n"
"Ready", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
