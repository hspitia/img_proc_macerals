#include "Image.h"

Image::Image()
{
    matrix=0;
    lut=0;
    columns=0;
    width=0;
    rows=0;
    levels=0;
    format="";
}

Image::Image(const Image & objImage)
{
    columns = objImage.columns;
    width = objImage.width;
    rows = objImage.rows;
    levels = objImage.levels;
    format = objImage.format;

    matrix = new int* [rows];
    for(int idx=0;idx<rows;idx++)
    {
        matrix[idx] = new int [width];
        for(int idy=0;idy<width;idy++)
        {
            matrix[idx][idy] = 0;
        }
    }

    lut = new int [levels+1];
    for (int index=0; index<levels+1; index++)
    {
        lut[index] = objImage.lut[index];
    }
}

Image::~Image()
{
    if(matrix!=0)
    {
        delete matrix;
        matrix=0;
    }

    if(lut!=0)
    {
        delete lut;
        lut=0;
    }
}

void Image::createMatrix()
{
    matrix = new int* [rows];

    for (int idx=0; idx<rows; idx++)
    {
        matrix[idx] = new int [width];

        for (int idy=0; idy<width; idy++)
        {
            matrix[idx][idy] = 0;
        }
    }
}

void Image::createLut()
{
    lut = new int [levels+1];

    for (int index=0; index<levels+1; index++)
    {
        lut[index] = index;
    }
}

void Image::readImage(const QString & path)
{
    QFile file(path);

    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&file);
        QString line = "";

        for(int i=0;i<3;i++)
        {
            line = stream.readLine();
            if(!line.startsWith("#"))
            {
                if(i==0)
                        format = line;
                if(i==1)
                {
                    QStringList list = line.split(" ");
                    columns=list[0].toInt();
                    rows=list[1].toInt();
                    if(QString::compare(format, "P3") == 0 || QString::compare(format, "P6") == 0)
                        width=columns*3;
                    else
                        width=columns;
                }
                if(i==2)
                    levels = line.toInt();
            }
            else
                i--;
        }

        createLut();
        createMatrix();

        for (int idx=0; idx<rows; idx++ )
        {
            for (int idy=0; idy<width; idy++ )
            {
                stream>>matrix[idx][idy];
            }
        }
    }
    file.close();
}

void Image::saveImage(const QString & name)
{
    QString extension="";
    if(format=="P2" || format=="P5")
        extension=".pgm";
    else if(format=="P3" || format=="P6")
        extension=".ppm";

    QFile file(name+extension);
    if (file.open(QFile::WriteOnly | QFile::Truncate))
    {
        QTextStream stream(&file);

        stream<<format;
        stream<<"\n";
        stream<<"# Image modified by juanzuro";
        stream<<"\n";
        stream<<columns;
        stream<<" ";
        stream<<rows;
        stream<<"\n";
        stream<<levels;
        stream<<"\n";

        int count=0;
        for (int idx=0; idx<rows; idx++ )
        {
            for (int idy=0; idy<width; idy++ )
            {
                stream<<lut[matrix[idx][idy]];
                stream<<" ";
                count++;
                if(count==15)
                {
                    stream<<"\n";
                    count=0;
                }
            }
        }
        stream<<"\n";
    }
    file.close();
}

QString Image::getFormat()
{
    return format;
}

int Image::getColumns()
{
    return columns;
}

int Image::getWidth()
{
    return width;
}

int Image::getRows()
{
    return rows;
}

int Image::getLevels()
{
    return levels;
}

int Image::getPixel(const int & x, const int & y)
{
    return matrix[x][y];
}

void Image::getPixel(const int & x, const int & y, int & red, int & green, int & blue)
{
    red=matrix[x][y*3];
    green=matrix[x][(y*3)+1];
    blue=matrix[x][(y*3)+2];
}

int Image::getIntensity(const int & index)
{
    return lut[index];
}

void Image::setFormat(const QString & type)
{
    format=type;
}

void Image::setColumns(const int & column)
{
    columns=column;
}

void Image::setWidth()
{
    if(QString::compare(format, "P3") == 0 || QString::compare(format, "P6") == 0)
            width=columns*3;
    else
            width=columns;
}

void Image::setRows(const int & row)
{
    rows=row;
}

void Image::setLevels(const int & value)
{
    levels=value;
}

void Image::setPixel(const int & x, const int & y, const int & gray)
{
    matrix[x][y]=gray;
}

void Image::setPixel(	const int & x, const int & y, const int & red, const int & green, const int & blue)
{
    matrix[x][y*3]=red;
    matrix[x][(y*3)+1]=green;
    matrix[x][(y*3)+2]=blue;
}

void Image::setIntensity(const int & index, const int & value)
{
    lut[index]=value;
}
