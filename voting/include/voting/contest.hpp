#ifndef VOTING_CONTEST_H
#define VOTING_CONTEST_H

#include <vector>

class Contest {
	public:
		Contest(int option_count);

		int option_count() const;

		int vote_count(int option_num) const;
		int vote_count() const;

		void cast_vote(int option_num);

	private:
		void increment_vote_count(int option_num);	

		int option_count_;
		std::vector<int> vote_counts_;
};

#endif // #ifndef VOTING_CONTEST_H
