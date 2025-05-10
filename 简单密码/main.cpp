/*
��������

Julius Caesar����ʹ�ù�һ�ֺܼ򵥵����롣���������е�ÿ���ַ�������������ĸ���к�5λ��Ӧ���ַ������棬�����͵õ������ġ������ַ�A��F�����档���������ĺ��������ַ��Ķ�Ӧ��ϵ��

����

A B C D E F G H I J K L M N O P Q R S T U V W X Y Z

����

V W X Y Z A B C D E F G H I J K L M N O P Q R S T U

��������ǶԸ��������Ľ��н��ܵõ����ġ�

����Ҫע����ǣ������г��ֵ���ĸ���Ǵ�д��ĸ��������Ҳ��������ĸ���ַ�������Щ�ַ����ý��н��롣

������ʽ

�����еĲ������ݲ�����100�顣ÿ�����ݶ������µ���ʽ�����Ҹ����������֮��û�пհ׵��С�

һ��������ݰ���������

��ʼ�У�һ�У������ַ��� "START"

���ģ�һ�У��������ģ����Ĳ�Ϊ�գ��������е��ַ���������200

�����У�һ�У������ַ��� "END"

�����һ���������֮����һ�У������ַ��� "ENDOFINPUT"��

�����ʽ

��ÿ�����ݣ�����һ��������������Ķ�Ӧ�����ġ�

��������

START
NS BFW�� JAJSYX TK NRUTWYFSHJ FWJ YMJ WJXZQY TK YWNANFQ HFZXJX
END
START
N BTZQI WFYMJW GJ KNWXY NS F QNYYQJ NGJWNFS ANQQFLJ YMFS XJHTSI NS WTRJ
END
START
IFSLJW PSTBX KZQQ BJQQ YMFY HFJXFW NX RTWJ IFSLJWTZX YMFS MJ
END
ENDOFINPUT

�������

IN WAR�� EVENTS OF IMPORTANCE ARE THE RESULT OF TRIVIAL CAUSES
I WOULD RATHER BE FIRST IN A LITTLE IBERIAN VILLAGE THAN SECOND IN ROME
DANGER KNOWS FULL WELL THAT CAESAR IS MORE DANGEROUS THAN HE
*/

#include <iostream>
#include <string>

using namespace std;

void decrypt(string &cipher)
{
	for (auto &c : cipher)
	{
		if (c < 'A' || c > 'Z') continue;
		c = (c - 'A' + 26 - 5) % 26 + 'A';
	}
}

int main()
{
	while (true)
	{
		string line;
		getline(cin, line);
		if (line == "ENDOFINPUT") break;
		string cipher;
		getline(cin, cipher);
		decrypt(cipher);
		getline(cin, line);
		cout << cipher << endl;
	}
	return 0;
}