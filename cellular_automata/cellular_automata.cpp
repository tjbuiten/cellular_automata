// Function decleration
int rules(int a, int b, int c);

// Start of the program
int main()
{
	// Variables
	const int children = 72;
	const int generations = 32;
	int gen[children];

	// Initialize first gen and draw it
	for (int i = 0; i < children; i++) {
		gen[i] = 0;
	}
	gen[children / 2] = 1;

	// Set up variables for the nextgens
	int nextgens[2] = { 0, 0 };

	// Generation process
	for (int i = 1; i < generations; i++) {

		// Start of the new generation
		for (int j = 1; j < children - 1; j++) {
			nextgens[1] = nextgens[0];
			nextgens[0] = rules(gen[j - 1], gen[j], gen[j + 1]);

			gen[j - 1] = nextgens[1];
		}

		// Flush out last values from nextgens
		gen[children - 2] = nextgens[1];
	}

	// End of the program
	return 0;
}

// Handling the rulesets for our Cellular Automata
int rules(int a, int b, int c) {
	int ruleset[8] = { 0,0,0,1,1,1,1,0 };
	if (a == 1 && b == 1 && c == 1) return ruleset[0];
	else if (a == 1 && b == 1 && c == 0) return ruleset[1];
	else if (a == 1 && b == 0 && c == 1) return ruleset[2];
	else if (a == 1 && b == 0 && c == 0) return ruleset[3];
	else if (a == 0 && b == 1 && c == 1) return ruleset[4];
	else if (a == 0 && b == 1 && c == 0) return ruleset[5];
	else if (a == 0 && b == 0 && c == 1) return ruleset[6];
	else if (a == 0 && b == 0 && c == 0) return ruleset[7];
	return 0;
}