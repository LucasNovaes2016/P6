#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main()
{
	std::vector<int> data{};
	int x{};

	while(std::cin >> x) 
		data.push_back(x);

	for (auto start(data.begin()), end(data.end()); start < end; ++start) {
		--end;
		std::iter_swap(start, end); // swap contents of two iterators
	}
	std::copy(data.begin(),
		data.end(),
		std::ostream_iterator<int>(std::cout, "\n"));
}