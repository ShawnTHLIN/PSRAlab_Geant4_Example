#ifndef PhysicsList_h
#define PhysicsList_h 1

#include "G4VModularPhysicsList.hh"
#include "G4EmConfigurator.hh"
#include "globals.hh"
#include "G4TripathiCrossSection.hh"
#include "G4VCrossSectionDataSet.hh"
#include "G4IonsShenCrossSection.hh"
#include "G4BinaryLightIonReaction.hh"
#include "G4BinaryCascade.hh"
#include "G4ProtonInelasticCrossSection.hh"
#include "G4TripathiLightCrossSection.hh"
#include "G4WilsonAblationModel.hh"


#include "G4TheoFSGenerator.hh"
#include "G4Evaporation.hh"
#include "G4CompetitiveFission.hh"
#include "G4FermiBreakUp.hh"
#include "G4StatMF.hh"
#include "G4ExcitationHandler.hh"
#include "G4PreCompoundModel.hh"
#include "G4GeneratorPrecompoundInterface.hh"
#include "G4QGSModel.hh"
#include "G4QGSParticipants.hh"
#include "G4QGSMFragmentation.hh"
#include "G4ExcitedStringDecay.hh"
#include "G4VPhysicsConstructor.hh"
#include "G4HadronElastic.hh"
#include "G4HadronElasticProcess.hh"
#include "G4HadronElastic.hh"
#include "G4HadronicProcess.hh"

// Inelastic Processes
#include "G4ProtonInelasticProcess.hh"
#include "G4AntiProtonInelasticProcess.hh"
#include "G4NeutronInelasticProcess.hh"
#include "G4AntiNeutronInelasticProcess.hh"
#include "G4PionPlusInelasticProcess.hh"
#include "G4PionMinusInelasticProcess.hh"
#include "G4KaonPlusInelasticProcess.hh"
#include "G4KaonZeroSInelasticProcess.hh"
#include "G4KaonZeroLInelasticProcess.hh"
#include "G4KaonMinusInelasticProcess.hh"
#include "G4DeuteronInelasticProcess.hh"
#include "G4TritonInelasticProcess.hh"
#include "G4AlphaInelasticProcess.hh"
#include "G4LambdaInelasticProcess.hh"
#include "G4AntiLambdaInelasticProcess.hh"
#include "G4OmegaMinusInelasticProcess.hh"
#include "G4AntiOmegaMinusInelasticProcess.hh"
#include "G4SigmaMinusInelasticProcess.hh"
#include "G4AntiSigmaMinusInelasticProcess.hh"
#include "G4SigmaPlusInelasticProcess.hh"
#include "G4AntiSigmaPlusInelasticProcess.hh"
#include "G4XiZeroInelasticProcess.hh"
#include "G4AntiXiZeroInelasticProcess.hh"
#include "G4XiMinusInelasticProcess.hh"
#include "G4AntiXiMinusInelasticProcess.hh"

#include "G4IonBinaryCascadePhysics.hh"


#include "G4VEvaporationChannel.hh"
#include "G4PhotonEvaporation.hh"

//#include "G4PromptPhotonEvaporation.hh"
#include "G4ProtonEvaporationChannel.hh"
/*
// Stopping processes
#include "G4PiMinusAbsorptionAtRest.hh"
#include "G4KaonMinusAbsorptionAtRest.hh"
#include "G4AntiProtonAnnihilationAtRest.hh"
#include "G4AntiNeutronAnnihilationAtRest.hh"
*/

class G4VPhysicsConstructor;


class PhysicsList : public G4VUserPhysicsList
{
public:
	PhysicsList();
	virtual ~PhysicsList();

public:
	//virtual void AddTransportation();
	virtual void ConstructParticle();
	virtual void ConstructProcess();

	virtual void SetCuts();

	void HadronicPhysics();/////
	
	//these methods Construct physics processes and register them
	//void ConstructDecay();
	//void ConstructEM();
	void ConstructOp();

	//for the Messenger 
	void SetVerbose(G4int);
	void SetNbOfPhotonsCerenkov(G4int);
	
	
		// Binary Cascade
  G4TheoFSGenerator* theHEModel;
  G4Evaporation* theEvaporation;
  G4FermiBreakUp* theFermiBreakUp;
  G4StatMF* theMF;
  G4ExcitationHandler* theHandler;
  G4PreCompoundModel* thePreEquilib;
  G4GeneratorPrecompoundInterface* theCascade;
  G4VPartonStringModel* theStringModel;
  G4BinaryCascade* theCasc;
  G4VLongitudinalStringDecay* theFragmentation;
  G4ExcitedStringDecay* theStringDecay;
  G4BinaryCascade* theCascForPi;
  
  G4PhotonEvaporation* thePPE;
  G4VEvaporationChannel* theEC;
  //G4PromptPhotonEvaporation* thePromptPhotonEvaporation ;
  G4ProtonEvaporationChannel* theProtonEvaporationChannel;
  G4WilsonAblationModel* theWilsonAblationModel;
  
  
  // Cascade for light ions
  G4BinaryLightIonReaction* theIonCascade;
  G4TripathiCrossSection* theTripathiCrossSection;
  G4TripathiLightCrossSection* theTripathiLightCrossSection;
  G4IonsShenCrossSection* theShenCrossSection;
  G4ProtonInelasticCrossSection* theProtonInelasticCrossSection ;
  G4BinaryLightIonReaction* theGenIonCascade;



   
	//G4ProtonInelasticProcess* theProtonInelasticProcess;////////
	G4HadronicProcess* theGenericIonInelasticProcess;///////////
	G4HadronicProcess* theProtonInelasticProcess;
	
  // pi+
  G4PionPlusInelasticProcess thePionPlusInelasticProcess;
  //G4LEPionPlusInelastic* theLEPionPlusInelasticModel;

  // pi-
  G4PionMinusInelasticProcess thePionMinusInelasticProcess;
  //G4LEPionMinusInelastic* theLEPionMinusInelasticModel;
  //G4PiMinusAbsorptionAtRest thePiMinusAbsorptionAtRest;
  
  // kaon+
  G4KaonPlusInelasticProcess theKaonPlusInelasticProcess;
  //G4LEKaonPlusInelastic* theLEKaonPlusInelasticModel;

  // kaon0S
  G4KaonZeroSInelasticProcess theKaonZeroSInelasticProcess;
  //G4LEKaonZeroSInelastic* theLEKaonZeroSInelasticModel;

  // kaon0L
  G4KaonZeroLInelasticProcess theKaonZeroLInelasticProcess;
  //G4LEKaonZeroLInelastic* theLEKaonZeroLInelasticModel;

  // kaon-
  G4KaonMinusInelasticProcess* theKaonMinusInelasticProcess;
  //G4LEKaonMinusInelastic* theLEKaonMinusInelasticModel;
  //G4KaonMinusAbsorptionAtRest* theKaonMinusAbsorptionAtRest;
  
  
  G4HadronElasticProcess theElasticProcess;
  //G4HadronElastic* theElasticModel;

  //G4HadronicProcess
  

  
  
private:
	G4int    fVerboseLebel;
	G4VPhysicsConstructor* emPhysicsList;
	G4VPhysicsConstructor* decPhysicsList;
	G4VPhysicsConstructor* radDecayPhysicsList;

	G4VPhysicsConstructor* G4HadronElasticPhysicsHPList;
	G4VPhysicsConstructor* G4HadronElasticPhysicsList;
	G4VPhysicsConstructor* HadronPhysicsQGSP_BIC_HPList;
	G4VPhysicsConstructor* HadronPhysicsQGSP_BICList;
	G4VPhysicsConstructor* G4StoppingPhysicsList;
	G4VPhysicsConstructor* G4IonPhysicsList;
	G4VPhysicsConstructor* G4EmExtraPhysicsList;
	G4VPhysicsConstructor* G4IonBinaryCascadePhysicsList;
	G4HadronElasticProcess  fTheElasticProcess;
	G4VPhysicsConstructor* LowemPhysicsList;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

