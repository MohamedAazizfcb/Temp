#pragma once
#include"AllIncludes.h"
class Mapper
{
	Mapper();
	static Mapper* instance;
public:
	static Mapper* getinstance();
	string Encode(wstring input);
	wstring Decode(string input);
	~Mapper();
};

