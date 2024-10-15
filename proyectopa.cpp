#include<iostream>
#include<string>
#include<iomanip>
#include<unistd.h>
#include<windows.h>
#include<conio.h>

#include <limits>
#include <algorithm>

using namespace std;


void menu();
int ValidaEntero();
string ValidaTexto();
bool ValidarCodigo(const string& codigo);
string ValidaCodigo();
void quicksort(int primero, int ultimo);
void notimpr(int j,int c);
void desaprovados();
void aprovados();
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
	string codigo;
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

int ValidaEntero() {
    int Ent;
    while (true){
        cin>>Ent;
        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Entrada no valida. Por favor, ingrese un numero entero."<<endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return Ent;
        }
    }
}

string ValidaTexto(){
    string texto;
    while (true){
        getline(cin, texto);  
        bool Validad=true;
        for (char c:texto){
            if (!isalpha(c) && !isspace(c)){
                cout<<"El texto solo debe contener letras y espacios."<<endl;
                Validad=false;
                break;
            }
        }
        if (Validad){
            return texto;
        }
    }
}

bool ValidarCodigo(const string& codigo){
    if (codigo.length() != 11){
        return false;
    }
    for (int i=0; i<4; i++){
        if (!isdigit(codigo[i])){
            return false;
        }
    }
    if (codigo[4]!='-'){
        return false;
    }
    for (int i=5; i<11; i++){
        if (!isdigit(codigo[i])){
            return false;
        }
    }
    return true;
}

string ValidaCodigo(){
    string codigo;
    while (true) {
        cin>>codigo;
        if (ValidarCodigo(codigo)){
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return codigo;
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Código no válido. Por favor, ingrese un código en el formato (Ejemplo: 2024-119009)."<<endl;
        }
    }
}

void menu(){
	int op,c=1;
	cout<<setw(10)<<"BIENVENIDO DOCENTE"<<endl;
	cout<<"-------------------------------------\n";
	cout<<"Ingrese su nombre: ";
	doc.nombre=ValidaTexto();
	cout<<"Ingrese apellido: ";
	doc.apellidos=ValidaTexto();
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
		cout<<"\t6. Modificar casillas de notas ("<<c<<" casillas)\n";
		cout<<"\t7. Salir\n";
		cout<<"--------------------------------------"<<endl;
		cout<<"Seleccione una opcion: ";
		op=ValidaEntero();
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
				cout<<"Ingrese la cantidad (1-10): ";
				c=ValidaEntero();
				if(c>10||c<1){
					cout<<"\nIngrese una cantidad no mayor que 10 ni menor que 1 \n\n";
				}
				system("pause");
				system("cls");
				break;
			case 7:
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
	}while(op!=7);
	return;
}

void borrarnota(int n,int c){
	int b;
	cout<<"Ingrese la casilla de la nota que quiere eliminar ("<<c<<"): ";
	b=ValidaEntero();
	if(b<=c&&b>=0){
	doc.alu[n].notas[b-1]=0;
	doc.alu[n].profinal=(suma(n,c-1))/c;
	system("cls");
	return;
	} else {
		cout<<"Ingrese primero la cantidad de notas o ingrese nuevo: \n";
		system("pause");
		system("cls");
		return;
	}
}

void agregarnota(int n,int c){
	int b;
	cout<<"Ingrese la casilla de la nota que quieres agregar ("<<c<<"): ";
	b=ValidaEntero();
	if(b<=c&&b>=0){
	cout<<"Ingrese la nota: ";
	doc.alu[n].notas[b-1]=ValidaEntero();
	doc.alu[n].profinal=(suma(n,c-1))/c;
	system("cls");
	return;
	} else {
		cout<<"Ingrese primero la cantidad de notas o ingrese nuevo: \n";
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
		cout<<"Nombre: ";
		doc.alu[ca].name=ValidaTexto();
		cout<<"Apellido: ";
		doc.alu[ca].last=ValidaTexto();
		cout<<"Codigo: ";
		doc.alu[ca].codigo=ValidaCodigo();
		ca++;
		cout<<"Desea seguir agregando alumnos? (Si:1) (No:0): ";
		cin>>n;
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
	
	cout<<"Seleccione una opcion: ";
	op=ValidaEntero();
		switch(op){
			case 1:
				system("cls");
    			aprovados();
    			cout<<endl;
    			system("pause");
    			system("cls");
    			return;
				break;
			case 2:
				system("cls");
    			desaprovados();
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
    			quicksort(0,ca-1);
    			for (int i = 0; i < ca ; i++) {
        			cout<<doc.alu[i].name<<" "<<doc.alu[i].last;
        			gotoxy(50,i+3);
					cout<<doc.alu[i].profinal;
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
	string k;
	int b;
	cout<<"INGRESE EL CODIGO DE UN ALUMNO: ";
	k=ValidaCodigo();
	bool encontrado=false;
	for(int i=0;i<ca;i++){
		if(doc.alu[i].codigo==k){
			b=i;
			encontrado = true;
		}
	}
	if(encontrado){
		system("cls");
		int op;
		do{
			cout<<"ALUMNO\t\t\t\t\tNOTAS\n";
    		cout<<"-------------------------------------------------------\n";
			cout<<doc.alu[b].last<<"  "<<doc.alu[b].name;
			gotoxy(50,2);
			for(int i=0;i<c;i++){
				cout<<doc.alu[b].notas[i]<<" ";
			}
			cout<<endl;
			cout<<"1. Borrar nota\n2. Agregar nota\n0. Volver\nSeleccione una opcion: ";
			op=ValidaEntero();
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
	opc=ValidaEntero();
	switch (opc)
	{
	case 1:
		system("cls");
		return;
		break;
	case 2:
		for(int i=0;i<ca;i++){
			for(int j=0;j<ca;j++){
				doc.alu[i].notas[j]=0;
				doc.alu[i].profinal=0;
			}
		}
		system("cls");
		break;
	
	default:
		break;
	}
}

void eliminaralumnos(){
	string cod;
	if(ca>=0){
	cout<<"---------------Elimnar alumnos-----------------"<<endl;
	cout<<"-----------------------------------------------"<<endl;
	cout<<endl;
    cout<<"Ingrese el codigo del alumno a eliminar: ";
    cod=ValidaCodigo();
    
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
	} else {
		cout<<"No hay registros de alumnos. \n";
	}
	system("pause");
    system("cls");
	return;
}

void aprovados(){
	cout<<"Notas de los aprobados\n";
	cout<<"Nombre\t\t\t\t\t\tPromedio\n";
	cout<<"-------------------------------------------------------\n";
	quicksort(0,ca-1);
	int e=0;
	for(int i=0; i<ca;i++){
		if(doc.alu[i].profinal>=11){
			cout<<doc.alu[i].name<<" "<<doc.alu[i].last;
			gotoxy(50,e+3);
			cout<<doc.alu[i].profinal;
			cout<<'\n';	
			e++;
		}
	}
}

void desaprovados(){
	cout<<"Notas de los desaprobados\n";
	cout<<"Nombre\t\t\t\t\t\tPromedio\n";
	cout<<"-------------------------------------------------------\n";
	quicksort(0,ca-1);
	int e=0;
	for(int i=0; i<ca;i++){
		if(doc.alu[i].profinal<11){
			cout<<doc.alu[i].name<<" "<<doc.alu[i].last;
			gotoxy(50,e+3);
			cout<<doc.alu[i].profinal;
			cout<<'\n';	
			e++;
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

void quicksort(int primero, int ultimo){
    int central, i, j;
    int pivote;

    central = (primero + ultimo) / 2;
    pivote = doc.alu[central].profinal;
    i = primero;
    j = ultimo;

    do {
        while (doc.alu[i].profinal < pivote) i++;
        while (doc.alu[j].profinal > pivote) j--;

        if (i <= j) {
            ALUMNOS temp;
            temp = doc.alu[i];
            doc.alu[i] = doc.alu[j];
            doc.alu[j] = temp;
            i++;
            j--;
        }
    } while (i <= j);

    if (primero < j) {
        quicksort(primero, j);  // mismo proceso con sublista izquierda
    }
    if (i < ultimo) {
        quicksort(i, ultimo);  // mismo proceso con sublista derecha
    }
}