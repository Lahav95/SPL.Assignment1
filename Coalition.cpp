#include "Coalition.h"
#include "Party.h"
#include "Simulation.h"


//Coalition::Coalition(): mCoalition(-1), numOfMandates(-1)  {}  //default constructor

Coalition::Coalition(int agentId) : mCoalition(agentId), numOfMandates(0), lPartiesId({}){

}

void Coalition::addParty(Party& _p, int pId){      
   lPartiesId.push_back(pId);
   numOfMandates = numOfMandates+_p.getMandates();
   _p.setCoalitionId(mCoalition);

} 

   int Coalition::getMandates(int CoalitionId){
      return numOfMandates;
   }






