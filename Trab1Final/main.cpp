

#include "Lista2.h"

using namespace std;

struct Listaseq{
    long int rg;
    char nome[20];
};

void Menu(int aux,string* txt);
int opcoes();
int opcoes2();
int opcoes3();
Listaseq* alocaVetor(int aux);
void troca(Listaseq auxv, int menor,int maior);
void selectionSort(Listaseq* v,int tam);
void insertionSort(Listaseq* v,int tam);
void mergeSort(Listaseq* v,Listaseq*w,int ini, int fim);
void funcaoIntercala(Listaseq* v,Listaseq*w,int ini, int meio, int fim);




int main()
{

    time_t t_ini, t_fim;
    int c=0;
    int m=0;
    float tempo;
    Listaseq* seq;
    int menu,menu2,menu3,tamanholista=0;
    cout <<"Escolha uma opcao:"<<endl;
    opcoes();
    cin>>menu;
    system("clear");
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

        t_ini=time(NULL);

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
            t_fim=time(NULL);
            tempo=difftime(t_fim,t_ini);

            cout<<"Tempo seq:"<<tempo<<endl;
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
        listaenc.AdicionaNodeFim(rgnovo,nomenovo);
        seq= (Listaseq*)realloc (seq,(tamanholista+1)*sizeof(Listaseq));
        tamanholista++;

        t_ini=time(NULL);

        seq[tamanholista-1].rg=rgnovo;m++;
        strcpy(seq[tamanholista-1].nome,"            ");
        strcpy(seq[tamanholista-1].nome,nomenovo);m++;

        t_fim=time(NULL);
        tempo=difftime(t_fim,t_ini);
        cout<<"Tempo seq:"<<tempo<<endl;
        cout<<"M seq("<<m<<")"<<endl;
        cout<<"C seq("<<c<<")"<<endl;
    }
    else if(menu2==3){
        m=0;
        c=0;
        long int rgnovo,novoaux,antigoaux;
        int num;
        char nomenovo[20], novo[20],antigo[20];

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

        t_ini=time(NULL);

        for(int i=num;i<tamanholista+1;i++){

            c++;
            antigoaux=seq[i-1].rg;m++;//Duas variaveis (antigo e novo).Flutuando os valores para adequar a matriz;
            strcpy(antigo,"         ");
            strcpy(antigo,seq[i-1].nome);m++;

            seq[i-1].rg=novoaux;m++;
            strcpy(seq[i-1].nome,"        ");
            strcpy(seq[i-1].nome,novo);m++;

            novoaux=antigoaux;m++;
            strcpy(novo,"               ");
            strcpy(novo,antigo);m++;
        }

        t_fim=time(NULL);
        tempo=difftime(t_fim,t_ini);
        cout<<"Tempo seq:"<<tempo<<endl;
        cout<<"M seq("<<m<<")"<<endl;
        cout<<"C seq("<<c<<")"<<endl;
    }
    else if(menu2==4){
        m=0;
        c=0;
        listaenc.DeletaNodePrimeiro();

        t_ini=time(NULL);

        for(int i=0;i<tamanholista-1;i++){
            c++;
            seq[i].rg = seq[i+1].rg;m++;
            strcpy(seq[i].nome,seq[i+1].nome);m++;
        }
        seq= (Listaseq*)realloc (seq,(tamanholista-1)*sizeof(Listaseq));
        tamanholista--;

        t_fim=time(NULL);
        tempo=difftime(t_fim,t_ini);
        cout<<"Tempo seq:"<<tempo<<endl;
        cout<<"M seq("<<m<<")"<<endl;
        cout<<"C seq("<<c<<")"<<endl;

    }
    else if(menu2==5){
        m=0;
        c=0;
        int i=0;
        listaenc.DeletaNodeUltimo();
        t_ini=time(NULL);

        strcpy(seq[tamanholista-1].nome,"  ");
        seq[tamanholista-1].rg=NULL;m++;
        seq= (Listaseq*)realloc (seq,(tamanholista-1)*sizeof(Listaseq));
        tamanholista--;

        t_fim=time(NULL);
        tempo=difftime(t_fim,t_ini);

        cout<<"Tempo seq:"<<tempo<<endl;
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
        t_ini=time(NULL);
        tamanholista--;
        strcpy(seq[num-1].nome,"             ");
        seq[num-1].rg=NULL;m++;
        for(int i=num-1;i<tamanholista;i++){
            c++;
            seq[i].rg=seq[i+1].rg;m++;
            strcpy(seq[i].nome,"             ");
            strcpy(seq[i].nome,seq[i+1].nome);m++;
        }
        seq= (Listaseq*)realloc (seq,(tamanholista)*sizeof(Listaseq));

        t_fim=time(NULL);
        tempo=difftime(t_fim,t_ini);
        cout<<"Tempo seq:"<<tempo<<endl;
        cout<<"M seq("<<m<<")"<<endl;
        cout<<"C seq("<<c<<")"<<endl;

    }
    else if(menu2==7){
        m=0;
        c=0;
         int rg1;
        cout<<"Insira o RG"<<endl;
        cin>>rg1;
        t_ini=time(NULL);
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


        t_fim=time(NULL);
        tempo=difftime(t_fim,t_ini);
        cout<<"Tempo seq:"<<tempo<<endl;
        cout<<"M seq("<<m<<")"<<endl;
        cout<<"C seq("<<c<<")"<<endl;

    }
    else if(menu2==8){
        cout << "ENCADEADA"<<endl;
        listaenc.ImprimeLista();
        cout << "Sequencial"<<endl;
         for(int bn=0;bn<tamanholista;bn++)
         {
            cout<< seq[bn].nome<<", "<<seq[bn].rg<<endl;

            cout.flush();
         }
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

    else if(menu2==10){

        opcoes3();
        cin>>menu3;

        while(menu3!=0){

        if(menu3==0){
            break;
        }
        else if(menu3==1){
            selectionSort(seq,tamanholista);

        }
        else if(menu3==2){
            insertionSort(seq,tamanholista);

        }
        else if(menu3==3){
            Listaseq w[tamanholista];
            mergeSort(seq,w,0,tamanholista-1);
        }
        opcoes3();
        cin>>menu3;
        }

    }

     opcoes2();
     cin>>menu2;
     system("clear");

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
    cout << "10 -> Sort Variations"<<endl;

    return 0;
}

    int opcoes3(){
    cout << "0 -> Exit"<<endl;
    cout << "1 -> Selection Sort"<<endl;
    cout << "2 -> Insertion Sort"<<endl;
    cout << "3 -> Merge Sort"<<endl;


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

void troca(Listaseq*auxv,int menor,int maior){

    Listaseq aux;
    aux=auxv[maior];
    auxv[maior]=auxv[menor];
    auxv[menor]=aux;


}
void selectionSort(Listaseq* v,int tam){

    int i,j,menor;

    for(i=0;i<tam;i++){
        menor=i;
        for(j=i+1;j<tam;j++){
            if(v[j].rg<v[menor].rg){
                menor=j;
            }
        }

    troca(v,menor,i);
    }
}

void insertionSort(Listaseq*v,int tam){

    int i,j;
    Listaseq aux;

    for(i=1;i<tam;i++){
        aux=v[i];
        j=i-1;

        while(j>=0&&v[j].rg>aux.rg){
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=aux;
    }
}

void mergeSort(Listaseq* v,Listaseq*w,int ini,int fim){

        if(ini<fim){
            int meio =(ini+fim)/2;
            mergeSort(v,w,ini,fim);
            mergeSort(v,w,meio+1,fim);
            funcaoIntercala(v,w,ini,meio,fim);
        }
}

void funcaoIntercala(Listaseq* v,Listaseq*w,int ini, int meio, int fim){

        for(int k=ini;k<=fim;k++)
            w[k]=v[k];

        int i=ini;
        int j=meio+1;

        for(int k=ini;k<=fim;k++){
            if(i>meio)
                v[k]=w[j++];

            else if(j>fim)
                v[k]=w[i++];

            else if(w[i].rg<w[j].rg)
                v[k]=w[i++];

            else
                v[k]=w[j++];
        }
        free (w);
}
