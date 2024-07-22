
class Solution {
public:
    struct Person {
        std::string name;
        int height;
    };

    static bool compare(const Person &a, const Person &b) {
        return a.height > b.height;
    }

    std::vector<std::string> sortPeople(std::vector<std::string>& names, std::vector<int>& heights) {
        int n = names.size();
        std::vector<Person> people(n);

        for (int i = 0; i < n; ++i) {
            people[i] = {names[i], heights[i]};
        }

        std::sort(people.begin(), people.end(), compare);

        std::vector<std::string> sortedNames(n);
        for (int i = 0; i < n; ++i) {
            sortedNames[i] = people[i].name;
        }

        return sortedNames;
    }
};

