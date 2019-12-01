// Exploring fumction.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>

typedef float typeOfAns;

using funcType = typeOfAns(*)(typeOfAns);



// метод половинного деления
float methodOfHalfDiv(funcType f) {
	typeOfAns a, b, eps, c;
	while ( b - a > 2 * eps) {
		c = (a + b) / 2;
		if (f(a) * f(c) < 0)
			b = c;
		else
			if (f(b) * f(c) < 0)
				a = c;
	}
	return (a + b) / 2;
}



// метод хорд и касательных 
// f - функция, ffd(function first derivative) - ее первая производная, fsd(function second derivative) - ее вторая производная
float methodOfChordsAndTangets(funcType f, funcType ffd, funcType fsd) {
	typeOfAns a, b, eps;
	while (b - a > 2 * eps) {
		if (f(a) * fsd(a) > 0) {
			typeOfAns d = a - f(a) / ffd(a);
			typeOfAns c = (a * f(b) - b * f(a)) / (f(b) - f(a));
			a = d;
			b = c;
		}
		else
			if (f(b) * fsd(b) > 0) {
				typeOfAns d = b - f(b) / ffd(b);
				typeOfAns c = (a * f(b) - b * f(a)) / (f(b) - f(a));
				b = d;
				a = c;
			}
	}
	return (a + b) / 2;
}



int main()
{
	funcType f1 = [](typeOfAns x)->typeOfAns {
		return 8 * x + 8 + pow(5, x);
	};
	funcType f2 = [](typeOfAns x)->typeOfAns {
		return 5 * pow(x, 3) + 2 * pow(x, 2) - 4;
	};
	funcType f2fd = [](typeOfAns x)->typeOfAns {
		return 15 * pow(x, 2) + 2 * x;
	};
	funcType f2sd = [](typeOfAns x)->typeOfAns {
		return 30 * x + 4;
	};



}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
