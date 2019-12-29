/***************************************************
Copyright (c) 2017 Luis Llamas
(www.luisllamas.es)

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License
****************************************************/


#ifndef _ARTICULATEDQUADRILATERAL_h
#define _ARTICULATEDQUADRILATERAL_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Point2D.h"
#include "TrigUtils.h"

class ArticulatedQuadrilateral2D
{
public:
	ArticulatedQuadrilateral2D(float l1, float l2, float l3, bool useInnerRelativeAngles = false) 
		: L1(l1), L2(l2), L3(l3), UseInnerRelativeAngles(useInnerRelativeAngles) {};

	void SolveDirectAbsolute(float angle1, float angle2, float angle3);
	void SolveDirectRelative(float angle1, float angle2, float angle3);

	void SolveReverse(float absoluteAngle3);
	void SolveReverse(Point2D target, float absoluteAngle3);

	bool UseInnerRelativeAngles;
	float L1, L2, L3, D;
	float AbsoluteAngle1, AbsoluteAngle2, AbsoluteAngle3, RelativeAngle12, RelativeAngle23;
	Point2D Target;

protected:
	void SolveDirect();
};

#endif

