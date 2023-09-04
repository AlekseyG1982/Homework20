#include<iostream>
#include<ctime>
#include<cstdlib>

template<typename T> void fill_arr(T arr[], int const size, T left, T right);
template<typename T> void print_arr(T arr[], int const size);
template<typename T> int search_index(T arr[], int const size, T n, int begin = 0)
{
	int index = 0;
	for (int i = begin; i < size; i++)
	{
		if (arr[i] == n)
		{
			index = i;
			return index;
		}
	}
}
template<typename T> int search_last_index(T arr[], int const size, T n)
{
	int index = 0;
	for (int i = 0; i < size; i++) if (arr[i] == n) index = i;
	return index;
}

template<typename T> int search_last_index(T arr[], int const size, T n, int begin)
{
	int index = 0;
	for (int i = begin; i < size; i++) if (arr[i] == n) index = i;
	return index;
}

template<typename T> int arr_min(T arr[], int const size);
template<typename T> int arr_max(T arr[], int const size);
template<typename T> int mean_value(T arr[], int const size);
template<typename T> void  range(T arr[], int const size, int left, int right);
template<typename T> int count(T arr[], int const size, T n);
template<typename T> void sort_arr(T arr[], int const size);

int main()
{
	std::cout << "Homework 20 \n";
	int const size = 20;
	int a=-50, b=50;
	//std::cout << "Enter the range of arr from A to B - ";
	//std::cin >> a >> b;
	int arr[size];

	fill_arr(arr, size, a, b);
	print_arr(arr, size);
	std::cout << "\nEnter the nember - ";
	int n;
	std::cin >> n;
	std::cout<<"Index - "<<search_index(arr, size, n);
	std::cout << "\nEnter the nember - ";
	int m;
	std::cin >> m;
	std::cout << "Index - " << search_last_index(arr, size, m);

	std::cout << "\nMinimum - " << arr_min(arr, size);
	std::cout<<"\nMaximum - "<< arr_max(arr, size);
	std::cout << "\nValue - " << mean_value(arr, size);
	std::cout << "\nEnter the range from A to B - ";
	int A,B;
	std::cin >> A>>B;
	range(arr,size,A,B);
	std::cout << "\nEnter the nember - ";
	int N;
	std::cin >> N;
	std::cout << "The number occurs - " << count(arr, size, N) << " times\n";
	sort_arr(arr, size);
	print_arr(arr, size);

	return 0;
}

template<typename T> void fill_arr(T arr[], int const size, T left, T right)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++) arr[i] = rand() % (right - left) + left;
}
template<typename T> void print_arr(T arr[], int const size)
{
	std::cout << "{  ";
	for (int i = 0; i < size; i++) std::cout << arr[i] << "  ";
	std::cout << "}";
}
template<typename T> int arr_min(T arr[], int const size)
{
	T min = arr[0];
	for (int i = 0; i < size; i++) if (arr[i] < min) min = arr[i];
	return min;
}
template<typename T> int arr_max(T arr[], int const size)
{
	T max = arr[0];
	for (int i = 0; i < size; i++) if (arr[i] > max) max = arr[i];
	return max;
}
template<typename T> int mean_value(T arr[], int const size)
{
	int sum = 0;
	for (int i = 0; i < size; i++) sum += arr[i];
	return sum / size;
}
template<typename T> void  range(T arr[], int const size, int left, int right)
{
	for (int i = 0; i < size; i++) if (arr[i] >=left and arr[i]<=right) std::cout <<arr[i]<<"  ";
}
template<typename T> int count(T arr[], int const size, T n)
{
	int count = 0;
	for (int i = 0; i < size; i++) if (arr[i] == n) count++;
	return count;
}
template<typename T> void sort_arr(T arr[], int const size)
{
	for(int j=size-1;j>=0;j--)
		for (int i = 0; i < j; i++)
		{
			if (arr[i] > arr[i + 1]) std::swap(arr[i], arr[i + 1]);
		}

}