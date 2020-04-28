#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include "case.h"
#include "partie.h"
using namespace std;
void menu() ;
void jouer() ;
int main()
{
    menu() ;
    return 0;
}
void menu(){
    cout <<"1-jouer" << endl ;
    cout << "2-score" << endl ;
    cout << "3-quitter" << endl ;
    int n ;
    cin >> n ;
    switch (n){
    case 1:
        system("cls") ;
        jouer() ;
        break ;

    case 3:
        system("cls");
    }
}
void jouer(){
    cout << "donner votre nom et prenom :" ;
    string nom,prenom ;
    cin >> nom >> prenom ;
    system("cls") ;
    cout << "choisir la difficulte : "<< endl ;
    cout << "1-difficile" <<endl ;
    cout << "2-normal"<< endl ;
    cout << "3-facile" << endl ;
    int n ;
    cin >> n ;
    string ch ;
    switch (n){
    case 1:
        ch="difficile" ;
        break ;
    case 2:
        ch="normal" ;
        break ;
    case 3:
        ch="facile" ;
        break ;
    }
    Partie p(ch) ;


    int h ,q;
    system("cls") ;
    cout << p ;

    cout << "donner les coordonnes de la case : ";
    cin >> h >> q ;
    p.placerMine(h,q) ;
    p.calculValeur() ;
    p.selectAction(0,h,q) ;


    do{
        system("cls") ;
        cout << p ;

        cout << "donner les coordonnes de la case : ";
        cin >> h >> q ;
        cout << "choisir votre action :\n 1-liberer une case 2-marquer une mine 3-demarquer une mine 4-quitter partie" << endl ;
        cin >> n ;
        if(n==4) break ;

    }while(p.selectAction(n-1,h,q)) ;
    system("cls") ;
    cout << p ;
    if (p.resultatPartie()){cout << "\n \n Bien joue !!";}
    else {cout <<"\n\nGame Over" ;}
    cout << "\n\n 1-rejouer 2-retourner vers menu\n" ;
    cin >> n ;
    switch (n){
    case 1:
        system("cls") ;
        jouer() ;
        break ;
    case 2:
        system("cls") ;
        menu();
    }




}
