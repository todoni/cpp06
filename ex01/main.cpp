#include <iostream>

struct	Data
{
	int	a;
	int	b;
	std::string str;
};

uintptr_t	serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

int	main()
{
	Data	data1;
	Data	*data2 = new Data();

	uintptr_t	ptr1;
	uintptr_t	ptr2;

	data1.a = 42;
	data1.b = -42;

	data2->a = 128;
	data2->b = 129;

	ptr1 = serialize(&data1);
	ptr2 = serialize(data2);

	Data	*pData1 = deserialize(ptr1);
	Data	*pData2 = deserialize(ptr2);

	std::cout << pData1->a << std::endl;
	std::cout << pData1->b << std::endl;
	std::cout << "------------------------" << std::endl;

	std::cout << pData2->a << std::endl;
	std::cout << pData2->b << std::endl;

	delete data2;
}
