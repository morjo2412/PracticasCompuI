#ifndef PUNTO_H
#define PUNTO_H

#include <math.h>
#include <iostream>

using namespace std;
class Punto2D
{
	public:
		void SetPosicion(float x1,float y1);
		void Trasladar(float temp1,float temp2);
		void RotarRespectoAlOrigen(float temp1);
		void Escalar(float temp1,float temp2);
		
		float GetX();
		float GetY();
		
	private:
		float x;
		float y;
};

#endif
