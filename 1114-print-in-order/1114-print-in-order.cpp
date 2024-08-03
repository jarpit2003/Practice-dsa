class Foo {
public:
    Foo() : count(1) {} // Initialize count to 1 in the constructor

    void first(function<void()> printFirst) {
        unique_lock<mutex> lock(mtx);
        printFirst(); // Print "first"
        count = 2; // Update count to 2
        cv.notify_all(); // Notify waiting threads
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this](){ return count == 2; }); // Wait until count is 2
        printSecond(); // Print "second"
        count = 3; // Update count to 3
        cv.notify_all(); // Notify waiting threads
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this](){ return count == 3; }); // Wait until count is 3
        printThird(); // Print "third"
    }

private:
    mutex mtx;
    condition_variable cv;
    int count;
};