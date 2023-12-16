#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include <random>
#include <stack>

using namespace std;

namespace sorting {
   
   class Books {
   private:
	   string _name;
	   int _pages;
   public:
	   Books() : _name(""), _pages(0) {}
	   Books(string n, int p): _name(n), _pages(p) {}

	   string get_name() const { return _name; }
	   int get_pages() const { return _pages; }

	   bool operator==(const Books& other)const {
		   return _name == other._name && _pages == other._pages;
	   }

	   bool operator<(Books& rhs) {
		   return _pages < rhs._pages;
	   }
	   bool operator>(Books& rhs) {
		   return _pages > rhs._pages;
	   }
   };

   ostream& operator<<(ostream& os, const Books& b) {
	   os << b.get_name() << ": " << b.get_pages() << "pg" << endl;
	   return os;
   }

   struct stats {
	   size_t comparison_count = 0;
	   size_t copy_count = 0;

	   stats& operator+=(const stats& stats) {
		   comparison_count += stats.comparison_count;
		   copy_count += stats.copy_count;
		   return *this;
	   }
   };

   ostream& operator<<(ostream& os, const stats& stats) {
	   os << "Number of comparison: " << stats.comparison_count << " | " << "Number of copies: " << stats.copy_count << endl;
	   return os;
   }

   template<typename T>
   void swap(T& a, T& b) {
	   T temp = a;
	   a = b;
	   b = temp;
   }

   template<typename T>
   stats insert_sort(vector<T>& mas) {
	   stats stats;
	   for (int i = 1; i < mas.size(); i++) {
		   for (int j = i; j > 0; j--) {
			   stats.comparison_count++;
			   if (mas[j - 1] > mas[j]) {
				   swap(mas[j - 1], mas[j]);
				   stats.copy_count += 2;
			   }
		   }
	   }
	   return stats;
   }
    
   /*template<typename T>
   int partition(std::vector<T>& arr, int low, int high, stats& s) {
	   T pivot = arr[high];
	   int i = (low - 1);
	   for (int j = low; j <= high - 1; j++) {
		   s.comparison_count++;
		   if (arr[j] < pivot) {
			   i++;
			   std::swap(arr[i], arr[j]);
			   s.copy_count++;
		   }
	   }
	   std::swap(arr[i + 1], arr[high]);
	   s.copy_count++;
	   return (i + 1);
   }

   template<typename T>
   void quick_sort(std::vector<T>& arr, int low, int high, stats& s) {
	   if (low < high) {
		   int pi = partition(arr, low, high, s);
		   quick_sort(arr, low, pi - 1, s);
		   quick_sort(arr, pi + 1, high, s);
	   }
   }

   template<typename T>
   stats quick_sort(std::vector<T>& arr) {
	   stats s;
	   quick_sort(arr, 0, arr.size() - 1, s);
	   return s;
   }*/

   template<class T>
   stats quick_sort(std::vector<T>& arr) {
	   stats stat;
	   std::stack<T> stack;
	   stack.push(0);
	   stack.push(arr.size() - 1);

	   while (!stack.empty()) {
		   int high = stack.top();
		   stack.pop();
		   int low = stack.top();
		   stack.pop();

		   T pivot = arr[high];
		   int i = low - 1;

		   for (int j = low; j <= high - 1; j++) {
			   stat.comparison_count++;
			   if (arr[j] <= pivot) {
				   i++;
				   stat.copy_count++;
				   std::swap(arr[i], arr[j]);
			   }
		   }
		   stat.copy_count++;
		   std::swap(arr[i + 1], arr[high]);

		   int p = i + 1;

		   if (p - 1 > low) {
			   stack.push(low);
			   stack.push(p - 1);
		   }

		   if (p + 1 < high) {
			   stack.push(p + 1);
			   stack.push(high);
		   }
	   }

	   return stat;
   }

   template<typename T>
   stats comb_sort(vector<T>& arr) {
	   stats s;
	   int n = arr.size();
	   int gap = n;
	   bool swapped = true;

	   while (gap != 1 || swapped) {
		   gap = (gap * 10) / 13;
		   if (gap < 1) {
			   gap = 1;
		   }
		   swapped = false;
		   for (int i = 0; i < n - gap; i++) {
			   s.comparison_count++;
			   if (arr[i] > arr[i + gap]) {
				   swap(arr[i], arr[i + gap]);
				   s.copy_count++;
				   swapped = true;
			   }
		   }
	   }
	   return s;
   }


   template<typename T>
   ostream& operator<<(ostream& os, const vector<T>& arr) {
	   for (int i = 0; i < arr.size(); i++)
		   os << arr[i] << " ";
	   return os;
   }


   template <typename T>
   T random(T a, T b)
   {
	   std::random_device random_device;
	   std::mt19937 generator(random_device());
	   std::uniform_int_distribution<> segment(a, b);
	   T x = segment(generator);
	   return x;
   }

   template<typename T>
   vector<T> random_arr(size_t size) {
	   vector<T> arr;
	   int min = 1;
	   int max = 100000;
	   for (int i = 0; i < size; ++i)
		   arr.push_back(random(min, max));
	   return arr;
   }

   std::vector<int> random_seed(int a, int b, int n, int seed) {
	   std::vector<int> res;
	   std::mt19937 generator(seed);
	   std::uniform_int_distribution<> distribution(a, b);
	   for (int i = 0; i < n; i++) {
		   int x = distribution(generator);
		   res.push_back(x);
	   }
	   return res;
   }

   template <typename T>
   stats average_stats(size_t size, stats(*sorted_f)(vector<T>& arr)) {
	   stats average;
	   int c = 5;
	   for (int i = 0; i < c; i++) {
		   vector<T> arr = random_arr<int>(size);
		   average += sorted_f(arr);
		   cout << i << " " << size << endl;
	   }

	   average.comparison_count /= c;
	   average.copy_count /= c;

	   return average;
   }

   template<typename T>
   vector<T> sorted_arr(size_t size) {
	   vector<T> arr;
	   for (int i = 0; i < size; i++)
		   arr.push_back(i);
	   return arr;
   }

   template<typename T>
   vector<T> reverse(size_t size) {
	   vector<T> arr;
	   for (int i = size; i > 0; i--)
		   arr.push_back(i);
	   return arr;
   }

}