#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <utility>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> answer;
        int i = 0, j = 0;
        while (i < words.size()) {
            // cout << i << " " << j << endl;
            int currentLength = 0;
            while (j < words.size() && currentLength + words[j].length() <= maxWidth) {
                currentLength += (words[j].length() + 1);
                j++;
            }
            string next;
            if (j == words.size()) {
                next.append(words[i++]);
                while (i < j) {
                    next += ' ';
                    next.append(words[i++]);
                }
                next.append(maxWidth-next.length(), ' ');
                answer.push_back(move(next));
                continue;
            }
            if (j - i == 1) {
                next = words[i];
                next.append(maxWidth-next.length(), ' ');
                answer.push_back(move(next));
                i++;
                continue;
            }
            currentLength -= 1;
            int wordCount = j - i;
            int totalWhiteSpaces = maxWidth - currentLength;
            int minSpaces = totalWhiteSpaces / (wordCount - 1);
            int howManyTakesExtra = totalWhiteSpaces % (wordCount - 1);
            while (howManyTakesExtra > 0) {
                next.append(words[i]);
                next.append(minSpaces+2, ' ');
                i++;
                howManyTakesExtra--;
            }
            while (i + 1 < j) {
                next.append(words[i]);
                next.append(minSpaces+1, ' ');
                i++;
            }
            next.append(words[i]);
            i++;
            // cout << "\"" << next << "\"" << endl;
            answer.push_back(move(next));
        }
        return answer;
    }
};

int main() {

    Solution sol;
    vector<string> v = {"What","must","be","shall","be."};
    vector<string> ans = sol.fullJustify(v, 16);
    for (const auto& s: ans)
        cout << "\"" << s << "\"" << endl;

    return 0;
}
