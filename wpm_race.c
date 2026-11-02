#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int main() {
    char sentence[] = "C programming is fun!";
    char input[100];
    time_t start, end;
    double time_taken, wpm;
    int player_distance = 0, computer_distance = 0;
    int player_speed;

    printf("🏁 Welcome to the Typing Speed Car Race Game! 🏁\n\n");
    printf("Type this sentence as fast as you can:\n");
    printf("\"%s\"\n\n", sentence);
    printf("Press ENTER when you are ready to start...");
    getchar();

    printf("\nStart typing now:\n");
    time(&start);
    fgets(input, sizeof(input), stdin);
    time(&end);

    input[strcspn(input, "\n")] = 0;

    time_taken = difftime(end, start);
    int correct = 0;
    int total = strlen(sentence);
    for (int i = 0; i < total; i++) {
        if (input[i] == sentence[i])
            correct++;
    }

    double accuracy = ((double)correct / total) * 100.0;
    wpm = ((double)strlen(input) / 5) / (time_taken / 60.0);

    player_speed = (int)wpm / 5; // convert typing speed into car movement units
    player_distance = player_speed;
    computer_distance = rand() % 15 + 5; // random computer speed

    printf("\n=== Race Progress ===\n\n");
    printf("Player Car : ");
    for (int i = 0; i < player_distance; i++) printf("-");
    printf("🚗\n");

    printf("Computer Car: ");
    for (int i = 0; i < computer_distance; i++) printf("-");
    printf("🚙\n");

    printf("\n=== Results ===\n");
    printf("Time Taken: %.2f seconds\n", time_taken);
    printf("Accuracy: %.2f%%\n", accuracy);
    printf("Typing Speed: %.2f WPM\n\n", wpm);

    if (player_distance > computer_distance)
        printf("🏆 You Win! Your typing speed beat the computer!\n");
    else if (player_distance < computer_distance)
        printf("😅 Computer Wins! Try to type faster next time!\n");
    else
        printf("🤝 It's a tie! So close!\n");

    return 0;
}
