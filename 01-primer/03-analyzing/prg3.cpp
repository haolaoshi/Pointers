#include <iostream>
#include <string>


using namespace std;



int main()
{
    string pathname, path, filename, executableFile;
    int backslashIndex, dotIndex;
    cout << "Enter the path name: "<<endl;
    cin>>pathname;


    backslashIndex = pathname.find_last_of('\\');
    path = pathname.substr(0,backslashIndex);

    cout << "Path : \t"<<path << endl;

    filename = pathname.substr(backslashIndex + 1, -1);
    cout << "Filename : \t"<<filename << endl;

    dotIndex = filename.find_last_of('.');
    if(dotIndex != -1 && filename.substr(dotIndex + 1) == "cpp")
    {
	executableFile = filename;
	executableFile.erase(dotIndex , 3);
	executableFile += "exe";
	cout << "Executable: " << executableFile << endl;
    }

    return 0;
}
