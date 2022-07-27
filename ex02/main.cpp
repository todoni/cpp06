#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <exception>

Base*	generate(void)
{
	static int	srandFlag;

	if (srandFlag == 0)
	{
		srand(time(NULL));
		srandFlag = 1;
	}

	Base*	random;
	int	num = rand() % 3;
	switch (num)
	{
		case 0:
			random = new A();
			std::cout << "A Generated" << std::endl;
			break;
		case 1:
			random = new B();
			std::cout << "B Generated" << std::endl;
			break;
		case 2:
			random = new C();
			std::cout << "C Generated" << std::endl;
			break;
		default:
			random = NULL;
	}
	return (random);
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "It's A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "It's B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "It's C" << std::endl;
}

void	identify(Base& p)
{
	try
	{	
		A& a = dynamic_cast<A&>(p);
		std::cout << "It's A" << std::endl;
		(void)a;
	}
	catch (std::exception& e)
	{

	}
	try
	{	
		B& b = dynamic_cast<B&>(p);
		std::cout << "It's B" << std::endl;
		(void)b;
	}
	catch (std::exception& e)
	{

	}
	try
	{	
		C& c = dynamic_cast<C&>(p);
		std::cout << "It's C" << std::endl;
		(void)c;
	}
	catch (std::exception& e)
	{

	}
}

int	main()
{
	Base	*test[10];

	for (int i = 0; i < 10; i++)
	{
		test[i] = generate();
		Base &ref = *test[i];
		identify(test[i]);
		identify(ref);
		delete test[i];
		std::cout << "====================" << std::endl;
	}
	Base *b1 = generate();
	Base &b1Ref = *b1;

	identify(b1);
	identify(b1Ref);

	delete b1;
}
