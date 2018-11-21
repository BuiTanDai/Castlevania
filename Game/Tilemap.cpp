#include "Tilemap.h"
#include<fstream>
using namespace std;

void Tilemap::Init(const char * tilesheetPath, const char * matrixPath)
{
	/* khởi tạo tilesheet */
	tilesheet = new GameTexture();
	tilesheet->Init(tilesheetPath);

	/* khởi tạo matrix */
	fstream fs(matrixPath);

	/* đọc cái giá trị đã nêu trong file world */
	fs >> tileRows >> tileColumns >> tileWidth >> tileHeight >> tilesheetColumns;

	/* khởi tạo ma trận */
	matrix = new int*[tileRows];

	for (size_t rowIndex = 0; rowIndex < tileRows; rowIndex++)
	{
		matrix[rowIndex] = new int[tileColumns];
		for (size_t columnIndex = 0; columnIndex < tileColumns; columnIndex++)
		{
			/* đọc thông số ma trận tile file */
			fs >> matrix[rowIndex][columnIndex];
		}
	}

}

void Tilemap::Init(const char * folderPath)
{
	/* tìm đường dẫn tilesheet và matrix */
	string folderPathString = (string)folderPath;
	string tilesheetString = folderPathString;
	tilesheetString.append("/tilesheet.png");
	string matrixPathString = folderPathString;
	matrixPathString.append("/matrix.dat");

	/* khởi tạo bằng phương thức trên */
	Init(tilesheetString.c_str(), matrixPathString.c_str());
}
Tilemap::Tilemap()
{
}
Tilemap::~Tilemap()
{
}
