#include <vector>
#include <algorithm>

class Solution {
public:
    int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
        int numOfCars = position.size();
        std::vector<std::pair<int, double>> cars;
        for (int i = 0; i < numOfCars; i++) {
            double eta = (double) (target - position[i]) / speed[i];
            cars.push_back({position[i], eta});
        }

        sort(cars.begin(), cars.end());

        int result = 0;
        double maxTime = 0.0;
        for (int i = numOfCars - 1; i >= 0; i--) {
            if (cars[i].second > maxTime) {
                maxTime = cars[i].second;
                result++;
            }
        }

        return result;
    }
};