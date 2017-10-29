#include <boost/python.hpp>
#include "G4UIcmdWithAnInteger.hh"
#include "G4UIcmdWithAString.hh"
#include "G4UImessenger.hh"

using namespace boost::python;

// ====================================================================
// module definition
// ====================================================================
void export_G4UIcmdWith()
{
  class_<G4UIcmdWithAnInteger, boost::noncopyable, bases<G4UIcommand>>
    ("G4UIcmdWithAnInteger", init<const char *,G4UImessenger *>())
    .def("GetNewIntValue", &G4UIcmdWithAnInteger::GetNewIntValue)
    .staticmethod("GetNewIntValue")
    .def("SetParameterName", &G4UIcmdWithAnInteger::SetParameterName)
    .def("SetDefaultValue", &G4UIcmdWithAnInteger::SetDefaultValue)
    ;
  class_<G4UIcmdWithAString, boost::noncopyable, bases<G4UIcommand>>
    ("G4UIcmdWithAString", init<const char *,G4UImessenger *>())
    .def("SetParameterName", &G4UIcmdWithAString::SetParameterName)
    .def("SetDefaultValue", &G4UIcmdWithAString::SetDefaultValue)
    ;
}

