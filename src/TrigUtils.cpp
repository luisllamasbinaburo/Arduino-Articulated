/***************************************************
Copyright (c) 2017 Luis Llamas
(www.luisllamas.es)

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License
****************************************************/

#include "TrigUtils.h"

float TrigUtils::Pythagoras(const float& X, const float& Y)
{
	const float D = sqrt(X * X + Y * Y);
	return D;
}

float TrigUtils::Pythagoras(const float& X, const float& Y, const float& Z)
{
	const float D = sqrt(X * X + Y * Y + Z * Z);
	return D;
}

float TrigUtils::SolveCosine(const float& L1, const float& L2, const float& angle3)
{
	const float L3 = sqrt(L1 * L1 + L2 * L2 - 2 * L1 * L2 * cos(angle3));
	return L3;
}

float TrigUtils::SolveInverseCosine(const float& L1, const float& L2, const float& L3)
{
	const float angle3 = acos((L1 * L1 + L2 * L2 - L3 * L3) / (2 * L1 * L2));
	return angle3;
}

float TrigUtils::SolveSin(const float& L1, const float& angle1, const float& angle2)
{
	const float L2 = L1 * sin(angle2) / sin(angle1);
	return L2;
}

float TrigUtils::AbsoluteToRelative(float absolute1, float absolute2, bool inner)
{
	return inner ? absolute2 - absolute1 + PI : absolute2 - absolute1;
}

float TrigUtils::RelativeToAbsolute1(float relative12, float absolute2, bool inner)
{
	return inner ? absolute2 - relative12 + PI : absolute2 - relative12;
}

float TrigUtils::RelativeToAbsolute2(float relative12, float absolute1, bool inner)
{
	return inner ? absolute1 + relative12 - PI : absolute1 + relative12;
}

void TrigUtils::SolveTriangle(float& X, float& Y, float& L1, float& L2, bool UseInnerRelativeAngles,
	float& D, float& AbsoluteAngle1, float& AbsoluteAngle2, float& RelativeAngle12)
{
	const float angle_0 = atan2(Y, X);
	D = Pythagoras(X, Y);

	const float angle_l1 = SolveInverseCosine(D, L2, L1);
	const float angle_l2 = SolveInverseCosine(D, L1, L2);
	const float angle_D = PI - angle_l1 - angle_l2;

	AbsoluteAngle1 = angle_0 + angle_l2;
	RelativeAngle12 = UseInnerRelativeAngles ? angle_D : angle_D - PI;
	AbsoluteAngle2 = RelativeToAbsolute2(RelativeAngle12, AbsoluteAngle1, UseInnerRelativeAngles);
}
