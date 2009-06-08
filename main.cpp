#include <QtGui/QApplication>
#include "MainWindow.h"
#include "Kmeans.h"
#include "Segmentation.h"
// #include "utils/QColor.h"
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
		
		int classes = 5;
		
		QColor p1 = QColor(255,255,255); // blanco
		QColor p2 = QColor(174,93,0); // marron
		QColor p3 = QColor(246,231,0); // amarillo
		QColor p4 = QColor(121,132,1); // verde
		QColor p5 = QColor(0,0,0); // negro
    
		
		// QColor p1 = QColor(0,5,250); //azul
		// QColor p2 = QColor(0,255,0); //verde
		// QColor p3 = QColor(250,0,0); //rojo
		
		// QColor p1 = QColor(255,255,255); // blanco
		// QColor p2 = QColor(255,254,39); // amarillo
		// QColor p3 = QColor(148,88,0); // marron
		
		QVector<QColor> centroids(classes);
		centroids[0] = p1;
		centroids[1] = p2;
		centroids[2] = p3;
		centroids[3] = p4;
		centroids[4] = p4;
		
		// ImageAlternative * img = new ImageAlternative("data/snail.ppm"); 
		// ImageAlternative * img = new ImageAlternative("data/sines2.ppm"); 
		// ImageAlternative * img = new ImageAlternative("data/a1.ppm"); 
		ImageAlternative * img = new ImageAlternative(argv[1]); 
		
		Kmeans k = Kmeans(classes, img);
		k.setCentroids(centroids);
		QVector<int> classified = k.execute();
		QVector<QColor> nuevosColores(classes);
		
		nuevosColores[0] = QColor(200,200,200);  // amarillo brillante - piritas    -> gris 
		nuevosColores[1] = QColor(153,0,153); 		// amarillo           - liptinita  -> lila
		nuevosColores[2] = QColor(255,153,0);		// marron             - vitrinita  -> amarillo
		nuevosColores[3] = QColor(76,23,100);		// verde              - resina     -> azul oscuro
		nuevosColores[4] = QColor(200,23,15);		// marron             -   -> 
		
		ImageAlternative * segmented = Segmentation::segmentFromKmeans(img, classified, nuevosColores);
				
		segmented->save("data/ppm/out.ppm");
		
		return 0;
}
