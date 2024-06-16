struct Car {
    int sp;
    int pos;
    double time;
};

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);
        // calulate the position after every second for every car
        // each second check if any cars have same pos and set their speeds to minimum of the fleet.
        // repeat this until target is reached.
        vector<Car> cars(position.size());
        for(int i = 0; i<position.size(); i++) {
            cars[i].sp = speed[i];
            cars[i].pos = position[i];
            cars[i].time = (target-cars[i].pos) * 1.0 / cars[i].sp;
        }
        sort(cars.begin(), cars.end(), [](auto& a, auto& b) {
            return a.pos < b.pos;
        });
        Car* prev = nullptr;
        int fleet = cars.size();
        for(int i = cars.size()-1; i >=0; i--) {
            if(!prev) {
                prev = &cars[i];
            }else {
                if(cars[i].time > prev->time) { // they will not intersect
                    prev = &cars[i];
                }else {
                    fleet--;
                }

            }
        }
        return fleet;
    }
};