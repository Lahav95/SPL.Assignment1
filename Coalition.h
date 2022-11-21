#pragma once

#include <vector>
#include "Simulation.h"

using std::vector;

class Party;
class Agent;
class Graph;
class Simulation;

class Coalition
{
public:

        Coalition();

        Coalition(int, int);

        int mCoalition;
        int numOfMandates;
    //    Simulation& thisSim;
        bool isMajority;


        

        void addParty(Party& _p);  
    //    void merge(Coalition other); 
        Party maxParty();
        int getMandates(int CoalitionId);

    //   void addAgent(Agent*);
        // merge()
        // max()
        

       vector<int> lPartiesId;      // parties of this coalition
       vector<Agent> lAgent;      // agents of this coalition

};