#include "generator.hh"
#include "math.h"



PrimaryGenerator::PrimaryGenerator()
{
    fParticleGun=new G4ParticleGun(1);
    G4ParticleTable *ptable = G4ParticleTable::GetParticleTable();
    G4ThreeVector pos(0.0050*m,0.0025*m,2.5*m);
    G4ThreeVector mom(0,0,-1);
    fParticleGun->SetParticlePosition(pos);
    fParticleGun->SetParticleMomentumDirection(mom);
    fParticleGun->SetParticleMomentum(1*GeV);
    fParticleGun->SetParticleDefinition(G4MuonMinus::Definition());    
}
PrimaryGenerator::~PrimaryGenerator()
{
    delete fParticleGun;
}

void PrimaryGenerator::GeneratePrimaries(G4Event*anEvent)
{
    fParticleGun->GeneratePrimaryVertex(anEvent);
}