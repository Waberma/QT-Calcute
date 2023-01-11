#include "mainwindow.h"
#include "ui_mainwindow.h"

double num_first;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(digin_num()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(digin_num()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(digin_num()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(digin_num()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(digin_num()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(digin_num()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(digin_num()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(digin_num()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(digin_num()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(digin_num()));
    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(math_operation()));
    connect(ui->pushButton_min,SIGNAL(clicked()),this,SLOT(math_operation()));
    connect(ui->pushButton_x,SIGNAL(clicked()),this,SLOT(math_operation()));
    connect(ui->pushButton_dev,SIGNAL(clicked()),this,SLOT(math_operation()));
    connect(ui->pushButton_pm,SIGNAL(clicked()),this,SLOT(operation()));
    connect(ui->pushButton_percent,SIGNAL(clicked()),this,SLOT(operation()));

    ui->pushButton_min->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_x->setCheckable(true);
    ui->pushButton_dev->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digin_num()
{
    QPushButton *butt = (QPushButton *) sender();

    double all_num;
    QString newlabel;

    if(ui->label->text().contains(".") && butt->text() == "0")
    {
        newlabel = ui->label->text() + butt->text();
    }
    else
    {
        all_num = (ui->label->text() + butt->text()).toDouble();
        newlabel = QString::number(all_num, 'g', 15);
    }

    ui->label->setText(newlabel);
}

void MainWindow::on_pushButton_point_clicked()
{
    if(!ui->label->text().contains("."))
    {
        ui->label->setText(ui->label->text() + ".");
    }
}

void MainWindow::operation()
{
    QPushButton *butt = (QPushButton *) sender();

    double all_num;
    QString newlabel;

    if(butt->text() =="+/-")
    {
        all_num = (ui->label->text()).toDouble();
        all_num *= -1;

        newlabel = QString::number(all_num, 'g', 15);

        ui->label->setText(newlabel);
    }else if(butt->text() =="%")
    {
        all_num = (ui->label->text()).toDouble();
        all_num *= 0.01;

        newlabel = QString::number(all_num, 'g', 15);

        ui->label->setText(newlabel);
    }
}

void MainWindow::math_operation()
{
    QPushButton *butt = (QPushButton *) sender();

    num_first = ui->label->text().toDouble();
    ui->label->setText("");

    butt->setChecked(true);

}

void MainWindow::on_pushButton_AC_clicked()
{
    ui->pushButton_x->setChecked(false);
    ui->pushButton_min->setChecked(false);
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_dev->setChecked(false);

    ui->label->setText("0");
}

void MainWindow::on_pushButton_rav_clicked()
{
    double labelnum, num_second;
    QString newlabel;
    num_second = ui->label->text().toDouble();
    if(ui->pushButton_dev->isChecked())
    {
        if(num_second == 0)
        {
            ui->label->setText("0");
        }else
        {
            labelnum = num_first / num_second;
            newlabel = QString::number(labelnum, 'g', 15);
        }
        ui->label->setText(newlabel);
        ui->pushButton_dev->setChecked(false);
    }else if(ui->pushButton_plus->isChecked())
    {
        labelnum = num_first + num_second;
        newlabel = QString::number(labelnum, 'g', 15);

        ui->label->setText(newlabel);
         ui->pushButton_plus->setChecked(false);
    }else if(ui->pushButton_x->isChecked())
    {
        labelnum = num_first * num_second;
        newlabel = QString::number(labelnum, 'g', 15);

        ui->label->setText(newlabel);
        ui->pushButton_x->setChecked(false);
    }else if(ui->pushButton_min->isChecked())
    {
        labelnum = num_first - num_second;
        newlabel = QString::number(labelnum, 'g', 15);

        ui->label->setText(newlabel);
        ui->pushButton_min->setChecked(false);
    }
}
