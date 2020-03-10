#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStringListModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {

    ui->setupUi(this);

    QObject::connect(ui->pbtPush, &QPushButton::clicked, this, &MainWindow::onPbtPushclicked);
    QObject::connect(ui->pbtPop, &QPushButton::clicked, this, &MainWindow::onPbtPopclicked);

}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::onPbtPushclicked() {
    _stack.push(ui->ledPush->text());
    updateWindow();
    ui->ledPush->setFocus();
    ui->ledPush->selectAll();
}

void MainWindow::onPbtPopclicked() {
    if (!_stack.isEmpty())
        ui->lblPop->setText(_stack.pop());
    updateWindow();
}

void MainWindow::updateWindow() {
    if (!_stack.isEmpty())
        ui->lblTop->setText(_stack.top());
    else
        ui->lblTop->setText("-");

    QStringList itens = {};
    for (int i = _stack.size() - 1; i >= 0; i--) {
        itens.append(_stack.at(i));
    }

    ui->lvwStack->setModel(new QStringListModel(itens));
}
