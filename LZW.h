#pragma once
#include"MNode.h"
class LZW
{
	LZW();
	static LZW* instance;
public:
	static LZW* getinstance();
	virtual string Encode(string input);
	virtual string Decode(string initinput);
	~LZW();
};

