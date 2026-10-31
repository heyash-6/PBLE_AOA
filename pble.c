
#include <stdio.h>

#define MAX 100

struct Package
{
    int id;
    float value, weight, ratio;
    float selectedWeight, selectedValue;
};

struct Package p[MAX];
int n = 0, entered = 0, sorted = 0, calculated = 0;
float capacity = 0, maxValue = 0, totalWeight = 0;

void enterDetails()
{
    int i;

    printf("Enter number of packages (1-%d): ", MAX);
    scanf("%d", &n);

    if (n < 1 || n > MAX)
    {
        printf("Invalid number of packages!\n");
        n = 0;
        entered = 0;
        sorted = 0;
        calculated = 0;
        return;
    }

    for (i = 0; i < n; i++)
    {
        p[i].id = i + 1;

        printf("Enter value of package %d: ", i + 1);
        scanf("%f", &p[i].value);

        printf("Enter weight of package %d: ", i + 1);
        scanf("%f", &p[i].weight);

        if (p[i].value < 0 || p[i].weight <= 0)
        {
            printf("Invalid value or weight!\n");
            n = 0;
            entered = 0;
            sorted = 0;
            calculated = 0;
            return;
        }

        p[i].ratio = 0;
        p[i].selectedWeight = 0;
        p[i].selectedValue = 0;
    }

    printf("Enter vehicle capacity: ");
    scanf("%f", &capacity);

    if (capacity <= 0)
    {
        printf("Invalid capacity!\n");
        n = 0;
        entered = 0;
        sorted = 0;
        calculated = 0;
        return;
    }

    entered = 1;
    sorted = 0;
    calculated = 0;

    printf("Package details entered successfully.\n");
}

void displayDetails()
{
    int i;

    if (!entered)
    {
        printf("Please enter package details first.\n");
        return;
    }

    printf("\nID\tValue\tWeight\tRatio\n");

    for (i = 0; i < n; i++)
    {
        printf("%d\t%.2f\t%.2f\t%.2f\n",
               p[i].id, p[i].value, p[i].weight,
               p[i].value / p[i].weight);
    }

    printf("Vehicle Capacity = %.2f\n", capacity);
}

void calculateRatio()
{
    int i;

    if (!entered)
    {
        printf("Please enter package details first.\n");
        return;
    }

    for (i = 0; i < n; i++)
    {
        p[i].ratio = p[i].value / p[i].weight;
    }

    printf("\nValue-to-weight ratios calculated:\n");

    for (i = 0; i < n; i++)
    {
        printf("Package %d: %.2f\n",
               p[i].id, p[i].ratio);
    }
}

void sortPackages()
{
    int i, j;
    struct Package temp;

    if (!entered)
    {
        printf("Please enter package details first.\n");
        return;
    }

    calculateRatio();

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (p[j].ratio < p[j + 1].ratio)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    sorted = 1;
    calculated = 0;

    printf("\nPackages sorted by decreasing ratio:\n");
    printf("ID\tValue\tWeight\tRatio\n");

    for (i = 0; i < n; i++)
    {
        printf("%d\t%.2f\t%.2f\t%.2f\n",
               p[i].id, p[i].value,
               p[i].weight, p[i].ratio);
    }
}

void findMaximumValue()
{
    int i;
    float remaining, fraction;

    if (!entered)
    {
        printf("Please enter package details first.\n");
        return;
    }

    if (!sorted)
        sortPackages();

    remaining = capacity;
    maxValue = 0;
    totalWeight = 0;

    for (i = 0; i < n; i++)
    {
        p[i].selectedWeight = 0;
        p[i].selectedValue = 0;

        if (remaining <= 0)
            break;

        if (p[i].weight <= remaining)
        {
            p[i].selectedWeight = p[i].weight;
            p[i].selectedValue = p[i].value;
        }
        else
        {
            fraction = remaining / p[i].weight;

            p[i].selectedWeight = remaining;
            p[i].selectedValue = p[i].value * fraction;
        }

        remaining -= p[i].selectedWeight;
        totalWeight += p[i].selectedWeight;
        maxValue += p[i].selectedValue;
    }

    calculated = 1;

    printf("\nMaximum value = %.2f\n", maxValue);
    printf("Total weight used = %.2f\n", totalWeight);
}

void displaySelected()
{
    int i;

    if (!calculated)
    {
        printf("Please calculate maximum value first.\n");
        return;
    }

    printf("\nSelected Packages:\n");
    printf("ID\tWeight Taken\tValue Obtained\n");

    for (i = 0; i < n; i++)
    {
        if (p[i].selectedWeight > 0)
        {
            printf("%d\t%.2f\t\t%.2f\n",
                   p[i].id, p[i].selectedWeight,
                   p[i].selectedValue);
        }
    }

    printf("Total Weight = %.2f\n", totalWeight);
    printf("Maximum Value = %.2f\n", maxValue);
}

int main()
{
    int choice;

    do
    {
        printf("\n--- SMART DELIVERY PLANNING ---\n");
        printf("1. Enter Package Details\n");
        printf("2. Display Package Details\n");
        printf("3. Calculate Value/Weight Ratio\n");
        printf("4. Sort Packages by Ratio\n");
        printf("5. Find Maximum Value\n");
        printf("6. Display Selected Packages\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                enterDetails();
                break;

            case 2:
                displayDetails();
                break;

            case 3:
                calculateRatio();
                break;

            case 4:
                sortPackages();
                break;

            case 5:
                findMaximumValue();
                break;

            case 6:
                displaySelected();
                break;

            case 7:
                printf("Program terminated.\n");
                break;

            default:
                printf("Invalid menu choice!\n");
        }

    } while (choice != 7);

    return 0;
}
