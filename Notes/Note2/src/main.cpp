#include <iostream>
#include <exeption>


class DivisionByZeroException : public std::exception
{
	const char* what() const noexcept override
	{
		return "DivisionByZeroException";
	}
};


void divide(int &divident, int divisor)
{
	if (divisor == 0)
	{
		throw DivisionByZeroException();
	}
	divident /= divisor;

}

int distribute(int apples, int count)
{
	if (apples < 0 || count > apples) throw std::invalid_argument(apples < 0 ? "apples" : "count");
	if (apples > 100) throw apples;
	return divide(apples, count);
}


int main() {

	int apples;
	int count;
	bool input = true;


	while (input)
	{

		std::cin >> apples;
		std::cin >> count;
		try
		{
			std::cout << distribute(apples, count) << std::endl;
			input = false;
		}
		catch (const DivizionByZeroException& x)
		{
			input = false;
		}
		catch (const std::invalid_argument& x)
		{
			std::cerr << "Caught exception:\t" << x.what() << std::endl;
		}
		catch (...)
		{
			std::cerr << "Caught some exception..." << std::endl;
		}

	}
}