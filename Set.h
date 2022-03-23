#pragma once

template <typename KeyType, typename DataType>
class SetElement
{
public:
	KeyType key;
	DataType data;
	SetElement() :key(), data() {}
	SetElement(KeyType _key, DataType _data) :key(_key), data(_data) {}
};