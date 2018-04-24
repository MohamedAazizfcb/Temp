#include "LZW.h"


LZW* LZW::instance = NULL;
LZW::LZW()
{
}

LZW* LZW::getinstance()
{
	if (instance == NULL)
		instance = new LZW();
	return instance;
}
string LZW::Encode(string input)
{
	string result;
	int length, last_seen, index = 0;
	vector<string> dictionary;
	 {
		int i = 0;
		dictionary.resize(++i);
		dictionary[i - 1] = '0';  dictionary.resize(++i);
		dictionary[i - 1] ='1';
		/*
		char temp = 0;
		for (int i = 0; i < 256; i++)
		{
			dictionary.resize(i+1);
			dictionary[i] = temp;
			temp += 1;
		}*/
		/*
		int i = 0;
		dictionary.resize(++i);
		dictionary[i - 1] = L"ا";  dictionary.resize(++i);
		dictionary[i - 1] = L"ل";  dictionary.resize(++i);
		dictionary[i - 1] = L"ن";  dictionary.resize(++i);
		dictionary[i - 1] = L"م";  dictionary.resize(++i);
		dictionary[i - 1] = L"ي";  dictionary.resize(++i);
		dictionary[i - 1] = L"و";  dictionary.resize(++i);
		dictionary[i - 1] = L"ه";  dictionary.resize(++i);
		dictionary[i - 1] = L"ب";  dictionary.resize(++i);
		dictionary[i - 1] = L"ر";  dictionary.resize(++i);
		dictionary[i - 1] = L"ع";  dictionary.resize(++i);
		dictionary[i - 1] = L"أ";  dictionary.resize(++i);
		dictionary[i - 1] = L"ف";  dictionary.resize(++i);
		dictionary[i - 1] = L"ق";  dictionary.resize(++i);
		dictionary[i - 1] = L"د";  dictionary.resize(++i);
		dictionary[i - 1] = L"ت";  dictionary.resize(++i);
		dictionary[i - 1] = L"س";  dictionary.resize(++i);
		dictionary[i - 1] = L"ك";  dictionary.resize(++i);
		dictionary[i - 1] = L"ح";  dictionary.resize(++i);
		dictionary[i - 1] = L"ة";  dictionary.resize(++i);
		dictionary[i - 1] = L"ى";  dictionary.resize(++i);
		dictionary[i - 1] = L"ج";  dictionary.resize(++i);
		dictionary[i - 1] = L"ص";  dictionary.resize(++i);
		dictionary[i - 1] = L"ال";  dictionary.resize(++i);
		dictionary[i - 1] = L"ٳ";  dictionary.resize(++i);
		dictionary[i - 1] = L"ذ";  dictionary.resize(++i);
		dictionary[i - 1] = L"ث";  dictionary.resize(++i);
		dictionary[i - 1] = L" ";  dictionary.resize(++i);
		dictionary[i - 1] = L"خ";  dictionary.resize(++i);
		dictionary[i - 1] = L"ش";  dictionary.resize(++i);
		dictionary[i - 1] = L"ز";  dictionary.resize(++i);
		dictionary[i - 1] = L"ط";  dictionary.resize(++i);
		dictionary[i - 1] = L"ض";  dictionary.resize(++i);
		dictionary[i - 1] = L"غ";  dictionary.resize(++i);
		dictionary[i - 1] = L"ء";  dictionary.resize(++i);
		dictionary[i - 1] = L"ئ";  dictionary.resize(++i);
		dictionary[i - 1] = L"ظ";  dictionary.resize(++i);
		dictionary[i - 1] = L"آ";  dictionary.resize(++i);
		dictionary[i - 1] = L"ؤ";  dictionary.resize(++i);
		dictionary[i - 1] = L"\n";  dictionary.resize(++i);

		dictionary[i - 1] = L"0";  dictionary.resize(++i);
		dictionary[i - 1] = L"1";  dictionary.resize(++i);
		dictionary[i - 1] = L"2";  dictionary.resize(++i);
		dictionary[i - 1] = L"3";  dictionary.resize(++i);
		dictionary[i - 1] = L"4";  dictionary.resize(++i);
		dictionary[i - 1] = L"5";  dictionary.resize(++i);
		dictionary[i - 1] = L"6";  dictionary.resize(++i);
		dictionary[i - 1] = L"7";  dictionary.resize(++i);
		dictionary[i - 1] = L"8";  dictionary.resize(++i);
		dictionary[i - 1] = L"9"; dictionary.resize(++i);
		dictionary[i - 1] = L":";*/
		index = i;

	}
	
	length = (int)input.length();

	for (int i = 0; i < length; i++)
	{
		string *searched = NULL;
		string search;
		int searched_index;
		search = input[i];
		cout << i*100.0 / length<<'\n';

		while (true)
		{
			//////////////////////searchnode
				bool found = false;
				for (int f = 0; f < index; f++)
				{
					if (search == dictionary[f])
					{
						searched = &search;
						found = true;
						searched_index = f;
						break;
					}
				}
				if (!found)
				{
					searched = NULL;
				}
			/////////////////////
			if (searched)
			{
				i++;
				search += input[i];
				last_seen = searched_index;
				if (i == length)
					break;
					
			}
			else break;
		}
		if (!searched)
		{
			dictionary.resize(++index);
		    dictionary[index-1] = search;
		}
		result += to_string(last_seen) + " " ;
		i--;
	}
	/////////////////////////////////////////////////////////////////////
	string finalresult = "";
	for (long i = 0; i < result.size(); i += 2)
	{
		unsigned char temp;	
		switch (result[i])
		{
		case '0':
			temp = 0;
			break;
		case '1':
			temp = 1;
			break;
		case '2':
			temp = 2;
			break;
		case '3':
			temp = 3;
			break;
		case '4':
			temp = 4;
			break;
		case '5':
			temp = 5;
			break;
		case '6':
			temp = 6;
			break;
		case '7':
			temp = 7;
			break;
		case '8':
			temp = 8;
			break;
		case '9':
			temp = 9;
			break;
		case ' ':
			temp = 10;
			break;
		}
		switch (result[i+1])
		{
		case '0':
			temp += 0;
			break;
		case '1':
			temp += 16;
			break;
		case '2':
			temp += 32;
			break;
		case '3':
			temp += 48;
			break;
		case '4':
			temp += 64;
			break;
		case '5':
			temp += 80;
			break;
		case '6':
			temp += 96;
			break;
		case '7':
			temp += 112;
			break;
		case '8':
			temp += 128;
			break;
		case '9':
			temp += 144;
			break;
		case ' ':
			temp += 160;
			break;
		}
		finalresult += temp;
	}
	/////////////////////////////////////////////////////////////////////
	return finalresult;
}

string LZW::Decode(string initinput)
{
	/////////////////////////////////////////////////////////////////////
	string input = "";
	for (long i = 0; i < initinput.size(); i++)
	{
		unsigned char temp;
		temp = initinput[i] & 15;
		switch (temp)
		{
		case 0:
			input += '0';
			break;
		case  1:
			input += '1';
			break;
		case 2:
			input += '2';
			break;
		case 3:
			input += '3';
			break;
		case 4:
			input += '4';
			break;
		case 5:
			input += '5';
			break;
		case 6:
			input += '6';
			break;
		case 7:
			input += '7';
			break;
		case 8:
			input += '8';
			break;
		case 9:
			input += '9';
			break;
		case 10:
			input += ' ';
			break;
		}
		temp = initinput[i] & 240;
		switch (temp)
		{
		case 0:
			input += '0';
			break;
		case 16:
			input += '1';
			break;
		case 32:
			input += '2';
			break;
		case 48:
			input += '3';
			break;
		case 64:
			input += '4';
			break;
		case 80:
			input += '5';
			break;
		case 96:
			input += '6';
			break;
		case 112:
			input += '7';
			break;
		case 128:
			input += '8';
			break;
		case 144:
			input += '9';
			break;
		case 160:
			input += ' ';
			break;
		}
	}
	/////////////////////////////////////////////////////////////////////
	vector<string> dictionary;
	string result;
	int index = 0;
	{
		int i = 0;
		dictionary.resize(++i);
		dictionary[i - 1] = '0';  dictionary.resize(++i);
		dictionary[i - 1] = '1';
		/*
		char temp = 0;
		for (int i = 0; i < 256; i++)
		{
		dictionary.resize(i+1);
		dictionary[i] = temp;
		temp += 1;
		}*/
		/*
		int i = 0;
		dictionary.resize(++i);
		dictionary[i - 1] = L"ا";  dictionary.resize(++i);
		dictionary[i - 1] = L"ل";  dictionary.resize(++i);
		dictionary[i - 1] = L"ن";  dictionary.resize(++i);
		dictionary[i - 1] = L"م";  dictionary.resize(++i);
		dictionary[i - 1] = L"ي";  dictionary.resize(++i);
		dictionary[i - 1] = L"و";  dictionary.resize(++i);
		dictionary[i - 1] = L"ه";  dictionary.resize(++i);
		dictionary[i - 1] = L"ب";  dictionary.resize(++i);
		dictionary[i - 1] = L"ر";  dictionary.resize(++i);
		dictionary[i - 1] = L"ع";  dictionary.resize(++i);
		dictionary[i - 1] = L"أ";  dictionary.resize(++i);
		dictionary[i - 1] = L"ف";  dictionary.resize(++i);
		dictionary[i - 1] = L"ق";  dictionary.resize(++i);
		dictionary[i - 1] = L"د";  dictionary.resize(++i);
		dictionary[i - 1] = L"ت";  dictionary.resize(++i);
		dictionary[i - 1] = L"س";  dictionary.resize(++i);
		dictionary[i - 1] = L"ك";  dictionary.resize(++i);
		dictionary[i - 1] = L"ح";  dictionary.resize(++i);
		dictionary[i - 1] = L"ة";  dictionary.resize(++i);
		dictionary[i - 1] = L"ى";  dictionary.resize(++i);
		dictionary[i - 1] = L"ج";  dictionary.resize(++i);
		dictionary[i - 1] = L"ص";  dictionary.resize(++i);
		dictionary[i - 1] = L"ال";  dictionary.resize(++i);
		dictionary[i - 1] = L"ٳ";  dictionary.resize(++i);
		dictionary[i - 1] = L"ذ";  dictionary.resize(++i);
		dictionary[i - 1] = L"ث";  dictionary.resize(++i);
		dictionary[i - 1] = L" ";  dictionary.resize(++i);
		dictionary[i - 1] = L"خ";  dictionary.resize(++i);
		dictionary[i - 1] = L"ش";  dictionary.resize(++i);
		dictionary[i - 1] = L"ز";  dictionary.resize(++i);
		dictionary[i - 1] = L"ط";  dictionary.resize(++i);
		dictionary[i - 1] = L"ض";  dictionary.resize(++i);
		dictionary[i - 1] = L"غ";  dictionary.resize(++i);
		dictionary[i - 1] = L"ء";  dictionary.resize(++i);
		dictionary[i - 1] = L"ئ";  dictionary.resize(++i);
		dictionary[i - 1] = L"ظ";  dictionary.resize(++i);
		dictionary[i - 1] = L"آ";  dictionary.resize(++i);
		dictionary[i - 1] = L"ؤ";  dictionary.resize(++i);
		dictionary[i - 1] = L"\n";  dictionary.resize(++i);

		dictionary[i - 1] = L"0";  dictionary.resize(++i);
		dictionary[i - 1] = L"1";  dictionary.resize(++i);
		dictionary[i - 1] = L"2";  dictionary.resize(++i);
		dictionary[i - 1] = L"3";  dictionary.resize(++i);
		dictionary[i - 1] = L"4";  dictionary.resize(++i);
		dictionary[i - 1] = L"5";  dictionary.resize(++i);
		dictionary[i - 1] = L"6";  dictionary.resize(++i);
		dictionary[i - 1] = L"7";  dictionary.resize(++i);
		dictionary[i - 1] = L"8";  dictionary.resize(++i);
		dictionary[i - 1] = L"9"; dictionary.resize(++i);
		dictionary[i - 1] = L":";*/
		index = i;

	}
	vector <string> s_input = split(input, ' ');
	for (int i = 0; i < s_input.size(); i++)
	{
		string *searched;
		int search;
		search = stoi(s_input[i]);
		if (search < index)
			searched = &dictionary[search];
		else
			searched = NULL;

		string cur, prev, data;
		if (searched)
			cur = dictionary[stoi(s_input[i])];
		if (i != 0)
			prev = dictionary[stoi(s_input[i - 1])];
		else
			prev = cur;

		int show = 0;
		if (searched)
		{
			result = result +  *searched;

			if (i != 0)
			{
				data = prev + cur[0];
				if (show != 1)
				{
					dictionary.resize(++index);
					dictionary[index-1] = data;
				}
			}
			show = 0;
		}
		else
		{
			data = prev + prev[0];
			dictionary.resize(++index);
			dictionary[index - 1] = data;
			show = 1;
			result += data;
		}
	}

	return result;
}


LZW::~LZW()
{
}
