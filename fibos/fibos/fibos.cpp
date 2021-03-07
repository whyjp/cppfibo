// fibos.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stack>
#include <chrono>
#include <vector>

int Recur_fibo(int n) {
    if (n < 2) {
        return n;
    }
    return Recur_fibo(n - 1) + Recur_fibo(n - 2);
}
int DP_fibo(int n) {
    std::vector<int> vec(n + 1);

    vec[0] = 0;
    vec[1] = 1;

    for (int i = 2; i <= n; ++i) {
        vec[i] = vec[i - 1] + vec[i - 2];
    }
    return vec[n];
}
int main()
{
    auto before_Recur = std::chrono::high_resolution_clock::now();
    std::cout << "Recur_fibo :" << Recur_fibo(100) << std::endl;
    std::chrono::duration<double> sec = std::chrono::high_resolution_clock::now() - before_Recur;
    std::cout << "Recur_fibo duration : " << sec.count() << std::endl;

    std::cout << "--------------------------------" << std::endl;

    auto before_DP = std::chrono::high_resolution_clock::now();
    std::cout << "DP_fibo :" << DP_fibo(100) << std::endl;
    std::chrono::duration<double> sec2 = std::chrono::high_resolution_clock::now() - before_DP;
    std::cout << "DP_fibo duration : " << sec2.count() << std::endl;


    getchar();
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
