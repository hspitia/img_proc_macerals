#ifndef SEGMENTATION__H
#define SEGMENTATION__H

#include <QColor>
#include <QVector>
#include "Image.h"
#include "ImageAlternative.h"

class Segmentation
{
public:
	Segmentation();
	virtual ~Segmentation();
	virtual void colorToGrayscale(Image* imgColor, Image* imageGray);
	virtual void segment1(Image* image,Image* imageOutput,QColor vitrinitaColor,QColor liptinitaColor,QColor piritaColor);
	virtual void segment2(Image* image,Image* imageOutput,QColor vitrinitaColor,QColor liptinitaColor,QColor piritaColor);
	virtual void segment3(Image* image,Image* imageOutput,QColor inertinitaColor);
	
	static ImageAlternative * segmentFromKmeans(ImageAlternative * imageIn, QVector<int> pixelsClassified, QVector<QColor> newColors);
		
};

#endif
