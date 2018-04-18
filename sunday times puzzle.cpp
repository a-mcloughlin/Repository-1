// ConsoleApplication6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"


void main()
{
	int i,j,k,num;
	int mods[1000];
	int signals[1000][3];
	int ans[10];

	for (num = 100; num < 1000; num++)
	{
		mods[num] = 0;
		signals[num - 100][3] = num % 10;
		signals[num - 100][2] = (((num % 100) - signals[num - 100][3]) / 10);
		signals[num - 100][1] = ((num - ((10 * signals[num - 100][2]) + (signals[num - 100][3]))) / 100);

		if (signals[num - 100][1] != 0 && signals[num - 100][2] != 0 && signals[num - 100][3] != 0)
		{
			mods[num] = num;
		}

		if (signals[j - 100][1] == signals[j - 100][2] || signals[j - 100][1] == signals[j - 100][3] || signals[j - 100][3] == signals[j - 100][2])
		{
			mods[j] = 0;
		}
	}

	i = 0;
	j = 0;
	for (i = 100;i < 1000; i++)
	{
		ans[0] = ((signals[i - 100][1] * 100) + (signals[i - 100][2] * 10) + (signals[i - 100][3]));
		ans[1] = ((signals[i - 100][2] * 100) + (signals[i - 100][3] * 10) + (signals[i - 100][1]));
		ans[2] = ((signals[i - 100][3] * 100) + (signals[i - 100][1] * 10) + (signals[i - 100][2]));
		ans[3] = ((signals[i - 100][3] * 100) + (signals[i - 100][2] * 10) + (signals[i - 100][1]));
		ans[4] = ((signals[i - 100][2] * 100) + (signals[i - 100][1] * 10) + (signals[i - 100][3]));
		ans[5] = ((signals[i - 100][1] * 100) + (signals[i - 100][3] * 10) + (signals[i - 100][2]));

		for (j = 0;j < 6;j++)
		{
			for (k = 0;k < 6;k++)
			{
				if (mods[i] != 0)
				{
					if ((ans[j] % 7) == (ans[k] % 7) && j != k)
					{
						mods[i] = 0;
					}
					if (ans[k] % 7 == 0)
						mods[i] = 0;
				}
			}
		}
	}

	i = 0;
	for (i = 100;i < 1000;i++)
	{
		if (mods[i] != 0 && (mods[i] % 3 == 0) && (mods[i] % 7 != 0))
		{
			printf("The Numbers are %d, %d and %d\n\n", signals[i - 100][1], signals[i - 100][2], signals[i - 100][3]);
			break;
		}
	}
}

