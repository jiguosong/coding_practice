/*
 * Arrays.h
 *
 *  Created on: Dec 4, 2016
 *      Author: songjiguo
 */

#ifndef JSARRAYS_H_
#define JSARRAYS_H_

#ifdef USE_VAL_ARRAY

#include <valarray>
typedef std::valarray<double> JSArray;

#else
// ifdef USE_VAL_ARRAY
class JSArray
{
public:
	explicit JSArray(unsigned long size = 0);
	JSArray(const JSArray& original);
	~JSArray();

	JSArray& operator=(const JSArray& original);
	JSArray& operator=(const double& val);

	JSArray& operator+=(const JSArray& operand);
	JSArray& operator-=(const JSArray& operand);
	JSArray& operator/=(const JSArray& operand);
	JSArray& operator*=(const JSArray& operand);

	JSArray& operator+=(const double& operand);
	JSArray& operator-=(const double& operand);
	JSArray& operator/=(const double& operand);
	JSArray& operator*=(const double& operand);

	JSArray apply(double f(double)) const;
	inline double operator[](unsigned long i) const;
	inline double& operator[](unsigned long i);
	inline unsigned long size() const;
	void resize(unsigned long newSize);
	double sum() const;
	double min() const;
	double max() const;
private:
	double* ValuesPtr;
	double* EndPtr;
	unsigned long Size;
	unsigned long Capacity;
};

inline double JSArray::operator[](unsigned long i) const
{
#ifdef RANGE_CHECKING
	if (i >= Size)
	{
		throw("Index out of bounds");
	}
#endif
	return ValuesPtr[i];
}
inline double& JSArray::operator[](unsigned long i)
{
#ifdef RANGE_CHECKING

	if (i >= Size)
	{
		throw("Index out of bounds");
	}
#endif
	return ValuesPtr[i];
}
inline unsigned long JSArray::size() const
{
	return Size;
}
#endif // ifdef USE_VAL_ARRAY

#endif /* JSARRAYS_H_ */
