/*




 */

#include "task4.h"

void task4::dummy()
{
}

static bool change(vector<int> &flags)
{
	for (auto e : flags) {
		if (e != 0)
			return true;
	}
	return false;
}

vector<int> task4::studentscore(vector<int> &scores)
{
	int sz = scores.size();
	vector<int> flags(sz, 0);

	while (1) {
		for (int i = 1; i < sz - 1; ++i) {
			if (scores[i] < scores[i + 1] && scores[i] < scores[i - 1])
				flags[i] = 1;
			else if (scores[i] > scores[i + 1] && scores[i] > scores[i - 1])
				flags[i] = -1;
		}

		if (!change(flags)) break;
		for (int i = 1; i < sz - 1; ++i) {
			scores[i] += flags[i];
			flags[i] = 0;
		}
	}

	return scores;

}
