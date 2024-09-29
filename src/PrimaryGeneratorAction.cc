#include "PrimaryGeneratorAction.hh"

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "G4ios.hh"
#include "G4Event.hh"
#include "G4ParticleGun.hh"
#include "Randomize.hh"

using namespace CLHEP;

PrimaryGeneratorAction::PrimaryGeneratorAction()
{
    particleGun = new G4ParticleGun(1);

    // Particle definition
    G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
    G4String particleName = "e-";
    G4ParticleDefinition *particle = particleTable->FindParticle(particleName);
    particleGun->SetParticleDefinition(particle);
}

PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
    delete particleGun;
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event *anEvent)
{
    G4double GunRadius = 1.25 * mm;
    G4double GunMeanEnergy = 5.9 * MeV;
    G4double GunStdEnergy = 0.051 * MeV;

    // Direction
    G4ThreeVector dir;
    G4double sinTheta, cosTheta, phi;

    sinTheta = RandGauss::shoot(0., 0.001);
    cosTheta = std::sqrt(1 - sinTheta * sinTheta);
    phi = twopi * G4UniformRand();
    dir.set(sinTheta * std::cos(phi), sinTheta * std::sin(phi), cosTheta);
    particleGun->SetParticleMomentumDirection((G4ParticleMomentum)dir);

    // Beam radius
    G4ThreeVector pos;
    G4double rho, alpha;

    rho = G4UniformRand() * GunRadius;
    alpha = G4UniformRand() * twopi;
    pos.setX(rho * std::sin(alpha));
    pos.setY(rho * std::cos(alpha));
    pos.setZ(-0.50138 * cm);
    particleGun->SetParticlePosition(pos * mm);

    // Energy distribution
    G4double ek;
    ek = RandGauss::shoot(GunMeanEnergy, GunStdEnergy);
    particleGun->SetParticleEnergy(ek * MeV);

    particleGun->GeneratePrimaryVertex(anEvent);
}
