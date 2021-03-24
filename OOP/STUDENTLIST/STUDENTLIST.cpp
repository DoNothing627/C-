#include <bits/stdc++.h>

using namespace std;

int n, lamda= 20;

struct student
{
    string name;
    string clas;
    float score;
    //student(){};

};

student *List= new student[lamda];

string convert(string s)
{
    int n= s.length();
    while(s[--n]== ' ') s.erase(n- 1, 1);
}

string getName(string s)
{
    int n= s.length();
    while(s[n- 1]!= ' '&& n) --n;
    string _s= "";
    while(n< s.length())
        _s= _s+ s[n++];
    return _s;
}

/*void Swap(int i, int j)
{
    student *tmp= List[i];
    List[i]= List[j];
    List[j]= tmp;
}

void Process(student *a)
{
    ++ n;
    List[n]= a;
    for(int i= 0; i< n; i++)
       for(int j= i+ 1; j< n; j++)
       {
           string NAME= getName(List[i].name), _NAME= getName(List[j].name);
           if(NAME== _NAME)
               if(List[i].name< List[j].name)
                   //Swap(i, j);
           //if(NAME< _NAME) Swap(i, j);
       }
}*/

void Input()
{
    cout<< "Option :\n";
    cout<< "1: Enter a new student's data\n";
    cout<< "2: Show all students in the list\n";
    cout<< "3: Quit\n";
    int type;
    cin>> type;
    if(type== 1){

        string _name, _clas;
        float _score;
        //student *a= new student;
        cout<< "Student's name: ";
        cin>> _name;
        cout<< "Student's clas: ";
        cin>> _clas;
        cout<< "Student's score: ";
        cin>> _score;

        convert(_name);

        if(_name!= ""){
            student *a= new student;
            *a = {_name, _clas, _score};
            //cout<< "\n";
            //Process(a);
            //std::cout<< a->name<< " "<< a->clas<< " "<< a->score<< "\n";
            cout<< 1;
            delete a;
        }
    }
    else if(type== 2)
        for(int i= 0; i< n; i++)
            //cout<< List[i].name<< " "<<< List[i].clas<< " "<< List[i].score<< "\n";
            cout<< "1";
    else if(type== 3) return;
    else{
        char c;
        cout<< "Do you want to quit? Y/N \n";
        cin>> c;
        if(c== 'Y') return;
    }
    Input();
}

/*void Test()
{
    string *s;
    s= "132";
    cout<< s+ 1;
}*/

int main()
{
    Input();

    //Test();
    return 0;
}
