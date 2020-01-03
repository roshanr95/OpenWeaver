#include "./Simulator.h"
#include "../EventManagement/EventManager/EventManager.h"
#include "../Network/Node/Miner.h"
#include "../../helpers/InitializeNetwork.h"

// #include "../Networking/RoutingTable.h"
// #include "../Blockchain/Block/Block.h"
// #include "../Blockchain/Block/PoWBlock.h"
// #include "../Blockchain/Block/PoSBlock.h"

bool Simulator::setup() {
	network = getRandomNetwork();
	return true;
}

void Simulator::start() {
	LOG(INFO) << "Starting simulator"; 

	EventManager eventManager;

	while(eventManager.hasNextEvent()) {
		eventManager.executeNextEvent();
	}

	LOG(INFO) << "Safely exiting simulator"; 
}