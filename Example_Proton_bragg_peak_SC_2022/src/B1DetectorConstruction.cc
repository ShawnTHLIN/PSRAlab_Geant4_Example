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
// $Id$
//
/// \file B1DetectorConstruction.cc
/// \brief Implementation of the B1DetectorConstruction class

#include "B1DetectorConstruction.hh"
#include "B1SteppingAction.hh"
   // use of stepping action to set the accounting volume

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Cons.hh"
#include "G4Orb.hh"
#include "G4Sphere.hh"
#include "G4Trd.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4Tubs.hh"


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B1DetectorConstruction::B1DetectorConstruction()
: G4VUserDetectorConstruction()
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B1DetectorConstruction::~B1DetectorConstruction()
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* B1DetectorConstruction::Construct()
{  
 	G4NistManager* nistManager = G4NistManager::Instance();
	// Get nist material manager
	G4NistManager* nist = G4NistManager::Instance();



	// Option to switch on/off checking of volumes overlaps
	//
	G4bool checkOverlaps = true;

	//nistManager->FindOrBuildMaterial("G4_POLYETHYLENE");
	//nistManager->FindOrBuildMaterial("G4_STAINLESS-STEEL");
	//nistManager->FindOrBuildMaterial("G4_Al");
	nistManager->FindOrBuildMaterial("G4_Au");
	nistManager->FindOrBuildMaterial("G4_C");
	nistManager->FindOrBuildMaterial("G4_N");
	nistManager->FindOrBuildMaterial("G4_O");

	G4Material* HDPE = nistManager->FindOrBuildMaterial("G4_POLYETHYLENE");

	//     
	G4double z, a, density , fractionmass;
	G4String name, symbol;
	G4int ncomponents, natoms;
	
	//G4Element* elMo = new G4Element(name = "Mo", symbol = "Mo", z = 42 , a);
	//G4Element *elZn = new G4Element(name = "Zn", symbol = "Zn", z = 30, a);
	//G4Element *elTl = new G4Element(name = "Tl", symbol = "Tl", z = 81, a);
	G4Element *C12 = new G4Element(name = "C_12", symbol = "C_12", z = 6, a = 12 * g / mole); //-----C
	//G4Element *N14 = new G4Element(name = "N_14", symbol = "N_14", z = 7, a); ///////////-------N
	//G4Element *O16 = new G4Element(name = "O_16", symbol = "O_16", z = 8, a = 16 * g / mole); //-----C

	//density =10.28 *g / cm3;
	//density = 7.14*g / cm3;
	//density = 11.85* g / cm3;
	//density = 2.2* g / cm3;  //-------------C
	//density = 0.0012506* g / cm3;

	//G4Material*Mo = new G4Material(name = "mo100", density, ncomponents = 1);
	//G4Material * Zn67 = new G4Material(name = "Zn67", density, ncomponents = 1);
	//G4Material * Tl203 = new G4Material(name = "Tl203", density, ncomponents = 1);
	G4Material * G4_Mat = new G4Material(name = "G4_C_12", density = 2.2* g / cm3, ncomponents = 1); //---------C
	//G4Material * G4_Mat = new G4Material(name = "G4_O_16", density = 0.1* g / cm3, ncomponents = 1); //---------O
	//G4Material * G4_N_14 = new G4Material(name = "G4_N_14", density, ncomponents = 1);//---------N

	//Mo->AddElement(elMo, natoms = 1);
	//Zn67->AddElement(elZn, natoms = 1);
	//Tl203->AddElement(elTl, natoms = 1);
	G4_Mat->AddElement(C12, natoms = 1);//---------------C
	//G4_Mat->AddElement(O16, natoms = 1);//---------------C
	//G4_N_14->AddElement(N14, natoms = 1);//----------------N
	
	
	G4Material * CO2 = nist->FindOrBuildMaterial("G4_CARBON_DIOXIDE");

	//Density=0.00184212g/cm3        I ionization energy 85 
	G4Material * C2_H4 = nist->FindOrBuildMaterial("G4_POLYETHYLENE");
	//printf("********************* %lf\n", C2_H4->GetIonisation()->GetMeanExcitationEnergy()/CLHEP::eV);
	//fgetc(stdin);
	//Density=0.94  g/cm3        I ionization energy 57.4
	//nistManager->FindOrBuildMaterial("G4_WATER");
	G4Material * Water = nist->FindOrBuildMaterial("G4_WATER");
	//G4Material * PMMA = nist->FindOrBuildMaterial("G4_PLEXIGLASS");

	

	//PDMS
	
	G4Element* H = nist->FindOrBuildElement("H");
	G4Element* Si = nist->FindOrBuildElement("Si");
	G4Element* O = nist->FindOrBuildElement("O");
	G4Element* C = nist->FindOrBuildElement("C");

	G4Material* PDMS = new G4Material("PDMS", density = 0.976*g / cm3, ncomponents = 4); //0.965
	PDMS->AddElement(C, fractionmass = 0.324);
	PDMS->AddElement(Si, fractionmass = 0.379);
	PDMS->AddElement(H, fractionmass = 0.081);
	PDMS->AddElement(O, fractionmass = 0.216);
	
	
	//PE
	G4Material* PE = new G4Material("PE", density = 0.9638*g / cm3, ncomponents = 2);
	PE->AddElement(C,2);
	PE->AddElement(H,4);
	//printf("********************* %lf\n", PE->GetIonisation()->GetMeanExcitationEnergy()/CLHEP::eV);
	//fgetc(stdin);
	//system("pause");
	PE->GetIonisation()->SetMeanExcitationEnergy(57.4*eV);
	//printf("********************* %lf\n", PDMS->GetIonisation()->GetMeanExcitationEnergy());
	
	//PP
	G4Material* PP = new G4Material("PP", density = 0.946*g / cm3, ncomponents = 2);
	PP->AddElement(C,3);
	PP->AddElement(H,6);
	
	
	//PMMA
	G4Material* PMMA = new G4Material("PMMA", density = 1.1928*g / cm3, ncomponents = 3);
	PMMA->AddElement(C,5);
	PMMA->AddElement(O,2);
	PMMA->AddElement(H,8);
	//printf("********************* %lf\n", PMMA->GetIonisation()->GetMeanExcitationEnergy()/CLHEP::eV);
	//fgetc(stdin);
	//system("pause");
	PMMA->GetIonisation()->SetMeanExcitationEnergy(74*eV);
	//printf("********************* %lf\n", PMMA->GetIonisation()->GetMeanExcitationEnergy());
	
	//Scintillator
	
	G4Material* BC400 = new G4Material("BC400", density = 1.032*g / cm3, ncomponents = 2);

	BC400->AddElement(H,1);
	BC400->AddElement(C,1);

	G4Material* EJ290 = new G4Material("EJ290", density = 1.02*g / cm3, ncomponents = 2);

	EJ290->AddElement(H,11);
	EJ290->AddElement(C,10);

	
	//havar
	G4Element* Co = nist->FindOrBuildElement("Co");
	G4Element* Cr = nist->FindOrBuildElement("Cr");
	G4Element* W = nist->FindOrBuildElement("W");
	G4Element* Mo = nist->FindOrBuildElement("Mo");
	G4Element* Fe = nist->FindOrBuildElement("Fe");
	G4Element* Ni = nist->FindOrBuildElement("Ni");
	G4Element* Mn = nist->FindOrBuildElement("Mn");
	
	G4Material* Havar = new G4Material("Havar", density = 8.3*g / cm3, ncomponents = 8);
	Havar->AddElement(Co, fractionmass = 0.42);
	Havar->AddElement(Cr, fractionmass = 0.195);
	Havar->AddElement(Ni, fractionmass = 0.127);
	Havar->AddElement(W, fractionmass = 0.027);
	Havar->AddElement(Mo, fractionmass = 0.022);
	Havar->AddElement(Mn, fractionmass = 0.016);
	Havar->AddElement(C, fractionmass = 0.002);
	Havar->AddElement(Fe, fractionmass = 0.191);
	
	
	
	G4Material * Boron = nist->FindOrBuildMaterial("G4_B");
	
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//Detector
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

	// World
	//
	//G4double world_sizeXY = 1.2*env_sizeXY;
	//G4double world_sizeZ  = 1.2*env_sizeZ;
	//G4Material* world_mat = nist->FindOrBuildMaterial("G4_Galactic");
	G4Material* world_mat = nist->FindOrBuildMaterial("G4_AIR");


	G4Box* solidWorld =
		new G4Box("World",                       //its name
		100 * cm, 100 * cm, 100 * cm);     //its size

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

	//     
	//G4double inches = 2.54 * cm;
	// C,N,O target
	//Target 
	//G4ThreeVector positionTar = G4ThreeVector(0, 0, 0.1 *cm);
	
	/*
	G4Box * YTar =
		new G4Box("YTar", 2.5*cm, 2.5*cm ,0.1 *cm);
	G4LogicalVolume * fLogTar
		= new G4LogicalVolume(YTar, PP, "YTar", 0, 0, 0);
	G4VPhysicalVolume* Tar_Physical =
		new G4PVPlacement(0,               // no rotation
		positionTar,  // at (x,y,z)
		fLogTar,    // its logical volume
		"YTar",        // its name
		logicWorld,         // its mother volume
		false,           // no boolean operations
		0,               // copy number
		checkOverlaps); // checking overlaps 
	
	G4ThreeVector positionha = G4ThreeVector(0, 0, -20* um);
 
	G4double Havar_thickeness = 0.5 * 40;///////////
	G4Box * hav =
		new G4Box("hav", 5.0*cm, 5.0*cm, Havar_thickeness * um);
	G4LogicalVolume * hava
		= new G4LogicalVolume(hav, Havar, "hav", 0, 0, 0);
	G4VPhysicalVolume * hav_Physical =
	new G4PVPlacement(0,
	positionha,
	hava,
	"hav",
	logicWorld,
	false,
	0,
	checkOverlaps);
	*/
	//G4cout<< "Detector was compiled"<< thickeness <<G4endl;
	
	
	
	//Target phantom
	G4ThreeVector positionBTar = G4ThreeVector(0, 0, 20 *cm);

	G4Box * BTar =
		new G4Box("BTar", 5*cm, 5*cm ,20 *cm);
	G4LogicalVolume * fLogBTar
		= new G4LogicalVolume(BTar, Boron, "BTar", 0, 0, 0);
	G4VPhysicalVolume* BTar_Physical =
		new G4PVPlacement(0,               // no rotation
		positionBTar,  // at (x,y,z)
		fLogBTar,    // its logical volume
		"BTar",        // its name
		logicWorld,         // its mother volume
		false,           // no boolean operations
		0,               // copy number
		checkOverlaps); // checking overlaps 

	
  //
  return physWorld;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
