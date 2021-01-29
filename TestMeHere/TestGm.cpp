#include <iostream>
#include <string>
#include <vector>
#include <sstream> // for stringstream
#include <map>

using namespace std;

template <class T>
T findDuplicate(vector<T>& arr);

void ShowMeTheDuplicate();
void SayWhat();

int main() {

    ShowMeTheDuplicate();

    return 0;
}

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

    // one other way to find duplicate using map
    //while (getline(cin, line)) {
    //    string first = line.substr(0, line.find(";"));
    //    string last = line.substr(line.find(";") + 1);

    //    stringstream ss(last);
    //    string substr;

    //    while (getline(ss, substr, ',')) {
    //        result.push_back(substr);
    //    }
    //    // use map to iterate through the vector result.
    //    map<string, int> countMap;
    //    for (auto& elem : result) {
    //        auto test = countMap.insert(pair<string, int>(elem, 1));
    //        if (test.second == false)
    //            test.first->second++;
    //    }
    //    // find the duplicate from the map
    //    for (auto& elem : countMap) {
    //        if (elem.second > 1) {
    //            cout << elem.first << ", " << elem.second << endl;
    //            line = elem.first;
    //        }
    //    }
    //    cout << line << endl;
    //}

    // Still undergoing development
    // Give me back my change...
    //string test;
    //double Penny = 0.01, Nickel = 0.05, Dime = 0.10, Quarter = 0.25,
    //    Looney = 1.00, Twooney = 2.00, change = 0;

    //while (getline(cin, line)) {
    //    string pp = line.substr(0, line.find(delimeter));
    //    string ch = line.substr(line.find(delimeter) + 1);
    //    double result = stod(ch) - stod(pp);
    //    if (result >= Twooney) {
    //        change = result / Twooney;
    //        if (change >= 1) test += "Twooney,";
    //        if (result - Twooney > 0 && result - Twooney < Nickel) test += "Penny,";
    //    }
    //    setprecision(2);

    //    // cout << fixed << get_money(result) << endl;
    //    cout << fixed << result << endl;

    //    // line = to_string(result);

    //    cout << test << endl;
    //}