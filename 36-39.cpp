#include <iostream>
#include <ctime> 
#include <chrono>
#include <thread>
#include <iomanip>

void program0()
{
    srand(time(0));
    int answer;
    int correct = 0;

    for (int i = 0; i < 10; ++i) 
    {
        int a = 2 + rand() % 8;
        int b = 2 + rand() % 8;
        std::cout << a << " * " << b << " = ";
        auto start = std::chrono::high_resolution_clock::now();
        std::cin >> answer;
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;

        // проверка, что были введены числа
        if (std::cin.fail()) // извлечение не производилось
        {
            std::cout << "\nInput error!!!";
            // сбрасываем биты состояния обратно в goodbit, чтобы мы могли использовать ignore()
            std::cin.clear();
            // очищаем недопустимый ввод из потока
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return;
        }

        if (elapsed.count() > 20.0) 
        {
            std::cout << "Time is up!\n";
            break;
        }
        if (answer == a * b) {
            ++correct;
        }
    }

    if (correct == 10) 
    {
        std::cout << "Exellent!\n";
    }
    else if (correct == 9) 
    {
        std::cout << "Good!\n";
    }
    else if (correct == 7 || correct == 8) 
    {
        std::cout << "Satisfactory!\n";
    }
    else 
    {
        std::cout << "Unsatisfactory!\n";
    }
}

void program1()
{
    std::string M[] = { "", "M", "MM", "MMM" };
    std::string C[] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
    std::string X[] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
    std::string I[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };

    int num;
    std::cout << "Convert arabic number to roman, enter your number in range [1, 3999]: ";
    std::cin >> num;

    // проверка, что были введены числа
    if (std::cin.fail()) // извлечение не производилось
    {
        std::cout << "\nInput error!!!";
        // сбрасываем биты состояния обратно в goodbit, чтобы мы могли использовать ignore()
        std::cin.clear();
        // очищаем недопустимый ввод из потока
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    if (num < 1 || num > 3999)
    {
        std::cout << "Your number is out of range!";
        return;
    }

    std::string thousands = M[num / 1000];
    std::string hundreds = C[(num % 1000) / 100];
    std::string tens = X[(num % 100) / 10];
    std::string ones = I[num % 10];

    std::string result = thousands + hundreds + tens + ones;

    std::cout << "Roman number: " << result << std::endl;
}

void program2()
{
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            if (i * j < 10)
            {
                std::cout << " " << i * j << "  ";
            }
            else
            {
                std::cout << i * j << "  ";
            }
        }
        std::cout << "\n";
    }
}

void program3()
{
    int miles = 1;
    int km;
    std::cout << "Enter number of km: ";
    std::cin >> km;

    // проверка, что были введены числа
    if (std::cin.fail()) // извлечение не производилось
    {
        std::cout << "\nInput error!!!";
        // сбрасываем биты состояния обратно в goodbit, чтобы мы могли использовать ignore()
        std::cin.clear();
        // очищаем недопустимый ввод из потока
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\n|    Miles    |    Km    |";
    std::cout << "\n-------------------------";

    for (int i = 1; i <= km; i++)
    {
        if (i / 1.6093 < miles)
            std::cout << "\n| " << std::setw(10) << i / 1.6093 << " | " << std::setw(6) << i << " |";

        else
        {
            if (miles * 1.6093 <= km)
            {
                std::cout << "\n| " << std::setw(10) << miles << " | " << std::setw(6) << miles * 1.6093 << " |";
                if (i <= km)
                    std::cout << "\n| " << std::setw(10) << i / 1.6093 << " | " << std::setw(6) << i << " |";
                miles++;
            }
        }
    }
}





int main()
{
    bool answer;

    //program0(); //36 [
    //program1(); //37 [
    //program2(); //38 [
    //program3(); //39 [

    std::cout << "\nOne more? (1 - yes, 0 - no): ";
    std::cin >> answer;

    if (answer)
    {
        main();
    }
    return 0;
}
