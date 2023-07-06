#include <stdexcept>
using namespace std;

struct GuessResult
{
	bool solved;
	int strikes;
	int balls;
};

class Baseball
{
public:
	explicit Baseball(const string& questions)
		: question(questions)
	{
	}

	GuessResult guess(const string& guessNumber)
	{
		assertIllegalArgument(guessNumber);

		if (guessNumber == question)
		{
			return { true, 3, 0 };
		}

		GuessResult ret = { false, 0, 0 };
		ret.strikes = getStrikeCnt(guessNumber);
		ret.balls = getBallCnt(guessNumber);
		if (ret.strikes == 3) ret.solved = true;

		return ret;
	}

	void assertIllegalArgument(const string& guessNumber)
	{
		if (guessNumber.length() != 3)
		{
			throw length_error("Must be three letters.");
		}

		for (char ch : guessNumber)
		{
			if (ch >= '0' && ch <= '9')
				continue;
			throw invalid_argument("Must be number");
		}

		if (isDuplicateNumber(guessNumber))
		{
			throw invalid_argument("Must not have the same number");
		}
	}

private:
	bool isDuplicateNumber(const string& guessNumber)
	{
		return guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2];
	}
	
	int getStrikeCnt(const string& guessNumber)
	{
		int cnt = 0;
		for (int i = 0; i < guessNumber.size(); ++i)
		{
			if (guessNumber[i] != question[i]) continue;

			cnt++;
		}
		return cnt;
	}

	int getBallCnt(const string& guessNumber)
	{
		int cnt = 0;
		for (int i = 0; i < guessNumber.size(); ++i)
		{			
			for (int j = 0; j < 3; ++j)
			{
				if (i == j) continue;
				if (question[i] != guessNumber[j]) continue;

				cnt++;
				break;
			}
		}
		return cnt;
	}

private:
	string question;
};
