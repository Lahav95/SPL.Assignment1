#pragma once
using namespace std;

class Simulation;
class Party;
class Agent;

class SelectionPolicy {

public:

    const void step(Simulation &sim);
    bool isValid(int offeringParty, int recievingParty, Simulation &sim);
    Party biggestMandate(Simulation &sim, Agent agent);
    Party biggestEdge(Simulation &sim, Agent agent);
    
    virtual ~SelectionPolicy(){};
    virtual void select(Simulation& sim, Agent agent)=0;
        
 };

class MandatesSelectionPolicy: public SelectionPolicy{ 

     public:
        MandatesSelectionPolicy();
        virtual ~MandatesSelectionPolicy();
        virtual void select(Simulation& sim, Agent agent); 

};

class EdgeWeightSelectionPolicy: public SelectionPolicy{ 

    public:
        EdgeWeightSelectionPolicy();
        virtual ~EdgeWeightSelectionPolicy();
        virtual void select(Simulation& sim, Agent agent);

};