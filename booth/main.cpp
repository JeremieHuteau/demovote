#include <iostream>

#include "voting/contest.hpp"

int main() {
	std::cout << std::endl << "#~# Voting booth #~#" << std::endl << std::endl;

	int options_count = 2;

	Contest contest = Contest(options_count);

	for (int i=0; i<5; i++) {
		int option_num = (i % 2) + 1;
		contest.cast_vote(option_num);
	}

	for (int num = 1; num <= contest.option_count(); num++) {
		std::cout << "Option n°" << num \
			<< " got " << contest.vote_count(num)	<< " votes." << std::endl;
	}

	return 0;
}

