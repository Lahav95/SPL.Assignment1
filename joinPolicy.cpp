#pragma once
#include "JoinPolicy.h"
#include "Agent.h"
#include "Simulation.h"

MandatesJoinPolicy::MandatesJoinPolicy(){};
MandatesJoinPolicy::~MandatesJoinPolicy(){};
int MandatesJoinPolicy::Join(Simulation& sim, vector<Agent>& offerList){
    int maxMan;
    for(Agent a: offerList){
 //       if (getMandates( a.coalitionId))

    //    if (sim.getParty1(a.getPartyId).getMandates()>maxMan)

    }
}

LastOfferJoinPolicy::LastOfferJoinPolicy(){};
LastOfferJoinPolicy::~LastOfferJoinPolicy(){};
int LastOfferJoinPolicy::Join(Simulation& sim, vector<Agent>& offerList){

    Agent a = offerList.back() ;
    return a.getPartyId();
}