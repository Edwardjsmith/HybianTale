#pragma once
#include <fstream>
#include <string>
#include <vector>
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
		for (int j = 0; j < width * 3; j += 3)
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
			
			tmp = data[j + 2];
			int b = tmp;
			w.push_back(std::stoi( std::to_string(b)));
		}
		t.push_back(w);
	}
	fclose(f);

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

	return t;
};