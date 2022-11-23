#include "Coalition.h"
#include "Party.h"
#include "Simulation.h"


Coalition::Coalition(int Id, int numOfMandates) : mCoalition(Id),
                     numOfMandates(numOfMandates), lPartiesId({}){

}

void Coalition::addParty(Party& _p, int pId){      
   lPartiesId.push_back(pId);
   numOfMandates = numOfMandates+_p.getMandates();
   _p.setCoalitionId(mCoalition);

} 

   int Coalition::getMandates(int CoalitionId){
      return numOfMandates;
   }