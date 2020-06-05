// #1115: Print FooBar Alternately
// 
// Rowan Tran
//
// The same instance of FooBar will be passed to two different threads. Thread A will call foo()
// while thread B will call bar(). Modify the given program to output "foobar" n times.

#include <mutex>

class FooBar {
private:
    int n;
    mutex foobar_mutex;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
        	// printFoo() outputs "foo". Do not change or remove this line.
            foobar_mutex.lock();
        	printFoo();
            foobar_mutex.unlock();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
        	// printBar() outputs "bar". Do not change or remove this line.
            foobar_mutex.lock();
        	printBar();
            foobar_mutex.unlock();
        }
    }
};
