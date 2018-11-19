/***************************************************
Copyright (c) 2017 Luis Llamas
(www.luisllamas.es)

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License
****************************************************/

#include "ArticulatedQuadrilateral2D.h"

ArticulatedQuadrilateral2D quad(100, 50, 30, false);

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

void setup()
{
	Serial.begin(115200);
	while (!Serial) { ; }

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
}

void loop()
{
	// Do nothing
	delay(10000);
}
