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

	Wrapper(T* DataPtr_)
	{
		DataPtr = DataPtr_;
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
			T* newPtr = (original.DataPtr != nullptr) ? original.DataPtr->clone() : nullptr;

			if (DataPtr != nullptr) delete DataPtr;

			DataPtr = newPtr;
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
