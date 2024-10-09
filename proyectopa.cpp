#include<iostream>
#include<string>
#include<iomanip>
#include<unistd.h>
#include<windows.h>
using namespace std;

void menu();
void reiniciarnotas();
void imprimirnotas();
void buscaralumnos();
void agregaralumnos();
void borrarnota(int n);
void agregarnota(int n);
void eliminaralumnos();

struct ALUMNOS{
	double notas[100];
	int profinal[100];
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
	int op;
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
				imprimirnotas();
				break;
			case 5:
				system("cls");
				buscaralumnos();
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

void borrarnota(int n){
	int b;
	cout<<"Ingrese la casilla de la nota que quiere eliminar: ";cin>>b;
	doc.alu[n].notas[b-1]=0;
	system("cls");
	return;
}

void agregarnota(int n){
	int b;
	cout<<"Ingrese la casilla de la nota que quieres agregar: ";cin>>b;
	cout<<"Ingrese la nota: ";cin>>doc.alu[n].notas[b-1];
	system("cls");
	return;
}

void agregaralumnos(){
	int k;
	cout<<"Ingrese la cantidad de alumnos que desea ingresar: ";cin>>k;
	for(int i=0;i<k;i++){
		cin.ignore();
		cout<<"AGREGANDO ALUMNO "<<ca+1<<": \n";
		cout<<"Nombre: ";getline(cin,doc.alu[ca].name);
		cout<<"Apellido: ";getline(cin,doc.alu[ca].last);
		cout<<"Codigo: ";cin>>doc.alu[ca].codigo;
		ca++;
	}
	system("cls");
	return;
}

void imprimirnotas(){
	int op;
	
	do{
	cout<<"--------------------------------------"<<endl;
	cout<<"		Imprimir notas\n";
	cout<<"--------------------------------------"<<endl;
	cout<<"1.Ver aprobados"<<endl;
	cout<<"2.Ver desaprobados"<<endl;
	cout<<"3.General"<<endl;
	cout<<"4.Salir"<<endl;
	
	cout<<"Seleccione una opcion: ";cin>>op;
		switch(op){
			case 1:
				system("cls");
				cout<<"Notas de los aprobados\n";
    			cout<<"Nombre                        Notas\n";
    			cout<<"--------------------------------------\n";
    			for (int i = 0; i < ca ; i++) {
        			cout<<doc.alu[i].name<<" "<<doc.alu[i].last;
        			cout<<"\t\t"<<doc.alu[i].notas<<'\n';
    			}
    			cout<<endl;
    			system("pause");
    			system("cls");
    			return;
				break;
			case 2:
				system("cls");
				cout<<"Notas de los desaprobados\n";
    			cout<<"Nombre                        Notas\n";
    			cout<<"--------------------------------------\n";
    			for (int i = 0; i < ca ; i++) {
        			cout<<doc.alu[i].name<<" "<<doc.alu[i].last;
        			cout<<"\t\t"<<doc.alu[i].notas<<'\n';
    			}
    			cout<<endl;
    			system("pause");
    			system("cls");
    			return;
				break;
			case 3:
    			system("cls");
    			cout<<"Notas generales de todos\n";
    			cout<<"Nombre                        Notas\n";
    			cout<<"--------------------------------------\n";
    			for (int i = 0; i < ca ; i++) {
        			cout<<doc.alu[i].name<<" "<<doc.alu[i].last;
        			cout<<"\t\t"<<doc.alu[i].notas<<'\n';
    			}
    			cout<<endl;
    			system("pause");
    			system("cls");
    			return;
				break;
			case 4:
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

void buscaralumnos(){
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
			cout<<"ALUMNO\t\t\tNOTAS\n";
			cout<<"-----------------------------------\n";
			cout<<doc.alu[b].last<<"  "<<doc.alu[b].name<<"\t\t";
			for(int i=0;i<3;i++){
				cout<<doc.alu[b].notas[i]<<" ";
			}
			cout<<endl;
			cout<<"1. Borrar nota\n2. Agregar nota\n0. Volver\nSeleccione una opcion: ";cin>>op;
			switch(op){
				case 1:
					system("cls");
					borrarnota(b);
					break;
				case 2:
					system("cls");
					agregarnota(b);
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
	} else {
		cout<<"Elemento no encontrado\n";
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
    } else {
        cout<<"Alumno no encontrado.\n";
    }
	system("pause");
    system("cls");
	return;
}
