/********************************************************************************
** Form generated from reading UI file 'movietickets.ui'
**
** Created: Sat 29. Dec 18:15:14 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOVIETICKETS_H
#define UI_MOVIETICKETS_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MovieTicketsClass
{
public:
    QAction *actionQuit;
    QAction *actionPrint_This;
    QAction *add_actionPrint_All;
    QAction *add_actionSave_PDF;
    QAction *actionRe_Order;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *add_director_lineEdit;
    QLineEdit *add_title_lineEdit;
    QLineEdit *add_duration_lineEdit;
    QLabel *label_5;
    QLabel *label_6;
    QDoubleSpinBox *add_rating_doubleSpinBox;
    QDateEdit *add_visualization_dateEdit;
    QComboBox *add_year_comboBox;
    QLabel *label_4;
    QPushButton *add_cast_pushButton;
    QPlainTextEdit *add_cast_textEdit;
    QPlainTextEdit *add_plot_textEdit;
    QLabel *label_9;
    QFrame *line;
    QLabel *label_7;
    QLineEdit *add_image_lineEdit;
    QPushButton *add_image_pushButton;
    QLabel *add_image_label;
    QPushButton *add_save_pushButton;
    QPushButton *add_reset_pushButton;
    QWidget *tab_3;
    QScrollArea *scrollArea_5;
    QWidget *scrollAreaWidgetContents_5;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLineEdit *edit_director_lineEdit;
    QLineEdit *edit_title_lineEdit;
    QLineEdit *edit_duration_lineEdit;
    QLabel *label_20;
    QLabel *label_21;
    QDoubleSpinBox *edit_rating_doubleSpinBox;
    QDateEdit *edit_visualization_dateEdit;
    QComboBox *edit_year_comboBox;
    QLabel *label_22;
    QPushButton *edit_cast_pushButton;
    QPlainTextEdit *edit_cast_textEdit;
    QPlainTextEdit *edit_plot_textEdit;
    QLabel *label_23;
    QLabel *edit_image_label;
    QFrame *line_5;
    QPushButton *edit_save_pushButton;
    QLineEdit *edit_image_lineEdit;
    QLabel *label_24;
    QPushButton *edit_image_pushButton;
    QPushButton *edit_reset_pushButton;
    QPushButton *edit_remove_pushButton;
    QPushButton *edit_next_pushButton;
    QPushButton *edit_previous_pushButton;
    QWidget *tab_2;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QLabel *view_director_label;
    QLabel *view_year_label;
    QLabel *view_title_label;
    QLabel *view_duration_label;
    QLabel *view_rating_label;
    QLabel *view_visualization_label;
    QLabel *view_plot_label;
    QLabel *view_cast_label;
    QTextBrowser *view_plot_textBrowser;
    QTextBrowser *view_cast_textBrowser;
    QFrame *line_2;
    QLabel *view_image_label;
    QPushButton *view_next_pushButton;
    QPushButton *view_previous_pushButton;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuPrint;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MovieTicketsClass)
    {
        if (MovieTicketsClass->objectName().isEmpty())
            MovieTicketsClass->setObjectName(QString::fromUtf8("MovieTicketsClass"));
        MovieTicketsClass->resize(669, 533);
        actionQuit = new QAction(MovieTicketsClass);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionPrint_This = new QAction(MovieTicketsClass);
        actionPrint_This->setObjectName(QString::fromUtf8("actionPrint_This"));
        add_actionPrint_All = new QAction(MovieTicketsClass);
        add_actionPrint_All->setObjectName(QString::fromUtf8("add_actionPrint_All"));
        add_actionSave_PDF = new QAction(MovieTicketsClass);
        add_actionSave_PDF->setObjectName(QString::fromUtf8("add_actionSave_PDF"));
        actionRe_Order = new QAction(MovieTicketsClass);
        actionRe_Order->setObjectName(QString::fromUtf8("actionRe_Order"));
        centralWidget = new QWidget(MovieTicketsClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 0, 651, 481));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        scrollArea = new QScrollArea(tab);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(10, 10, 341, 441));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 339, 439));
        label_3 = new QLabel(scrollAreaWidgetContents);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 60, 46, 13));
        label_2 = new QLabel(scrollAreaWidgetContents);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 110, 46, 13));
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 46, 13));
        add_director_lineEdit = new QLineEdit(scrollAreaWidgetContents);
        add_director_lineEdit->setObjectName(QString::fromUtf8("add_director_lineEdit"));
        add_director_lineEdit->setGeometry(QRect(10, 80, 321, 20));
        add_title_lineEdit = new QLineEdit(scrollAreaWidgetContents);
        add_title_lineEdit->setObjectName(QString::fromUtf8("add_title_lineEdit"));
        add_title_lineEdit->setGeometry(QRect(10, 30, 321, 20));
        add_duration_lineEdit = new QLineEdit(scrollAreaWidgetContents);
        add_duration_lineEdit->setObjectName(QString::fromUtf8("add_duration_lineEdit"));
        add_duration_lineEdit->setGeometry(QRect(130, 130, 71, 20));
        label_5 = new QLabel(scrollAreaWidgetContents);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(130, 110, 46, 13));
        label_6 = new QLabel(scrollAreaWidgetContents);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(260, 110, 71, 16));
        add_rating_doubleSpinBox = new QDoubleSpinBox(scrollAreaWidgetContents);
        add_rating_doubleSpinBox->setObjectName(QString::fromUtf8("add_rating_doubleSpinBox"));
        add_rating_doubleSpinBox->setGeometry(QRect(260, 130, 71, 22));
        add_rating_doubleSpinBox->setDecimals(1);
        add_rating_doubleSpinBox->setMaximum(10);
        add_rating_doubleSpinBox->setSingleStep(0.1);
        add_rating_doubleSpinBox->setValue(5);
        add_visualization_dateEdit = new QDateEdit(scrollAreaWidgetContents);
        add_visualization_dateEdit->setObjectName(QString::fromUtf8("add_visualization_dateEdit"));
        add_visualization_dateEdit->setGeometry(QRect(10, 190, 110, 22));
        add_visualization_dateEdit->setDate(QDate(2012, 1, 1));
        add_year_comboBox = new QComboBox(scrollAreaWidgetContents);
        add_year_comboBox->setObjectName(QString::fromUtf8("add_year_comboBox"));
        add_year_comboBox->setGeometry(QRect(10, 130, 69, 22));
        label_4 = new QLabel(scrollAreaWidgetContents);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 170, 91, 16));
        add_cast_pushButton = new QPushButton(scrollAreaWidgetContents);
        add_cast_pushButton->setObjectName(QString::fromUtf8("add_cast_pushButton"));
        add_cast_pushButton->setGeometry(QRect(170, 190, 161, 23));
        add_cast_textEdit = new QPlainTextEdit(scrollAreaWidgetContents);
        add_cast_textEdit->setObjectName(QString::fromUtf8("add_cast_textEdit"));
        add_cast_textEdit->setGeometry(QRect(10, 220, 321, 91));
        add_plot_textEdit = new QPlainTextEdit(scrollAreaWidgetContents);
        add_plot_textEdit->setObjectName(QString::fromUtf8("add_plot_textEdit"));
        add_plot_textEdit->setGeometry(QRect(10, 340, 321, 91));
        label_9 = new QLabel(scrollAreaWidgetContents);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 320, 91, 16));
        scrollArea->setWidget(scrollAreaWidgetContents);
        line = new QFrame(tab);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(350, 10, 20, 441));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        label_7 = new QLabel(tab);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(370, 350, 51, 16));
        add_image_lineEdit = new QLineEdit(tab);
        add_image_lineEdit->setObjectName(QString::fromUtf8("add_image_lineEdit"));
        add_image_lineEdit->setGeometry(QRect(370, 370, 221, 20));
        add_image_pushButton = new QPushButton(tab);
        add_image_pushButton->setObjectName(QString::fromUtf8("add_image_pushButton"));
        add_image_pushButton->setGeometry(QRect(594, 370, 41, 23));
        add_image_label = new QLabel(tab);
        add_image_label->setObjectName(QString::fromUtf8("add_image_label"));
        add_image_label->setGeometry(QRect(370, 10, 271, 331));
        add_save_pushButton = new QPushButton(tab);
        add_save_pushButton->setObjectName(QString::fromUtf8("add_save_pushButton"));
        add_save_pushButton->setGeometry(QRect(560, 420, 75, 23));
        add_reset_pushButton = new QPushButton(tab);
        add_reset_pushButton->setObjectName(QString::fromUtf8("add_reset_pushButton"));
        add_reset_pushButton->setGeometry(QRect(470, 420, 75, 23));
        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        scrollArea_5 = new QScrollArea(tab_3);
        scrollArea_5->setObjectName(QString::fromUtf8("scrollArea_5"));
        scrollArea_5->setGeometry(QRect(10, 10, 341, 441));
        scrollArea_5->setWidgetResizable(true);
        scrollAreaWidgetContents_5 = new QWidget();
        scrollAreaWidgetContents_5->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_5"));
        scrollAreaWidgetContents_5->setGeometry(QRect(0, 0, 339, 439));
        label_17 = new QLabel(scrollAreaWidgetContents_5);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(10, 60, 46, 13));
        label_18 = new QLabel(scrollAreaWidgetContents_5);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(10, 110, 46, 13));
        label_19 = new QLabel(scrollAreaWidgetContents_5);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(10, 10, 46, 13));
        edit_director_lineEdit = new QLineEdit(scrollAreaWidgetContents_5);
        edit_director_lineEdit->setObjectName(QString::fromUtf8("edit_director_lineEdit"));
        edit_director_lineEdit->setGeometry(QRect(10, 80, 321, 20));
        edit_title_lineEdit = new QLineEdit(scrollAreaWidgetContents_5);
        edit_title_lineEdit->setObjectName(QString::fromUtf8("edit_title_lineEdit"));
        edit_title_lineEdit->setGeometry(QRect(10, 30, 321, 20));
        edit_duration_lineEdit = new QLineEdit(scrollAreaWidgetContents_5);
        edit_duration_lineEdit->setObjectName(QString::fromUtf8("edit_duration_lineEdit"));
        edit_duration_lineEdit->setGeometry(QRect(130, 130, 71, 20));
        label_20 = new QLabel(scrollAreaWidgetContents_5);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(130, 110, 46, 13));
        label_21 = new QLabel(scrollAreaWidgetContents_5);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(260, 110, 71, 16));
        edit_rating_doubleSpinBox = new QDoubleSpinBox(scrollAreaWidgetContents_5);
        edit_rating_doubleSpinBox->setObjectName(QString::fromUtf8("edit_rating_doubleSpinBox"));
        edit_rating_doubleSpinBox->setGeometry(QRect(260, 130, 71, 22));
        edit_rating_doubleSpinBox->setDecimals(1);
        edit_rating_doubleSpinBox->setMaximum(10);
        edit_rating_doubleSpinBox->setSingleStep(0.1);
        edit_rating_doubleSpinBox->setValue(5);
        edit_visualization_dateEdit = new QDateEdit(scrollAreaWidgetContents_5);
        edit_visualization_dateEdit->setObjectName(QString::fromUtf8("edit_visualization_dateEdit"));
        edit_visualization_dateEdit->setGeometry(QRect(10, 190, 110, 22));
        edit_visualization_dateEdit->setDate(QDate(2012, 1, 1));
        edit_year_comboBox = new QComboBox(scrollAreaWidgetContents_5);
        edit_year_comboBox->setObjectName(QString::fromUtf8("edit_year_comboBox"));
        edit_year_comboBox->setGeometry(QRect(10, 130, 69, 22));
        label_22 = new QLabel(scrollAreaWidgetContents_5);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(10, 170, 91, 16));
        edit_cast_pushButton = new QPushButton(scrollAreaWidgetContents_5);
        edit_cast_pushButton->setObjectName(QString::fromUtf8("edit_cast_pushButton"));
        edit_cast_pushButton->setGeometry(QRect(170, 190, 161, 23));
        edit_cast_textEdit = new QPlainTextEdit(scrollAreaWidgetContents_5);
        edit_cast_textEdit->setObjectName(QString::fromUtf8("edit_cast_textEdit"));
        edit_cast_textEdit->setGeometry(QRect(10, 220, 321, 91));
        edit_plot_textEdit = new QPlainTextEdit(scrollAreaWidgetContents_5);
        edit_plot_textEdit->setObjectName(QString::fromUtf8("edit_plot_textEdit"));
        edit_plot_textEdit->setGeometry(QRect(10, 340, 321, 91));
        label_23 = new QLabel(scrollAreaWidgetContents_5);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(10, 320, 91, 16));
        scrollArea_5->setWidget(scrollAreaWidgetContents_5);
        edit_image_label = new QLabel(tab_3);
        edit_image_label->setObjectName(QString::fromUtf8("edit_image_label"));
        edit_image_label->setGeometry(QRect(370, 10, 271, 331));
        line_5 = new QFrame(tab_3);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(350, 10, 20, 441));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);
        edit_save_pushButton = new QPushButton(tab_3);
        edit_save_pushButton->setObjectName(QString::fromUtf8("edit_save_pushButton"));
        edit_save_pushButton->setGeometry(QRect(560, 400, 75, 23));
        edit_image_lineEdit = new QLineEdit(tab_3);
        edit_image_lineEdit->setObjectName(QString::fromUtf8("edit_image_lineEdit"));
        edit_image_lineEdit->setGeometry(QRect(370, 370, 221, 20));
        label_24 = new QLabel(tab_3);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(370, 350, 51, 16));
        edit_image_pushButton = new QPushButton(tab_3);
        edit_image_pushButton->setObjectName(QString::fromUtf8("edit_image_pushButton"));
        edit_image_pushButton->setGeometry(QRect(594, 370, 41, 23));
        edit_reset_pushButton = new QPushButton(tab_3);
        edit_reset_pushButton->setObjectName(QString::fromUtf8("edit_reset_pushButton"));
        edit_reset_pushButton->setGeometry(QRect(470, 400, 75, 23));
        edit_remove_pushButton = new QPushButton(tab_3);
        edit_remove_pushButton->setObjectName(QString::fromUtf8("edit_remove_pushButton"));
        edit_remove_pushButton->setEnabled(true);
        edit_remove_pushButton->setGeometry(QRect(380, 400, 75, 23));
        edit_next_pushButton = new QPushButton(tab_3);
        edit_next_pushButton->setObjectName(QString::fromUtf8("edit_next_pushButton"));
        edit_next_pushButton->setGeometry(QRect(516, 430, 121, 23));
        edit_previous_pushButton = new QPushButton(tab_3);
        edit_previous_pushButton->setObjectName(QString::fromUtf8("edit_previous_pushButton"));
        edit_previous_pushButton->setGeometry(QRect(370, 430, 131, 23));
        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        scrollArea_2 = new QScrollArea(tab_2);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setGeometry(QRect(10, 10, 321, 441));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 319, 439));
        view_director_label = new QLabel(scrollAreaWidgetContents_2);
        view_director_label->setObjectName(QString::fromUtf8("view_director_label"));
        view_director_label->setGeometry(QRect(10, 30, 301, 16));
        view_year_label = new QLabel(scrollAreaWidgetContents_2);
        view_year_label->setObjectName(QString::fromUtf8("view_year_label"));
        view_year_label->setGeometry(QRect(10, 50, 81, 16));
        view_title_label = new QLabel(scrollAreaWidgetContents_2);
        view_title_label->setObjectName(QString::fromUtf8("view_title_label"));
        view_title_label->setGeometry(QRect(10, 10, 301, 16));
        view_duration_label = new QLabel(scrollAreaWidgetContents_2);
        view_duration_label->setObjectName(QString::fromUtf8("view_duration_label"));
        view_duration_label->setGeometry(QRect(90, 50, 111, 16));
        view_rating_label = new QLabel(scrollAreaWidgetContents_2);
        view_rating_label->setObjectName(QString::fromUtf8("view_rating_label"));
        view_rating_label->setGeometry(QRect(200, 50, 111, 16));
        view_visualization_label = new QLabel(scrollAreaWidgetContents_2);
        view_visualization_label->setObjectName(QString::fromUtf8("view_visualization_label"));
        view_visualization_label->setGeometry(QRect(10, 70, 301, 16));
        view_plot_label = new QLabel(scrollAreaWidgetContents_2);
        view_plot_label->setObjectName(QString::fromUtf8("view_plot_label"));
        view_plot_label->setGeometry(QRect(10, 90, 91, 16));
        view_cast_label = new QLabel(scrollAreaWidgetContents_2);
        view_cast_label->setObjectName(QString::fromUtf8("view_cast_label"));
        view_cast_label->setGeometry(QRect(10, 220, 321, 16));
        view_plot_textBrowser = new QTextBrowser(scrollAreaWidgetContents_2);
        view_plot_textBrowser->setObjectName(QString::fromUtf8("view_plot_textBrowser"));
        view_plot_textBrowser->setGeometry(QRect(10, 110, 301, 101));
        view_cast_textBrowser = new QTextBrowser(scrollAreaWidgetContents_2);
        view_cast_textBrowser->setObjectName(QString::fromUtf8("view_cast_textBrowser"));
        view_cast_textBrowser->setGeometry(QRect(10, 240, 301, 191));
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);
        line_2 = new QFrame(tab_2);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(330, 10, 20, 441));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        view_image_label = new QLabel(tab_2);
        view_image_label->setObjectName(QString::fromUtf8("view_image_label"));
        view_image_label->setGeometry(QRect(350, 10, 291, 401));
        view_next_pushButton = new QPushButton(tab_2);
        view_next_pushButton->setObjectName(QString::fromUtf8("view_next_pushButton"));
        view_next_pushButton->setGeometry(QRect(510, 430, 121, 23));
        view_previous_pushButton = new QPushButton(tab_2);
        view_previous_pushButton->setObjectName(QString::fromUtf8("view_previous_pushButton"));
        view_previous_pushButton->setGeometry(QRect(354, 430, 131, 23));
        tabWidget->addTab(tab_2, QString());
        MovieTicketsClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MovieTicketsClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 669, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuPrint = new QMenu(menuBar);
        menuPrint->setObjectName(QString::fromUtf8("menuPrint"));
        MovieTicketsClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MovieTicketsClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MovieTicketsClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MovieTicketsClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MovieTicketsClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuPrint->menuAction());
        menuFile->addAction(actionRe_Order);
        menuFile->addAction(actionQuit);
        menuPrint->addAction(actionPrint_This);
        menuPrint->addAction(add_actionPrint_All);

        retranslateUi(MovieTicketsClass);

        tabWidget->setCurrentIndex(2);
        add_year_comboBox->setCurrentIndex(0);
        edit_year_comboBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MovieTicketsClass);
    } // setupUi

    void retranslateUi(QMainWindow *MovieTicketsClass)
    {
        MovieTicketsClass->setWindowTitle(QApplication::translate("MovieTicketsClass", "MovieTickets", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("MovieTicketsClass", "Quit", 0, QApplication::UnicodeUTF8));
        actionPrint_This->setText(QApplication::translate("MovieTicketsClass", "Print This", 0, QApplication::UnicodeUTF8));
        add_actionPrint_All->setText(QApplication::translate("MovieTicketsClass", "Print All", 0, QApplication::UnicodeUTF8));
        add_actionSave_PDF->setText(QApplication::translate("MovieTicketsClass", "Save PDF", 0, QApplication::UnicodeUTF8));
        actionRe_Order->setText(QApplication::translate("MovieTicketsClass", "Re-Order", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MovieTicketsClass", "Director:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MovieTicketsClass", "Year:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MovieTicketsClass", "Title:", 0, QApplication::UnicodeUTF8));
        add_director_lineEdit->setText(QString());
        add_duration_lineEdit->setText(QString());
        label_5->setText(QApplication::translate("MovieTicketsClass", "Duration:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MovieTicketsClass", "IMDB Rating:", 0, QApplication::UnicodeUTF8));
        add_year_comboBox->clear();
        add_year_comboBox->insertItems(0, QStringList()
         << QApplication::translate("MovieTicketsClass", "2012", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MovieTicketsClass", "2011", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MovieTicketsClass", "2010", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MovieTicketsClass", "2009", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MovieTicketsClass", "2008", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MovieTicketsClass", "2007", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MovieTicketsClass", "2006", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MovieTicketsClass", "2005", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MovieTicketsClass", "2004", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MovieTicketsClass", "2003", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MovieTicketsClass", "2002", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MovieTicketsClass", "2001", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MovieTicketsClass", "2000", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MovieTicketsClass", "1999", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MovieTicketsClass", "1998", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MovieTicketsClass", "1997", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MovieTicketsClass", "1996", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MovieTicketsClass", "1995", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MovieTicketsClass", "1994", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MovieTicketsClass", "1993", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MovieTicketsClass", "1992", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MovieTicketsClass", "1991", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MovieTicketsClass", "1990", 0, QApplication::UnicodeUTF8)
        );
        label_4->setText(QApplication::translate("MovieTicketsClass", "Visualization Date:", 0, QApplication::UnicodeUTF8));
        add_cast_pushButton->setText(QApplication::translate("MovieTicketsClass", "Add Cast", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MovieTicketsClass", "Plot", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MovieTicketsClass", "File Name:", 0, QApplication::UnicodeUTF8));
        add_image_pushButton->setText(QApplication::translate("MovieTicketsClass", "Add", 0, QApplication::UnicodeUTF8));
        add_image_label->setText(QString());
        add_save_pushButton->setText(QApplication::translate("MovieTicketsClass", "Save", 0, QApplication::UnicodeUTF8));
        add_reset_pushButton->setText(QApplication::translate("MovieTicketsClass", "Reset", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MovieTicketsClass", "Add Movies", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("MovieTicketsClass", "Director:", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("MovieTicketsClass", "Year:", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("MovieTicketsClass", "Title:", 0, QApplication::UnicodeUTF8));
        edit_director_lineEdit->setText(QString());
        edit_duration_lineEdit->setText(QString());
        label_20->setText(QApplication::translate("MovieTicketsClass", "Duration:", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("MovieTicketsClass", "IMDB Rating:", 0, QApplication::UnicodeUTF8));
        edit_year_comboBox->clear();
        edit_year_comboBox->insertItems(0, QStringList()
         << QApplication::translate("MovieTicketsClass", "2012", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MovieTicketsClass", "2011", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MovieTicketsClass", "2010", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MovieTicketsClass", "2009", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MovieTicketsClass", "2008", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MovieTicketsClass", "2007", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MovieTicketsClass", "2006", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MovieTicketsClass", "2005", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MovieTicketsClass", "2004", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MovieTicketsClass", "2003", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MovieTicketsClass", "2002", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MovieTicketsClass", "2001", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MovieTicketsClass", "2000", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MovieTicketsClass", "1999", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MovieTicketsClass", "1998", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MovieTicketsClass", "1997", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MovieTicketsClass", "1996", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MovieTicketsClass", "1995", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MovieTicketsClass", "1994", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MovieTicketsClass", "1993", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MovieTicketsClass", "1992", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MovieTicketsClass", "1991", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MovieTicketsClass", "1990", 0, QApplication::UnicodeUTF8)
        );
        label_22->setText(QApplication::translate("MovieTicketsClass", "Visualization Date:", 0, QApplication::UnicodeUTF8));
        edit_cast_pushButton->setText(QApplication::translate("MovieTicketsClass", "Add Cast", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("MovieTicketsClass", "Plot", 0, QApplication::UnicodeUTF8));
        edit_image_label->setText(QString());
        edit_save_pushButton->setText(QApplication::translate("MovieTicketsClass", "Save", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("MovieTicketsClass", "File Name:", 0, QApplication::UnicodeUTF8));
        edit_image_pushButton->setText(QApplication::translate("MovieTicketsClass", "Add", 0, QApplication::UnicodeUTF8));
        edit_reset_pushButton->setText(QApplication::translate("MovieTicketsClass", "Reset", 0, QApplication::UnicodeUTF8));
        edit_remove_pushButton->setText(QApplication::translate("MovieTicketsClass", "Remove", 0, QApplication::UnicodeUTF8));
        edit_next_pushButton->setText(QApplication::translate("MovieTicketsClass", "Next", 0, QApplication::UnicodeUTF8));
        edit_previous_pushButton->setText(QApplication::translate("MovieTicketsClass", "Previous", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MovieTicketsClass", "Edit Movies", 0, QApplication::UnicodeUTF8));
        view_director_label->setText(QApplication::translate("MovieTicketsClass", "Director:", 0, QApplication::UnicodeUTF8));
        view_year_label->setText(QApplication::translate("MovieTicketsClass", "Year:", 0, QApplication::UnicodeUTF8));
        view_title_label->setText(QApplication::translate("MovieTicketsClass", "Title:", 0, QApplication::UnicodeUTF8));
        view_duration_label->setText(QApplication::translate("MovieTicketsClass", "Duration:", 0, QApplication::UnicodeUTF8));
        view_rating_label->setText(QApplication::translate("MovieTicketsClass", "IMDB Rating:", 0, QApplication::UnicodeUTF8));
        view_visualization_label->setText(QApplication::translate("MovieTicketsClass", "Visualization Date:", 0, QApplication::UnicodeUTF8));
        view_plot_label->setText(QApplication::translate("MovieTicketsClass", "Plot:", 0, QApplication::UnicodeUTF8));
        view_cast_label->setText(QApplication::translate("MovieTicketsClass", "Cast:", 0, QApplication::UnicodeUTF8));
        view_image_label->setText(QString());
        view_next_pushButton->setText(QApplication::translate("MovieTicketsClass", "Next", 0, QApplication::UnicodeUTF8));
        view_previous_pushButton->setText(QApplication::translate("MovieTicketsClass", "Previous", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MovieTicketsClass", "View Movies", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MovieTicketsClass", "File", 0, QApplication::UnicodeUTF8));
        menuPrint->setTitle(QApplication::translate("MovieTicketsClass", "Print", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MovieTicketsClass: public Ui_MovieTicketsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOVIETICKETS_H
