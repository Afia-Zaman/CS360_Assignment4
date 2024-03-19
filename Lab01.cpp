1. Correct the errors in the following snippets and explain


a. Assume the following prototype is declared in class Time:
   void ~Time( int );

Ans: The syntax for declaring a destructor in C++ is ~ClassName(). A destructor doesn't take any arguments. 
   So, the correct declaration should be:
   ~Time();
   In C++, the destructor function is declared with a tilde (~) followed by the class name, and it does not take any arguments. 
   Destructors are called automatically when an object is destroyed, typically at the end of its lifetime or when it goes out of scope. 
   They are used to release resources acquired by the object during its lifetime.
  
b. Assume the following prototype is declared in class Employee:
   int Employee( string, string );
     
Ans: int Employee( string, string ); looks like a constructor declaration, but it lacks the Employee keyword before the function name. 
   Constructors don't have return types explicitly declared. Assuming it's meant to be a constructor, it should be:
   Employee( string, string );
   In C++, constructors are special member functions of a class that are automatically called when an object of that class is created. 
   They have the same name as the class and do not specify a return type.

c. The following is a definition of class Example:
class Example{
public:
Example( int y = 10 ): data( y ){
// empty body
} // end Example constructor
int getIncrementedData() const{
return ++data;
} // end function getIncrementedData
static int getCount(){
cout << "Data is " << data << endl;
return count;
} // end function getCount
private:
int data;
static int count;
}; // end class Example

Ans: 
The static member function getCount is trying to access a non-static member data, which is not allowed. 
Static member functions can only access static members of the class. Also, the static member count is declared but not initialized.
class Example{
public:
    Example(int y = 10) : data(y) {}
    int getIncrementedData() const {
        return ++data;
    }
    static int getCount() {
        cout << "Count is " << count << endl;
        return count;
    }
private:
    int data;
    static int count;
};

int Example::count = 0;

In this corrected code, the constructor initializes the data member data with the value passed as an argument, defaulting to 10 if no argument is provided.
The getIncrementedData function returns the value of data after incrementing it.
The getCount function outputs the value of the static member count and returns it.
The static member count is defined outside the class with an initial value of 0. Static members are shared among all instances of 
the class and are accessed using the class name.
