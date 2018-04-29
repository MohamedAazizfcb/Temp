#include"AllIncludes.h"
#include"Arithmtic.h"
#include <locale>

int main()
{
	string menue = "1-compress\n2-decompress\n";
	cout << menue;
	string op;
	cin >> op;
	if (op == "1")
	{
		wstring text = LoadUtf8FileToString(L"input.tsv");
		Arithmtic* l = Arithmtic::getinstance();
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
		Arithmtic* l = Arithmtic::getinstance();
		wstring detext = l->Decode(text);
		if (auto f = wofstream("Decoded.tsv")) {
			f.imbue(locale(std::locale(), new std::codecvt_utf8_utf16<wchar_t>));
			f << detext;
		}
	}
	return 0;
}