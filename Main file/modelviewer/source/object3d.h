#ifndef OBJECT3D_H
#define OBJECT3D_H

#include "transformf.h"

#define OBJECT3D_CAMERA		1000

class object3d : public transformf
{
public:
	object3d(int id)
	{
		m_iBaseTypeID=id;
	}

	virtual ~object3d()
	{
	}

private:
	int m_iBaseTypeID;
};
#endif