// ============================================================
// SK하이닉스 코딩테스트 연습용 템플릿 (프로그래머스 스타일)
//
// 실제 시험은 "함수 완성형"입니다:
//   - main()을 직접 작성하지 않음
//   - 주어진 시그니처(반환형/매개변수)를 절대 바꾸지 않음
//   - 정답이 여러 개면 vector<T>에 담아 반환
//   - 주석 / 변수명 / 코드 스타일도 채점 요소이므로 평소에 습관화할 것
//
// 이 파일은 "로컬에서 테스트할 수 있도록" solution()과 별개로
// main()에 assert 기반 테스트케이스를 붙여둔 연습용 포맷입니다.
// 실제 제출 환경(프로그래머스)에서는 solution() 함수만 채점 대상입니다.
// ============================================================
#include <bits/stdc++.h>
using namespace std;

// ------------------------------------------------------------
// 문제: (여기에 문제 설명을 짧게 요약해서 적어두기)
// 시그니처: 실제 문제에서 주어지는 형태를 최대한 그대로 사용
// ------------------------------------------------------------
vector<int> solution(vector<int> arr) {
    vector<int> answer;

    // TODO: 풀이 작성
    // 1) 문제 조건 다시 읽고 엣지케이스 정리
    // 2) 시간복잡도 목표 정하기 (입력 크기 보고 역산)
    // 3) 구현

    return answer;
}

// ------------------------------------------------------------
// 로컬 테스트 (제출 시에는 제거하거나 주석 처리)
// ------------------------------------------------------------
void print_vec(const vector<int>& v) {
    cout << "[ ";
    for (int x : v) cout << x << " ";
    cout << "]";
}

int main() {
    struct Case { vector<int> input; vector<int> expected; };
    vector<Case> cases = {
        {{1, 2, 3}, {1, 2, 3}},   // TODO: 실제 기대값으로 교체
    };

    int pass = 0;
    for (size_t i = 0; i < cases.size(); ++i) {
        vector<int> got = solution(cases[i].input);
        bool ok = (got == cases[i].expected);
        cout << "case " << i + 1 << ": " << (ok ? "PASS" : "FAIL") << "  got=";
        print_vec(got);
        cout << "  expected=";
        print_vec(cases[i].expected);
        cout << "\n";
        if (ok) pass++;
    }
    cout << pass << "/" << cases.size() << " passed\n";
    return 0;
}
