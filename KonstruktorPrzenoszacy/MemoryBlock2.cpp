#include "MemoryBlock2.h"
#include <iostream>
#include <algorithm>

MemoryBlock2::MemoryBlock2(size_t length)
	: _length(length)
	, _data(new int(length))
{
	std::cout << "Zwykly konstruktor, lenght = " << _length << "    Adres: " << this << std::endl;
}

MemoryBlock2::MemoryBlock2(const MemoryBlock2& other)
	: _length(other._length)
	, _data(new int[other._length])
{
	std::cout << "Konstruktor kopiujacy, lenght =" << _length << "    Adres: " << this << std::endl;
	std::copy(other._data, other._data + _length, _data);
}

MemoryBlock2::MemoryBlock2(MemoryBlock2&& other) noexcept
	: _length(std::move(other._length))
	, _data(std::move(other._data))
{

	std::cout << "Konstruktor przenoszacy std::move, lenght =" << _length << "    Adres: " << this << std::endl;
}

MemoryBlock2::~MemoryBlock2()
{
	std::cout << "Destruktor na obiekcie, lenght: " << _length << "    Adres: " << this << std::endl;
	if (_data != nullptr)
	{
		std::cout << " -------- Usuwam dane" << std::endl;
//		delete[] _data;
	}
}

MemoryBlock2& MemoryBlock2::operator= (const MemoryBlock2& other)
{
	std::cout << "Operator przypisania kopiujacy lenght = " << other._length << "do obiektu, ktorego length wynosil wczesniej " << this->_length << "    Adres: " << this << std::endl;

	if (this != &other)
	{
		delete[] _data;

		_length = other._length;
		_data = new int[other._length];

		std::copy(other._data, other._data + _length, _data);

	}
	return *this;
}

MemoryBlock2& MemoryBlock2::operator=(MemoryBlock2&& other) noexcept
{
	std::cout << "Operator przypisania przenoszacy length = " << other._length << "do obiektu, ktorego length wynosil wczesniej " << this->_length << "    Adres: " << this << std::endl;
	

		_length = std::move(other._length);
		_data = std::move(other._data);

	return *this;
}

size_t MemoryBlock2::Length() const
{
	return _length;
}