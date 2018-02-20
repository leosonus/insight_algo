#include <stdio.h>
#include <stdlib.h>

#define N 5

// copied
void swap_arr(int arr[], int i, int j)
{
	int temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

// copied
void print_mperm(int arr[][N], int r, int t)
{
	int i, j;

	for (i = 0; i < t; i++) {
		for (j = 0; j < r; j++)
			printf("%d ", arr[i][j]);
		printf("  ");
	}
	printf("\n");
}

static long called;

enum CATEGORY {COUNTRY, COLOR, BEVERAGE, CIGARETTE, PET};
enum eCOUNTRY {England, Germany, Sweden, Norway, Denmark};
enum eCOLOR   {Red, Green, Blue, Yellow, White};
enum eBEVERAGE {Tea, Water, Milk, Coffee, Beer};
enum eCIGARETTE {Blend, Dunhill, BlueMaster, PallMall, Prince};
enum ePET {Dog, Cat, Horse, Zebra, Bird};

int check_einstein(int solution[][N])
{
#if 1
	called++;
	if (called % 1000000 == 0)
		printf("%ld\n", called);
#endif

	if (solution[COUNTRY][England] != solution[COLOR][Red]) 
		return 0;   // rule 1
	if (solution[COUNTRY][Sweden] != solution[PET][Dog]) 
		return 0;   // rule 2
	if (solution[COUNTRY][Denmark] != solution[BEVERAGE][Tea]) 
		return 0;	// rule 3
	if (solution[COLOR][Green] != solution[COLOR][White] - 1) 
		return 0;   // rule 4
	if (solution[COLOR][Green] != solution[BEVERAGE][Coffee]) 
		return 0;   // rule 5
	if (solution[CIGARETTE][PallMall] != solution[PET][Bird]) 
		return 0;   // rule 6
	if (solution[COLOR][Yellow] != solution[CIGARETTE][Dunhill]) 
		return 0;   // rule 7
	if (solution[BEVERAGE][Milk] != 2)
		return 0;	// rule 8
	if (solution[COUNTRY][Norway] != 0) 
		return 0;   // rule 9
	if (abs(solution[CIGARETTE][Blend] - solution[PET][Cat]) != 1) 
		return 0;	// rule 10;
	if (abs(solution[PET][Horse] - solution[CIGARETTE][Dunhill]) != 1) 
		return 0;	// rule 11;
	if (solution[CIGARETTE][BlueMaster] != solution[BEVERAGE][Beer]) 
		return 0;	// rule 12
	if (solution[COUNTRY][Germany] != solution[CIGARETTE][Prince]) 
		return 0;	// rule 13
	if (abs(solution[COUNTRY][Norway] - solution[COLOR][Blue]) != 1) 
		return 0;	// rule 14;
	if (abs(solution[CIGARETTE][Blend] - solution[BEVERAGE][Water]) != 1) 
		return 0;	// rule 15;

	return 1;
}

int check_einstein2(int solution[][N], int level)
{
	called++;

	if (level == 0) {          
		// COUNTRY
		if (solution[COUNTRY][Norway] != 0) 
			return 0;	// rule 9
	} else if (level == 1) {   
		// COUNTRY, COLOR
		if (solution[COUNTRY][England] != solution[COLOR][Red]) 
			return 0;	// rule 1
		if (solution[COLOR][Green] != solution[COLOR][White] - 1) 
			return 0;	// rule 4
		if (abs(solution[COUNTRY][Norway] - solution[COLOR][Blue]) != 1) 
			return 0;	// rule 14;
	} else if (level == 2) {   
		// COUNTRY, COLOR, BEVERAGE
		if (solution[BEVERAGE][Milk] != 2) 
			return 0;	// rule 8
		if (solution[COUNTRY][Denmark] != solution[BEVERAGE][Tea]) 
			return 0;	// rule 3
		if (solution[COLOR][Green] != solution[BEVERAGE][Coffee]) 
			return 0;	// rule 5
	} else if (level == 3) {   
		// COUNTRY, COLOR, BEVERAGE, CIGARETTE
		if (solution[COLOR][Yellow] != solution[CIGARETTE][Dunhill]) 
			return 0;	// rule 7
		if (solution[CIGARETTE][BlueMaster] != solution[BEVERAGE][Beer]) 
			return 0;	// rule 12
		if (solution[COUNTRY][Germany] != solution[CIGARETTE][Prince]) 
			return 0;	// rule 13
		if (abs(solution[CIGARETTE][Blend] - solution[BEVERAGE][Water]) != 1) 
			return 0;	// rule 15;
	} else if (level == 4) {   
		// COUNTRY, COLOR, BEVERAGE, CIGARETTE, PET
		if (solution[COUNTRY][Sweden] != solution[PET][Dog]) 
			return 0;	// rule 2
		if (solution[CIGARETTE][PallMall] != solution[PET][Bird]) 
			return 0;	// rule 6
		if (abs(solution[CIGARETTE][Blend] - solution[PET][Cat]) != 1) 
			return 0;	// rule 10;
		if (abs(solution[PET][Horse] - solution[CIGARETTE][Dunhill]) != 1) 
			return 0;	// rule 11;
	}

	return 1;
}

void mperm_einstein(int arr[][N], int index, int len, int n, int r, int t)
{
	int i;

	if (index == t) {
		if (check_einstein(arr)) 
			print_mperm(arr, r, t);
		return;
	}

	if (len == r) {
		mperm_einstein(arr, index + 1, 0, n, r, t);
		return;
	}

	for (i = len; i < n; i++) {
		swap_arr(arr[index], i, len);
		mperm_einstein(arr, index, len + 1, n, r, t);
		swap_arr(arr[index], i, len);
	}
}

void mperm_einstein2(int arr[][N], int index, int len, int n, int r, int t)
{
	int i;

	if (index == t) {
		if (check_einstein2(arr, index - 1)) 
			print_mperm(arr, r, t);
		return;
	}

	if (len == r) {
		if (check_einstein2(arr, index)) 
			mperm_einstein2(arr, index + 1, 0, n, r, t);
		return;
	}

	for (i = len; i < n; i++) {
		swap_arr(arr[index], i, len);
		mperm_einstein2(arr, index, len + 1, n, r, t);
		swap_arr(arr[index], i, len);
	}
}

int test()
{
	int arr[N][N];
	arr[COUNTRY][0] = Norway;
	arr[COUNTRY][1] = Denmark;
	arr[COUNTRY][2] = England;
	arr[COUNTRY][3] = Germany;
	arr[COUNTRY][4] = Sweden;

	arr[COLOR][0] = Yellow;
	arr[COLOR][1] = Blue;
	arr[COLOR][2] = Red;
	arr[COLOR][3] = Green;
	arr[COLOR][4] = White;

	arr[BEVERAGE][0] = Water;
	arr[BEVERAGE][1] = Tea;
	arr[BEVERAGE][2] = Milk;
	arr[BEVERAGE][3] = Coffee;
	arr[BEVERAGE][4] = Beer;

	arr[CIGARETTE][0] = Dunhill;
	arr[CIGARETTE][1] = Blend;
	arr[CIGARETTE][2] = PallMall;
	arr[CIGARETTE][3] = Prince;
	arr[CIGARETTE][4] = BlueMaster;

	arr[PET][0] = Cat;
	arr[PET][1] = Horse;
	arr[PET][2] = Bird;
	arr[PET][3] = Zebra;
	arr[PET][4] = Dog;

	printf("%d\n", check_einstein(arr));
	return 1;
}

int main()
{
	int arr[N][N], i, j;

	//test();
	for(i=0; i<N; i++) 
		for(j=0; j<N; j++)
			arr[i][j] = j;

	mperm_einstein(arr, 0, 0, N, N, N);
	//mperm_einstein2(arr, 0, 0, N, N, N);
	printf("called: %ld\n", called);
	return 0;
}
