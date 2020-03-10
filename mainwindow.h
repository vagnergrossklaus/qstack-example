#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QStack>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onPbtPushclicked();
    void onPbtPopclicked();

private:
    Ui::MainWindow *ui;
    QStack<QString> _stack;

    void updateWindow();
};
#endif // MAINWINDOW_H
