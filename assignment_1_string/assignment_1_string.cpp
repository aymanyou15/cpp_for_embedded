#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>


#define music  0
#define image  1
#define movie  2
#define others 3


using namespace std;

int main()
{
    int *size = new int[4]{0};
    int test_cases = 0;
    cin>>test_cases;
    int *lines_no = new int[test_cases];
    string **lines = new string *[test_cases];

    for(int i = 0; i < test_cases; i++)
    {   
        cin>>lines_no[i];
        lines[i] = new string[lines_no[i]];
    }
    for(int i = 0; i < test_cases; i++)
    {
        for(int j = 0; j < lines_no[i]; j++)
        {
            string size_str;
            int size_int = 0;
            getline(cin>>ws, lines[i][j]);
            stringstream s(lines[i][j]);
            getline(s, lines[i][j], '.');
            getline(s, lines[i][j], ' ');
            getline(s, size_str, 'b');
            size_int = stoi(size_str);

            if(lines[i][j] == "mp3" || lines[i][j] == "aac" || lines[i][j] == "flac")
            {
                size[music] += size_int;
            }
            else if(lines[i][j] == "jpg" || lines[i][j] == "bmp" || lines[i][j] == "gif")
            {
                size[image] += size_int;
            }
            else if(lines[i][j] == "mp4" || lines[i][j] == "avi" || lines[i][j] == "mkv")
            {
                size[movie] += size_int;
            }
            else
            {
                size[others] += size_int;
            }

           
        }
        cout<<"music "<< size[music]<< "b images " << size[image] << "b movies " << size[movie]<< "b other "<< size[others]<<"b"<<endl;
    }
    
    delete[] lines_no;
    delete[] lines;
    return 0;
}