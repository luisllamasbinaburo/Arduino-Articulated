/***************************************************
Copyright (c) 2017 Luis Llamas
(www.luisllamas.es)

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License
 ****************************************************/

#ifndef _ARTICULATEDTRIANGLE3D_h
#define _ARTICULATEDTRIANGLE3D_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Point3D.h"
#include "TrigUtils.h"

class ArticulatedTriangle3D
{
public:
	ArticulatedTriangle3D(float l1, float l2, bool useInnerRelativeAngles = false)
		: L1(l1), L2(l2), UseInnerRelativeAngles(useInnerRelativeAngles) {};

	void SolveDirectAbsolute(float angle0, float angle1, float angle2);
	void SolveDirectRelative(float angle0, float angle1, float angle2);

	void SolveReverse();
	void SolveReverse(Point3D target);

	bool UseInnerRelativeAngles;
	float L1, L2, D;
	float AbsoluteAngle0, AbsoluteAngle1, AbsoluteAngle2, RelativeAngle12;
	Point3D Target;

protected:
	void SolveDirect();
};


#endif

