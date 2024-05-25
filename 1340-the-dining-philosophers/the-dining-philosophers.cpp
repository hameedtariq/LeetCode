class DiningPhilosophers {
    mutex eating;
    condition_variable cv;

public:
    DiningPhilosophers() {
        
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        
        unique_lock<mutex> lock(eating);
        pickLeftFork();
        pickRightFork();
        eat();
		putLeftFork();
        putRightFork();
    }
};