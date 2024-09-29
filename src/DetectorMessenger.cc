#include "DetectorMessenger.hh"
#include "DetectorConstruction.hh"
#include "G4UIdirectory.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"
#include "G4UIcmdWithAString.hh"
#include "G4UIcmdWith3Vector.hh"
#include "G4UIcmdWithAnInteger.hh"
#include "G4UIcmdWith3VectorAndUnit.hh"
#include "G4UIcmdWithAString.hh"
#include "G4UIcmdWithABool.hh"

DetectorMessenger::DetectorMessenger(DetectorConstruction *pDetectorConstruction)
    : G4UImessenger(), fDetectorConstruction(pDetectorConstruction)
{
    // create new directory
    linacDir = new G4UIdirectory("/LINAC/Geometry/");
    linacDir->SetGuidance("Command to change LGK setups");

    //
    setIsocenterCmd = new G4UIcmdWithADoubleAndUnit("/LINAC/Geometry/SetIsocenter", this);
    setIsocenterCmd->SetGuidance("Set isocenter distance.");
    setIsocenterCmd->SetParameterName("isocenter", false);
    setIsocenterCmd->SetUnitCategory("Length");
    setIsocenterCmd->AvailableForStates(G4State_PreInit, G4State_Idle);

    //
    setJaw1XApertureCmd = new G4UIcmdWithADoubleAndUnit("/LINAC/Geometry/SetJaw1XAperture", this);
    setJaw1XApertureCmd->SetGuidance("Set Jaw 1X aperture.");
    setJaw1XApertureCmd->SetParameterName("jaw1XAperture", false);
    setJaw1XApertureCmd->SetUnitCategory("Length");
    setJaw1XApertureCmd->AvailableForStates(G4State_PreInit, G4State_Idle);

    //
    setJaw2XApertureCmd = new G4UIcmdWithADoubleAndUnit("/LINAC/Geometry/SetJaw2XAperture", this);
    setJaw2XApertureCmd->SetGuidance("Set Jaw 2X aperture.");
    setJaw2XApertureCmd->SetParameterName("jaw2XAperture", false);
    setJaw2XApertureCmd->SetUnitCategory("Length");
    setJaw2XApertureCmd->AvailableForStates(G4State_PreInit, G4State_Idle);

    //
    setJaw1YApertureCmd = new G4UIcmdWithADoubleAndUnit("/LINAC/Geometry/SetJaw1YAperture", this);
    setJaw1YApertureCmd->SetGuidance("Set Jaw 1Y aperture.");
    setJaw1YApertureCmd->SetParameterName("jaw1YAperture", false);
    setJaw1YApertureCmd->SetUnitCategory("Length");
    setJaw1YApertureCmd->AvailableForStates(G4State_PreInit, G4State_Idle);

    //
    setJaw2YApertureCmd = new G4UIcmdWithADoubleAndUnit("/LINAC/Geometry/SetJaw2YAperture", this);
    setJaw2YApertureCmd->SetGuidance("Set Jaw 2Y aperture.");
    setJaw2YApertureCmd->SetParameterName("jaw2YAperture", false);
    setJaw2YApertureCmd->SetUnitCategory("Length");
    setJaw2YApertureCmd->AvailableForStates(G4State_PreInit, G4State_Idle);

    //
    setPhantomXDimCmd = new G4UIcmdWithADoubleAndUnit("/LINAC/Geometry/SetPhantomXDim", this);
    setPhantomXDimCmd->SetGuidance("Set phantom dimension along X axis.");
    setPhantomXDimCmd->SetParameterName("phantomXDim", false);
    setPhantomXDimCmd->SetUnitCategory("Length");
    setPhantomXDimCmd->AvailableForStates(G4State_PreInit, G4State_Idle);

    //
    setPhantomYDimCmd = new G4UIcmdWithADoubleAndUnit("/LINAC/Geometry/SetPhantomYDim", this);
    setPhantomYDimCmd->SetGuidance("Set phantom dimension along Y axis.");
    setPhantomYDimCmd->SetParameterName("phantomYDim", false);
    setPhantomYDimCmd->SetUnitCategory("Length");
    setPhantomYDimCmd->AvailableForStates(G4State_PreInit, G4State_Idle);

    //
    setPhantomZDimCmd = new G4UIcmdWithADoubleAndUnit("/LINAC/Geometry/SetPhantomZDim", this);
    setPhantomZDimCmd->SetGuidance("Set phantom dimension along Z axis.");
    setPhantomZDimCmd->SetParameterName("phantomZDim", false);
    setPhantomZDimCmd->SetUnitCategory("Length");
    setPhantomZDimCmd->AvailableForStates(G4State_PreInit, G4State_Idle);

    //
    setNOfVoxelsAlongXCmd = new G4UIcmdWithAnInteger("/LINAC/Geometry/SetNumberOfVoxelsAlongX", this);
    setNOfVoxelsAlongXCmd->SetGuidance("Set number of voxels along X axis.");
    setNOfVoxelsAlongXCmd->SetParameterName("nOfVoxelsX", false);
    setNOfVoxelsAlongXCmd->AvailableForStates(G4State_Idle, G4State_PreInit);

    //
    setNOfVoxelsAlongYCmd = new G4UIcmdWithAnInteger("/LINAC/Geometry/SetNumberOfVoxelsAlongY", this);
    setNOfVoxelsAlongYCmd->SetGuidance("Set number of voxels along Y axis.");
    setNOfVoxelsAlongYCmd->SetParameterName("nOfVoxelsY", false);
    setNOfVoxelsAlongYCmd->AvailableForStates(G4State_Idle, G4State_PreInit);

    //
    setNOfVoxelsAlongZCmd = new G4UIcmdWithAnInteger("/LINAC/Geometry/SetNumberOfVoxelsAlongZ", this);
    setNOfVoxelsAlongZCmd->SetGuidance("Set number of voxels along Z axis.");
    setNOfVoxelsAlongZCmd->SetParameterName("nOfVoxelsZ", false);
    setNOfVoxelsAlongZCmd->AvailableForStates(G4State_Idle, G4State_PreInit);
}

DetectorMessenger::~DetectorMessenger()
{
    delete setIsocenterCmd;
    delete setJaw1XApertureCmd;
    delete setJaw2XApertureCmd;
    delete setJaw1YApertureCmd;
    delete setJaw2YApertureCmd;
    delete setPhantomXDimCmd;
    delete setPhantomYDimCmd;
    delete setPhantomZDimCmd;
    delete setNOfVoxelsAlongXCmd;
    delete setNOfVoxelsAlongYCmd;
    delete setNOfVoxelsAlongZCmd;
}

void DetectorMessenger::SetNewValue(G4UIcommand *command, G4String newValue)
{
    if (command == setIsocenterCmd)
    {
        fDetectorConstruction->SetIsocenter(setIsocenterCmd->GetNewDoubleValue(newValue));
    }

    if (command == setJaw1XApertureCmd)
    {
        fDetectorConstruction->SetJaw1XAperture(setJaw1XApertureCmd->GetNewDoubleValue(newValue));
    }

    if (command == setJaw2XApertureCmd)
    {
        fDetectorConstruction->SetJaw2XAperture(setJaw2XApertureCmd->GetNewDoubleValue(newValue));
    }

    if (command == setJaw1YApertureCmd)
    {
        fDetectorConstruction->SetJaw1YAperture(setJaw1YApertureCmd->GetNewDoubleValue(newValue));
    }

    if (command == setJaw2YApertureCmd)
    {
        fDetectorConstruction->SetJaw2YAperture(setJaw2YApertureCmd->GetNewDoubleValue(newValue));
    }
    if (command == setPhantomXDimCmd)
    {
        fDetectorConstruction->SetPhantomXDimension(setPhantomXDimCmd->GetNewDoubleValue(newValue));
    }

    if (command == setPhantomYDimCmd)
    {
        fDetectorConstruction->SetPhantomYDimension(setPhantomYDimCmd->GetNewDoubleValue(newValue));
    }

    if (command == setPhantomZDimCmd)
    {
        fDetectorConstruction->SetPhantomZDimension(setPhantomZDimCmd->GetNewDoubleValue(newValue));
    }

    if (command == setNOfVoxelsAlongXCmd)
    {
        fDetectorConstruction->SetNumberOfVoxelsAlongX(setNOfVoxelsAlongXCmd->GetNewIntValue(newValue));
    }

    if (command == setNOfVoxelsAlongYCmd)
    {
        fDetectorConstruction->SetNumberOfVoxelsAlongY(setNOfVoxelsAlongYCmd->GetNewIntValue(newValue));
    }

    if (command == setNOfVoxelsAlongZCmd)
    {
        fDetectorConstruction->SetNumberOfVoxelsAlongZ(setNOfVoxelsAlongZCmd->GetNewIntValue(newValue));
    }
}