#pragma once
#include "Coalition.h"
#include "Party.h"
#include "Simulation.h"


Coalition::Coalition(): mCoalition(-1), numOfMandates(-1) {}

Coalition::Coalition(int Id, int numOfMandates) : mCoalition(Id), numOfMandates(numOfMandates) {


 //  lParty;

}



void Coalition::addParty(Party& _p, int partyId){
    
   lPartiesId.push_back(partyId);
   numOfMandates = numOfMandates+_p.getMandates();
   _p.setCoalitionId(mCoalition);

}  

   int Coalition::getMandates(int CoalitionId){
      return numOfMandates;
   }