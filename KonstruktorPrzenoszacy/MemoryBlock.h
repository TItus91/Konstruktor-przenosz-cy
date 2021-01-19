#pragma once


class MemoryBlock
{

public:

	explicit MemoryBlock(size_t length);    //zwykly konstruktor
	MemoryBlock(const MemoryBlock& other);  //konstruktor kopiujacy
	MemoryBlock(MemoryBlock&& other) noexcept;       //konstruktor przenoszacy

	~MemoryBlock();

	MemoryBlock& operator=(const MemoryBlock& other);   //operator kopiowania
	MemoryBlock& operator=(MemoryBlock&& other) noexcept;		//operator przypisania

	size_t Length() const;

private:

	size_t _length;
	int* _data;
};

