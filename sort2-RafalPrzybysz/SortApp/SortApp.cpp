#include <iostream>
#include <ostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include "benchmark.h"
#include "../SortLib/BubbleSort.h"
#include "../SortLib/InsertionSort.h"
#include "../SortLib/SelectionSort.h"
#include "../SortLib/MergeSort.h"
#include "../SortLib/QuickSort.h"

int main()
{
	setlocale(LC_ALL, "pl-pl");
	std::vector<size_t> s = { 50000, 100000,150000, 200000, 300000, 400000, 500000, 600000, 800000, 1000000 };
	for (auto n : s)
	{
		std::vector<unsigned int> v;

		// wygenerowanie losowej zawartoœci kolekcji
		/*size_t n;
		std::cout << "Podaj liczbê elementów:";
		std::cin >> n;*/

		// wygenerowanie losowej zawartoœci kolekcji
		auto seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::mt19937 generator((unsigned int)seed);

		for (size_t i = 0; i < n; i++)
			v.push_back(generator() /*% 1000*/);

		//std::sort(v.begin(), v.end());

		// wyœwietlenie zawartoœci kolekcji przed sortowaniem
		/*std::cout << "Kolekcja nieposortowana:" << std::endl;
		for (auto value : v)
			std::cout << value << std::endl;
		std::cout << std::endl;*/

		Benchmark<std::chrono::nanoseconds> b;
		//bubbleSort(v.begin(), v.end());
		mergeSort(v.begin(), v.end()/*, 1000U*/);
		auto t = b.elapsed();

		// wyœwietlenie zawartoœci kolekcji po posortowaniu
		/*std::cout << "Kolekcja posortowana:" << std::endl;
		for (auto value : v)
			std::cout << value << std::endl;
		std::cout << std::endl;*/

		std::cout << t << std::endl;
	}
}
