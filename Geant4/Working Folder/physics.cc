#include "physics.hh"


physicslist::physicslist(){
        RegisterPhysics(new G4EmStandardPhysics());
        RegisterPhysics(new G4OpticalPhysics());
        RegisterPhysics(new G4DecayPhysics());
        RegisterPhysics(new G4RadioactiveDecayPhysics());

}


physicslist::~physicslist(){}