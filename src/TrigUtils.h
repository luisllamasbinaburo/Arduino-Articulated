/***************************************************
Copyright (c) 2017 Luis Llamas
(www.luisllamas.es)

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License
****************************************************/

#ifndef _TRIGUTILS_hº
#define _TRIGUTILS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

class TrigUtils
{
 public:
	static float Pythagoras(const float& X, const float& Y);
	static float Pythagoras(const float& X, const float& Y, const float& Z);

	static float SolveCosine(const float& L1, const float& L2, const float& angle3);
	static float SolveInverseCosine(const float& L1, const float& L2, const float& L3);
	static float SolveSin(const float& L1, const float& angle1, const float& angle2);

	static float AbsoluteToRelative(float absolute1, float absolute2, bool inner);
	static float RelativeToAbsolute1(float relative12, float absolute2, bool inner);
	static float RelativeToAbsolute2(float relative12, float absolute1, bool inner);

	static void SolveTriangle(float& X, float& Y, float& L1, float& L2, bool UseInnerRelativeAngles,
							  float& D, float& AbsoluteAngle1, float& AbsoluteAngle2, float& RelativeAngle12);
};

#endif

