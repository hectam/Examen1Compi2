#include "ast.h"
#include <map>
#include <iostream>


#include "ast.h"

int NumExpr::evaluate(){
    printf("Number: %f ", this->number );
    return this->number;
}

int AddExpr::evaluate(){
    return this->expr1->evaluate() + this->expr2->evaluate();
}
int SubExpr::evaluate(){
    return this->expr1->evaluate() - this->expr2->evaluate();
}
int MulExpr::evaluate(){
    return this->expr1->evaluate() * this->expr2->evaluate();
}
int DivExpr::evaluate(){
    return this->expr1->evaluate() / this->expr2->evaluate();
}