#include <boost/python.hpp>
#include "G4SDManager.hh"

using namespace boost::python;

void export_G4SDManager() {
  class_<G4SDManager, boost::noncopyable>("G4SDManager", no_init)
    .def("AddNewDetector", &G4SDManager::AddNewDetector)
    .def("Activate", &G4SDManager::Activate)
    .def("GetSDMpointer", &G4SDManager::GetSDMpointer,
        "Get an instance of G4SDManager",
        return_value_policy<reference_existing_object>())
    .staticmethod("GetSDMpointer")
    ;
}
