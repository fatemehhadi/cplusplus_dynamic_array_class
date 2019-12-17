#include <iostream>
#include <cstdlib>

#include "studentvec.h"

using namespace std;


int
main(int argc,char **argv)
{
    StudentVec::size_type  n;

    cout << "============ Test 1 ==============" << endl;
    StudentVec  sv1;
    n = 10;
    for(StudentVec::value_type i = 0; i < n; i++) 
	sv1.push_back(i);
    cout << " 1: size()     = " << sv1.size() << endl;
    cout << " 2: capacity() = " << sv1.capacity() << endl;
    for(StudentVec::value_type i = 0; i < sv1.size(); i++)  {
	if(i != sv1[i])
	    cout << "L1: logic error" << endl;
    }
    cout << " 3: Printing sv1" << endl;
    for(StudentVec::value_type i = 0; i < sv1.size(); i++)  
	cout << " sv1[" << i << "] = " << sv1[i] << endl;

    cout << "============ Test 2 ==============" << endl;
    StudentVec sv2(sv1);
    cout << " 4: size()     = " << sv2.size() << endl;
    cout << " 5: capacity() = " << sv2.capacity() << endl;
    for(StudentVec::value_type i = 0; i < sv2.size(); i++)  {
        if(i != sv2[i])
            cout << "L2: logic error" << endl;
    }
    cout << " 6: Printing sv2" << endl;
    for(StudentVec::value_type i = 0; i < n; i++)
        cout << " sv2[" << i << "] = " << sv2[i] << endl;

    cout << "============ Test 3 ==============" << endl;
    StudentVec sv3;
    sv3 = sv2;
    cout << " 7: size()     = " << sv3.size() << endl;
    cout << " 8: capacity() = " << sv3.capacity() << endl;
    for(StudentVec::value_type i = 0; i < sv3.size(); i++)  {
        if(i != sv3[i])
            cout << "L3: logic error" << endl;
    }
    cout << " 9: Printing sv3" << endl;
    for(StudentVec::value_type i = 0; i < n; i++)
        cout << " sv3[" << i << "] = " << sv3[i] << endl;
//
    cout << "============ Test 4 ==============" << endl;
    StudentVec sv4;
    n = 100000;
    
    for(StudentVec::value_type i = 0; i < n; i++)
    {
        sv4.push_back(i);
    }
    cout << " 10: size()     = " << sv4.size() << endl;
    cout << " 11: capacity() = " << sv4.capacity() << endl;
    for(StudentVec::value_type i = 0; i < sv4.size(); i++)  {
        if(i != sv4[i])
            cout << "L4: logic error" << endl;
    }

    cout << "============ Test 5 ==============" << endl;
    int  init_size = 1000;
    StudentVec sv5(init_size);
    n = 500;
    for(StudentVec::value_type i = 0; i < n; i++)
        sv5.push_back(i);
    cout << " 12: size()     = " << sv5.size() << endl;
    cout << " 13: capacity() = " << sv5.capacity() << endl;
    for(StudentVec::value_type i = init_size; i < sv5.size(); i++)  {
        if(i - init_size != sv5[i])
            cout << "L5: logic error" << endl;
    }

    cout << "============ Test 6 ==============" << endl;
    init_size = 1000;
    StudentVec *psv = new StudentVec(init_size);
    n = 1500;
    for(StudentVec::value_type i = 0; i < n; i++)
        psv->push_back(i);
    cout << " 14: size()     = " << psv->size() << endl;
    cout << " 15: capacity() = " << psv->capacity() << endl;
    for(StudentVec::value_type i = init_size; i < psv->size(); i++)  {
        if(i - init_size != (*psv)[i])
            cout << "L6: logic error" << endl;
    }
    delete psv;

    cout << "============ Test 7 ==============" << endl;
    n = 10000;
    StudentVec sv6(n);
    for(StudentVec::value_type i = 0; i < sv6.capacity(); i++)
        sv6[i] = i;
    cout << " 16: size()     = " << sv6.size() << endl;
    cout << " 17: capacity() = " << sv6.capacity() << endl;
    for(StudentVec::value_type i = 0; i < sv6.size(); i++)  {
        if(i != sv6[i])
            cout << "L7: logic error" << endl;
    }

    cout << endl;

    return 0;
}
