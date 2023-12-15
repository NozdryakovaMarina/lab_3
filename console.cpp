#include "sorting.cpp"
#include <iostream>
#include <vector>

using namespace std;
using namespace sorting;

int main() {

	//vector<int> arr{ 12, 17, 13, 6, 2, 19, 18, 10, 8, 4, 9, 7, 3, 15, 20, 1, 11, 14, 5, 16 };
	//cout << arr << endl;
	//cout << insert_sort(arr);
	//cout << arr << endl << endl;


	//vector<int> arr1{ 12, 17, 13, 6, 2, 19, 18, 10, 8, 4, 9, 7, 3, 15, 20, 1, 11, 14, 5, 16 };
	//cout << arr1 << endl;
	//cout << quick_sort(arr1);
	//cout << arr1 << endl << endl;

	//vector<int> arr2{ 12, 17, 13, 6, 2, 19, 18, 10, 8, 4, 9, 7, 3, 15, 20, 1, 11, 14, 5, 16 };
	//cout << arr2 << endl;
	//cout << comb_sort(arr2);
	//cout << arr2 << endl << endl;

	vector<size_t> size{ 1000,2000,3000,4000,5000,6000,7000,8000,9000,10000,25000,50000,100000 };

	//for (size_t i = 0; i < size.size(); ++i) {
	//	stats stat = average_stats(size[i], insert_sort);
	//	stats stat1 = average_stats(size[i], quick_sort);
	//	stats stat2 = average_stats(size[i], comb_sort);
	//	cout << stat;
	//}

	//vector<string> arr{"Hamlet","Moby-Dick","Pygmalion","Airport","Dune","Misery","Inferno","Prestige","Genius","Hobbit"};
	//cout << arr << endl;
	//cout << insert_sort(arr);
	//cout << quick_sort(arr);
	//cout << comb_sort(arr);
	//cout << arr << endl << endl;

	//vector<Books> books{ Books("Hamlet", 250), Books("Moby-Dick", 512),Books("Pygmalion", 448),Books("Airport", 608),Books("Dune",704),Books("Misery", 416),Books("Inferno", 550),Books("Prestige", 464), Books("Genius", 1024), Books("Hobbit", 252) };
	//cout << books << endl;
	//cout << insert_sort(books);
	//cout << quick_sort(books);
	//cout << comb_sort(books);
	//cout << books << endl;

	return 0;
}