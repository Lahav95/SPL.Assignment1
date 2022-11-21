#pragma once
#include "Coalition.h"
#include "Party.h"
#include "Simulation.h"


Coalition::Coalition(): mCoalition(-1), numOfMandates(-1), isMajority(false)  {}

Coalition::Coalition(int Id, int numOfMandates) : mCoalition(Id), numOfMandates(numOfMandates) , isMajority(false){


 //  lParty;

}



void Coalition::addParty(Party& _p){      //NNN
    
  // lParty.push_back(_p);
   numOfMandates = numOfMandates+_p.getMandates();
   _p.setCoalitionId(mCoalition);
 //  thisSim.partiesByCoalitions.at(mCoalition).push_back(_p.getPartyId());
   // clone

} 

   int Coalition::getMandates(int CoalitionId){
      return numOfMandates;
   }