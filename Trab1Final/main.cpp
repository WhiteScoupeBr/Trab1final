#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Lista2.h"

using namespace std;

struct Listaseq{
    long int rg;
    char nome[20];
};

void Menu(int aux,string* txt);
int opcoes();
int opcoes2();
Listaseq* alocaVetor(int aux);
//InicioSeq




int main()
{
    std::clock_t start;
    double duration;
    int c=0;
    int m=0;
    Listaseq* seq;
    int menu,menu2,tamanholista=0;
    cout <<"Escolha uma opcao:"<<endl;
    opcoes();
    cin>>menu;
    seq = alocaVetor(menu);
    Lista2 listaenc;
    string txt;
    Menu(menu,&txt);
    long int rg;
    int n;
    string rgAux,line,aux;
    string nomeAux;
    char *nomeAux2;

    ifstream listaTeste(txt.c_str());
    if(listaTeste.is_open()){
        while (getline(listaTeste,line)){
            stringstream ss(line);
            getline(ss,nomeAux,',');
            getline(ss,rgAux,',');
            stringstream aux(rgAux);
            aux>>rg;
            n=nomeAux.length();
            nomeAux2 = new char[n+1];
            strcpy(nomeAux2,nomeAux.c_str());
            listaenc.AdicionaNode(rg,nomeAux2);
            seq[tamanholista].rg=rg;
            strcpy(seq[tamanholista].nome,nomeAux2);
            tamanholista++;
        }
    }
    opcoes2();
    cin>>menu2;

    while (menu2!=0){
    if(menu2==0){
        break;
    }
    if(menu2==1){
        int i;
        m=0;
        c=0;
        long int rgnovo,novoaux,antigoaux;
        char nomenovo[20], novo[20],antigo[20];
        cout<<"Insira um nome"<< endl;
        cin>>nomenovo;
        cout<<"Insira um RG"<< endl;
        cin>>rgnovo;
        start = std::clock();
        seq= (Listaseq*)realloc (seq,(tamanholista+1)*sizeof(Listaseq));
        listaenc.AdicionaNodeInicio(rgnovo,nomenovo);
        novoaux=rgnovo;m++;
        strcpy(novo,"          ");
        strcpy(novo,nomenovo);m++;
        tamanholista++;
        for(i=0;i<tamanholista;i++){
            c++;
            antigoaux=seq[i].rg;m++;//Duas variaveis (antigo e novo).Flutuando os valores para adequar a matriz;
            strcpy(antigo,"         ");
            strcpy(antigo,seq[i].nome);m++;

            seq[i].rg=novoaux;m++;
            strcpy(seq[i].nome,"        ");
            strcpy(seq[i].nome,novo);m++;

            novoaux=antigoaux;m++;
            strcpy(novo,"               ");
            strcpy(novo,antigo);m++;

        }
            duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
            cout<<"Tempo seq:"<< duration <<'\n';
            cout<<"M seq("<<m<<")"<<endl;
            cout<<"C seq("<<c<<")"<<endl;
    }
    else if(menu2==2){
        m=0;
        c=0;
        long int rgnovo,novoaux,antigoaux;
        char nomenovo[20];
        cout<<"Insira um nome"<< endl;
        cin>>nomenovo;
        cout<<"Insira um RG"<< endl;
        cin>>rgnovo;
        start = std::clock();
        listaenc.AdicionaNodeFim(rgnovo,nomenovo);
        seq= (Listaseq*)realloc (seq,(tamanholista+1)*sizeof(Listaseq));
        tamanholista++;

        seq[tamanholista].rg=rgnovo;m++;
        strcpy(seq[tamanholista-1].nome,"            ");
        strcpy(seq[tamanholista-1].nome,nomenovo);m++;
        duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
        cout<<"Tempo seq:"<< duration <<'\n';
        cout<<"M seq("<<m<<")"<<endl;
        cout<<"C seq("<<c<<")"<<endl;
    }
    else if(menu2==3){
        m=0;
        c=0;
        long int rgnovo,novoaux,antigoaux;
        int num;
        char nomenovo[20], novo[20],antigo[20];
        start = std::clock();
        seq= (Listaseq*)realloc (seq,(tamanholista+1)*sizeof(Listaseq));
        tamanholista++;
        cout<<"Insira um nome"<< endl;
        cin>>nomenovo;
        cout<<"Insira um RG"<< endl;
        cin>>rgnovo;
        cout<<"Insira a posicao N"<< endl;
        cin>>num;

        novoaux=rgnovo;m++;
        strcpy(novo,"          ");
        strcpy(novo,nomenovo);m++;
        listaenc.AdicionaNodeN(rgnovo,nomenovo,num);

        for(int i=num;i<tamanholista;i++){

            c++;
            antigoaux=seq[i].rg;m++;//Duas variaveis (antigo e novo).Flutuando os valores para adequar a matriz;
            strcpy(antigo,"         ");
            strcpy(antigo,seq[i].nome);m++;

            seq[i-1].rg=novoaux;m++;
            strcpy(seq[i-1].nome,"        ");
            strcpy(seq[i-1].nome,novo);m++;

            novoaux=antigoaux;m++;
            strcpy(novo,"               ");
            strcpy(novo,antigo);m++;
            //cout <<seq[i].rg<<endl;

        }
        duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
        cout<<"Tempo seq:"<< duration <<'\n';
        cout<<"M seq("<<m<<")"<<endl;
        cout<<"C seq("<<c<<")"<<endl;
    }
    else if(menu2==4){
        m=0;
        c=0;
        listaenc.DeletaNodePrimeiro();
        start = std::clock();


        for(int i=0;i<tamanholista-1;i++){
            c++;
            seq[i].rg = seq[i+1].rg;m++;
            strcpy(seq[i].nome,seq[i+1].nome);m++;
            cout<<seq[i].nome<<endl;
        }
        tamanholista--;
        duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
        cout<<"Tempo seq:"<< duration <<'\n';
        cout<<"M seq("<<m<<")"<<endl;
        cout<<"C seq("<<c<<")"<<endl;

    }
    else if(menu2==5){
        m=0;
        c=0;
        int i=0;
        listaenc.DeletaNodeUltimo();
        start = std::clock();

        strcpy(seq[tamanholista-1].nome,"              ");
        seq[tamanholista-1].rg=NULL;m++;
        tamanholista=tamanholista-2;
        duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
        cout<<"Tempo seq:"<< duration <<'\n';
        cout<<"M seq("<<m<<")"<<endl;
        cout<<"C seq("<<c<<")"<<endl;

    }
    else if(menu2==6){
        m=0;
        c=0;
        int num;
        cout<<"Insira a posicao N"<< endl;
        cin>>num;
        long int rgnovo,novoaux,antigoaux;
        char nomenovo[20], novo[20],antigo[20];
        listaenc.DeletaNodeN(num);
        start = std::clock();
        strcpy(seq[num-1].nome,"             ");
        seq[num-1].rg=NULL;m++;
        for(int i=num-1;i<tamanholista;i++){
            c++;
            seq[i].rg=seq[i+1].rg;m++;
            strcpy(seq[i].nome,"             ");
            strcpy(seq[i].nome,seq[i+1].nome);m++;
        }
        tamanholista--;
        duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
        cout<<"Tempo seq:"<< duration <<'\n';
        cout<<"M seq("<<m<<")"<<endl;
        cout<<"C seq("<<c<<")"<<endl;

    }
    else if(menu2==7){
        m=0;
        c=0;
        long int rg1;
        cout<<"Insira o RG"<<endl;
        cin>>rg1;
        start = std::clock();
        listaenc.ProcuraNo(rg1);
        int cont=0;
        while(rg1!=seq[cont].rg&&cont<tamanholista){
            c++;
            cont++;
        }
        if(rg1==seq[cont].rg){
            c++;
            cout<<"Sequencial: "<<seq[cont].nome<<endl;
        }
        else{
            cout<<"Não encontrado"<<endl;

        }
        duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
        cout<<"Tempo seq:"<< duration <<'\n';
        cout<<"M seq("<<m<<")"<<endl;
        cout<<"C seq("<<c<<")"<<endl;

    }
    else if(menu2==8){
        cout << "ENCADEADA"<<endl;
        listaenc.ImprimeLista();
        cout << "Sequencial"<<endl;
         for(int b=0;b<tamanholista;b++)
        cout<<seq[b].nome<<", "<< seq[b].rg<<endl;
    }
    else if(menu2==9){
        int contaux=0;
        ofstream myfile ("example.txt");
        if (myfile.is_open())
        {
        while(contaux<tamanholista){
          myfile << seq[contaux].nome;
          myfile << ", ";
          myfile << seq[contaux].rg;"\n";
          contaux++;
        }
        myfile.close();
        }
        else cout << "Unable to open file";


    }

     opcoes2();
     cin>>menu2;
     system("cls");

    }

    free(seq);

}



    int opcoes(){
        cout << "1 -> 10"<<endl;
        cout << "2 -> 50"<<endl;
        cout << "3 -> 100"<<endl;
        cout << "4 -> 1000"<<endl;
        cout << "5 -> 10000"<<endl;
        cout << "6 -> 1000000"<<endl;
        cout << "7 -> 10000000"<<endl;

        return 0;
    }
    int opcoes2(){
    cout << "0 -> Exit"<<endl;
    cout << "1 -> No no inicio da lista"<<endl;
    cout << "2 -> No no fim da lista"<<endl;
    cout << "3 -> No na posicao N"<<endl;
    cout << "4 -> Retirar no no inicio da lista"<<endl;
    cout << "5 -> Retirar no no fim da lista"<<endl;
    cout << "6 -> Retirar no na posicao N"<<endl;
    cout << "7 -> Procurar um valor"<<endl;
    cout << "8 -> Imprimir lista"<<endl;
    cout << "9 -> Escreve lista"<<endl;

    return 0;
}

void Menu(int aux, string *txt){


    switch ( aux )
        {
        case 1 :
            *txt="NomeRG10.txt";
            break;

        case 2 :
            *txt="NomeRG50.txt";
            break;

        case 3 :
            *txt="NomeRG100.txt";
            break;

        case 4 :
            *txt="NomeRG1K.txt";
            break;

        case 5 :
            *txt="NomeRG10K.txt";
            break;

        case 6 :
            *txt="NomeRG1M.txt";
            break;

        case 7 :
            *txt="NomeRG100M.txt";
            break;
        }

}

Listaseq* alocaVetor(int aux){
    Listaseq *v;
     switch ( aux )
        {
        case 1 :
        v = new Listaseq[10];
        return v;
        break;

        case 2 :
        v = new Listaseq[50];
        return v;
        break;

        case 3 :
        v = new Listaseq[100];
        return v;
        break;

        case 4 :
        v = new Listaseq[1000];
        return v;;
        break;

        case 5 :
        v = new Listaseq[10000];
        return v;
        break;

        case 6 :
        v = new Listaseq[1000000];
        return v;
        break;

        case 7 :
         v = new Listaseq[11748443];
        return v;
        break;
        }
}
