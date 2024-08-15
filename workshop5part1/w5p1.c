/*
Glenn Parreno
115 814 196
geparreno@myseneca.ca
IPC144 NDD
*/

#include <stdio.h>
#define MAX_PATH_LEN 70
#define MIN_PATH_LEN 10
#define MAX_LIVES 10
#define MIN_LIVES 1
#define MULTIPLE 5


struct PlayerInfo
{
	int playerLives;
	char playerSymbol;
	int playerTreasure;
	int playerMoves[MAX_PATH_LEN];
};

struct GameInfo
{
	int maxMoves;
	int pathLen;
	int treasures[MAX_PATH_LEN];
	int bombs[MAX_PATH_LEN];
};

int main(void)
{
	struct PlayerInfo player = { 0, '\0', 0, {0} };
	struct GameInfo game = { 0, 0, {0}, {0} };
	int i, j, num1 = 1, num2 = MULTIPLE, num3 = 0;

	printf("================================\n");
	printf("         Treasure Hunt!         \n");
	printf("================================\n\n");
	printf("PLAYER Configuration\n");
	printf("--------------------\n");
	printf("Enter a single character to represent the player: ");
	scanf(" %c", &player.playerSymbol);
	do
	{
		printf("Set the number of lives: ");
		scanf("%d", &player.playerLives);

		if (player.playerLives > MAX_LIVES || player.playerLives < MIN_LIVES)
			printf("     Must be between %d and %d\n", MIN_LIVES, MAX_LIVES);

	}while(player.playerLives > MAX_LIVES || player.playerLives < MIN_LIVES);

	printf("Player configuration set-up is complete\n\n");
	printf("GAME Configuration\n");
	printf("------------------\n");
	do
	{
		printf("Set the path length (a multiple of %d between %d - %d): ", MULTIPLE, MIN_PATH_LEN, MAX_PATH_LEN);
		scanf("%d", &game.pathLen);
		if (game.pathLen > MAX_PATH_LEN || game.pathLen < MIN_PATH_LEN || game.pathLen % MULTIPLE != 0)
			printf("     Must be a multiple of %d and between %d-%d!!!\n", MULTIPLE, MIN_PATH_LEN, MAX_PATH_LEN);

	} while (game.pathLen > MAX_PATH_LEN || game.pathLen < MIN_PATH_LEN || game.pathLen % MULTIPLE != 0);
	do
	{
		printf("Set the limit for number of moves allowed: ");
		scanf("%d", &game.maxMoves);
		if (game.maxMoves > (game.pathLen * .75) || game.maxMoves < player.playerLives)
			printf("    Value must be between %d and %.0lf\n", player.playerLives, game.pathLen * .75);

	} while (game.maxMoves > game.pathLen * .75 || game.maxMoves < player.playerLives);

	printf("\nBomb Placement\n");
	printf("--------------\n");
	printf("Enter the bomb positions in sets of %d where a value\n"
		"of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n"
		"(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", MULTIPLE, game.pathLen);

	for (i = 0; i < (game.pathLen / MULTIPLE); i++)
	{
		printf("   Positions [%2d-%2d]: ", num1, num2);
		for (j = 0; j < MULTIPLE; j++)
		{
			scanf("%d", &game.bombs[num3]);
			num3 += 1;
		}
		num1 = num1 + MULTIPLE;
		num2 = num2 + MULTIPLE;
	}
	printf("BOMB placement set\n\n");

	printf("TREASURE Placement\n");
	printf("------------------\n");
	printf("Enter the treasure placements in sets of %d where a value\n"
		"of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n"
		"(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", MULTIPLE, game.pathLen);

	num1 = 1, num2 = MULTIPLE, num3 = 0;
	for (i = 0; i < (game.pathLen / MULTIPLE); i++)
	{
		printf("   Positions [%2d-%2d]: ", num1, num2);
		for (j = 0; j < MULTIPLE; j++)
		{
			scanf("%d", &game.treasures[num3]);
			num3 += 1;
		}
		num1 = num1 + MULTIPLE;
		num2 = num2 + MULTIPLE;
	}
	printf("TREASURE placement set\n\n");
	printf("GAME configuration set-up is complete...\n\n");
	printf("------------------------------------\n");
	printf("TREASURE HUNT Configuration Settings\n");
	printf("------------------------------------\n");
	printf("Player:\n");
	printf("   Symbol     : %c\n", player.playerSymbol);
	printf("   Lives      : %d\n", player.playerLives);
	printf("   Treasure   : [ready for gameplay]\n");
	printf("   History    : [ready for gameplay]\n\n");

	printf("Game:\n");
	printf("   Path Length: %d\n", game.pathLen);
	printf("   Bombs      : ");
	for (i = 0; i < game.pathLen; i++)
	{
		printf("%d", game.bombs[i]);
	}
	printf("\n");
	printf("   Treasure   : ");

	for (i = 0; i < game.pathLen; i++)
	{
		printf("%d", game.treasures[i]);
	}
	printf("\n\n");
	printf("====================================\n");
	printf("~ Get ready to play TREASURE HUNT! ~\n");
	printf("====================================\n");



	return 0;
}