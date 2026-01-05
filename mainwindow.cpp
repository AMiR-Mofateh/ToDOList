#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QListWidgetItem>
#include <QFont>
#include <QBrush>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->AddTask, &QLineEdit::returnPressed,
            this, &MainWindow::on_Add_btn_clicked);
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Add_btn_clicked()
{
    QString text = ui->AddTask->text();

    if (!text.isEmpty()) {
        QListWidgetItem* item = new QListWidgetItem(text);

        item->setData(Qt::UserRole, false);

        ui->TaskList->addItem(item);

        ui->AddTask->clear();

        updateStatus();
    }//test
}
void MainWindow::on_Delete_btn_clicked()
{
    QListWidgetItem* item = ui->TaskList->currentItem();
    if (item != nullptr) {
        delete ui->TaskList->takeItem(ui->TaskList->row(item));
        updateStatus();
    }
}
void MainWindow::on_TaskList_itemDoubleClicked(QListWidgetItem *item)
{
    if (!item) return;

    bool done = item->data(Qt::UserRole).toBool();

    if (!done) {
        QFont f = item->font();
        f.setStrikeOut(true);
        item->setFont(f);
        item->setForeground(QBrush(Qt::green));
        item->setData(Qt::UserRole, true);
    } else {
        QFont f = item->font();
        f.setStrikeOut(false);
        item->setFont(f);
        item->setForeground(QBrush(Qt::black));
        item->setData(Qt::UserRole, false);
    }

    updateStatus();
}
void MainWindow::updateStatus()
{
    int total = ui->TaskList->count();
    int doneCount = 0;

    for (int i = 0; i < total; ++i) {
        QListWidgetItem* it = ui->TaskList->item(i);
        if (it && it->data(Qt::UserRole).toBool()) {
            doneCount++;
        }
    }

    ui->Status->setText(
        QString("total : %1 | done : %2").arg(total).arg(doneCount)
        );
}
