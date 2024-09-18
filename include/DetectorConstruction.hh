#ifndef DetectorConstruction_h
#define DetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"

class G4Material;
class G4VisAttributes;
class G4LogicalVolume;
class G4VPhysicalVolume;

class DetectorConstruction : public G4VUserDetectorConstruction
{

public:
    DetectorConstruction();
    ~DetectorConstruction();

    virtual G4VPhysicalVolume *Construct();
    void ConstructSDandField();

    void DefineMaterial();
    void DefineMaterialAttribute();
    G4VPhysicalVolume *ConstructVolume();
    void ConstructAcc();
    void ConstructTarget();
    

private:
    G4Material *Air, *Copper, *Tungsten;
    G4VisAttributes *tungstenAtt;
    G4LogicalVolume *logicWorld;
    G4VPhysicalVolume *physWorld;
};
#endif