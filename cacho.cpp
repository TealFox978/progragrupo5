#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class juego{
	public:
	int dado[5],d,ds=0,dc,p;
	int balas,tontos,trenes,cuadras,quinas,senas;
	int escal,full,poker,g;
	int punt[5];
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
	void anotar(int n, int s){
		int w;
		int pts[n][10];
		w=s-1;
		cout<<"Anote los puntos obtenidos: "<<endl;
		cout<<"Balas(4pts): "; cin>>pts[s][0];
		cout<<"Tontos(8pts): "; cin>>pts[s][1];
		cout<<"Trenes(12pts): "; cin>>pts[s][2];
		cout<<"Cuadras(16pts): "; cin>>pts[s][3];
		cout<<"Quinas(20pts): "; cin>>pts[s][4];
		cout<<"Senas(24): "; cin>>pts[s][5];
		cout<<"ESCALERA(20/25pts): "; cin>>pts[s][6];
		cout<<"FULL(30/35pts): "; cin>>pts[s][7];
		cout<<"POKER(40/45pts): "; cin>>pts[s][8];
		cout<<"GRANDE(50/100): "; cin>>pts[s][9];
		int t=0;
		cout<<"________________________________"<<endl;
		cout<<"Puntaje actual: "<<endl;
		for(int r=0;r<9;r++){
			t=t+pts[s][r];
		}
		punt[s]=t;
		cout<<"Puntaje Jugador "<<s<<"= "<<punt[s]<<endl;
	}
	void total(int n){
		int m=0,gd;
		cout<<"________________________________"<<endl;
		cout<<"Puntajes TOTALES"<<endl;
		for(int j=1;j<=n;j++){
			cout<<"Jugador"<<j<<" ="<<punt[j]<<" ; ";
			if(punt[j]>m){
				m=punt[j];
				gd=j;
			}
		}
		cout<<endl;
		cout<<"________________________________"<<endl;
		cout<<"Ganador: Jugador"<<gd<<" puntaje: "<<m<<endl;
	}
};

int main(){
	int n,s=1,partida=0,s1;
	juego cacho;
	cout<<"Ingrese el número de jugadores: "; cin>>n;
	
	while(partida==0){
		while(s<=n){
			cout<<"________________________________"<<endl;
			cout<<"juega: JUGADOR"<<s<<endl;
        	cacho.dados1();
			cacho.anotar(n,s);
			s++;
		}
		cout<<"Sigue la partida? (s=1,n=0): "; cin>>s1;
		if(s1==1){
			partida=0;
		}
		else{
			partida=1;
		}
	}	
	cacho.total(n);
	return 0;
}

