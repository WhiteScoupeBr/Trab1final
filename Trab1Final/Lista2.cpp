#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Lista2.h"

using namespace std;

Lista2::Lista2(){
    primeiro = NULL;
    atual = NULL;
    aux = NULL;
}


void Lista2::AdicionaNode(long int addData, char* addNome){

    nodePnt n = new node;
    n->prox=NULL;
    n->rg = addData;
    strcpy(n->nome,addNome);

    if (primeiro != NULL){
        atual = primeiro;
        while(atual->prox != NULL){
            atual = atual->prox;
        }
        atual->prox = n;
    }
    else{
        primeiro = n;
    }

}
void Lista2::AdicionaNodeFim(long int addData, char* addNome){

    std::clock_t start;
    double duration;
    int c=0;
    int m=0;
    start = std::clock();
    nodePnt n = new node;
    n->prox=NULL;
    n->rg = addData;
    strcpy(n->nome,addNome);
    atual = primeiro;
    while(atual->prox != NULL){
        c++;
        atual = atual->prox;m++;
    }
        atual->prox = n;
         duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
        cout<<"Tempo enc:"<< duration <<'\n';
        cout<<"M enc("<<m<<")"<<endl;
        cout<<"C enc("<<c<<")"<<endl;

}

void Lista2::DeletaNode(int delData){
    std::clock_t start;
    double duration;
    int c=0;
    int m=0;
    start = std::clock();
    nodePnt delPont = NULL;m++;
    aux = primeiro;m++;
    atual = primeiro;m++;
    while(atual != NULL && atual->rg !=delData){
        c++;
        aux = atual;m++;
        atual = atual->prox;m++;
    }
    if(atual==NULL){
        c++;
        cout << delData << "Não estava na lista\n";
        delete delPont;
    }
    else{
        delPont = atual;m++;
        atual = atual->prox;m++;
        aux->prox=atual;m++;
        if(delPont==primeiro){
            c++;
            primeiro = primeiro->prox;m++;
            atual = NULL;m++;
        }
        delete delPont;
        cout << delData << " Foi deletado\n";
    }
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
        cout<<"Tempo enc:"<< duration <<'\n';
        cout<<"M enc("<<m<<")"<<endl;
        cout<<"C enc("<<c<<")"<<endl;
}

void Lista2::DeletaNodePrimeiro(){
    std::clock_t start;
    double duration;
    start = std::clock();
    int c=0;
    int m=0;
    nodePnt delPont = NULL;m++;
    aux = primeiro;m++;
    atual = primeiro;m++;
    delPont = atual;m++;
    atual = atual->prox;m++;
    aux->prox=atual;m++;
    primeiro = primeiro->prox;m++;
    atual = NULL;m++;
    delete delPont;m++;
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
        cout<<"Tempo enc:"<< duration <<'\n';
        cout<<"M enc("<<m<<")"<<endl;
        cout<<"C enc("<<c<<")"<<endl;
    }

void Lista2::DeletaNodeUltimo(){
    std::clock_t start;
    double duration;
    int c=0;
    int m=0;
    start = std::clock();

    nodePnt delPont = NULL;m++;
    aux = primeiro;m++;
    atual = primeiro;m++;
    atual = atual->prox;m++;
    atual = atual->prox;m++;
    while(atual != NULL){
        c++;
        aux = aux->prox;
        atual = atual->prox;
    }
        delPont = aux;m++;
        atual = NULL;m++;
        aux->prox=atual;m++;
        delete delPont;
        duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
        cout<<"Tempo enc:"<< duration <<'\n';
        cout<<"M enc("<<m<<")"<<endl;
        cout<<"C enc("<<c<<")"<<endl;
}
void Lista2::DeletaNodeN(int num){
    std::clock_t start;
    double duration;
    int c=0;
    int m=0;
    start = std::clock();
    nodePnt delPont = NULL;
    if(num==1){
        c++;
        nodePnt delPont = NULL;m++;
        aux = primeiro;m++;
        atual = primeiro;m++;
        delPont = atual;m++;
        atual = atual->prox;m++;
        aux->prox=atual;m++;
        primeiro = primeiro->prox;m++;
        atual = NULL;m++;
        delete delPont;
    }
    else{
        c++;
        aux=primeiro;m++;
        atual=primeiro;m++;
        for(int i=1;i<num;i++){
            c++;
            aux=atual;m++;
            atual=atual->prox;m++;
        }

        delPont = aux;m++;
        atual = atual->prox;m++;
        aux->prox=atual;m++;
        delete delPont;
    }
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
        cout<<"Tempo enc:"<< duration <<'\n';
        cout<<"M enc("<<m<<")"<<endl;
        cout<<"C enc("<<c<<")"<<endl;
}

void Lista2::AdicionaNodeInicio(long int addData,char*addNome){
    std::clock_t start;
    double duration;
    int c=0;
    int m=0;
    start = std::clock();
    nodePnt n = new node;
    n->prox=NULL;m++;
    n->rg = addData;m++;
    strcpy(n->nome,addNome);m++;

    n->prox=primeiro;m++;
    primeiro=n;m++;
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
        cout<<"Tempo enc:"<< duration <<'\n';
        cout<<"M enc("<<m<<")"<<endl;
        cout<<"C enc("<<c<<")"<<endl;
}

void Lista2::AdicionaNodeN(long int addData, char* addNome,int num){
    std::clock_t start;
    double duration;
    int c=0;
    int m=0;
    start = std::clock();
    nodePnt n = new node;
    n->prox=NULL;m++;
    n->rg = addData;m++;
    strcpy(n->nome,addNome);m++;
    if(num==1){
        c++;
        n->prox=primeiro;m++;
        primeiro=n;m++;

    }
    else{
        c++;
        atual=primeiro;m++;
        for(int i=1;i<num-1;i++){
            atual=atual->prox;m++;
            c++;
        }
        n->prox=atual->prox;m++;
        atual->prox=n;m++;
    }
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
        cout<<"Tempo enc:"<< duration <<'\n';
        cout<<"M enc("<<m<<")"<<endl;
        cout<<"C enc("<<c<<")"<<endl;
}

void Lista2::ImprimeLista(){
    atual = primeiro;
    while(atual != NULL){
        cout <<  atual->nome << ", "  <<atual->rg<<endl;
        atual= atual->prox;
    }

}

void Lista2::CleanNode(){
     std::clock_t start;
    double duration;
    int c=0;
    int m=0;
    start = std::clock();

    nodePnt delPont = NULL;m++;
    atual = primeiro;m++;
    while(atual!=NULL){
        c++;
        delPont=atual;m++;
        atual=atual->prox;m++;
        delete delPont;
    }
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
        cout<<"Tempo enc:"<< duration <<'\n';
        cout<<"M enc("<<m<<")"<<endl;
        cout<<"C enc("<<c<<")"<<endl;
}
void Lista2::ProcuraNo(long int rg1){
        std::clock_t start;
        double duration;
        int c=0;
        int m=0;
        start = std::clock();
        atual = primeiro;m++;
        aux=primeiro;m++;
        while(rg1!=atual->rg||atual==NULL){
            c++;
            aux=atual;m++;
            atual=atual->prox;m++;
        }
        cout<<"Encadeada: "<<atual->nome<<endl;
        duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
        cout<<"Tempo enc:"<< duration <<'\n';
        cout<<"M enc("<<m<<")"<<endl;
        cout<<"C enc("<<c<<")"<<endl;

}
