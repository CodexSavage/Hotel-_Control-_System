#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

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
void leer_archivo(vector<tVehiculo>& S){//Kevin,leer fichero coches
		char texto[200];
		tVehiculo C;
		ifstream fin("coches_final01.txt");
		fin.getline(texto,200);
		while(fin>>C.marca>>C.modelo>>C.tipo>>C.transmision>>C.combustible>>C.colores>>C.precio_v>>C.disponible){
			S.push_back(C);
		}
	}

//buscar_vehiculo(vector<tVehiculo>& S,vector<tDatos_1>& F,vector<tComida>& C,vector<tReservados>& ca_reservas,vector<tUsuario>& U)
buscar_vehiculo(vector<tVehiculo>& S)
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
        cout<<"Presione ENTER para volver. "<<endl;
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
        cout<<"Presione ENTER para volver. "<<endl;
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
        cout<<"Presione ENTER para volver. "<<endl;
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
        cout<<"Presione ENTER para volver. "<<endl;
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
        cout<<"Presione ENTER para volver. "<<endl;
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
        cout<<"Presione ENTER para volver. "<<endl;
    }

    else if(ternera!="Marca" || ternera!="Modelo"|| ternera!="Tipo"|| ternera!="Transmision"|| ternera!="Combustible"|| ternera!="Color")
    {
        cout<<"Ese filtro no esta disponible"<<endl;
        cout<<"Presione ENTER para volver. "<<endl;
    }


}

int main()
{
    vector<tVehiculo> S;
    leer_archivo(S);
    buscar_vehiculo(S);

}
