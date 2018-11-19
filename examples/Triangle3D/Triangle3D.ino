/***************************************************
Copyright (c) 2017 Luis Llamas
(www.luisllamas.es)

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License
****************************************************/

#include "ArticulatedTriangle3D.h"

ArticulatedTriangle3D trig3D(100, 50, false);

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

void setup()
{
	Serial.begin(115200);
	while (!Serial) { ; }

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
}

void loop()
{
	// Do nothing
	delay(10000);
}
