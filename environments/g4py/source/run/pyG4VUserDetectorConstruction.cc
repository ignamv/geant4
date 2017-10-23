//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// $Id: pyG4VUserDetectorConstruction.cc 76884 2013-11-18 12:54:03Z gcosmo $
// ====================================================================
//   pyG4VUserDetectorConstruction.cc
//
//                                         2005 Q
// ====================================================================
#include <boost/python.hpp>
#include "G4VUserDetectorConstruction.hh"
#include "G4VSensitiveDetector.hh"
#include "G4VPhysicalVolume.hh"

using namespace boost::python;

// ====================================================================
// thin wrappers
// ====================================================================
namespace pyG4VUserDetectorConstruction {

struct CB_G4VUserDetectorConstruction :
  G4VUserDetectorConstruction, wrapper<G4VUserDetectorConstruction> {

  G4VPhysicalVolume* Construct() {
    return get_override("Construct")();
  }
  void ConstructSDandField() {
      if (override f = get_override("ConstructSDandField"))
          f();
      else
          G4VUserDetectorConstruction::ConstructSDandField();
  }
  void DefaultConstructSDandField() {
    this->G4VUserDetectorConstruction::ConstructSDandField();
  }
  void SetSensitiveDetector(const G4String &logVolName,
        G4VSensitiveDetector *aSD, G4bool multi) {
    this->G4VUserDetectorConstruction::SetSensitiveDetector(
        logVolName, aSD, multi);
  }

void (G4VUserDetectorConstruction::*f1_SetSensitiveDetector)(const G4String &,
        G4VSensitiveDetector*, G4bool)
  = &G4VUserDetectorConstruction::SetSensitiveDetector;

};

}

using namespace pyG4VUserDetectorConstruction;


// ====================================================================
// module definition
// ====================================================================
void export_G4VUserDetectorConstruction()
{
  class_<CB_G4VUserDetectorConstruction, CB_G4VUserDetectorConstruction*,
    boost::noncopyable>
    ("G4VUserDetectorConstruction",
     "base class of user detector construction")

    .def("SetSensitiveDetector", &CB_G4VUserDetectorConstruction::SetSensitiveDetector)
    .def("Construct",
	 pure_virtual(&G4VUserDetectorConstruction::Construct),
         return_value_policy<reference_existing_object>())
    .def("ConstructSDandField",
        &G4VUserDetectorConstruction::ConstructSDandField,
        &CB_G4VUserDetectorConstruction::DefaultConstructSDandField)
    ;
}
