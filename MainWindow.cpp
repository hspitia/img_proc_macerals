#include "MainWindow.h"
#include "ui_MainWindow.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindowClass)
{
  inDir="";
  outDir="";
  vitrinitaColor = QColor(0,0,255);
  leptinitaColor = QColor(255,0,0);
  inertinitaColor = QColor(255,255,255);
  piritaColor = QColor(255,255,0);
  objSegmentation = new Segmentation();
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
    QDir dir(inDir);
	dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
	QString dirImage = "";
		QFileInfoList list = dir.entryInfoList();
		for (int i = 0; i < list.size(); ++i) 
		{
			QFileInfo fileInfo = list.at(i);
			QString name = fileInfo.fileName();
			dirImage = inDir + name;
			
			inImage = new Image();
			inImage->readImage(dirImage);
			inGrayImage = new Image();
			objSegmentation->colorToGrayscale(inImage,inGrayImage);
			
			if(name.indexOf("Fluo")>=0)
			{
			  outImage = new Image(*inImage);
			  int time = QString(name.at(name.indexOf("X")+2)).toInt();
			  //cout<<"Fluo "<<time<<endl;
			  if(time == 2)
			  {
				objSegmentation->segment1(inGrayImage,outImage,vitrinitaColor,leptinitaColor,piritaColor);
			  }
			  else if(time == 3)
			  {
			  	objSegmentation->segment2(inGrayImage,outImage,vitrinitaColor,leptinitaColor,piritaColor);
			  }
			}
			else if(name.indexOf("Refle")>=0)
			{
				objSegmentation->segment3(inGrayImage,outImage,inertinitaColor);
				//cout<<"Refle "<<endl;
				outImage->saveImage(outDir + "a" + QString(name.at(1)) + QString(name.at(2)));
				cout<<qPrintable("procesando..." + outDir + "a" + QString(name.at(1)) + QString(name.at(2)))<<endl;
				delete outImage;
				outImage = NULL;
			}
			
			delete inImage;
			inImage = NULL;
			delete inGrayImage;
			inGrayImage = NULL;
		}
		cout<<"Listo"<<endl;
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
  return QFileDialog::getExistingDirectory(this, tr("Seleccione un directorio"),
                                            ".",
                                            QFileDialog::ShowDirsOnly
                                            | QFileDialog::DontResolveSymlinks);
}

QColor MainWindow::chooseMineralColor(QColor initialColor)
{
  return QColorDialog::getColor(initialColor,this);
}
