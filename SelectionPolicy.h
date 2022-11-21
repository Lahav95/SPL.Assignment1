#pragma once

class SelectionPolicy {

public:

    void step(Simulation &);
    bool isValid(int v1, int v2, Simulation &);
    Party biggestMandate(Simulation &sim, Agent agent);
    Party biggestEdge(Simulation &sim, Agent agent);
    
    virtual ~SelectionPolicy(){};
    virtual Party select(Simulation& sim, Agent agent)=0;
        
 };

class MandatesSelectionPolicy: public SelectionPolicy{ 

     public:
        MandatesSelectionPolicy();
        virtual ~MandatesSelectionPolicy();
        virtual Party select(Simulation& sim, Agent agent); 


    //call biggestMandate func to select party (Agent agent)

    // void join();

    //add self to offers vectosr

};

class EdgeWeightSelectionPolicy: public SelectionPolicy{ 

    public:
        EdgeWeightSelectionPolicy();
        virtual ~EdgeWeightSelectionPolicy();
        virtual Party select(Simulation& sim, Agent agent);

    //call biggestEdge func to select party (Agent agent)

    // void join();

    //add self to offers vector

};