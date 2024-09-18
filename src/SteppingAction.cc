#include "SteppingAction.hh"
#include "G4Step.hh"

SteppingAction::SteppingAction()
    : G4UserSteppingAction()
{
}

void SteppingAction::UserSteppingAction(const G4Step *)
{
}