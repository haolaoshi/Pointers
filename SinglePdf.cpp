
#include <string>
#include <iostream>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

class PDF{
public:
	PDF()=default;
	PDF(const std::string &s):name(s){};
	PDF(const std::string &s,unsigned i):name(s),size(i){};
	PDF(const std::string &s,const std::string &p,unsigned i):name(s),path(p),size(i){};
	bool operator==(const PDF &p2){
		return size == p2.size;
	};
	 
	string toString() const{ 
		string str = "";
		str.append(name);
		str.append(",");
		str.append("" + size);
		str.append(",");
		str.append(path);
		return str;
	};
private:
	string name;
	string path;
	int size;

};
std::vector<PDF> files;
std::map<int,string> pdfSizeMap;

string new_path = "D:/projects/study/delete4";
ofstream log, dupling;//(new_path,ofsream::app|ofstream::our);



int getFileSize(const char *path){
    FILE* fp = fopen(path,"rb");
    if(fp) {
      fseek(fp, 0 , SEEK_END);
      long fileSize = ftell(fp);
      fseek(fp, 0 , SEEK_SET);// needed for next read from beginning of file
      
      fclose(fp);
      return fileSize;
    }
    return 0;
}
void listFilesRecursively(char *basePath)
{
    char path[1000];
    struct dirent *dp;
    DIR *dir = opendir(basePath);

    if (!dir){
        return;
    }

    while ((dp = readdir(dir)) != NULL)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {
            // Construct new path from our base path
            strcpy(path, basePath);
            strcat(path, "/");
            strcat(path, dp->d_name);
            if(strstr(dp->d_name,".pdf") > 0 || strstr(dp->d_name,".PDF") >0 || strstr(dp->d_name,".chm") >0){

                int s_t = getFileSize(path)/1024;
                PDF p = PDF(dp->d_name,path,s_t);

                files.push_back(p);
                auto iter = pdfSizeMap.find(s_t);
                if(iter == pdfSizeMap.end()){
                	pdfSizeMap.insert(map<int,string>::value_type(s_t,path));
                	log<<path<<endl;
                }else if(string(path).find("books") < string(path).rfind("books")){
                	//int rename(char * oldname, char * newname);
                	string _path = string(new_path);
                	_path.append("/");_path.append(dp->d_name);
                	dupling<<path<<"----->"<<_path<<endl;
                	int result = rename(path,_path.c_str());
                	if(result != 0){
                		dupling<<"call rename failed."<<result<<endl;
                	}
                }else{ 
                	dupling<< iter->second<<"\n="<<path<<"\n"<<endl;
                }
                
            }
            listFilesRecursively(path);
        }
    }

    closedir(dir);
}

int main(int argc,char** argv)
{
    char p1[] = "D:/projects/books/bookstore";
    char log_path[] = "D:/projects/books/log.txt";
    char dup_path[] = "D:/projects/books/dup.txt";
   log = ofstream(log_path,ofstream::app|ofstream::out);
   dupling = ofstream(dup_path,ofstream::out|ofstream::app);

    listFilesRecursively(p1);
    log<<files.size()<<endl;
    return 0;
}