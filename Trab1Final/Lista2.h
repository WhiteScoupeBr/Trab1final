#include <iostream>
#include <cstring>
#ifndef LISTA2_H
#define LISTA2_H
#include <ctime>
#include <cstdio>


using namespace std;

class Lista2{
private:

    typedef struct node{
        long int rg;
        char nome[20];
        node* prox;
    }* nodePnt;

    nodePnt primeiro;
    nodePnt atual;
    nodePnt aux;

public:
    Lista2();//construtora
    void CleanNode();
    void AdicionaNode(long int addData, char* addNome);
    void DeletaNode(int delData);
    void AdicionaNodeInicio(long int addData,char*addNome);
    void ImprimeLista();
    void AdicionaNodeN(long int addData, char* addNome,int num);
    void DeletaNodePrimeiro();
    void DeletaNodeUltimo();
    void DeletaNodeN(int num);
    void ProcuraNo(long int rg1);
    void AdicionaNodeFim(long int addData,char*addNome);

};


#endif // LISTA_H

