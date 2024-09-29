#ifndef DetectorConstruction_h
#define DetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"

class G4Material;
class G4VisAttributes;
class G4Box;
class G4LogicalVolume;
class G4VPhysicalVolume;
class DetectorMessenger;

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
    void ConstructPrimaryCollimator();
    void ConstructBeWindow();
    void ConstructFlatteningFilter();
    void ConstructIonizationChamber();
    void ConstructMirror();
    void ConstructJaw1X();
    void ConstructJaw2X();
    void ConstructJaw1Y();
    void ConstructJaw2Y();
    void ConstructMLC();
    void ConstructPhantom();

    inline void SetIsocenter(G4double val) { isoCentre = val; }
    inline G4double GetIsocenter() { return isoCentre; }
    inline void SetJaw1XAperture(G4double val) { jaw1XAperture = val; }
    inline void SetJaw2XAperture(G4double val) { jaw2XAperture = val; }
    inline void SetJaw1YAperture(G4double val) { jaw1YAperture = val; }
    inline void SetJaw2YAperture(G4double val) { jaw2YAperture = val; }
    inline G4double GetJaw1XAperture() { return jaw1XAperture; }
    inline G4double GetJaw2XAperture() { return jaw2XAperture; }
    inline G4double GetJaw1YAperture() { return jaw1YAperture; }
    inline G4double GetJaw2YAperture() { return jaw2YAperture; }
    inline void SetPhantomXDimension(G4double val) { phantomXDim = val; }
    inline void SetPhantomYDimension(G4double val) { phantomYDim = val; }
    inline void SetPhantomZDimension(G4double val) { phantomZDim = val; }
    inline G4double GetPhantomXDimension() { return phantomXDim; }
    inline G4double GetPhantomYDimension() { return phantomYDim; }
    inline G4double GetPhantomZDimension() { return phantomZDim; }
    inline void SetNumberOfVoxelsAlongX(G4int val) { numberOfVoxelsAlongX = val; }
    inline void SetNumberOfVoxelsAlongY(G4int val) { numberOfVoxelsAlongY = val; }
    inline void SetNumberOfVoxelsAlongZ(G4int val) { numberOfVoxelsAlongZ = val; }
    inline G4int GetNumberOfVoxelsAlongX() { return numberOfVoxelsAlongX; }
    inline G4int GetNumberOfVoxelsAlongY() { return numberOfVoxelsAlongY; }
    inline G4int GetNumberOfVoxelsAlongZ() { return numberOfVoxelsAlongZ; }

private:
    G4Material *Air, *Vacuum, *Copper, *Tungsten, *Lead, *Beryllium, *Kapton, *Mylar, *Water;
    G4VisAttributes *tungstenAtt;
    G4LogicalVolume *logicWorld;
    G4VPhysicalVolume *physWorld;
    G4double isoCentre, jaw1XAperture, jaw2XAperture, jaw1YAperture, jaw2YAperture;
    G4double phantomXDim, phantomYDim, phantomZDim;
    G4int numberOfVoxelsAlongX, numberOfVoxelsAlongY, numberOfVoxelsAlongZ;
    G4Box *RODetectorXDivision, *RODetectorYDivision, *RODetectorZDivision;
    G4LogicalVolume *RODetectorXDivisionLog, *RODetectorYDivisionLog, *RODetectorZDivisionLog;
    G4VPhysicalVolume *RODetectorXDivisionPhys, *RODetectorYDivisionPhys, *RODetectorZDivisionPhys;
    G4double ssd;

    G4LogicalVolume *leafLog;
    G4VPhysicalVolume *leafAPhys;
    G4VPhysicalVolume *leafBPhys;
    G4String leaf_name;
    G4double pos;
    G4double a1y;
    G4double a2y;
    G4double a3y;
    G4double a4y;
    G4double a5y;
    G4double a6y;
    G4double a7y;
    G4double a8y;
    G4double a9y;
    G4double a10y;
    G4double a11y;
    G4double a12y;
    G4double a13y;
    G4double a14y;
    G4double a15y;
    G4double a16y;
    G4double a17y;
    G4double a18y;
    G4double a19y;
    G4double a20y;
    G4double a21y;
    G4double a22y;
    G4double a23y;
    G4double a24y;
    G4double a25y;
    G4double a26y;
    G4double a27y;
    G4double a28y;
    G4double a29y;
    G4double a30y;
    G4double a31y;
    G4double a32y;
    G4double a33y;
    G4double a34y;
    G4double a35y;
    G4double a36y;
    G4double a37y;
    G4double a38y;
    G4double a39y;
    G4double a40y;

    G4double b1y;
    G4double b2y;
    G4double b3y;
    G4double b4y;
    G4double b5y;
    G4double b6y;
    G4double b7y;
    G4double b8y;
    G4double b9y;
    G4double b10y;
    G4double b11y;
    G4double b12y;
    G4double b13y;
    G4double b14y;
    G4double b15y;
    G4double b16y;
    G4double b17y;
    G4double b18y;
    G4double b19y;
    G4double b20y;
    G4double b21y;
    G4double b22y;
    G4double b23y;
    G4double b24y;
    G4double b25y;
    G4double b26y;
    G4double b27y;
    G4double b28y;
    G4double b29y;
    G4double b30y;
    G4double b31y;
    G4double b32y;
    G4double b33y;
    G4double b34y;
    G4double b35y;
    G4double b36y;
    G4double b37y;
    G4double b38y;
    G4double b39y;
    G4double b40y;

    DetectorMessenger *fDetMessenger;
};
#endif