#ifndef CASE_H_INCLUDED
#define CASE_H_INCLUDED
#include <iostream>
using namespace std ;
#include <iostream>
class Case {
private:
    char etat ;
    int valeur ;
public:
    Case();
    Case(int,char) ;
    ~Case() ;
    void setShown();
    void setHidden();
    void setFlag() ;
    int getValue() const  ;
    void setValue(int) ;
    char getEtat() const ;
    friend ostream & operator<<(ostream & , const Case ) ;



};


#endif // CASE_H_INCLUDED
