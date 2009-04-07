#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//#include <QtGui/QMainWindow>
#include <QtGui>
#include <QtCore>

namespace Ui
{
    class MainWindowClass;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindowClass *ui;
    QString inDir;
    QString outDir;
    QColor vitrinitaColor;
    QColor leptinitaColor;
    QColor inertinitaColor;
    QColor piritaColor;
    
    QString pathToDirectory();
    QColor chooseMineralColor(QColor initialColor);

private slots:
    void on_vitrinitaColorBtn_clicked();
    void on_leptinitaColorBtn_clicked();
    void on_inertinitaColorBtn_clicked();
    void on_piritaColorBtn_clicked();
    void on_exitBtn_clicked();
    void on_executeBtn_clicked();
    void on_browseOutBtn_clicked();
    void on_browseInBtn_clicked();
};

#endif // MAINWINDOW_H
