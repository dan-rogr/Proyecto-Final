#include <bits/stdc++.h> 

using namespace std; 

struct Usuario{
	string nombre;
	int edad;
	float peso;
	float altura;
	float MB;
	string sexo;
	string plan;
	string dieta;
};

void guardar(Usuario pers){ 
	string s;
	stringstream ss;
	ss << "EDAD: " << pers.edad << endl << "PESO: " << pers.peso << "Kg" <<  endl << "ALTURA: " << pers.altura << "cm" << endl << "SEXO: " <<pers.sexo << endl << "METABOLISMO BASAL (MB): " <<pers.MB << endl << "PLAN: " <<pers.plan << endl <<"DIETA Y CONSEJOS: " << pers.dieta << endl; 
	s = "NOMBRE: " + pers.nombre + "\n" + ss.str();
	
	ofstream archivo;
	string ruta = pers.nombre + ".txt";
	archivo.open(ruta.c_str(), ios::out); 
	 
	if(archivo.fail()){  
		cout<<"\t\t\tERROR AL GUARDAR EL ARCHIVO\n";
		exit(1);
	}
	archivo<<s; 
	archivo.close();
}

void guardarNuevaMarca(string ruta, string texto){ 
	ofstream archivo;
	archivo.open(ruta.c_str(), ios::out); 
	 
	if(archivo.fail()){  
		cout<<"\t\t\tERROR AL GUARDAR EL ARCHIVO\n";
		exit(1);
	}
	archivo<<texto; 
	archivo.close();
}

string cargar(string name){
	ifstream archivo;
	string texto, salida;
	
	archivo.open(name.c_str(), ios::in);
	if(archivo.fail()){
		cout<<"\t\t\tERROR AL ABRIR EL ARCHIVO\n";
		exit(1);
	}
	
	while(!archivo.eof()){
		getline(archivo, texto);
		salida += texto + "\n";
	}
	archivo.close();
	return salida;
}

void informacion(string name){
	cout<<"\n\t\t\t\t*INFORMACION DEL PERFIL*\n\n";
	string txt = cargar(name + ".txt");
	cout<<txt<<endl;
	system("pause");
}

void nueva_marca(string name){
	string txt = cargar(name + ".txt");
	cout<<"\n\t\t\t\t*ANADIR NUEVA MARCA: "<<name<<"*\n\n";
	Usuario pers;
	pers.nombre = name;
	cout<<"\n\t\t\t-> INGRESE SU EDAD: ";	
	cin>>pers.edad;
	cout<<"\n\t\t\t-> INGRESE SU PESO (KG): ";
	cin>>pers.peso;
	cout<<"\n\t\t\t-> INGRESE SU ALTURA (CM): ";
	cin>>pers.altura;
	cout<<"\n\t\t\t-> 1. HOMBRE - 2. MUJER: ";	
	int sx;
	cin>>sx;
	if(sx == 1){
		pers.sexo = "HOMBRE";
		pers.MB = (10 * pers.peso) + (6.25 * pers.altura) - (5*pers.edad) + 5;
	}else if(sx == 2){
		pers.sexo = "MUJER";
		pers.MB = (10 * pers.peso) + (6.25 * pers.altura) - (5*pers.edad) - 161;
	}else{
		cout<<"\n\t\t\tERROR EN LOS DATOS"<<endl;
		exit(1);
	}
	cout<<"\n\t\t\t-> SELECCIONE SU PLAN: 1. MANTENER  -  2. DEFINIR  -  3. VOLUMEN     : ";
	int pn; 
	cin>>pn;
	if(pn == 1){
		stringstream ss;
		ss << pers.MB;
		pers.plan = "MANTENER";
		pers.dieta = "DEBES CONSUMIR APROXIMADAMENTE " + ss.str() + " CALORIAS DIARIAS, 45% HIDRATOS, 35% PROTEINAS Y 25% DE GRASAS Y SIGUIENDO UN ENTRENAMIENTO DE LEVANTAMIENTO DE PESAS Y ACTIVIDAD CARDIOVASCULAR MODERADA";
	}else if(pn == 2){
		stringstream ss;
		ss << (pers.MB - 250);
		pers.plan = "DEFINIR";
		pers.dieta = "DEEBES CONSUMIR APROXIMADAMENTE " + ss.str() + " CALORIAS DIARIAS, 35-45% HIDRATOS, 20-35% PROTEINAS Y 15-25% GRASAS Y SIGUIENDO UN ENTRENAMIENTO DE LEVANTAMIENTO DE PESAS CON VARIOS DIAS A LA SEMANA DE ACTIVIDAD CARDIOVASCULAR";
	}else{
		stringstream ss;
		ss << (pers.MB + 250);
		pers.plan = "VOLUMEN";
		pers.dieta = "DEBES CONSUMIR APROXIMADAMENTE " + ss.str() + " CALORIAS DIARIAS, 50-55% HIDRATOS, 20-25% DE PROTEINAS Y  25-30% DE GRASAS Y SIGUIENDO UN ENTRENAMIENTO SOLO DE LEVANTAMIENTO DE PESAS.";
	}
	
	stringstream ss;
	ss << "EDAD: " << pers.edad << endl << "PESO: " << pers.peso << "Kg" <<  endl << "ALTURA: " << pers.altura << "cm" << endl << "SEXO: " <<pers.sexo << endl << "METABOLISMO BASAL (MB): " <<pers.MB << endl << "PLAN: " <<pers.plan << endl <<"DIETA Y CONSEJOS: " << pers.dieta << endl; 
	string s = "NUEVA MARCA REGISTRADA: \n" + ss.str();
	
	txt += s;
	guardarNuevaMarca(name + ".txt", txt);
	system("pause");
}

int perfil(string pers){
	int opcion;
	do{
		system("cls");
		system("color F0"); 
		system("color F0");
		cout<<"\t\t\t------------------------------------------"<<endl;
		cout<<"\t\t\t-                                        -"<<endl;
		cout<<"\t\t\t-               >>> PERFIL <<<           -"<<endl;
		cout<<"\t\t\t-                                        -"<<endl;
		cout<<"\t\t\t------------------------------------------"<<endl;
		cout<<"\t\t\t\t\t    "<<pers<<endl;
		cout<<"\t\t\t------------------------------------------"<<endl;	
		cout<<"\t\t\t-                                        -"<<endl;
		cout<<"\t\t\t-          1. INFORMACION DEL PERFIL,    -"<<endl;
		cout<<"\t\t\t-             PLAN E HISTORIAL.          -"<<endl;
		cout<<"\t\t\t-          2. ANADIR MARCA.              -"<<endl;
		cout<<"\t\t\t-          3. SALIR.                     -"<<endl;
		cout<<"\t\t\t-                                        -"<<endl;
		cout<<"\t\t\t------------------------------------------"<<endl;
		cout<<endl<<endl;
		cout<<"\tPOR FAVOR, SELECCIONE UN OPCION DEL SISTEMA --| ";
		cin>>opcion;
		
		switch(opcion){
			case 1:{
				system("cls");
				informacion(pers);
				break;
			}
			case 2:{
				system("cls");
				nueva_marca(pers);
				break;
			}
			case 3:{
				system("cls");
				cout<<endl<<"\t\t\t\t\t!!! GRACIAS POR UTLIZAR EL SISTEMA !!!"<<endl<<endl;
				return 0;
				break;
			}
			default:{
				system("cls");
				cout<<endl<<"\t\t\t\t\t!!! GRACIAS POR UTLIZAR EL SISTEMA !!!"<<endl<<endl;
				return 0;
				break;
			}
		}
	}while(opcion > 0 && opcion < 5);
}

void registro(){
	cout<<"\n\t\t\t\t*REGISTRO*\n\n";
	Usuario pers;
	cout<<"\n\t\t\t-> INGRESE SU NOMBRE: ";	
	cin>>pers.nombre;
	cout<<"\n\t\t\t-> INGRESE SU EDAD: ";	
	cin>>pers.edad;
	cout<<"\n\t\t\t-> INGRESE SU PESO (KG): ";
	cin>>pers.peso;
	cout<<"\n\t\t\t-> INGRESE SU ALTURA (CM): ";
	cin>>pers.altura;
	cout<<"\n\t\t\t-> 1. HOMBRE - 2. MUJER: ";	
	int sx;
	cin>>sx;
	if(sx == 1){
		pers.sexo = "HOMBRE";
		pers.MB = (10 * pers.peso) + (6.25 * pers.altura) - (5*pers.edad) + 5;
	}else if(sx == 2){
		pers.sexo = "MUJER";
		pers.MB = (10 * pers.peso) + (6.25 * pers.altura) - (5*pers.edad) - 161;
	}else{
		pers.sexo = "HOMBRE";
		cout<<"\n\t\t\tERROR EN LOS DATOS"<<endl;
		exit(1);
	}
	cout<<"\n\t\t\t-> SELECCIONE SU PLAN: 1. MANTENER  -  2. DEFINIR  -  3. VOLUMEN     : ";
	int pn; 
	cin>>pn;
	if(pn == 1){
		stringstream ss;
		ss << pers.MB;
		pers.plan = "MANTENER";
		pers.dieta = "DEBES CONSUMIR APROXIMADAMENTE " + ss.str() + " CALORIAS DIARIAS, 45% HIDRATOS, 35% PROTEINAS Y 25% DE GRASAS Y SIGUIENDO UN ENTRENAMIENTO DE LEVANTAMIENTO DE PESAS Y ACTIVIDAD CARDIOVASCULAR MODERADA";
	}else if(pn == 2){
		stringstream ss;
		ss << (pers.MB - 250);
		pers.plan = "DEFINIR";
		pers.dieta = "DEEBES CONSUMIR APROXIMADAMENTE " + ss.str() + " CALORIAS DIARIAS, 35-45% HIDRATOS, 20-35% PROTEINAS Y 15-25% GRASAS Y SIGUIENDO UN ENTRENAMIENTO DE LEVANTAMIENTO DE PESAS CON VARIOS DIAS A LA SEMANA DE ACTIVIDAD CARDIOVASCULAR";
	}else{
		stringstream ss;
		ss << (pers.MB + 250);
		pers.plan = "VOLUMEN";
		pers.dieta = "DEBES CONSUMIR APROXIMADAMENTE " + ss.str() + " CALORIAS DIARIAS, 50-55% HIDRATOS, 20-25% DE PROTEINAS Y  25-30% DE GRASAS Y SIGUIENDO UN ENTRENAMIENTO SOLO DE LEVANTAMIENTO DE PESAS.";
	}
	
	guardar(pers);
	cout<<"\n\t\t\tREGISTRO EXITOSO\n";
	system("pause");
	perfil(pers.nombre);
}

void iniciar_sesion(){
	cout<<"\n\t\t\t\t*INICIAR SESION*\n\n";
	string name;
	cout<<"\t\t\t-> INGRESE SU NOMBRE: ";
	cin>>name;
	string txt = cargar(name + ".txt");
	cout<<txt;
	if(txt.find(name) != string::npos) perfil(name);
	else{
		cout<<"\n\t\t\tUSUARIO NO ENCONTRADO\n";
		exit(1);
	}
	system("pause");
}

int main(int argc, char*argv[]){
	int opcion;
	do{
		system("cls");
		system("color F0"); 
		system("color F0");
		cout<<"\t\t\t------------------------------------------"<<endl;
		cout<<"\t\t\t-                                        -"<<endl;
		cout<<"\t\t\t-               >>> MENU <<<             -"<<endl;
		cout<<"\t\t\t-                                        -"<<endl;
		cout<<"\t\t\t------------------------------------------"<<endl;
		cout<<"\t\t\t-                                        -"<<endl;
		cout<<"\t\t\t-          1. INICIAR SESION.            -"<<endl;
		cout<<"\t\t\t-          2. REGISTRARSE.               -"<<endl;
		cout<<"\t\t\t-          3. SALIR.                     -"<<endl;
		cout<<"\t\t\t-                                        -"<<endl;
		cout<<"\t\t\t------------------------------------------"<<endl;
		cout<<endl<<endl;
		cout<<"\tPOR FAVOR, SELECCIONE UN OPCION DEL SISTEMA --| ";
		cin>>opcion;	
		switch(opcion){
			case 1:{
				system("cls");
				iniciar_sesion();
				break;
			}
			case 2:{
				system("cls");
				registro();
				break;
			}
			case 3:{
				system("cls");
				cout<<endl<<"\t\t\t\t\t!!! GRACIAS POR UTLIZAR EL SISTEMA !!!"<<endl<<endl;
				return 0;
			}
		}	
	}while(opcion > 0  && opcion < 4);
	return 0;
}
