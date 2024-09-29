#include "DetectorConstruction.hh"
#include "DetectorMessenger.hh"
#include "G4GeometryManager.hh"
#include "G4PhysicalVolumeStore.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4SolidStore.hh"
#include "G4SystemOfUnits.hh"
#include "G4NistManager.hh"
#include "G4VisAttributes.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4Cons.hh"
#include "G4IntersectionSolid.hh"
#include "G4DisplacedSolid.hh"
#include "G4UnionSolid.hh"
#include "G4SubtractionSolid.hh"
#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4PVReplica.hh"
#include "G4RotationMatrix.hh"
#include "G4ThreeVector.hh"

DetectorConstruction::DetectorConstruction()
    : G4VUserDetectorConstruction()
{
    fDetMessenger = new DetectorMessenger(this);

    ssd = 100.0 * cm;

    a1y = 40. * cm;
    a2y = 40. * cm;
    a3y = 40. * cm;
    a4y = 40. * cm;
    a5y = 40. * cm;
    a6y = 40. * cm;
    a7y = 40. * cm;
    a8y = 40. * cm;
    a9y = 40. * cm;
    a10y = 40. * cm;
    a11y = 40. * cm;
    a12y = 40. * cm;
    a13y = 40. * cm;
    a14y = 40. * cm;
    a15y = 40. * cm;
    a16y = 40. * cm;
    a17y = 40. * cm;
    a18y = 40. * cm;
    a19y = 40. * cm;
    a20y = 40. * cm;
    a21y = 40. * cm;
    a22y = 40. * cm;
    a23y = 40. * cm;
    a24y = 40. * cm;
    a25y = 40. * cm;
    a26y = 40. * cm;
    a27y = 40. * cm;
    a28y = 40. * cm;
    a29y = 40. * cm;
    a30y = 40. * cm;
    a31y = 40. * cm;
    a32y = 40. * cm;
    a33y = 40. * cm;
    a34y = 40. * cm;
    a35y = 40. * cm;
    a36y = 40. * cm;
    a37y = 40. * cm;
    a38y = 40. * cm;
    a39y = 40. * cm;
    a40y = 40. * cm;

    b1y = 40. * cm;
    b2y = 40. * cm;
    b3y = 40. * cm;
    b4y = 40. * cm;
    b5y = 40. * cm;
    b6y = 40. * cm;
    b7y = 40. * cm;
    b8y = 40. * cm;
    b9y = 40. * cm;
    b10y = 40. * cm;
    b11y = 40. * cm;
    b12y = 40. * cm;
    b13y = 40. * cm;
    b14y = 40. * cm;
    b15y = 40. * cm;
    b16y = 40. * cm;
    b17y = 40. * cm;
    b18y = 40. * cm;
    b19y = 40. * cm;
    b20y = 40. * cm;
    b21y = 40. * cm;
    b22y = 40. * cm;
    b23y = 40. * cm;
    b24y = 40. * cm;
    b25y = 40. * cm;
    b26y = 40. * cm;
    b27y = 40. * cm;
    b28y = 40. * cm;
    b29y = 40. * cm;
    b30y = 40. * cm;
    b31y = 40. * cm;
    b32y = 40. * cm;
    b33y = 40. * cm;
    b34y = 40. * cm;
    b35y = 40. * cm;
    b36y = 40. * cm;
    b37y = 40. * cm;
    b38y = 40. * cm;
    b39y = 40. * cm;
    b40y = 40. * cm;
}

DetectorConstruction::~DetectorConstruction()
{
    delete fDetMessenger;
}

G4VPhysicalVolume *DetectorConstruction ::Construct()
{
    // clear old geometry
    G4GeometryManager::GetInstance()->OpenGeometry();
    G4PhysicalVolumeStore::GetInstance()->Clean();
    G4LogicalVolumeStore::GetInstance()->Clean();
    G4SolidStore::GetInstance()->Clean();

    DefineMaterial();
    DefineMaterialAttribute();
    return ConstructVolume();
}

void DetectorConstruction::DefineMaterial()
{
    G4NistManager *nist = G4NistManager::Instance();
    Air = nist->FindOrBuildMaterial("G4_AIR");
    Vacuum = nist->FindOrBuildMaterial("G4_Galactic");
    Tungsten = nist->FindOrBuildMaterial("G4_W");
    Copper = nist->FindOrBuildMaterial("G4_Cu");
    Lead = nist->FindOrBuildMaterial("G4_Pb");
    Beryllium = nist->FindOrBuildMaterial("G4_Be");
    Kapton = nist->FindOrBuildMaterial("G4_KAPTON");
    Mylar = nist->FindOrBuildMaterial("G4_MYLAR");
    Water = nist->FindOrBuildMaterial("G4_WATER");
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
    logicWorld->SetVisAttributes(G4VisAttributes::GetInvisible());

    this->ConstructAcc();
    this->ConstructPhantom();

    return physWorld;
}

void DetectorConstruction::ConstructAcc()
{
    this->ConstructTarget();
    this->ConstructPrimaryCollimator();
    this->ConstructBeWindow();
    this->ConstructFlatteningFilter();
    this->ConstructIonizationChamber();
    this->ConstructMirror();
    this->ConstructJaw1X();
    this->ConstructJaw2X();
    this->ConstructJaw1Y();
    this->ConstructJaw2Y();
    this->ConstructMLC();
}

void DetectorConstruction::ConstructTarget()
{
    // target A (W)
    G4double targetA_XDim = 10.0 * mm;
    G4double targetA_YDim = 10.0 * mm;
    G4double targetA_ZDim = 0.889 * mm;

    G4Box *targetABox =
        new G4Box("targetABox", targetA_XDim / 2.0, targetA_YDim / 2.0, targetA_ZDim / 2.0);
    G4LogicalVolume *targetALV =
        new G4LogicalVolume(targetABox, Tungsten, "targetALV", 0, 0, 0);
    targetALV->SetVisAttributes(tungstenAtt);

    // target B (Cu)
    G4double targetB_XDim = 10.0 * mm;
    G4double targetB_YDim = 10.0 * mm;
    G4double targetB_ZDim = 1.5748 * mm;
    G4Box *targetBBox =
        new G4Box("targetABox", targetB_XDim / 2.0, targetB_YDim / 2.0, targetB_ZDim / 2.0);
    G4LogicalVolume *targetBLV =
        new G4LogicalVolume(targetBBox, Copper, "targetBLV", 0, 0, 0);

    // specific translations for the various parts of the component
    new G4PVPlacement(0, G4ThreeVector(0., 0., targetABox->GetZHalfLength()),
                      "targetAPV", targetALV, physWorld, false, 0);

    new G4PVPlacement(0,
                      G4ThreeVector(0., 0., targetABox->GetZHalfLength() * 2. + targetBBox->GetZHalfLength()),
                      "targetBPV",
                      targetBLV,
                      physWorld,
                      false, 0);
}

void DetectorConstruction::ConstructPrimaryCollimator()
{
    G4RotationMatrix *rotateMatrix = new G4RotationMatrix();
    rotateMatrix->rotateX(180.0 * deg);

    // upper collimator
    G4double innerRadiusOfTheTubeEx = 1.0 * cm;
    G4double outerRadiusOfTheTubeEx = 8. * cm;
    G4double hightOfTheTubeEx = 3.0 * cm;
    G4double startAngleOfTheTubeEx = 0. * deg;
    G4double spanningAngleOfTheTubeEx = 360. * deg;
    G4Tubs *UpperCollimator = new G4Tubs("UpperCollimator", innerRadiusOfTheTubeEx,
                                         outerRadiusOfTheTubeEx, hightOfTheTubeEx,
                                         startAngleOfTheTubeEx, spanningAngleOfTheTubeEx);
    G4LogicalVolume *UpperCollimator_log = new G4LogicalVolume(UpperCollimator, Tungsten, "UpperCollimator_log", 0, 0, 0);

    G4double UpperCollimatorPosX = 0. * cm;
    G4double UpperCollimatorPosY = 0. * cm;
    G4double UpperCollimatorPosZ = -1. * cm;
    new G4PVPlacement(0,
                      G4ThreeVector(UpperCollimatorPosX, UpperCollimatorPosY,
                                    UpperCollimatorPosZ),
                      "UpperCollimator",
                      UpperCollimator_log, physWorld, false, 0);

    // lower collimator
    G4double pRmin1 = 0. * cm;

    G4double pRmax1 = 0.5 * cm;
    G4double pRmin2 = 0. * cm;
    G4double pRmax2 = 1.7658592 * cm;
    G4double hightOfTheCone = 3.2 * cm;
    G4double startAngleOfTheCone = 0. * deg;
    G4double spanningAngleOfTheCone = 360. * deg;

    G4Cons *collim_cone = new G4Cons("collim_cone", pRmin1, pRmax1, pRmin2,
                                     pRmax2, hightOfTheCone, startAngleOfTheCone,
                                     spanningAngleOfTheCone);
    G4LogicalVolume *collim_log = new G4LogicalVolume(collim_cone, Vacuum, "collim_log", 0, 0, 0);

    //
    G4double innerRadiusOfTheTube = 0. * cm;
    G4double outerRadiusOfTheTube = 8. * cm;
    G4double hightOfTheTube = 3.1 * cm;
    G4double startAngleOfTheTube = 0. * deg;
    G4double spanningAngleOfTheTube = 360. * deg;
    G4Tubs *tracker_tube = new G4Tubs("tracker_tube", innerRadiusOfTheTube,
                                      outerRadiusOfTheTube, hightOfTheTube,
                                      startAngleOfTheTube, spanningAngleOfTheTube);

    G4SubtractionSolid *CylMinusCone = new G4SubtractionSolid("Cyl-Cone",
                                                              tracker_tube, collim_cone);
    G4LogicalVolume *CylMinusCone_log = new G4LogicalVolume(CylMinusCone, Tungsten, "CylminusCone_log", 0, 0, 0);
    G4double CminusCPos_x = 0. * cm;
    G4double CminusCPos_y = 0. * cm;
    G4double CminusCPos_z = +6.2 * cm;
    new G4PVPlacement(rotateMatrix,
                      G4ThreeVector(CminusCPos_x, CminusCPos_y, CminusCPos_z),
                      "CylMinusCone", CylMinusCone_log, physWorld, false, 0);
}

void DetectorConstruction::ConstructBeWindow()
{
    G4Tubs *BeWTube = new G4Tubs("BeWindowTube", 0., 36. * mm, 0.2 * mm, 0. * deg, 360. * deg);
    G4LogicalVolume *BeWTubeLV = new G4LogicalVolume(BeWTube, Beryllium, "BeWTubeLV", 0, 0, 0);
    new G4PVPlacement(0, G4ThreeVector(0., 0., 100. * mm), "BeWTubePV", BeWTubeLV,
                      physWorld, false, 0);
}

void DetectorConstruction::ConstructFlatteningFilter()
{
    G4double z0, h0;
    G4ThreeVector centre, halSize;

    // first layer
    z0 = 130.0 * mm;
    h0 = 5.0 / 2. * cm;
    centre.set(0., 0., z0);
    G4Cons *FFL1A_1Cone = new G4Cons("FFL1A_1", 0. * cm, 0.3 * cm, 0. * cm, 5. * cm, h0, 0. * deg, 360. * deg);
    G4LogicalVolume *FFL1A_1LV = new G4LogicalVolume(FFL1A_1Cone, Copper, "FFL1A_1LV", 0, 0, 0);
    new G4PVPlacement(0, centre, "FFL1A_1PV", FFL1A_1LV, physWorld, false, 0);

    // second layer
    z0 += h0;
    h0 = 0.081 / 2. * cm;
    z0 += h0;
    centre.setZ(z0);
    z0 += h0;
    G4Tubs *FFL2_1Tube = new G4Tubs("FFL6_1", 0. * cm, 2.5 * cm, h0, 0. * deg, 360. * deg);
    G4LogicalVolume *FFL2_1LV = new G4LogicalVolume(FFL2_1Tube, Copper, "FFL2_1LV", 0, 0, 0);
    new G4PVPlacement(0, centre, "FFL2_1PV", FFL2_1LV, physWorld, false, 0);
}

void DetectorConstruction::ConstructIonizationChamber()
{
    G4Tubs *ICTubeW = new G4Tubs("ionizationChamberTube", 0., 2. * 2.54 * 10. * mm, 0.016 * 25.4 * mm, 0. * deg, 360. * deg);
    G4Tubs *ICTubeP = new G4Tubs("ionizationChamberTube", 0., 2. * 2.54 * 10. * mm, 0.010 * 25.4 * mm, 0. * deg, 360. * deg);

    G4ThreeVector centre;
    // W1
    centre.set(0., 0., 157. * mm);
    G4LogicalVolume *PCUTubeW1LV = new G4LogicalVolume(ICTubeW, Kapton, "ionizationChamberTubeW1LV", 0, 0, 0);
    new G4PVPlacement(0, centre, "ionizationChamberTubeW1PV", PCUTubeW1LV, physWorld, false, 0);

    // P1
    centre.set(0., 0., 158. * mm);
    G4LogicalVolume *PCUTubeP1LV = new G4LogicalVolume(ICTubeP, Kapton, "ionizationChamberTubeP1LV", 0, 0, 0);
    new G4PVPlacement(0, centre, "ionizationChamberTubeP1PV", PCUTubeP1LV, physWorld, false, 0);

    // W2
    centre.set(0., 0., 159. * mm);
    G4LogicalVolume *PCUTubeW2LV = new G4LogicalVolume(ICTubeW, Kapton, "ionizationChamberTubeW2LV", 0, 0, 0);
    new G4PVPlacement(0, centre, "ionizationChamberTubeW2PV", PCUTubeW2LV, physWorld, false, 0);

    // P2
    centre.set(0., 0., 160. * mm);
    G4LogicalVolume *PCUTubeP2LV = new G4LogicalVolume(ICTubeP, Kapton, "ionizationChamberTubeP2LV", 0, 0, 0);
    new G4PVPlacement(0, centre, "ionizationChamberTubeP2PV", PCUTubeP2LV, physWorld, false, 0);

    // W3
    centre.set(0., 0., 161. * mm);
    G4LogicalVolume *PCUTubeW3LV = new G4LogicalVolume(ICTubeW, Kapton, "ionizationChamberTubeW3LV", 0, 0, 0);
    new G4PVPlacement(0, centre, "ionizationChamberTubeW3PV", PCUTubeW3LV, physWorld, false, 0);

    // P3
    centre.set(0., 0., 162. * mm);
    G4LogicalVolume *PCUTubeP3LV = new G4LogicalVolume(ICTubeP, Kapton, "ionizationChamberTubeP3LV", 0, 0, 0);
    new G4PVPlacement(0, centre, "ionizationChamberTubeP3PV", PCUTubeP3LV, physWorld, false, 0);
}

void DetectorConstruction::ConstructMirror()
{
    G4Tubs *MirrorTube = new G4Tubs("MirrorTube", 0., 63. * mm, .5 * mm, 0. * deg, 360. * deg);
    G4LogicalVolume *MirrorTubeLV = new G4LogicalVolume(MirrorTube, Mylar, "MirrorTubeLV", 0, 0, 0);
    G4RotationMatrix *cRotation = new G4RotationMatrix();
    cRotation->rotateY(12.0 * deg);
    new G4PVPlacement(cRotation, G4ThreeVector(0., 0., 175. * mm), "MirrorTubePV", MirrorTubeLV, physWorld, false, 0);
}

void DetectorConstruction::ConstructJaw1X()
{
    G4String name = "Jaws1X";
    G4ThreeVector centre, halfSize;
    G4RotationMatrix *cRotation = new G4RotationMatrix();
    centre.set(0., 0., (367. + 78. / 2.) * mm);
    halfSize.set(50. * mm, 90. * mm, 78. / 2. * mm);
    G4Box *box = new G4Box(name + "Box", halfSize.getX(), halfSize.getY(), halfSize.getZ());
    G4LogicalVolume *logVol = new G4LogicalVolume(box, Tungsten, name + "LV", 0, 0, 0);
    // SetJawAperture(1, centre, halfSize,cRotation);
    G4double theta, x, y, z, dx, dy; //, dz, top;
    x = centre.getX();
    y = centre.getY();
    z = centre.getZ();
    dx = halfSize.getX();
    dy = halfSize.getY();
    theta = fabs(atan(jaw1XAperture / isoCentre));
    centre.set(z * sin(theta) + dx * cos(theta), y, z * cos(theta) - dx * sin(theta));
    cRotation->rotateY(-theta);
    new G4PVPlacement(cRotation, centre, name + "PV", logVol, physWorld, false, 0);
}

void DetectorConstruction::ConstructJaw2X()
{
    G4String name = "Jaws2X";
    G4ThreeVector centre, halfSize;
    G4RotationMatrix *cRotation = new G4RotationMatrix();
    centre.set(0., 0., (367. + 78. / 2.) * mm);
    halfSize.set(50. * mm, 90. * mm, 78. / 2. * mm);
    G4Box *box = new G4Box(name + "Box", halfSize.getX(), halfSize.getY(), halfSize.getZ());
    G4LogicalVolume *logVol = new G4LogicalVolume(box, Tungsten, name + "LV", 0, 0, 0);
    // SetJawAperture(2, centre, halfSize, cRotation);
    G4double theta, x, y, z, dx, dy; //, dz, top;
    x = centre.getX();
    y = centre.getY();
    z = centre.getZ();
    dx = halfSize.getX();
    dy = halfSize.getY();
    theta = fabs(atan(jaw2XAperture / isoCentre));
    centre.set(-(z * sin(theta) + dx * cos(theta)), y, z * cos(theta) - dx * sin(theta));
    cRotation->rotateY(theta);
    new G4PVPlacement(cRotation, centre, name + "PV", logVol, physWorld, false, 0);
}

void DetectorConstruction::ConstructJaw1Y()
{
    G4String name = "Jaws1Y";
    G4ThreeVector centre, halfSize;
    G4RotationMatrix *cRotation = new G4RotationMatrix();
    centre.set(0., 0., (280. + 78. / 2.) * mm);
    halfSize.set(90. * mm, 50. * mm, 78. / 2. * mm);
    G4Box *box = new G4Box(name + "Box", halfSize.getX(), halfSize.getY(), halfSize.getZ());
    G4LogicalVolume *logVol = new G4LogicalVolume(box, Tungsten, name + "LV", 0, 0, 0);
    // SetJawAperture(3, centre, halfSize, cRotation);
    G4double theta, x, y, z, dx, dy; //, dz, top;
    x = centre.getX();
    y = centre.getY();
    z = centre.getZ();
    dx = halfSize.getX();
    dy = halfSize.getY();
    theta = fabs(atan(jaw1YAperture / isoCentre));
    centre.set(x, z * sin(theta) + dy * cos(theta), z * cos(theta) - dy * sin(theta));
    cRotation->rotateX(theta);
    new G4PVPlacement(cRotation, centre, name + "PV", logVol, physWorld, false, 0);
}

void DetectorConstruction::ConstructJaw2Y()
{
    G4String name = "Jaws2Y";
    G4ThreeVector centre, halfSize;
    G4RotationMatrix *cRotation = new G4RotationMatrix();
    centre.set(0., 0., (280. + 78. / 2.) * mm);
    halfSize.set(90. * mm, 50. * mm, 78. / 2. * mm);
    G4Box *box = new G4Box(name + "Box", halfSize.getX(), halfSize.getY(), halfSize.getZ());
    G4LogicalVolume *logVol = new G4LogicalVolume(box, Tungsten, name + "LV", 0, 0, 0);
    // SetJawAperture(4, centre, halfSize, cRotation);
    G4double theta, x, y, z, dx, dy; //, dz, top;
    x = centre.getX();
    y = centre.getY();
    z = centre.getZ();
    dx = halfSize.getX();
    dy = halfSize.getY();
    theta = fabs(atan(jaw2YAperture / isoCentre));
    centre.set(x, -(z * sin(theta) + dy * cos(theta)), z * cos(theta) - dy * sin(theta));
    cRotation->rotateX(-theta);
    new G4PVPlacement(cRotation, centre, name + "PV", logVol, physWorld, false, 0);
}

void DetectorConstruction::ConstructMLC()
{
    G4RotationMatrix *rotateLeaf = new G4RotationMatrix();
    rotateLeaf->rotateY(90.0 * deg);

    G4RotationMatrix *rotateLeavesB = new G4RotationMatrix();
    rotateLeavesB->rotateX(180.0 * deg);

    G4double preLeafDim_x = 2.715 * mm;
    G4double preLeafDim_y = 64.72066 * mm;
    G4double preLeafDim_z = 29.3 * mm;
    G4Box *preLeaf_box = new G4Box("preLeaf_box", preLeafDim_x, preLeafDim_y, preLeafDim_z);

    G4double preLeafPos_x = 0.0 * m;
    G4double preLeafPos_y = 0.0 * m;
    G4double preLeafPos_z = -50. * cm;
    G4DisplacedSolid *disPreLeaf = new G4DisplacedSolid("disPreLeaf", preLeaf_box, 0,
                                                        G4ThreeVector(preLeafPos_x, preLeafPos_y, preLeafPos_z));

    G4double innerRadiusOfTheLeafEnd = 0.01 * mm;
    G4double outerRadiusOfTheLeafEnd = 80. * mm;
    G4double hightOfTheLeafEnd = 2.715 * mm;
    G4double startAngleOfTheLeafEnd = 0. * deg;
    G4double spanningAngleOfTheLeafEnd = 180. * deg;
    G4Tubs *aLeafEnd = new G4Tubs("aLeafEnd", innerRadiusOfTheLeafEnd,
                                  outerRadiusOfTheLeafEnd, hightOfTheLeafEnd,
                                  startAngleOfTheLeafEnd, spanningAngleOfTheLeafEnd);

    G4double gapDim_x = 90.00 * mm;
    G4double gapDim_y = 74.18 * mm;
    G4double gapDim_z = 3.0 * mm;
    G4Box *gap = new G4Box("gap", gapDim_x, gapDim_y, gapDim_z);

    G4SubtractionSolid *leafEnd = new G4SubtractionSolid("leafEnd", aLeafEnd, gap);

    G4double leafEndPosX = 0. * cm;
    G4double leafEndPosY = -9.4413249 * mm;
    G4double leafEndPosZ = -50.0 * cm;

    G4DisplacedSolid *disLeafEnd = new G4DisplacedSolid("disLeafEnd", leafEnd, rotateLeaf, G4ThreeVector(leafEndPosX, leafEndPosY, leafEndPosZ));

    G4UnionSolid *fullLeaf = new G4UnionSolid("fullLeaf", disPreLeaf, disLeafEnd);

    G4double cutADim_x = 0.20 * mm;
    G4double cutADim_y = 68.0 * mm;
    G4double cutADim_z = 15.925 * mm;
    G4Box *cutA = new G4Box("cutA", cutADim_x, cutADim_y, cutADim_z);

    G4double cutAPosX = -2.515 * mm;
    G4double cutAPosY = 3.0 * mm;
    G4double cutAPosZ = -48.6625 * cm;
    G4DisplacedSolid *disCutA = new G4DisplacedSolid("disCutA", cutA, 0, G4ThreeVector(cutAPosX, cutAPosY, cutAPosZ));

    G4SubtractionSolid *nearlyLeaf = new G4SubtractionSolid("nearlyLeaf", fullLeaf, disCutA);
    //++++++++++++++++++++++++++++
    G4double cutBDim_x = 0.1625 * mm;
    G4double cutBDim_y = 68.0 * mm;
    G4double cutBDim_z = 14.415 * mm;
    G4Box *cutB = new G4Box("cutB", cutBDim_x, cutBDim_y, cutBDim_z);

    G4double cutBPosX = 2.5525 * mm;
    G4double cutBPosY = 3.0 * mm;
    G4double cutBPosZ = -51.4885 * cm;
    G4DisplacedSolid *disCutB = new G4DisplacedSolid("disCutB", cutB, 0, G4ThreeVector(cutBPosX, cutBPosY, cutBPosZ));

    G4SubtractionSolid *leaf = new G4SubtractionSolid("leaf", nearlyLeaf, disCutB);

    leafLog = new G4LogicalVolume(leaf, Tungsten, "leafLog", 0, 0, 0);

    G4double leafAPosX[41];
    G4double leafAPosY[41];
    G4double leafAPosYF[41];

    leafAPosX[0] = -111.335 * mm;

    leafAPosY[0] = 40. * cm;
    leafAPosY[1] = a1y;
    leafAPosY[2] = a2y;
    leafAPosY[3] = a3y;
    leafAPosY[4] = a4y;
    leafAPosY[5] = a5y;
    leafAPosY[6] = a6y;
    leafAPosY[7] = a7y;
    leafAPosY[8] = a8y;
    leafAPosY[9] = a9y;
    leafAPosY[10] = a10y;
    leafAPosY[11] = a11y;
    leafAPosY[12] = a12y;
    leafAPosY[13] = a13y;
    leafAPosY[14] = a14y;
    leafAPosY[15] = a15y;
    leafAPosY[16] = a16y;
    leafAPosY[17] = a17y;
    leafAPosY[18] = a18y;
    leafAPosY[19] = a19y;
    leafAPosY[20] = a20y;
    leafAPosY[21] = a21y;
    leafAPosY[22] = a22y;
    leafAPosY[23] = a23y;
    leafAPosY[24] = a24y;
    leafAPosY[25] = a25y;
    leafAPosY[26] = a26y;
    leafAPosY[27] = a27y;
    leafAPosY[28] = a28y;
    leafAPosY[29] = a29y;
    leafAPosY[30] = a30y;
    leafAPosY[31] = a31y;
    leafAPosY[32] = a32y;
    leafAPosY[33] = a33y;
    leafAPosY[34] = a34y;
    leafAPosY[35] = a35y;
    leafAPosY[36] = a36y;
    leafAPosY[37] = a37y;
    leafAPosY[38] = a38y;
    leafAPosY[39] = a39y;
    leafAPosY[40] = a40y;

    G4int CopyNbA = 0;

    for (G4int i = 1; i <= 40; i++)
    {
        leafAPosYF[i] = -(((leafAPosY[i] * (100. - 47.25)) / 100.) + 70.5587 * mm);

        G4double leafAPosZ = 97.25 * cm;
        leafAPosX[i] = leafAPosX[i - 1] + 5.431 * mm;
        leafAPhys = new G4PVPlacement(0, G4ThreeVector(leafAPosX[i], leafAPosYF[i], leafAPosZ), "leafA", leafLog, physWorld, false, CopyNbA);
        CopyNbA = CopyNbA + 1;
    }

    G4double leafBPosX[41];
    G4double leafBPosY[41];
    G4double leafBPosYF[41];

    G4double leafBPosZ = -2.75 * cm;
    leafBPosX[0] = -111.335 * mm;
    G4int CopyNbB = 0;

    leafBPosY[0] = 40. * cm;
    leafBPosY[1] = b1y;
    leafBPosY[2] = b2y;
    leafBPosY[3] = b3y;
    leafBPosY[4] = b4y;
    leafBPosY[5] = b5y;
    leafBPosY[6] = b6y;
    leafBPosY[7] = b7y;
    leafBPosY[8] = b8y;
    leafBPosY[9] = b9y;
    leafBPosY[10] = b10y;
    leafBPosY[11] = b11y;
    leafBPosY[12] = b12y;
    leafBPosY[13] = b13y;
    leafBPosY[14] = b14y;
    leafBPosY[15] = b15y;
    leafBPosY[16] = b16y;
    leafBPosY[17] = b17y;
    leafBPosY[18] = b18y;
    leafBPosY[19] = b19y;
    leafBPosY[20] = b20y;
    leafBPosY[21] = b21y;
    leafBPosY[22] = b22y;
    leafBPosY[23] = b23y;
    leafBPosY[24] = b24y;
    leafBPosY[25] = b25y;
    leafBPosY[26] = b26y;
    leafBPosY[27] = b27y;
    leafBPosY[28] = b28y;
    leafBPosY[29] = b29y;
    leafBPosY[30] = b30y;
    leafBPosY[31] = b31y;
    leafBPosY[32] = b32y;
    leafBPosY[33] = b33y;
    leafBPosY[34] = b34y;
    leafBPosY[35] = b35y;
    leafBPosY[36] = b36y;
    leafBPosY[37] = b37y;
    leafBPosY[38] = b38y;
    leafBPosY[39] = b39y;
    leafBPosY[40] = b40y;

    for (G4int i = 1; i <= 40; i++)
    {
        leafBPosYF[i] = (((leafBPosY[i] * (100. - 47.25)) / 100.) + 70.5587 * mm);
        leafBPosX[i] = leafBPosX[i - 1] + 5.431 * mm;
        leafBPhys = new G4PVPlacement(rotateLeavesB,
                                      G4ThreeVector(leafBPosX[i], leafBPosYF[i], leafBPosZ),
                                      "leafB", leafLog, physWorld, false, CopyNbB);
        CopyNbB = CopyNbB + 1;
    }
}

void DetectorConstruction::ConstructPhantom()
{
    G4ThreeVector centre, halfSize;
    G4ThreeVector fPhantomSize; // Size of Water Phantom

    fPhantomSize.setX(phantomXDim);
    fPhantomSize.setY(phantomYDim);
    fPhantomSize.setZ(phantomZDim);
    halfSize.setX(fPhantomSize.getX() / 2.);
    halfSize.setY(fPhantomSize.getY() / 2.);
    halfSize.setZ(fPhantomSize.getZ() / 2.);

    centre.set(0., 0., ssd + halfSize.getZ());

    G4Box *fullWaterPhantomBox = new G4Box("fullWaterPhantomBox", halfSize.getX(), halfSize.getY(), halfSize.getZ());
    G4LogicalVolume *fullWaterPhantomLV = new G4LogicalVolume(fullWaterPhantomBox, Water, "fullWaterPhantomLV", 0, 0, 0);
    G4VPhysicalVolume *physWaterPhantom = new G4PVPlacement(0, centre, "fullWaterPhantomPV", fullWaterPhantomLV, physWorld, false, 0);

    // Division along X axis
    G4double halfXVoxelSizeX = fPhantomSize.getX() / 2. / numberOfVoxelsAlongX;
    G4double halfXVoxelSizeY = fPhantomSize.getY() / 2.;
    G4double halfXVoxelSizeZ = fPhantomSize.getZ() / 2.;
    G4double voxelXThickness = 2 * halfXVoxelSizeX;

    RODetectorXDivision = new G4Box("RODetectorXDivision", halfXVoxelSizeX, halfXVoxelSizeY, halfXVoxelSizeZ);
    RODetectorXDivisionLog = new G4LogicalVolume(RODetectorXDivision, Water, "RODetectorXDivisionLog", 0, 0, 0);
    RODetectorXDivisionPhys = new G4PVReplica("RODetectorXDivisionPhys", RODetectorXDivisionLog, physWaterPhantom, kXAxis, numberOfVoxelsAlongX, voxelXThickness);

    // Division along Y axis
    G4double halfYVoxelSizeX = halfXVoxelSizeX;
    G4double halfYVoxelSizeY = fPhantomSize.getY() / 2. / numberOfVoxelsAlongY;
    G4double halfYVoxelSizeZ = fPhantomSize.getZ() / 2.;
    G4double voxelYThickness = 2 * halfYVoxelSizeY;

    RODetectorYDivision = new G4Box("RODetectorYDivision", halfYVoxelSizeX, halfYVoxelSizeY, halfYVoxelSizeZ);
    RODetectorYDivisionLog = new G4LogicalVolume(RODetectorYDivision, Water, "RODetectorYDivisionLog", 0, 0, 0);
    RODetectorYDivisionPhys = new G4PVReplica("RODetectorYDivisionPhys", RODetectorYDivisionLog, RODetectorXDivisionPhys, kYAxis, numberOfVoxelsAlongY, voxelYThickness);

    // Division along Z axis
    G4double halfZVoxelSizeX = halfXVoxelSizeX;
    G4double halfZVoxelSizeY = halfYVoxelSizeY;
    G4double halfZVoxelSizeZ = fPhantomSize.getZ() / 2. / numberOfVoxelsAlongZ;
    G4double voxelZThickness = 2 * halfZVoxelSizeZ;

    RODetectorZDivision = new G4Box("RODetectorZDivision", halfZVoxelSizeX, halfZVoxelSizeY, halfZVoxelSizeZ);
    RODetectorZDivisionLog = new G4LogicalVolume(RODetectorZDivision, Water, "RODetectorZDivisionLog", 0, 0, 0);
    RODetectorZDivisionPhys = new G4PVReplica("RODetectorZDivisionPhys", RODetectorZDivisionLog, RODetectorYDivisionPhys, kZAxis, numberOfVoxelsAlongZ, voxelZThickness);
}

void DetectorConstruction::ConstructSDandField()
{
}