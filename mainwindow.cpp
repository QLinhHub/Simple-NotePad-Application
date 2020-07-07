#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionSave_As_triggered()
{
    QString file_name = QFileDialog :: getSaveFileName(this, "Open this file");

    file_path = file_name;

    QFile file(file_path);

    if(!file.open(QFile :: WriteOnly | QFile :: Text)){
        QMessageBox :: warning(this, "WARNING", "This file can't not open");
        return;
    }

    QTextStream S(&file);

    S << ui->textEdit->toPlainText();

    file.flush();
    file.close();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionAbout_Me_triggered()
{
    QMessageBox :: about(this, "About me", "Nhà Bao Việc");
}

void MainWindow::on_actionNew_triggered()
{
    file_path = "";
    ui->textEdit->setText("");
}

void MainWindow::on_actionOpen_triggered()
{
    QString file_name = QFileDialog :: getOpenFileName(this,"Open this file");

    file_path = file_name;

    QFile file(file_path);

    if(!file.open(QFile :: ReadOnly | QFile :: Text)){
        QMessageBox :: warning(this, "WARNING", "This file can't not open");
        return;
    }

    QTextStream E(&file);

    ui->textEdit->setText(E.readAll());
    file.close();

}

void MainWindow::on_actionSave_triggered()
{
    //QString file_name = QFileDialog :: getSaveFileName(this, "Open this file");

    //file_path = file_name;

    QFile file(file_path);

    if(!file.open(QFile :: WriteOnly | QFile :: Text)){
        QMessageBox :: warning(this, "WARNING", "This file can't not open");
        return;
    }

    QTextStream S(&file);

    S << ui->textEdit->toPlainText();

    file.flush();
    file.close();
}
