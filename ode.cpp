#include<iostream>
#define _USE_MATH_DEFINES
#include<math.h>
#include<fstream>
using namespace std;
//funcion para calcular la aceleracion en x:
float a_x(float v_x,float v_y){
	float a_x=-sqrt(pow(v_x,2)+pow(v_y,2))*v_x;
	return a_x;
}
//funcion para calcular la aceleracion en y:
float a_y(float v_x, float v_y){
	float a_y=-10-sqrt(pow(v_x,2)+pow(v_y,2))*v_y;
	return a_y;
}

int main(){
	//las consatntes del problema:
	float v_i=300, x=0, y=0, delta_t=0.0001, tetha=0.7853981634, i=0;
	
	float v_i_x=v_i*cos(tetha);
	float v_i_y=v_i*sin(tetha);
	float v_x_medio=v_i_x-(delta_t/2)*a_x(v_i_x, v_i_y);
	float v_y_medio=v_i_y-(delta_t/2)*a_y(v_i_x, v_i_y);
	// hacemos un bluque while para calcular las posiciones:
	ofstream proyectil("proyectil.txt");
	while (y>=0){
		v_i_x=v_x_medio+(delta_t)*a_x(v_i_x, v_i_y);//velocidad en x en t-deltat/2:
		if(v_i_x<0){
			v_i_x=0;
		}
		v_i_y=v_y_medio+(delta_t)*a_y(v_i_x, v_i_y);//velocidad en y en t-deltat/2
		//ahora calculamos las posiciones en t:
		x=x+v_i_x*delta_t;
		y=y+v_i_y*delta_t;
		//actualizamos los valores de las melocidades en t-deltat/2:
		v_x_medio=v_i_x;
		v_y_medio=v_i_y;
		//finalmente calculamos las velocidades en delta t:
		float v_x_exp=v_x_medio+a_x(v_x_medio, v_y_medio)*(delta_t/2);
		float v_y_exp=v_y_medio+a_y(v_x_medio, v_y_medio)*(delta_t/2);
		i+=1;
		proyectil<<i*delta_t<<","<<x<<","<<y<<","<<v_x_exp<<","<<v_y_exp<<"\n";
		//cout<<"x="<<v_y_exp<<"\n";
	
		
	}
	
	cout<<"la distancia alcanzada por el proyectil es "<<x<<"\n";
	float x_max=x;
	float tetha_max=tetha;
	
	//segunda parte: para diferentes angulos:
	ofstream proyectil1("segunda_parte.txt");
	for (int i=0;i<7;i++){
		float tetha=((10)+10*i)*M_PI/180;
			
		float v_i=300, x=0, y=0, delta_t=0.0001, j=0;
	
		float v_i_x=v_i*cos(tetha);
		float v_i_y=v_i*sin(tetha);
		float v_x_medio=v_i_x-(delta_t/2)*a_x(v_i_x, v_i_y);
		float v_y_medio=v_i_y-(delta_t/2)*a_y(v_i_x, v_i_y);
		// hacemos un bluque while para calcular las posiciones:
		
		while (y>=0){
			v_i_x=v_x_medio+(delta_t)*a_x(v_i_x, v_i_y);//velocidad en x en t-deltat/2:
				if(v_i_x<0){
				v_i_x=0;
			}
			v_i_y=v_y_medio+(delta_t)*a_y(v_i_x, v_i_y);//velocidad en y en t-deltat/2
			//ahora calculamos las posiciones en t:
			x=x+v_i_x*delta_t;
			y=y+v_i_y*delta_t;
			//actualizamos los valores de las melocidades en t-deltat/2:
			v_x_medio=v_i_x;
			v_y_medio=v_i_y;
			//finalmente calculamos las velocidades en delta t:
			float v_x_exp=v_x_medio+a_x(v_x_medio, v_y_medio)*(delta_t/2);
			float v_y_exp=v_y_medio+a_y(v_x_medio, v_y_medio)*(delta_t/2);
			j+=1;
			proyectil1<<j*delta_t<<","<<x<<","<<y<<","<<v_x_exp<<","<<v_y_exp<<"\n";
			//cout<<"x="<<v_y_exp<<"\n";
		
		}
		if (x>x_max){
			x_max=x;
			tetha_max=tetha;
		}
	}
	proyectil1<<"hasta aqui el set de datos del angulo en cuestion "<<"\n";
		
	
		
		
	float tetha_max_grados=180*tetha_max/3.141592654;
	
	cout<<"la distancia maxima es "<<x_max<<" a un angulo de "<<tetha_max_grados<<" grados";
	
	
	
	return 0;
}
