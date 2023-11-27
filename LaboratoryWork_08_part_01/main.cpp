#include "sources.h"

int main() {
    int numberIterations = 1000000, containerSize = 10000;

	AddingElementsToEnd(numberIterations);
    SearchingElements(containerSize);
    RemovingElementsFromBeginning(containerSize);

	return 0;
}