#include "DetectorConstruction.hh"

#include "G4SystemOfUnits.hh"

#include "G4NistManager.hh"
#include "G4VisAttributes.hh"

#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4RotationMatrix.hh"
#include "G4ThreeVector.hh"

DetectorConstruction::DetectorConstruction()
    : G4VUserDetectorConstruction()
{
}

DetectorConstruction::~DetectorConstruction()
{
}

G4VPhysicalVolume *DetectorConstruction ::Construct()
{
    DefineMaterial();
    DefineMaterialAttribute();
    return ConstructVolume();
}

void DetectorConstruction::DefineMaterial()
{
    G4NistManager *nist = G4NistManager::Instance();
    Air = nist->FindOrBuildMaterial("G4_AIR");
    Tungsten = nist->FindOrBuildMaterial("G4_W");
    Copper = nist->FindOrBuildMaterial("G4_Cu");
}

void DetectorConstruction::DefineMaterialAttribute()
{
    tungstenAtt = new G4VisAttributes(G4Colour(1., 0.3, 0.3));
    tungstenAtt->SetVisibility(true);
    tungstenAtt->SetForceWireframe(true);
    tungstenAtt->SetForceAuxEdgeVisible(true);
}

G4VPhysicalVolume *DetectorConstruction::ConstructVolume()
{
    G4Box *solidWorld = new G4Box("solidWorld", 500. * cm, 500. * cm, 500. * cm);
    logicWorld = new G4LogicalVolume(solidWorld, Air, "logicWorld");
    physWorld = new G4PVPlacement(0, G4ThreeVector(), logicWorld, "physWorld", 0, false, 0, true);

    this->ConstructAcc();

    return physWorld;
}

void DetectorConstruction::ConstructAcc()
{
    this->ConstructTarget();
}

void DetectorConstruction::ConstructTarget()
{
    G4Box *targetABox =
        new G4Box("targetABox", 5. * mm, 5. * mm, (.035 * 25.4 / 2.) * mm);
    G4LogicalVolume *targetALV =
        new G4LogicalVolume(targetABox, Tungsten, "targetALV", 0, 0, 0);
    targetALV->SetVisAttributes(tungstenAtt);

    G4Box *targetBBox =
        new G4Box("targetABox", 5. * mm, 5. * mm, (0.062 * 25.4 / 2.) * mm);
    G4LogicalVolume *targetBLV =
        new G4LogicalVolume(targetBBox, Copper, "targetBLV", 0, 0, 0);

    // specific translations for the various parts of the component
    new G4PVPlacement(0,
                      G4ThreeVector(0., 0., targetABox->GetZHalfLength()),
                      "targetAPV",
                      targetALV,
                      physWorld,
                      false, 0);

    new G4PVPlacement(0,
                      G4ThreeVector(0., 0., targetABox->GetZHalfLength() * 2. + targetBBox->GetZHalfLength()),
                      "targetBPV",
                      targetBLV,
                      physWorld,
                      false, 0);
}

void DetectorConstruction::ConstructSDandField()
{
}