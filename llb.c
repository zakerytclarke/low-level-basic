#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//All keywords
char* commands[]=
{
  "ptrx",
  "ptry",
  "ptrz",

  "putx",
  "puty",
  "putz",

  "goto",
  "if=",
  "if>",
  "if<",

  "add",
  "sub",
  "mul",
  "div",
  "pow",
  "mod",
  "if<=",
  "if>=",

  "prt",
  "inp",

  "movx",
  "movy",
  "movz",
  "swap",

  "prtc",
  "prts",
  "inpc",
  "inps",


  "end",
  "rem"
};

//The program storage
int coms[10000];
int args[10000];
//Current exec
int prgmPtr=0;

//Memory
int mem[10000];
//Pointers
int ptrx=0;
int ptry=0;
int ptrz=0;

int p=0;

void lllb(char com[10]);
void run();
void exec(int com,int arg);

/**
 * Reads in a program and executes
 */
int main(int argc,char *argv[]){
  FILE *file;

  file = fopen(argv[1], "r");


  char c;
  c=(char)fgetc(file);
  //Read until eof
  while(c!=EOF){
    char comStr[10]="";
    int comStrPtr=0;
    //One line at a time
    while(c!='\n'){
      comStr[comStrPtr]=c;
      c=fgetc(file);
      comStrPtr++;
    }
    lllb(comStr);
    c=fgetc(file);
  }
  coms[prgmPtr]=28;
  run();
  return 0;
}

/**
 * Process command and add to program
 */
void lllb(char com[10]){

  char comRun[4];
  comRun[0]='\0';
  comRun[1]='\0';
  comRun[2]='\0';
  comRun[3]='\0';

  int comArg=0;

  int i=0;
  while(com[i]!=' '&&com[i]){
    comRun[i]=com[i];
    i++;
  }
  i++;
  while(com[i]){
    comArg=10*comArg+(com[i]-'0');
    i++;
  }

  int k=0;
  while(k<30&&strcmp(commands[k],comRun)){
    k++;
  }
  //Command exists
  if(k<30&&k>=0){
    coms[prgmPtr]=k;
    args[prgmPtr]=comArg;
  }else{
    coms[prgmPtr]=29;
    args[prgmPtr]=0;
    if(strcmp(com,"")){
      printf("Unknown Command: %s\n",com);
    }
  }
  prgmPtr++;
}


/**
 * Executes the program
 */
void run(){
  prgmPtr=0;
  while(1){
    exec(coms[prgmPtr],args[prgmPtr]);
    prgmPtr++;
  }
}

/**
 * Executes a single command
 */
void exec(int com,int arg){

  //printf("%s %d\n",commands[com],arg);
  if(!strcmp(commands[com],"ptrx")){
    ptrx=arg;
  }
  if(!strcmp(commands[com],"ptry")){
    ptry=arg;
  }
  if(!strcmp(commands[com],"ptrz")){
    ptrz=arg;
  }
  if(!strcmp(commands[com],"putx")){
    mem[ptrx]=arg;
  }
  if(!strcmp(commands[com],"puty")){
    mem[ptry]=arg;
  }
  if(!strcmp(commands[com],"putz")){
    mem[ptrz]=arg;
  }
  if(!strcmp(commands[com],"goto")){
    prgmPtr=arg-2;
  }
  if(!strcmp(commands[com],"if=")){
    if(mem[ptrx]==mem[ptry]){
      prgmPtr=arg-2;
    }
  }

  if(!strcmp(commands[com],"if>")){
    if(mem[ptrx]>mem[ptry]){
      prgmPtr=arg-2;
    }
  }

  if(!strcmp(commands[com],"if<")){
    if(mem[ptrx]<mem[ptry]){
      prgmPtr=arg-2;
    }
  }

  if(!strcmp(commands[com],"if>=")){
    if(mem[ptrx]>=mem[ptry]){
      prgmPtr=arg-2;
    }
  }

  if(!strcmp(commands[com],"if<=")){
    if(mem[ptrx]<=mem[ptry]){
      prgmPtr=arg-2;
    }
  }

  if(!strcmp(commands[com],"if!=")){
    if(mem[ptrx]!=mem[ptry]){
      prgmPtr=arg-2;
    }
  }





  if(!strcmp(commands[com],"add")){
    mem[ptrz]=mem[ptrx]+mem[ptry];

  }
  if(!strcmp(commands[com],"sub")){
    mem[ptrz]=mem[ptrx]-mem[ptry];
  }

  if(!strcmp(commands[com],"mul")){
    mem[ptrz]=mem[ptrx]*mem[ptry];
  }

  if(!strcmp(commands[com],"div")){
    mem[ptrz]=mem[ptrx]/mem[ptry];
  }

  if(!strcmp(commands[com],"pow")){
    mem[ptrz]=pow(mem[ptrx],mem[ptry]);
  }

  if(!strcmp(commands[com],"mod")){
    mem[ptrz]=mem[ptrx]%mem[ptry];
  }


  //Output
  if(!strcmp(commands[com],"prt")){
    printf("%d",mem[arg]);
  }
  if(!strcmp(commands[com],"prtc")){
    printf("%c",mem[arg]);
  }
  if(!strcmp(commands[com],"prts")){
    while(mem[arg]!=0){
      printf("%c",mem[arg]);
      arg++;
    }
  }

  //Inputs

  if(!strcmp(commands[com],"inp")){
    int c=getchar();
    while(c!='\n'){
      mem[arg]=10*mem[arg]+(c-'0');
      c=getchar();
    }

  }
  if(!strcmp(commands[com],"inpc")){
    int c=getchar();
    mem[arg]=c;
  }
  if(!strcmp(commands[com],"inps")){
    int c=getchar();
    while(c!='\n'&&arg>0){
      mem[ptrz]=c;
      arg--;
      ptrz++;
      c=getchar();
    }
  }



  if(!strcmp(commands[com],"movx")){
    mem[arg]=mem[ptrx];
  }

  if(!strcmp(commands[com],"movy")){
    mem[arg]=mem[ptry];
  }
  if(!strcmp(commands[com],"movz")){
    mem[arg]=mem[ptrz];
  }

  if(!strcmp(commands[com],"swap")){
    int temp=mem[ptrx];
    mem[ptrx]=mem[ptry];
    mem[ptry]=temp;
  }

  if(!strcmp(commands[com],"end")){
    printf("\n");
    exit(0);
  }

}
