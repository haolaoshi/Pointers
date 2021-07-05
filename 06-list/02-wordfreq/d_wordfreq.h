#include <iostream>
#include <string>


using namespace std;





class wordFreq{

public:
    wordFreq(const string& str):word(str),freq(1)
    {}
    void increment()
    { freq++;}
    friend bool operator ==(const wordFreq& lhs,const wordFreq& rhs)
    {
	return lhs.word == rhs.word;
    }

    friend bool operator<(const wordFreq& lhs,const wordFreq& rhs)
    {
	return lhs.word < rhs.word;
    }
    friend ostream&  operator<<(ostream& ostr, const wordFreq& w)
    {
	ostr << w.word << " ( " << w.freq << " )" ;
	return ostr;
    }

private:
    string word;
    int freq;
};
