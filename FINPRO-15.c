#include <stdio.h>
#include <stdlib.h>

typedef enum {
    NEUTRAL = 1,
    NEAR_NEUTRAL = 2,
    NON_NEUTRAL = 3,
    EXTREME = 4
} PostureType;

typedef enum {
    SLOW = 1,
    FAIR = 2,
    FAST = 3,
    VERY_FAST = 4
} SpeedType;

typedef struct {
    int intensity;
    float duration_pct;
    int efforts;
    PostureType posture;
    SpeedType speed;
    float hours;
} TaskData;

typedef struct {
    float m_intensity;
    float m_duration;
    float m_efforts;
    float m_posture;
    float m_speed;
    float m_hours;
    float strain_index;
    int risk_level;
} Result;

int main () {
    TaskData task;
    Result   result;
    int      pilihan;
    char     ulangi;

    system("cls");
    printf("========================================\n");
    printf("    RSI STRAIN INDEX CALCULATOR\n");
    printf("    Based on Moore & Garg (1995)\n");
    printf("    SDG 3: Good Health & Well-Being\n");
    printf("========================================\n");
    printf("This program calculates your risk of\n");
    printf("Repetitive Strain Injury (RSI) on your\n");
    printf("hands and wrists from gaming or coding.\n");
    printf("You will answer 6 simple questions.\n");
    printf("========================================\n");
    printf("\nPress ENTER to start...");
    getchar();

    do {

        system("cls");
        printf("========================================\n");
        printf("    RSI STRAIN INDEX CALCULATOR\n");
        printf("========================================\n");
        printf("[1/6] INTENSITY OF EXERTION\n");
        printf("----------------------------------------\n");
        printf("How hard are your fingers/hands working\n");
        printf("during the activity?\n\n");
        printf("Rate based on how tired your fingers\n");
        printf("feel after 10 minutes:\n\n");
        printf("1. Light\n");
        printf("   Fingers barely feel anything.\n");
        printf("   e.g. browsing, reading, scrolling\n\n");
        printf("2. Somewhat Light\n");
        printf("   Fingers slightly active, comfortable.\n");
        printf("   e.g. casual typing, replying messages\n\n");
        printf("3. Somewhat Hard\n");
        printf("   Fingers noticeably working.\n");
        printf("   e.g. typing reports, regular computer use\n\n");
        printf("4. Hard\n");
        printf("   Fingers work heavily, tired after 30 min.\n");
        printf("   e.g. fast typing, intensive computer work\n\n");
        printf("5. Near Maximal\n");
        printf("   Fingers at maximum capacity.\n");
        printf("   e.g. non-stop typing, high-speed repetitive work\n\n");
        printf("----------------------------------------\n");
        do {
            printf("Choose (1-5): ");
            scanf("%d", &task.intensity);
        } while (task.intensity < 1 || task.intensity > 5);

        system("cls");
        printf("========================================\n");
        printf("    RSI STRAIN INDEX CALCULATOR\n");
        printf("========================================\n");
        printf("[2/6] DURATION OF EXERTION\n");
        printf("----------------------------------------\n");
        printf("Out of 60 seconds, how many seconds are\n");
        printf("your fingers ACTIVELY pressing keys\n");
        printf("or clicking the mouse?\n\n");
        printf("Do not count pauses or resting time.\n\n");
        printf("1. 0-5 seconds active   ( 5%%)\n");
        printf("   Fingers mostly resting.\n");
        printf("   e.g. reading, watching, occasional clicks\n\n");
        printf("2. 6-17 seconds active  (20%%)\n");
        printf("   Fingers work occasionally.\n");
        printf("   e.g. light typing with long pauses\n\n");
        printf("3. 18-29 seconds active (40%%)\n");
        printf("   Fingers work and rest equally.\n");
        printf("   e.g. regular typing with thinking pauses\n\n");
        printf("4. 30-47 seconds active (60%%)\n");
        printf("   Fingers active more than resting.\n");
        printf("   e.g. continuous typing, fast computer work\n\n");
        printf("5. 48-60 seconds active (80%%)\n");
        printf("   Fingers almost constantly pressing.\n");
        printf("   e.g. non-stop typing, repetitive clicking\n\n");
        printf("----------------------------------------\n");
        do {
            printf("Choose (1-5): ");
            scanf("%d", &pilihan);
        } while (pilihan < 1 || pilihan > 5);

        if      (pilihan == 1) task.duration_pct = 5.0;
        else if (pilihan == 2) task.duration_pct = 20.0;
        else if (pilihan == 3) task.duration_pct = 40.0;
        else if (pilihan == 4) task.duration_pct = 60.0;
        else                   task.duration_pct = 80.0;

        system("cls");
        printf("========================================\n");
        printf("    RSI STRAIN INDEX CALCULATOR\n");
        printf("========================================\n");
        printf("[3/6] EFFORTS PER MINUTE\n");
        printf("----------------------------------------\n");
        printf("How many times do you press keyboard\n");
        printf("keys or click the mouse per minute?\n\n");
        printf("Count all keystrokes and mouse clicks\n");
        printf("combined in one minute.\n\n");
        printf("1. Less than 50 times per minute\n");
        printf("   You press keys or click very rarely.\n");
        printf("   e.g. reading articles, watching videos,\n");
        printf("        occasional mouse clicks\n\n");
        printf("2. 50 to 100 times per minute\n");
        printf("   You press keys or click occasionally.\n");
        printf("   e.g. casual typing, replying messages,\n");
        printf("        light computer work\n\n");
        printf("3. 100 to 150 times per minute\n");
        printf("   You press keys or click at a moderate rate.\n");
        printf("   e.g. regular typing, writing reports,\n");
        printf("        moderate computer work\n\n");
        printf("4. 150 to 200 times per minute\n");
        printf("   You press keys or click frequently.\n");
        printf("   e.g. fast typing, intensive computer work,\n");
        printf("        rapid data entry\n\n");
        printf("5. More than 200 times per minute\n");
        printf("   You press keys or click at a very high rate.\n");
        printf("   e.g. non-stop typing, highly repetitive\n");
        printf("        clicking or keystrokes\n\n");
        printf("----------------------------------------\n");
        do {
            printf("Choose (1-5): ");
            scanf("%d", &pilihan);
        } while (pilihan < 1 || pilihan > 5);

        if      (pilihan == 1) task.efforts = 40;
        else if (pilihan == 2) task.efforts = 75;
        else if (pilihan == 3) task.efforts = 125;
        else if (pilihan == 4) task.efforts = 175;
        else                   task.efforts = 250;

        system("cls");
        printf("========================================\n");
        printf("    RSI STRAIN INDEX CALCULATOR\n");
        printf("========================================\n");
        printf("[4/6] HAND/WRIST POSTURE\n");
        printf("----------------------------------------\n");
        printf("What is the position of your wrist\n");
        printf("relative to your forearm while working?\n\n");
        printf("1. Neutral\n");
        printf("   Your wrist is completely straight and\n");
        printf("   aligned with your forearm.\n");
        printf("   There is no bending up, down, or sideways.\n");
        printf("   e.g. keyboard stand with a wrist rest\n\n");
        printf("2. Near Neutral\n");
        printf("   Your wrist is almost straight with only\n");
        printf("   a slight bend (less than 15 degrees).\n");
        printf("   e.g. standard desktop, keyboard lying flat\n\n");
        printf("3. Non-Neutral\n");
        printf("   Your wrist is clearly bent (15-30 degrees).\n");
        printf("   You can visibly see the bend.\n");
        printf("   e.g. laptop on a desk too low or too high\n\n");
        printf("4. Extreme\n");
        printf("   Your wrist is severely bent (30+ degrees).\n");
        printf("   The bend is very noticeable.\n");
        printf("   e.g. laptop on bed or lap\n\n");
        printf("----------------------------------------\n");
        do {
            printf("Choose (1-4): ");
            scanf("%d", &pilihan);
        } while (pilihan < 1 || pilihan > 4);
        task.posture = (PostureType) pilihan;

        system("cls");
        printf("========================================\n");
        printf("    RSI STRAIN INDEX CALCULATOR\n");
        printf("========================================\n");
        printf("[5/6] SPEED OF WORK\n");
        printf("----------------------------------------\n");
        printf("How rushed is your working pace\n");
        printf("during the activity?\n\n");
        printf("1. Slow\n");
        printf("   Very relaxed, many long pauses.\n");
        printf("   You can stop anytime without any problem.\n");
        printf("   e.g. hobby project with no deadline\n\n");
        printf("2. Fair\n");
        printf("   Normal comfortable pace.\n");
        printf("   Deadline is still days away.\n");
        printf("   e.g. assignment due next week\n\n");
        printf("3. Fast\n");
        printf("   Somewhat rushed, short pauses only.\n");
        printf("   There is pressure to finish quickly.\n");
        printf("   e.g. assignment due tomorrow\n\n");
        printf("4. Very Fast\n");
        printf("   Full sprint mode, almost no breaks.\n");
        printf("   Stopping feels impossible.\n");
        printf("   e.g. assignment due in a few hours\n\n");
        printf("----------------------------------------\n");
        do {
            printf("Choose (1-4): ");
            scanf("%d", &pilihan);
        } while (pilihan < 1 || pilihan > 4);
        task.speed = (SpeedType) pilihan;

        system("cls");
        printf("========================================\n");
        printf("    RSI STRAIN INDEX CALCULATOR\n");
        printf("========================================\n");
        printf("[6/6] DURATION PER DAY\n");
        printf("----------------------------------------\n");
        printf("How many hours per day do you spend\n");
        printf("on this activity on average?\n\n");
        printf("How to estimate your daily average:\n");
        printf("Add up your total hours in one week,\n");
        printf("then divide by 7.\n\n");
        printf("Example:\n");
        printf("Mon 2h + Tue 2h + Wed 2h + Thu 3h\n");
        printf("+ Fri 4h + Sat 8h + Sun 6h = 27h\n");
        printf("27 / 7 = 3.9 hours per day\n\n");
        printf("Tip: Check your screen time app for\n");
        printf("a more accurate number.\n\n");
        printf("Format: 1.5 = 1 hour 30 minutes\n\n");
        printf("----------------------------------------\n");
        do {
            printf("Hours (0-16): ");
            scanf("%f", &task.hours);
        } while (task.hours < 0 || task.hours > 16);

        result = hitung_strain_index(&task);
        tampilkan_hasil(&task, &result);

        printf("\nCalculate again? (y/n): ");
        scanf(" %c", &ulangi);

    } while (ulangi == 'y' || ulangi == 'Y');

    system("cls");
    printf("========================================\n");
    printf("  Thank you for using RSI Calculator!\n");
    printf("          Stay healthy!\n");
    printf("========================================\n");

    return 0;
}