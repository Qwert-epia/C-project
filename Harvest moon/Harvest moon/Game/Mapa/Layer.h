#pragma once
#include <string>
#include <vector>

using namespace std;

class Layer
{

public:
	Layer();
	~Layer();

	int getId() { return _id; }
	void setId(int id) { _id = id; }

	std::string getName() { return _name; }
	void setName(std::string name) { _name = name; }

	int getWidth() { return _width; }
	void setWidth(int width) { _width = width; }

	int getHeight() { return _height; }
	void setHeight(int height) { _height = height; }

	vector<vector<int>> data;


private:
	int _id;
	string _name;
	int _width;
	int _height;	
};

