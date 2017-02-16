
#include "BST_Tester.h"
#include "Experiment.h"
using namespace std;

int main() {
	BST_Tester bstt;
	bstt.runTests();
	Experiment e;
	for (unsigned i = 0; i < 10; i++) {
		e.runExperiment();
	}
}
