#include "EventAction.hh"
#include "G4Event.hh"

EventAction::EventAction()
    : G4UserEventAction()
{
}

EventAction::~EventAction()
{
}

void EventAction::BeginOfEventAction(const G4Event *)
{
}

void EventAction::EndOfEventAction(const G4Event *)
{
}