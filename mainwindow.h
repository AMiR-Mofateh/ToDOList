#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QListWidgetItem;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Add_btn_clicked();
    void on_Delete_btn_clicked();
    void on_TaskList_itemDoubleClicked(QListWidgetItem *item);
    void updateStatus();

private:
    Ui::MainWindow *ui;
};

#endif
