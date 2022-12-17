#include <iostream>
#include <string>


std::string sum(std::string A, std::string B)
{
    bool flag = false;
    std::string answer_sum, num_a, num_b;
    int calc, m;
    int len, r_B = 0, r_A = 0;

    if (A.size() > B.size())
    {
        len = A.size();
        r_B = A.size() - B.size();
    }
    else
    {
        len = B.size();
        r_A = B.size() - A.size();
    }

    for (int i = 1; i <= len; i++)
    {
        num_a = '0';
        num_b = '0';
        if (len - i - r_A > -1)
        {
            num_a = A[len - i - r_A];
        }
        if (len - i - r_B > -1)
        {
            num_b = B[len - i - r_B];
        }
        if (flag)
        {
            calc = std::stoi(num_a) + std::stoi(num_b) + 1;
            flag = false;
        }
        else
        {
            calc = std::stoi(num_a) + std::stoi(num_b);
        }
        if (calc > 9)
        {
            flag = true;
            calc -= 10;
        }
        answer_sum = std::to_string(calc) + answer_sum;

    }
    if (flag)
    {
        answer_sum = '1' + answer_sum;
        flag = false;
    }
    return answer_sum;
}


int main()
{
    setlocale(LC_ALL, "Russian");
    std::string A, B, answer_mult, num_a, num_b, c = "1";
    
    std::cin >> A >> B;

    std::cout << "сумма:" << sum(A, B) << std::endl;
    answer_mult = A;
    do
    {
        answer_mult = sum(answer_mult, A);
        c = sum(c, "1");
    }
    while (c != B);
    std::cout << "Произведение:" << answer_mult;
    return 0;
}
