#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;

class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        stringstream ss;
        for (auto& s: strs) {
            ss << "<" + to_string(s.length()) + ">";
            ss << s;
        }
        return ss.str();
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        istringstream iss(s);
        vector<string> result;
        iss.peek();
        while (!iss.eof()) {
            int length = getLength(iss);
            string element;
            while (length-- > 0) {
                element.push_back(iss.get());
            }
            result.push_back(element);
            iss.peek();
        }
        return result;
    }

private:
    int getLength(istringstream& iss) {
        assert(iss.peek() == '<');
        iss.ignore();
        int length;
        iss >> length;
        assert(iss.peek() == '>');
        iss.ignore();
        return length;
    }
};

int main() {

    Codec codec;
    vector<string> vs = {
        ""
    };
    string encoded = codec.encode(vs);
    cout << "encoded" << endl << encoded << endl;
    auto newVs = codec.decode(encoded);
    for (auto& s: newVs) {
        cout << s << endl;
    }

    return 0;
}