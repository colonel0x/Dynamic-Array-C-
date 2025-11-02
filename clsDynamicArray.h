#pragma once
#include <iostream>
using namespace std;

template <class DataType>
class clsDynamicArray
{



	int _Size;
	DataType* _TempArray;
public:
	DataType* OriginalArray;
	clsDynamicArray(int size = 0)
	{
		


		OriginalArray = new DataType[size];
		_Size = size;
	};
	~clsDynamicArray()
	{
		if (OriginalArray[0] < 0)
			return;

		delete[]OriginalArray;
	};


	bool SetItem(int Index, DataType value)
	{

		if (Index >= _Size || _Size < 0)
			return false;

		else;
		OriginalArray[Index] = value;
		return true;
	};
	bool IsEmpty()
	{

		if (_Size != 0)
		{
			return true;
		};

		return false;

	}
	int Size()
	{

		return _Size;
	}
	void PrintList()
	{
		if (OriginalArray[0] < 0)
			return;


		for (int i = 0; i < _Size; i++)
		{

			cout << OriginalArray[i] << " ";


		}
		cout << endl;

	}
	bool ReSize(int Size)
	{

		if (Size < 0 || Size == _Size)
		{
			return false;

		};

		if (Size < _Size)
			_Size = Size;

		_TempArray = new DataType[Size];

		for (int i = 0; i < _Size; i++)
		{
			_TempArray[i] = OriginalArray[i];

		};
		delete[]OriginalArray;
		OriginalArray = _TempArray;
		_Size = Size;
		return true;


	}
	DataType GetItem(int Index)
	{

		return OriginalArray[Index];

	};
	void Reverse()
	{

		_TempArray = new DataType[_Size];

		for (int i = 0; i < _Size; i++)
		{
			_TempArray[i] = OriginalArray[(_Size - 1) - i];

		}
		delete[]OriginalArray;
		OriginalArray = _TempArray;

	}
	void Clear()
	{
		if (OriginalArray[0] > 0)
		{
			_TempArray = new DataType[0];
			delete[]OriginalArray;
			OriginalArray = _TempArray;
			_Size = 0;
		}


	};
	bool DeleteItemAt(int Index)
	{

		if (Index > _Size || Index < 0)
		{
			return false;
		}

		_Size--;
		_TempArray = new DataType[_Size];


		for (int i = 0; i < Index; i++)
		{
			_TempArray[i] = OriginalArray[i];

		}

		for (int i = Index; i < _Size; i++)
		{
			_TempArray[i] = OriginalArray[i+1];
		}


		delete[]OriginalArray;
		OriginalArray = _TempArray;
	
		return true;
			
	}
	void DeleteFirstItem()
	{
		DeleteItem(0);
	};
	void DeleteLastItem()
	{
		DeleteItem(_Size - 1);
	};
	int Find(DataType value)
	{
	
		for (int i = 0; i < _Size; i++)
		{
			if (OriginalArray[i] == value)
				return i;
			   


		};
		return -1;
	}
	bool DeleteItem(DataType value)
	{
	
		if (DeleteItemAt(Find(value)) == true)
			return true;
		
		
		return false;
		
	};
	bool InsertAt(int Index,DataType value)
	{
	


		if (Index > _Size || Index < 0)
		{
			return false;
		}

		_Size++;
		_TempArray = new DataType[_Size];

		for (int i = 0; i < Index; i++)
		{
			_TempArray[i] = OriginalArray[i];

		};
		
		for (int i = Index; i < _Size-1; i++)
		{
		
			_TempArray[i + 1] = OriginalArray[i];

		};


		_TempArray[Index] = value;
		delete[]OriginalArray;
		OriginalArray = _TempArray;

		return true;
	}
	bool InsertAtBeginning(DataType value)
	{

		return	InsertAt(0, value);

	}
	bool InsertBefor(int Index,DataType value)
	{
	if(Index < 1)
		return InsertAt(0, value);
	else
		return InsertAt(Index - 1, value);

	
	}
	bool InsertAfter(int Index, DataType value)
	{

		if (Index >= _Size)
			return InsertAt(_Size-1, value);
		else
			return InsertAt(Index + 1, value);

	}
	bool InsertAtEnd(DataType value)
	{

		return	InsertAt(_Size, value);

	}













};

