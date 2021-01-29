// Console Application
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>

using namespace std;

int factorial(int n)
{
    int result = 1;

    for (int i = 1; i <= n; i++)
        result *= i;

    return result;
}

bool containsDuplicate(vector<int>& nums) {
    for (int i = 0; i < (signed)nums.size(); i++)
        for (int j = i + 1; j < (signed)nums.size(); j++)
            if (nums[i] == nums[j])
                return true;
    return false;
}

int removeDuplicate(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    int i = 0;
    for (int j = 1; j < (signed)nums.size(); j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1;
}

vector<int> countElements(vector<int>& nums) {
    vector<int> output;
    int length = (signed)nums.size();
    if (length == 0) return output;

    for (int j = 0; j < length; j++) {
        int count = 1;
        while (j + 1 < length && (nums[j] == nums[j+1])) {
                ++count;
                ++j;
        }
        output.push_back(count);
        output.push_back(nums[j]);
    }

    return output;
}

vector<int> rotateRight(vector<int>& nums, int k) {
    int first = nums[0], next = 0;
    for (int i = 0; i < k; i++) {
        for (int x = 0; x < (signed)nums.size() - 1; x++) {
            next = nums[x + 1];
            nums[x + 1] = first;
            first = next;
        }
    }
    nums[0] = first;
    return nums;
}

vector<char> rotateStringRight(vector<char>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        char tmp = nums[left];
        nums[left++] = nums[right];
        nums[right--] = tmp;
    }

    return nums;
}

vector<int> rotateLeft(vector<int>& nums, int k) {
    int first = 0, next = 0, last = 0;
    for (int i = 0; i < k; i++) {
        last = nums[0];
        for (int x = 0; x < (signed)nums.size() - 1; x++) {
            first = nums[x];
            next = nums[x + 1];
            nums[x] = next;
        }
        nums[(signed)nums.size() - 1] = last;
    }
    return nums;
}

int reverseInteger(int x) {
    long num = 0;
    int rem = 0;
    while (x)
    {
        rem = x % 10;
        num = num * 10 + rem;
        x = x / 10;
    }
    return (num > INT_MAX || num < INT_MIN) ? 0 : num;
}

int myAtoi(string str) {
    int i = 0;
    int sign = 1;
    int result = 0;
    if (str.length() == 0) return 0;

    //Discard whitespaces in the beginning
    while (i < (signed)str.length() && str[i] == ' ')
        i++;

    // Check if optional sign if it exists
    if (i < (signed)str.length() && (str[i] == '+' || str[i] == '-'))
        sign = (str[i++] == '-') ? -1 : 1;

    // Build the result and check for overflow/underflow condition
    while (i < (signed)str.length() && str[i] >= '0' && str[i] <= '9') {
        if (result > INT_MAX / 10 ||
            (result == INT_MAX / 10 && str[i] - '0' > INT_MAX % 10)) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
        result = result * 10 + (str[i++] - '0');
    }
    return result * sign;
}

bool isNumber(string s) {

    int i = 0;
    if (s[i] == '-' || s[i] == '+')
        i++;

    int digits = 0;
    int dots = 0;
    while (i < (signed)s.length() && (s[i] == '.' || isdigit(s[i])))
        isdigit(s[i++]) ? digits++ : dots++;

    if (dots > 1 || digits == 0)
        return false;

    digits = 0;
    dots = 0;
    if (s[i] == 'e' || s[i] == 'E')
    {
        i++;
        if (s[i] == '-' || s[i] == '+')
            i++;
        while (i < (signed)s.length() && (s[i] == '.' || isdigit(s[i])))
            isdigit(s[i++]) ? digits++ : dots++;

        if (digits == 0 || dots > 0)
            return false;
    }

    return i == s.length();

}

//int *decimalToBinary(int num) {
//    int bin[10];
//    for (int i = 0; num > 0; i++) {
//        bin[i] = num % 2;
//        num = num / 2;
//    }
//    return bin;
//}

void testList() {
    list<int> ll = {7,5,16,8};
    ll.push_front(25); // add to front
    ll.push_back(13); // add to back
    // add before 16
    auto it = find(ll.begin(), ll.end(), 16);
    if (it != ll.end())
        ll.insert(it, 42);

    // Print out the list
    for (int n : ll) 
        cout << n << ", ";
    cout << "\n";
    cout << "List length: " << ll.size() << endl;
}

int OldMain()
{
    // int *y = decimalToBinary(24);

    testList();

    string s = "Hello, World!";

    string p = "";
    int count = s.length();

    p += to_string(count) + s;

    cout << p << endl;

    vector<char> ch = {'h', 'e', 'l', 'l', 'o'};

    vector<char> test = rotateStringRight(ch);

    // 32-bit integer - -2,147,483,648 to +2,147,483,647
    int tt = reverseInteger(-1463847412);

    vector<int> arr = { 1,2,3,4,5,6 };

    vector<int> output = rotateLeft(arr,2);

    for (int i = 0; i < (signed)output.size(); i++)
        cout << output[i] << ", ";
    cout << endl;
    cout << "Length: " << output.size();
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, 
// or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, 
// go to File > Open > Project and select the .sln file
