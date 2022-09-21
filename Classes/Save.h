#pragma once

#include "cocos2d.h"
#include "CCUserDefault.h"

static class Save 
{
public:
	cocos2d::UserDefault* data = cocos2d::UserDefault::getInstance();
	Save();
	~Save();

	static Save& current()
	{
		static Save game;
		return game;
	}

	/*template<typename T>
	void AddData(const char* key, T& data);*/

	void AddData(const char* key, char* data);
	void AddData(const char* key, std::string& data);
	void AddData(const char* key, int data);
	void AddData(const char* key, float data);
	void AddData(const char* key, double data);
	void AddData(const char* key, bool data);

	/*template<typename T>
	T LoadData(const char* key);*/

	void DeleteData(const char* key);

	void ClearData();
};