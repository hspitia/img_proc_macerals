#include "Segmentation.h"

Segmentation::Segmentation()
{}

Segmentation::~Segmentation()
{}


ImageAlternative * Segmentation::segmentFromKmeans(ImageAlternative * imageIn, QVector<int> pixelsClassified, QVector<QColor> newColors){
		
	ImageAlternative * segmented = new ImageAlternative((*imageIn));
	int idxClassified = 0;
	int colorIdx = 0;
	int r = 0;
	int g = 0;
	int b = 0;
	
	for(int i = 0; i < segmented->getHeight(); ++i){
		for(int j = 0; j < segmented->getWidth(); ++j){
			idxClassified = j+(i*segmented->getWidth());
			colorIdx = pixelsClassified[idxClassified];
			r = newColors[colorIdx].red();
			g = newColors[colorIdx].green();
			b = newColors[colorIdx].blue();
			segmented->setPixel(i,j,r,g,b);
		}
	}
	
	return segmented;
	
}

void Segmentation::colorToGrayscale(Image* imgColor, Image* imageGray)
{
	imageGray->setFormat("P2");
	imageGray->setColumns(imgColor->getColumns());
	imageGray->setWidth();
	imageGray->setRows(imgColor->getRows());
	imageGray->setLevels(imgColor->getLevels());
	imageGray->createLut();
	imageGray->createMatrix();
	
	int red=0;
	int green=0;
	int blue=0;
	int gray=0;
	
	for(int idx=0;idx<imgColor->getRows();idx++)
	{
		for(int idy=0;idy<imgColor->getColumns();idy++)
		{
			imgColor->getPixel(idx, idy,red,green,blue);
			gray = (int)((0.299*red) + (0.587*green) + (0.114*blue));
			imageGray->setPixel(idx,idy,gray);
		}
	}
}

void Segmentation::segment1(Image* image,Image* imageOutput,QColor vitrinitaColor,QColor liptinitaColor,QColor piritaColor)
{
	for(int idx=0;idx<image->getRows();idx++)
	{
		for(int idy=0;idy<image->getColumns();idy++)
		{
			if(image->getPixel(idx,idy) > 0 && image->getPixel(idx,idy) <= 174)
			{
				imageOutput->setPixel(idx,idy,vitrinitaColor.red(),vitrinitaColor.green(),vitrinitaColor.blue());
			}
			if(image->getPixel(idx,idy) > 174 && image->getPixel(idx,idy) <= 240)
			{
				imageOutput->setPixel(idx,idy,liptinitaColor.red(),liptinitaColor.green(),liptinitaColor.blue());
			}
			if(image->getPixel(idx,idy) > 240 && image->getPixel(idx,idy) < image->getLevels()+1)
			{
				imageOutput->setPixel(idx,idy,piritaColor.red(),piritaColor.green(),piritaColor.blue());
			}
		}
	}
}

void Segmentation::segment2(Image* image,Image* imageOutput,QColor vitrinitaColor,QColor liptinitaColor,QColor piritaColor)
{
	for(int idx=0;idx<image->getRows();idx++)
	{
		for(int idy=0;idy<image->getColumns();idy++)
		{
			if(image->getPixel(idx,idy) > 0 && image->getPixel(idx,idy) <= 194)
			{
				imageOutput->setPixel(idx,idy,vitrinitaColor.red(),vitrinitaColor.green(),vitrinitaColor.blue());
			}
			if(image->getPixel(idx,idy) > 194 && image->getPixel(idx,idy) <= 240)
			{
				imageOutput->setPixel(idx,idy,liptinitaColor.red(),liptinitaColor.green(),liptinitaColor.blue());
			}
			if(image->getPixel(idx,idy) > 240 && image->getPixel(idx,idy) < image->getLevels()+1)
			{
				imageOutput->setPixel(idx,idy,piritaColor.red(),piritaColor.green(),piritaColor.blue());
			}
		}
	}
}

void Segmentation::segment3(Image* image,Image* imageOutput,QColor inertinitaColor)
{
	for(int idx=0;idx<image->getRows();idx++)
	{
		for(int idy=0;idy<image->getColumns();idy++)
		{
			if(image->getPixel(idx,idy) > 150 && image->getPixel(idx,idy) < image->getLevels()+1)
			{
				imageOutput->setPixel(idx,idy,inertinitaColor.red(),inertinitaColor.green(),inertinitaColor.blue());
			}
		}
	}
}

