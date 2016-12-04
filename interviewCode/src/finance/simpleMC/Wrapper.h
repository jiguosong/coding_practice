/*
 * Wrapper.h
 *
 *  Created on: Dec 4, 2016
 *      Author: songjiguo
 */

#ifndef WRAPPER_H_
#define WRAPPER_H_

template<class T>
class Wrapper
{
public:
	Wrapper()
	{
		DataPtr = nullptr;
	}

	Wrapper(const T& inner)
	{
		DataPtr = inner.clone();
	}

	~Wrapper()
	{
		if (DataPtr != nullptr) delete DataPtr;  // why check nullptr?
	}

	Wrapper(const Wrapper<T>& original)
	{
		if (original.DataPtr != nullptr)
			DataPtr = original.DataPtr->clone();
		else
			DataPtr = nullptr;
	}

	Wrapper& operator=(const Wrapper<T>& original)
	{
		if (this != &original)
		{
			if (DataPtr != nullptr) delete DataPtr;
			DataPtr = (original.DataPtr != nullptr) ? original.DataPtr->clone() : 0;
		}
		return *this;
	}

	T& operator*()
	{
		return *DataPtr;
	}

	const T& operator*() const
	{
		return *DataPtr;
	}

	const T* const operator->() const
	{
		return DataPtr;
	}

	T* operator->()
	{
		return DataPtr;
	}

private:
	T* DataPtr;

};

#endif /* WRAPPER_H_ */
