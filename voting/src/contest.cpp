#include "contest.hpp"

#include <stdexcept>

Contest::Contest(int option_count): option_count_(option_count)
{
	vote_counts_.resize(option_count_, 0);
}

int Contest::option_count() const
{ 
	return option_count_; 
}

int Contest::vote_count(int option_num) const
{ 
	return vote_counts_[option_num-1]; 
}

int Contest::vote_count() const
{
	int total_count = 0;
	for (int num = 1; num <= option_count(); num++) {
		total_count += vote_count(num);
	}
	return total_count;
}

void Contest::cast_vote(int option_num) 
{
	if (option_num > option_count()) {
		throw std::invalid_argument("option num > option_count");
	}
	if (option_num < 1) {
		throw std::invalid_argument("option num < 1");
	}
	increment_vote_count(option_num);	
}

void Contest::increment_vote_count(int option_num)
{
	vote_counts_[option_num-1] += 1;
}
