#include "JoinPolicy.h"
#include "Agent.h"
#include "Simulation.h"


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

JoinPolicy* MandatesJoinPolicy::duplicate(){
    return new MandatesJoinPolicy(*this);
}

int LastOfferJoinPolicy::Join(Simulation& sim, vector<int> offerList){

    int a = offerList.back() ;
    return a;   
}

JoinPolicy* LastOfferJoinPolicy::duplicate(){
    return new LastOfferJoinPolicy(*this);
}