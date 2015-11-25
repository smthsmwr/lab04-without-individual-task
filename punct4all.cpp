#include <iostream>
#include <fstream>
#include "locale"
#include <string>
#include "sdt.h"
#include<windows.h>
#include <cstring>
#include <cctype>
using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    char filename[25];
    char filename1[25];
    bool perm,perm1;
    perm=true;
    perm1=true;
    cout <<"Input file name: ";

    fgets(filename, sizeof(filename), stdin);
    filename[strlen(filename) - 1] = 0;
    FILE * ptrFile = fopen(filename, "a+");
    for(int i=0; i<strlen(filename); ++i)
    {
        if (filename[i]=='*' || filename[i]=='"' || filename[i]=='<' || filename[i]=='>' || filename[i]=='?' || filename[i]=='|')
        {
            cerr <<"Error!";
            perm=false;
            break;
        }
    }

    char * pch=strrchr(filename,'.');
    if (pch-filename+1 < 0)
        //if (!pch)
    {
        cerr <<"Input file extension!\n";
        perm=false;
    }
    else
    {
        if (strncmp(pch,".txt",(strlen(pch)-1))!=0 && strncmp(pch,".TXT",(strlen(pch)-1))!=0)
        {
            cerr<<"Allowed extension is: .txt !\n";
            perm=false;

        }
    }

    char * pch1=strchr(filename,':');
    // if (pch1-filename+1 > 0)
    if (pch1)
    {
        if (filename[pch1-filename+1]!='/')
        {
            cerr<<"Unknown character ':' in file name!\n";
            perm=false;
        }

    }

    if (perm)
    {
        fseek(ptrFile,0,SEEK_END);
        // fputs("parta",ptrFile);
        int size = ftell(ptrFile);
        cout <<"File size: "<<size<<"\n";
        fseek(ptrFile,0,SEEK_SET);
        char * mas = (char*) malloc(sizeof(char) * size); //dynamic allocation using "malloc"
        for(int i=0; i<size; ++i) mas[i]=' ';
        size_t res = fread(mas, sizeof(char), size, ptrFile);
        if (res != ftell(ptrFile))
        {
            fputs("Reading error!", ptrFile);
            exit (3);
        }
        mas[strlen(mas)] = 0;
        cout<<"\nText in file:\n";
        puts(mas);
        // delete [] mas;
        int * pos=new int [10];
        int numofprop=0;
        int j=1;
        pos[0]=-1;
        for(int i=0; i<size; ++i)


            if(mas[i] == '.' || mas[i] == '?' || mas[i] == '!' || i==size-1)
            {
                ++numofprop;
                pos[j]=0;

                pos[j]=i;
                ++j;
            }

        cout <<"\nThe number of proposals:  "<<numofprop<<"\n";
        cout <<"Enter the string to be found in file: ";
        char str[25];
        fgets(str, sizeof(str), stdin);
        str[strlen(str) - 1] = 0;
        puts(str);
        // cout<<strlen(str);
        char *cp = (char *) mas;
        char *s1, *s2;
        while(*cp)
        {
            s1 = cp;
            s2 = (char *) str;
            while ( *s1 && *s2 && !(*s1-*s2) )
                s1++, s2++;

            if (!*s2)
                cout<<"Pos. of the input string in the text: "<<(cp-mas+1)<<"\n";

            cp++;
        }

        char ** proparray=new char*[numofprop]; //dynamic allocation using "new"
        char * mas1 = (char*) malloc(sizeof(char) * pos[2]); //then to release
        char * str2 = (char*) malloc(sizeof(char) * pos[2]); //then to release
        for(int i=0; i<numofprop; ++i)
        {
            fseek(ptrFile, pos[i]+1,SEEK_SET);
            char * mas1 = (char*) malloc(sizeof(char) * pos[i+1]);
            fread(mas1,sizeof(char),pos[i+1],ptrFile);
            char * str2 = (char*) malloc(sizeof(char) * pos[i+1]);
            proparray[i]= strncpy(str2, mas1, (pos[i+1]-pos[i])*sizeof(char));
        }
        free(pos),free(str2),free(mas1);
        fclose (ptrFile);
        cout<<"\n";
        for(int i=0; i<numofprop; ++i)
        {
            cout<<i+1<<" prop. : "<<proparray[i]<<"\n";
            cout<<"len of "<<i+1<<"th prop. : "<<strlen(proparray[i])<<"\n";
        }
        char * temp;
        for (int i = 0; i < numofprop - 1; i++)
        {
            for (int j = 0; j < numofprop - i - 1; j++)
            {
                if (strlen(proparray[j]) > strlen(proparray[j + 1]))
                {

                    temp = proparray[j];
                    proparray[j] = proparray[j + 1];
                    proparray[j + 1] = temp;
                }
            }
        }
        cout<<"\n\nAFTER SORT:\n";
        for(int i=0; i<numofprop; ++i)
        {
            cout<<i+1<<" prop. : "<<proparray[i]<<"\n";
            cout<<"len of "<<i+1<<"th prop. : "<<strlen(proparray[i])<<"\n";
        }

        cout <<"Input file name to save new data: ";
        fgets(filename1, sizeof(filename1), stdin);
        filename1[strlen(filename1) - 1] = 0;
        FILE * ptrFile1 = fopen(filename1, "w");

        for(int i=0; i<strlen(filename1); ++i)
        {
            if (filename1[i]=='*' || filename1[i]=='"' || filename1[i]=='<' || filename1[i]=='>' || filename1[i]=='?' || filename1[i]=='|')
            {
                cerr <<"Error!";
                perm1=false;
                break;
            }
        }

        char * pch=strrchr(filename1,'.');
        if (pch-filename1+1 < 0)
            //if (!pch)
        {
            cerr <<"Input file extension!\n";
            perm1=false;
        }
        else
        {
            if (strncmp(pch,".txt",(strlen(pch)-1))!=0 && strncmp(pch,".TXT",(strlen(pch)-1))!=0)
            {
                cerr<<"Allowed extension is: .txt !\n";
                perm1=false;

            }
        }

        char * pch1=strchr(filename1,':');
        // if (pch1-filename+1 > 0)
        if (pch1)
        {
            if (filename1[pch1-filename1+1]!='/')
            {
                cerr<<"Unknown character ':' in file name!\n";
                perm1=false;
            }

        }
        if(perm1)
        {
            for(int i=0; i<numofprop; ++i)
                fputs(proparray[i], ptrFile1);
            fclose (ptrFile1);
        } //end of perm1
        free(mas);
        for(int i=0; i<numofprop; ++i)
        delete [] proparray[i];
        fclose (ptrFile1);


    } //end of perm
}

