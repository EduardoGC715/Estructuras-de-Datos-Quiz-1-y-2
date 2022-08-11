#include <iostream>
#include <algorithm>
using namespace std;
//Variables
int train_1[30]={0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0};
int train_2[25]={1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0};
int train_3[5]={0,0,0,0,0};
//Functions
void available_seats(int train[],int size) {
    /*
     Funcion que devuelve una lista con los asientos disponibles del tren.
     Parametros: int train[]: arreglo de tipo entero; int size: tamaño del arreglo.
     Retorna: void.
     */
    int count_aux=0;
    int count_seats;
    bool found= false;
    int av_seats[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    //first 10
    for (count_seats=0;count_seats<size;count_seats++){
        if (train[count_seats]==0){
            av_seats[count_aux]=count_seats+1;
            count_aux++;
        }
        if (count_aux==10){
            break;
        }
    }
    //last 10
    count_aux=10;
    for (count_seats=size;count_seats>0;count_seats--){
        if (train[count_seats-1]==0){
            count_aux--;
            for(int pointer = 0; pointer < 20; pointer++){
                if(av_seats[pointer] == count_seats){
                    found= true;
                    break;
                }
            }
            if (!found){
                av_seats[count_aux+10]=count_seats;
            }
        }
        if (count_aux==0){
            break;
        }
    }
    //print array of all available seats
    for (int count_aux=0;count_aux<20;count_aux++){
        if (av_seats[count_aux]!=0){
            cout<<"Asiento numero "<<av_seats[count_aux]<<" disponible."<<"\n";
        }
    }
    cout<<"DONE!\n";
}
//Main
int main() {
    available_seats(train_1, sizeof(train_1)/4);
    available_seats(train_2, sizeof(train_2)/4);
    available_seats(train_3, sizeof(train_3)/4);
    return 0;
}