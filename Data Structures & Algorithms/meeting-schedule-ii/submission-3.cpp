/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;

        // 1. On extrait directement les heures dans des vecteurs simples
        vector<int> starts;
        vector<int> ends;
        starts.reserve(intervals.size());
        ends.reserve(intervals.size());

        for (const auto& interval : intervals) {
            starts.push_back(interval.start);
            ends.push_back(interval.end);
        }

        // 2. On trie les deux vecteurs d'entiers indépendamment
        std::sort(starts.begin(), starts.end());
        std::sort(ends.begin(), ends.end());
        
        int s = 0;
        int e = 0;
        int count = 0;
        int res = 0;

        // 3. Ta boucle while avec les bonnes conditions
        while (s < intervals.size()) {
            if (starts[s] < ends[e]) { 
                // Une réunion commence avant qu'une salle ne se libère
                count++;
                s++;
            } else {
                // Une réunion se termine (ou s'enchaîne pile), une salle se libère
                count--;
                e++;
            }
            res = std::max(res, count);
        }

        return res;
    }
};
