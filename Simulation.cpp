#include "Simulation.h"
#include "Coalition.h"
#include "Agent.h"

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents) 
{
    for (Agent a: agents){
        int coalitionId = a.getId();
        int numOfMandates = getParty(a.getPartyId()).getMandates();
        Coalition c (coalitionId, numOfMandates);       //creates a coalition object

        mCoalitions.push_back(c);       // add coalition to the list in simulation

    //    partiesByCoalitions.push_back(c.lPartiesId);    // add coalition to partiesByCoalition
        a.coalitionId = coalitionId;            //update coalition Id of agent //NNN
    }
}

void Simulation::step()
{
  for (int i = 0; i<mGraph.getNumVertices(); i++){
    getParty1(i).step(*this); 
  }

  for (Agent agent: mAgents){
    agent.step(*this);
  }
}

bool Simulation::shouldTerminate() const
{
    bool toEnd= false;

    while (!toEnd)
    {
        for (int i = 0; i<mCoalitions.size(); i++) {
            if (mCoalitions.at(i).numOfMandates > 60)
                toEnd = true;
        }

    
        for (int i=0; i< mGraph.getNumVertices(); i++){
            if (getParty(i).getState() != Joined)
                toEnd = true;
        }
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
    return vector<vector<int>>();
}

Agent &Simulation::getAgentbyId(int agentId)       
{

    for(Agent agent: mAgents)
        if (agent.getId() == agentId)
            return agent;

}

void Simulation::addParty(int coalitionId, int partyId){      //NNN
    
    // partiesByCoalitions.at(coalitionId).push_back(partyId);


    // coalitionParties.push_back(party);
    // numOfMandates = numOfMandates+party.getMandates();
    //  _p.setCoalitionId(mCoalition);
 //  thisSim.partiesByCoalitions.at(mCoalition).push_back(_p.getPartyId());
   // clone

}  
