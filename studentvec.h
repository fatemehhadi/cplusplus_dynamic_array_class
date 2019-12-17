//
//  Program 7. The purpose of this excercise is to gain   
//  experience with class design.
//  Course: CSYE 6205
//  Assignment number: 7 (h)
//  Author of LinkedList Class (last/first): Hadi Fatemeh

using namespace std;

class StudentVec
{

public:
    typedef int value_type;
    typedef size_t size_type;
    //Ctors/Dtors
    StudentVec();                        // Default Ctor (default capacity
                                         // must be zero)
    ~StudentVec();                       // Dtor
    StudentVec(size_type);               // Specify an initial capacity
    StudentVec(const StudentVec& other); // Copy Ctor. Perform a deep copy
    void push_back(value_type value);    // Append a value_type to dynamic
                                         // array
    size_t size() const;                 // Return current size
    size_t capacity() const;             // Return current capacity
    StudentVec operator=(const StudentVec& other);     
                                         // Overloaded copy assignment operator
    value_type operator[](int position) const;
                                         // For reading
                                         // Overloaded subscript operator
    value_type& operator[](int position);
                                         // For writing
                                         // Overloaded subscript operator    
    void operator=(value_type value);
    
private:
   void regrow();
   size_type fcapacity;
   size_type fsize;
   value_type *pl;
   value_type *plregrow;
};    