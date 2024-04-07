#include <vector>
#include <queue>
#include <algorithm>
class Solution {
public:
    int leastInterval(std::vector<char>& tasks, int n) {
        std::priority_queue<int> pq;
        std::queue<std::pair<int, int>> q;
        std::vector<int> freq(26, 0);

        int tasks_size = tasks.size();
        for (int i = 0; i < tasks_size; i++) ++freq[tasks[i] - 'A'];
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) pq.push(freq[i]);
        }

        int cycle = 0;
        while (!pq.empty() || !q.empty()) {
            ++cycle;
            if (!pq.empty()) {
                int l = pq.top() - 1;
                if (l != 0) q.push({l, cycle + n});
                pq.pop(); 
            }
            if (!q.empty() && q.front().second == cycle) {
                pq.push(q.front().first);
                q.pop();
            }
        }

        return cycle;
    }

    int leastInterval1(std::vector<char>& tasks, int n) {
        std::vector<int> freq(26, 0);
        int tasks_size = tasks.size();
        int max = 0;
        int max_count = 0;
        for (int i = 0; i < tasks_size; i++) {
            ++freq[tasks[i] - 'A'];

            if (freq[tasks[i] - 'A'] == max) {
                max_count++;
            } else if (freq[tasks[i] - 'A'] > max) {
                max = freq[tasks[i] - 'A'];
                max_count = 1;
            }
        }

        int parts = max - 1;
        int part_length = n - max_count + 1;
        int idles = std::max(0, parts * part_length - (int)(tasks.size() - max * max_count));

        return tasks.size() + idles;
    }
};