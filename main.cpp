#include <QtGui/QApplication>
#include "MainWindow.h"
#include "Kmeans.h"
#include "Segmentation.h"
#include "utils/Array.h"
#include "utils/utils.h"
#include <QVector>
#include <QColor>

int main(int argc, char *argv[])
{
    // QApplication a(argc, argv);
    // MainWindow w;
    // w.show();
    // return a.exec();
		
		int classes = 10;
		
    QVector<QColor> centroids(classes);
    
    //Blanco
		// QColor p1 = QColor(255,255,255);
    //Marron - vitrinita
		centroids[0] = QColor(145,79,5);
    centroids[1] = QColor(105,60,1);
    //Amarillo - liptinita
		centroids[2] = QColor(254,254,47);
    centroids[6] = QColor(222,150,10);
    // centroids[8] = QColor(187,134,9);
    //Marrón muy oscuro casi Negro - piritas (blanco en reflejada)
    centroids[3] = QColor(18,2,2);
    //Marrón oscuro - Inertinita (gris claro en reflejada)
    centroids[4] = QColor(44,23,4);
    //verde - resina (liptinita resinita) - 
    centroids[5] = QColor(103,117,4);
    centroids[7] = QColor(193,168,22);
		centroids[8] = QColor(92,77,2);
		centroids[9] = QColor(221,223,14);
    
		// ImageAlternative * img = new ImageAlternative("data/snail.ppm"); 
		// ImageAlternative * img = new ImageAlternative("data/sines2.ppm"); 
		// ImageAlternative * img = new ImageAlternative("data/a1.ppm"); 
		ImageAlternative * img = new ImageAlternative(argv[1]); 
		
		Kmeans k = Kmeans(centroids, img);
		k.setCentroids(centroids);
		QVector<int> classified = k.execute();
		QVector<QColor> nuevosColores(centroids.size());
		
		//Marron - vitrinita
		nuevosColores[0] = QColor(145,79,5);
    nuevosColores[1] = QColor(105,60,1);
    //Amarillo - liptinita
		nuevosColores[2] = QColor(254,254,47);
    nuevosColores[6] = QColor(222,150,10);
    // nuevosColores[8] = QColor(187,134,9);
    //Marrón muy oscuro casi Negro - piritas (blanco en reflejada)
    nuevosColores[3] = QColor(18,2,2);
    //Marrón oscuro - Inertinita (gris claro en reflejada)
    nuevosColores[4] = QColor(44,23,4);
    //verde - resina (liptinita resinita) - 
    nuevosColores[5] = QColor(103,117,4);
    nuevosColores[7] = QColor(193,168,22);
    nuevosColores[8] = QColor(92,77,2);
    nuevosColores[9] = QColor(221,223,14);
		
    cout << "\n\nCENTROIDES REMOVIDOS:" << endl;
    QVector<int> removed = k.getRemovedCentroids();
    for(int i = 0; i < removed.size(); ++i){
      nuevosColores.remove(removed[i]);
      cout << removed[i] << endl;
    }
    
		ImageAlternative * segmented = Segmentation::segmentFromKmeans(img, classified, nuevosColores);
				
		// segmented->save(QString("data/ppm/01_out.ppm").arg(argv[1]));
		segmented->save("data/ppm/01_out.ppm");
		
		return 0;
}
