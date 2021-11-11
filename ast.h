#ifndef _AST_H_
#define _AST_H_

#include <list>
#include <string>

using namespace std;


class Expr;
class InitDeclarator;
class Declaration;
class Parameter;
class Statement;
typedef list<Expr *> InitializerElementList;
typedef list<InitDeclarator *> InitDeclaratorList;
typedef list<Declaration *> DeclarationList;
typedef list<Parameter *> ParameterList;
typedef list<Statement *> StatementList;

enum StatementKind{
    WHILE_STATEMENT,
};

enum Type{
    INVALID,
    FLOAT,
    BOOL
};

class Expr {
    public:
        virtual int evaluate() = 0;
};


class BinaryExpr: public Expr {
    public:
        BinaryExpr(Expr * expr1, Expr * expr2){
            this->expr1 = expr1;
            this->expr2 = expr2;
        }
        Expr * expr1;
        Expr * expr2;
};

class AddExpr: public BinaryExpr{
    public:
        AddExpr(Expr * expr1, Expr * expr2): BinaryExpr(expr1, expr2){}
        int evaluate();
};

class SubExpr: public BinaryExpr{
    public:
        SubExpr(Expr * expr1, Expr * expr2): BinaryExpr(expr1, expr2){}
        int evaluate();
};

class MulExpr: public BinaryExpr{
    public:
        MulExpr(Expr * expr1, Expr * expr2): BinaryExpr(expr1, expr2){}
        int evaluate();
};

class DivExpr: public BinaryExpr{
    public:
        DivExpr(Expr * expr1, Expr * expr2): BinaryExpr(expr1, expr2){}
        int evaluate();
};

class NumExpr: public Expr{
    public:
        NumExpr(float number){
            this->number = number;
        }
        float number;
        int evaluate();
};


#endif