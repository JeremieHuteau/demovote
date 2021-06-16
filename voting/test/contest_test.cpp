#include <gtest/gtest.h>
#include "voting/contest.hpp"

TEST(contest_test, vote_count) { 
	int option_count = 3;

	Contest contest = Contest(option_count);

	ASSERT_EQ(contest.vote_count(), 0);
	ASSERT_EQ(contest.vote_count(1), 0);
	ASSERT_EQ(contest.vote_count(2), 0);
	ASSERT_EQ(contest.vote_count(3), 0);

	contest.cast_vote(1);

	ASSERT_EQ(contest.vote_count(), 1);
	ASSERT_EQ(contest.vote_count(1), 1);
	ASSERT_EQ(contest.vote_count(2), 0);
	ASSERT_EQ(contest.vote_count(3), 0);

	contest.cast_vote(1);

	ASSERT_EQ(contest.vote_count(), 2);
	ASSERT_EQ(contest.vote_count(1), 2);
	ASSERT_EQ(contest.vote_count(2), 0);
	ASSERT_EQ(contest.vote_count(3), 0);

	contest.cast_vote(2);

	ASSERT_EQ(contest.vote_count(), 3);
	ASSERT_EQ(contest.vote_count(1), 2);
	ASSERT_EQ(contest.vote_count(2), 1);
	ASSERT_EQ(contest.vote_count(3), 0);

	contest.cast_vote(3);

	ASSERT_EQ(contest.vote_count(), 4);
	ASSERT_EQ(contest.vote_count(1), 2);
	ASSERT_EQ(contest.vote_count(2), 1);
	ASSERT_EQ(contest.vote_count(3), 1);
}


