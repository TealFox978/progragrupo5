#include <iostream>
#include <time.h>
#include <cstdlib>
#include <ctime>
using namespace std;
class juego{
	public:
	int dado[5],d,ds=0,dc,p;
	int n,s=1,partida=0,s1,x=0;
	void intro(){
      		cout<<"Ingrese el número de jugadores: "; cin>>n;
		int punt[n],pts[n][10],vuel[n];
		for(int i=0;i<n;i++){  
                	for(int z=0;z<10;z++){ 
                        	pts[i][z]=0;
                	}
       		}
		for(int y=0;y<n;y++){
			punt[y]=0;
		}
		for(int j=0;j<n;j++){
			vuel[j]=0;
		}
        	while(s<=n){
                	cout<<"________________________________"<<endl;
                	cout<<"juega: JUGADOR"<<s<<endl;
                	dados1();
                	anotar(n,s,x,punt,pts,vuel);
                	if(s==n){
                        	cout<<"Sigue la partida? (s=1,n=0): "; cin>>s1;
                        	if(s1==1){
                                	s=0;
                        	}
                	}
                	s++;
        	}
        	total(n,punt);
	}
	void dados1(){
		srand(time(0));
		dado[0]=rand()%(6)+1;
		cout<<"Dado1= "<<dado[0];
		dado[1]=rand()%(6)+1;
                cout<<" ; Dado2= "<<dado[1];
		dado[2]=rand()%(6)+1;
                cout<<"; Dado3= "<<dado[2];
		dado[3]=rand()%(6)+1;
                cout<<"; Dado4= "<<dado[3];
		dado[4]=rand()%(6)+1;
                cout<<"; Dado5= "<<dado[4]<<endl;
		cout<<"Lanzara algún dado de nuevo?(s=1/n=0): "; cin>>p;
                if(p==1){
                        cout<<"Cuantos dados tirara de nuevo?: "; cin>>d;
	                while(ds<d){
        	                cout<<"Ingrese el número del dado a cambiar: "; cin>>dc;
                	        dado[dc-1]=rand()%(6)+1;
                        	cout<<" Dado"<<dc<<"= "<<dado[dc-1]<<endl;
                        	ds++;
                	}
                	ds=0;
                }

	}
	void anotar(int n, int s,int x,int punt[],int pts[][10],int vuel[]){
		int w,anotar=0;
		w=s-1;
		do{	
			cout<<"Opciones de puntos:"<<endl<<"1.Balas"<<endl;
			cout<<"2.Tontos"<<endl;
			cout<<"3.trenes"<<endl;
			cout<<"4.Cuadras"<<endl;
			cout<<"5.quinas"<<endl;
			cout<<"6.Senas"<<endl;
			cout<<"7.Escalera"<<endl;
			cout<<"8.Full"<<endl;
			cout<<"9.Poker"<<endl;
			cout<<"10.Grande"<<endl<<"11.Ya Anote todos mis puntos"<<endl;
			cout<<"Seleccione que puntos desea anotar: "; cin>>anotar;	
			switch(anotar){
               	 		case 1: cout<<"Balas: "; cin>>pts[w][0];
				break;
               	 		case 2: cout<<"Tontos: "; cin>>pts[w][1];
				break;
                		case 3: cout<<"Trenes: "; cin>>pts[w][2];
                		break;
                		case 4: cout<<"Cuadras: "; cin>>pts[w][3];
                		break;
                		case 5: cout<<"Quinas: "; cin>>pts[w][4];
                		break;
                		case 6: cout<<"Senas: "; cin>>pts[w][5];
                		break;
                		case 7: cout<<"ESCALERA: "; cin>>pts[w][6];
                		break;
                		case 8: cout<<"FULL: "; cin>>pts[w][7];
                		break;
                		case 9: cout<<"POKER: "; cin>>pts[w][8];
                		break;
                		case 10: cout<<"GRANDE: "; cin>>pts[w][9];
                		break;
			}
		}while(anotar<=10);
		int t=0,r;
		cout<<"________________________________"<<endl;
		cout<<"Puntaje actual: "<<endl;
		for(r=0;r<9;r++){
			t=t+pts[w][r];
		}
		punt[w]=t+vuel[w];
		vuel[w]=punt[w];
		r=0;
		t=0;
		cout<<"Puntaje Jugador "<<s<<"= "<<punt[w]<<endl;
	}
	void total(int n,int punt[]){
		int m=0,gd;
		cout<<"________________________________"<<endl;
		cout<<"Puntajes TOTALES"<<endl;
		for(int j=0;j<n;j++){
			cout<<"Jugador"<<j+1<<" ="<<punt[j]<<" ; ";
			if(punt[j]>m){
				m=punt[j];
				gd=j+1;
			}
		}
		cout<<endl;
		cout<<"________________________________"<<endl;
		cout<<"Ganador: Jugador"<<gd<<" puntaje: "<<m<<endl;
	}
};
class rpg{
	public:
		int dinero=0;
		int opcion=0;
		int saludPla=100;
		int saludMon=0;
		int armadura=1;
		int arma=1;
		int pocion=3;
		int x=0;
		int acc=0;
	
		int batalla(int opcion)
		{
			while(saludMon>0){
			
			cout<<"es tu turno!"<<endl;
			cout<<"1.- Atacar"<<endl;
			cout<<"2.- Usar poción"<<endl;
			cin>>acc;
			switch(acc){	
				case 1:
					dmgPla(arma);
				break;
				case 2:
					pocion=pocion-1;
					saludPla=saludPla+50;
					cout<<"te quedan "<<pocion<<"pociones"<<endl;
				break;
			}
			cout<<"El monstruo te ataca!"<<endl;
			dmgMon(armadura,opcion,saludPla);
			if(saludMon<=0){
				cout<<"Ganaste!"<<endl;
				switch(opcion){
					case 1: dinero=dinero+50;
					break;
					case 2: dinero=dinero+200;
					break;
					case 3: dinero=dinero+600;
					break;
				}
				pueblo();
			}
			}
		}
		void dmgMon(int armadura,int opcion, int saludPla){
			int dado = (rand()%9)+1;
			if (dado<10){
				int dano = (((rand()%3)+1)*opcion)-armadura;
				cout<<"fué un golpe ligero"<<" -"<<dano<<" hp"<<endl;
				saludPla = saludPla - dano;
				x=getchar();
				
			}
			else{
				int dano = (((rand()%3)+1)*opcion*2)-armadura;
				cout<<"¡fué un golpe crítico!"<<"... -"<<dano<<" hp"<<endl;
				saludPla = saludPla - dano;
				x=getchar();
				
			}
			if (saludPla<=0){
				gameOver();
			}
		}
		int dmgPla(int arma){
			int dado = (rand()%9)+1;
			if (dado<10){
				int dano = (((rand()%3)+1)+arma);
				cout<<"fué un golpe ligero"<<" -"<<dano<<" hp"<<endl;
				saludMon = saludMon - dano;
				cout<<"al mons. le quedan "<<saludMon<<" hp"<<endl;
				x=getchar();
				
			}
			else{
				int dano = (((rand()%3)+1)+arma*2);
				cout<<"¡fué un golpe crítico!"<<"... -"<<dano<<" hp"<<endl;
				saludMon = saludMon - dano;
				x=getchar();
				
		}
	}
		void tienda(){
		
		  cout<<"Ingrese la opción que desea comprar.-"<<endl;
		  cout<<"1.-armadura + espada de acero = 50 Z"<<endl;
		  cout<<"2.-armadura + espada de hipermetal = 200 Z"<<endl;
		  cout<<"3.-armadura + espada de dragonita = 800 Z"<<endl;
		  cout<<"9.- salir "<<endl;
		  cin>>opcion;
		  switch(opcion){
				case 1:
				if(dinero>=50){
				dinero = dinero - 50;
				armadura = 3;
				arma = 3;
				pueblo();}
				else{
					cout<<"No tienes suficiente dinero"<<endl;
					pueblo();
				}
				break;
				case 2: if(dinero>=200){
				dinero = dinero - 200;
				armadura = 8;
				arma = 8;
				pueblo();}
				else{
					cout<<"No tienes suficiente dinero"<<endl;
					pueblo();
				}
				break;
				case 3: if(dinero>=800){
				dinero = dinero - 800;
				armadura = 10;
				arma = 10;
				pueblo();}
				else{
					cout<<"No tienes suficiente dinero"<<endl;
					pueblo();
				}
				break;
				case 9: pueblo();
				break;
			}
		}
		void pueblo(){
			saludPla = 100;
			cout<<"Selecciona una ubicación para ir"<<endl;
			cout<<"1.-Bosque --- (Caza un  Kut-Ku - Fácil)"<<endl;
			cout<<"2.- Cueva --- (Caza un Zinogre - Medio)"<<endl;
			cout<<"3.-Montaña --- (Caza un Fatalis- Dificil)"<<endl;
			cout<<"4.- Tienda"<<endl;
			cout<<"5.- Stats"<<endl;
			cout<<"9.-Salir del juego "<<endl;
			cin>>opcion;
			switch(opcion){
				case 1: 
				saludMon = 20;
				batalla(1);
				break;
				case 2:
				saludMon = 30;
				 batalla(2);
				break;
				case 3: 
				saludMon=40;
				batalla(3);
				break;
				case 4: tienda();
				break;
				case 5:
					cout<<"Armadura: "<<armadura<<endl;
					cout<<"dinero: "<<dinero<<endl;
					cout<<"daño: "<<arma<<endl;
					pueblo();
				case 9: gameOver();
				break;
			}
		}
		void gameOver(){
			cout<<"GAME OVER"<<endl;
		}
};
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
	
	int opcion_juego;
	cout<<"Ingrese el número de juego que desea jugar"<<endl;
	cout<<"1.-Cacho"<<endl;
	cout<<"2.-Polonesa"<<endl;
	cout<<"3.-RPG"<<endl;
	cin>>opcion_juego;
	switch (opcion_juego){
		case 1:{
			
			juego cacho;
			cacho.intro();}
		break; 
		case 2:{
			
			int n=6,gan=0;
	int jugadores,s=0,ppn=1,puntaje,ss;
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
//		ppn=1;
		int i;
		int n=6;
		for(i=0; i<jugadores ; ++i){
			while(ppn==1){
				cout << "Es el turno del jugador "<< i+1 << endl;
                       		puntaje=0;
                       	 	numero.num(vec,n);
                       		numero.puntaje(puntaje,vec,n,ppn,gan,ss);
                       		cout<<puntaje<<endl;
                       	 	puntos[i]=puntos[i]+puntaje;
                       	 	cout<<"el puntaje actual del jugador "<<i+1<<" es igual a: "<<puntos[i]<<endl;
                	        cout<<" -----------------/ ---------------------"<<endl;
				if (puntos[i]>=1000){
                                        gan=1;
					ppn=0;
                                        cout <<endl;
                                        cout<<endl;
                                        cout<< " usted ha ganado el juego ;)"<<endl;
                                        cout<<endl;
                                        cout<<endl;
                                 }
                                else{
					cout << "desea volver a tirar sus dados? si es asi presione 1, de lo contrario coloque 0 "<<endl;
                                	cin>>ppn;
				//	ppn=1;
                                        gan=0;
                                }

//				cout<<"segundo ppn" <<ppn<<endl;
				cout<<" *********************************************************"<<endl;

			}

			if(gan==1){
				ppn=0;
			}
			else{
				ppn=1;
			}

                }

				}}		break;
		case 3:{
			//test
		rpg mh;
		mh.pueblo();}
		break;
		}
	return 0;
}
