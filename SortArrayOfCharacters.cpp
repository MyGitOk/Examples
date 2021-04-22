#include <iostream>
//#include <cstdlib>

void sort_char(unsigned char* _data, const int _array_size, const bool _ascending = true)
{
	const int range_of_values = 256;
	unsigned char tmp_arr[range_of_values]; // crate temporary array. capacity equels range of values char (256)
	memset(tmp_arr, 0, range_of_values); // array initialization with zeros

	// count each of symbols
	for (size_t i = 0; i < _array_size; i++)
	{
		unsigned char index = _data[i];
		tmp_arr[index]++;
	}

	// write sorted array
	int sorted_poz = 0;
	for (size_t i = 0; i < range_of_values; i++)
	{
		for (size_t j = 0; j < tmp_arr[i]; j++)
		{
			_data[sorted_poz] = _ascending ? i : 255 - i; // if ascending strat index == 0 else index == 255
			sorted_poz++;
		}
	}
}

int main()
{
	const int size_arr = 10000;
	unsigned char arr[size_arr];

	// randome values to array
	const unsigned int range_of_values = 256; // range of values unsigned char 0...255
	for (size_t i = 0; i < size_arr; i++)
		arr[i] = rand() % range_of_values;

	// sorting array
	sort_char(arr, size_arr, false);

	// print sorted array
	std::cout << "char array sorted:" << std::endl;
	for (auto x : arr)
		std::cout << static_cast<int>(x) << " ";

	return 0;
}