#include "sdt.h"
#include "convert1.h"
struct Student
{
    char name[16];
    int year;
    double GPA;
    int sex:1;
    int class1;
    Student *starosta;
};
main()
{

    Student studarray[3]=
    {
        {"Maksutova", 2013,4.6,0,3,&studarray[1]},
        {"Vasilkova", 2014,4.8,0,4,nullptr},
        {"Sukharev", 2015,4.3,1,5,&studarray[1]}

    };



    cout <<"Adress of array: "<<&studarray<<"\n";
    cout <<"Size of array: "<<sizeof(studarray)<<"\n\n";
    cout <<"\tAdress of element:"<<"\tSize of element:\n";
    for(int i=0; i<3; ++i)
    {
        cout<<i+1<<": \t"<<&studarray[i]<<"\t\t"<<sizeof(studarray[i])<<"\n";
    }
    cout<<"\nFOR FIRST [0] ELEMENT OF ARRAY:\n";
    cout <<"\t     Adress of field:"<<"\tSize of field:"<<"\tOffset:\n";
    cout <<"NAME: \t\t"<<&studarray[0].name<<"\t\t"<<sizeof(studarray[0].name)<<"\t"<<offsetof(struct Student,name)<<"\n";
    cout <<"YEAR: \t\t"<<&studarray[0].year<<"\t\t"<<sizeof(studarray[0].year)<<"\t"<<offsetof(struct Student,year)<<"\n";
    cout <<"GPA: \t\t"<<&studarray[0].GPA<<"\t\t"<<sizeof(studarray[0].GPA)<<"\t"<<offsetof(struct Student,GPA)<<"\n";
    cout <<"CLASS: \t\t"<<&studarray[0].class1<<"\t\t"<<sizeof(studarray[0].class1)<<"\t"<<offsetof(struct Student,class1)<<"\n";
    cout <<"STAROSTA: \t"<<&studarray[0].starosta<<"\t\t"<<sizeof(studarray[0].starosta)<<"\t"<<offsetof(struct Student,starosta)<<"\n";
    cout<<"\n";
    cout <<"NAME: \t\t\n";
    cout <<"Binary: ";
    print_in_binary(&studarray[0].name,sizeof(studarray[0].name));
    cout<<"\n";
    cout<<"Hex: ";
    print_in_hex(&studarray[0].name,sizeof(studarray[0].name));
    cout<<"\n\n";
    cout <<"YEAR:\n";
    cout <<"Binary: ";
    print_in_binary(&studarray[0].year,sizeof(studarray[0].year));
    cout<<"\n";
    cout<<"Hex: ";
    print_in_hex(&studarray[0].year,sizeof(studarray[0].year));
    cout<<"\n\n";
    cout <<"GPA:\n";
    cout <<"Binary: ";
    print_in_binary(&studarray[0].GPA,sizeof(studarray[0].GPA));
    cout<<"\t";
    cout<<"Hex: ";
    print_in_hex(&studarray[0].GPA,sizeof(studarray[0].GPA));
    cout<<"\n\n";
    cout <<"CLASS: \n";
    cout <<"Binary: ";
    print_in_binary(&studarray[0].class1,sizeof(studarray[0].class1));
    cout<<"\n";
    cout<<"Hex: ";
    print_in_hex(&studarray[0].class1,sizeof(studarray[0].class1));
    cout<<"\n\n";
    cout <<"STAROSTA: \n";
    cout <<"Binary: ";
    print_in_binary(&studarray[0].starosta,sizeof(studarray[0].starosta));
    cout<<"\n";
    cout<<"Hex: ";
    print_in_hex(&studarray[0].starosta,sizeof(studarray[0].starosta));
    cout<<"\n\n";
    cout <<"Elements of array in hex:\n";
    for(int i=0; i<3; ++i)
    {
        cout<<i+1<<": ";
        print_in_hex(&studarray[i],sizeof(studarray[i]));

        cout<<"\n\n\n";
    }

}
