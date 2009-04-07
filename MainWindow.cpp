#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindowClass)
{
  inDir="";
  outDir="";
  vitrinitaColor = QColor(140,140,140);
  leptinitaColor = QColor(110,110,110);
  inertinitaColor = QColor(140,140,140);
  piritaColor = QColor(140,140,140);
  ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_browseInBtn_clicked()
{
  inDir = pathToDirectory();
  ui->inDirLedt->setText(inDir);
}

void MainWindow::on_browseOutBtn_clicked()
{
  outDir = pathToDirectory();
  ui->outDirLedt->setText(outDir);
}

void MainWindow::on_executeBtn_clicked()
{
    
}

void MainWindow::on_exitBtn_clicked()
{
    close();
}

void MainWindow::on_vitrinitaColorBtn_clicked()
{
    vitrinitaColor = chooseMineralColor(vitrinitaColor);
}

void MainWindow::on_leptinitaColorBtn_clicked()
{
  leptinitaColor = chooseMineralColor(leptinitaColor);
}

void MainWindow::on_inertinitaColorBtn_clicked()
{
  inertinitaColor = chooseMineralColor(inertinitaColor);
}

void MainWindow::on_piritaColorBtn_clicked()
{
  piritaColor = chooseMineralColor(piritaColor);
}


QString MainWindow::pathToDirectory()
{
  return QFileDialog::getExistingDirectory(this, tr("Directorio de entrada"),
                                            ".",
                                            QFileDialog::ShowDirsOnly
                                            | QFileDialog::DontResolveSymlinks);
}

QColor MainWindow::chooseMineralColor(QColor initialColor)
{
  return QColorDialog::getColor(initialColor,this);
}
