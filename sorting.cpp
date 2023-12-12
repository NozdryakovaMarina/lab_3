#pragma once

#include <iostream>
#include <cmath>
#include <vector>
#include <stdexcept>
#include <complex>
#include <random>

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
   stats insert_sort(vector<T>& arr) {
	   stats stats;

	   for (size_t i = 0; i < arr.size() - 1; ++i) {
		   size_t minIndex = i;

		   for (size_t j = i + 1; j < arr.size(); ++j) {
			   ++stats.comparison_count;
			   if (arr[j] < arr[minIndex])
				   minIndex = j;
		   }

		   if (minIndex != i) {
			   std::swap(arr[i], arr[minIndex]);
			   ++stats.copy_count;
		   }
	   }

	   return stats;
   }

   // Функция для разделения массива на подмассивы и возврата индекса опорного элемента
   template<typename T>
   int partition(std::vector<T>& arr, int low, int high, stats& s) {
	   int pivot = arr[high];
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

   // Функция быстрой сортировки
   template<typename T>
   void quick_sort(std::vector<T>& arr, int low, int high, stats& s) {
	   if (low < high) {
		   int pi = partition(arr, low, high, s);
		   quick_sort(arr, low, pi - 1, s);
		   quick_sort(arr, pi + 1, high, s);
	   }
   }

   // Функция для вызова быстрой сортировки
   template<typename T>
   stats quick_sort(std::vector<T>& arr) {
	   stats s;
	   quick_sort(arr, 0, arr.size() - 1, s);
	   return s;
   }

   template<typename T>
   stats combSort(std::vector<T>& arr) {
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
				   std::swap(arr[i], arr[i + gap]);
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
}