#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->treeWidget->setColumnCount(2);
    QTreeWidgetItem *imageItem1 = new QTreeWidgetItem(ui->treeWidget,QStringList(QString("图像1")));
    QTreeWidgetItem *imageItem1_1 = new QTreeWidgetItem(imageItem1,QStringList(QString("Band1"))); //子节点1
    imageItem1->setText(0,QString("abc"));
    imageItem1->setText(1,QString("bcd"));
    //imageItem1->addChild(imageItem1_1); //添加子节点
    QTreeWidgetItem *imageItem2 = new QTreeWidgetItem(ui->treeWidget,QStringList(QString("图像2")));
    QTreeWidgetItem *imageItem2_1 = new QTreeWidgetItem(imageItem2,QStringList(QString("Band1"))); //子节点1
    QTreeWidgetItem *imageItem2_2 = new QTreeWidgetItem(imageItem2,QStringList(QString("Band2"))); //子节点2
    imageItem2->addChild(imageItem2_1);
    imageItem2->addChild(imageItem2_2);
    QTreeWidgetItem *imageItem3 = new QTreeWidgetItem(QStringList(QString("图像3")));
    ui->treeWidget->addTopLevelItem(imageItem3);

    connect(ui->treeWidget,SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)),this,SLOT(showSelectedImage(QTreeWidgetItem*,int)));

    //ui->treeWidget->expandAll(); //结点全部展开
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showSelectedImage(QTreeWidgetItem* item,int col)
{
    ui->label->setText(item->data(col,Qt::DisplayRole).toString());
}
