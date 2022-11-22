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
        int cId= sim.getAgentbyId(a).coalitionId;
        int temp= sim.mCoalitions.at(cId).numOfMandates;        //instead of numMandates of agent
        if (temp > maxMan){
            maxMan = maxMan;
            answerId = a;
        }
    }
    return answerId;
}

LastOfferJoinPolicy::LastOfferJoinPolicy(){};
LastOfferJoinPolicy::~LastOfferJoinPolicy(){};
int LastOfferJoinPolicy::Join(Simulation& sim, vector<int> offerList){

    int a = offerList.back() ;
    return a;
}