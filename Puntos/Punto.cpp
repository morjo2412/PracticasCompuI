#include "Punto.h"

void Punto2D::SetPosicion(float x1,float y1){
	x=x1;
	y=y1;
}
void Punto2D::Trasladar(float temp1,float temp2){
	x += temp1;
	y += temp2;
}
void Punto2D::RotarRespectoAlOrigen(float temp1){
	float rad, x1, y1;
	x1=x;
	y1=y;
	const double pi = std::acos(-1);
	rad=(temp1)*(pi/180);
	cout<<x<< "  "<< y<<endl;
	x= (x1*cos(rad))-(y1*sin(rad));
	cout<<rad<< " "<< cos(rad)<<" "<<sin(rad)<<endl;
	y= (x1*sin(rad))+(y1*cos(rad));
}
void Punto2D::Escalar(float temp1,float temp2){
	x*=temp1;
	y*=temp2;
}

float Punto2D::GetX(){
	return x;
}
float Punto2D::GetY(){
	return y;
}
