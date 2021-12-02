#include<iostream>
#include<vector>
#include<fstream>
#include <cstdlib>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string>
using namespace std;
struct tDatos_1 //Alberto, almacena los datos de hotel
{
    int habitacion,piso;
    char orientacion;
    int precio;
    string tipo;
    string sede;
    bool disponibilidad;
};
struct tVehiculo{
    string marca;
    string modelo;
    string tipo;
    string transmision;
    string combustible;
    string colores;
    float precio_v;
    bool disponible;
};
struct tComida{
	string comida;
	float cost;
};
struct tUsuario //Alberto, almacena datos de un usuario
{
    string nombre;
    string apellido;
    string email;
    string contr;
    int dia_nax;
    int mes_nax;
    int any_nax;
};

struct tReservados //Alberto & Kevin, almacena usuarios y datos de hotel/vehiculo/comida
{
    tDatos_1 reservado;//hotel
    tUsuario registrado;//datos usuario
    tComida comidas;//comida
    tVehiculo reservado2;//vehiculo
};
	void gotoxy(int x,int y){
    	HANDLE Posicion;
    	COORD Coordenadas;
    	Posicion = GetStdHandle(STD_OUTPUT_HANDLE);
    	Coordenadas.X = x;
    	Coordenadas.Y = y;
    	SetConsoleCursorPosition(Posicion,Coordenadas);
	}
	void supBuf(){//utilizaci�n de la tecla enter para avanzar
    		int ch;
    		while((ch = fgetc(stdin)) != EOF && ch != '\n' ){}
	}
	void leer_ficheroH (vector<tDatos_1>& fichero){ //Alberto, lee fichero de habitaciones
    	ifstream fin("Fichero.txt");
    	tDatos_1 s;
    		while(fin>>s.habitacion>>s.piso>>s.orientacion>>s.precio>>s.tipo>>s.sede>>s.disponibilidad){
     			 fichero.push_back(s);
   			 }
	}
	void leer_archivo(vector<tVehiculo>& S){//Kevin,leer fichero coches
		char texto[200];
		tVehiculo C;
		ifstream fin("coches_final01.txt");
		fin.getline(texto,200);
		while(fin>>C.marca>>C.modelo>>C.tipo>>C.transmision>>C.combustible>>C.colores>>C.precio_v>>C.disponible){
			S.push_back(C);
		}
	}
	void leer_comida(vector<tComida>& C){
		char texto[200];
		tComida L;
		ifstream fin("comida.txt");
		fin.getline(texto,200);
		while(fin>>L.comida>>L.cost){
			C.push_back(L);
		}
	}
	bool corroborar_email(string ca_email);
	bool corroborar_edad(int ca_dia, int ca_mes, int ca_any);
	void buscar_vehiculo(vector<tVehiculo>& S,vector<tDatos_1>& F,vector<tComida>& C,vector<tReservados>& ca_reservas,vector<tUsuario>& U);
	void menu_inicio_alquiler_visitante(vector<tVehiculo>& S,vector<tDatos_1>& F,vector<tComida>& C,vector<tReservados>& ca_reservas,vector<tUsuario>& U);
	void servicio_comida(vector<tComida>& C,vector<tVehiculo>& S,vector<tDatos_1>& f,vector<tReservados>& ca_reservas,vector<tUsuario>& U);
	void menu_inicio_habitacion_visitante(vector<tVehiculo>& S,vector<tDatos_1>& f,vector<tComida>& C,vector<tReservados>& ca_reservas,vector<tUsuario>& U);
	void menu_visitante(vector<tVehiculo>& S,vector<tDatos_1>& F,vector<tComida>& C,vector<tReservados>& ca_reservas,vector<tUsuario>& U );
	void menu_principal(vector<tVehiculo>& S,vector<tDatos_1>& f,vector<tComida>& C,vector<tReservados>& ca_reservas,vector<tUsuario>& U);

	void limite_consola(){
		for(int i = 4 ; i<180; i++) {
			gotoxy(i,2);printf("%c",205);//limite arriba
			gotoxy(i,56);printf("%c",205);//limite abajo
		}
		for(int i = 3 ; i < 56; i++) {
			gotoxy(3,i);printf("%c",186);//limite izquierdo
			gotoxy(180,i);printf("%c",186);//limite derecho
		}
		gotoxy(3,2);printf("%c",201);gotoxy(3,56);printf("%c",200);gotoxy(180,2);printf("%c",187);gotoxy(180,56);printf("%c",188);supBuf();//tecla enter para avanzar
		system("cls");//borrar todo
	}
	void pintar_portada(){
		system("color 7C");
			gotoxy (1,8); cout<<"                                .(&@@@@@@@@@@@@@@@#,                                                                                                                                 "<<endl;
			gotoxy (1,9); cout<<"                          #@@@@@@@@@@@@@@%/,..,/%@@@@@@@(           @@                                     .@@@@@@@@@@@@@@@@@@@%                              @@@@@@@@@@@@@@@@@@@@@  "<<endl;
			gotoxy (1,10);cout<<"                      #@@@@@@@@@@@@@/                 (@@@@@.      %@@                                           *@@@@@@@@@@@@@@@.                                 ,@@@@@@@@@@%      "<<endl;
			gotoxy (1,11);cout<<"                   &@@@@@@@@@@@@@#                       .@@@@&   .@@@                                             @@@@@@@@@@@@@@@@                                   (@@@@@%        "<<endl;
			gotoxy (1,12);cout<<"                *@@@@@@@@@@@@@@&                            @@@@@@@@@@                                             &@@@@@@@@@@@@@@@@.                                  /@@@@         "<<endl;
			gotoxy (1,13);cout<<"               (@@@@@@@@@@@@@@@                                @@@@@@@@                                             *@@@@@@@@@@@@@@@@@@                                  @@@.        "<<endl;
			gotoxy (1,14);cout<<"             ,@@@@@@@@@@@@@@@&                                  #@@@@@@                                             ,@@@@@@@@@@@@@@@@@@@&                                &@@         "<<endl;
			gotoxy (1,15);cout<<"            @@@@@@@@@@@@@@@@#                                    #@@@@@                                             ,@@@@@@@@@@@@@@@@@@@@@,                              #@@         "<<endl;
			gotoxy (1,16);cout<<"          ,@@@@@@@@@@@@@@@@&                                      @@@@@                                             ,@@@@@@@@@@@@@@@@@@@@@@&                             *@@         "<<endl;
			gotoxy (1,17);cout<<"         *@@@@@@@@@@@@@@@@@                                        @@@@                                             ,@@@@@@@@@@@@@@@@@@@@@@@@(                           ,@@         "<<endl;
			gotoxy (1,18);cout<<"        /@@@@@@@@@@@@@@@@@                                         %@@@                                             ,@@ .@@@@@@@@@@@@@@@@@@@@@@                          ,@@         "<<endl;
			gotoxy (1,19);cout<<"       *@@@@@@@@@@@@@@@@@%                                          @@@                                             ,@@   %@@@@@@@@@@@@@@@@@@@@@@                        ,@@         "<<endl;
			gotoxy (1,20);cout<<"       @@@@@@@@@@@@@@@@@@                                           @@@                                             ,@@     @@@@@@@@@@@@@@@@@@@@@@*                      ,@@         "<<endl;
			gotoxy (1,21);cout<<"      @@@@@@@@@@@@@@@@@@@                                           %@@                                             ,@@      (@@@@@@@@@@@@@@@@@@@@@@                     ,@@         "<<endl;
			gotoxy (1,22);cout<<"     *@@@@@@@@@@@@@@@@@@#                                                                                                                                                ,@@         "<<endl;
			gotoxy (1,23);cout<<"     @@@@@@@@@@@@@@@@@@@                                                                                                                                                 ,@@         "<<endl;
			gotoxy (1,24);cout<<"     @@@@@@@@@@@@@@@@@@@                                                                                                                                                 ,@@         "<<endl;
			gotoxy (1,25);cout<<"    (@@@@@@@@@@@@@@@@@@@     @@,   &@@         ,@@@@@@@,        @@@@@@@@&       .@@@@@@@,        @@@            @@@@@@@@        .@@@@@@@#           %@@@                 ,@@         "<<endl;
			gotoxy (1,26);cout<<"    &@@@@@@@@@@@@@@@@@@@     @@,   &@@        (@@     @@/          @@@          .@@              @@@            @@@             .@@   .@@          /@@*@@                ,@@         "<<endl;
			gotoxy (1,27);cout<<"    @@@@@@@@@@@@@@@@@@@&     @@@@@@@@@        &@@     @@&          @@@          .@@@@@@@         @@@            @@@@@@@,        .@@@@@@@&          @@  &@@               ,@@         "<<endl;
			gotoxy (1,28);cout<<"    @@@@@@@@@@@@@@@@@@@&     @@,   &@@         @@@   @@@           @@@          .@@              @@@            @@@             .@@  &@@          @@@@@@@@%              ,@@         "<<endl;
			gotoxy (1,29);cout<<"    @@@@@@@@@@@@@@@@@@@&     @@,   &@@          ,@@@@@.            @@@          .@@@@@@@#        @@@@@@@        @@@@@@@@        .@@   &@@        @@/     @@/             ,@@         "<<endl;
			gotoxy (1,30);cout<<"    @@@@@@@@@@@@@@@@@@@@                                                                                                                                                 ,@@         "<<endl;
			gotoxy (1,31);cout<<"    #@@@@@@@@@@@@@@@@@@@                                                                                                                                                 ,@@         "<<endl;
			gotoxy (1,32);cout<<"    .@@@@@@@@@@@@@@@@@@@                           (@@@@@@@@@@@@@@@@@@@@@.                                          ,@@                        @@@@@@@@@@@@@@@@@@@@@@@   ,@@         "<<endl;
			gotoxy (1,33);cout<<"     @@@@@@@@@@@@@@@@@@@                             #@@@@@@@@@@@@@@@@@@,                                           ,@@                         (@@@@@@@@@@@@@@@@@@@@@@# ,@@         "<<endl;
			gotoxy (1,34);cout<<"     #@@@@@@@@@@@@@@@@@@,                             @@@@@@@@@@@@@@@@@@                                            ,@@                           @@@@@@@@@@@@@@@@@@@@@@@*@@         "<<endl;
			gotoxy (1,35);cout<<"      @@@@@@@@@@@@@@@@@@&                             ,@@@@@@@@@@@@@@@@@                                            ,@@                            #@@@@@@@@@@@@@@@@@@@@@@@@         "<<endl;
			gotoxy (1,36);cout<<"      ,@@@@@@@@@@@@@@@@@@                              @@@@@@@@@@@@@@@@@                                            ,@@                              @@@@@@@@@@@@@@@@@@@@@@@         "<<endl;
			gotoxy (1,37);cout<<"       &@@@@@@@@@@@@@@@@@                              @@@@@@@@@@@@@@@@@                                            ,@@                               .@@@@@@@@@@@@@@@@@@@@@         "<<endl;
			gotoxy (1,38);cout<<"        @@@@@@@@@@@@@@@@@@                             @@@@@@@@@@@@@@@@@                                            ,@@                                 %@@@@@@@@@@@@@@@@@@@         "<<endl;
			gotoxy (1,39);cout<<"         @@@@@@@@@@@@@@@@@,                            @@@@@@@@@@@@@@@@@                                            ,@@                                   @@@@@@@@@@@@@@@@@@         "<<endl;
			gotoxy (1,40);cout<<"          &@@@@@@@@@@@@@@@@                            @@@@@@@@@@@@@@@@@                                            /@@.                                   #@@@@@@@@@@@@@@@@         "<<endl;
			gotoxy (1,41);cout<<"           ,@@@@@@@@@@@@@@@@                           @@@@@@@@@@@@@@@@@                                            #@@*                                     @@@@@@@@@@@@@@@         "<<endl;
			gotoxy (1,42);cout<<"             %@@@@@@@@@@@@@@@                          @@@@@@@@@@@@@@@@@                                            @@@%                                      *@@@@@@@@@@@@@         "<<endl;
			gotoxy (1,43);cout<<"               #@@@@@@@@@@@@@@,                        @@@@@@@@@@@@@@@@@                                            @@@@                                        @@@@@@@@@@@@         "<<endl;
			gotoxy (1,44);cout<<"                 .@@@@@@@@@@@@@@.                     %@@@@@@@@&,   @@@@                                           @@@@@@                                         @@@@@@@@@@         "<<endl;
			gotoxy (1,45);cout<<"                    .@@@@@@@@@@@@@*                  @@@@@@@,        @@@                                         &@@@@@@@@@#                                       &@@@@@@@@         "<<endl;
			gotoxy (1,46);cout<<"                        .@@@@@@@@@@@@@*          ,&@@@@@*             @@                                    .@@@@@@@@@@@@@@@@@@@@@                                   @@@@@@@         "<<endl;
			gotoxy (1,47);cout<<"                               ,#@@@@@@@@@@@@@@@@@/                                                        ..@@@@@@@@@@@@@@@@@@@@@@.                                  @@@@@@         "<<endl;
			gotoxy (1,50);cout<<"	                                                                          By C.Alberto & K.Tipan                                                                                    "<<endl;
		limite_consola();
	}
	void bienvenido(){
		system("color 0E");
		int a, b=48, i, j;
		for(i=8, j=7; i<=b, j<=b; i++, j++){
			gotoxy(i,6); cout<<"########  #### ######## ##    ## ##     ## " <<endl;
			gotoxy(i,7); cout<<"##     ##  ##  ##       ###   ## ##     ## " <<endl;
			gotoxy(i,8); cout<<"##     ##  ##  ##       ####  ## ##     ## " <<endl;
			gotoxy(i,9); cout<<"########   ##  ######   ## ## ## ##     ## " <<endl;
			gotoxy(i,10);cout<<"##     ##  ##  ##       ##  ####  ##   ##  " <<endl;
			gotoxy(i,11);cout<<"##     ##  ##  ##       ##   ###   ## ##   " <<endl;
			gotoxy(i,12);cout<<"########  #### ######## ##    ##    ###    " <<endl;
				//borrar rastro
		    	gotoxy (j,6); cout <<" ";gotoxy (j,7); cout <<" ";gotoxy (j,8); cout <<" ";	gotoxy (j,9); cout <<" ";gotoxy (j,10);cout <<" ";gotoxy (j,11);cout <<" ";gotoxy (j,12);cout <<" ";
		}
		int k,c = 91;
		for(i=176, j=175; i>=c, j>=c; i--, j--){
			gotoxy(i,6);  cout<<"######## ##    ## #### ########   #######  " <<endl;
			gotoxy(i,7);  cout<<"##       ###   ##  ##  ##     ## ##     ## " <<endl;
			gotoxy(i,8);  cout<<"##       ####  ##  ##  ##     ## ##     ## " <<endl;
			gotoxy(i,9);  cout<<"######   ## ## ##  ##  ##     ## ##     ## " <<endl;
			gotoxy(i,10); cout<<"##       ##  ####  ##  ##     ## ##     ## " <<endl;
			gotoxy(i,11); cout<<"##       ##   ###  ##  ##     ## ##     ## " <<endl;
			gotoxy(i,12); cout<<"######## ##    ## #### ########   #######  " <<endl;
				//borrar rastro
		    	gotoxy (j,6); cout <<" ";gotoxy (j,7); cout <<" ";gotoxy (j,8); cout <<" ";gotoxy (j,9); cout <<" ";gotoxy (j,10);cout <<" ";gotoxy (j,11);cout <<" ";gotoxy (j,12);cout <<" ";
		}
	}
		void final(){
			system("cls");
		system("color 7C");
		gotoxy(27,23);cout<<" #####  ######     #     #####  ###    #     #####     ######  ####### ######     ####### #       #######  #####  ### ######      ";
		gotoxy(27,24);cout<<"#     # #     #   # #   #     #  #    # #   #     #    #     # #     # #     #    #       #       #       #     #  #  #     #     ";
		gotoxy(27,25);cout<<"#       #     #  #   #  #        #   #   #  #          #     # #     # #     #    #       #       #       #        #  #     #     ";
		gotoxy(27,26);cout<<"#  #### ######  #     # #        #  #     #  #####     ######  #     # ######     #####   #       #####   #  ####  #  ######      ";
		gotoxy(27,27);cout<<"#     # #   #   ####### #        #  #######       #    #       #     # #   #      #       #       #       #     #  #  #   #       ";
		gotoxy(27,28);cout<<"#     # #    #  #     # #     #  #  #     # #     #    #       #     # #    #     #       #       #       #     #  #  #    #      ";
 		gotoxy(27,29);cout<<" #####  #     # #     #  #####  ### #     #  #####     #       ####### #     #    ####### ####### #######  #####  ### #     #     ";

		gotoxy(27,31);cout<<"                        #####  #     #    #     # ####### ####### ####### #       ####### ######     #   						   ";
		gotoxy(27,32);cout<<"                       #     # ##    #    #     # #     #    #    #       #       #       #     #   # #   						   ";
		gotoxy(27,33);cout<<"                       #       # #   #    #     # #     #    #    #       #       #       #     #  #   #  						   ";
		gotoxy(27,34);cout<<"                       #  #### #  #  #    ####### #     #    #    #####   #       #####   ######  #     # 						   ";
		gotoxy(27,35);cout<<"                       #     # #   # #    #     # #     #    #    #       #       #       #   #   ####### 						   ";
		gotoxy(27,36);cout<<"                       #     # #    ##    #     # #     #    #    #       #       #       #    #  #     # 						   ";
		gotoxy(27,37);cout<<"                        #####  #     #    #     # #######    #    ####### ####### ####### #     # #     # 						   ";
	}
	void menu_buscar_habitacion_sede(vector<tVehiculo>& S,vector<tDatos_1>& fichero,vector<tComida>& C,vector<tReservados>& ca_reservas,vector<tUsuario>& U){
		system("cls");
		bienvenido();
		gotoxy(37,20);cout<<"Habitacion segun sede";
		gotoxy(39,22);cout<<"1. Diagonal          2. Rambla de Catalunya         3. Paseo Maritimo        4. Forum       5. La Maquinista";
			int n;
			while(n!=6){
				string ca_sede;
				gotoxy(40,24);cout<<"Seleccione una opcion: ";cin>>n;
					if(n==1)ca_sede="Diagonal";
						else if(n==2)ca_sede="RamblaCat";
							else if(n==3)ca_sede="PaseoMar";
								else if(n==4)ca_sede="Forum";
									else if(n==5)ca_sede="Maquinista";
					int cont=0;
						if(ca_sede=="Diagonal" || ca_sede=="RamblaCat" || ca_sede=="PaseoMar" || ca_sede=="Forum" || ca_sede=="Maquinista"){
    						gotoxy(40,26);cout<<"Las habitaciones de esta sede son: "<<endl<<endl<<endl;
    						for(int ca_i=0;ca_i<fichero.size();ca_i++){
        						if(fichero[ca_i].sede==ca_sede){
           							cout<<"                                        "<<"La habitacion numero: "<<fichero[ca_i].habitacion<<" ubicada en el piso "<<fichero[ca_i].piso<< " y con orientacion al ";
           							if(fichero[ca_i].orientacion=='N')cout<<"Norte";
           								else if(fichero[ca_i].orientacion=='S')cout<<"Sur";
           										else if(fichero[ca_i].orientacion=='E')cout<<"Este";
          											else if(fichero[ca_i].orientacion=='O')cout<<"Oeste";
           							cout<<" de tipo "<<fichero[ca_i].tipo<<". Estado: ";
           								if(fichero[ca_i].disponibilidad==true)cout<<"disponible."<<endl;
           									else if(fichero[ca_i].disponibilidad==false)cout<<"ocupada."<<endl;
           								cont++;
      							}
    						}
    						system("PAUSE");
    						supBuf();
    							for(int i=0;i<cont+2;i++){
									gotoxy(40,26+i);cout<<"                                                                                                                           "<<endl;
								}
						}
			}system("cls");menu_inicio_habitacion_visitante(S,fichero,C,ca_reservas,U);
	}
	void menu_buscar_habitacion_tipo(vector<tVehiculo>& S,vector<tDatos_1>& fichero,vector<tComida>& C,vector<tReservados>& ca_reservas,vector<tUsuario>& U){
		system("cls");
		bienvenido();

		gotoxy(37,20);cout<<"Habitacion segun tipo";

		gotoxy(39,22);cout<<"1. Sencilla        2. Doble        3. Matrimonial        4. SJunior        5. SDoble        6. SPresidencial";
			int n;
			while(n!=7){
				string ca_tipo;
				gotoxy(40,24);cout<<"Seleccione una opcion: ";cin>>n;

					if(n==1)ca_tipo="sencilla";
						else if(n==2)ca_tipo="doble";
							else if(n==3)ca_tipo="Matrimonial";
								else if(n==4)ca_tipo="SJunior";
									else if(n==5)ca_tipo="SDoble";
										else if(n==6)ca_tipo="SPresidencial";
						int cont=0;
							if(ca_tipo=="sencilla" || ca_tipo=="doble" || ca_tipo=="Matrimonial" || ca_tipo=="SJunior" || ca_tipo=="SDoble"|| ca_tipo=="SPresidencial"){
								gotoxy(40,26);cout<<"Para este tipo de habitacion tenemos las siguientes: "<<endl<<endl;
    							for(int ca_j=0;ca_j<fichero.size();ca_j++){
        							if(fichero[ca_j].tipo==ca_tipo){
           								cout<<"                                        "<<"La habitacion numero: "<<fichero[ca_j].habitacion<<" ubicada en el piso "<<fichero[ca_j].piso<< " y con orientacion al ";
          									if(fichero[ca_j].orientacion=='N')cout<<"Norte";
           										else if(fichero[ca_j].orientacion=='S')cout<<"Sur";
            											else if(fichero[ca_j].orientacion=='E')cout<<"Este";
           													else if(fichero[ca_j].orientacion=='O')cout<<"Oeste";
           								cout<<" de la sede "<<fichero[ca_j].sede<<". Estado: ";
           									if(fichero[ca_j].disponibilidad==true)cout<<"disponible."<<endl;
            									else if(fichero[ca_j].disponibilidad==false)cout<<"ocupada."<<endl;
            									cont++;
        							}
    							}
    							system("PAUSE");
    							supBuf();
    								for(int i=0;i<cont+2;i++){
										gotoxy(40,26+i);cout<<"                                                                                                                           "<<endl;
									}
							}

			}system("cls");menu_inicio_habitacion_visitante(S,fichero,C,ca_reservas,U);
	}
	void habitaciones_disponibles(vector<tVehiculo>& S,vector<tDatos_1>& f,vector<tComida>& C,vector<tReservados>& ca_reservas,vector<tUsuario>& U){
		system("cls");
		bienvenido();
			gotoxy(85,14);cout<<"A GN HOTELERA"<<endl;
    		gotoxy(75,15);cout<<"Seccion de busqueda de habitaciones"<< endl;
    		for(int i = 69 ; i<114; i++) {
				gotoxy(i,18);printf("%c",205);//limite arriba
				gotoxy(i,22);printf("%c",205);//limite abajo
			}
			for(int i = 19 ; i < 22; i++) {
				gotoxy(68,i);printf("%c",186);//limite izquierdo
				gotoxy(114,i);printf("%c",186);//limite derecho
			}
				gotoxy(68,18);printf("%c",201);gotoxy(68,22);printf("%c",200);gotoxy(114,18);printf("%c",187);gotoxy(114,22);printf("%c",188);
    			gotoxy(79,19);cout<< "HABITACIONES EN DISPOSICION"<<endl;
    			gotoxy(71,21);cout<< "DISPONIBLES                NO DISPONIBLES"<<endl<<endl<<endl;
    				for(int i=0;i<f.size();i++){
    					if(f[i].disponibilidad==true)cout<<"                                                                "<<f[i].habitacion<<" "<<f[i].piso<<" "<<f[i].orientacion<<" "<<f[i].tipo<<" "<<f[i].sede<<endl;
							else cout<<"                                                                                              "<<f[i].habitacion<<" "<<f[i].piso<<" "<<f[i].orientacion<<" "<<f[i].tipo<<" "<<f[i].sede<<endl;
					}
				gotoxy(75,26+f.size());cout<< "Pulse ENTER para volver al menu"<<endl<<endl;
				system("pause");supBuf();menu_inicio_habitacion_visitante(S,f,C,ca_reservas,U);
	}
	void vehiculos_disponibles(vector<tVehiculo>& S,vector<tDatos_1>& f,vector<tComida>& C,vector<tReservados>& ca_reservas,vector<tUsuario>& U){
		system("cls");
		bienvenido();
			gotoxy(85,14);cout<<"A GN HOTELERA"<<endl;
    		gotoxy(75,15);cout<<"Seccion de busqueda de habitaciones"<< endl;
    		for(int i = 69 ; i<114; i++) {
				gotoxy(i,18);printf("%c",205);//limite arriba
				gotoxy(i,22);printf("%c",205);//limite abajo
			}
			for(int i = 19 ; i < 22; i++) {
				gotoxy(68,i);printf("%c",186);//limite izquierdo
				gotoxy(114,i);printf("%c",186);//limite derecho
			}
				gotoxy(68,18);printf("%c",201);gotoxy(68,22);printf("%c",200);gotoxy(114,18);printf("%c",187);gotoxy(114,22);printf("%c",188);
    			gotoxy(79,19);cout<< "VEHICULOS EN DISPOSICION GN"<<endl;
    			gotoxy(71,21);cout<< "DISPONIBLES                NO DISPONIBLES"<<endl<<endl<<endl;
    				for(int i=0;i<S.size();i++){
    					if(S[i].disponible==true)cout<<"                                                                       "<<S[i].marca<<" "<<S[i].modelo<<endl;
							else cout<<"                                                                                                  "<<S[i].marca<<" "<<S[i].modelo<<endl;
					}
				gotoxy(75,26+S.size());cout<< "Pulse ENTER para volver al menu"<<endl<<endl;
				system("pause");supBuf();menu_inicio_alquiler_visitante(S,f,C,ca_reservas,U);
	}
	void master_control(string usuario, string contr, vector<tReservados> ca_reservas){
    	string nombreFichero="Historial de datos.txt";
    		if(usuario=="admin" && contr=="admin"){
    			ofstream ofs(nombreFichero.c_str());

    			ofs<<"Nombre usuario"<<" "<<"Apellido usuario"<<" ";
                ofs<<"Email usuario"<<" "<<"Contrasenya usuario"<<" ";
                ofs<<"Habitacion reservada"<<" "<<"Tipo de habitacion reservada"<<" ";
                ofs<<"Sede de la habitacion"<<" "<<"Precio habitacion reservada"<<" ";
                ofs<<"Marca vehiculo reservado"<<" "<<"Modelo vehiculo reservado"<<" ";
                ofs<<"Color vehiculo reservado"<<" "<<"Tipo vehiculo reservado"<<" ";
                ofs<<"Precio vehiculo reservado"<<" ";
                ofs<<"Comida reservada"<<" "<<"Precio comida reservada"<<endl<<endl;

    				for(int ca_g=0;ca_g<ca_reservas.size();ca_g++){
       					ofs<<ca_reservas[ca_g].registrado.nombre<<" "<<ca_reservas[ca_g].registrado.apellido<<" ";
        				ofs<<ca_reservas[ca_g].registrado.email<<" "<<ca_reservas[ca_g].registrado.contr<<" ";
        				ofs<<ca_reservas[ca_g].reservado.habitacion<<" "<<ca_reservas[ca_g].reservado.tipo<<" ";
        				ofs<<ca_reservas[ca_g].reservado.sede<<" "<<ca_reservas[ca_g].reservado.precio<<" ";
        				ofs<<ca_reservas[ca_g].reservado2.marca<<" "<<ca_reservas[ca_g].reservado2.modelo<<" ";
        				ofs<<ca_reservas[ca_g].reservado2.colores<<" "<<ca_reservas[ca_g].reservado2.tipo<<" ";
        				ofs<<ca_reservas[ca_g].reservado2.precio_v<<" ";
        				ofs<<ca_reservas[ca_g].comidas.comida<<" "<<ca_reservas[ca_g].comidas.cost<<endl;
    				}
    				ofs.close();
   	 		}
	}
	void mostrar_reservas(vector<tReservados>& ca_reservas,vector<tVehiculo>& S,vector<tDatos_1>& f,vector<tComida>& C,vector<tUsuario>& U){
		system("cls");
		bienvenido();
		gotoxy(85,14);cout<<"A GN HOTELERA"<<endl;
    			gotoxy(75,15);cout<<"Seccion de acceso a mi cuenta de GN"<< endl;
    			gotoxy(75,15);cout<<"Seccion de busqueda de habitaciones"<< endl;
    			string ca_email,ca_contr;
    				gotoxy(65,17);cout<<"Escriba su email y contrase�a de GN ";cin>>ca_email>>ca_contr;
    				master_control(ca_email,ca_contr,ca_reservas);
    					for(int ca_w=0;ca_w<ca_reservas.size();ca_w++){
        					if((ca_reservas[ca_w].registrado.email==ca_email)&&(ca_reservas[ca_w].registrado.contr==ca_contr)){
         						gotoxy(60,20);cout<<"Su reserva es: "<<endl;
         						gotoxy(62,22);cout<<"Hotel: "<<ca_reservas[ca_w].reservado.sede<<"."<<endl;
         						gotoxy(60,23);cout<<"Habitacion: "<<ca_reservas[ca_w].reservado.habitacion<<"."<<endl;
        						gotoxy(60,24);cout<<"Tama�o: "<<ca_reservas[ca_w].reservado.tipo<<"."<<endl;
         						gotoxy(60,25);cout<<"Orientada al "<<ca_reservas[ca_w].reservado.orientacion;

        						if(ca_reservas[ca_w].reservado.orientacion=='N')cout<<"Norte."<<endl;
        							else if(ca_reservas[ca_w].reservado.orientacion=='S')cout<<"Sur."<<endl;
        								else if(ca_reservas[ca_w].reservado.orientacion=='E')cout<<"Este."<<endl;
        									else if(ca_reservas[ca_w].reservado.orientacion=='O')cout<<"Oeste."<<endl;
        									gotoxy(60,25);cout<<"Su comida reservada es: ";
       										cout<<ca_reservas[ca_w].comidas.comida<<endl;
        									gotoxy(60,26);cout<<"Su coche es: "<<endl;
        									gotoxy(60,27);cout<<"Marca: "<<ca_reservas[ca_w].reservado2.marca<<"."<<endl;
        									gotoxy(60,28);cout<<"Modelo: "<<ca_reservas[ca_w].reservado2.modelo<<"."<<endl;
        									gotoxy(60,29);cout<<"Tipo: "<<ca_reservas[ca_w].reservado2.tipo<<"."<<endl;
        									gotoxy(60,30);cout<<"Color: "<<ca_reservas[ca_w].reservado2.colores<<"."<<endl;

        							float total=0;
    								for(int ca_w=0;ca_w<ca_reservas.size();ca_w++){
				       					if((ca_reservas[ca_w].registrado.email==ca_email)&&(ca_reservas[ca_w].registrado.contr==ca_contr)){
		            					total=ca_reservas[ca_w].reservado.precio+ca_reservas[ca_w].comidas.cost+ca_reservas[ca_w].reservado2.precio_v;
        		    					gotoxy(60,31);cout<<"El precio total de su reserva es: "<<total<<" euros."<<endl;
        								}
        							}
        					}
    					}
    					system("pause");
    					supBuf();menu_principal(S,f,C,ca_reservas,U);
		}
void guardar_datos_usuario(vector<tDatos_1> &fichero,vector<tUsuario> &bigdata,vector<tReservados>& Reservas, vector<tComida>& C, vector<tVehiculo>& carros);
int main(){
	vector<tDatos_1> fichero;
	vector<tVehiculo> S;
	vector<tComida> C;
	vector<tUsuario> U;
	vector<tReservados> ca_reservas;
	leer_ficheroH (fichero);
	leer_archivo(S);
	leer_comida(C);
	pintar_portada();
	menu_principal(S,fichero,C,ca_reservas,U);

}

		void menu_inicio_habitacion_visitante(vector<tVehiculo>& S,vector<tDatos_1>& f,vector<tComida>& C,vector<tReservados>& ca_reservas,vector<tUsuario>& U){
			system("cls");
			bienvenido();
			int n,cont=0;
				gotoxy(85,14);cout<<"A GN HOTELERA"<<endl;
    			gotoxy(75,15);cout<<"Seccion de busqueda de habitaciones"<< endl;
    			gotoxy(60,20);cout<<"1. Buscar habitacion segun sede"<<endl;
    			gotoxy(60,22);cout<<"2. Buscar habitacion segun tipo"<<endl;
    			gotoxy(60,24);cout<<"3. Consultar habitaciones disponibles de los hoteles GN HOTELERA"<<endl;
    			gotoxy(60,26);cout<<"4. Salir de la seccion de busqueda de habotaciones"<<endl;
    				while(n!=3){
    					gotoxy(83,28);cout<<"Seleccione una opcion: ";
    					gotoxy(105,28);cin>>n;
    					switch (n){
    						case 1: menu_buscar_habitacion_sede(S,f,C,ca_reservas,U);break;
    						case 2: menu_buscar_habitacion_tipo(S,f,C,ca_reservas,U);break;
    						case 3: habitaciones_disponibles(S,f,C,ca_reservas,U);break;
    						case 4: menu_visitante(S,f,C,ca_reservas,U);break;
						}
					}
		}
		void servicio_comida(vector<tComida>& C,vector<tVehiculo>& S,vector<tDatos_1>& f,vector<tReservados>& ca_reservas,vector<tUsuario>& U){
			system("cls");
			bienvenido();
				gotoxy(85,14);cout<<"A GN HOTELERA"<<endl;
    			gotoxy(75,15);cout<<"Seccion de servicio de comida hotel"<< endl;
    			for(int i = 69 ; i<114; i++) {
				gotoxy(i,18);printf("%c",205);//limite arriba
				gotoxy(i,22);printf("%c",205);//limite abajo
			}
			for(int i = 19 ; i < 22; i++) {
				gotoxy(68,i);printf("%c",186);//limite izquierdo
				gotoxy(114,i);printf("%c",186);//limite derecho
			}
    				gotoxy(68,18);printf("%c",201);gotoxy(68,22);printf("%c",200);gotoxy(114,18);printf("%c",187);gotoxy(114,22);printf("%c",188);
					gotoxy(79,19);cout<< "POSIBILIDADES  DE  COMBINAR"<<endl;
					gotoxy(71,21);cout<< "DISPONIBLES                NO DISPONIBLES"<<endl<<endl<<endl;
    				gotoxy(71,21);cout<< "TIPOS DE COMIDA            PRECIOS"<<endl<<endl<<endl;
    				for(int i=0;i<C.size();i++){
    					cout<<"                                                                             "<<C[i].comida<<"         "<<C[i].cost<<endl;
					}
				gotoxy(75,26+C.size());cout<< "Pulse ENTER para volver al menu"<<endl<<endl;
				system("pause");supBuf();menu_visitante(S,f,C,ca_reservas,U);
		}
		void menu_inicio_alquiler_visitante(vector<tVehiculo>& S,vector<tDatos_1>& F,vector<tComida>& C,vector<tReservados>& ca_reservas,vector<tUsuario>& U){
		system("cls");
		bienvenido();
		int n,cont=0,tam=S.size();
			gotoxy(85,14);cout<<"A GN HOTELERA"<<endl;
    		gotoxy(76,15);cout<<"Seccion de alquiler de vehiculos"<< endl;
    		gotoxy(67,20);cout<<"1. Buscar vehiculo segun preferencias"<<endl;
    		gotoxy(67,22);cout<<"2. Consultar modelos disponibles y no disponibles"<<endl;
    		gotoxy(67,24);cout<<"3. Salir de la seccion de alquiler de vehiculos"<<endl;
    			while(n!=3){
    				gotoxy(80,26);cout<<"Seleccione una opcion: ";
    				gotoxy(102,26);cin>>n;
    				switch (n){
    					case 1: buscar_vehiculo(S,F,C,ca_reservas,U);break;
    					case 2: vehiculos_disponibles(S,F,C,ca_reservas,U);break;
    					case 3: system("cls");menu_visitante(S,F,C,ca_reservas,U);break;
					}
				}
	}
		void menu_visitante(vector<tVehiculo>& S,vector<tDatos_1>& F,vector<tComida>& C,vector<tReservados>& ca_reservas,vector<tUsuario>& U){
				system("cls");
				bienvenido();
				int num;
					gotoxy(85,14);cout<<"A GN HOTELERA"<<endl;
					while(num!=4){
						gotoxy(70,20);cout<<" 1. Ver habitaciones de GN HOTELERA";
						gotoxy(70,22);cout<<" 2. Consultar servicio de comida";//iniciar sesion con cuenta y constrase�a
						gotoxy(70,24);cout<<" 3. Consultar servicio de alquiler de coches";
						gotoxy(70,26);cout<<" 4. Salir de GN HOTELERA";
						gotoxy(79,28);cout<<"Seleccione su preferencia:";
						gotoxy(105,28);cin>>num;

						switch (num){
							case 1: menu_inicio_habitacion_visitante(S,F,C,ca_reservas,U);break;
							case 2: servicio_comida(C,S,F,ca_reservas,U);break;
							case 3: menu_inicio_alquiler_visitante(S,F,C,ca_reservas,U);break;
							case 4: menu_principal(S,F,C,ca_reservas,U);break;
						}
					}
		}
void menu_principal(vector<tVehiculo>& S,vector<tDatos_1>& f,vector<tComida>& C,vector<tReservados>& ca_reservas,vector<tUsuario>& U){
		system("cls");
		int num;
		bienvenido();
		gotoxy(85,14);cout<<"A GN HOTELERA"<<endl;
		while(num!=4){
			gotoxy(77,20);cout<<"1. Crear cuenta en GN HOTELERA";
			gotoxy(77,22);cout<<"2. Acceder a mi cuenta";//iniciar sesion con cuenta y constrase�a
			gotoxy(77,24);cout<<"3. Entrar como visitante";
			gotoxy(77,26);cout<<"4. Salir de GN HOTELERA";
			gotoxy(86,28);cout<<"Seleccione su opcion:";
			gotoxy(107,28);cin>>num;
				switch (num){
				case 1: guardar_datos_usuario(f,U,ca_reservas,C,S);break;
				case 2: mostrar_reservas(ca_reservas,S,f,C,U);break;
				case 3: menu_visitante(S,f,C,ca_reservas,U);break;
				case 4: final();supBuf();exit(1);break;
				}
		}
	}
bool corroborar_email(string ca_email)//Alberto, corrobora la extension del email para saber si es correcto
{
    bool es_correcto=true;
    for(int ca_e=0; ca_e<ca_email.size();ca_e++)
    {
        if(ca_email[ca_e]=='@')
        {
        string extension_email=ca_email.substr(ca_e+1);
        if(extension_email!="gmail.com")es_correcto=false;
        //en este punto se podria consultar con una base de datos de extensiones de correos (para ampliar la precision)
        }
    }
    return es_correcto;
}

bool corroborar_edad(int ca_dia, int ca_mes, int ca_any)//Alberto, corrobora si eres mayor de edad, pero no de manera exhaustiva
{
    bool es_correcto2=false;
    int actual_dia=8,actual_mes=1,actual_any=2020; //dia fictidio actual (entrega del proyecto)
    if(actual_any-ca_any>18)es_correcto2=true;
    else if(actual_any-ca_any==18)
    {
        if(actual_mes-ca_mes>0)es_correcto2=true;
        else if(actual_mes-ca_mes==0)
        {if(actual_dia-ca_dia>0)es_correcto2=true;}
    }
    return es_correcto2;
}

void guardar_datos_usuario(vector<tDatos_1> &fichero,vector<tUsuario> &bigdata,vector<tReservados>& Reservas, vector<tComida>& C, vector<tVehiculo>& carros) //guardar datos de usuario en un vector
{
    tUsuario ca_usuario;
    cout<<"Diga nombre y apellido: "<<endl;
    cin>>ca_usuario.nombre>>ca_usuario.apellido;
    cout<<"Diga el email con el que desea registrarse: "<<endl;
    cin>>ca_usuario.email;
    bool chequeo=corroborar_email(ca_usuario.email);
    while(chequeo!=true)
    {
    cout<<"El email no es correcto. Diga el email con el que desea registrarse: "<<endl;
    cin>>ca_usuario.email;
    bool chequeo=corroborar_email(ca_usuario.email);
    }
    if(chequeo==true)cout<<"Email correcto."<<endl;
    cout<<"Indique la contrase�a que desee: "<<endl;
    cin>>ca_usuario.contr;
    string comprobar_contra;
    cout<<"Repita su contrase�a para comprobar si es correcta: "<<endl;
    cin>>comprobar_contra;
    while(ca_usuario.contr!=comprobar_contra)
    {
        cout<<"No son iguales. Intente otra vez"<<endl;
        cin>>ca_usuario.contr;
        cout<<"Repita su contrase�a para comprobar si es correcta: "<<endl;
        cin>>comprobar_contra;
    }
    if(ca_usuario.contr==comprobar_contra)cout<<"Es correcta."<<endl;
    cout<<"Indique su fecha de nacimiento para comprobar que es mayor de edad: "<<endl;
    cin>>ca_usuario.dia_nax>>ca_usuario.mes_nax>>ca_usuario.any_nax;
    bool chequeo_edad=corroborar_edad(ca_usuario.dia_nax,ca_usuario.mes_nax,ca_usuario.any_nax);
    while(chequeo_edad !=true)
    {
        cout<<"No es mayor de edad o no ha puesto bien su edad. Intenlo otra vez: "<<endl;
        cin>>ca_usuario.dia_nax>>ca_usuario.mes_nax>>ca_usuario.any_nax;
        bool chequeo_edad=corroborar_edad(ca_usuario.dia_nax,ca_usuario.mes_nax,ca_usuario.any_nax);
    }
    if(chequeo_edad==true)cout<<"Usuario registrado con exito."<<endl;
        cout<<"Indique si prefiere filtrar por la sede del hotel o por el tipo de habitacion: "<<endl;
        cout<<"(SEDE/TIPO)"<<endl;
        string ca_filtro;
        cin>>ca_filtro;
        if(ca_filtro=="SEDE")
        {
            string ca_sede;
            cout<<"Indique en que sede desea buscar: "<<endl;
            cout<<"--SEDES--"<<endl;
            cout<<"Diagonal"<<endl<<"RamblaCat"<<endl<<"PaseoMar"<<endl<<"Forum"<<endl<<"Maquinista"<<endl;
            cin>>ca_sede;
            cout<<"Las habitaciones de esta sede son: "<<endl<<endl;
            for(int ca_i=0;ca_i<fichero.size();ca_i++)
            {
                if(fichero[ca_i].sede==ca_sede)
                {
                    cout<<"La habitacion numero: "<<fichero[ca_i].habitacion<<" ubicada en el piso "<<fichero[ca_i].piso<< " y con orientacion al ";
                    if(fichero[ca_i].orientacion=='N')cout<<"Norte";
                    else if(fichero[ca_i].orientacion=='S')cout<<"Sur";
                    else if(fichero[ca_i].orientacion=='E')cout<<"Este";
                    else if(fichero[ca_i].orientacion=='O')cout<<"Oeste";
                    cout<<" de tipo "<<fichero[ca_i].tipo<<". Estado: ";
                    if(fichero[ca_i].disponibilidad==true)cout<<"disponible.";
                    else if(fichero[ca_i].disponibilidad==false)cout<<"ocupada.";
                }
            }
        }
        else if(ca_filtro=="TIPO")
        {
            string ca_tipo;
            cout<<"Indique el tipo de habitacion que desea buscar: "<<endl;
            cout<<"--TIPOS DE HABITACION--"<<endl;
            cout<<"sencilla"<<endl<<"Doble"<<endl<<"Matrimonial"<<endl<<"SJunior"<<endl<<"SDoble"<<endl<<"SPresidencial"<<endl;
            cin>>ca_tipo;
            cout<<"Para este tipo de habitacion tenemos las siguientes: "<<endl<<endl;
            for(int ca_j=0;ca_j<fichero.size();ca_j++)
            {
                if(fichero[ca_j].tipo==ca_tipo)
                {
                    cout<<"La habitacion numero: "<<fichero[ca_j].habitacion<<" ubicada en el piso "<<fichero[ca_j].piso<< " y con orientacion al ";
                    if(fichero[ca_j].orientacion=='N')cout<<"Norte";
                    else if(fichero[ca_j].orientacion=='S')cout<<"Sur";
                    else if(fichero[ca_j].orientacion=='E')cout<<"Este";
                    else if(fichero[ca_j].orientacion=='O')cout<<"Oeste";
                    cout<<" de la sede "<<fichero[ca_j].sede<<". Estado: ";
                    if(fichero[ca_j].disponibilidad==true)cout<<"disponible.";
                    else if(fichero[ca_j].disponibilidad==false)cout<<"ocupada.";
                }
            }
        }
        cout<<"Una vez escogida la habitacion escriba SI para continuar."<<endl;
        string si;
        cin>>si;
        if(si=="SI")
        {
            int ca_habitacion;
            string ca_sede2;
            cout<<"Indique la habitacion que escogio: "<<endl;
            cin>>ca_habitacion;
            cout<<"Indique la sede en que escogio el numero de habitacion: "<<endl;
            cout<<"--SEDES--"<<endl;
            cout<<"Diagonal"<<endl<<"RamblaCat"<<endl<<"PaseoMar"<<endl<<"Forum"<<endl<<"Maquinista"<<endl;
            cin>>ca_sede2;
            for(int ca_r=0;ca_r<fichero.size();ca_r++)
            {
                if((fichero[ca_r].habitacion==ca_habitacion) && (fichero[ca_r].sede==ca_sede2) && (fichero[ca_r].disponibilidad=true))
                {
                    cout<<"La habitacion tiene un precio de: "<<fichero[ca_r].precio<<" euros por cada noche de estadia."<<endl;
                }
                else if((fichero[ca_r].habitacion==ca_habitacion) && (fichero[ca_r].sede==ca_sede2) && (fichero[ca_r].disponibilidad=false))
                {
                    cout<<"La habitacion tiene un precio de: "<<fichero[ca_r].precio<<" euros, pero esta ocupada."<<endl;
                }
            }

        }
        cout<<"Indique otra vez el numero de habitacion y la sede para confirmar la reserva: "<<endl;
        int conf_hab;
        string conf_sede;
        cout<<"--SEDES--"<<endl;
        cout<<"Diagonal"<<endl<<"RamblaCat"<<endl<<"PaseoMar"<<endl<<"Forum"<<endl<<"Maquinista"<<endl;
        cin>>conf_hab>>conf_sede;
            for(int ca_r=0;ca_r<fichero.size();ca_r++)
             {
                if((fichero[ca_r].habitacion==conf_hab) && (fichero[ca_r].sede==conf_sede))
                {
                    fichero[ca_r].disponibilidad=false;
                }
             }
        tDatos_1 ca_guardar;
        for(int ca_h=0;ca_h<fichero.size();ca_h++)
        {
            if((fichero[ca_h].habitacion==conf_hab) && (fichero[ca_h].sede==conf_sede))
            {
                ca_guardar=fichero[ca_h];
            }
        }
        cout<<"Habitacion reservada con exito. "<<endl;
        tComida ca_comida;
        cout<<"Desea reservar comida en el hotel?"<<endl;
        cout<<"SI/NO";
        string patata;
        cin>>patata;
        if(patata=="SI")
        {
            //string ca_menu;
            //float precio_menu;
            cout<<"Que menu querra para su estancia?"<<endl;
            cout<<"---MENUS---"<<endl;
            cout<<"Desayuno: 5euros."<<endl;
            cout<<"Comida: 10euros."<<endl;
            cout<<"Cena: 15euros."<<endl;
            cout<<"Menu_Medio: 17euros."<<endl;
            cout<<"Menu_Completo: 20euros."<<endl;
            cin>>ca_comida.comida;
            for(int ca_f=0; ca_f<C.size();ca_f++)
            {
                if(C[ca_f].comida==ca_comida.comida)ca_comida.cost=C[ca_f].cost;
            }
            cout<<"Reserva del menu completado."<<endl;
            cout<<"Seguiremos con la reserva del vehiculo. "<<endl;
        }
        else if(patata=="NO")
        {
            ca_comida.comida="Menu no reservado";
            ca_comida.cost=0.0;
            cout<<"Seguiremos con la reserva del vehiculo. "<<endl; //encadenar con subprograma de coche (KEVIN)
        }
        tVehiculo carrito;
        cout<<"Desea reservar un vehiculo?"<<endl;
        cout<<"SI/NO";
        string tocino;
        cin>>tocino;
        if(tocino=="SI")
        {
            cout<<"Los modelos disponibles son los siguientes: "<<endl<<endl;
            for(int i=0;i<carros.size();i++)
            {
                if(carros[i].disponible==true)
                {
                    cout<<carros[i].marca<<" "<<carros[i].modelo<<endl;
                }
            }
            cout<<endl;
            cout<<"Una vez escogido el modelo, indique la marca y modelo que le interesa: "<<endl;
            cin>>carrito.marca>>carrito.modelo;
            for(int ca_r=0; ca_r<carros.size();ca_r++)
            {
                if((carros[ca_r].marca==carrito.marca)&&(carros[ca_r].modelo==carrito.modelo))
                {
                    carrito=carros[ca_r];
                }
            }
            cout<<"Reserva del vehiculo completado."<<endl;
            cout<<"Cuenta creada con su reserva. "<<endl;
        }
        else if(tocino=="NO")
        {
            carrito.marca="No reservado";
            carrito.modelo="No reservado";
            carrito.tipo="No reservado";
            carrito.transmision="No reservado";
            carrito.combustible="No reservado";
            carrito.colores="No reservado";
            carrito.precio_v=0.0;
            cout<<"Cuenta creada con su reserva. "<<endl;
        }
        cout<<"Precio total de su reserva: "<<endl;
        float total_apagar=ca_guardar.precio+ca_comida.cost+carrito.precio_v;
        cout<<total_apagar<<" euros."<<endl;
        cout<<"Desea aceptar el pago?"<<endl;
        cout<<"SI/NO"<<endl;
        string var_pago;
        cin>>var_pago;
        tReservados ca_osito;
        if(var_pago=="SI")
        {
             //Alberto reserva puesta en un vector
            ca_osito.registrado=ca_usuario;
            ca_osito.reservado=ca_guardar;
            ca_osito.comidas=ca_comida;
            ca_osito.reservado2=carrito;//variable de vehiculo
            Reservas.push_back(ca_osito);
            cout<<"Gracias por su reserva."<<endl;
        }
        else if(var_pago=="NO")
        {
            ca_osito.registrado=ca_usuario;
            ca_osito.reservado={0,0,'0',0,"no reservado","no reservado",0};
            ca_osito.comidas={"no reservado",0.0};
            ca_osito.reservado2={"no reservado","no reservado","no reservado","no reservado","no reservado","no reservado",0.0,0};
            Reservas.push_back(ca_osito);
            cout<<"Gracias por su visita."<<endl;
        }
    cout<< "Pulse ENTER para volver al menu"<<endl<<endl;
    system("pause");supBuf();menu_principal(carros,fichero,C,Reservas,bigdata);
}
void buscar_vehiculo(vector<tVehiculo>& S,vector<tDatos_1>& F,vector<tComida>& C,vector<tReservados>& ca_reservas,vector<tUsuario>& U)
{
    cout<<"Indique el patron de busqueda que desea usar para su vehiculo: "<<endl;
    cout<<"--PATRONES DE BUSQUEDA--"<<endl<<endl;
    cout<<"Marca"<<endl;
    cout<<"Modelo"<<endl;
    cout<<"Tipo"<<endl;
    cout<<"Transmision"<<endl;
    cout<<"Combustible"<<endl;
    cout<<"Color"<<endl<<endl;

    string ternera,dragon;
    cin>>ternera;

    if(ternera=="Marca")
    {
        cout<<"Indique la marca que desee: "<<endl<<endl;
        cin>>dragon;
        for(int ca_b=0;ca_b<S.size();ca_b++)
        {
            if((S[ca_b].marca==dragon) && (S[ca_b].disponible=true))
            {
                cout<<S[ca_b].marca<<" ";
                cout<<S[ca_b].modelo<<" ";
                cout<<S[ca_b].tipo<<" ";
                cout<<S[ca_b].transmision<<" ";
                cout<<S[ca_b].combustible<<" ";
                cout<<S[ca_b].colores<<" ";
                cout<<S[ca_b].precio_v<<" "<<endl;
            }
            //else if(dragon!="Audi" || dragon!="Volvo"....)//aqui se agregarian todos lo que incluye la lista del fichero para mejorar el error por escritura.
        }
        cout<<"Pulse ENTER para volver. "<<endl;
    }
    else if(ternera=="Modelo")
    {
        cout<<"Indique el modelo que desee: "<<endl<<endl;
        cin>>dragon;
        for(int ca_b=0;ca_b<S.size();ca_b++)
        {
            if((S[ca_b].modelo==dragon) && (S[ca_b].disponible=true))
            {
                cout<<S[ca_b].marca<<" ";
                cout<<S[ca_b].modelo<<" ";
                cout<<S[ca_b].tipo<<" ";
                cout<<S[ca_b].transmision<<" ";
                cout<<S[ca_b].combustible<<" ";
                cout<<S[ca_b].colores<<" ";
                cout<<S[ca_b].precio_v<<" "<<endl;
            }
        }
        cout<<"Pulse ENTER para volver. "<<endl;
    }
    else if(ternera=="Tipo")
    {
        cout<<"Indique el tipo de coche que desee: "<<endl<<endl;
        cin>>dragon;
        for(int ca_b=0;ca_b<S.size();ca_b++)
        {
            if((S[ca_b].tipo==dragon) && (S[ca_b].disponible=true))
            {
                cout<<S[ca_b].marca<<" ";
                cout<<S[ca_b].modelo<<" ";
                cout<<S[ca_b].tipo<<" ";
                cout<<S[ca_b].transmision<<" ";
                cout<<S[ca_b].combustible<<" ";
                cout<<S[ca_b].colores<<" ";
                cout<<S[ca_b].precio_v<<" "<<endl;
            }
        }
        cout<<"Pulse ENTER para volver. "<<endl;
    }
    else if(ternera=="Color")
    {
        cout<<"Indique el color de coche que desee: "<<endl<<endl;
        cin>>dragon;
        for(int ca_b=0;ca_b<S.size();ca_b++)
        {
            if((S[ca_b].colores==dragon) && (S[ca_b].disponible=true))
            {
                cout<<S[ca_b].marca<<" ";
                cout<<S[ca_b].modelo<<" ";
                cout<<S[ca_b].tipo<<" ";
                cout<<S[ca_b].transmision<<" ";
                cout<<S[ca_b].combustible<<" ";
                cout<<S[ca_b].colores<<" ";
                cout<<S[ca_b].precio_v<<" "<<endl;
            }
        }
        cout<<"Pulse ENTER para volver. "<<endl;
    }
    else if(ternera=="Transmision")
    {
        cout<<"Indique el tipo de transmision que desee: "<<endl<<endl;
        cin>>dragon;
        for(int ca_b=0;ca_b<S.size();ca_b++)
        {
            if((S[ca_b].transmision==dragon) && (S[ca_b].disponible=true))
            {
                cout<<S[ca_b].marca<<" ";
                cout<<S[ca_b].modelo<<" ";
                cout<<S[ca_b].tipo<<" ";
                cout<<S[ca_b].transmision<<" ";
                cout<<S[ca_b].combustible<<" ";
                cout<<S[ca_b].colores<<" ";
                cout<<S[ca_b].precio_v<<" "<<endl;
            }
        }
        cout<<"Pulse ENTER para volver. "<<endl;
    }
    else if(ternera=="Combustible")
    {
        cout<<"Indique el tipo de combustible que use el vehiculo que desee: "<<endl<<endl;
        cin>>dragon;
        for(int ca_b=0;ca_b<S.size();ca_b++)
        {
            if((S[ca_b].combustible==dragon) && (S[ca_b].disponible=true))
            {
                cout<<S[ca_b].marca<<" ";
                cout<<S[ca_b].modelo<<" ";
                cout<<S[ca_b].tipo<<" ";
                cout<<S[ca_b].transmision<<" ";
                cout<<S[ca_b].combustible<<" ";
                cout<<S[ca_b].colores<<" ";
                cout<<S[ca_b].precio_v<<" "<<endl;
            }
        }
        cout<<"Pulse ENTER para volver. "<<endl;
    }

    else if(ternera!="Marca" || ternera!="Modelo"|| ternera!="Tipo"|| ternera!="Transmision"|| ternera!="Combustible"|| ternera!="Color")
    {
        cout<<"Ese filtro no esta disponible"<<endl;
        cout<<"Pulse ENTER para volver al menu. "<<endl;
    }

system("pause");supBuf();menu_inicio_alquiler_visitante(S,F,C,ca_reservas,U);
}
