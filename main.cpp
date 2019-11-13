#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

using namespace std;

int isOperator(char buffer[]){ // operator
    char keywords[32][10] = {"not","and","or","xor","if","then","iff"};
    int i;
    int flag = 0;
    for(i = 0; i < 32; ++i){
        if(strcmp(keywords[i], buffer) == 0){;
            flag = 1;
            break;
        }
    }
    if(flag == 1){
        return i+2;
    } else{
        return 0;
    }

}
int isOperand(char buffer[]){ // operator
    char keywords[32][10] = {"p","q","r","s"};
    int i, flag = 0;

    for(i = 0; i < 32; ++i){
        if(strcmp(keywords[i], buffer) == 0){
            flag = 1;
            break;
        }
    }

    return flag;
}

int isGrouping(char buffer[]){ // operator
    char keywords[2][10] = {"(",")"};
    int i;
    int flag = 0;
    for(i = 0; i < 2; ++i){
        if(strcmp(keywords[i], buffer) == 0){;
            flag = 1;
            break;
        }
    }
    if(flag == 1){
        return i+9;
    } else{
        return 0;
    }

}
int main(){
    char ch, buffer[15], grouping[] = "()";
    ifstream fin("program.txt");
    int i,j=0;

    if(!fin.is_open()){
        cout<<"error while opening the file\n";
        exit(0);
    }

    while(!fin.eof()){
           ch = fin.get();
  //      cout<<ch;

            for(i = 0; i < 2; ++i){
               if(ch == grouping[i]){
                    if(ch == '(')
                        cout<<ch<<" 9\n";
                    else if(ch == ')')
                        cout<<ch<<" 10\n";
               }
           }

           if(isalnum(ch)){
               buffer[j++] = ch;
           }
           else if((ch == ' ' || ch == '\n') && (j != 0)){
                   buffer[j] = '\0';
                   j = 0;

                   if(isOperator(buffer) > 0)
                       cout<<buffer<<"      "<<isOperator(buffer)<<endl;
                   else if(isOperand(buffer) == 1)
                       cout<<buffer<<"      1"<<endl;
                   else if(buffer == "not(")
                       cout<<buffer[0]<<buffer[1]<<buffer[2] << "  2"<<endl<<buffer[3]<<"  9"<<endl;
                   else
                        cout<<" error\n";
           }
    }

    fin.close();

    return 0;
}
