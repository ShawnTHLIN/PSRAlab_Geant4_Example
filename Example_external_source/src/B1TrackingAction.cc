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
/// \file electromagnetic/TestEm1/src/TrackingAction.cc
/// \brief Implementation of the TrackingAction class
//
// $Id: TrackingAction.cc 79976 2014-03-27 15:13:45Z gcosmo $
// 
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "B1TrackingAction.hh"
#include <iostream>
#include <fstream>


//#include "B2PrimaryGeneratorAction.hh"
#include "B1RunAction.hh"
#include "B1EventAction.hh"
//#include "HistoManager.hh"
#include "G4TrackStatus.hh"



#include "G4RunManager.hh"


#include "G4SystemOfUnits.hh"
#include "G4UnitsTable.hh"


#include <stdlib.h>
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

//G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();


B1TrackingAction::B1TrackingAction(B1EventAction* eventAction, B1RunAction *runAction)
:G4UserTrackingAction(),
fEventAction(eventAction),
frunAction(runAction)
//,fPrimary(prim)
{
	
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void B1TrackingAction::PreUserTrackingAction(const G4Track* preTrack)
{
	/*
	if ((preTrack->GetDefinition()->GetParticleName()=="gamma")&&
		(preTrack->GetTouchableHandle()->GetVolume()->GetName()=="YTar")){
					frunAction->output(preTrack->GetKineticEnergy(),0,0);
	}
	
	if ((preTrack->GetDefinition()->GetParticleName()=="gamma")&&
		(preTrack->GetTouchableHandle()->GetVolume()->GetName()=="YTar")){
		if (preTrack->GetCreatorProcess()!=0){
			//frunAction->output(preTrack->GetKineticEnergy(),0,0);
			if (preTrack->GetParentID()==1 ){
				G4String pPhyInt = preTrack->GetCreatorProcess()->GetProcessName();
				if(pPhyInt == "protonInelastic"){
					frunAction->output(0,0,preTrack->GetKineticEnergy());
					//G4cout<<preTrack->GetKineticEnergy()<<G4endl;
					//fgetc(stdin);
				}
			}
		}
	}
	*/

	
	/*
	G4int ParticleNum = 0;
	if  ((preTrack->GetDefinition()->GetParticleName()!="proton")&&
		 (preTrack->GetDefinition()->GetParticleName()!="neutron")&&
		 (preTrack->GetDefinition()->GetParticleName()!="gamma")&&
		 (preTrack->GetDefinition()->GetParticleName()!="e-")&&
		 (preTrack->GetDefinition()->GetParticleName()!="e+")&&
		 (preTrack->GetDefinition()->GetParticleName()!="alpha")&&
		 (preTrack->GetDefinition()->GetParticleName()!="triton")&&
		 (preTrack->GetDefinition()->GetParticleName()!="deuteron")){
			 
			ParticleNum = 99;
		 }
	
	if  (preTrack->GetDefinition()->GetParticleName()!="Au193") ParticleNum = 11;frunAction->output(0,0,ParticleNum);
	if  (preTrack->GetDefinition()->GetParticleName()!="Au194") ParticleNum = 12;frunAction->output(0,0,ParticleNum);
	if 	(preTrack->GetDefinition()->GetParticleName()!="Au195") ParticleNum = 13;frunAction->output(0,0,ParticleNum);
	if  (preTrack->GetDefinition()->GetParticleName()!="Au196") ParticleNum = 14;frunAction->output(0,0,ParticleNum);
	if  (preTrack->GetDefinition()->GetParticleName()!="Au198") ParticleNum = 15;frunAction->output(0,0,ParticleNum);
	if  (preTrack->GetDefinition()->GetParticleName()!="Au199") ParticleNum = 16;frunAction->output(0,0,ParticleNum);
	
	if  (preTrack->GetDefinition()->GetParticleName()!="Hg190") ParticleNum = 21;frunAction->output(0,0,ParticleNum);
	if  (preTrack->GetDefinition()->GetParticleName()!="Hg191") ParticleNum = 22;frunAction->output(0,0,ParticleNum);
	if  (preTrack->GetDefinition()->GetParticleName()!="Hg192") ParticleNum = 23;frunAction->output(0,0,ParticleNum);
		 
	if (ParticleNum==99) frunAction->output(0,0,ParticleNum);

	*/
	
		/*
	if ((preTrack->GetDefinition()->GetParticleName() == "neutron")) {
		frunAction->output(preTrack->GetKineticEnergy(),0,0);
				
	}
	*/
	/*
	if ((preTrack->GetDefinition()->GetParticleName() == "proton")&&( preTrack->GetParentID()==1)){
		//if( preTrack->GetStep()->GetPostStepPoint()->GetProcessDefinedStep()==0){
	
		//fgetc(stdin);		
				
				G4double ProtonEnergy = 0;
				//fEventAction->fNumofprotons++;
				ProtonEnergy = preTrack->GetKineticEnergy();
				
				//G4cout <<"STEPPING "<< ProtonEnergy << G4endl;
	
				fEventAction-> InifEnprotons = fEventAction-> InifEnprotons+ProtonEnergy;
				
				//G4cout << "ACCUMLATING "<<fEventAction-> fEnprotons<<G4endl;
				//frunAction-> output(ProtonEnergy);
				
				//G4cout <<"PARENTID  " <<  preTrack->GetParentID() << G4endl;
				
				//G4cout <<"TrackID  " <<  preTrack->GetTrackID() << G4endl;
//G4cout <<"TrackID  " <<  preTrack->GetTotalEnergy () << G4endl;
		//}	
	}

	G4String NameofParticle = preTrack->GetDefinition()->GetParticleName();
	G4double Charge = preTrack->GetDefinition()->GetPDGCharge();


	if ((NameofParticle!="proton")&&(NameofParticle!="opticalphoton")&&(NameofParticle!="neutron")){
		frunAction -> fp << NameofParticle << " "<< preTrack->GetKineticEnergy()/CLHEP::MeV <<" "<< Charge <<  G4endl;
	}
	
	//G4cout << preTrack->GetCurrentStepNumber() << G4endl;
	//G4cout << preTrack->GetVolume()->GetName() << G4endl;
	//system("pause");
*/
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void B1TrackingAction::PostUserTrackingAction(const G4Track* postTrack)
{

		//G4cout << frunAction -> QMeVproton <<"1"<< G4endl;
/*
		if (postTrack->GetDefinition()->GetParticleName() == "proton"){
			fgetc(stdin);
		}


	if (postTrack->GetTouchableHandle()->GetVolume()!=0){
		if ((postTrack->GetDefinition()->GetParticleName() == "proton")&&(postTrack->GetTouchableHandle()->GetVolume()->GetName()=="World")){
			fEventAction-> FinfEnprotons = fEventAction -> FinfEnprotons + postTrack ->GetKineticEnergy()/CLHEP::MeV;
			
		}
	}

	if (postTrack->GetDefinition()->GetParticleName() == "C12"){
			fgetc(stdin);
		}
*/
	//if (postTrack->GetDefinition()->GetParticleName() == "opticalphoton"){
	//	fEventAction->cpaddNum();
	//}	
	
}	



//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

