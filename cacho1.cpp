#include <iostream>
#include <ctime>
#include <cstdlib>
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

int main(){
	juego cacho;
	cacho.intro();
	return 0;
}
