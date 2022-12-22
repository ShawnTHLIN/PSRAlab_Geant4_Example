//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//
/// \file B1DetectorConstruction.cc
/// \brief Implementation of the B1DetectorConstruction class

#include "B1DetectorConstruction.hh"
#include "B1SteppingAction.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Cons.hh"
#include "G4Orb.hh"
#include "G4Tubs.hh"
#include "G4Sphere.hh"
#include "G4Trd.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4INCLGlobals.hh"
#include "G4MaterialPropertiesTable.hh"
#include "G4Tubs.hh"

#include "G4VisAttributes.hh"
#include "G4Colour.hh"

static const G4double inches = 2.54 * cm;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B1DetectorConstruction::B1DetectorConstruction()
: G4VUserDetectorConstruction(),
  fScoringVolume(0)
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B1DetectorConstruction::~B1DetectorConstruction()
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* B1DetectorConstruction::Construct()
{  
  // Get nist material manager
  G4NistManager* nistManager = G4NistManager::Instance();
  G4NistManager* nist = G4NistManager::Instance();
  // Envelope parameters
  //
  //G4double env_sizeXY = 20*cm, env_sizeZ = 30*cm;
  //G4Material* env_mat = nistManager->FindOrBuildMaterial("G4_WATER");
   
  // Option to switch on/off checking of volumes overlaps
  //
  G4bool checkOverlaps = true;

  G4double z, a, density ,fractionmass;
	G4String name, symbol;
	G4int ncomponents, natoms;

	//NaI
	G4Element * Na23 = new G4Element(name = "Sodium", symbol = "Na", z = 11, a = 22.989769 * g / mole);
	G4Element* I127 = new G4Element(name = "Iodine", symbol = "I", z = 53, a = 126.90447 * g/mole);
	G4Element* Tl204 = new G4Element(name = "Thallium", symbol = "Tl", z = 81, a = 204.3833 * g/mole);
	density = 3.67 * g/cm3;
	G4Material * NaI_Tl = new G4Material(name = "NaI_Tl", density, ncomponents = 3);
	NaI_Tl->AddElement(Na23, natoms = 1);
	NaI_Tl->AddElement(I127, natoms = 1);
	NaI_Tl->AddElement(Tl204, natoms = 1);

  //     
  // World
  //
  //G4double world_sizeXY = 1.2*env_sizeXY;
  //G4double world_sizeZ  = 1.2*env_sizeZ;
  G4Material* world_mat = nistManager->FindOrBuildMaterial("G4_AIR");
  
  G4Box* solidWorld =    
    new G4Box("World",                       //its name
       50 * cm, 50 * cm, 50 * cm);     //its size
      
  G4LogicalVolume* logicWorld =                         
    new G4LogicalVolume(solidWorld,          //its solid
                        world_mat,           //its material
                        "World");            //its name
                                   
  G4VPhysicalVolume* physWorld = 
    new G4PVPlacement(0,                     //no rotation
                      G4ThreeVector(),       //at (0,0,0)
                      logicWorld,            //its logical volume
                      "World",               //its name
                      0,                     //its mother  volume
                      false,                 //no boolean operation
                      0,                     //copy number
                      checkOverlaps);        //overlaps checking
  /*                 
  //     
  // Envelope
  //  
  G4Box* solidEnv =    
    new G4Box("Envelope",                    //its name
        0.5*env_sizeXY, 0.5*env_sizeXY, 0.5*env_sizeZ); //its size
      
  G4LogicalVolume* logicEnv =                         
    new G4LogicalVolume(solidEnv,            //its solid
                        env_mat,             //its material
                        "Envelope");         //its name
               
  new G4PVPlacement(0,                       //no rotation
                    G4ThreeVector(),         //at (0,0,0)
                    logicEnv,                //its logical volume
                    "Envelope",              //its name
                    logicWorld,              //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking
 */
  //     
  // Shape 1
  //  
 //Phantom 1
	//brain
	//create the scoring box w/ 100 layers
	G4double layer_num = 100;
	G4double SSD = 10;
	G4double phantom_z_len = 11.136;
	G4double phantom_B_len = 2.924;
	G4double layer_thickness = phantom_z_len/layer_num;
	G4int counts = 0;
	G4int counts_B = 0;
	G4Material * phantomMat_1 = nist->FindOrBuildMaterial("G4_WATER");	
	//G4Material * phantomMat_1 = nist->FindOrBuildMaterial("G4_BRAIN_ICRP");
 
		//G4cout<<counts<<G4endl;
		//fgetc(stdin);  // Stop point
	}
	/*
	// Detector
	// the parameter units are cm
	G4double SDD = 10;
	G4double collimator_height = 2.5 * 2;
	G4double collimator_width = 5;
	G4double collimator_slit = 0.2;
	G4double detector_thickness = 2.5 * 2.54; 
	G4ThreeVector positionDetector = G4ThreeVector(0, (SDD + sphere_radius/2 + collimator_height + (detector_thickness/2)) * cm, (SSD + sphere_radius/2) * cm); 
	G4cout<< "the detector position is "<< positionDetector << G4endl;
	//fgetc(stdin);  // Stop point
	G4Material * detectorMat = NaI_Tl;

	// the cylinder is craeted by G4Tubs
	// G4Tubs("Name", inner radius, outer radius, height, phi, delta angle)
	// fill the cylinder, phi = 0, delta = 2pi

  G4RotationMatrix* Rotation = new G4RotationMatrix();
  Rotation->rotateX(90*deg);
  Rotation->rotateY(0*deg);
  Rotation->rotateZ(0*deg);

	G4Tubs * Detector =
		new G4Tubs("Detector", 0, 1.25 * inches, 1.25 * inches, 0, G4INCL::Math::twoPi);
	G4LogicalVolume * LogDetector =
		new G4LogicalVolume(Detector, detectorMat, "Detector", 0, 0, 0);
	G4VPhysicalVolume * Detector_Physical =
		new G4PVPlacement(Rotation,    // no rotation
		positionDetector,  // at (x,y,z)
		LogDetector,    // its logical volume
		"Detector",        // its name
		logicWorld,         // its mother volume, the daughter volume position vertor is based on the mother volume 
		false,           // no boolean operations
		0,               // copy number
		checkOverlaps); // checking overlaps 

  // slit collimator
	// 2mm slit
	G4ThreeVector positionCollimator_1 = G4ThreeVector(0, (SDD + sphere_radius/2 + collimator_height/2) * cm, (SSD + sphere_radius/2 - collimator_width/2 - collimator_slit/2) * cm);
	G4cout<< "the collimator position is "<< positionCollimator_1 << G4endl;
	//fgetc(stdin);  // Stop point
	G4Material * CollimatorMat = nistManager -> FindOrBuildMaterial("G4_Pb");
	G4Box * Collimator_1 =
		new G4Box("Collimator", 5 * cm, (collimator_height/2) * cm, 2.5 * cm);
	G4LogicalVolume * LogCollimator_1 =
		new G4LogicalVolume(Collimator_1, CollimatorMat, "Collimator", 0, 0, 0);
	G4VPhysicalVolume * Collimator_Physical_1 =
		new G4PVPlacement(0,    // no rotation
		positionCollimator_1,  // at (x,y,z)
		LogCollimator_1,    // its logical volume
		"Collimator",        // its name
		logicWorld,         // its mother volume, the daughter volume position vertor is based on the mother volume 
		false,           // no boolean operations
		0,               // copy number
		checkOverlaps); // checking overlaps 

 
	G4ThreeVector positionCollimator_2 = G4ThreeVector(0, (SDD + sphere_radius/2 + collimator_height/2) * cm, (SSD + sphere_radius/2 + collimator_width/2 + collimator_slit/2) * cm);
	G4cout<< "the collimator position is "<< positionCollimator_2 << G4endl;
	//fgetc(stdin);  // Stop point
	G4Box * Collimator_2 =
		new G4Box("Collimator", 5 * cm, (collimator_height/2) * cm, 2.5 * cm);
	G4LogicalVolume * LogCollimator_2 =
		new G4LogicalVolume(Collimator_2, CollimatorMat, "Collimator", 0, 0, 0);
	G4VPhysicalVolume * Collimator_Physical_2 =
		new G4PVPlacement(0,    // no rotation
		positionCollimator_2,  // at (x,y,z)
		LogCollimator_2,    // its logical volume
		"Collimator",        // its name
		logicWorld,         // its mother volume, the daughter volume position vertor is based on the mother volume 
		false,           // no boolean operations
		0,               // copy number
		checkOverlaps); // checking overlaps 
  */
  return physWorld;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
