#include<iostream>
#include<math.h>
#include<fstream>
using namespace std;
int main(){
	//datos:
	float k=1.62;
	float cp=820;
	float pro=(2.71/1000)*pow(100,3);
	//arrays para guardar la información de los nodos
	float i_nodos[34];//indice de los nodos
	float x_nodos[34];//coordenada x
	float y_nodos[34];//coordenada y
	float T_nodos[34];//Temperatura de los nodos.
	float avarage_delta_x=0.05;//espaciamiento 5 cm.
	float T_varilla=100;
	float dt=0.00000000001;
	float v=k*(cp*pro);
	//llenar los anteriores con la informacion:
	for (int i=0;i<34;i++){
		i_nodos[i+1]=i+1;
	}//ahora llenamos las corrdenadas x y y hasta el nodo 22. Este proceso se conoce como enmallado
	for (int i=0;i<4;i++){
		for (int j=0;j<6;j++){
			x_nodos[j+1+i*6]=j*avarage_delta_x;
			y_nodos[j+1+i*6]=i*avarage_delta_x;
		}
	}
	x_nodos[25]=4*avarage_delta_x;
	y_nodos[25]=0.0134+3*avarage_delta_x;
	for (int i=0;i<4;i++){
		x_nodos[26+i]=i*avarage_delta_x;
		y_nodos[26+i]=4*avarage_delta_x;		
	}
	x_nodos[30]=0.0134+3*avarage_delta_x;
	y_nodos[30]=4*avarage_delta_x;
	for (int i=0;i<4;i++){
		x_nodos[31+i]=i*avarage_delta_x;
		y_nodos[31+i]=5*avarage_delta_x;
	}
 	//generar archivos de malla:
 	ofstream malla("malla.txt");
 	for (int i=0;i<34;i++){
 		malla<<i_nodos[i+1]<<","<<x_nodos[i+1]<<","<<y_nodos[i+1]<<"\n";
	 }
	//caso 1: fronteras a 10°
	
	//resolver para nodos internos:
	float T_t_next[34];//creamos un vector para cuadar en t +deltt,
	//resolvemos primero las T de las fronteras simetricas:
	
	float tiempo=0;
	float contador=0;
	ofstream sol("solucion_primer_caso.txt");
	//BUCLE TEMPORAL CON 10000 PASOS DE TIEMPO
	for(int it=0;it<10000;it++){
	
		contador+=1;
		tiempo=contador*dt;
		sol<<"tiempo="<<tiempo<<"\n";
		for (int i=12;i<19;i=i+6){
			T_t_next[i]=T_nodos[i]+v*dt*(((2*T_nodos[i-1]-2*T_nodos[i])/pow(avarage_delta_x,2))+((T_nodos[i+6])+T_nodos[i-6]-2*T_nodos[i])/pow(avarage_delta_x,2));
		}
		for (int i=32;i<34;i++){
			T_t_next[i]=T_nodos[i]+v*dt*(((2*T_nodos[i-3+2*(32-i)]-2*T_nodos[i])/pow(avarage_delta_x,2))+((T_nodos[i+1])+T_nodos[i-1]-2*T_nodos[i])/pow(avarage_delta_x,2));
		}
		//ahora se resuelven los nodos internos
		for (int i=0;i<3;i++){
			for(int j=0;j<4;j++){
				T_t_next[8+6*i+j]=T_nodos[8+6*i+j]+v*dt*(1/pow(avarage_delta_x,2))*(-4*T_nodos[8+6*i+j]+T_nodos[8+6*i+j+1]+T_nodos[8+6*i+j-1]+T_nodos[8+6*i+j+6]+T_nodos[8+6*i+j-6]);
			}
		}
		for (int i=27;i<29;i++){
			T_t_next[i]=T_nodos[i]+v*dt*(1/pow(avarage_delta_x,2))*(-4*T_nodos[i]+T_nodos[i+1]+T_nodos[i-1]+T_nodos[i+5]+T_nodos[i-3+2*(27-i)]);
		}
		//resolver los nodos adyacentes al cilindro:
		T_t_next[23]=T_nodos[23]+v*dt*(((T_nodos[24]+T_nodos[22]-2*T_nodos[23])/pow(avarage_delta_x,2))+(((T_nodos[25]-T_nodos[23])/0.0134)-((T_nodos[23]-T_nodos[17])/avarage_delta_x))/(0.0134+avarage_delta_x));           
		T_t_next[29]=T_nodos[29]+v*dt*(((T_nodos[22]+T_nodos[34]-2*T_nodos[29])/pow(avarage_delta_x,2))+(((T_nodos[30]-T_nodos[29])/0.0134)-((T_nodos[29]-T_nodos[28])/avarage_delta_x))/(0.0134+avarage_delta_x));    
		//calculamos el cambio:
		
		//actualizar vector de T:
		for(int i=8;i<25;i++){
			T_nodos[i]=T_t_next[i];
			
		}
		T_nodos[24]=100;
		T_nodos[13]=10;
		T_nodos[19]=10;
		for (int i=27;i<30;i++){
			T_nodos[i]=T_t_next[i];
		}
		T_nodos[32]=T_t_next[32];
		T_nodos[33]=T_t_next[33];
	
	    
	    
	    for (int i=0;i<34;i++){
	    	sol<<i_nodos[i+1]<<","<<T_nodos[i+1]<<"\n";
		}
	    
	
	}
	
	//segunda parte
	
	
		
	



return 0;	
}

