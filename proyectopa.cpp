#include<iostream>
#include<string>
#include<iomanip>
#include<windows.h>
using namespace std;

void menu();
void reiniciarnotas();
void imprimirnotas();

struct ALUMNOS{
	double notas[100];
	int profinal[100];
	string name;
	string last;
	string codigo;
};

struct docente{
	string nombre;
	string apellidos;
	ALUMNOS alu[100];
}doc;

int ca = 0;

void agregaralumnos();

int main(){
	menu();
	return 0;
}

void menu(){
	int op;
	cout<<setw(10)<<"BIENVENIDO DOCENTE"<<endl;
	cout<<"-------------------------------------\n";
	cout<<"Ingrese su nombre: ";getline(cin, doc.nombre);
	cout<<"Ingrese apellido: ";getline(cin, doc.apellidos);
	system("cls");
	do{
		cout<<"--------------------------------------"<<endl;
		cout<<"		BIENVENIDO\n";
		cout<<"--------------------------------------"<<endl;
		cout<<"\t1. Agregar alumnos\n"; //codigo, nombre, apellidos,
		cout<<"\t2. Eliminar alumnos\n";
		cout<<"\t3. Reiniciar notas\n";
		cout<<"\t4. Agregar notas\n";
		cout<<"\t5. Quitar notas\n";
		cout<<"\t6. Imprimir notas\n";	//1. Aprobados 2. Desaprobados 3. En general 0. volver	
		cout<<"\t7. Buscar alumnos\n"; //1. Buscar por codigo	
		cout<<"\t0. Salir\n";
		cout<<"--------------------------------------"<<endl;
		cout<<"Seleccione una opcion: ";cin>>op;
		switch(op){
			case 1:
				system("cls");
				agregaralumnos();
				system("cls");
				break;
			case 2:
				system("cls");
				//elimnaralumnos();
				break;
			case 3:
				system("cls");
				reiniciarnotas();
				break;
			case 4:
				system("cls");
				//agregarnotas();
				break;
			case 5:
				system("cls");
				//quitarnotas();
				break;
			case 6:
				system("cls");
				imprimirnotas();
				break;
			case 7:
				system("cls");
				//buscaralumnos(ca-1);
				break;
			case 0:
				cout<<"Cerrando programa";
           			for(int i=1;i<=3;i++){
            			cout<<".";
            			sleep(1);
					}
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

void agregaralumnos(){
	int k;
	cout<<"Ingrese la cantidad de alumnos que desea ingresar: ";cin>>k;
	for(int i=0;i<k;i++){
		cout<<"AGREGANDO ALUMNO "<<ca+1<<": \n";
		cout<<"Nombre: ";getline(cin,doc.alu[ca].name);
		cin.ignore();
		cout<<"Apellido: ";getline(cin,doc.alu[ca].last);
		cin.ignore();
		cout<<"Codigo: ";getline(cin,doc.alu[ca].codigo);
		cin.ignore();
		ca++;
	}
}

void imprimirnotas(){
	int op;
	
	do{
	cout<<"--------------------------------------"<<endl;
	cout<<"		Imprimir notas\n";
	cout<<"--------------------------------------"<<endl;
	cout<<"1.Ver aprovados"<<endl;
	cout<<"2.Ver desaprovados"<<endl;
	cout<<"3.General"<<endl;
	cout<<"4.Salir"<<endl;
	
	cout<<"Seleccione una opcion: ";cin>>op;
		switch(op){
			case 1:
				system("cls");
				//agregaralumnos();
				return; //<-- retornara hacia la funcion verificar dni
				break;
			case 2:
				system("cls");
				//elimnaralumnos();
				break;
			case 3:
				system("cls");
				//reiniciarnotas();
				break;
			case 4:
				cout<<"Cerrando programa";
           			for(int i=1;i<=3;i++){
            			cout<<".";
            			sleep(1);
					}
				system("cls");
				void menu();
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
		for(int i=1,i<=100,i++){
			for(int j=1,j<=100,j++){
				doc.alu[i].notas[j]=0;
			}
		}
		break;
	
	default:
		break;
	}
	}