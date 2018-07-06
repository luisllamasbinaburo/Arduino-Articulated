/***************************************************
Copyright (c) 2017 Luis Llamas
(www.luisllamas.es)

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License
****************************************************/

#include "ArticulatedQuadrilateral3D.h"
#include "ArticulatedTriangle3D.h"
#include "ArticulatedTriangle2D.h"
#include "ArticulatedQuadrilateral2D.h"

ArticulatedTriangle2D trig(100, 50, false);
ArticulatedQuadrilateral2D quad(100, 50, 30, false);
ArticulatedTriangle3D trig3D(100, 50, false);
ArticulatedQuadrilateral3D quad3D(100, 50, 30, false);

void Debug(ArticulatedTriangle2D& tri)
{
	Serial.print("Target X:\t");
	Serial.println(tri.Target.X, 4);
	Serial.print("Target Y:\t");
	Serial.println(tri.Target.Y, 4);

	Serial.print("Abs. Angle1:\t");
	Serial.println(degrees(tri.AbsoluteAngle1), 4);
	Serial.print("Abs. Angle2:\t");
	Serial.println(degrees(tri.AbsoluteAngle2), 4);

	Serial.print("Rel. Angle12:\t");
	Serial.println(degrees(tri.RelativeAngle12), 4);
}

void Debug(ArticulatedTriangle3D& tri)
{
	Serial.print("Target X:\t");
	Serial.println(tri.Target.X, 4);
	Serial.print("Target Y:\t");
	Serial.println(tri.Target.Y, 4);
	Serial.print("Target Z:\t");
	Serial.println(tri.Target.Z, 4);

	Serial.print("Abs. Angle0:\t");
	Serial.println(degrees(tri.AbsoluteAngle0), 4);
	Serial.print("Abs. Angle1:\t");
	Serial.println(degrees(tri.AbsoluteAngle1), 4);
	Serial.print("Abs. Angle2:\t");
	Serial.println(degrees(tri.AbsoluteAngle2), 4);

	Serial.print("Rel. Angle12:\t");
	Serial.println(degrees(tri.RelativeAngle12), 4);
}

void Debug(ArticulatedQuadrilateral2D& qua)
{
	Serial.print("Target X:\t");
	Serial.println(qua.Target.X, 4);
	Serial.print("Target Y:\t");
	Serial.println(qua.Target.Y, 4);

	Serial.print("Abs. Angle 1:\t");
	Serial.println(degrees(qua.AbsoluteAngle1), 4);
	Serial.print("Abs. Angle 2:\t");
	Serial.println(degrees(qua.AbsoluteAngle2), 4);
	Serial.print("Abs. Angle 3:\t");
	Serial.println(degrees(qua.AbsoluteAngle3), 4);

	Serial.print("Rel. Angle 12:\t");
	Serial.println(degrees(qua.RelativeAngle12), 4);
	Serial.print("Rel. Angle 23:\t");
	Serial.println(degrees(qua.RelativeAngle23), 4);
}

void Debug(ArticulatedQuadrilateral3D& qua)
{
	Serial.print("Target X:\t");
	Serial.println(qua.Target.X, 4);
	Serial.print("Target Y:\t");
	Serial.println(qua.Target.Y, 4);
	Serial.print("Target Z:\t");
	Serial.println(qua.Target.Z, 4);

	Serial.print("Abs. Angle 0:\t");
	Serial.println(degrees(qua.AbsoluteAngle0), 4);
	Serial.print("Abs. Angle 1:\t");
	Serial.println(degrees(qua.AbsoluteAngle1), 4);
	Serial.print("Abs. Angle 2:\t");
	Serial.println(degrees(qua.AbsoluteAngle2), 4);
	Serial.print("Abs. Angle 3:\t");
	Serial.println(degrees(qua.AbsoluteAngle3), 4);

	Serial.print("Rel. Angle 12:\t");
	Serial.println(degrees(qua.RelativeAngle12), 4);
	Serial.print("Rel. Angle 23:\t");
	Serial.println(degrees(qua.RelativeAngle23), 4);
}

void setup()
{
	Serial.begin(115200);
	while (!Serial) { ; }

	Serial.println(F("**** TRIG2D ****"));
	Serial.println(F("Solve Direct Absolute"));
	trig.SolveDirectAbsolute(radians(55), radians(-20));
	Debug(trig);

	Serial.println(F("Solve Direct Relative"));
	trig.SolveDirectRelative(radians(55), radians(-75));
	Debug(trig);

	Serial.println(F("Solve Inverse"));
	trig.Target.X = 104.3423;
	trig.Target.Y = 64.8141;
	trig.SolveReverse();
	Debug(trig);
	

	Serial.println(F(""));
	Serial.println(F("**** TRIG3D ****"));
	Serial.println(F("Solve Direct Absolute"));
	trig3D.SolveDirectAbsolute(radians(30), radians(55), radians(-20));
	Debug(trig3D);

	Serial.println(F("Solve Direct Relative"));
	trig3D.SolveDirectRelative(radians(30), radians(55), radians(-75));
	Debug(trig3D);

	Serial.println(F("Solve Inverse"));
	trig3D.Target.X = 90.3631;
	trig3D.Target.Y = 52.1711;
	trig3D.Target.Z = 64.8141;
	trig3D.SolveReverse();
	Debug(trig3D);


	Serial.println(F(""));
	Serial.println(F("**** QUAD2D ****"));
	Serial.println(F("Solve Direct Absolute"));
	quad.SolveDirectAbsolute(radians(55), radians(-20), radians(-70));
	Debug(quad);

	Serial.println(F("Solve Direct Relative"));
	quad.SolveDirectRelative(radians(55), radians(-75), radians(-50));
	Debug(quad);

	Serial.println(F("Solve Inverse"));
	quad.Target.X = 114.60289;
	quad.Target.Y = 36.62342;
	quad.SolveReverse(radians(-70));
	Debug(quad);


	Serial.println(F(""));
	Serial.println(F("**** QUAD3D ****"));
	Serial.println(F("Solve Direct Absolute"));
	quad3D.SolveDirectAbsolute(radians(30), radians(55), radians(-20), radians(-70));
	Debug(quad3D);

	Serial.println(F("Solve Direct Relative"));
	quad3D.SolveDirectRelative(radians(30), radians(55), radians(-75), radians(-50));
	Debug(quad3D);

	Serial.println(F("Solve Inverse"));
	quad3D.Target.X = 99.2490;
	quad3D.Target.Y = 57.3014;
	quad3D.Target.Z = 36.62342;
	quad3D.SolveReverse(radians(-70));
	Debug(quad3D);
}

void loop()
{
	// Do nothing
	delay(10000);
}
