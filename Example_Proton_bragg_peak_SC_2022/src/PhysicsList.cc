#include "PhysicsList.hh"
#include "G4VModularPhysicsList.hh"

#include "G4IonPhysics.hh"

#include "G4ParticleDefinition.hh"
#include "G4ParticleTypes.hh"
#include "G4ParticleTable.hh"

#include "G4BosonConstructor.hh"
#include "G4LeptonConstructor.hh"
#include "G4MesonConstructor.hh"
#include "G4BaryonConstructor.hh"
#include "G4IonConstructor.hh"
#include "G4ShortLivedConstructor.hh"
#include "G4Proton.hh"
#include "G4GenericIon.hh"
#include "G4Electron.hh"
#include "G4Neutron.hh"
#include "G4Gamma.hh"



#include "G4ProcessManager.hh"
#include "G4ProcessVector.hh"
#include "G4PhysicsListHelper.hh"


#include "G4Cerenkov.hh"
#include "G4Scintillation.hh"
#include "G4OpAbsorption.hh"
#include "G4OpRayleigh.hh"
#include "G4OpMieHG.hh"
#include "G4OpBoundaryProcess.hh"

#include "G4LossTableManager.hh"
#include "G4EmSaturation.hh"

#include "G4EmStandardPhysics_option4.hh"
#include "G4EmLowEPPhysics.hh"
#include "G4EmStandardPhysics.hh"


#include "G4EmStandardPhysics_option3.hh"///
#include "G4EmLivermorePhysics.hh"
#include "G4DecayPhysics.hh"
#include "G4RadioactiveDecayPhysics.hh"
#include "G4EmPenelopePhysics.hh"
#include "G4VPhysicsConstructor.hh"
#include "G4ProductionCutsTable.hh"
#include "G4ios.hh"
#include "G4StepLimiter.hh"
#include "globals.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"
#include "G4IonBinaryCascadePhysics.hh"///
#include "G4VEvaporationChannel.hh"//////
#include "G4NeutronInelasticProcess.hh"
#include "G4IonInelasticProcess.hh"
#include "G4CascadeInterface.hh"
#include "G4GeneratorPrecompoundInterface.hh"




#include "G4EmStandardPhysics.hh"
#include "G4EmExtraPhysics.hh"
#include "G4StoppingPhysics.hh"
#include "G4HadronElasticPhysicsHP.hh"
#include "G4HadronElasticPhysics.hh"
#include "G4HadronPhysicsQGSP_BIC_HP.hh"
#include "G4HadronPhysicsQGSP_BIC.hh"
#include "G4HadronPhysicsINCLXX.hh"
#include "G4HadronElastic.hh"




#include "G4TripathiCrossSection.hh"
#include "G4IonsShenCrossSection.hh"
#include "G4AntiProton.hh"
#include "G4QMDReaction.hh"
#include "G4ProtonInelasticProcess.hh"

#include "G4ParticleDefinition.hh"
#include "G4ParticleWithCuts.hh"
#include "G4ParticleTypes.hh"
#include "G4ParticleTable.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
#include "G4HadronicProcess.hh"

#include "G4ComptonScattering.hh"
#include "G4GammaConversion.hh"
#include "G4PhotoElectricEffect.hh"

#include "G4eMultipleScattering.hh"
#include "G4MuMultipleScattering.hh"
#include "G4hMultipleScattering.hh"

#include "G4eIonisation.hh"
#include "G4eBremsstrahlung.hh"
#include "G4eplusAnnihilation.hh"

#include "G4MuIonisation.hh"
#include "G4MuBremsstrahlung.hh"
#include "G4MuPairProduction.hh"

#include "G4hIonisation.hh"
#include "G4Threading.hh"

#include "G4HadronElasticPhysics.hh"



//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


PhysicsList::PhysicsList()
: G4VUserPhysicsList(),
fVerboseLebel()  //Tan: choose the level of details about each interaciton displayed on the screen
{
	G4LossTableManager::Instance();
	// default values.
	//G4Cerenkov::SetMaxNumPhotonsPerStep(20);
	//G4Cerenkov::SetMaxBetaChangePerStep(10.0);
	//G4Cerenkov::SetTrackSecondariesFirst(true);
	//G4Scintillation::SetScintillationYieldFactor(1.);
	//G4Scintillation::SetTrackSecondariesFirst(true);
	//G4Scintillation::SetScintillationByParticleType(true);
	decPhysicsList = new G4DecayPhysics(1);
	radDecayPhysicsList = new G4RadioactiveDecayPhysics(1);
	emPhysicsList = new G4EmStandardPhysics_option3(1);
	//emPhysicsList = new G4EmStandardPhysics(1);
	
	G4HadronElasticPhysicsHPList = new G4HadronElasticPhysicsHP(1);
	//G4HadronElasticPhysicsList = new G4HadronElasticPhysics(1);
	//HadronPhysicsQGSP_BIC_HPList = new G4HadronPhysicsQGSP_BIC_HP(1);
	HadronPhysicsQGSP_BICList = new G4HadronPhysicsQGSP_BIC();
	G4StoppingPhysicsList = new G4StoppingPhysics(1);
	G4IonBinaryCascadePhysicsList = new G4IonBinaryCascadePhysics(1);

	LowemPhysicsList= new G4EmLowEPPhysics();
	G4IonPhysicsList = new G4IonPhysics();
	G4EmExtraPhysicsList = new G4EmExtraPhysics();
	//theGammaPhysics = new GammaPhysics();
	//HadronPhysicsQGSP_BIC_HPList = new G4HadronPhysicsINCLXX(1);
	//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
	//HadronPhysicsQGSP_BIC_HPList->RegisterProcess(theProtonInelasticProcess,G4Proton::ProtonDefinition());
	
  }
	/*
	//G4TripathiCrossSectionList = new G4TripathiCrossSection();
	//G4IonsShenCrossSectionList = new ();
	//G4HadronInelasticProcess* theIPGenericIon = new G4HadronInelasticProcess("IonInelastic", G4GenericIon::GenericIon() );
	G4HadronInelasticProcess* theIPGenericIon = new G4ProtonInelasticProcess("IonInelastic", G4Proton::Proton()  ); 
	
	G4TripathiCrossSection * TripathiCrossSection= new G4TripathiCrossSection;
	G4IonsShenCrossSection * aShen = new G4IonsShenCrossSection;
	theIPGenericIon->AddDataSet(aShen);
	theIPGenericIon->AddDataSet(TripathiCrossSection); 
	
	G4QMDReaction * theGenIonQMD= new G4QMDReaction;
	theIPGenericIon->RegisterMe(theGenIonQMD); 
	G4ProcessManager* pmanager = G4GenericIon::GenericIon()->GetProcessManager();
	pmanager->AddDiscreteProcess(theIPGenericIon); */

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
/*

void PhysicsList::AddTransportation() {

  G4VUserPhysicsList::AddTransportation();
  
}
*/
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void PhysicsList::ConstructParticle()
{
	// In this method, static member functions should be called
	// for all particles which you want to use.
	// This ensures that objects of these particle types will be
	// created in the program.
	
	//decPhysicsList->ConstructParticle();
	///////////////////
	//HadronPhysicsQGSP_BIC_HPList->ConstructParticle();
	//emPhysicsList->ConstructParticle();
	//G4IonPhysicsList->ConstructParticle();
	//////////////////
	
	G4BosonConstructor bConstructor;
	bConstructor.ConstructParticle();

	G4LeptonConstructor lConstructor;
	lConstructor.ConstructParticle();

	G4MesonConstructor mConstructor;
	mConstructor.ConstructParticle();

	G4BaryonConstructor rConstructor;
	rConstructor.ConstructParticle();

	G4IonConstructor iConstructor;
	iConstructor.ConstructParticle();
	
    G4ShortLivedConstructor pShortLivedConstructor;
    pShortLivedConstructor.ConstructParticle(); 
	
	G4Proton::ProtonDefinition();
	G4GenericIon::GenericIonDefinition();
	G4Neutron::NeutronDefinition();
	/*
	G4Gamma::GammaDefinition();
	G4Electron::ElectronDefinition();
	*/
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void PhysicsList::ConstructProcess()
{

	AddTransportation();
	//ConstructDecay();
	//ConstructEM();
	
	emPhysicsList->ConstructProcess();///////////////////-1
	LowemPhysicsList->ConstructProcess();
	decPhysicsList->ConstructProcess();
	radDecayPhysicsList->ConstructProcess();
	G4HadronElasticPhysicsHPList->ConstructProcess();
	//G4HadronElasticPhysicsList->ConstructProcess();
	//HadronPhysicsQGSP_BIC_HPList->ConstructProcess();//////
	//HadronPhysicsQGSP_BICList->ConstructProcess();
	
	G4StoppingPhysicsList->ConstructProcess();
	G4IonBinaryCascadePhysicsList->ConstructProcess();
	//theGammaPhysics->ConstructProcess();
	
	//////////////////////////////////////////////
	//G4EmExtraPhysicsList->ConstructProcess();
	//G4IonPhysicsList->ConstructProcess();//---------------
	
	HadronicPhysics();
	/////////////////
	//ConstructOp();
}


void PhysicsList::HadronicPhysics() 
{

	// **************************************************//
  // *** preparing inelastic reactions for hadrons *** // 
  // **************************************************//
  //
   // high energy model for proton, neutron, pions and kaons
  //theHEModel = new G4TheoFSGenerator;
  //theHEModel->SetTransport(new G4GeneratorPrecompoundInterface);  
  
  //thePromptPhotonEvaporation = new G4PromptPhotonEvaporation;
  theProtonEvaporationChannel= new G4ProtonEvaporationChannel;
  // all models for treatment of thermal nucleus 
  thePPE= new G4PhotonEvaporation;
  //thePPE->SetICM(1);
  //thePPE->RDMForced(1);
  theEvaporation = new G4Evaporation;
  theWilsonAblationModel=new G4WilsonAblationModel;
  theEvaporation->SetPhotonEvaporation(thePPE);
  //theEvaporation->SetPhotonEvaporation(theProtonEvaporationChannel);
  theFermiBreakUp = new G4FermiBreakUp;
  theMF = new G4StatMF;
  

  // evaporation logic
  theHandler = new G4ExcitationHandler;
  //theHandler->BreakItUp();
  theHandler->SetEvaporation(theEvaporation);
  //theHandler->SetEvaporation(theWilsonAblationModel);
  theHandler->SetFermiModel(theFermiBreakUp);
  //theHandler->SetPhotonEvaporation (thePPE);///
  theHandler->SetMultiFragmentation(theMF);
  theHandler->SetMaxAForFermiBreakUp(18);
  theHandler->SetMaxZForFermiBreakUp(9);
  theHandler->SetMinEForMultiFrag(3 *MeV); ///3
  
  

////////////////////////////////////////////////////////

  // pre-equilibrium stage 
  thePreEquilib = new G4PreCompoundModel(theHandler);
  //thePreEquilib = new G4PreCompoundModel();
  thePreEquilib->SetMinEnergy(0 *MeV);
  thePreEquilib->SetMaxEnergy(70 *MeV);///70
  
   // a no-cascade generator-precompound interaface
  theCascade = new G4GeneratorPrecompoundInterface;
  theCascade->SetDeExcitation(thePreEquilib);///////////////
  
  // high energy model for proton, neutron, pions and kaons
  theHEModel = new G4TheoFSGenerator;
  //theHEModel->SetTransport(new G4GeneratorPrecompoundInterface);
  theHEModel->SetTransport(theCascade);
  

    // Binary cascade for lightion
  //theGenIonCascade = new G4BinaryLightIonReaction;
  //theGenIonCascade->SetMinEnergy(0*MeV); ////0
  //theGenIonCascade->SetMaxEnergy(30*GeV);;
  
  
//thePreEquilib = new G4PreCompoundModel(theHandler);
  // Binary cascade for p, n
  theCasc = new G4BinaryCascade;
  theCasc->SetMinEnergy(65 *MeV);//65
  theCasc->SetMaxEnergy(6.1*GeV);
  theCasc->SetDeExcitation(thePreEquilib);
  //piproc = new G4PionPlusInelasticProcess;

  // QGSP model
  theStringModel = new G4QGSModel<G4QGSParticipants>;
  //theHEModel->SetTransport(theCascade);
  theHEModel->SetTransport(theCasc);
  theHEModel->SetHighEnergyGenerator(theStringModel);
  theHEModel->SetMinEnergy(6*GeV);
  theHEModel->SetMaxEnergy(100*TeV);
	

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
  
 /*
  // Generic Ion and He3
  // NOTE: Shen XS only up to 10 GeV/n;
  theGenIonCascade = new G4BinaryLightIonReaction;
  theGenIonCascade->SetMinEnergy(0*MeV); ////0
  theGenIonCascade->SetMaxEnergy(30*GeV);

  // fragmentation
  theFragmentation = new G4QGSMFragmentation;
  theStringDecay = new G4ExcitedStringDecay(theFragmentation);
  theStringModel->SetFragmentationModel(theStringDecay);
  
    // Binary Cascade for Pi
  theCascForPi = new G4BinaryCascade;
  theCascForPi->SetMinEnergy(0*MeV);
  theCascForPi->SetMaxEnergy(1.5*GeV);
  */
 /* 
  // LEP to fill the gap
  theLEPionPlusInelasticModel = new G4LEPionPlusInelastic();
  theLEPionPlusInelasticModel->SetMinEnergy(1.4*GeV);
  theLEPionPlusInelasticModel->SetMaxEnergy(6.1*GeV);
  theLEPionMinusInelasticModel = new G4LEPionMinusInelastic();
  theLEPionMinusInelasticModel->SetMinEnergy(1.4*GeV);
  theLEPionMinusInelasticModel->SetMaxEnergy(6.1*GeV);
   
 
	//LOW energy slope
  	G4ParticleDefinition *theProton = G4Proton::ProtonDefinition();
	G4ProcessManager *theProtonProcMan = theProton->GetProcessManager();
    G4ProtonInelasticProcess *theProtonIEProc = new G4ProtonInelasticProcess();
    G4CascadeInterface *theProtonIE = new G4CascadeInterface();
	//theProtonIE->SetDeExcitation(thePreEquilib);
	theProtonIEProc->RegisterMe( theProtonIE );
	theProtonProcMan->AddDiscreteProcess( theProtonIEProc );  
	

  //G4NeutronInelasticProcess* nproc = new G4NeutronInelasticProcess;
  //nproc->RegisterMe(thePreEquilib);
  //neutronManager->AddDiscreteProcess(nproc);
  
 */
  
  // Elastic Process
  //fTheElasticProcess.RegisterMe(new G4HadronElastic());
  //....oooOO0OOooo........
  
  theTripathiCrossSection = new G4TripathiCrossSection;
  theShenCrossSection = new G4IonsShenCrossSection;
  theProtonInelasticCrossSection= new G4ProtonInelasticCrossSection;
  theTripathiLightCrossSection = new G4TripathiLightCrossSection;
  
  //theElasticModel = new G4HadronElastic();
  //theElasticProcess->RegisterMe(theElasticModel);
  
/*  
	G4PhysicsListHelper* pmanager = G4PhysicsListHelper::GetPhysicsListHelper();
	G4PhysicsListHelper* ph = G4PhysicsListHelper::GetPhysicsListHelper();
	theProtonInelasticProcess= new G4ProtonInelasticProcess("protonInelastic");
	theProtonInelasticProcess->AddDataSet(theTripathiCrossSection);
	//theProtonInelasticProcess->AddDataSet(theTripathiLightCrossSection);
    theProtonInelasticProcess->RegisterMe(theCasc);
	theProtonInelasticProcess->RegisterMe(theHEModel);
	theProtonInelasticProcess->RegisterMe(thePreEquilib);
    //pmanager->AddDiscreteProcess(theProtonInelasticProcess);
	ph->RegisterProcess(theProtonInelasticProcess,G4Proton::ProtonDefinition());
*/
	

	auto theParticleIterator = GetParticleIterator();
	theParticleIterator->reset();
  while ((*theParticleIterator)()) {
    G4ParticleDefinition* particle = theParticleIterator->value();
    G4ProcessManager* pmanager = particle->GetProcessManager();
    G4String particleName = particle->GetParticleName();
	G4PhysicsListHelper* ph = G4PhysicsListHelper::GetPhysicsListHelper();

	if (particleName == "proton") {
      //pmanager->AddDiscreteProcess(&fTheElasticProcess);
      //theProtonInelasticProcess= new G4ProtonInelasticProcess("protonInelastic");
	  theProtonInelasticProcess= new G4ProtonInelasticProcess("protonInelastic");
	  //theProtonInelasticProcess->AddDataSet(theProtonInelasticCrossSection);
	  theProtonInelasticProcess->AddDataSet(theTripathiCrossSection);
	  //theProtonInelasticProcess->AddDataSet(theTripathiLightCrossSection);
      //theProtonInelasticProcess->AddDataSet(theShenCrossSection);
      //theProtonInelasticProcess->RegisterMe(theCasc);
	  //theProtonInelasticProcess->RegisterMe(theCascade);
	  theProtonInelasticProcess->RegisterMe(theHEModel);
	  theProtonInelasticProcess->RegisterMe(thePreEquilib);
	  pmanager->AddDiscreteProcess(theProtonInelasticProcess);
	  //ph->RegisterProcess(theProtonInelasticProcess,G4Proton::ProtonDefinition());
    }
	/*
	if (particleName == "GenericIon") {
      //pmanager->AddDiscreteProcess(theElasticProcess);
      theGenericIonInelasticProcess = new G4HadronInelasticProcess
	  ("IonInelastic", G4GenericIon::GenericIon());
      theGenericIonInelasticProcess->AddDataSet(theTripathiCrossSection);
      theGenericIonInelasticProcess->AddDataSet(theShenCrossSection);
      theGenericIonInelasticProcess->RegisterMe(theGenIonCascade);
      pmanager->AddDiscreteProcess(theGenericIonInelasticProcess);
    }/*
  }
  */
	
	///////////////////////////////
	/*
	 else if (particleName == "GenericIon") {
      //pmanager->AddDiscreteProcess(&fTheElasticProcess);
      theGenericIonInelasticProcess = new G4HadronInelasticProcess
	  ("IonInelastic", G4GenericIon::GenericIon());
      //theGenericIonInelasticProcess->AddDataSet(theTripathiCrossSection);
      theGenericIonInelasticProcess->AddDataSet(theShenCrossSection);
      theGenericIonInelasticProcess->RegisterMe(theGenIonCascade);
	  //theGenericIonInelasticProcess->RegisterMe(thePreEquilib);
      //pmanager->AddDiscreteProcess(theGenericIonInelasticProcess);
	  ph->RegisterProcess(theGenericIonInelasticProcess,G4GenericIon::GenericIonDefinition());
	}
}
*/
}
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "G4Decay.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


void PhysicsList::ConstructOp()
{}
/*
{
	//G4Cerenkov* cerenkovProcess = new G4Cerenkov("Cerenkov");
	//cerenkovProcess->SetMaxNumPhotonsPerStep(20);
	//cerenkovProcess->SetMaxBetaChangePerStep(10.0);
	//cerenkovProcess->SetTrackSecondariesFirst(true);
	G4Scintillation* scintillationProcess = new G4Scintillation("Scintillation");
	scintillationProcess->SetScintillationYieldFactor(1.);
	scintillationProcess->SetTrackSecondariesFirst(false);
	scintillationProcess->SetScintillationByParticleType(true);

	G4OpAbsorption* absorptionProcess = new G4OpAbsorption();
	G4OpRayleigh* rayleighScatteringProcess = new G4OpRayleigh();
	G4OpMieHG* mieHGScatteringProcess = new G4OpMieHG();
	G4OpBoundaryProcess* boundaryProcess = new G4OpBoundaryProcess();

	//cerenkovProcess->SetVerboseLevel(fVerboseLebel);
	scintillationProcess->SetVerboseLevel(fVerboseLebel);
	absorptionProcess->SetVerboseLevel(fVerboseLebel);
	rayleighScatteringProcess->SetVerboseLevel(fVerboseLebel);
	mieHGScatteringProcess->SetVerboseLevel(fVerboseLebel);
	boundaryProcess->SetVerboseLevel(0); //Tan: choose the level of details about each interaciton displayed on the screen

	// Use Birks Correction in the Scintillation process
	if (!G4Threading::IsWorkerThread())
	{
		G4EmSaturation* emSaturation =
			G4LossTableManager::Instance()->EmSaturation();
		//G4Scintillation::AddSaturation(emSaturation);
		scintillationProcess->AddSaturation(emSaturation);
	}
	// G4cout << "************************************************************************************" << G4endl;
	
	auto theParticleIterator=GetParticleIterator();

  	theParticleIterator->reset();
 	
	 while( (*theParticleIterator)() ){
		G4ParticleDefinition* particle = theParticleIterator->value();
		G4ProcessManager* pmanager = particle->GetProcessManager();
		G4String particleName = particle->GetParticleName();
		//if (cerenkovProcess->IsApplicable(*particle)) {
		//	pmanager->AddProcess(cerenkovProcess);
		//	pmanager->SetProcessOrdering(cerenkovProcess, idxPostStep);
		//}
		if (scintillationProcess->IsApplicable(*particle)) {
			pmanager->AddProcess(scintillationProcess);
			pmanager->SetProcessOrderingToLast(scintillationProcess, idxAtRest);
			pmanager->SetProcessOrderingToLast(scintillationProcess, idxPostStep);
		}
		if (particleName == "opticalphoton") {
			G4cout << " AddDiscreteProcess to OpticalPhoton " << G4endl; 
//Tan: This portion runs at the beginning of the simulation
			pmanager->AddDiscreteProcess(absorptionProcess);
			pmanager->AddDiscreteProcess(rayleighScatteringProcess);
			pmanager->AddDiscreteProcess(mieHGScatteringProcess);
			pmanager->AddDiscreteProcess(boundaryProcess);
		}
	}
}
*/
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void PhysicsList::SetVerbose(G4int verbose)
{
	fVerboseLebel = verbose;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void PhysicsList::SetNbOfPhotonsCerenkov(G4int maxnumber)
{
	//cerenkovProcess->SetMaxNumPhotonsPerStep(MaxNumber);
	//fMaxNumPhotonStep = MaxNumber;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void PhysicsList::SetCuts()
{
	//  " G4VUserPhysicsList::SetCutsWithDefault" method sets
	//   the default cut value for all particle types
	//
	
	SetCutsWithDefault();
	
	//SetCutValue(0.001*mm,"gamma");
	SetCutValue(0, "proton");
	if (verboseLevel>0) DumpCutValuesTable();
}



//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

PhysicsList::~PhysicsList() {
	delete decPhysicsList;
	delete radDecayPhysicsList;
	delete emPhysicsList;
	delete G4HadronElasticPhysicsHPList;
	delete HadronPhysicsQGSP_BIC_HPList;
	delete G4StoppingPhysicsList;
	delete G4IonPhysicsList;
	//delete G4EmExtraPhysicsList;
	delete G4IonBinaryCascadePhysicsList;
	delete LowemPhysicsList;
	
	
	delete theHEModel;
	delete theEvaporation;
	delete theFermiBreakUp;
	delete theMF;
	delete thePreEquilib;
	delete theHandler ;
	delete theStringModel;
	delete theCasc;
	delete theFragmentation;
	delete theStringDecay;
	delete theTripathiCrossSection;
	//delete theBinaryCascade:
	delete theGenericIonInelasticProcess;
	delete theGenIonCascade;
	delete theShenCrossSection;
	delete theProtonInelasticCrossSection;
	delete theTripathiLightCrossSection;
	 /////
	delete theCascade;
	delete thePPE;
	//delete thePromptPhotonEvaporation ;
	delete theProtonEvaporationChannel;
	delete theWilsonAblationModel;
	delete G4HadronElasticPhysicsList;
	delete HadronPhysicsQGSP_BICList;
	//delete theGammaPhysics;
	
}


