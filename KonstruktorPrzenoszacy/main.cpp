#include <vector>
#include "MemoryBlock.h"
#include "MemoryBlock2.h"



int main()
{
	
	std::vector<MemoryBlock> dane;
	dane.reserve(5);

	dane.push_back(MemoryBlock(10));
	dane.push_back(MemoryBlock(20));
	dane.emplace_back(MemoryBlock(30));
	dane.emplace_back(MemoryBlock(40));
	dane.insert(dane.begin(), MemoryBlock(50));
	

	std::vector<MemoryBlock2> dane2;
	dane2.reserve(5);

	dane2.push_back(MemoryBlock2(10));
	dane2.push_back(MemoryBlock2(20));
	dane2.emplace_back(MemoryBlock2(30));
	dane2.emplace_back(MemoryBlock2(40));
	dane2.insert(dane2.begin(), MemoryBlock2(50));

}