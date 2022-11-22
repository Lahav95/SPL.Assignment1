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


        

        void addParty(Party& _p, int partyId);  
        int getMandates(int CoalitionId);
        

       vector<int> lPartiesId;      // parties of this coalition

};