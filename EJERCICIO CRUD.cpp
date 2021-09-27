#include <iostream>
#include <string.h>
using namespace std;
const char *nombre_archivo = "archivo.dat";
int opcion=0;

struct Estudiante{
	int codigo;
	char nombres[50];
	char apellidos[50];
	int telefono;
};
void menu();
void crear();
void leer();
void actualizar();
void eliminar();

main(){
menu();	
}

void menu(){
	system("cls");
cout<<"\t____________MENU DE OPCIONES____________"<<endl;
cout<<"\t\t1. Crear estudiante"<<endl;
cout<<"\t\t2. ver estudiantes"<<endl;
cout<<"\t\t3. Actualizar estudiante"<<endl;
cout<<"\t\t4. eliminar estudiante"<<endl;
cout<<"\t\t5. Salir"<<endl<<endl;
cout<<"\t\t\tDigite su opcion: ";
cin>>opcion; 
			
	system("cls");
	
	switch(opcion)
	{
		case 1: crear();		 		;break;
 		case 2: leer();					;break;
 		case 3: actualizar();	 		;break;
 		case 4: eliminar();	 		;break;
 		case 5: exit(-1);				;break;  
		default:cout<<"Opcion no valida";  
	}	
}
void leer(){
		system("cls");
		FILE* archivo = fopen(nombre_archivo,"rb");
        if (!archivo){
            archivo = fopen(nombre_archivo,"w+b");
        }
        Estudiante estudiante;
        int id=0;
        fread(&estudiante,sizeof(Estudiante),1,archivo);
        cout<<"__"<<endl;
        cout<<"id"<<"|"<<"Codigo"<<"|"<<"Nombres"<<"|"<<"Apellidos"<<"|"<<"Telefono"<<endl;
        do{
        cout<<"__"<<endl;
        cout<<id<<"|"<<estudiante.codigo<<"|"<<estudiante.nombres<<"|"<<estudiante.apellidos<<"|"<<estudiante.telefono<<endl;
        fread(&estudiante,sizeof(Estudiante),1,archivo);
        id+=1;
        }while(feof(archivo)==0);
        fclose(archivo);
        cout<<endl;
		system("pause");
		
		menu();
}
void actualizar(){
FILE* archivo = fopen(nombre_archivo,"r+b");
    int id;
    Estudiante estudiante;
    string nombre,apellido;
    cout<<"Ingres el ID que desa Modificar:";
    cin>>id;
    fseek(archivo,id * sizeof(Estudiante),SEEK_SET);
    cout<<"Ingrese el Codigo: ";
        cin>>estudiante.codigo;
        cin.ignore();
        cout<<"Ingrese los Nombres:  ";
        getline(cin,nombre);
        strcpy(estudiante.nombres,nombre.c_str());
        cout<<"Ingrese los Apellidos: ";
        getline(cin,apellido);
        strcpy(estudiante.apellidos,apellido.c_str());
        cout<<"Ingrese el Telefono: ";
        cin>>estudiante.telefono;
        cin.ignore();

    fwrite(&estudiante,sizeof(Estudiante),1,archivo);
    fclose(archivo);
		system("pause");
		
		menu();
}
void crear(){
	char continuar;
	FILE* archivo = fopen(nombre_archivo,"ab");
	Estudiante estudiante;
	string nombre,apellido;
	do{
		fflush(stdin);
		cout<<"Ingrese el Codigo:";
		cin>>estudiante.codigo;
		cin.ignore();
		cout<<"Ingrese los Nombres:";
		getline(cin,nombre);
		strcpy(estudiante.nombres,nombre.c_str());
		cout<<"Ingrese los Apellidos:";
		getline(cin,apellido);
		strcpy(estudiante.apellidos,apellido.c_str());
		cout<<"Ingrese el Telefono:";
		cin>>estudiante.telefono;
		cin.ignore();
		fwrite(&estudiante,sizeof(Estudiante),1,archivo);
		cout<<"Dese Agregar otro Estudiante (s/n):";
		cin>>continuar;
	} while ( (continuar=='s') || (continuar=='S') );
	fclose(archivo);
	leer();
		system("pause");
		
		menu();
}
void eliminar(){
	FILE* archivo = fopen(nombre_archivo,"r+b");
	int id;
	Estudiante estudiante;
	string nombre,apellido;
	cout<<"Ingres el ID que desee eliminar: ";
	cin>>id;
	fseek(archivo,id * sizeof(Estudiante),SEEK_SET);

	estudiante.codigo=0;
	estudiante.	nombres[50]=0;
	estudiante.apellidos[50]=0;
	estudiante.	telefono=0;
	
	cout<<"se a eliminado el registro"<<endl;
	
	fwrite(&estudiante,sizeof(Estudiante),1,archivo);
	fclose(archivo);
		system("pause");
		
		menu();
}

