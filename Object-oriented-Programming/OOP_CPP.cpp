#include <iostream>

using namespace std;

//----------------------------- Class Student 0 --------------------------------------------
//constructors, parametrized constructors, destructos
//class of name student
class student_0{
    //default private
private:
    string pri_proc_friend;
public:
    int id;
    string name;
    int salary;
    
    //constructor
    /*
     A class constructor is a special member function of a class that is executed whenever we create new objects of that class.
    */
    student_0(){
        cout<<"Default Constructor Evoked "<<endl;
        //initialize some values at starting
        id = 0;
        name = " ";
        salary = 0;
        pri_proc_friend = " ";
    }
    
    //Parametrized Constructor
    student_0(int i, string n, int sal){
        cout<<"Parameterized constructor Evoked "<<endl;
        id = i;
        name = n;
        salary = sal;
        pri_proc_friend = n;
    }
    
    //Destructor
    /*
     A destructor is a special member function of a class that is executed whenever an object of it's class goes out of scope or whenever the delete expression is applied to a pointer to the object of that class.
    */
    ~student_0(){
        cout<<"Destructor is Evoked"<<endl;
    }
    
    //some function
    void insert(int i, string n, int sal){
        id = i;
        name = n;
        salary = sal;
        pri_proc_friend = n;
    }
    
    //display
    void display(){
        cout<<"Id: "<<id<<" "<<"Name: "<<name<<" "<<"Salary: "<<salary<<endl;
    }
    
    friend void print_ss(student_0 ss);
};

/*
A friend function of a class is defined outside that class' scope but it has the right to access all private and protected members of the class. Even though the prototypes for friend functions appear in the class definition, friends are not member functions.
*/
void print_ss(student_0 s){
    cout<<"Inside Friend function: "<<endl;
    cout<<"Name: " << s.pri_proc_friend << endl;
}
//--------------------------End of Class Student 0 -----------------------------------------------------


//------------------------------- Class Box ------------------------------------------------------------
//member functions, static functions
class Box{
private:
    double length;         // Length of a box
    double breadth;        // Breadth of a box
    double height;         // Height of a box

public:
    static int objectCount;
    // Member functions declaration
    Box(){
        objectCount++;
    }
    Box(double l, double b, double h);
    double getVolume(void);
    void setLength( double len );
    void setBreadth( double bre );
    void setHeight( double hei );
    
    static int getCount();
};
//constructor
Box::Box(double l, double b, double h){
    length = l;
    breadth = b;
    height = h;
    
    objectCount++;
}

// Member functions definitions
double Box::getVolume(void) {
    return length * breadth * height;
}
void Box::setLength( double len ) {
    length = len;
}
void Box::setBreadth( double bre ) {
    breadth = bre;
}
void Box::setHeight( double hei ) {
    height = hei;
}

/*
By declaring a function member as static, you make it independent of any particular object of the class. A static member function can be called even if no objects of the class exist and the static functions are accessed using only the class name and the scope resolution operator ::.
*/
int Box::getCount(){
    return objectCount;
}
int Box::objectCount = 0;

//--------------------------End of Class Box -----------------------------------------------------


//-------------------------------  Inheritance -----------------------------------------------------
//hybrid inheritance
class A{
protected:
    int a;
public:
    void get_a(){
        a =10;
    }
};

class B : public A{
protected:
    int b;
public:
    void get_b(){
        b =20;
    }
};

class C{
protected:
    int c;
public:
    void get_c(){
        c =30;
    }
};
class D : public B, public C {
protected:
    int d;
public:
    void mul()
    {
        get_a();
        get_b();
        get_c();
        std::cout << "Multiplication of a,b,c is : " <<a*b*c<< std::endl;
    }
};
//------------------------------- End of Inheritance ---------------------------------------------

//------------------------------- Polymorphism - Virtual Function ---------------------------------

class animal{
public:
    virtual void eat(){cout<<"I am eating animal food"<<endl; }
    void fun_1() { cout << "base_animal-1\n"; }
    virtual void fun_2() { cout << "base_animal-2\n"; }
    virtual void fun_3() { cout << "base_animal-3\n"; }
    virtual void fun_4() { cout << "base_animal-4\n"; }
};
class dog : public animal{
public:
    void eat() { cout<<"I am eating dog food"<<endl; }
    void fun_1() { cout << "derived_dog-1\n"; }
    void fun_2() { cout << "derived-2_dog\n"; }
    void fun_4(int x) { cout << "derived_dog-4\n"; }
    
};


//A trivial intermidiate function to call
void func(animal *xyz) { xyz->eat(); }



//------------------------------- End of  Polymorphism - Virtual Function -------------------------

//------------------------------- Namespaces ---------------------------------------------
// first name space
namespace first_space {
    void func() { cout << "Inside first_space" << endl; }
}
// second name space
namespace second_space {
    void func() { cout << "Inside second_space" << endl; }
}
//------------------------------- End of Namespace ---------------------------------------------

//----------------------------------- Main Function ------------------------------------------------------
int main() {
    
    //basic class
    student_0 s0;
    s0.display();
    s0.insert(1, "dheenu", 89000);
    s0.display();
    cout<<endl;
    //parametrized constructor
    student_0 s1(2, "messi", 75000);
    s1.display();
    print_ss(s1);  //friend function
    cout<<endl;
    
    
    Box Box1;                // Declare Box1 of type Box
    double volume = 0.0;     // Store the volume of a box here
    // box 1 specification
    Box1.setLength(6.0);
    Box1.setBreadth(7.0);
    Box1.setHeight(5.0);
    // volume of box 1
    volume = Box1.getVolume();
    cout << "Volume of Box1 : " << volume <<endl;
    Box Box2(8.5, 6.0, 2.0);    // Declare box2
    Box Box3(1.0, 1.0, 1.0);    // Declare box3
    cout << "Final Stage Count: " << Box::getCount() << endl;
    cout<<endl;
    
    //multiple, hybid inhertance
    D d;
    d.mul();
    cout<<endl;
    
    //polymorphism - virtual function
    animal *ani = new animal;
    dog *dogg = new dog;
    //direct calling eat for each objected created
    ani->eat();  //I am eating animal food
    dogg->eat(); //I am eating dog food
    //A trivial intermidiate function the problem arise here
    func(ani);   //I am eating animal food
    func(dogg);  //I am eating animal food - without virtual
    //adding virtual at the base class solves this problem - I am eating dog food
    //another example:
    animal *p;
    dog obj1;
    p = &obj1;
    p->fun_1(); //base_animal-1
    p->fun_2(); //derived-2_dog
    p->fun_3(); //base_animal-3
    p->fun_4(); //base_animal-4
    cout<<endl;
    
    //namespaces
    first_space::func(); //similar to std<::cout
    second_space::func();
    cout<<endl;

    return 0;
}
