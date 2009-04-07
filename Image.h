#ifndef IMAGE__H
#define IMAGE__H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QStringList>

class Image
{
    private:
    //attributes
    int** matrix;
    int* lut;
    int columns, width, rows, levels;
    QString format;

    public:
    //methods
    Image();
    Image(const Image & objImage);
    virtual ~Image();
    virtual void createMatrix();//create a matrix with the size of the image.
    virtual void createLut();//create a array with the range of the intensity.
    virtual void readImage(const QString & path);//read the image and save its attributes.
    virtual void saveImage(const QString & name);//save the image in a file.

    virtual QString getFormat();
    virtual int getColumns();
    virtual int getWidth();
    virtual int getRows();
    virtual int getLevels();
    virtual int getPixel(const int & x, const int & y);
    virtual void getPixel(const int & x, const int & y, int & red, int & green, int & blue);
    virtual int getIntensity(const int & index);

    virtual void setFormat(const QString & type);
    virtual void setColumns(const int & column);
    virtual void setWidth();
    virtual void setRows(const int & row);
    virtual void setLevels(const int & value);
    virtual void setPixel(const int & x, const int & y, const int & gray);
    virtual void setPixel(const int & x, const int & y, const int & red, const int & green, const int & blue);
    virtual void setIntensity(const int & index, const int & value);
};

#endif
