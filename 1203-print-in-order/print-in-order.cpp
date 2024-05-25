class Foo {
    bool f;
    bool s;
    mutex mx;
    condition_variable cv;
public:
    Foo() {
        f = false;
        s = false;
    }

    void first(function<void()> printFirst) {
        lock_guard<mutex> lock(mx);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        f = true;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(mx);
        while(!f) {
            cv.wait(lock);
        };
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        s = true;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lock(mx);

        while(!f || !s) {
            cv.wait(lock);
        };
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};