class Solution 
{
public:
	bool isAnagram(std::string s, std::string t)
	{
		int arr1[26]{};
		int arr2[26]{};
		for (char c : s)
		{
			arr1[c - 97]++;
		}
		for (char c : t)
		{
			arr2[c - 97]++;
		}
		for (int i = 0; i < 26; i++)
		{
			if (arr1[i] != arr2[i])
				return false;
		}
		return true;
	}
};