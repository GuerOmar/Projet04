#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>
#include <set>
#include "partie.h"

Partie::Partie(string s){
    if (s=="difficile"){
        nb_col=30 ;
        nb_li=16;
        nb_bomb=99 ;
    }
    if(s=="normal"){
        nb_col=16 ;
        nb_li=16 ;
        nb_bomb=40 ;
    }
    if(s=="facile"){
        nb_col=9 ;
        nb_li=9;
        nb_bomb= 10 ;
    }
}
Partie::~Partie() {}
ostream & operator<<(ostream &out , const Partie p){
    out << "   " ;
    for(int i=0;i<p.nb_col;i++){
        out  << i <<" ";
        if (i<10) out << " " ;
    }
    out << "\n" ;
    for(int i=0;i<p.nb_li;i++){
        out <<i<< " " ;
        if (i<10) out << " " ;

        for(int j=0;j<p.nb_col;j++){
            out << p.grille[i][j]<<"  " ;
        }
        out << "\n" ;
    }
    return out ;
}
void Partie::calculValeur(){
     for(int i=0;i<nb_li;i++){
        for(int j=0;j<nb_col;j++){
            if (grille[i][j].getValue()==-1){
                for(int k=i-1;k<i+2;k++){
                    for(int h=j-1;h<j+2;h++){
                        if((k>=0) && (h>=0) && (k<nb_li) && (h<nb_col) && !((k==i) and (h== j))) {
                            if (grille[k][h].getValue()!=-1) {
                                    grille[k][h].setValue(grille[k][h].getValue() +1 ) ;
                            }
                        }
                    }
                }
            }
        }
    }
}
void Partie::afficherBomb(){
       for(int i=0;i<nb_li;i++){
        for(int j=0;j<nb_col;j++){
            if (grille[i][j].getValue()==-1) grille[i][j].setShown() ;
        }
   }
}
void Partie::placerMine(int x,int y){
    int a,b,Ent;
    bool test;
    srand(time(NULL)) ;
    Ent= 2 + rand() % 3;
    vector <int> vecX;
    vector <int> vecY;
    for (int i=0; i<Ent+1; i++)
    {
        vecX.push_back(x+i);
        vecX.push_back(x-i);
        vecY.push_back(y+i);
        vecY.push_back(y-i);
        cout << x+i <<" "<< y+i <<endl ;
    }

    for(int i=0;i<nb_bomb;i++){

        do {
        test = true ;
        a=rand()%nb_li ;
        b=rand()%nb_col ;
        if (find(vecX.begin(), vecX.end(), a) != vecX.end() && find(vecY.begin(), vecY.end(), b) != vecY.end())
            test=false;}
        while (test==false)   ;
        grille[a][b].setValue(-1) ;
    }
}
void Partie::afficherZeros(int x, int y){
    if (grille[x][y].getValue()==0){
        grille[x][y].setShown();
        for (int i=x-1;i<x+2;i++){
            for (int j=y-1;j<y+2;j++){
            if((i>=0) &&(j>=0) &&(i<nb_li) &&(j<nb_col) &&!((i==x)&&(j==y)) && grille[i][j].getEtat()!='s') afficherZeros(i,j);
            }
        }
    }
    else {
        grille[x][y].setShown() ;
    }
}
bool Partie::selectAction(int i ,int x,int y){
    if (i==0){
        if (grille[x][y].getValue()==-1 && grille[x][y].getEtat()!='f') {afficherBomb() ; return false ;}
        if (grille[x][y].getValue()==0) afficherZeros(x,y) ;
        if (grille[x][y].getEtat()!='f') grille[x][y].setShown() ;
        for(int i=0;i<nb_li;i++){
            for(int j=0;j<nb_col;j++){
                if (grille[i][j].getValue()!=-1 && grille[i][j].getEtat()!='s') return true ;
            }
       }
        return false ;
    }
    if(i==1){
        if (grille[x][y].getEtat()=='s') return true ;
        grille[x][y].setFlag() ;
        nb_bomb-=1 ;
        return true ;
    }
    if(i==2){
        if (grille[x][y].getEtat()=='f') grille[x][y].setHidden() ;
        return true ;
    }
}
bool Partie::resultatPartie(){
    for(int i=0;i<nb_li;i++){
        for(int j=0;j<nb_col;j++){
            if (grille[i][j].getValue()==-1 && grille[i][j].getEtat()=='s') return false  ;
            if (grille[i][j].getValue()!=-1 && grille[i][j].getEtat()=='h') return false ;
        }
   }
   return true ;
}

