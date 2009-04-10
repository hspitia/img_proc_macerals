#include "ImageAlternative.h"

ImageAlternative::ImageAlternative()
{
  matrix = NULL;
	format = NONE;
	rows = 0;
	cols = 0;
	maxLevel = 0;
	width = 0;
	height = 0;
}

ImageAlternative::ImageAlternative(const ImageAlternative & imageObject)
{
	if (imageObject.matrix != NULL) matrix = new Matrix<int>(*(imageObject.matrix));
	else matrix = NULL;
	
	lut = QVector<int>(imageObject.lut);
	format = imageObject.format;
	rows = imageObject.rows;
	cols = imageObject.cols;
	maxLevel = imageObject.maxLevel;
	width = imageObject.width;
	height = imageObject.height;
}

ImageAlternative::ImageAlternative(const QString & fileName)
{
  matrix = NULL;
	format = NONE;
	rows = 0;
	cols = 0;
	maxLevel = 0;
	width = 0;
	height = 0;
	load(fileName);
}

ImageAlternative::ImageAlternative(const int & width,  const int & height, format_t format, const int & maxLevel, const int & backgroundLevel)
{
	require(backgroundLevel < maxLevel, "ImageAlternative::ImageAlternative. The background level must be lesser or equal than maxLevel.");
	rows = height; 
	cols = width;
  if(format == P3 || format == P6) cols = width * 3;
	
	
	matrix = new Matrix<int>(rows, cols, backgroundLevel);
	this->format = format;
	this->maxLevel = maxLevel;
	this->width = width;
	this->height = height;
	initLut();
	// cout<<"-- DEBUG -- "<<endl;
} 

ImageAlternative::~ImageAlternative()
{
	if (matrix != NULL){
		delete  matrix;
		matrix = NULL;
	}
}

bool ImageAlternative::load(const QString & fileName)
{
	QFile file(fileName);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
		cout<<"ImageAlternative::Error al load el file \""<<qPrintable(fileName)<<"\". Archivo inexistente."<<endl;
		return false;
	}
	
	QTextStream in(&file);
	if (parseHeader(in)){
		
		initLut();
		
		if(!parseData(in)) {
			cout<<"ImageAlternative::Error al load el file \""<<qPrintable(fileName)<<"\". Final de file inesperado."<<endl;
			return false;
		}
	}
	else {
		cout<<"ImageAlternative::Error al load el file \""<<qPrintable(fileName)<<"\". Formato de file no valido."<<endl;
		return false;
	}
	
	return true;
}

bool ImageAlternative::parseData(QTextStream & in)
{
	matrix = new Matrix<int>(rows, cols);
	int value = 0;
	
	for(int i = 0; i < rows; i++ ){
		for(int j = 0; j < cols; j++ ){
			if(in.atEnd()) return false;
			in >> value;
			matrix->setAt(i, j, lut.at(value));
		}
	}

	return true;
}

bool ImageAlternative::parseHeader(QTextStream & in)
{
	int headerLines = 3;
	int readLines = 0;
	bool ok;
	
	while (readLines < headerLines && !in.atEnd()) {
		QString line = in.readLine();
		
		if(!line.startsWith("#")) {
			if(readLines == 0){
				if(QString::compare(line, "P2") == 0){
					format = ImageAlternative::P2;
				}
				else if(QString::compare(line, "P3") == 0){
					format = ImageAlternative::P3;
				}
				else if(QString::compare(line, "P5") == 0){
					format = ImageAlternative::P5;
				}
				else if(QString::compare(line, "P6") == 0){
					format = ImageAlternative::P6;
				}
				else 
					return false;
				
				readLines++;
			}
			
			else if(readLines == 1){
				QStringList list = line.split(" ");
				
				if(list.size() != 2) return false;
				
				width = list[0].toInt(&ok);
				cols = width;
				if(format == P3 || format == P6) cols = width * 3;
				
				height = list[1].toInt(&ok);
				rows = height;
				
				if(height <= 0 || width <= 0) return false;
				
				readLines++;
			}
			
			else if(readLines == 2){
				maxLevel = line.toInt(&ok);
				
				if(maxLevel <= 0) return false;
				
				readLines++;
			}
		}
	}
	return true;
}

bool ImageAlternative::save(const QString & fileName, format_t formatValue)
{
	if(matrix == NULL){
		cout<<"ImageAlternative::save. Error al save la imagen.  No se ha cargado ningun file.";
		return false;
	}
	
	if(format == P2 && formatValue == P3){
		cout<<"No se puede convertir a format PPM desde PGM.";
		return false;
	}
	else{
		QFile data(fileName);
		if (data.open(QFile::WriteOnly | QFile::Truncate)) {
			QTextStream out(&data);
			
			writeHeader(out, formatValue);
			writeData(out, formatValue);
		}
	}
	
	return true;
}


void ImageAlternative::writeData(QTextStream & out, format_t formatValue)
{
	// cout<<"formatValue: "<<qPrintable(formatToString(formatValue))<<endl;
	if(formatValue == SAME){
		int value = 0;
		for(int i = 0; i < rows; i++ ){
			for(int j = 0; j < cols; j++ ){
				value = lut.at(matrix->getAt(i,j));
				out << value<<"\n";
			}
		}
	}
	else //if(format == P3 && formatValue == P2)
	{
		int grayPixel = 0;
		for(int i = 0; i < rows; i++ ){
			for(int j = 0; j < cols; j+=3 ){
				
				grayPixel = (int)(	(0.299*lut.at(matrix->getAt(i,j))) + 
													(0.587*lut.at(matrix->getAt(i,j+1))) + 
													(0.114*lut.at(matrix->getAt(i,j+2))));
				
				out << grayPixel<<"\n";
			}
		}
	}
}

void ImageAlternative::writeHeader(QTextStream & out, format_t formatValue)
{
	// cout<<qPrintable(formatToString(formatValue))<<endl;
	out << formatToString(formatValue) <<"\n";
	out << "# CREATOR: ImageAlternativeProcessing v0.1 - hfabioen UNIVALLE"<<"\n";
	out << width <<" "<<height<<"\n";
	out << maxLevel<<"\n";
}

int ImageAlternative::getFormat(){
	return format;
}

QString ImageAlternative::formatToString(format_t formatValue){
	QString str = "";
	switch(formatValue){
		case P2: {	
			str = "P2";
			break;
		}
		case P3: {	
			str = "P3";
			break;
		}
		case P5: {	
			str = "P5";
			break;
		}
		case P6: {	
			str = "P6";
			break;
		}
		case SAME: {	
			str = formatToString(this->format);
			break;
		}
		default:
			str = "NONE";
	}
	return str;
}

void ImageAlternative::setPixel(const int & x, const int & y, const int & greyLevel)
{
	matrix->setAt(x,y,lut.at(greyLevel));
}

void ImageAlternative::setPixel(	const int & x, 
											const int & y, 
											const int & red, 
											const int & green, 
											const int & blue)
{
	int trueY = y * 3;
	matrix->setAt(x, trueY, lut.at(red));
	matrix->setAt(x, trueY+1, lut.at(green));
	matrix->setAt(x, trueY+2, lut.at(blue));
}

int ImageAlternative::getPixel(const int & x, const int & y)
{
	// int row = height - y;
	// int col = x;
	if ( ((x < 0) || (x > rows)) || (((y < 0) || (y > cols))) )	{
		cerr<<" ImageAlternative::getPixel:: IndexOutOfBounds ["<< x<<"]["<< y<<"] in ["<<rows<<"]["<<cols<<"]"<<endl;
		assert(false);
		return false;
	}
	
	// return matrix->getAt(x,y);
	return lut.at(matrix->getAt(x,y));

}

void ImageAlternative::getPixel(const int & x, const int & y, int & green, int & red, int & blue)
{
	if ( ((x < 0) || (x > rows)) || (((y < 0) || (y > cols))) )	{
		cerr<<" ImageAlternative::getPixel:: IndexOutOfBounds ["<< x<<"]["<< y<<"] in ["<<rows<<"]["<<cols<<"]"<<endl;
		assert(false);
	}
	
	int trueY = y * 3;
	red = lut.at(matrix->getAt(x,trueY));
	green = lut.at(matrix->getAt(x,trueY+1));
	blue = lut.at(matrix->getAt(x,trueY+2));
}

void ImageAlternative::initLut()
{
	lut = QVector<int> (maxLevel+1);
	for(int i = 0; i < lut.size(); i++ ){
		lut[i] = i;
	}
}


int ImageAlternative::getRows()
{
  return rows;
}


int ImageAlternative::getCols()
{
  return cols;
}

int ImageAlternative::getMaxLevel()
{
  return maxLevel;
}

int ImageAlternative::getWidth()
{
  return width;
}

int ImageAlternative::getHeight()
{
  return height;
}

void ImageAlternative::setLut(const QVector<int> & lut){
	this->lut = QVector<int>(lut);
}

QVector<int> & ImageAlternative::getLut(){
	return lut;
} 

Matrix<int> * ImageAlternative::getMatrix()
{
	return matrix;
}
