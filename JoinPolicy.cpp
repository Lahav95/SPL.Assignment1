#pragma once
#include "JoinPolicy.h"
#include "Agent.h"
#include "Simulation.h"

MandatesJoinPolicy::MandatesJoinPolicy(){};
MandatesJoinPolicy::~MandatesJoinPolicy(){};
int MandatesJoinPolicy::Join(Simulation& sim, vector<int> offerList){
    int maxMan;
    int answerId;
    for(int a: offerList){
        int temp= sim.getAgentbyId(a).numOfMandates;
        if (temp > maxMan){
            maxMan = maxMan;
            answerId = a;
        }
    //    if (sim.getParty1(a.getPartyId).getMandates()>maxMan)

    }

    return answerId;
}

LastOfferJoinPolicy::LastOfferJoinPolicy(){};
LastOfferJoinPolicy::~LastOfferJoinPolicy(){};
int LastOfferJoinPolicy::Join(Simulation& sim, vector<int> offerList){

    int a = offerList.back() ;
    return a;
}