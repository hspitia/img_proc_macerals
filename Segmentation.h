#ifndef SEGMENTATION__H
#define SEGMENTATION__H

 #include <QColor>
#include "Image.h"

class Segmentation
{
    public:
    Segmentation();
    virtual ~Segmentation();
    virtual void colorToGrayscale(Image* imgColor, Image* imageGray);
	virtual void segment1(Image* image,Image* imageOutput,QColor vitrinitaColor,QColor leptinitaColor,QColor piritaColor);
	virtual void segment2(Image* image,Image* imageOutput,QColor vitrinitaColor,QColor leptinitaColor,QColor piritaColor);
	virtual void segment3(Image* image,Image* imageOutput,QColor inertinitaColor);
};

#endif
