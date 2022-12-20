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
/// \file electromagnetic/TestEm1/include/TrackingAction.hh
/// \brief Definition of the TrackingAction class
//
// $Id: TrackingAction.hh 76293 2013-11-08 13:11:23Z gcosmo $
//
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#ifndef B1TrackingAction_h
#define B1TrackingAction_h 1

#include "G4UserTrackingAction.hh"

//class B2PrimaryGeneratorAction;
class B1EventAction;
class B1RunAction;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class B1TrackingAction : public G4UserTrackingAction {

public:
	B1TrackingAction(B1EventAction* eventAction, B1RunAction* runAction);
	~B1TrackingAction() {};

	virtual void  PreUserTrackingAction(const G4Track*);
	virtual void  PostUserTrackingAction(const G4Track*);



private:
	//PrimaryGeneratorAction* fPrimary;
	B1EventAction* fEventAction;
	B1RunAction* frunAction;
};
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
