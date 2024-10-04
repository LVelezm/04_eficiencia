#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
using namespace std;
void SeleccionDir(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int menor = A[i];
        int k = i;

        for (int j = i + 1; j < n; j++) {
            if (menor > A[j]) {
                menor = A[j];
                k = j;
            }
        }

        A[k] = A[i];
        A[i] = menor;
    }
}
void InsercionDir(int A[], int n) {
    for (int i = 1; i < n; i++) {
        int aux = A[i];
        int k = i - 1;
        while (k >= 0 && aux < A[k]) {
            A[k + 1] = A[k];
            k = k - 1;
        }
        A[k + 1] = aux;
    }
}
int main(){
	srand(time(0));
	int n;
	int opcion;
	cout<<"Ingrese la cantidad de numeros aleatorios a generar(preferiblemente de 10000 a mas): ";
	cin>>n;
	int arreglo[n];
	int copia[n];
	for(int i=0; i<n; i++){
		arreglo[i]=rand()%2*n+1-n;
		copia[i]=arreglo[i];	
	}
	do{
		cout<<"Elija una opcion: "<<endl;
		cout<<"1) Ordenacion por seleccion"<<endl;
		cout<<"2) Ordenacion por insercion"<<endl;
		cout<<"3) Salir"<<endl;
		cout<<"opcion: ";
		cin>>opcion;
		if(opcion==1){
			auto inicioSeleccion=std::chrono::high_resolution_clock::now();
			SeleccionDir(arreglo, n);
			auto finSeleccion=std::chrono::high_resolution_clock::now();
			auto duracionSeleccion=std::chrono::duration_cast<std::chrono::milliseconds>(finSeleccion-inicioSeleccion).count();
			cout<<"Tiempo de ordenacion por seleccion: "<<duracionSeleccion<<"ms"<<endl;
		}else if(opcion==2){	
			auto inicioInsercion=std::chrono::high_resolution_clock::now();
			InsercionDir(copia, n);
			auto finInsercion=std::chrono::high_resolution_clock::now();
			auto duracionInsercion=std::chrono::duration_cast<std::chrono::milliseconds>(finInsercion-inicioInsercion).count();
			cout<<"Tiempo de ordenacion por insercion: "<<duracionInsercion<<"ms"<<endl;
		}else if(opcion!=3){
			cout<<"opcion invalida"<<endl;
		}
	}while(opcion!=3);
		cout<<"Saliendo del programa"<<endl;
	return 0;
}


