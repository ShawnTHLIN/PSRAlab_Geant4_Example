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
/// @file exMPI01.cc
// $Id: exMPI01.cc 78126 2013-12-03 17:43:56Z gcosmo $
//
/// @brief A MPI example code

#include "G4MPImanager.hh"
#include "G4MPIsession.hh"
#include "G4ScoringManager.hh"

#ifdef G4MULTITHREADED
#include "G4MTRunManager.hh"
#else
#include "G4RunManager.hh"
#endif

#include "G4UImanager.hh"

#ifdef G4VIS_USE
#include "G4VisExecutive.hh"
#endif

#include "B1DetectorConstruction.hh"
#include "B1ActionInitialization.hh"
#include "FTFP_BERT.hh"
#include "QGSP_BIC_HP.hh"
#include "PhysicsList.hh"
#include "G4PhysListFactory.hh"
//#include "HadrontherapyPhysicsList.hh"

#include <iostream>
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

int main(int argc, char** argv)
{
  // random engine
  CLHEP::MTwistEngine randomEngine;
  G4Random::setTheEngine(&randomEngine);
  	G4ScoringManager::GetScoringManager();
  
  G4UIExecutive* ui = 0;
  if ( argc == 1 ) {
    ui = new G4UIExecutive(argc, argv);
  }


  // --------------------------------------------------------------------
  // MPI session
  // --------------------------------------------------------------------
  // At first, G4MPImanager/G4MPIsession should be created.
  G4MPImanager* g4MPI = new G4MPImanager(argc, argv);

  // MPI session (G4MPIsession) instead of G4UIterminal
  // Terminal availability depends on your MPI implementation.
  G4MPIsession* session = g4MPI-> GetMPIsession();

  // LAM/MPI users can use G4tcsh.
  G4String prompt = "[40;01;33m";
  prompt += "G4MPI";
  prompt += "[40;31m(%s)[40;36m[%/][00;30m:";
  session-> SetPrompt(prompt);

  // --------------------------------------------------------------------
  // user application setting
  // --------------------------------------------------------------------
#ifdef G4MULTITHREADED
  G4MTRunManager* runManager = new G4MTRunManager();
  runManager-> SetNumberOfThreads(1);//////
#else
  G4RunManager* runManager = new G4RunManager();

  
#endif


  // setup your application

  runManager-> SetUserInitialization(new B1DetectorConstruction);

  // Physics list////////////


  
  
  //G4VModularPhysicsList* physt = new QGSP_BIC_EMY;
  //G4VModularPhysicsList* physt = new HadrontherapyPhysicsList;
  //PhysicsList *physt = new PhysicsList();

  
  //G4String plname = "QGSP_BIC_HP";  // set however you like ...
                                      // i.e. QGSP_BIC + _EMZ
  //G4String plname ="HadrontherapyPhysicsList"	;							  
  //G4PhysListFactory factory;
  //G4VModularPhysicsList* physt = factory.GetReferencePhysList(plname);
  //

  G4PhysListFactory factory;
  auto* physt = factory.GetReferencePhysList("QGSP_BIC_EMY");
  runManager->SetUserInitialization(physt);
  physt->SetVerboseLevel(1);
  
  //  runManager->SetUserInitialization(new QGSP_BIC_EMY);
  runManager-> SetUserInitialization(new B1ActionInitialization);

  runManager-> Initialize();
  
  
  // Get the pointer to the User Interface manager
  G4UImanager* UImanager = G4UImanager::GetUIpointer();

  // Process macro or start UI session
  //
  if ( ! ui ) { 
    // batch mode
    G4String command = "/control/execute ";
    G4String fileName = argv[1];
    UImanager->ApplyCommand(command+fileName);
  }
  else { 
    // interactive mode
    UImanager->ApplyCommand("/control/execute init_vis.mac");
    ui->SessionStart();
    delete ui;
  }
  
#ifdef G4VIS_USE
  G4VisExecutive* visManager = new G4VisExecutive;
  visManager-> Initialize();
  G4cout << G4endl;
#endif

  // --------------------------------------------------------------------
  // ready for go
  // MPIsession treats both interactive and batch modes.
  // Just start your session as below.
  // --------------------------------------------------------------------
  session-> SessionStart();

  // --------------------------------------------------------------------
  // termination
  // --------------------------------------------------------------------
#ifdef G4VIS_USE
  delete visManager;
#endif

  delete g4MPI;

  delete runManager;

  return EXIT_SUCCESS;
}
