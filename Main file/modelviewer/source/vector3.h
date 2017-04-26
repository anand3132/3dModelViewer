

#ifndef VECTOR3_H
#define VECTOR3_H

#include "pxMath.h"

//using namespace myMath;
//-------template type definition for float
template<class T>
class vector3;
typedef vector3<float> vector3f;

//-------template type definition for int
template<class T>
class vector3;		
typedef vector3<int> vector3i;

//template class 
template<class T>
class vector3
{
public:
	T x, y, z;
	//vector3<T>(int xx, int yy, int zz)			{	x=xx;	y=yy;	z=zz;	}

	//construtor
	vector3<T>()								{	x=y=z=0;				}
	vector3<T>(float xx, float yy, float zz)	{	x=xx;	y=yy;	z=zz;	}
	vector3<T>(const vector3<T>& v)				{	x=v.x;	y=v.y;	z=v.z;	}
	vector3<T>(T *v)							{	x=v[0];	y=v[1];	z=v[2];	}

	~vector3<T>(){}

	//overload functions
	vector3<T> operator+(const vector3<T>& v)	{	return vector3<T>(x+v.x, y+v.y, z+v.z);	}
	vector3<T> operator-(const vector3<T>& v)	{	return vector3<T>(x-v.x, y-v.y, z-v.z);	}
	
	vector3<T> operator*(const int n)			{	return vector3<T>(x*n, y*n, z*n);	}
	vector3<T> operator*(const float n)			{	return vector3<T>(x*n, y*n, z*n);	}
	
	
	vector3<T> operator/(const short n)	const			{	return vector3<T>(x/n, y/n, z/n);			}
	vector3<T> operator/(const unsigned short n)const	{	return vector3<T>(x/n, y/n, z/n);			}
	vector3<T> operator/(const int n)		const		{	return vector3<T>(x/n, y/n, z/n);			}
	vector3<T> operator/(const unsigned int n)	const	{	return vector3<T>(x/n, y/n, z/n);			}
	vector3<T> operator/(const float n)	const			{	return vector3<T>(x/n, y/n, z/n);			}
	
	// vetex functions
	void set(T xx, T yy, T zz)		{	x=xx;	y=yy;	z=zz;	}
	void zero()						{	x=y=z=0;	}
	
	T lengthSquared()				{	return (x*x+y*y+z*z);					}
	T length()						{	return pxMath::SQRT(lengthSquared());	}

	T dot(const vector3<T>& v)	{	return x*v.x + y*v.y + z*v.z;	}
	
	vector3<T> negative()	{	return vector3(-x, -y, -z);	}

	vector3<T> cross(const vector3<T>& v)
	{
		vector3<T> res;
		res.x=y*v.z-z*v.y;
		res.y=z*v.x-x*v.z;
		res.z=x*v.y-y*v.x;
		return res;
	}
	
	T normalize()		//??
	{
		T n, oon;
		n=lengthSquared();
		if(n==0.0f || n==1.0f) return 0.0f;
		
		n=pxMath::SQRT(n);
		oon = 1.0f;
		
		oon/=n;
		
		x*=oon;
		y*=oon;
		z*=oon;
		
		return oon;
	}
	
};

#endif