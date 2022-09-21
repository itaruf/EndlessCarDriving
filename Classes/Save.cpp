#include "Save.h"

Save::Save()
{
}

Save::~Save()
{
}

void Save::AddData(const char* key, char* value)
{
	data->setStringForKey(key, value);
}

void Save::AddData(const char* key, std::string& value)
{
	data->setStringForKey(key, value);
}

void Save::AddData(const char* key, int value)
{
	data->setIntegerForKey(key, value);
}

void Save::AddData(const char* key, float value)
{
	data->setFloatForKey(key, value);
}

void Save::AddData(const char* key, double value)
{
	data->setDoubleForKey(key, value);
}

void Save::AddData(const char* key, bool value)
{
	data->setBoolForKey(key, value);
}

//template<typename T>
//T Save::LoadData(const char* key)
//{
//
//}

void Save::DeleteData(const char* key)
{
	data->deleteValueForKey(key);
}

void Save::ClearData()
{
	data->flush();
}
