/***************************************************
Copyright (c) 2017 Luis Llamas
(www.luisllamas.es)

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License
 ****************************************************/
 
#include "ArticulatedQuadrilateral3D.h"

void ArticulatedQuadrilateral3D::SolveDirectAbsolute(float angle0, float angle1, float angle2, float angle3)
{
	AbsoluteAngle0 = angle0;
	AbsoluteAngle1 = angle1;
	AbsoluteAngle2 = angle2;
	AbsoluteAngle3 = angle3;
	RelativeAngle12 = TrigUtils::AbsoluteToRelative(AbsoluteAngle1, AbsoluteAngle2, UseInnerRelativeAngles);
	RelativeAngle23 = TrigUtils::AbsoluteToRelative(AbsoluteAngle2, AbsoluteAngle3, UseInnerRelativeAngles);

	SolveDirect();
}

void ArticulatedQuadrilateral3D::SolveDirectRelative(float angle0, float angle1, float angle2, float angle3)
{
	AbsoluteAngle0 = angle0;
	AbsoluteAngle1 = angle1;
	RelativeAngle12 = angle2;
	RelativeAngle23 = angle3;
	AbsoluteAngle2 = TrigUtils::RelativeToAbsolute2(RelativeAngle12, AbsoluteAngle1, UseInnerRelativeAngles);
	AbsoluteAngle3 = TrigUtils::RelativeToAbsolute2(RelativeAngle23, AbsoluteAngle2, UseInnerRelativeAngles);

	SolveDirect();
}

void ArticulatedQuadrilateral3D::SolveReverse(float absoluteAngle3)
{
	AbsoluteAngle3 = absoluteAngle3;
	AbsoluteAngle0 = atan2(Target.Y, Target.X);
	D = TrigUtils::Pythagoras(Target.X, Target.Y, Target.Z);

	float Lx = TrigUtils::Pythagoras(Target.X, Target.Y);
	float P2x = Lx - L3 * cos(AbsoluteAngle3);
	float P2y = Target.Z - L3 * sin(AbsoluteAngle3);

	float D0;
	TrigUtils::SolveTriangle(P2x, P2y, L1, L2, UseInnerRelativeAngles,
		D0, AbsoluteAngle1, AbsoluteAngle2, RelativeAngle12);

	RelativeAngle23 = TrigUtils::AbsoluteToRelative(AbsoluteAngle2, AbsoluteAngle3, UseInnerRelativeAngles);

}

void ArticulatedQuadrilateral3D::SolveReverse(Point3D target, float absoluteAngle3)
{
	AbsoluteAngle3 = absoluteAngle3;
	Target = target;
	SolveReverse(absoluteAngle3);
}

void ArticulatedQuadrilateral3D::SolveDirect()
{
	const float L = L1 * cos(AbsoluteAngle1) + L2 * cos(AbsoluteAngle2) + L3 * cos(AbsoluteAngle3);
	Target.X = L * cos(AbsoluteAngle0);
	Target.Y = L * sin(AbsoluteAngle0);
	Target.Z = L1 * sin(AbsoluteAngle1) + L2 * sin(AbsoluteAngle2) + L3 * sin(AbsoluteAngle3);
	D = TrigUtils::Pythagoras(Target.X, Target.Y, Target.Z);


}