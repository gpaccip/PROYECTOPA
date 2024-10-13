#include<iostream>
#include<string>
#include<iomanip>
#include<unistd.h>
#include<windows.h>
#include<conio.h>
using namespace std;


void menu();
void notimpr(int j,int c);
void desaprovados(int c);
void aprovados(int c);
void reiniciarnotas();
void imprimirnotas(int c);
void buscaralumnos(int c);
void agregaralumnos();
void borrarnota(int n);
void agregarnota(int n);
void eliminaralumnos();
int suma(int n,int c);
void gotoxy(int x,int y);

struct ALUMNOS{
	double notas[100]={0};
	int profinal=0;
	string name;
	string last;
	int codigo;
};

struct docente{
	string nombre;
	string apellidos;
	ALUMNOS alu[100];
}doc;

int ca = 0;

int main(){
	menu();
	return 0;
}

void menu(){
	int op,c;
	cout<<setw(10)<<"BIENVENIDO DOCENTE"<<endl;
	cout<<"-------------------------------------\n";
	cout<<"Ingrese su nombre: ";getline(cin, doc.nombre);
	cout<<"Ingrese apellido: ";getline(cin, doc.apellidos);
	system("pause");
	system("cls");
	do{
		cout<<"--------------------------------------"<<endl;
		cout<<"		BIENVENIDO\n";
		cout<<"--------------------------------------"<<endl;
		cout<<"\t1. Agregar alumnos\n"; //codigo, nombre, apellidos,
		cout<<"\t2. Eliminar alumnos\n";
		cout<<"\t3. Reiniciar notas\n";
		cout<<"\t4. Imprimir notas\n";	//1. Aprobados 2. Desaprobados 3. En general 0. volver	
		cout<<"\t5. Buscar alumnos\n"; //1. Buscar por codigo 1.Quitar notas 2. Agregar notas	
		cout<<"\t6. INGRESE LA CANTIDAD DE NOTAS QUE QUIERE ANADIR\n";
		cout<<"\t0. Salir\n";
		cout<<"--------------------------------------"<<endl;
		cout<<"Seleccione una opcion: ";cin>>op;
		switch(op){
			case 1:
				system("cls");
				agregaralumnos();
				break;
			case 2:
				system("cls");
				eliminaralumnos();
				break;
			case 3:
				system("cls");
				reiniciarnotas();
				break;
			case 4:
				system("cls");
				imprimirnotas(c);
				break;
			case 5:
				system("cls");
				buscaralumnos(c);
				break;
			case 6:
				system("cls");
				cout<<"Ingrese la cantidad (1-10): ";cin>>c;
				if(c>10||c<1){
					cout<<"\nIngrese una cantidad no mayor que 10 ni menor que 1 \n\n";
				}
				system("pause");
				system("cls");
				break;
			case 0:
				cout<<"Cerrando programa";
           			for(int i=1;i<=3;i++){
            			cout<<".";
            			sleep(1);
					}
				system("cls");
				break;
			default:
				system("cls");
          		cout<<"Opcion invalida. Intentelo de nuevo\n";
           		system("pause");
          		system("cls");
          	 	break;
		}
	}while(op!=0);
	return;
}

void borrarnota(int n,int c){
	int b;
	cout<<"Ingrese la casilla de la nota que quiere eliminar ("<<c<<"): ";cin>>b;
	if(b<c&&b>=0){
	doc.alu[n].notas[b-1]=0;
	doc.alu[n].profinal=(suma(n,c-1))/c;
	system("cls");
	return;
	} else{
		cout<<"Ingrese primero la cantidad de notas: \n";
		system("pause");
		system("cls");
		return;
	}
}

void agregarnota(int n,int c){
	int b;
	cout<<"Ingrese la casilla de la nota que quieres agregar ("<<c<<"): ";cin>>b;
	if(b<c&&b>=0){
	cout<<"Ingrese la nota: ";cin>>doc.alu[n].notas[b-1];
	doc.alu[n].profinal=(suma(n,c-1))/c;
	system("cls");
	return;
	}else{
		cout<<"Ingrese primero la cantidad de notas: \n";
		system("pause");
		system("cls");
		return;
	}
}

int suma(int n,int c){
	if(c<0){
		return 0;
	}else{
		int s=0;
		s=doc.alu[n].notas[c]+suma(n,c-1);
		return s;
	}
}

void agregaralumnos(){
	bool k=true;
	int n;
	do{
		cin.ignore();
		cout<<"AGREGANDO ALUMNO "<<ca+1<<": \n";
		cout<<"Nombre: ";getline(cin,doc.alu[ca].name);
		cout<<"Apellido: ";getline(cin,doc.alu[ca].last);
		cout<<"Codigo: ";cin>>doc.alu[ca].codigo;
		ca++;
		cout<<"Desea seguir agregando alumnos?(Si:1)(No:0): ";cin>>n;
		if(n==1){
			k=true;
		} else{
			k=false;
		}
	}while(k);
	system("cls");
	return;
}

void imprimirnotas(int c){
	int op;
	
	do{
	cout<<"--------------------------------------"<<endl;
	cout<<"		Imprimir notas\n";
	cout<<"--------------------------------------"<<endl;
	cout<<"1.Ver aprobados"<<endl;
	cout<<"2.Ver desaprobados"<<endl;
	cout<<"3.Promedio General"<<endl;
	cout<<"4.Notas Generales"<<endl;
	cout<<"5.Salir"<<endl;
	
	cout<<"Seleccione una opcion: ";cin>>op;
		switch(op){
			case 1:
				system("cls");
    			aprovados(c);
    			cout<<endl;
    			system("pause");
    			system("cls");
    			return;
				break;
			case 2:
				system("cls");
    			desaprovados(c); 
    			cout<<endl;
    			system("pause");
    			system("cls");
    			return;
				break;
			case 3:
    			system("cls");
    			cout<<"Notas promedio generales de todos\n";
    			cout<<"Nombre\t\t\t\t\t\tNotas\n";
    			cout<<"-------------------------------------------------------\n";
    			for (int i = 0; i < ca ; i++) {
        			cout<<doc.alu[i].name<<" "<<doc.alu[i].last;
        			gotoxy(50,i+3);cout<<doc.alu[i].profinal;
					cout<<'\n';
    			}
    			cout<<endl;
    			system("pause");
    			system("cls");
    			return;
				break;
			case 4:
				system("cls");
				cout<<"Notas Generales\n";
    			cout<<"Nombre\t\t\t\t\t\tNotas\n";
    			cout<<"-------------------------------------------------------\n";
    			for (int i = 0; i < ca ; i++) {
        			cout<<doc.alu[i].name<<" "<<doc.alu[i].last;
        			gotoxy(50,i+3);notimpr(i,c);
					cout<<'\n';
    			}
    			cout<<endl;
    			system("pause");
    			system("cls");
    			return;
				break;
			case 5:
				system("cls");
				return;
				break;
			default:
				system("cls");
          		cout<<"Opcion invalida. Intentelo de nuevo\n";
           		system("pause");
          		system("cls");
          	 	break;
		}
	}while(op!=0);
	return;
}

void buscaralumnos(int c){
	int k;
	int b;
	cout<<"INGRESE EL CODIGO DE UN ALUMNO: ";cin>>k;
	bool encontrado=false;
	for(int i=0;i<ca;i++){
		if(doc.alu[i].codigo==k){
			b=i;
			encontrado = true;
		}
	}
	if(encontrado){
		cout<<endl;
		int op;
		do{
			cout<<"ALUMNO\t\t\t\t\tNOTAS\n";
    		cout<<"-------------------------------------------------------\n";
			cout<<doc.alu[b].last<<"  "<<doc.alu[b].name;
			gotoxy(50,4);
			for(int i=0;i<c;i++){
				cout<<doc.alu[b].notas[i]<<" ";
			}
			cout<<endl;
			cout<<"1. Borrar nota\n2. Agregar nota\n0. Volver\nSeleccione una opcion: ";cin>>op;
			switch(op){
				case 1:
					system("cls");
					borrarnota(b,c);
					break;
				case 2:
					system("cls");
					agregarnota(b,c);
					break;
				case 0:
					system("cls");
					return;
				default:
					system("cls");
          			cout<<"Opcion invalida. Intentelo de nuevo\n";
           			system("pause");
          			system("cls");
          	 		break;	
			}
		}while(op!=0);
		system("pause");
	}else{
		cout<<"Alumno no encontrado\n";
	}
	system("pause");
	system("cls");
    return;
}

void reiniciarnotas(){
	int opc;
	cout<<"---------------REINICIAR NOTAS-----------------"<<endl;
	cout<<"-----------------------------------------------"<<endl;
	cout<<"¿ESTAS SEGURO QUE QUIERES REINICIAR LAS NOTAS?"<<endl;
	cout<<"      1.   NO                    2.   SI      "<<endl;
	cin>>opc;
	switch (opc)
	{
	case 1:
		return;
		break;
	case 2:
		for(int i=0;i<ca;i++){
			for(int j=0;j<ca;j++){
				doc.alu[i].notas[j]=0;
			}
		}
		break;
	
	default:
		break;
	}
}

void eliminaralumnos(){
	int cod;
	if(ca>=0){
	cout<<"---------------Elimnar alumnos-----------------"<<endl;
	cout<<"-----------------------------------------------"<<endl;
	cout<<endl;
    cout<<"Ingrese el codigo del alumno a eliminar: ";
    cin>>cod;
    
    int i;
    for(i = 0; i < ca; i++) {
        if (doc.alu[i].codigo == cod) {
            break;
        }
    }
    
    if(i<ca) {
        for(int j=i;j<ca-1;j++) {
            doc.alu[j].codigo = doc.alu[j+1].codigo;
        }
        ca--;
        cout<<"Alumno eliminado con exito.\n";
    }
	}else{
		cout<<"No hay registros de alumnos. \n";
	}
	system("pause");
    system("cls");
	return;
}

void aprovados(int c){
	cout<<"Notas de los aprobados\n";
	cout<<"Nombre\t\t\t\t\t\tPromedio\n";
	cout<<"-------------------------------------------------------\n";
	for(int i=0; i<ca;i++){
		if(doc.alu[i].profinal>=11){
			cout<<doc.alu[i].name<<" "<<doc.alu[i].last;
			gotoxy(50,i+3);cout<<doc.alu[i].profinal;
			cout<<'\n';	
		}
	}
}

void desaprovados(int c){
	cout<<"Notas de los desaprobados\n";
	cout<<"Nombre\t\t\t\t\t\tPromedio\n";
	cout<<"-------------------------------------------------------\n";
	for(int i=0; i<ca;i++){
		if(doc.alu[i].profinal<11){
			cout<<doc.alu[i].name<<" "<<doc.alu[i].last;
			gotoxy(50,i+3);cout<<doc.alu[i].profinal;
			cout<<'\n';	
		}
	}
}

void notimpr(int j,int c){
	for(int i=0;i<c;i++){
		cout<<doc.alu[j].notas[i]<<" ";
	}
}

void gotoxy(int x,int y){
	HANDLE hacon=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	SetConsoleCursorPosition(hacon,dwPos);
}
