#include <iostream>

#include "Vector.h"

int size_test ();
int max_size_test ();
int resize_test();
int empty_test();
int capacity_test ();
int Access_element_test ();
int Access_element_test_at ();
int front_test ();
int back_test ();
int data_test ();
int swap_test ();

int main() {
    //size_test();
    //max_size_test();
    //resize_test();
    //empty_test();
    //capacity_test ();
    //Access_element_test ();
    //Access_element_test_at ();
    //front_test ();
    //back_test ();
    //data_test ();
    //swap_test ();

}


int size_test () {
    Vector<int> myints;
    std::cout << "0. size: " << myints.size() << '\n';

    for (int i = 0; i < 10; i++) myints.push_back(i);
    std::cout << "1. size: " << myints.size() << '\n';

    myints.pop_back();
    std::cout << "3. size: " << myints.size() << '\n';

    return 0;

}


int max_size_test ()
{
    Vector<int> myvector;

    // set some content in the vector:
    for (int i=0; i<101; i++) myvector.push_back(i);

    std::cout << "size: " << myvector.size() << "\n";
    std::cout << "capacity: " << myvector.capacity() << "\n";
    std::cout << "max_size: " << myvector.max_size() << "\n";
    return 0;
}


int resize_test ()
{
    Vector<int> myvector;

    // set some initial content:
    for (int i=1;i<10;i++) myvector.push_back(i);

    myvector.resize();
    myvector.resize();
    myvector.resize();

    std::cout << "myvector contains:";
    for (int i=0;i<myvector.size();i++)
        std::cout << ' ' << myvector[i];
    std::cout << '\n';

    return 0;
}


int empty_test()
{
    Vector<int> myvector;
    int sum (0);

    for (int i=1;i<=10;i++) myvector.push_back(i);

    while (!myvector.empty())
    {
        sum += myvector.back();
        myvector.pop_back();
    }

    std::cout << "total: " << sum << '\n';

    return 0;
}


int capacity_test ()
{
    size_t sz;
    Vector<int> foo;
    sz = foo.capacity();
    std::cout << "making foo grow:\n";
    for (int i=0; i<100; ++i) {
        foo.push_back(i);
        if (sz!=foo.capacity()) {
            sz = foo.capacity();
            std::cout << "capacity changed: " << sz << '\n';
        }
    }

    Vector<int> bar;
    sz = bar.capacity();
    bar.reserve(100);   // this is the only difference with foo above
    std::cout << "making bar grow:\n";
    for (int i=0; i<100; ++i) {
        bar.push_back(i);
        if (sz!=bar.capacity()) {
            sz = bar.capacity();
            std::cout << "capacity changed: " << sz << '\n';
        }
    }
    return 0;
}

int Access_element_test ()
{
    Vector<int> myvector;   // 10 zero-initialized elements
    int x = 0;
    for (int i=1;i<=10;i++) myvector.push_back(x);
    size_t sz = myvector.size();

    // assign some values:
    for (unsigned i=0; i<sz; i++) myvector[i]=i;

    // reverse vector using operator[]:
    for (unsigned i=0; i<sz/2; i++)
    {
        int temp;
        temp = myvector[sz-1-i];
        myvector[sz-1-i]=myvector[i];
        myvector[i]=temp;
    }

    std::cout << "myvector contains:";
    for (unsigned i=0; i<sz; i++)
        std::cout << ' ' << myvector[i];
    std::cout << '\n';

    return 0;
}

int Access_element_test_at ()
{
    Vector<int> myvector;   // 10 zero-initialized elements
    int x = 0;
    for (int i=1;i<=10;i++) myvector.push_back(x);

    // assign some values:
    for (unsigned i=0; i<myvector.size(); i++)
        myvector.at(i)=i;

    std::cout << "myvector contains:";
    for (unsigned i=0; i<myvector.size(); i++)
        std::cout << ' ' << myvector.at(i);
    std::cout << '\n';

    return 0;
}

int front_test ()
{
    Vector<int> myvector;
    int x = 78;
    int y = 16;
    myvector.push_back(x);
    myvector.push_back(y);

    // now front equals 78, and back 16

    myvector.front() -= myvector.back();

    std::cout << "myvector.front() is now " << myvector.front() << '\n';

    return 0;
}

int back_test ()
{
    Vector<int> myvector;
    int x = 10;
    int y;
    myvector.push_back(x);

    while (myvector.back() != 0)
    {
        y = myvector.back() -1;
        myvector.push_back (y  );
    }

    std::cout << "myvector contains:";
    for (unsigned i=0; i<myvector.size() ; i++)
        std::cout << ' ' << myvector[i];
    std::cout << '\n';

    return 0;
}

int data_test ()
{
    Vector<int> myvector;
    int x = 0;
    for (int i=1;i<=5;i++) myvector.push_back(x);
    int* p = myvector.data();

    *p = 10;
    ++p;
    *p = 20;
    p[2] = 100;

    std::cout << "myvector contains:";
    for (unsigned i=0; i<myvector.size(); ++i)
        std::cout << ' ' << myvector[i];
    std::cout << '\n';

    return 0;
}

int swap_test ()
{
    Vector<int> foo;   // three ints with a value of 100
    int x = 100;
    for (int i=1;i<=3;i++) foo.push_back(x);
    Vector<int> bar;   // five ints with a value of 200
    int y = 200;
    for (int i=1;i<=5;i++) bar.push_back(y);


    foo.swap(bar);

    std::cout << "foo contains:";
    for (unsigned i=0; i<foo.size(); i++)
        std::cout << ' ' << foo[i];
    std::cout << '\n';

    std::cout << "bar contains:";
    for (unsigned i=0; i<bar.size(); i++)
        std::cout << ' ' << bar[i];
    std::cout << '\n';

    return 0;
}