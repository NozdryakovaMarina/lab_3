#include "sorting.cpp"

using namespace sorting;

int main() {

	vector<int> arr{ 12, 17, 13, 6, 2, 19, 18, 10, 8, 4, 9, 7, 3, 15, 20, 1, 11, 14, 5, 16 };
	cout << arr << endl;
	cout << insert_sort(arr);
	cout << arr << endl << endl;


	vector<int> arr1{ 12, 17, 13, 6, 2, 19, 18, 10, 8, 4, 9, 7, 3, 15, 20, 1, 11, 14, 5, 16 };
	cout << arr1 << endl;
	cout << quick_sort(arr1);
	cout << arr1 << endl << endl;

	vector<int> arr2{ 12, 17, 13, 6, 2, 19, 18, 10, 8, 4, 9, 7, 3, 15, 20, 1, 11, 14, 5, 16 };
	cout << arr2 << endl;
	cout << combSort(arr2);
	cout << arr2 << endl << endl;
	return 0;
}