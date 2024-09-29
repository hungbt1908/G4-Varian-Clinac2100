#ifndef DetectorMessenger_h
#define DetectorMessenger_h 1

#include "G4UImessenger.hh"
#include "globals.hh"

class G4UIdirectory;
class G4UIcmdWithADoubleAndUnit;
class G4UIcmdWithAnInteger;
class DetectorConstruction;

class DetectorMessenger : public G4UImessenger
{

public:
    DetectorMessenger(DetectorConstruction *);
    ~DetectorMessenger();
    void SetNewValue(G4UIcommand *, G4String);

private:
    G4UIdirectory *linacDir;
    G4UIcmdWithADoubleAndUnit *setIsocenterCmd;
    G4UIcmdWithADoubleAndUnit *setJaw1XApertureCmd;
    G4UIcmdWithADoubleAndUnit *setJaw2XApertureCmd;
    G4UIcmdWithADoubleAndUnit *setJaw1YApertureCmd;
    G4UIcmdWithADoubleAndUnit *setJaw2YApertureCmd;
    G4UIcmdWithADoubleAndUnit *setPhantomXDimCmd;
    G4UIcmdWithADoubleAndUnit *setPhantomYDimCmd;
    G4UIcmdWithADoubleAndUnit *setPhantomZDimCmd;
    G4UIcmdWithAnInteger *setNOfVoxelsAlongXCmd;
    G4UIcmdWithAnInteger *setNOfVoxelsAlongYCmd;
    G4UIcmdWithAnInteger *setNOfVoxelsAlongZCmd;

    DetectorConstruction *fDetectorConstruction;
};
#endif