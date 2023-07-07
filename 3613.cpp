#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// java의 변수인지 판단하는 함수. 대문자가 있으면 true로 간주한다.
bool isJava(const string& str) {
    for (const auto& x : str)
        if (isupper(x)) return true;

    return false;
}

// C++의 변수인지 판단하는 함수. '_'가 있으면 true로 간주한다.
bool isCpp(const string& str) {
    for (const auto& x : str)
        if (x == '_') return true;
    
    return false;
}

// 위 두 함수로 잡지 못하는 모든 예외를 처리한다.
bool isError(const string& str) {
    // '_'와 대문자가 혼재되있는지 판단한다.
    bool underbar = false;
    bool upper = false;

    for (const auto& x : str) {
        if (x == '_') underbar = true;
        else if (isupper(x)) upper = true;
    }

    if (underbar && upper) return true; // 여기서 return이 발생한다는 것은 대문자와 '_'가 모두 있다는 뜻.

    // 첫 문자가 대문자거나 '_'인지 판단한다.
    else if (isupper(str[0]) || str[0] == '_') return true; 

    // 마지막 문자가 '_'인지 판단한다.    
    else if (*(str.end() - 1) == '_') return true;

    // '_'이 연속해서 나오는지 판단한다.
    for (int i = 0; i < str.length() - 1; ++i)
        if (str[i] == '_' && str[i + 1] == '_') return true;

    // 이 모든 경우를 통과했다면 Error가 아니다.
    return false;
}

// Java형식의 변수를 C++형식으로 바꾼다.
string JtoC(const string& var) {
    string str = "";
    for (const auto& x : var) {
        if (isupper(x)) { // 대문자인 경우
            str += '_'; // '_'를 붙이고
            str += tolower(x); // 소문자로 바꿔서 붙인다.
        }
        else str += x; // 소문자라면 그냥 붙인다.
    }
    return str;
}

string CtoJ(const string& var) {
    string str = "";
    bool changeFlag = false; // 대문자로 바꿔야 하는지 판단할 변수

    for (const auto& x : var) {
        if (x == '_') changeFlag = true; // '_'인 경우, 붙이지 않고 다음 문자를 대문자로 붙인다.
        else {
            if (changeFlag) { // 대문자로 바꿔야 한다면
                str += toupper(x); // 대문자로 바꿔서 붙이고
                changeFlag = false; // 다음 문자는 소문자로 바꿔쓴다.
            }
            else str += x; // 바꿀 필요가 없으면 그냥 소문자로 붙인다
        }
    }
    return str;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string varName;

    cin >> varName;

    if (isError(varName))
        cout << "Error!";

    else if (isCpp(varName))
        cout << CtoJ(varName);

    else if (isJava(varName))
        cout << JtoC(varName);

    else cout << varName;
}