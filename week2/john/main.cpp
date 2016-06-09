#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
	fstream stream(argv[1], ios_base::in);

	int n, m;
	while (stream >> n && stream >> m)
	{
		if (m == 1)
			cout << n - 1 << endl;
		else if (m == 0)
			cout << n << endl;

		// excluding the last door and iteration from calculations, the state of the last door is computed at the end and added if open
		int n_exclude_last = n - 1;
		int m_exclude_last = m - 1;

		// ax represents number of doors affected by beat 1
		// bx represents number of doors affected by beat 2
		// abx represents number of doors affected by both
		// always_open represents number of doors affected by neither
		int ax = n_exclude_last / 2;
		int bx = n_exclude_last / 3;
		int abx = n_exclude_last / 6;
		int always_open = n_exclude_last - ax - (bx - abx);

		bool divisible_by_2 = n % 2 == 0;
		bool divisible_by_3 = n % 3 == 0;

		// o represents number of doors that will always be open regardless of number of iterations > 1
		int o = always_open + abx;

		if (m_exclude_last > 1 && m_exclude_last % 2 == 0)
		{
			o += bx - abx;

			if (divisible_by_2 && !divisible_by_3)
				o += 1;
		}
		else if (divisible_by_2 && !divisible_by_3)
		{
			o += 1;
		}
		else if (!divisible_by_2 && divisible_by_3)
		{
			o += 1;
		}

		cout << o << endl;
	}

	return 0;
}
