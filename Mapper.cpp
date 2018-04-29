#include "Mapper.h"


Mapper* Mapper::instance = NULL;
Mapper::Mapper()
{
}

Mapper* Mapper::getinstance()
{
	if (instance == NULL)
		instance = new Mapper();
	return instance;
}


string Mapper::Encode(wstring input)
{
	string result = "";
	for (int i = 0;i<input.length();i++)
		{
			switch (input[i])
			{
			case  L'ا' :
				result += 'q';
				break;
				case  L'ل' :  
					result += 'w';
					break;
				case  L'ن' :  
					result += 'e';
					break;
				case  L'م' :  
					result += 'r';
					break;
				case  L'ي' :
					result += 't';
					break;
				case  L'و' :  
					result += 'y';
					break;
				case  L'ه' :  
					result += 'u';
					break;
				case  L'ب' :  
					result += 'i';
					break;
				case  L'ر' :  
					result += 'o';
					break;
				case  L'ع' :
					result += 'p';
					break;
				case  L'أ' :  
					result += 'l';
					break;
				case  L'ف' :  
					result += 'k';
					break;
				case  L'ق' :  
					result += 'j';
					break;
				case  L'د' :  
					result += 'h';
					break;
				case  L'ت' :
					result += 'g';
					break;
				case  L'س' :  
					result += 'f';
					break;
				case  L'ك' :  
					result += 'd';
					break;
				case  L'ح' :  
					result += 's';
					break;
				case  L'ة' :  
					result += 'a';
					break;
				case  L'ى' :  
					result += 'z';
					break;
				case  L'ج' :  
					result += 'x';
					break;
				case  L'ص' :  
					result += 'c';
					break;
				case  L'إ' :
					result += 'v';
					break;
				case  L'ذ' :  
					result += 'b';
					break;
				case  L'ث' :  
					result += 'n';
					break;
				case  L' ' :
					result += 'm';
					break;
				case  L'خ' :  
					result += 'Q';
					break;
				case  L'ش' :  
					result += 'W';
					break;
				case  L'ز' :
					result += 'E';
					break;
				case  L'ط' :  
					result += 'R';
					break;
				case  L'ض' :  
					result += 'T';
					break;
				case  L'غ' :  
					result += 'Y';
					break;
				case  L'ء' :  
					result += 'U';
					break;
				case  L'ئ' :
					result += 'I';
					break;
				case  L'ظ' :
					result += 'O';
					break;
				case  L'آ' :
					result += 'P';
					break;
				case  L'ؤ' :
					result += 'L';
					break;
				case  L'،':
					result += 'K';
					break;
				case  L'"':
					result += 'J';
					break;
				case  1600:
					result += 'H';
					break;	
				case  L'.':
					result += 'G';
					break;
				case 1617:
					result += 'F';
					break;
				case L'\n':
					result += 'D';
					break;
				case 1615:
					result += 'S';
					break;
				case 1612:
					result += 'A';
					break;
				case 1611:
					result += 'Z';
					break;
				case 1567:
					result += 'C';
					break;
				case 1614:
					result += 'V';
					break;
				case 1613:
					result += 'B';
					break;
				case 1616:
					result += 'N';
					break;
				case 1563:
					result += 'M';
					break;
				case 1632:
					result += (char) 200;
					break;
				case 1633:
					result += (char) 201;
					break;
				case 1634:
					result += (char) 202;
					break;
				case 1635:
					result += (char) 203;
					break;
				case 1636:
					result += (char) 204;
					break;
				case 1637:
					result += (char) 205;
					break;
				case 1638:
					result += (char) 206;
					break;
				case 1639:
					result += (char) 207;
					break;
				case 1640:
					result += (char) 208;
					break;
				case 1641:
					result += (char) 209;
					break;
				case 1618:
					result += (char)210;
					break;
				case 8230:
					result += (char)211;
					break;
				case 1643:
					result += (char)212;
					break;
				case 65271:
					result += (char)213;
					break;
				case 65275:
					result += (char)214;
					break;
				case 1642:
					result += (char)215;
					break;
				case 65269:
					result += (char)216;
					break;
				case 65273:
					result += (char)217;
					break;
				case 1551:
					result += (char)218;
					break;
				case 1644:
					result += (char)219;
					break;
				case 1599:
					result += (char)220;
					break;
				case 1598:
					result += (char)221;
					break;
				case 1597:
					result += (char)222;
					break;
				case 1596:
					result += (char)223;
					break;
				case 1595:
					result += (char)224;
					break;		
				case 1645:
					result += (char)225;
					break;
			default:
				result += input[i];
				break;
			}
			
		}
	return result;	
}

wstring  Mapper::Decode(string input)
{
	wstring result = L"";
	for (int i = 0; i<input.length(); i++)
	{
		switch (input[i])
		{
		case  'q':
			result += L'ا';
			break;
		case  'w':
			result += L'ل';
			break;
		case  'e':
			result += L'ن';
			break;
		case  'r':
			result += L'م';
			break;
		case  't':
			result += L'ي';
			break;
		case  'y':
			result += L'و';
			break;
		case  'u':
			result += L'ه';
			break;
		case  'i':
			result += L'ب';
			break;
		case  'o':
			result += L'ر';
			break;
		case  'p':
			result += L'ع';
			break;
		case  'l':
			result += L'أ';
			break;
		case  'k':
			result += L'ف';
			break;
		case  'j':
			result += L'ق';
			break;
		case  'h':
			result += L'د';
			break;
		case  'g':
			result += L'ت';
			break;
		case  'f':
			result += L'س';
			break;
		case  'd':
			result += L'ك';
			break;
		case  's':
			result += L'ح';
			break;
		case  'a':
			result += L'ة';
			break;
		case  'z':
			result += L'ى';
			break;
		case  'x':
			result += L'ج';
			break;
		case  'c':
			result += L'ص';
			break;
		case  'v':
			result += L'إ';
			break;
		case  'b':
			result += L'ذ';
			break;
		case  'n':
			result += L'ث';
			break;
		case  'm':
			result += L' ';
			break;
		case  'Q':
			result += L'خ';
			break;
		case  'W':
			result += L'ش';
			break;
		case  'E':
			result += L'ز';
			break;
		case  'R':
			result += L'ط';
			break;
		case  'T':
			result += L'ض';
			break;
		case  'Y':
			result += L'غ';
			break;
		case  'U':
			result += L'ء';
			break;
		case  'I':
			result += L'ئ';
			break;
		case  'O':
			result += L'ظ';
			break;
		case  'P':
			result += L'آ';
			break;
		case  'L':
			result += L'ؤ';
			break;
		case  'K':
			result += L'،';
			break;
		case  'J':
			result += '"';
			break;
		case  'H':
			result += 1600;
			break;
		case  'G':
			result += '.';
			break;
		case 'F':
			result += 1617;
			break;
		case 'D':
			result += '\n';
			break;
		case 'S':
			result += 1615;
			break;
		case 'A':
			result += 1612;
			break;
		case 'Z':
			result += 1611;
			break;
		case 'C':
			result += 1567;
			break;
		case 'V':
			result += 1614;
			break;
		case 'B':
			result += 1613;
			break;
		case 'N':
			result += 1616;
			break;
		case 'M':
			result += 1563;
			break;
		case (char)200:
			result += 1632;
			break;
		case (char)201:
			result += 1633;
			break;
		case (char)202:
			result += 1634;
			break;
		case (char)203:
			result += 1635;
			break;
		case (char)204:
			result += 1636;
			break;
		case (char)205:
			result += 1637;
			break;
		case (char)206:
			result += 1638;
			break;
		case (char)207:
			result += 1639;
			break;
		case (char)208:
			result += 1640;
			break;
		case (char)209:
			result += 1641;
			break;
		case (char)210:
			result += 1618;
			break;
		case (char)211:
			result += 8230;
			break;
		case (char)212:
			result += 1643;
			break;
		case (char)213:
			result += 65271;
			break;
		case (char)214:
			result += 65275;
			break;
		case (char)215:
			result += 1642;
			break;
		case (char)216:
			result += 65269;
			break;
		case (char)217:
			result += 65273;
			break;
		case (char)218:
			result += 1551;
			break;
		case (char)219:
			result += 1644;
			break;
		case (char)220:
			result += 1599;
			break;
		case (char)221:
			result += 1598;
			break;
		case (char)222:
			result += 1597;
			break;
		case (char)223:
			result += 1596;
			break;
		case (char)224:
			result += 1595;
			break;
		case (char)225:
			result += 1645;
			break;
		default:
			result += input[i];
			break;
		}

	}
	return result;
}


Mapper::~Mapper()
{
}

