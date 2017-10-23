#include <boost/python.hpp>
#include "G4UIsession.hh"

using namespace boost::python;

namespace pyG4UIsession {

class  CB_G4UIsession :
    public G4UIsession,
    public wrapper<G4UIsession> {

public:
  CB_G4UIsession() : G4UIsession() { }
  ~CB_G4UIsession() { }

  G4int ReceiveG4cout(const G4String &str) {
		if (override f = get_override("ReceiveG4cout"))
            return f(str);
        else
            return G4UIsession::ReceiveG4cout(str);
  }
  G4int DefaultReceiveG4cout(const G4String &str) {
    this->G4UIsession::ReceiveG4cout(str);
  }
  G4int ReceiveG4cerr(const G4String &str) {
		if (override f = get_override("ReceiveG4cerr"))
            return f(str);
        else
            return G4UIsession::ReceiveG4cerr(str);
  }
  G4int DefaultReceiveG4cerr(const G4String &str) {
    this->G4UIsession::ReceiveG4cerr(str);
  }
};

}

using namespace pyG4UIsession;

// ====================================================================
// module definition
// ====================================================================
void export_G4coutDestination()
{
  class_<G4UIsession, G4UIsession*>("G4UIsession");
  class_<CB_G4UIsession, CB_G4UIsession*, boost::noncopyable>
    ("G4UIsession")
    .def("ReceiveG4cout",   &G4UIsession::ReceiveG4cout,
            &CB_G4UIsession::DefaultReceiveG4cout)
    .def("ReceiveG4cerr",   &G4UIsession::ReceiveG4cerr,
            &CB_G4UIsession::DefaultReceiveG4cerr)
    ;
}
