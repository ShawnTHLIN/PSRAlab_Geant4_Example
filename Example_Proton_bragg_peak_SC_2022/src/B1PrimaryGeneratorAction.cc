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
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
B1PrimaryGeneratorAction::B1PrimaryGeneratorAction()
: G4VUserPrimaryGeneratorAction(),
  fParticleGun(0)
  {
	fParticleGun = new G4GeneralParticleSource();
	G4ParticleDefinition* fproton
		= G4ParticleTable::GetParticleTable()->FindParticle("proton"); //S6
	fParticleGun->GetCurrentSource()->SetParticleDefinition(fproton);
    //fParticleGun->SetParticlePosition(G4ThreeVector(0,0,-35*cm));
    //fParticleGun->GetCurrentSource()->GetEneDist()->SetEnergyDisType("Gauss");
	fParticleGun->GetCurrentSource()->GetEneDist()->SetMonoEnergy(0.8 * MeV);
    //fParticleGun->GetCurrentSource()->GetEneDist()->SetBeamSigmaInE(0.2*MeV);
	//fParticleGun->GetCurrentSource()->GetEneDist()->SetBeamSigmaInE(stdd[groupindex[index]]*MeV);

	fParticleGun->GetCurrentSource()->GetPosDist()->SetPosDisType("Beam");
	fParticleGun->GetCurrentSource()->GetPosDist()->SetPosDisShape("Circle");
	fParticleGun->GetCurrentSource()->GetPosDist()->SetCentreCoords(G4ThreeVector(0 * mm, 0 * mm, 0 * cm));////-10>-2.7
	fParticleGun->GetCurrentSource()->GetAngDist()->SetParticleMomentumDirection(G4ThreeVector(0, 0, 1));
	fParticleGun->GetCurrentSource()->GetPosDist()->SetRadius(0 * cm);
	//fParticleGun->GetCurrentSource()->GetPosDist()->SetBeamSigmaInX(0.5267 * cm);
	//fParticleGun->GetCurrentSource()->GetPosDist()->SetBeamSigmaInY(0.4657 * cm);
	

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
   

  fParticleGun->GeneratePrimaryVertex(anEvent);
}
