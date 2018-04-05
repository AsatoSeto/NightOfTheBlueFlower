#include <iostream>
#include <locale.h>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>


#define input "/home/fantar/Downloads/Telegram Desktop/sakuya.obj"
#define output "/home/fantar/univer/c++/project/parser/Models.h"

using namespace std;

vector<string> stringdiv(string buffer)
{
	vector<string> divstr;
	string word;
	stringstream ss(buffer);
	while (getline(ss, word, ' ')) 
	{
		if (word != "v" && word != "f")
		{
			divstr.push_back(word);
		} 
	}
	return divstr;
}

int main() 
{	
	setlocale(LC_ALL, "Rus");

	vector<string> vertexArr;
	vector<string> numsArr;
	string buffer;

	ifstream inputfile (input, ios_base::in);
	ofstream outputfile (output, ios_base::out);
	stringstream outstringStream;
	string outstring;

	if (inputfile.is_open() && outputfile.is_open()){
		outputfile<<"using namespace std;"<<endl;
		outputfile<<"class Models"<<endl;
		outputfile<<"{"<<endl;
		outputfile<<"\tpublic:"<<endl;
		outputfile<<"\tvoid drawCube(float xrf,float yrf,float zrf, float stepx, float stepy, float stepz)"<<endl;
		outputfile<<"\t{"<<endl;
		outputfile<<"\t\tglClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);"<<endl<<endl;
		outputfile<<"\t\tglLoadIdentity();"<<endl;
		outputfile<<"\t\tglTranslatef(stepx, stepy, stepz);"<<endl<<endl;
		outputfile<<"\t\tglRotatef(xrf, 1.0f, 0.0f, 0.0f);"<<endl;
		outputfile<<"\t\tglRotatef(yrf, 0.0f, 1.0f, 0.0f);"<<endl;
		outputfile<<"\t\tglRotatef(zrf, 0.0f, 0.0f, 1.0f);"<<endl<<endl;
		while (getline(inputfile, buffer)) {
			if (buffer[0] == 'v') {
				numsArr = stringdiv(buffer);
				outstringStream << "\t\tglVertex3f("<<numsArr[0]<<","<<numsArr[1]<<","<<numsArr[2]<<");\n";
				outstringStream>>outstring;
				vertexArr.push_back(outstring);
			} else if (buffer[0] == 'f') {
				numsArr = stringdiv(buffer);
				if (numsArr.size() == 3) {
					outputfile<<"\t\tglBegin(GL_TRIANGLES);"<<endl;
				} else if (numsArr.size() == 4){
					outputfile<<"\t\tglBegin(GL_QUADS);"<<endl;
				}
				outputfile<<"\t\tglColor3f("<<(rand()%2)<<".0f, "<<(rand()%2)<<".0f, "<<(rand()%2)<<".0f);"<<endl;
				for (int i=0; i<numsArr.size(); i++){
					outstringStream<<vertexArr[atoi(numsArr[i].c_str())-1]<<endl;
					outstringStream>>outstring;
					outputfile<<"\t\t"<<outstring<<endl;
				}
				outputfile<<"\t\tglEnd();"<<endl;
			}
		}
		outputfile<<"\t}"<<endl;
		outputfile<<"};"<<endl;
	} else {
		cout<<"Ошибка открытия файла"<<endl;
		return -1;
	}
	inputfile.close();
	outputfile.close();
	return 0;
}
