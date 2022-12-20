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
// $Id: B1EventAction.cc 75117 2013-10-28 09:38:37Z gcosmo $
//
/// \file B1EventAction.cc
/// \brief Implementation of the B1EventAction class

#include "B1EventAction.hh"
//#include "B1Run.hh"
#include "B1RunAction.hh"

#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4SystemOfUnits.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B1EventAction::B1EventAction(B1RunAction* runAction)
: G4UserEventAction(), 
frunAction(runAction),
frawPhotons(0),
fdetPhotons(0),
fElectron(0),
fcount(0)
  //fEdep(0.)



{} 

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B1EventAction::~B1EventAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void B1EventAction::BeginOfEventAction(const G4Event*)
{    
frawPhotons = 0;
fdetPhotons = 0;
fElectron = 0;
fcount = 0;

//frunAction->QMeVproton=false;


}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void B1EventAction::EndOfEventAction(const G4Event*)
{   		//G4cout <<fNumofPhotons<< G4endl;
		//frunAction-> output(fNumofPhotons);
		//frunAction->outnumber(fNumofPhotons);

/*
if (InifEnprotons/CLHEP::MeV - 3 > 0.5){
	G4cout << "ENDOFEVENT"<<G4endl;
	G4cout << InifEnprotons << G4endl;
	G4cout << "ERR"<<G4endl;
	fgetc(stdin);
}
*/
/*
		if (fNumofPhotons != 0){
			frunAction-> output(fNumofPhotons);
			//G4cout << fNumofPhotons << G4endl;
		}
*/
	//G4cout << fNumofprotons << "protons are produced "<< G4endl;
	/*
	if (fcount == 1){
		frunAction->output(fElectron,0,frawPhotons);
	}
	if (fcount > 1){
		frunAction->output(0,fElectron,frawPhotons);
	}
*/
frunAction->output(fElectron,frawPhotons,fdetPhotons);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void B1EventAction::bpaddNum(G4double En)
{
fElectron = fElectron + En;
//fcount ++;
}

void B1EventAction::cpaddNum(G4double En)
{
//frawPhotons++;
frawPhotons = En;
}
void B1EventAction::dpaddNum()
{
fdetPhotons++;

}
void B1EventAction::output(G4int En){


}




