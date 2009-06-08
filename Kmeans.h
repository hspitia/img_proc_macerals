#ifndef KMEANS_H
#define KMEANS_H

#include <algorithm>
#include <cmath>
#include <iostream>
#include <QVector>
#include <QColor>
#include "ImageAlternative.h"
#include "utils/Array.h"
#include "utils/Matrix.h"
// #include "utils/QColor.h"
#include "utils/require.h"
#include "utils/utils.h"

using namespace std;

class Kmeans {
	private:
		int numClasses;
		ImageAlternative* image;
		QVector<QColor> centroids;
    
	public:
		double distance(	QColor & pixel1, QColor & pixel2);
		int indexOfMin(QVector<double> & elementsVector);
		
		
	public:
		Kmeans();
		Kmeans(const int & numClasses, ImageAlternative * image);
		virtual ~Kmeans();
		
		int getNumClasses();
		void setNumClasses(const int & numClasses);
		ImageAlternative* getImage();
		void setImage(ImageAlternative* imageValue);
		QVector<QColor> getCentroids();
		void setCentroids(const QVector<QColor> & centroidsValue);
		
		QVector<int> execute();
		
	
};
#endif        //  #ifndef KMEANS_H

