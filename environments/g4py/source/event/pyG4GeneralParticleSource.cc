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
// $Id: pyG4GeneralParticleSource.cc 76884 2013-11-18 12:54:03Z gcosmo $
// ====================================================================
//   pyG4GeneralParticleSource.cc
//
//                                         2005 Q
// ====================================================================
#include <boost/python.hpp>
#include "G4GeneralParticleSource.hh"

using namespace boost::python;

// ====================================================================
// module definition
// ====================================================================
void export_G4GeneralParticleSource()
{
    class_<G4GeneralParticleSource, boost::noncopyable>
    ("G4GeneralParticleSource", "particle source")
    .def("GeneratePrimaryVertex", &G4GeneralParticleSource::GeneratePrimaryVertex)
    .def("SetParticleDefinition", &G4GeneralParticleSource::SetParticleDefinition)
    .def("GetParticleDefinition", &G4GeneralParticleSource::GetParticleDefinition,
    	 return_value_policy<reference_existing_object>())
    .def("GetParticleMomentumDirection",
	 &G4GeneralParticleSource::GetParticleMomentumDirection)
    .def("GetParticleEnergy",     &G4GeneralParticleSource::GetParticleEnergy)
    .def("SetParticleCharge",     &G4GeneralParticleSource::SetParticleCharge)
    .def("SetParticlePolarization", &G4GeneralParticleSource::SetParticlePolarization)
    .def("GetParticlePolarization", &G4GeneralParticleSource::GetParticlePolarization)
    .def("SetNumberOfParticles",  &G4GeneralParticleSource::SetNumberOfParticles)
    .def("GetNumberOfParticles",  &G4GeneralParticleSource::GetNumberOfParticles)
    .def("GetParticlePosition",   &G4GeneralParticleSource::GetParticlePosition)
    .def("SetParticleTime",       &G4GeneralParticleSource::SetParticleTime)
    .def("GetParticleTime",       &G4GeneralParticleSource::GetParticleTime)
    ;
}
