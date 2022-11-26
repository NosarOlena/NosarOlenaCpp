#include <cstdio>
#include <cstdint>


void task6_1()
{
	uint8_t n;

	do
	{
		printf("n < 64 = ");
		scanf_s("%hhu" , &n);
	} while (n >= 64 || n <= 0);

	uint64_t m = 1llu << n;
	printf("2^%hhu = %llu\n", n, m);

}

void task6_2()
{
	int n, k;
	
	printf("n = ");
	scanf_s("%d", &n);

	do
	{
		printf("k > 0 = ");
		scanf_s("%d", &k);
	} while (k <= 0);

	printf("%d\n", n | (1 << k));
}

void task6_3()
{
	uint64_t m;
	uint8_t j;

	printf("m, j = ");
	scanf_s("%llu", &m);
	scanf_s("%hhu", &j);

	m &= ~(1 << (j - 1));
	printf("res (format 10) = %llu\nres (format 16) = %I64X\n", m, m);
}

void task6_4()
{
	uint32_t n;

	do
	{
		printf("n > 0 = ");
		scanf_s("%u", &n);
	} while (n <= 0);

	printf("n = %x\n", n);

	uint32_t first8bit = n & 0xFF;
	uint32_t last8bit = n >> 24;

	uint32_t m = ((n << 8) >> 16) << 8;

	m |= first8bit << 24;
	m |= last8bit;

	printf("m = %u\n", m);
	printf("m = %x\n", m);
}

void task6_5()
{
	int n;

	int len = sizeof(n) * 8;

	int cnt1 = 0;
	int max1 = 0;

	printf("Input n: ");
	scanf_s("%d", &n);

	for (int i = 0; i < len; i++)
	{
		if ((n >> i) & 1)
		{
			cnt1++;
		}
		else
		{
			if (cnt1 > max1) max1 = cnt1;
			cnt1 = 0;
		}
	}

	printf("Max number of 1 is %d\n", max1);
}

void task6_6()
{
	printf("y = (x & (x - 1)) > 0\n");
	// 0 - when x > 1 is power of 2, 1 otherwise
	int power2 = 2;

	for (int i = 2; i <= 500; i++)
	{
		printf("%d ", i);
		if (i == power2)
		{
			power2 *= 2;
			printf("power of 2 ");
			if ((i & (i - 1)) > 0)
			{
				printf("We are wrong cause %d is power of 2 but y == 1!\n", i);
				break;
			}
			else printf("y == 0\n");
		}
		else
		{
			if (!((i & (i - 1)) > 0))
			{
				printf("We are wrong cause %d is not power of 2 but y == 0!\n", i);
				break;
			}
			else printf("y == 1\n");
		}
		printf("\n");
	}
}

void task6_7()
{
	uint32_t A = 0x01020304;

	uint32_t A0 = A & 0xFF;
	uint32_t A3 = A >> 24;

	if (A0 == 0x04 && A3 == 0x01) printf("little endian\n");
	if (A0 == 0x01 && A3 == 0x04)
	{
		if ((A && (0xFF >> 8) == 0x02)) printf("middle endian\n");
		else printf("big endian\n");
	}
}

void task6_8()
{
	uint32_t m;
	uint8_t j;

	printf("m, j = ");
	scanf_s("%I32u", &m);
	scanf_s("%hhu", &j);

	m &= ~(1 << (j - 1));
	printf("res (format 10) = %I32u\nres (format 16) = %X\n", m, m);
}

void task6_20()
{
	unsigned n;
	unsigned i;

	unsigned len = sizeof(unsigned) * 8;

	unsigned res;

	do
	{
		printf("Input n > 0: ");
		scanf_s("%u", &n);
	} while (n <= 0);

	do
	{
		printf("Input 0<= i < %d: ", len);
		scanf_s("%u", &i);
	} while (i < 0 || i >= len);

	if (i == 0) res = n >> 1;
	else res = ((n >> (i + 1)) << i) | ((n << (len - i)) >> (len - i));
	printf("res = %d\n", res);


}

void task6_22()
{
	unsigned n;
	unsigned k;

	int len = sizeof(unsigned) * 8;

	unsigned res;

	unsigned flag = 0;

	printf("Input n: ");
	scanf_s("%d", &n);

	do
	{
		printf("Input 0 < k < %d: ", len);
		scanf_s("%u", &k);
	} while (k <= 0);

	for (int i = 0; i < (len - k); i++)
	{
		flag |= 1 << i;
	}

	res = (flag << k) | n;

	printf("res = %u\n", res);
}

int main()
{
	int n;

	printf("Input No of task [1-8, 20, 22]: ");
	scanf_s("%d", &n);

	switch (n)
	{
	case 1:
		task6_1();
		break;
	case 2:
		task6_2();
		break;
	case 3:
		task6_3();
		break;
	case 4:
		task6_4();
		break;
	case 5:
		task6_5();
		break;
	case 6:
		task6_6();
		break;
	case 7:
		task6_7();
		break;
	case 8:
		task6_8();
		break;
	case 20:
		task6_20();
		break;
	case 22:
		task6_22();
		break;
	}
}
