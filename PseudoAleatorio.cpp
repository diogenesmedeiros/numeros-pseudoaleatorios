#include <iostream>
#include <chrono>
#include <cmath>

class LinearCongruentialGenerator {
private:
    int seed;
public:
    LinearCongruentialGenerator(int seed = 0) {
        if (seed == 0) {
            seed = static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::system_clock::now().time_since_epoch()).count()
            );
        }

        this->seed = seed;
    }

    int random() {
        int a = 1664525;
        int b = 1013904223;
        int m = std::numeric_limits<int>::max();

        this->seed = (a * this->seed + b) % m;

        return this->seed;
    }
};

int randint(int a, int b) {
    LinearCongruentialGenerator rng = LinearCongruentialGenerator();
    int rand_num = rng.random();

    return a + std::abs(rand_num) % (b - a + 1);
}

int main()
{
    while(true) {
        char choice;
        int n1, n2;
        int randomNum;

        std::cout << "\nEscolha uma das opcoes: \n 1 - Deixe que o computador gere de 1 a 1000 \n 2 - Voce define \n 3 - E (sair) \n User> ";
        std::cin >> choice;

        switch (choice)
        {
        case '1':
            randomNum = randint(1, 1000);
            break;
        case '2':
            std::cout << "Primeiro numero: ";
            std::cin >> n1;

            std::cout << "Segundo numero: ";
            std::cin >> n2;

            randomNum = randint(n1, n2);
            break;
        case 'E':
            std::cout << 'Bye' << std::endl;
            break;
        }

        std::cout << "Seu numero aleatorio foi " << randomNum << std::endl;
    }
}