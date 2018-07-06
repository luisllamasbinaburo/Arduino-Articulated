/***************************************************
Copyright (c) 2017 Luis Llamas
(www.luisllamas.es)

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License
****************************************************/

#include "ArticulatedTriangle2D.h"

void ArticulatedTriangle2D::SolveDirectAbsolute(float angle1, float angle2)
{
	AbsoluteAngle1 = angle1; 
	AbsoluteAngle2 = angle2;
	RelativeAngle12 = TrigUtils::AbsoluteToRelative(AbsoluteAngle1, AbsoluteAngle2, UseInnerRelativeAngles);

	SolveDirect();
}

void ArticulatedTriangle2D::SolveDirectRelative(float angle1, float angle2)
{
	AbsoluteAngle1 = angle1;
	RelativeAngle12 = angle2;
	AbsoluteAngle2 = TrigUtils::RelativeToAbsolute2(RelativeAngle12, AbsoluteAngle1, UseInnerRelativeAngles);

	SolveDirect();
}

void ArticulatedTriangle2D::SolveReverse()
{
	TrigUtils::SolveTriangle(Target.X, Target.Y, L1, L2, UseInnerRelativeAngles,
		D, AbsoluteAngle1, AbsoluteAngle2, RelativeAngle12);
}

void ArticulatedTriangle2D::SolveReverse(Point2D target)
{
	Target = target;
	SolveReverse();
}

void ArticulatedTriangle2D::SolveDirect()
{
	Target.X = L1 * cos(AbsoluteAngle1) + L2 * cos(AbsoluteAngle2);
	Target.Y = L1 * sin(AbsoluteAngle1) + L2 * sin(AbsoluteAngle2);
	D = TrigUtils::Pythagoras(Target.X, Target.Y);
}