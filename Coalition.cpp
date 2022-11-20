#pragma once
#include "Coalition.h"
#include "Party.h"
#include "Simulation.h"



Coalition::Coalition(int Id, int numOfMandates) : mCoalition(Id), numOfMandates(numOfMandates) , isMajority(false){


 //  lParty;


}

void Coalition::addAgent(Agent& agent){

lAgent.push_back(agent);

}

void Coalition::addParty(Party& _p){
    
   lParty.push_back(_p);
   numOfMandates = numOfMandates+_p.getMandates();
   _p.setCoalitionId(mCoalition);
   // clone
   

} 

// Party Coalition::maxParty(){
//    int max = 0;
//    Party& maxP;
//    for(Party& _p: lParty){
//       if(_p.getMandates() > max){
//          max = _p.getMandates();
//          maxP = _p;
//       }
//    }
//}