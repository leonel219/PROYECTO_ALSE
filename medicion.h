#ifndef _MEDICION
#define _MEDICION

#include <iostream>

using namespace std;

class  Medicion{
public:
  friend ostream& operator<<(ostream& out, const Medicion &a );
  double promtemperatura ();
  double promhumedad();
  double promprecipitacion();
  double promintensidadluz();	






};
#endif
