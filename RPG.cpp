#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

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
				gameOver();
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
		  switch(opcion){
				case 1: dinero = dinero - 50;
				armadura = 3;
				arma = 3;
				break;
				case 2: dinero = dinero - 200;
				armadura = 6;
				arma = 6;
				break;
				case 3: dinero = dinero - 800;
				armadura = 10;
				arma = 10;
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
				case 9: gameOver();
				break;
			}
		}
		void gameOver(){
			cout<<"GAME OVER"<<endl;
		}
};
int main(){
	rpg mh;
		mh.pueblo();
			
	return 0;
}
