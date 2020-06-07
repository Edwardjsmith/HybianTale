#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


struct tilecoord {
	int x;
	int y;
	int width;
	int height;
};

std::vector<std::vector<int>> ReadBMP(std::string filename)
{

	// I will clean this up promis 
	// plese dont hurt me 
	int i;
	FILE* f = fopen(filename.c_str(), "rb");
	if (f == NULL)
		throw "Argument Exception";
	unsigned char info[54];
	fread(info, sizeof(unsigned char), 54, f); // read the 54-byte header
	int width = *(int*)&info[18];
	int height = *(int*)&info[22];
	int row_padded = (width * 3 + 3) & (~3);
	char* data = new char[row_padded];
	unsigned char tmp;

	std::vector<std::vector<int>> t;

	for (int i = 0; i < height; i++)
	{
		std::vector<int> w;
		fread(data, sizeof(unsigned char), row_padded, f);
		for (int j = 0; j < width * 4; j += 4)
		{
			// Convert (B, G, R) to (R, G, B)
			tmp = data[j];
			data[j] = data[j + 2];
			data[j + 2] = tmp;
			tmp = data[j];
			int r = tmp;
			tmp = data[j + 1];
			int g = tmp;
			tmp = data[j + 2];
			int b = tmp;
			w.push_back(std::stoi(std::to_string(r)+ std::to_string(g)+ std::to_string(b)));
		}
		t.push_back(w);
	}
	fclose(f);
	
	return t;
};

std::vector<std::vector<int>> ReadBMP_Blue(std::string filename)
{

	// I will clean this up promis 
	// plese dont hurt me 
	int i;
	FILE* f = fopen(filename.c_str(), "rb");
	if (f == NULL)
		throw "Argument Exception";
	unsigned char info[54];
	fread(info, sizeof(unsigned char), 54, f); // read the 54-byte header
	int width = *(int*)&info[18];
	int height = *(int*)&info[22];
	int row_padded = (width * 3 + 3) & (~3);
	char* data = new char[row_padded];
	unsigned char tmp;

	std::vector<std::vector<int>> t;

	for (int i = 0; i < height; i++)
	{
		std::vector<int> w;
		fread(data, sizeof(unsigned char), row_padded, f);
		for (int j = 0; j < width * 3; j += 3)
		{
			// Convert (B, G, R) to (R, G, B)
			tmp = data[j];
			data[j] = data[j + 2];
			data[j + 2] = tmp;

			int b = tmp;
			w.push_back(std::stoi( std::to_string(b)));
		}
		t.push_back(w);
	}
	fclose(f);
	delete data;
	return t;
};
std::vector<std::vector<int>> ReadBMP_Red(std::string filename)
{

	// I will clean this up promis 
	// plese dont hurt me 
	int i;
	FILE* f = fopen(filename.c_str(), "rb");
	if (f == NULL)
		throw "Argument Exception";
	unsigned char info[54];
	fread(info, sizeof(unsigned char), 54, f); // read the 54-byte header
	int width = *(int*)&info[18];
	int height = *(int*)&info[22];
	int row_padded = (width * 3 + 3) & (~3);
	char* data = new char[row_padded];
	unsigned char tmp;

	std::vector<std::vector<int>> t;

	for (int i = 0; i < height; i++)
	{
		std::vector<int> w;
		fread(data, sizeof(unsigned char), row_padded, f);
		for (int j = 0; j < width * 3; j += 3)
		{
			// Convert (B, G, R) to (R, G, B)
			tmp = data[j];
			data[j] = data[j + 2];
			data[j + 2] = tmp;
			tmp = data[j];
			int r = tmp;
			
			
			w.push_back(std::stoi(std::to_string(r)));
		}
		t.push_back(w);
	}
	fclose(f);
	delete data;
	return t;
};
std::vector<std::vector<int>> ReadBMP_Green(std::string filename)
{

	// I will clean this up promis 
	// plese dont hurt me 
	int i;
	FILE* f = fopen(filename.c_str(), "rb");
	if (f == NULL)
		throw "Argument Exception";
	unsigned char info[54];
	fread(info, sizeof(unsigned char), 54, f); // read the 54-byte header
	int width = *(int*)&info[18];
	int height = *(int*)&info[22];
	int row_padded = (width * 3 + 3) & (~3);
	char* data = new char[row_padded];
	unsigned char tmp;

	std::vector<std::vector<int>> t;

	for (int i = 0; i < height; i++)
	{
		std::vector<int> w;
		fread(data, sizeof(unsigned char), row_padded, f);
		for (int j = 0; j < width * 3; j += 3)
		{
			// Convert (B, G, R) to (R, G, B)
			tmp = data[j];
			data[j] = data[j + 2];
			data[j + 2] = tmp;
			
			tmp = data[j + 1];
			int g = tmp;
			
			w.push_back(std::stoi( std::to_string(g)));
		}
		t.push_back(w);
	}
	fclose(f);
	delete data;
	return t;
};
std::vector<std::string> LoadTextFile_WithSplit(std::string filename, char spliter) {
	
	std::vector<std::string> data;
	std::ifstream MyReadFile(filename);
	std::string myText;
	while (getline(MyReadFile, myText)) {
		std::string temp = "";
		for (int i = 0; i < myText.length(); i++) {
			if (myText.at(i) == spliter) {
				data.push_back(temp);
				temp = "";
			}
			else {
				temp.push_back(myText.at(i));
			}
		}
	}

	MyReadFile.close();
	return data;
}
std::vector<tilecoord> breakspritesheet(std::string filename, int spliter_red, int spliter_green, int spliter_blue) {
	std::vector<tilecoord> tiles;
	//std::vector<std::vector<int>> rgb = ReadBMP(filename);
	std::vector<std::vector<int>> red = ReadBMP_Red(filename);
	std::vector<std::vector<int>> green = ReadBMP_Green(filename);
	std::vector<std::vector<int>> blue = ReadBMP_Blue(filename);
	 

	for (int y = 0; y < red[0].size(); y++) {
		for (int x = 0; x < red.size(); x++) {
			if (red[red.size()-1-x][y] == spliter_red && green[red.size() - 1 -x][y] == spliter_green && blue[red.size() - 1 - x][y] == spliter_blue) {
				for (int i = x+1; i < red.size(); i++) {
					if (red[red.size() - 1 -i][y] == spliter_red && green[red.size() - 1 -i][y] == spliter_green && blue[red.size() - 1 -i][y] == spliter_blue) {
						tilecoord t;
						t.x = x+1;
						t.y = y+1;
						t.width = i-x -2;
						t.height = i-x -2;
						tiles.push_back(t);
						break;
					}
				}
			}
		}
	}



	return tiles;
}