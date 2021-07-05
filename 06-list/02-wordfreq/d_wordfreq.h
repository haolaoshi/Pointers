#include <iostream>
#include <string>








class wordFreq{

public:
    wordFreq(const string& str):word(str),freq(1)
    {}
    void increment()
    { freq++;}
    friend bool operator ==(const wordFreq& lhs,const wordReq& rhs)
    {
	return lhs.word == rhs.word;
    }

    friend bool operator<(const wordFreq& lhs,const wordReq& rhs)
    {
	return lhs.word < rhs.word;
    }
    friend ostream&  operator<<(ostream& ostr, const wordFreq& w)
    {
	ostr << w.worod << " ( " << w.freq << " )" ;
	return ostr;
    }

private:
    string word;
    int freq;
};
