#include "pch.h"
#include "../Project5/baseball.cpp"

#include <stdexcept>
using namespace std;

TEST(BaseballGame, ThrowExceptionWhenInputLengthIsUnmatched) {
	Baseball game;
	EXPECT_THROW(game.guess(string("12")), length_error);
}