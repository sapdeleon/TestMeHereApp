#include "gmsubs.h"

template <class T>
T findDuplicate(vector<T>& arr) {
    T result = "";

    if (arr.size() == 0) return result;
    for (int x = 0; x < (signed)arr.size(); x++) {
        for (int y = x + 1; y < (signed)arr.size(); y++) {
            if (arr[x] == arr[y])
                return arr[x];
        }
    }

    return result;
}

void ShowMeTheDuplicate() {
    // test vector<string> array
    // vector<string> arr = {"1","2","3","4","5","3","6","7"};
    string line;

    // this one works...
    // check as well if user does not enter anything - save from crashing...
    while (getline(cin, line) && line != "")
    {
        string first = line.substr(0, line.find(";"));
        string last = line.substr(line.find(";") + 1);

        vector<string> arr;
        stringstream ss(last);
        string substr;

        // gather all the elements here...
        while (getline(ss, substr, ',')) {
            arr.push_back(substr);
        }
        line = findDuplicate(arr);

        cout << line << endl;
    }
}

void SayWhat() {
    //reverse the string input - Hello World --> World Hello
    string line;
    string delimeter = " ";

    while (getline(cin, line) && line != "") {
        string first = line.substr(0, line.find(delimeter));
        string last = line.substr(line.find(delimeter) + 1);
        line = last + delimeter + first;
        cout << line << endl;
    }
}