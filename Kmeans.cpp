#include "Kmeans.h"

Kmeans::Kmeans(){
	this->numClasses = 0;
	this->image = NULL;
	this->centroids = QVector<QColor> ();
  this->removedCentroids = QVector<int> ();
}


Kmeans::Kmeans(const int & numClasses, ImageAlternative * image){
	this->numClasses = numClasses;
	this->image = image;
	this->centroids = QVector<QColor> (numClasses);
  this->removedCentroids = QVector<int> ();
}

Kmeans::Kmeans(QVector<QColor> centroids, ImageAlternative * image){
	this->numClasses = centroids.size();
	this->image = image;
	this->centroids = centroids;
  this->removedCentroids = QVector<int> ();
}

Kmeans::~Kmeans(){
	if(image != NULL) delete image;
	image = NULL;
}

QVector<int> Kmeans::execute(){
	
	bool exit = false;
	int size = image->getWidth() * image->getHeight(); //total number of image pixels

	QVector<int> pixelsClassified(size,0); //pixels classification QVector
	QVector<int> pixelsClassifiedNew(size,0); //pixels classification QVector
	QVector<int> classesCounter(numClasses,0);
	QVector<int> classesCounterNew(numClasses,0);
	QVector<QColor> tmpCentroids(numClasses);
	// // Initial classification
	// int classIdx = 0;
	// int numPixelsPerClass = (int) size / numClasses;
	// int end = numPixelsPerClass * numClasses;
	// for(int i = 0; i < end; ++i){
	// 	classIdx = (int) floor(i/numPixelsPerClass);
	// 	pixelsClassified[i] = classIdx;
	// 	classesCounter[classIdx]++;
	// }
	
	// classIdx = 0;
	// for(int i = end; i < size; ++i){
	// 	pixelsClassified[i] = classIdx;
	// 	classesCounter[classIdx]++;
	// }
	
	int pixelsIdx = 0;
	int minDistanceIdx = 0;
	QColor tmpPixel = QColor();
	int r = 0;
	int g = 0;
	int b = 0;
	
	
	int counter = 0;
	do {
		QVector<double> sumPixelsR(numClasses,0);
		QVector<double> sumPixelsG(numClasses,0);
		QVector<double> sumPixelsB(numClasses,0);
    QVector<double> distancesToCentroids (numClasses);
		classesCounterNew = QVector<int>(numClasses,0);
		
		// Pixels classification according to minimum distance to centroids
    
		// Cycle through the pixels of image
		for(int i = 0; i < image->getHeight(); ++i){
			for(int j = 0; j < image->getWidth(); ++j){
				image->getPixel(i, j, r, g, b);
        // cout << "\nCAZANDO" << endl;
				tmpPixel = QColor(r, g, b);
				
				// cout<<setw(5)<<counter++<<" - pixel: "<<tmpPixel<< " distances: ";
				
				// Distances calculation
				for(int k = 0; k < numClasses; ++k){
					distancesToCentroids[k] = distance(centroids[k], tmpPixel);
					// cout<<distancesToCentroids[k]<<", ";
				}
				// index of nearest class centroid
				minDistanceIdx = indexOfMin(distancesToCentroids);
				
				pixelsIdx = j + (i*image->getWidth());
				pixelsClassifiedNew[pixelsIdx] = minDistanceIdx;
				// cout<<" - cercano: "<<minDistanceIdx<<endl;
				
				sumPixelsR[minDistanceIdx] += r;
				sumPixelsG[minDistanceIdx] += g;
				sumPixelsB[minDistanceIdx] += b;
				
				classesCounterNew[minDistanceIdx]++;
			}
		}
    
    int removed = 0;
    for(int i = 0; i < numClasses; ++i){
      if(classesCounterNew[i] == 0){
        centroids.remove(i);
        sumPixelsR.remove(i);
        sumPixelsG.remove(i);
        sumPixelsB.remove(i);
        removedCentroids.append(i);
        ++removed;
      }
    }
    
    for(int i = 0; i < removed; ++i){
      classesCounterNew.remove(removedCentroids[i]);
      classesCounter.remove(removedCentroids[i]);
    }
    
    numClasses -= removed;

		//new centroids calculation
		int maxLevel = image->getMaxLevel();
		for(int i = 0; i < numClasses; ++i){
			r = (int) levelRound((sumPixelsR[i] / classesCounterNew[i]), maxLevel);
			g = (int) levelRound((sumPixelsG[i] / classesCounterNew[i]), maxLevel);
			b = (int) levelRound((sumPixelsB[i] / classesCounterNew[i]), maxLevel);
			cout<<"suma: "<<sumPixelsR[i]<<" contador: "<<classesCounterNew[i]<<endl;
			
			// r = (int) sumPixelsR[i] / classesCounterNew[i];
			// g = (int) sumPixelsG[i] / classesCounterNew[i];
			// b = (int) sumPixelsB[i] / classesCounterNew[i];
			// tmpPixel = QColor(r, g, b);
			// centroids[i] = tmpPixel;
      tmpCentroids[i] = QColor(r, g, b);
		}
		
		cout<<"Old centroids: ";
		for(int i = 0; i < centroids.size(); ++i){
			cout<<"("
					<<centroids[i].red()<<", "
					<<centroids[i].green()<<", "
					<<centroids[i].blue()
					<<")";
		}
		cout<<endl;
		
    cout<<"New centroids: ";
		for(int i = 0; i < centroids.size(); ++i){
			cout<<"("
					<<tmpCentroids[i].red()<<", "
					<<tmpCentroids[i].green()<<", "
					<<tmpCentroids[i].blue()
					<<")";
		}
		cout<<endl;
    
    
    /*
		// Evaluate changes in classifications
		// Counting of classes that are equals in size
		int classesEquals = 0;
		for(int i = 0; i < numClasses; ++i){
			cout << "classesCounterNew "<<i<<": "<< classesCounterNew[i]<< "  classesCounter "<<i<<": "<< classesCounter[i]<< endl;
			if(classesCounter[i] == classesCounterNew[i]) classesEquals++;
		}
		cout << "clases iguales: " << classesEquals;
		// Changes in the sizes of classes?
		if(classesEquals == numClasses){
			cout<<"\nentro: SI"<<endl;
			// Counting of the pars classification of the pixels
			int pars = 0;
			for(int i = 0; i < size; ++i){
				// cout << "pixelsClassified: "<<pixelsClassified[i]<<"  pixelsClassifiedNew: "<<pixelsClassifiedNew[i] << endl;
        // cout << "Antes" << endl;
				if(pixelsClassified[i] == pixelsClassifiedNew[i]) {
          pars++;
          // cout << "Despues" << endl;
        }
				else break;
			}
			
			if(pars == size) exit = true;
		}
    
		pixelsClassified = QVector<int>(pixelsClassifiedNew);
		classesCounter = QVector<int>(classesCounterNew);
		*/
    
    
    //New approach to stop the cycle
    if (centroids == tmpCentroids) exit = true;
    else {
      centroids = QVector<QColor>(tmpCentroids);
      pixelsClassified = QVector<int>(pixelsClassifiedNew);
      classesCounter = QVector<int>(classesCounterNew);
    }
    
    
		counter++;
		cout<<"  -  contador: "<<counter<<"  - ";
		
	// } while(exit != true);
	} while(counter < 2);
	
	return pixelsClassifiedNew;
}


int Kmeans::indexOfMin(QVector<double> & elementsVector){
	// sort(elementsVector.begin(), elementsVector.end());
	require(elementsVector.size() > 0, "Kmeans::indexOfMin. Error. The size of elementsVector must be greater than 0");
	int minIdx = 0;
	double min = elementsVector[0];
	
	for(int i = 1; i < (int)elementsVector.size(); ++i){
		if(elementsVector[i] < min) {
			min = elementsVector[i];
			minIdx = i;
		}
	}
	
	return minIdx;
}

double Kmeans::distance(QColor & pixel1, QColor & pixel2){
	double sum = 	pow((double)(pixel1.red() - pixel2.red()), 2.0) + 
								pow((double)(pixel1.green() - pixel2.green()), 2.0) + 
								pow((double)(pixel1.blue() - pixel2.blue()), 2.0);
								
	return sqrt(sum);
}

int Kmeans::getNumClasses()
{
  return numClasses;
}

void Kmeans::setNumClasses(const int& numClassesValue)
{
  numClasses = numClassesValue;
}

ImageAlternative* Kmeans::getImage()
{
  return image;
}

void Kmeans::setImage(ImageAlternative* imageValue)
{
  image = imageValue;
}

QVector<QColor> Kmeans::getCentroids()
{
  return centroids;
}

void Kmeans::setCentroids(const QVector<QColor> & centroidsValue)
{
  centroids = centroidsValue;
}

QVector<int> Kmeans::getRemovedCentroids()
{
	return removedCentroids;
}
