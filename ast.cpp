#include "ast.h"
#include <map>
#include <iostream>


#include "ast.h"

int NumExpr::evaluate(){
    
    return this->number;
}
int AddExpr::evaluate(){
    float n1=this->expr1->evaluate();
    float n2=this->expr2->evaluate();
    float result = this->expr1->evaluate() + this->expr2->evaluate();
    printf("Suma realizada con %f y %f \n, el resultado es: %f \n\n",n1,n2, result);
    return this->expr1->evaluate() + this->expr2->evaluate();
}
int SubExpr::evaluate(){
     float n1=this->expr1->evaluate();
    float n2=this->expr2->evaluate();
    float result = this->expr1->evaluate() - this->expr2->evaluate();
    printf("Resta realizada con %f y %f \n, el resultado es: %f \n\n",n1,n2, result);
    return this->expr1->evaluate() - this->expr2->evaluate();
}
int MulExpr::evaluate(){
     float n1=this->expr1->evaluate();
    float n2=this->expr2->evaluate();
    float result = this->expr1->evaluate() * this->expr2->evaluate();
    printf("Multiplicacion realizada con %f y %f \n, el resultado es: %f \n\n",n1,n2, result);
    return this->expr1->evaluate() * this->expr2->evaluate();
}
int DivExpr::evaluate(){
     float n1=this->expr1->evaluate();
    float n2=this->expr2->evaluate();
    float result = this->expr1->evaluate() / this->expr2->evaluate();
    printf("Division realizada con %f y %f \n, el resultado es: %f \n\n",n1,n2, result);
    return this->expr1->evaluate() / this->expr2->evaluate();
}
int PRelationExpr::evaluate(){
    
    float result = this->expr1->evaluate() < this->expr2->evaluate();
    printf("Comparativa: %f", result);
    return this->expr1->evaluate() < this->expr2->evaluate();
}
int MRelationExpr::evaluate(){
    float result = this->expr1->evaluate() > this->expr2->evaluate();
    printf("Comparativa: %f", result);
    return this->expr1->evaluate() > this->expr2->evaluate();
}