#include <boost/python.hpp>
#include "G4HCofThisEvent.hh"


using namespace boost::python;

void export_G4HCofThisEvent()
{
  class_<G4HCofThisEvent>
    ("G4HCofThisEvent")
    ;
}
