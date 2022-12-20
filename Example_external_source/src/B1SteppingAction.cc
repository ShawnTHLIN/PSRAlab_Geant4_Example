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
// $Id: B1SteppingAction.cc 74483 2013-10-09 13:37:06Z gcosmo $
//
/// \file B1SteppingAction.cc
/// \brief Implementation of the B1SteppingAction class
#include <iostream>
#include <fstream>

#include "B1SteppingAction.hh"
#include "B1EventAction.hh"
#include "B1DetectorConstruction.hh"
#include "B1RunAction.hh"

#include "G4Threading.hh"
#include "G4RunManager.hh"
#include "G4Step.hh"
#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4LogicalVolume.hh"
#include "G4MPImanager.hh"
#include "G4SystemOfUnits.hh"



//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B1SteppingAction::B1SteppingAction(B1EventAction* eventAction, B1RunAction *runAction)
: G4UserSteppingAction(),
fEventAction(eventAction),
frunAction(runAction)
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B1SteppingAction::~B1SteppingAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void B1SteppingAction::UserSteppingAction(const G4Step* step)
/////////////////////////////////////////////////// 

{
	
	if (step->GetPostStepPoint()->GetTouchableHandle()->GetVolume() != 0){
		if (step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetName()=="World"){
			if (step->GetPostStepPoint()->GetTouchableHandle()->GetVolume()->GetName()=="BTar"){   //BTar = phantom
				if (step->GetTrack()->GetDefinition()->GetParticleName()=="proton"){
					frunAction->output(step->GetPostStepPoint()->GetKineticEnergy(),0,0);
				}
			}
		}
	}
	/*
		if (step->GetPostStepPoint()->GetTouchableHandle()->GetVolume() != 0){
		if (step->GetTrack()->GetDefinition()->GetParticleName()=="proton"){
			if (step->GetPostStepPoint()->GetTouchableHandle()->GetVolume()->GetName() == "BTar"){
				G4double Posz_pre, Posz_post , S_Energy;
				G4ThreeVector Surfaceposition_pre = step->GetPreStepPoint()->GetPosition();
				Posz_pre= Surfaceposition_pre.getZ()/CLHEP::mm;
				G4ThreeVector Surfaceposition_post  = step->GetPostStepPoint()->GetPosition();
				Posz_post = Surfaceposition_post.getZ()/CLHEP::mm;
				
				for(G4double i = 345; i < 355; i+=0.10){
					
					if(Posz_post>=i && i>=Posz_pre) {
						//G4cout<<std::setprecision(3) <<"Position"<<i<<G4endl;
						
						S_Energy= step->GetPostStepPoint()->GetKineticEnergy();
						//G4cout<<std::setprecision(4) <<"Energy"<<S_Energy<<G4endl;
						//fgetc(stdin);
						frunAction->fp << i << "  " << S_Energy << G4endl;
					//frunAction->Refraction++;
					}
					else{

						continue;
						}
					}
				}
			}
		}
	*/
	}
	

/*
	if (step->GetPostStepPoint()->GetTouchableHandle()->GetVolume() != 0){
		if (step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetName()=="hav"){
			if (step->GetPostStepPoint()->GetTouchableHandle()->GetVolume()->GetName()=="World"){
				if (step->GetTrack()->GetDefinition()->GetParticleName()=="proton"){
					frunAction->output(0,step->GetPostStepPoint()->GetKineticEnergy(),0);
				}
			}
		}
	}
*/	

	/*
	if (step->GetPostStepPoint()->GetTouchableHandle()->GetVolume() != 0){
		if ((step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetName()=="World")or
			(step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetName()=="PDMSATT")){
			if(step->GetPostStepPoint()->GetTouchableHandle()->GetVolume()->GetName()=="Det"){
				if (step->GetTrack()->GetDefinition()->GetParticleName()=="proton"){
				frunAction->output(step->GetPostStepPoint()->GetKineticEnergy(),0,0);
				}
			}
		}
	}
	if (step->GetPostStepPoint()->GetTouchableHandle()->GetVolume() != 0){
		if (step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetName()=="World"){
			if(step->GetPostStepPoint()->GetTouchableHandle()->GetVolume()->GetName()=="PDMSATT"){
				if (step->GetTrack()->GetDefinition()->GetParticleName()=="proton"){
				frunAction->output(0,step->GetPostStepPoint()->GetKineticEnergy(),0);
				}
			}
		}
	}
*/
