/*
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
// $Id: B1PrimaryGeneratorAction.cc 69565 2013-05-08 12:35:31Z gcosmo $
//
/// \file B1PrimaryGeneratorAction.cc
/// \brief Implementation of the B1PrimaryGeneratorAction class

	fGPS->GetCurrentSource()->GetPosDist()->SetPosDisType("Plane");
	fGPS->GetCurrentSource()->GetPosDist()->SetPosDisShape("Circle");
	fGPS->GetCurrentSource()->GetPosDist()->SetCentreCoords(G4ThreeVector(0 * mm, 0 * mm, -15 * cm));
  fGPS->GetCurrentSource()->GetPosDist()->SetRadius(1.0*cm);

	//fParticleGun->GetCurrentSource()->GetPosDist()->SetCentreCoords(G4ThreeVector(0., 0.,0));
	//fParticleGun->GetCurrentSource()->GetPosDist()->SetBeamSigmaInX(0.667*cm);
	//fParticleGun->GetCurrentSource()->GetPosDist()->SetBeamSigmaInY(0.667*cm);

	fGPS->GetCurrentSource()->GetAngDist()->SetParticleMomentumDirection(G4ThreeVector(0, 0, 1));
	//if (index < total - 1){
	//  fParticleGun->AddaSource(1);
	// }

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B1PrimaryGeneratorAction::~B1PrimaryGeneratorAction()
{
  delete fGPS;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
*/
#include "B1PrimaryGeneratorAction.hh"
#include <iostream>
using namespace std;

#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4RunManager.hh"
#include "G4ParticleGun.hh"
#include "G4GeneralParticleSource.hh"	
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"

#include "B1RunAction.hh"

G4int file_counter = 0;
G4bool Out_of_range = false;
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
B1PrimaryGeneratorAction::B1PrimaryGeneratorAction()
: G4VUserPrimaryGeneratorAction(),
  fParticleGun(0)
  {
	fParticleGun = new G4GeneralParticleSource();

}
B1PrimaryGeneratorAction::~B1PrimaryGeneratorAction()
{
  delete fParticleGun;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void B1PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
  //this function is called at the begining of ecah event
  //

  // In order to avoid dependence of PrimaryGeneratorAction
  // on DetectorConstruction class we get Envelope volume
  // from G4LogicalVolumeStore.
  if ((file_counter>E_array.size()) || ( file_counter>Particle_array.size())){
		//G4cout<< file_counter<<"  "<< E_array.size()<<"  "<<Particle_array.size()<< "  "<< G4endl;
		G4cout<< "===self-defined: Error==="<< G4endl;
		G4cout<< "===Simulated Paricle number is out of input file==="<< G4endl;
		fgetc(stdin);
		Out_of_range = true;
  }
    G4ParticleDefinition* fpaticles;
#if 0 // one kind of particle
   	 fpaticles = G4ParticleTable::GetParticleTable()->FindParticle("proton");
#else // several kind of particles


	if (int(Particle_array[file_counter]) == 1){
		fpaticles = G4ParticleTable::GetParticleTable()->FindParticle("proton");
	}
	else if (int(Particle_array[file_counter]) == 2){
		fpaticles = G4ParticleTable::GetParticleTable()->FindParticle("neutron");
	}
	else if (int(Particle_array[file_counter]) == 3){
		fpaticles= G4ParticleTable::GetParticleTable()->FindParticle("e-");
	}
	else if (int(Particle_array[file_counter]) == 4){
		fpaticles= G4ParticleTable::GetParticleTable()->FindParticle("gamma");
	}
	else{
		G4cout<< "===self-defined: Error==="<< G4endl;
		G4cout<< "===Paricle not defined==="<< G4endl;
		fgetc(stdin);
	}
#endif

	fParticleGun->GetCurrentSource()->SetParticleDefinition(fpaticles);

	//fParticleGun->SetParticlePosition(G4ThreeVector(0,0,-35*cm));
	//fParticleGun->GetCurrentSource()->GetEneDist()->SetEnergyDisType("Gauss");	
	fParticleGun->GetCurrentSource()->GetEneDist()->SetMonoEnergy(E_array[file_counter] * MeV);

	if (Out_of_range == true){
		fParticleGun->GetCurrentSource()->GetEneDist()->SetMonoEnergy(0 * MeV);
	}


	//fParticleGun->GetCurrentSource()->GetEneDist()->SetBeamSigmaInE(0.2*MeV);
	//fParticleGun->GetCurrentSource()->GetEneDist()->SetBeamSigmaInE(stdd[groupindex[index]]*MeV);	
	fParticleGun->GetCurrentSource()->GetPosDist()->SetPosDisType("Beam");
	fParticleGun->GetCurrentSource()->GetPosDist()->SetPosDisShape("Circle");
	fParticleGun->GetCurrentSource()->GetPosDist()->SetCentreCoords(G4ThreeVector(0 * mm, 0 * mm, 0 * cm));////-10>-2.7
	fParticleGun->GetCurrentSource()->GetAngDist()->SetParticleMomentumDirection(G4ThreeVector(0, 0, 1));
	fParticleGun->GetCurrentSource()->GetPosDist()->SetRadius(0 * cm);
	//fParticleGun->GetCurrentSource()->GetPosDist()->SetBeamSigmaInX(0.5267 * cm);
	//fParticleGun->GetCurrentSource()->GetPosDist()->SetBeamSigmaInY(0.4657 * cm);
	

  	fParticleGun->GeneratePrimaryVertex(anEvent);
  	file_counter++;
}
