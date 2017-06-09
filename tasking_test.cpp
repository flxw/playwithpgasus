#include <vector>
#include <list>
#include <iostream>

#include <base/node.hpp>
#include <tasking/tasking.hpp>

//using numa::TaskRef;
//using numa::TriggerableRef;
using namespace std;

ostream& operator<<(ostream &os, const vector<numa::CpuId> &cl) {
	for (int i = 0; i < cl.size(); ++i) {
		os << (int)cl[i] << " ";
	}

	return os;
}

void printTaskNode() {
	cout << "Task running on node PHY" << numa::Node::curr().physicalId()
			 << " LOG" << numa::Node::curr().logicalId() << endl;
}

int main (int argc, char const* argv[]) {
	int priority = 0;
	int core = 0;
	list<numa::TriggerableRef> taskList;

	numa::NodeList nodeList = numa::NodeList::allNodes();

	for (int i = 0; i < nodeList.size(); ++i) {
		taskList.push_back(numa::async<void>(printTaskNode, priority, nodeList[i]));
	}

	numa::wait(taskList);

	return 0;
}
