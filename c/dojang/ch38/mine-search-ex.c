#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <stdlib.h>

#include <string.h>


int main()

{

	int m, n;

	// 행렬의 크기 변수 정의

	scanf("%d %d", &m, &n);

	// 행렬의 크기 입력받음

	char **mt = malloc(sizeof(char *) * m);

	// 문자 행렬을 저장할 (세로) 메모리 할당

	for (int c1 = 0; c1 < m; c1++)

		mt[c1] = malloc(sizeof(char) * n+1);

	// 문자 행렬을 저장할 (가로) 메모리 할당

	memset(mt, 0, sizeof(mt));

	// 메모리를 0으로 초기화

	for (int c2 = 0; c2 < m; c2++)

		scanf("%s", mt[c2]);

	// 문자 행렬 입력받음

	

	for (int i = 0; i < m; i++)

	{

		for (int j = 0; j < n; j++)

		{

			if (mt[i][j] == '*')

				continue;

			// 검사하는 값이 별이면 건너뛰기

			else

			{

				mt[i][j] = 0;

				// 주변 값을 체크하기 전에 0으로 초기화

				for (int k = i - 1; k < i + 1; k++)

				{

					if (k < 0 || k >= m)

						continue;

					else

					{

						for (int l = j - 1; l <= j + 1; l++)

						{

							if (l < 0 || l >= n)

							{

								continue;

							}

							// 주변 값을 체크할 때 범위를 벗어나면 건너뛰기

							else

							{

								if (mt[k][l] == '*')

								{

									mt[i][j] += 1;

								}

								// 만약 주변 값에 *이 있으면 +1

							}

							// 정상적으로 주변 값을 체크함

						}

					}

				}

			// 검사하는 값이 별이 아니면 주변 값들 체크

			}

		}

	}

	

	

	

	for (int i = 0; i < m; i++)

		free(mt[i]);

	// 가로 메모리 해방

	free(mt);

	// 세로 메모리 해방

	

	return 0;

	// 0을 반환하여 프로그램 종료

}
