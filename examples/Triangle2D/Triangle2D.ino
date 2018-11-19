/***************************************************
Copyright (c) 2017 Luis Llamas
(www.luisllamas.es)

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License
****************************************************/

#include "ArticulatedTriangle2D.h"

ArticulatedTriangle2D trig(100, 50, false);

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
}

void loop()
{
	// Do nothing
	delay(10000);
}
