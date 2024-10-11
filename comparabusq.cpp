#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
using namespace std;
void interDirDer(int A[], int n){
	int i, j;
	int aux;
	for(i=0; i<n-1; i++){
		for(j=0; j<n-i-1; j++){
			if (A[j]>A[j+1]){
				aux = A[j];
				A[j] = A[j+1];
				A[j+1] = aux;
			}
			
		}
		
	}
}
int secuencialOrd(int A[], int n, int num){
	int i=0;
	int pos;
	while(i<n&&A[i]<num){
		i=i+1;
	}
	if(i>n||A[i]!=num){
		pos=-i;
		return pos;
	}else{
		pos=i;
		return pos;
	} 
}
int binaria(int A[], int n,int num){
	int izq=0;
	int der=n-1;
	int cen=0;
	int pos;
	int m;
	while(izq<=der&&cen==0){
		m=(izq+der)/2;
		if(A[m]==num){
			cen=1;
		}else{
			if(A[m]<num){
				izq=m+1;
			}else{
				der=m-1;
			}
		}
	}
	if (cen==1){
		pos=m;
		return pos;
	}else{
		pos=-izq;
		return pos;
	}
}
int main(){
	srand(time(0));
	int n, min, max;
	int num;
	int pos;
	int opcion;
	cout<<"Este programa buscara un dato de manera secuencial ordenada o binaria y dara un tiempo"<<endl;
	cout<<"Cantidad de elementos del arreglo a generar aleatoriamente (100 a mas): "<<endl;
	cin>>n;
	cout<<"Ingrese el minimo: "<<endl;
	cin>>min;
	cout<<"Ingrese el numero maximo: "<<endl;
	cin>>max;
	int A[n];
	int copia[n];
	for(int i=0; i<n; i++){
		A[i]=min + (rand()%(max-min+1));	
	}
	interDirDer(A, n);
	for(int i=0; i<n; i++){
		copia[i]=A[i];
		cout<<A[i]<<", ";
	}
		cout<<endl;
		cout<<"Indique el numero a buscar: ";
		cin>>num;
	do{	
		cout<<"Elija una opcion:"<<endl;
		cout<<"1. Busqueda Binaria"<<endl;
		cout<<"2. Busqueda secuencial ordenada"<<endl;
		cout<<"3) Salir"<<endl;
		cout<<"opcion: ";
		cin>>opcion;
		if(opcion==1){
			auto inicioBinaria=std::chrono::high_resolution_clock::now();
			for(int i=0; i<1000000; i++){
				pos=binaria(A,n,num);
			}
			auto finBinaria=std::chrono::high_resolution_clock::now();
			auto duracionBinaria=std::chrono::duration_cast<std::chrono::milliseconds>(finBinaria-inicioBinaria).count();
			cout<<"EL numero esta en la posicion: "<<pos<<endl;
			cout<<"Tiempo de ordenacion por busqueda binaria: "<<duracionBinaria<<"ms"<<endl;
		}else if(opcion==2){
			auto inicioSecuencial=std::chrono::high_resolution_clock::now();
			for(int i=0; i<1000000; i++){
				pos=secuencialOrd(copia,n,num);
			}
			auto finSecuencial=std::chrono::high_resolution_clock::now();
			auto duracionSecuencial=std::chrono::duration_cast<std::chrono::milliseconds>(finSecuencial-inicioSecuencial).count();
			cout<<"EL numero esta en la posicion: "<<pos<<endl;
			cout<<"Tiempo de ordenacion por busqueda secuencial: "<<duracionSecuencial<<"ms"<<endl;
		}else if (opcion!=3){
			cout<<"opcion invalida"<<endl; 
		}
	}while(opcion!=3);
		cout<<"Saliendo del programa"<<endl;
	return 0;
}
