void reverseWords(string &s) 
{
    int i = 0;
    int j = 0;
    int sLength = s.length();
    reversePortion(s, 0, sLength - 1);
    while (i < sLength)
    {
    	i = getIndexOfNextChar(s, j);
    	j = getIndexOfNextSpace(s, i);
    	reversePortion(s, i, j);
    }
}

void reversePortion(string &s, int start, int end) 
{
	while (start < end) 
	{
		s[start], s[end] = s[end], s[start];
		start++;
		end--;
	}
}

int getIndexOfNextChar(string &s, int startIndex)
{
	int sLength = s.length();
	while (startIndex < sLength)
	{
		if (s[startIndex] != ' ')
			break;
		startIndex++;
	}
	return startIndex;
}

int getIndexOfNextSpace(string &s, int startIndex)
{
	int sLength = s.length();
	while (startIndex < sLength)
	{
		if (s[++startIndex] == ' ')
			break;
	}
	return startIndex;
}

