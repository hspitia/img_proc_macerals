/*
 * Basado en la implementaciOn propuesta por Ben Watson en su artículo
 *	 Operator Overloading in C++, disponible en 
 * http://www.devhood.com/tutorials/tutorial_details.aspx?tutorial_id=502
 *	
*/

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include "require.h"

using namespace std;

template<class T>
class Array {
	private:
		T * array;
		int size;
	
	public:
		Array<T> (const int & sizeValue = 0) : array(NULL) {
			setSize(sizeValue);
		}
		
		Array<T> (const int & sizeValue, const T & initValue) {
			setSize(sizeValue);
			for(int i = 0; i < size; ++i){
				array[i] = initValue;
			}
		}
		
		Array<T> (const Array<T> & arrayObject):array(NULL) {
			setSize(arrayObject.size);
			for(int i = 0; i < size; ++i){
				array[i] = arrayObject.array[i];
			} 
		}
		
		~Array() {
			setSize(0);
		}
		
		void setSize(const int & sizeValue){
			if (array) delete [] array;
			if (sizeValue > 0){
				array = new T[sizeValue];
				memset(array, 0, sizeof(T)*sizeValue / sizeof(char));
			}
			else array = NULL;
			size = sizeValue;
		}
		
		int lenght() { 
			return size; 
		}
		
		T operator[](const int & index) const{
			require(index >= 0 && index < size, "Array::operator[]. IndexOutOfBounds\n");
			return array[index];
		}
		
		T & operator[] (const int & index){
			require(index >= 0 && index < size, "Array::operator[]. IndexOutOfBounds\n");
			return array[index];
		}
		
		Array & operator= (const Array & arrayObject){
			setSize(arrayObject.size);
			for(int i = 0; i < size; ++i){
				array[i] = arrayObject.array[i];
			}
			return *this;
		}
		
		Array & operator+ (const Array & arrayObject){
			for(int i = 0; i < size; ++i){
				array[i] += arrayObject.array[i];
			}
			return *this;
		}
		
		Array & operator*= (const T & value){
			for(int i = 0; i < size; ++i){
				array[i] *= value;
			}
			return *this;
		}
		
		Array & operator+= (const T & value){
			for(int i = 0; i < size; ++i){
				array[i] += value;
			}
			return *this;
		}
		
		Array & operator/= (const T & value){
			for(int i = 0; i < size; ++i){
				array[i] /= value;
			}
			return *this;
		}
		
		friend std::ostream & operator<< (std::ostream & outStream, const Array<T> & arrayObject) {
			if(arrayObject.array != NULL){
				outStream << "[ ";
				for(int i = 0; i < arrayObject.size; i++ ){
					outStream<<arrayObject.array[i]<<" ";
				}
				outStream<<"]"<<endl;
			}
			else
				outStream<<"NULL"<<endl;
			
			return outStream;
		}
		
};
#endif        //  #ifndef ARRAY_H

