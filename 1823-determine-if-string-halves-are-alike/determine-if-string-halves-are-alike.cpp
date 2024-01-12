class Solution {
public:
	bool halvesAreAlike(string s) 
	{
		int count1{ 0 };
		int count2{ 0 };

		for (int i = 0; i < s.size() / 2; i++)
		{
			switch (s[i])
			{
			case 'a' :
			case 'e' :
			case 'i' :
			case 'o' :
			case 'u' :
			case 'A' :
			case 'E' :
			case 'I' :
			case 'O' :
			case 'U':	count1++;
			}
		}
		for (int i = s.size()/2; i < s.size(); i++)
		{
			switch (s[i])
			{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
			case 'A':
			case 'E':
			case 'I':
			case 'O':
			case 'U':	count2++;
			}
		}
		return (count1 == count2);
	}
};