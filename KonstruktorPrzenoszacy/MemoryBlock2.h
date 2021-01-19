#pragma once


class MemoryBlock2
{

public:

	explicit MemoryBlock2(size_t length);    //zwykly konstruktor
	MemoryBlock2(const MemoryBlock2& other);  //konstruktor kopiujacy
	MemoryBlock2(MemoryBlock2&& other) noexcept;       //konstruktor przenoszacy

	~MemoryBlock2();

	MemoryBlock2& operator=(const MemoryBlock2& other);   //operator kopiowania
	MemoryBlock2& operator=(MemoryBlock2&& other) noexcept;		//operator przypisania

	size_t Length() const;

private:

	size_t _length;
	int* _data;
};

