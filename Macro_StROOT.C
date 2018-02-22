#include <TSystem>

class StMaker;
class StChain;
class StBTofQAMaker;
class StMuDstMaker;
//class StBTofMatchMaker;


StChain *chain;
void Macro_StROOT( Int_t nEvents = 10000000, Char_t *inputFile="Foffline7813.list", Char_t *outputFile="7813.root")
{
	
//Load all the System libraries
	
	//gROOT->Macro("Macro_StROOT.C");

        gROOT->LoadMacro("$STAR/StRoot/StMuDSTMaker/COMMON/macros/loadSharedLibraries.C");
	loadSharedLibraries();
	
	//gSystem->Load("StMuDSTMaker");
	gSystem->Load("StDbBroker");
	gSystem->Load("StDetectorDbMaker");
	gSystem->Load("StTpcDb");
	gSystem->Load("StDaqLib");
	gSystem->Load("StDbUtilities");
	gSystem->Load("St_db_Maker");
	gSystem->Load("StDAQMaker");
/*	
	gSystem->Load("libtpc_Tables");
	gSystem->Load("libGeom");
	gSystem->Load("St_g2t");
	gSystem->Load("geometry");
	gSystem->Load("St_geant_Maker");
*/	
	gSystem->Load("StBTofHitMaker");
	gSystem->Load("StETofHitMaker");
	//gSystem->Load("StBTofUtil");
       	//gSystem->Load("StBTofMatchMaker");
  	//gSystem->Load("StVpdCalibMaker");
       	//gSystem->Load("StBTofCalibMaker");
	//gSystem->Load("StBTofQAMaker");


	//StMuDebug::setLevel(3);  
	
	chain = new StChain();
/*										
	St_geant_Maker *geantMk = new St_geant_Maker;
	geantMk->LoadGeometry("detp geometry y2009");
	geantMk->SetActive(kFALSE);
*/	
	//StMuDstMaker *MuDstMaker = new StMuDstMaker(0,0,"",inputFile,"MuDst",100);
											 //(0..read 1..write, 0..read from inFile 1..ioMaker,"",name of root file or filelist,"",max #.root files to chain) 	
	
	St_db_Maker *dbMk = new St_db_Maker("db","MySQL:StarDb","$STAR/StarDb","StarDb");
	
	//StBTofMatchMaker *matchMaker = new StBTofMatchMaker("matchMaker");
	//matchMaker->setMuDstIn(kTRUE);
	//matchMaker->SetDebug();

	//StVpdCalibMaker *vpdcalib = new StVpdCalibMaker();
	//vpdcalib->setMuDstIn();
	//vpdcalib->setInitFromFile();
	//vpdcalib->setCalibFilePvpd("/star/u/tlusty/D_analysis/test/calibPar/pvpdCali_4DB.dat");
       	//vpdcalib->SetDebug();

       	//StBTofCalibMaker *btofcalib = new StBTofCalibMaker(); 
	//btofcalib->setMuDstIn();
	//btofcalib->setInitFromFile();
	//btofcalib->setCalibFileTot("/star/u/tlusty/D_analysis/test/calibPar/totCali_4DB.dat");
	//btofcalib->setCalibFileZhit("/star/u/tlusty/D_analysis/test/calibPar/zCali_4DB.dat");
	//btofcalib->setCalibFileT0("/star/u/tlusty/D_analysis/test/calibPar/t0_4DB.dat");
       	//btofcalib->SetDebug(kFALSE); 

	//StBTofQAMaker *anaMaker = new StBTofQAMaker(MuDstMaker,outputFile);
	//anaMaker->setPicoDstOn(kTRUE);
	//anaMaker->setHistogramOn(kTRUE);
	
	StDAQReader *daq = new StDAQReader(inputFile);
	StBTofHitMaker *hitMaker = new StBTofHitMaker();
	//StETofHitMaker *hitMaker = new StETofHitMaker();

	chain->Init();
	cout<<"chain->Init();"<<endl;
	//chain->PrintInfo();
	int total = 0;
	for (Int_t i=0; i<nEvents; i++){
	  if(i%1==0)
	    {
		cout << "****************************************** " << endl;
		cout << "Working on eventNumber " << i << endl;
		cout << "****************************************** " << endl;
	    }
		//chain->Clear();
		int iret = chain->Make(i);
		
		if (iret) { cout << "Bad return code!" << endl; break;}
		
		total++;
		
	}
	
	cout << "****************************************** " << endl;
	cout << "Work done... now its time to close up shop!"<< endl;
	cout << "****************************************** " << endl;
	chain->Finish();
	cout << "****************************************** " << endl;
	cout << "total number of events  " << total << endl;
	cout << "****************************************** " << endl;
	
	delete chain;
	
	
}

