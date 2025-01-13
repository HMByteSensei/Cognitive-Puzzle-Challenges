class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        std::unordered_map<std::string, std::pair<int, bool>> l1_map;
        for(int i=0; i<list1.size(); i++) {
            l1_map[list1[i]] = std::make_pair(i, false);
        }
        int min = std::numeric_limits<int>::max();
        for(int j=0; j<list2.size(); j++) {
            if(l1_map.find(list2[j]) != l1_map.end()) {
                int temp = l1_map[list2[j]].first + j;
                l1_map[list2[j]].first = temp;
                l1_map[list2[j]].second = true;
                if(min > temp) {
                    min = temp;
                }
            }
        }
        list1.clear();
        // for(auto &x : l1_map) {
        //     std::cout << x.second.first << " " << x.first << "\n";
        // }
        for(std::unordered_map<std::string, std::pair<int, bool>>::iterator it = l1_map.begin(); it != l1_map.end(); it++) {
            if(it->second.first == min && it->second.second) {
                list1.push_back(it->first);
            }
        }
        return list1;
    }
};
