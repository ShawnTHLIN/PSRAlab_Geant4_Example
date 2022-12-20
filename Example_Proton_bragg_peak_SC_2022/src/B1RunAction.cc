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
// $Id: B1RunAction.cc 87359 2014-12-01 16:04:27Z gcosmo $
//
/// \file B1RunAction.cc
/// \brief Implementation of the B1RunAction class
#include <iostream>
#include <fstream>
#include <string>
#include "B1RunAction.hh"
#include "B1PrimaryGeneratorAction.hh"
#include "B1DetectorConstruction.hh"
//#include "B1Run.hh"

#include "G4RunManager.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"
#include "G4Threading.hh"
#include "G4MPImanager.hh"
#include <sstream> //for std::stringstream 
#include <ctime>

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B1RunAction::B1RunAction()
: G4UserRunAction()
{ 
  // add new units for dose
  // 
	G4RunManager::GetRunManager()->SetPrintProgress(1000);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B1RunAction::~B1RunAction()
{
	G4cout<< "End of this_core"<< G4endl;
	
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void B1RunAction::BeginOfRunAction(const G4Run*)
{ 
  //inform the runManager to save random number seed
  G4RunManager::GetRunManager()->SetRandomNumberStore(false);

  //fp.open("Particle.txt", std::ios_base::app); 
  G4String TargetEn ;
  TargetEn = "202212_Proton_Boron_1MeV_PE";
  G4String 	bpFile = TargetEn + "-PE_Surface.txt",
			//cpFile = TargetEn + "-Hava.txt",
			//dpFile = TargetEn + "-inelas-gamma.txt";
			fpFile = TargetEn + "-depth_energy.txt";
			
			
  fp.open(fpFile , std::ios_base::app);
  bp.open(bpFile , std::ios_base::app);
  //cp.open(cpFile , std::ios_base::app);
  //dp.open(dpFile , std::ios_base::app);


	

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void B1RunAction::EndOfRunAction(const G4Run* run)
{
	//fp << "There are " << Refraction << "s of photons are refracted" << G4endl;
	//bp << "There are " << Reflection << "s of photons are reflected" << G4endl;
	//bp << NUMofSkip << " gammas are skipped" << G4endl;

fp.close();
bp.close();
//cp.close();
//dp.close();
	
}

void B1RunAction::output(G4double bptotal,G4double cptotal,G4double dptotal){

//if (QMeVproton==true){
//fp << total << "\n";
//Result = initial - Final ;
//bp << initial << " " << Final << " " << Result << "\n";

 
if (bptotal != 0){
	bp << bptotal << "\n" ;
}
if (cptotal != 0){
	cp << cptotal << "\n" ;
}
///////////////

if (dptotal != 0){
	dp << dptotal << "\n" ;
}

/////////////////////*/
//bp << "this" << "\n";
//G4cout <<"I am on "<< this <<G4endl;
//}
}

//**************************//


void B1RunAction::Poutput(G4String Particle){
  fp << Particle << "\n";
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
