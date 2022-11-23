#include "Simulation.h"
#include "Agent.h"
#include <vector>


using std::vector;

Simulation::Simulation(Graph graph, vector<Agent> agents) : partiesByCoalitions({}), mCoalitions({}), newId(), mGraph(graph), mAgents(agents) 
{
    // You can change the implementation of the constructor, but not the signature!

    for (Agent a: agents){
        int coalitionId = a.getId();
        int numOfMandates = getParty(a.getPartyId()).getMandates();
        Coalition c (coalitionId, numOfMandates);       //creates a coalition object

        mCoalitions.push_back(c);       // add coalition to the list in simulation

        partiesByCoalitions.push_back(c.lPartiesId);    // add coalition to partiesByCoalition
        
        a.coalitionId = coalitionId;            //update coalition Id of agent 
    }

    newId = agents.size();      // counter for new agent objects
}


void Simulation::step()
{
  for (int i = 0; i<mGraph.getNumVertices(); i++){
    getParty1(i).step(*this); 
  }

  for (Agent a: mAgents){
    a.step(*this);
  }
}

bool Simulation::shouldTerminate() const
{
    bool toEnd= false;
    int j= mCoalitions.size();
     for (int i = 0; i< j && !toEnd; i++) {
        if (mCoalitions.at(i).numOfMandates > 60)
             return true;
     }

    toEnd = true;
    
    for (int i=0; i< mGraph.getNumVertices(); i++){
        if (getParty(i).getState() != Joined)
            return false;
            
    }

    
    return toEnd;
}

const Graph &Simulation::getGraph() const
{
    return mGraph;
}

const vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}

 vector<Agent> &Simulation::getAgents2() 
{
    return mAgents;
}

const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}

Party &Simulation::getParty1(int partyId) 
{
    return mGraph.getParty2(partyId);
}

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    // TODO: you MUST implement this method for getting proper output, read the documentation above.

    return partiesByCoalitions;     //check
}

Agent &Simulation::getAgentbyId(int agentId)       // Not necessarily needed
{
    vector<Agent>& temp = getAgents2();
    return temp.at(agentId);   
}

void Simulation:: clone(int id, int partyId){
    Agent clone (getAgentbyId(id));
    clone.setId(newId);
    clone.setPartyId(partyId);
    newId++;
    mAgents.push_back(clone);

}