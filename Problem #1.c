#include <stdio.h>

// Function to find and display all possible scoring combinations for a given score
void findCombinations(int score) {
    printf("Possible combinations of scoring plays if a team's score is %d:\n", score);
    
    for (int td2 = 0; td2 * 8 <= score; td2++) {
        for (int td7 = 0; td7 * 7 + td2 * 8 <= score; td7++) {
            for (int td6 = 0; td6 * 6 + td7 * 7 + td2 * 8 <= score; td6++) {
                for (int fg = 0; fg * 3 + td6 * 6 + td7 * 7 + td2 * 8 <= score; fg++) {
                    for (int safety = 0; safety * 2 + fg * 3 + td6 * 6 + td7 * 7 + td2 * 8 <= score; safety++) {
                        if (td2 * 8 + td7 * 7 + td6 * 6 + fg * 3 + safety * 2 == score) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td2, td7, td6, fg, safety);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int score;

    // Prompt the user to enter scores
    while (1) {
        printf("Enter the NFL score (enter 0 or 1 to stop): ");
        scanf("%d", &score);

        // If score is less than 2, exit the loop
        if (score <= 1) {
            break;
        }

        // Call function to find combinations for the entered score
        findCombinations(score);
    }

    return 0;
}
