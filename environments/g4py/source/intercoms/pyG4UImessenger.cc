#include <boost/python.hpp>
#include "G4UIcommand.hh"
#include "G4UImessenger.hh"

using namespace boost::python;

namespace pyG4UImessenger {

struct CB_G4UImessenger :
  G4UImessenger, wrapper<G4UImessenger> {

  void SetNewValue(G4UIcommand *cmd, G4String newvalue) {
    get_override("SetNewValue")(cmd, newvalue);
  }

};

}

using namespace pyG4UImessenger;

// ====================================================================
// module definition
// ====================================================================
void export_G4UImessenger()
{
  class_<CB_G4UImessenger, boost::noncopyable>
    ("G4UImessenger", "UI messenger")
    .def("SetNewValue", pure_virtual(&G4UImessenger::SetNewValue))
    ;
}
