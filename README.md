# Librería Arduino Articulated
La librería Articulated implementa los cálculos necesarios para resolver un triángulo o cuadrílátero articulado en 2D o 3D. Estan pensadas para simplificar el control de robots articulados (brazos robóticos, cuadrúpedos, hexápodos, bípedos...)

Más información https://www.luisllamas.es/libreria-arduino-articulated/

## Instrucciones de uso

Cada tipo de polígono de objeto se instancia a través de su constructor correspondiente (ArticulatedTriangle2D, ArticulatedTriangle3D, ArticulatedQuadrilateral2D, ArticulatedQuadrilateral3D) que reciben las longitudes de los brazos que forman cada polígono articulado.

Adicionalmente, el parámetro UseInnerRelativeAngles define si queremos que los ángulos relativos entre segmentos sean interiores o exteriores. Por defecto son exteriores. La librería trabaja en radianes.

La librería Articulated dispone de funciones para la resolución de la cinemática cinemática directa (SolveDirectAbsolute y SolveDirectRelative) o inversa (SolveReverse). 

La función SolveDirectAbsolute considera los ángulos de los segmentos respecto al plano del suelo, mientras que los SolveDirectRelative consideran el ángulo de un segmento respecto al anterior. Normalmente trabajaremos con SolveDirectRelative.

Por otro lado, las funciones de SolveReverse de cuadriláteros requieren pasar como parámetro el ángulo absoluto del último segmento, dado que la resolución de la posición con las longitudes admite múltiples soluciones.


## Triángulo articulado 2D

### Constructor
```c++
ArticulatedTriangle2D(float l1, float l2, bool useInnerRelativeAngles = false)
```

### Uso de ArticulatedTriangle2D
```c++
void SolveDirectAbsolute(float angle1, float angle2);
void SolveDirectRelative(float angle1, float angle2);

void SolveReverse();
void SolveReverse(Point2D target);

bool UseInnerRelativeAngles;
float L1, L2, D;
float AbsoluteAngle1, AbsoluteAngle2, RelativeAngle12;
Point2D Target;
```


## Cuadrilátero articulado 2D
### Constructor
```c++
ArticulatedQuadrilateral2D(float l1, float l2, float l3, bool useInnerRelativeAngles = false) 
```

### Uso de ArticulatedQuadrilateral2D
```c++
void SolveDirectAbsolute(float angle1, float angle2, float angle3);
void SolveDirectRelative(float angle1, float angle2, float angle3);

void SolveReverse(float absoluteAngle3);
void SolveReverse(Point2D target, float absoluteAngle3);

bool UseInnerRelativeAngles;
float L1, L2, L3, D;
float AbsoluteAngle1, AbsoluteAngle2, AbsoluteAngle3, RelativeAngle12, RelativeAngle23;
Point2D Target;
```


## Triángulo articulado 3D
### Constructor
```c++
ArticulatedTriangle3D(float l1, float l2, bool useInnerRelativeAngles = false)

```

### Uso de ArticulatedTriangle3D
```c++
void SolveDirectAbsolute(float angle0, float angle1, float angle2);
void SolveDirectRelative(float angle0, float angle1, float angle2);

void SolveReverse();
void SolveReverse(Point3D target);

bool UseInnerRelativeAngles;
float L1, L2, D;
float AbsoluteAngle0, AbsoluteAngle1, AbsoluteAngle2, RelativeAngle12;
Point3D Target;
```


## Cuadrilátero articulado 3D
### Constructor
```c++
ArticulatedQuadrilateral3D(float l1, float l2, float l3, bool useInnerRelativeAngles = false)
```

### Uso de ArticulatedQuadrilateral3D
```c++
void SolveDirectAbsolute(float angle0, float angle1, float angle2, float angle3);
void SolveDirectRelative(float angle0, float angle1, float angle2, float angle3);

void SolveReverse(float absoluteAngle3);
void SolveReverse(Point3D target, float absoluteAngle3);

bool UseInnerRelativeAngles;
float L1, L2, L3, D;
float AbsoluteAngle0, AbsoluteAngle1, AbsoluteAngle2, AbsoluteAngle3, RelativeAngle12, RelativeAngle23;
Point3D Target;
```


## Ejemplos
La librería Articulated incluye los siguientes ejemplos para ilustrar su uso.

* Triangle2D: Ejemplo que muestra el uso para un triángulo articulado 2D
```c++
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
```

* Quadrilateral2D: Ejemplo que muestra el uso para un cuadrilátero articulado 2D
```c++
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
```

* Triangle3D: Ejemplo que muestra el uso para un triángulo articulado 3D
```c++
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
```

* Quadrilateral3D: Ejemplo que muestra el uso para un cuadrilátero articulado 3D
```c++
#include "ArticulatedQuadrilateral3D.h"

ArticulatedQuadrilateral3D quad3D(100, 50, 30, false);

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
```
