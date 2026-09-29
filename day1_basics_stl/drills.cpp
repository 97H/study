// ============================================================
// Day1 STL 기초 드릴
// 각 함수의 TODO 부분만 채우면 됩니다. 채점은 main()의 assert가 자동으로 함.
// 순서대로 풀어보세요: vector -> string -> sort -> map
// 막히면 PROBLEMS.md에 없는 개념이라도 상관없음, 이 파일 자체가 학습용입니다.
// ============================================================
#include <bits/stdc++.h>
using namespace std;

// ---------- [A] vector ----------

// A1. 벡터의 모든 원소 합을 구하기
int sumVector(vector<int> v) {
    int answer = 0;
    for (int x : v) {
        answer += x;
    }
    return answer;
}

// A2. 벡터를 뒤집어서 반환 (STL reverse 쓰지 말고 직접 구현해볼 것)
vector<int> reverseVector(vector<int> v) {
    vector<int> answer;
    // TODO: v의 뒤에서부터 answer에 채워넣기
    for (int i = (int)v.size() - 1; i>=0 ; i--) {
        answer.push_back(v[i]);
    }
    return answer;
}

// A3. 중복 제거 후 오름차순 정렬해서 반환
vector<int> uniqueSorted(vector<int> v) {
    vector<int> answer;
    // TODO: sort 후 중복 없이 answer에 담기
    // 힌트: sort(v.begin(), v.end()) 후 앞뒤 값 비교하며 채우기
    sort(v.begin(), v.end());
    for (int x : v) {
        if (answer.empty() || answer.back() != x) {
            answer.push_back(x);
        }
    }
    return answer;
}

// ---------- [B] string ----------

// B1. 문자열에서 특정 문자 c의 개수 세기
int countChar(string s, char c) {
    int answer = 0;
    for (char ch : s) {
        if (ch == c) answer++;
    }
    return answer;
}

// B2. 문자열이 팰린드롬(앞뒤로 읽어도 같음)인지 판별
bool isPalindrome(string s) {
    // TODO: 양 끝에서 좁혀가며 비교 (투 포인터 살짝 맛보기)
    int left = 0, right = (int)s.size() -1;
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}

// B3. 공백 기준으로 문자열을 쪼개서 vector<string>으로 반환
vector<string> splitBySpace(string s) {
    vector<string> answer;
    stringstream ss(s);
    string word;
    while (ss >> word) {
        answer.push_back(word);
    }
    return answer;
}

// ---------- [C] sort ----------

// C1. 절댓값 기준 오름차순 정렬 (절댓값 같으면 원래 값이 작은 게 먼저)
vector<int> sortByAbs(vector<int> v) {
    sort(v.begin(), v.end(), [](int a, int b) {
        if (abs(a) != abs(b)) return abs(a) < abs(b);
        return a < b;
    });
    return v;
}

// ---------- [D] map ----------

// D1. 단어 리스트에서 가장 많이 등장한 단어 반환 (동점이면 아무거나)
string mostFrequentWord(vector<string> words) {
    unordered_map<string, int> cnt;
    for (const string& w : words) {
        cnt[w]++;
    }

    string answer;
    int best = -1;
    for (const auto& [word, count] : cnt) {
        if (count > best) {
            best = count;
            answer = word;
        }
    }
    return answer;
}

// ============================================================
// 테스트 하네스 — 여기는 수정할 필요 없음
// ============================================================
template<typename T>
void check(const string& name, T got, T expected) {
    bool ok = (got == expected);
    cout << (ok ? "[PASS] " : "[FAIL] ") << name;
    if (!ok) {
        cout << "  (결과가 기대값과 다름)";
    }
    cout << "\n";
}

int main() {
    check("A1 sumVector", sumVector({1, 2, 3, 4}), 10);
    check("A2 reverseVector", reverseVector({1, 2, 3}), vector<int>{3, 2, 1});
    check("A3 uniqueSorted", uniqueSorted({3, 1, 2, 1, 3}), vector<int>{1, 2, 3});

    check("B1 countChar", countChar("banana", 'a'), 3);
    check("B2 isPalindrome true", isPalindrome("level"), true);
    check("B2 isPalindrome false", isPalindrome("hello"), false);
    check("B3 splitBySpace", splitBySpace("hi there world"),
          vector<string>{"hi", "there", "world"});

    check("C1 sortByAbs", sortByAbs({-3, 1, -2, 2}), vector<int>{1, -2, 2, -3});

    check("D1 mostFrequentWord", mostFrequentWord({"a", "b", "a", "c", "a"}), string("a"));

    return 0;
}
