#pragma once

#include <vector>
//#include "Simulation.h"

using std::vector;

class Party;
class Agent;
class Graph;
class Simulation;

class Coalition
{
public:

        Coalition(int, int);

        int mCoalition;
        int numOfMandates;
        bool isMajority;

        
        void addAgent(Agent& agent);
        void addParty(Party& _p);  
        void merge(Coalition other); 
        Party maxParty();

    //   void addAgent(Agent*);
        // merge()
        // max()
        

       vector<Party> lParty;      // parties of this coalition
       vector<Agent> lAgent;      // agents of this coalition

};