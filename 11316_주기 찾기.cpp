#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;
int visit[1000010];

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		long long int s, p, q, m;
		scanf("%lld %lld %lld %lld", &s, &p, &q, &m);

		long long int cnt = 1;
		visit[s] = cnt;
		cnt++;

		long long int temp;
		while (1) {
			temp = (s * p + q) % m;
			if (visit[temp] != 0) break;

			s = (s * p + q) % m;
			visit[s] = cnt;

			cnt++;
		}
		//printf("--------------\n%d\n", cnt);
		//printf("-------------\n%d\n", visit[temp]);
		printf("#%d %d\n", test_case, cnt - visit[temp]);
		memset(visit, 0, sizeof(visit));
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}