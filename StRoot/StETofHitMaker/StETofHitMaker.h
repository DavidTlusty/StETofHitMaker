#ifndef STAR_StETofHitMaker_H
#define STAR_StETofHitMaker_H


/***************************************************************************                                          
 *                                                                                                                    
 * $Id: StETofHitMaker.h,v 0.1 2017/02/21 17:50:32 tlusty Exp $                                                    
 * StETofHitMaker - class to fille the StEvent from DAQ reader                                                        
 *--------------------------------------------------------------------------                                          
 *                                                                                                                    
 ***************************************************************************/
#include "StRTSBaseMaker.h"

#include <vector>

class StEvent;

class StETofHitMaker:public StRTSBaseMaker
{
private:
StEvent *mStEvent;

public:

/// Default constructor                                                                                          
 StETofHitMaker(const char *name="tof_raw");

 ~StETofHitMaker();

 void   Clear(Option_t* option="");
 Int_t  Init();
 Int_t  InitRun(Int_t);
 Int_t  FinishRun(Int_t);
 Int_t  Finish();
 Int_t  Make();

};

#endif
