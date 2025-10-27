#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int tinh_chiphi(int age, int h) {
    if (age < 13 || age > 30 || h <= 0 || h > 8)
        return -1;

    if (age < 18) {
        if (h < 4)
            return h * 50000;
        else
            return (h - 4) * 25000 + 200000;
    }

    if (h < 4)
        return h * 100000;
    else
        return (h - 4) * 50000 + 400000;
}

int main() {
    ifstream fin("testdongdulieu.txt");
    if (!fin) {
        cerr << "Khong mo duoc file input.txt\n";
        return 1;
    }

    string line;
    int test_passed = 0, test_total = 0;

    while (getline(fin, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        int id, age, h, expected;
        char comma;
        string temp;

        // Đọc ID
        ss >> id;
        ss >> temp; // đọc "age,h"
        size_t pos = temp.find(',');
        age = stoi(temp.substr(0, pos));
        h = stoi(temp.substr(pos + 1));

        ss >> expected;

        int result = tinh_chiphi(age, h);
        bool pass = (result == expected);
        test_total++;

        cout << "Test " << id << ": age=" << age << ", h=" << h
             << " => result=" << result << ", expected=" << expected
             << " --> " << (pass ? "PASS" : "FAIL") << endl;

        if (pass) test_passed++;
    }

    cout << "\nTong ket: " << test_passed << "/" << test_total << " test PASS.\n";
    return 0;
}
