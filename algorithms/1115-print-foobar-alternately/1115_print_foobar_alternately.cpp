// #1115: Print FooBar Alternately
// 
// Rowan Tran
//
// The same instance of FooBar will be passed to two different threads. Thread A will call foo()
// while thread B will call bar(). Modify the given program to output "foobar" n times.

#include <condition_variable>
#include <mutex>

class FooBar {
private:
    int n;
    mutex sync_mutex;
    condition_variable sync_cv;

    // Use a flag variable to provide a predicate function for the wait() function. This prevents
    // deadlock by solving the problem of the second thread running too fast, i.e. if the Foo
    // thread notifies the Bar thread and then the Bar thread runs before the Foo thread
    // starts waiting, the Foo thread won't wait at all.
    //
    // This variable is true when it is the Foo thread's turn to print, and false otherwise.
    bool foo_print;

public:
    FooBar(int n) : foo_print(true) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            // Creates a unique_lock, locking the mutex.
            unique_lock<mutex> foo_lock(sync_mutex);

        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            foo_print = false;

            sync_cv.notify_all();

            // Waits on the condition variable until the Bar thread finishes execution.
            // This also uses the predicate function previously mentioned, so this thread
            // will only lock if foo_print is false, i.e. if Bar hasn't finished executing
            // yet.
            sync_cv.wait(foo_lock, [this]() { return foo_print; });

            // Releases the mutex after the unique_lock goes out of scope.
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            // Creates a unique_lock, locking the mutex.
            unique_lock<mutex> bar_lock(sync_mutex);

            // Waits on the condition variable. This also unlocks the mutex,
            // so if this thread is called first, the Foo thread can take
            // the mutex. This uses another predicate function, so if the Foo thread
            // completely finished executing already, this thread won't lock.
            sync_cv.wait(bar_lock, [this]() { return !foo_print; });

            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            foo_print = true;

            sync_cv.notify_all();

            // Releases the mutex after the unique_lock goes out of scope.
        }
    }
};
