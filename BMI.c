#include <stdio.h>
#include <unistd.h>

int main() {
    float weight, BMI, BMR, calories, distance, stride_length, activity, height;
    int age, gender, steps, interval;

    printf("\n==================== WELCOME TO THE FITNESS CALCULATOR ====================\n\n");

    printf("Enter your weight in kg: ");
    scanf("%f", &weight);

    printf("\nEnter your height in meters (e.g., 1.75 for 175cm): ");
    scanf("%f", &height);

    BMI = weight / (height * height);
    printf("\nYour BMI is: %f\n", BMI);

    printf("\n======================= BMI CATEGORY & GUIDELINES ========================\n");
    if (BMI < 18.5) {
        printf("You are underweight.\n\n");
        printf("GUIDELINES TO GAIN WEIGHT:\n");
        printf("1. Caloric Surplus: Aim for a 300-500 calorie surplus per day.\n");
        printf("2. Protein Intake: 1.2 to 1.5 grams per kilogram of body weight.\n");
        printf("3. Healthy Fats: Incorporate calorie-dense healthy fats.\n");
        printf("4. Frequent Meals: Eat 3 main meals and 2-3 snacks daily.\n");
        printf("5. Nutrient-Dense Foods: Focus on whole, minimally processed foods.\n");
    } else if (BMI >= 18.5 && BMI < 24.9) {
        printf("You are of normal weight.\n\n");
        printf("GUIDELINES TO MAINTAIN WEIGHT:\n");
        printf("1. Balance caloric intake with Total Daily Energy Expenditure (TDEE).\n");
        printf("2. Maintain macronutrient balance: 40%% carbs, 30%% protein, 30%% fats.\n");
        printf("3. Frequent Meals: Have 3 balanced meals and 1-2 snacks daily.\n");
    } else if (BMI >= 25 && BMI < 29.9) {
        printf("You are overweight.\n\n");
        printf("GUIDELINES TO LOSE WEIGHT:\n");
        printf("1. Create a caloric deficit of 500-750 calories per day.\n");
        printf("2. Focus on nutrient-dense, low-calorie foods.\n");
        printf("3. Protein Intake: 1.2 to 1.5 grams per kilogram of body weight.\n");
        printf("4. Moderate healthy fats and avoid processed carbs.\n");
    } else {
        printf("You are obese.\n\n");
        printf("GUIDELINES FOR WEIGHT MANAGEMENT:\n");
        printf("1. Start with a caloric deficit of 500-750 calories per day.\n");
        printf("2. Choose nutrient-dense, low-calorie foods.\n");
        printf("3. Focus on balanced meals and include full-body workouts.\n");
    }

    printf("\n==========================================================================\n");

    printf("\nEnter your age in years: ");
    scanf("%d", &age);

    printf("\nEnter your gender (1 = MALE, 2 = FEMALE): ");
    scanf("%d", &gender);

    if (gender == 1) {
        BMR = 88.362 + (13.397 * weight) + (4.799 * height * 100) - (5.677 * age);
    } else {
        BMR = 447.593 + (9.247 * weight) + (3.098 * height * 100) - (4.330 * age);
    }

    printf("\nSelect your activity level:\n");
    printf("1. Sedentary (little or no exercise)\n");
    printf("2. Lightly active (exercise 1-3 days/week)\n");
    printf("3. Moderately active (exercise 3-5 days/week)\n");
    printf("4. Very active (exercise 6-7 days/week)\n");
    printf("5. Super active (intense physical job or training)\n");
    printf("Enter your choice: ");
    scanf("%f", &activity);

    switch ((int)activity) {
        case 1:
            calories = BMR * 1.2;
            break;
        case 2:
            calories = BMR * 1.375;
            break;
        case 3:
            calories = BMR * 1.55;
            break;
        case 4:
            calories = BMR * 1.725;
            break;
        case 5:
            calories = BMR * 1.9;
            break;
        default:
            printf("Invalid input.\n");
            return 1;
    }

    printf("\nYour daily caloric needs are: %.2f calories/day\n", calories);

    printf("\n========================= STEP & DISTANCE TRACKER =========================\n");
    printf("\nEnter the number of steps taken: ");
    scanf("%d", &steps);

    if (steps <= 5000) {
        printf("You walk below average on a daily basis.\n");
    } else if (steps >= 7000 && steps <= 10000) {
        printf("You walk the recommended daily steps. Great job!\n");
    } else {
        printf("You walk above average. Keep it up and maintain a balanced diet.\n");
    }

    printf("\nEnter your stride length in meters: ");
    scanf("%f", &stride_length);

    distance = steps * stride_length;
    printf("Total distance covered: %.2f meters\n", distance);

    printf("\n========================== WATER INTAKE REMINDER ==========================\n");
    printf("Enter the interval (in minutes) for water reminders: ");
    scanf("%d", &interval);

    printf("\nStarting reminders. Press CTRL+C to stop.\n");
    while (1) {
        printf("\n*** Reminder: Drink water! ***\n");
        sleep(interval * 60);
    }
        printf("============THANK YOU============");

    return 0;
}
