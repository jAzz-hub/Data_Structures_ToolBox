 
// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>



/*Na matriz esparça o usuário vai digitar a linha e a coluna, caso não seja possível armazenar nesta direção realize o deslocamento de Hash*/


/// @brief Função que verifica se a Hash está cheia:
/// @param array vetor do tipo Hash
/// @param N tamanho do vetor Hash
/// @return verdadeiro se o vetor estiver cheio e falso se não estiver cheio
bool fullHash(int *array,int N)
{

    int i = 0;

    while(i<N)
    {
        if(array[i]<0) return false;    
        
        else i++;
    }

    return true;
}


int Deslocar(int z[], int index, int N)
{
    int finalIndex;
    index++;
    if(z[index]>0)
    {
        printf("\n\t@@");
        Deslocar(z, index, N);
    }
    else if(index>N)
    {
        printf("\n\tEND");
        index = -1;
        Deslocar(z, index, N);
    }
    else
    {
        printf("\n\tRR");
        finalIndex = index;
    }
        printf("\n\t##");
    return finalIndex;
}

void inserirNaHash(int *z, int index,int entrada, int N,int *fullMeter)
{
    printf("ENTREEI");
    printf("\t\t \n\n \t\tindice: %d , z[indice]: %d, N: %d\t",index,z[index],N);
    if(fullHash(z,N)) 
    {

        printf("ENTREEI \n\n1111\n\n ");
        printf("A hash está cheia! * ¬ *");
        exit(0);
    }
    else if(z[index]>0)
    {
        printf("ENTREEI \n\n2222\n\n ");
        index = Deslocar(z, index, N);
        z[index] = entrada;
        fullMeter+=1;
    }
    else if(index<0)
    {
        printf("ENTREEI \n\n3333\n\n ");
        index = index*(-1);
        z[index] = entrada;
        fullMeter+=1;
        printf("%d",z[index]);
    }
    else
    {
        printf("ENTREEI \n\n4444\n\n ");
        z[index] = entrada;
        fullMeter+=1;
        printf("%d",z[index]);
    }
}

void MostarHash(int *z,int N)
{
    printf("\n\n HASH AQUI ESTÁ SUA HASH:\t");
    for(int a = 0;a<=N;a++)
    {
        printf("%d,",z[a]);
    }
    printf("\n\n\n\n\n\n");
}

void EsvaziarHash(int *z,int N)
{
    for(int a = 0;a<=N;a++)
    {
        z[a] = -1;
    }
    printf("HASH ESVAZIADA:");
    for(int a = 0;a<=N;a++)
    {
        printf("%d,",z[a]);
    }
    printf("\n\n\n\n\n\n");
}

int randomizerGenerator(int num,int num2)
{
    int aux=num2;
    num = num + 1;

    printf("AQUII a");
    if(num%2 == 0)
    {
        printf("AQUII");
        aux = round((log10(num*(233+(num*num))))*(num2*3.14171-1));
        randomizerGenerator(num,aux);
    }
    else 
    {
        printf("AQUII e");
        aux = round((log10(num*(233+(num*num))))*(num2*3.14171-1));
        return aux%num;
    }
    return aux%num;
}

#define N 10
//Função que mostra a soma dos quadrados dos 2 ou 1 digito(s) localizados na região de n/2 em uma sequência de n digitos. 
int main()
{
    // Write C code here
    int enter;
    int fullMeter = 0;
    int inserir = 1;
    int random;
    int z[N];
    int firstD; 
    int secondD;
    int ThirdD;
    EsvaziarHash(&*z,N);

    while(N != fullMeter)
    {
        //Criar Hash e receber entradas:
        printf("N:%d --- fM: %d",N,fullMeter);
        printf("Deseja inserir um novo valor na Hash?");
        scanf("%d",&inserir);

        printf("Insira o valor de entrada:");
        scanf("%d",&enter);
    

        
        //Verificando o número de dígitos da entrada para conseguir gerar um auxiliar:
        int numOfDigits = log10(enter)+1;


        //Gerando um vetor auxiliar:

        //Preenchendo o vetor auxiliar:
        int counter = 0;
        int enterAuxiliary = enter;


        int auxArray[N];
        while(enterAuxiliary)
        {
            auxArray[counter] = (enterAuxiliary%10);
            enterAuxiliary/=10;
            counter++;
        }


        if(numOfDigits>1)
        {        
            //Armazenando os digitos em variáveis:
            firstD = auxArray[(numOfDigits/2)-1];
            secondD = auxArray[(numOfDigits/2)];
            ThirdD = auxArray[(numOfDigits/2)+1];
        }
        else
        {
            firstD = auxArray[(numOfDigits/2)];
            secondD = auxArray[(numOfDigits/2)+1];
            ThirdD = auxArray[(numOfDigits/2)+2];
        }

        //Obtendo a soma dos quadrados dos digitos:
        int quarterSum = (firstD*firstD)+(secondD*secondD)+(ThirdD*ThirdD);

        //Obtendo o valor do índice de Hash:
        char key[12] = {'*','$','?','M','+','^','~','@','!','#','/'}; 
        int number = round(enter*(37.11379));
        
        
        //Here is good
        

        random = randomizerGenerator(key[secondD],key[firstD]);
       
        int mod = (random+(quarterSum*7/numOfDigits)+enter+key[number%10])%N;

        
        inserirNaHash(&*z, mod, enter, N, &fullMeter);
        MostarHash(&*z,N);
    }
    
    return 0;
}
