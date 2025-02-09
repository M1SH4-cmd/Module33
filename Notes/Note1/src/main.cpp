#include <iostream>
#include <exeption>

void divide(int &divident, int divisor)
{
	if (divisor == 0)
	{
		throw std::exception();
	}
	divident /= divisor;

}


int main() {

	int apples = 10;
	int count;
	std::cin >> count;

	try
	{
		divide(apples, count);
		std::cout << apples << std::endl;
	}
	catch (const std::exception& x)
	{
		std::cerr << "Caught exception: " << x.what() << std::endl;
	}

}