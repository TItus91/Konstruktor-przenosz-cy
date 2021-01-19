#include "MemoryBlock.h"
#include <iostream>
#include <algorithm>

MemoryBlock::MemoryBlock(size_t length)
	: _length(length)
	, _data(new int(length))
{
	std::cout << "Zwykly konstruktor, lenght = " << _length << "    Adres: "<< this <<std::endl;
}

MemoryBlock::MemoryBlock(const MemoryBlock& other)
	: _length(other._length)
	, _data(new int[other._length])
{
	std::cout << "Konstruktor kopiujacy, lenght =" << _length << "    Adres: " << this << std::endl;
	std::copy(other._data, other._data + _length, _data);
}

 MemoryBlock::MemoryBlock(MemoryBlock&& other) noexcept
	: _length(0)
	, _data(nullptr)
{
	if (&other != this)
	{
		_length = other._length;
		_data = other._data;

		other._length=0;
		other._data = nullptr;
	}

	std::cout << "Konstruktor przenoszacy, lenght =" << _length << "    Adres: " << this << std::endl;
}

MemoryBlock::~MemoryBlock()
{
	std::cout << "Destruktor na obiekcie, lenght: " << _length << "    Adres: " << this << std::endl;
	if (_data != nullptr)
	{
		std::cout << " -------- Usuwam dane" << std::endl;
		delete[] _data;
	}
}

MemoryBlock& MemoryBlock::operator= (const MemoryBlock& other)
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

MemoryBlock& MemoryBlock::operator=(MemoryBlock&& other) noexcept
{
	std::cout<<"Operator przypisania przenoszacy length = "<<other._length << "do obiektu, ktorego length wynosil wczesniej " << this->_length << "    Adres: " << this << std::endl;
	if (this != &other)
	{
		delete[] _data;

		_length = other._length;
		_data = other._data;

		other._length = 0;
		other._data = nullptr;
	}
	return *this;
}

size_t MemoryBlock::Length() const
{
	return _length;
}