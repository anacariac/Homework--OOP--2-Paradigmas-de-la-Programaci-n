#include "ej1.hpp"
#include <iostream>
#include <iomanip>

void testTime(){
    size_t h,m,s;
    string M;
    bool flag;
    int op;

    do{
        cout<<"\nOpciones:\n1.Inicializar por default\n2.Inicializar ingresando solamente la hora\n3.Inicializar con hora y minuros\n4.Inicializar con hora, minutos y segundos\n5.Incializar todo\n6.Salir del programa\nSeleccione una opción"<<endl;
        cin>> op;
        flag = true;
        
        try{
            TIME time;
            switch(op){
                case 1: 
                    time = TIME();
                    break;
                case 2:
                    cout<<"Ingrese la hora (1-12):"<<endl;
                    cin>>h;
                    time = TIME(h);
                    break;
                case 3:
                    cout<<"Ingrese la hora (1-12):"<<endl;
                    cin>>h;
                    cout<<"Ingrese los minutos (0-59):"<<endl;
                    cin>>m;
                    time = TIME(h,m);
                    break;
                case 4:
                    cout<<"Ingrese la hora (1-12):"<<endl;
                    cin>>h;
                    cout<<"Ingrese los minutos (0-59):"<<endl;
                    cin>>m;
                    cout<<"Ingrese los segundos (0-59):"<<endl;
                    cin>>s;
                    time = TIME(h,m,s);
                    break;
                case 5 :
                    cout<<"Ingrese la hora (1-12):"<<endl;
                    cin>>h;
                    cout<<"Ingrese los minutos (0-59):"<<endl;
                    cin>>m;
                    cout<<"Ingrese los segundos (0-59):"<<endl;
                    cin>>s;
                    cout<<"Ingrese 'a.m' o 'p.m':"<<endl;
                    cin>>M;
                    time = TIME(h,m,s,M);
                    break;
                case 6:
                    cout<<"Saliendo del programa"<<endl;
                    return;
                default:
                    cout<<"Opción inválida. Volver a intentar"<<endl;
                    flag = false;
            }
            if(1<=op && op<=5 && flag){
                cout<<"Hora inicializada correctamente"<<endl;
                cout<<"Horario en formato 12h: "<< setw(2) << setfill('0') << time.getHour() <<':'<< setw(2) << setfill('0') << time.getMinute() <<':'<< setw(2) << setfill('0') << time.getSeconds()<<' '<< time.getMeridian()<<endl;
                cout<<"Horario en formato 24h: ";
                time.printTime();
            }
        }catch(const invalid_argument& e){
            cout<<"Error"<<e.what()<<"Intente nuevamente"<<endl;
            flag = false;
        }
    }while(op!=6);

}

void TIME::validation(size_t h, size_t m, size_t s, string am_pm){
    if(h<1 || h>12) throw invalid_argument(": Hora fuera de rango."); //La hora 00 son las 12 a.m/p.m
    if(m > 60) throw invalid_argument(": Minutos fuera de rango.");
    if(s > 60) throw invalid_argument(": Segundos fuera de rango.");
    if(am_pm != "a.m" && am_pm != "p.m") throw invalid_argument(": Formato invalido (debe usar 'a.m' o 'p.m').");
}

TIME::TIME(): hour(0), minute(0), seconds(0), am_pm("a.m") {}

TIME::TIME(size_t h){
    validation(h);
    hour =h;
    minute = 0;
    seconds = 0; 
    am_pm = "a.m";
}

TIME::TIME(size_t h, size_t m){
    validation(h,m);
    hour = h;
    minute = m;
    seconds =0;
    am_pm = "a.m";
}

TIME::TIME(size_t h,size_t m,size_t s){
    validation(h,m,s);
    hour = h;
    minute = m;
    seconds = s;
    am_pm = "a.m";
}

TIME::TIME(size_t h,size_t m,size_t s, string M): hour(h), minute(m), seconds(s), am_pm(M){
    validation(h,m,s,M);
    hour = h;
    minute = m;
    seconds = s;
    am_pm = M;
}

void TIME::setHour(size_t h){
    validation(h, minute, seconds, am_pm);
    hour = h;
}

void TIME::setMinute(size_t m){
    validation(hour, m, seconds, am_pm);
    minute = m;
}

void TIME::setSeconds(size_t s){
    validation(hour, minute, s, am_pm);
    seconds = s;
}

void TIME::setMeridian(string& M){
    validation(hour, minute, seconds, M);
    am_pm = M;
}

size_t TIME::getHour() {return hour;}

size_t TIME::getMinute() {return minute;}

size_t TIME::getSeconds() {return seconds;}

string TIME::getMeridian() {return am_pm;}

void TIME::printTime(){
    size_t h = hour;
    if(am_pm == "a.m"&& hour == 12) h = 0;
    if(am_pm == "p.m"&& hour != 12) h += 12;

    cout<< setw(2) << setfill('0') << h <<':'<< setw(2) << setfill('0') << minute <<':'<< setw(2) << setfill('0') << seconds <<endl;
}

int main(){
    testTime();
    return 0;

}