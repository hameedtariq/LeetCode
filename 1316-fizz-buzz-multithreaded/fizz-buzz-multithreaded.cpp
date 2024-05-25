class FizzBuzz {
private:
    int n;
    int turn;
    condition_variable cv;
    mutex mtx;
public:
    FizzBuzz(int n) {
        this->n = n;
        this->turn = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while(true){
            unique_lock<mutex> lock(mtx);
            while(turn<=n && !(turn % 3 == 0 && turn % 5 != 0)) {
                cv.wait(lock);
            }
            if(turn > n) {
                cv.notify_all();
                return;
            };

            printFizz();
            turn++;
            cv.notify_all();
        }
        
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while(true){
            unique_lock<mutex> lock(mtx);
            while(turn<=n && !(turn % 3 != 0 && turn % 5 == 0)) {
                cv.wait(lock);
            }
            if(turn > n) {
                cv.notify_all();
                return;
            };

            printBuzz();
            turn++;
            cv.notify_all();
        }
        
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while(true) {
            unique_lock<mutex> lock(mtx);
            while(turn<=n && !(turn % 3 == 0 && turn % 5 == 0)) {
                cv.wait(lock);
            }
            if(turn > n) {
                cv.notify_all();
                return;
            };

            printFizzBuzz();
            turn++;
            cv.notify_all();
        }
        
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while(true){
            unique_lock<mutex> lock(mtx);
            while(turn<=n && (turn % 3 == 0 || turn % 5 == 0)) {
                cv.wait(lock);
            }
            if(turn > n) {
                cv.notify_all();
                return;
            };
            printNumber(turn);
            turn++;
            cv.notify_all();
        }
        
    }
};