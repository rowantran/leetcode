// #1115: Print FooBar Alternately
// 
// Rowan Tran
//
// The same instance of FooBar will be passed to two different threads. Thread A will call foo()
// while thread B will call bar(). Modify the given program to output "foobar" n times.

class FooBar {
private:
    int n;
    int foosPrinted;
    int barsPrinted;

public:
    FooBar(int n) : foosPrinted(0), barsPrinted(0) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            ++foosPrinted;

            while (foosPrinted > barsPrinted) {
                // wait
            }
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            while (foosPrinted <= barsPrinted) {
                // wait
            }

            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            ++barsPrinted;
        }
    }
};
