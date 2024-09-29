#include "EventAction.hh"
#include "G4Event.hh"
#include "G4SystemOfUnits.hh"
#include "G4ParticleDefinition.hh"
#include "G4AnalysisManager.hh"

EventAction::EventAction()
    : G4UserEventAction()
{
}

EventAction::~EventAction()
{
}

void EventAction::BeginOfEventAction(const G4Event *event)
{
    auto analysisManager = G4AnalysisManager::Instance();

    G4double priX0 = event->GetPrimaryVertex()->GetX0();
    G4double priY0 = event->GetPrimaryVertex()->GetY0();
    G4double priZ0 = event->GetPrimaryVertex()->GetZ0();

    G4ThreeVector priMomenDir = event->GetPrimaryVertex()->GetPrimary()->GetMomentumDirection();
    G4double theta = priMomenDir.theta();
    G4double phi = priMomenDir.phi();
    G4double priKinetic = event->GetPrimaryVertex()->GetPrimary()->GetKineticEnergy();
    G4String priParName = event->GetPrimaryVertex()->GetPrimary()->GetParticleDefinition()->GetParticleName();

    // G4cout << "Primary particle: " << priParName << G4endl;
    // G4cout << "POS (X0): " << priX0 / cm << " cm " << G4endl;
    // G4cout << "POS (Y0): " << priY0 / cm << " cm " << G4endl;
    // G4cout << "POS (Z0): " << priZ0 / cm << " cm " << G4endl;
    // G4cout << "Momentum Dir (X): " << priMomenDir.getX() << G4endl;
    // G4cout << "Momentum Dir (Y): " << priMomenDir.getY() << G4endl;
    // G4cout << "Momentum Dir (Z): " << priMomenDir.getZ() << G4endl;
    // G4cout << "Kinetic Energy: " << priKinetic / MeV << " MeV " << G4endl;

    analysisManager->FillNtupleSColumn(0, priParName);
    analysisManager->FillNtupleDColumn(1, priX0);
    analysisManager->FillNtupleDColumn(2, priY0);
    analysisManager->FillNtupleDColumn(3, priZ0);
    analysisManager->FillNtupleDColumn(4, priMomenDir.getX());
    analysisManager->FillNtupleDColumn(5, priMomenDir.getY());
    analysisManager->FillNtupleDColumn(6, priMomenDir.getZ());
    analysisManager->FillNtupleDColumn(7, phi);
    analysisManager->FillNtupleDColumn(8, theta);
    analysisManager->FillNtupleDColumn(9, priKinetic / MeV);
    analysisManager->AddNtupleRow();
}

void EventAction::EndOfEventAction(const G4Event *)
{
}