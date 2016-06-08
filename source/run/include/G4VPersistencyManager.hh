// This code implementation is the intellectual property of
// the RD44 GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4VPersistencyManager.hh,v 2.1 1998/07/12 03:08:33 urbi Exp $
// GEANT4 tag $Name: geant4-00 $
//

#ifndef G4VPersistencyManager_h
#define G4VPersistencyManager_h 1

#include "globals.hh"

class G4Event;
class G4Run;
class G4VPhysicalVolume;

class G4VPersistencyManager 
{
  public:
      static G4VPersistencyManager* GetPersistencyManager();

  protected:
      G4VPersistencyManager();

  public:
      virtual ~G4VPersistencyManager();

  private: 
      static G4VPersistencyManager * fPersistencyManager;

  public:
      virtual G4bool Store(const G4Event* anEvent)=0;
      virtual G4bool Store(const G4Run* aRun)=0;
      virtual G4bool Store(const G4VPhysicalVolume* theWorld)=0;

      virtual G4bool Retrieve(G4Event*& anEvent)=0;
      virtual G4bool Retrieve(G4Run*& aRun)=0;
      virtual G4bool Retrieve(G4VPhysicalVolume*& theWorld)=0;

};




#endif
