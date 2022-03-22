#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>

using namespace std;

class polonesa{
        public:
	void num(int vec[], int &n){
//crear los numeros de los dados
		int i;
		for(i=0; i<n ; ++i){
			vec[i]=1+rand() %(7-1);
		}
		cout << "sacaste los siguientes dados: " <<endl;
		for (i=0 ; i<n ; ++i){
			cout<<vec[i]<<"-";
		}
		cout<<endl;
	}
//los numero que se repiten
	void puntaje(int &puntaje, int vec[],int &n, int &ppn, int &gan, int &ss){
        	int unos=0,dos=0,tres=0,cuatro=0, cincos=0,seis=0,i;
		for (i=0 ; i<n ; ++i){
                	if(vec[i]==1){
                        	unos=unos+1;
                	}
                	else if(vec[i]==5){
                        	cincos=cincos+1;
                	}
			else if(vec[i]==2){
                                dos=dos+1;
                        }
			else if(vec[i]=3){
                                tres=tres+1;
                        }
			else if(vec[i]==4){
                                cuatro=cuatro+1;
                        }
			else{
				seis=seis+1;
			}
        	}

//para ver si hicieron algun punto
		if(unos==0 and cincos==0 and dos<=2 and tres<=2 and cuatro<=2 and seis<=2){
			puntaje=puntaje+0;
			cout<<"usted tiene cero puntos"<<endl;
			ss=0;
		}

		if(unos==1 and cincos==1 and dos==1 and tres==1 and cuatro==1 and seis==1){
			puntaje=puntaje+2500;
			cout<<"usted obtuvo "<<puntaje<<endl;
			ss=6;
		}
		if(unos>=1){
			puntaje=puntaje+(unos*100);
			ss=ss+unos;
		}
		if(cincos>=1){
                        puntaje=puntaje+(cincos*50);
			ss=ss+cincos;
                }
                if(dos>=3){
			if(dos==4){
                                puntaje=puntaje+400;
				ss=ss+dos;
                        }
                        else{
                                puntaje=puntaje+200;
				ss=ss+dos;
                        }
		}
		if(tres>=3){
			if(tres==4){
                                puntaje=puntaje+600;
				ss=ss+tres;
                        }
                        else{
                                puntaje=puntaje+300;
				ss=ss+tres;
                        }

                }
		if(cuatro>=3){
			if(cuatro==4){
                                puntaje=puntaje+800;
				ss=ss+cuatro;
                        }
                        else{
                                puntaje=puntaje+400;
				ss=ss+cuatro;
                        }

                }
		if(seis>=3){
			if(seis==4){
				puntaje=puntaje+1200;
				ss=ss+seis;
			}
			else{
                        	puntaje=puntaje+600;
				ss=ss+seis;
                	}
		}

		if(unos==6 or cincos==6){
                        ppn=1;
			gan=1;
			ss=6;
                }

	}

};






int main(){
	int n=6,gan=0;
	int jugadores,s=0,ppn,puntaje,ss;
	int vec[n];
	cout<<" ---------------------------------- "<<endl;
	cout<<"ingrese numero de jugadores: ";
	cin>>jugadores;
	polonesa numero;
	int puntos[jugadores];
	int j;
	cout<<endl;
	for(j=0; j<jugadores ; ++j){
                puntos[j]=0;
	}
	while(gan==0){
		int i;
		int n=6;
		for(i=0; i<jugadores ; ++i){
        		cout << "Es el turno del jugador "<< i+1 << endl;
			puntaje=0;
			numero.num(vec,n);
        		numero.puntaje(puntaje,vec,n,ppn,gan,ss);
			cout<<puntaje<<endl;
			puntos[i]=puntos[i]+puntaje;
			cout<<"el puntaje actual del jugador "<<i+1<<" es igual a: "<<puntos[i]<<endl;
			cout<<" -----------------/ ---------------------"<<endl;
//			cout << "desea volver a tirar sus dados? si es asi presione 1, de lo contrario coloque 0 "<<endl;
//			cin>>ppn;
/*			if(ppn=1 and ss<=5){
				n=n-ss;
				numero.num(vec,n);
				numero.puntaje(puntaje,vec,n,ppn,gan,ss);
				cout<<puntaje<<endl;
                        	puntos[i]=puntos[i]+puntaje;
                	        cout<<"el puntaje actual del jugador "<<i+1<<" es igual a: "<<puntos[i]<<endl;
        	                cout<<" -----------------------------------------------------"<<endl;

			}
			else if(ppn=1 and ss==6){
				n=6;
				numero.num(vec,n);
                                numero.puntaje(puntaje,vec,n,ppn,gan,ss);
                                cout<<puntaje<<endl;
                                puntos[i]=puntos[i]+puntaje;
                                cout<<"el puntaje actual del jugador "<<i+1<<" es igual a: "<<puntos[i]<<endl;
                                cout<<" -----------------------------------------------------"<<endl;
			}
			else{
				cout<< " su turno a terminado " <<endl;
				cout<< " ----------------------------------------------" <<endl;
			}*/
			if (puntos[i]>=5000){
                                gan=1;
                        }
			else{
                                gan=0;
                        }

                }

	}
	return 0;
}

