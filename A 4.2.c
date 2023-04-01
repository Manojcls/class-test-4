#include <stdio.h>

struct player {
    char name[20];
    int runs;
};

int main() {
    struct player team[11]; 
    int n, total_runs = 0;

    printf("Enter the number of players in the team: ");
    scanf("%d", &n);


    for (int i = 0; i < n; i++) {
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", team[i].name);
        printf("Enter the runs scored by player %d: ", i + 1);
        scanf("%d", &team[i].runs);
        total_runs += team[i].runs;
    }

    
    printf("\nBatting Information:\n");
    printf("Player\tRuns\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\n", team[i].name, team[i].runs);
    }

  
    printf("Total runs scored by the team: %d\n", total_runs);

    return 0;
}

