#pragma once
#include <vector>

using namespace std;

class Simulation;
class Party;
class Agent;

class SelectionPolicy {

public:
    
    virtual ~SelectionPolicy()=default;
    virtual int select(Simulation& sim, Agent agent, vector<int> validParties)=0;
    virtual SelectionPolicy* duplicate()=0;
        
 };

class MandatesSelectionPolicy: public SelectionPolicy{ 

     public:
   
        virtual int select(Simulation& sim, Agent agent, vector<int> validParties);
        virtual SelectionPolicy* duplicate();

};

class EdgeWeightSelectionPolicy: public SelectionPolicy{ 

    public:
       
        virtual int select(Simulation& sim, Agent agent, vector<int> validParties);
        virtual SelectionPolicy* duplicate();


};