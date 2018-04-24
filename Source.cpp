#include"AllIncludes.h"
#include"LZW.h"
#include <locale>

int main()
{
	string menue = "1-compress\n2-decompress\n";
	cout << menue;
	string op;
	cin >> op;
	if (op == "1")
	{
		ifstream* infile = new ifstream("input.tsv", ifstream::binary);
		infile->seekg(0, infile->end);
		long size = infile->tellg();
		infile->seekg(0);
		char* buffer = new char[size];
		infile->read(buffer, size);
		string text = "";
		for (long i = 0; i < size; i++)
		{
			text += buffer[i];
		}
		LZW* l = LZW::getinstance();
		string entext = l->Encode(text);
		ofstream out("Encoded.tsv");
		out << entext;
		out.close();
	}
	else
	{
		ifstream* infile = new ifstream("Encoded.tsv", ifstream::binary);
		infile->seekg(0, infile->end);
		long size = infile->tellg();
		infile->seekg(0);
		char* buffer = new char[size];
		infile->read(buffer, size);
		string text;
		for (long i = 0; i < size; i++)
		{
			text += buffer[i];
		}
		LZW* l = LZW::getinstance();
		string detext = l->Decode(text);
		ofstream out("Decoded.tsv");
		out << detext;
		out.close();
	}
	return 0;
}