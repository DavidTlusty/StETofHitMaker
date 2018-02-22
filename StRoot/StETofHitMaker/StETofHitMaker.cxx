#include "StETofHitMaker.h"
//_____________________________________________________________                                                       
StETofHitMaker::StETofHitMaker(const char *name):StRTSBaseMaker("tof",name)
 ,mStEvent(0)
{                                            
  LOG_DEBUG << "StETofHitMaker::ctor"  << endm;
}
//_____________________________________________________________                                                       
StETofHitMaker::~StETofHitMaker()
{ }
//_____________________________________________________________                                                       
void StETofHitMaker::Clear(Option_t* option)
{ }

//_____________________________________________________________                                                       
Int_t StETofHitMaker::Init()
{ }
//_____________________________________________________________                                                       
Int_t StETofHitMaker::InitRun(Int_t runnumber)
{ }

//_____________________________________________________________                                                       
Int_t StETofHitMaker::FinishRun(Int_t runnumber)
{ }

//-------------------------------------------------------------                                                       
Int_t StETofHitMaker::Finish()
{ }
//_____________________________________________________________                                                       
Int_t StETofHitMaker::Make()
{ }

