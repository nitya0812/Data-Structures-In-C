#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define _CRT_SECURE_NO_WARNINGS


void PrintMonth(int year, int month, int print_to_file) {
    system("cls");
    const char * moth = "January";
    const char * filename = "Calendar.txt";
    int days = 0;
    int FirstDay;
    int NewMonth = month - 2;
    int LastTwo = year % 100;
    FILE* fptr;


    if (NewMonth <= 0) {
        LastTwo -= 1;
    }
    if (NewMonth <= 0) {
        NewMonth += 12;
    }
    FirstDay = 1 + (((13 * NewMonth) - 1) / 5) + LastTwo + (LastTwo / 4) + ((year - (year % 100)) / 400) - (2 * ((year - (year % 100)) / 100));
    if (FirstDay >= 0) {
        FirstDay = FirstDay % 7;
    }
    else {
        int Temp = FirstDay;
        while (Temp % 7 != 0) {
            Temp--;
        }
        FirstDay = FirstDay - Temp;
    }

    switch (month) {
    case 1:
        moth = "January";
        days = 31;
        break;
    case 2:
        moth = "February";
        days = 28;
        if (year % 400 == 0) {
            days = 29;
        }
        else if (year % 100 == 0) {
            days = 28;
        }
        else if (year % 4 == 0) {
            days = 29;
        }
        break;
    case 3:
        moth = "March";
        days = 31;
        break;
    case 4:
        moth = "April";
        days = 30;
        break;
    case 5:
        moth = "May";
        days = 31;
        break;
    case 6:
        moth = "June";
        days = 30;
        break;
    case 7:
        moth = "July";
        days = 31;
        break;
    case 8:
        moth = "August";
        days = 31;
        break;
    case 9:
        moth = "September";
        days = 30;
        break;
    case 10:
        moth = "October";
        days = 31;
        break;
    case 11:
        moth = "November";
        days = 30;
        break;
    case 12:
        moth = "December";
        days = 31;
        break;
    }
    if (print_to_file > 0) {
        fptr=fopen(filename, "w+");
        if (fptr) {
            printf("Printing calendar to %s\n Close notepad to continue \n", filename);
        }
        else {
            printf("Unable to open file %s to write \n", filename);
            exit(1);
        }
    }
    if (print_to_file >0 && fptr) {
        fprintf(fptr, "  %s %d\n", moth, year);
        fprintf(fptr, "Su Mo Tu We Th Fr Sa\n");
    }
    else {
        printf("   %s %d\n", moth, year);
        printf("Su Mo Tu We Th Fr Sa\n");
    }
    if (print_to_file >0 && fptr) {
    }
    else {
    }
    for (int i = 0; i <= FirstDay; i++) {
        if (i != 0) {
            if (print_to_file > 0 && fptr) {
                fprintf(fptr, "   ");
            }
            else {
                printf("   ");
            }
        }
    }
    int ITnumber = 0;
    for (int i = 1; i <= days; i++) {
        if (i % (7 - FirstDay + (7 * ITnumber)) == 0) {
            if (print_to_file > 0 && fptr) {
                fprintf(fptr, "%2d\n", i);
            }
            else {
                printf("%2d\n", i);
            }

            ITnumber++;
        }
        else {
            if (print_to_file > 0 && fptr) {
                fprintf(fptr, "%2d ", i);
            }
            else {
                printf("%2d ", i);
            }

        }
    }
    if (print_to_file > 0 && fptr) {
        fclose(fptr);
    }
    printf("\n");

    if (print_to_file) system("notepad Calendar.txt");

}
int main() {
    printf("Calendar\n");
    int CurrentYear;
    int CurrentMonth;

    printf("Enter The year:");
    scanf("%d", &CurrentYear);
    while(CurrentYear < 0 ) {
        printf("Negative value for Year is not valid, try with a valid year again\n");
        scanf("%d", &CurrentYear);
    }
    printf("\nEnter The Month (in numbers):");
    scanf("%d", &CurrentMonth);
    while(CurrentMonth <= 0 || CurrentMonth > 12) {
        printf("%d is not valid. Month should be between 1 and 12, please try again\n", CurrentMonth);
        scanf("%d",&CurrentMonth);
    }
    PrintMonth(CurrentYear, CurrentMonth, 0);

    printf("\nNext Month: Left arrow\nPrevious Month: Right arrow\nNext Year: Up arrow\nPrevious Year: Down arrow\nInsert new Year and Month: i\nPrint in a text file: p\nLeave: esc\n");

    while (1) {

        int input = _getch();

        switch (input) {
        case 77:
            if (CurrentMonth == 12) {
                CurrentYear++;
                CurrentMonth = 1;
                PrintMonth(CurrentYear, CurrentMonth, 0);
            }
            else {
                CurrentMonth++;
                PrintMonth(CurrentYear, CurrentMonth,0);
            }
            printf("\nNext Month: Left arrow\nPrevious Month: Right arrow\nNext Year: Up arrow\nPrevious Year: Down arrow\nInsert new Year and Month: i\nPrint in a text file: p\nLeave: esc\n");
            break;
        case 75:
            if (CurrentMonth == 1) {
                    if(CurrentYear == 0){
                        printf("Year cannot be negative!\n");
                    }
                    else{
                        CurrentYear--;
                        CurrentMonth = 12;
                        PrintMonth(CurrentYear, CurrentMonth,0);
                    }
            }
            else {
                CurrentMonth--;
                PrintMonth(CurrentYear, CurrentMonth,0);
                printf("\nNext Month: Left arrow\nPrevious Month: Right arrow\nNext Year: Up arrow\nPrevious Year: Down arrow\nInsert new Year and Month: i\nPrint in a text file: p\nLeave: esc\n");
            }
            break;
        case 72:
            CurrentYear++;
            PrintMonth(CurrentYear, CurrentMonth,0);
            printf("\nNext Month: Left arrow\nPrevious Month: Right arrow\nNext Year: Up arrow\nPrevious Year: Down arrow\nInsert new Year and Month: i\nPrint in a text file: p\nLeave: esc\n");
            break;
        case 80:
            if(CurrentYear == 0){
                printf("Year cannot be negative!\n");
            }
            else{
                CurrentYear--;
                PrintMonth(CurrentYear, CurrentMonth,0);
                printf("\nNext Month: Left arrow\nPrevious Month: Right arrow\nNext Year: Up arrow\nPrevious Year: Down arrow\nInsert new Year and Month: i\nPrint in a text file: p\nLeave: esc\n");
            }
            break;
        case 27:
            return 0;
        case 105:
            printf("Enter The year:");
            scanf("%d", &CurrentYear);
            while(CurrentYear < 0 ) {
                 printf("Negative value for Year is not valid, try with a valid year again\n");
                 scanf("%d", &CurrentYear);
                 }
            printf("\nEnter The Month (in numbers):");
            scanf("%d", &CurrentMonth);
            while(CurrentMonth <= 0 || CurrentMonth > 12) {
                 printf("%d is not valid. Month should be between 1 and 12, please try again\n", CurrentMonth);
                 scanf("%d",&CurrentMonth);
            }
            PrintMonth(CurrentYear, CurrentMonth, 0);
            printf("\nNext Month: Left arrow\nPrevious Month: Right arrow\nNext Year: Up arrow\nPrevious Year: Down arrow\nInsert new Year and Month: i\nPrint in a text file: p\nLeave: esc\n");
            break;
        case 112:
            PrintMonth(CurrentYear, CurrentMonth, 1);
            PrintMonth(CurrentYear, CurrentMonth, 0);
            printf("\nNext Month: Left arrow\nPrevious Month: Right arrow\nNext Year: Up arrow\nPrevious Year: Down arrow\nInsert new Year and Month: i\nPrint in a text file: p\nLeave: esc\n");
            break;
        default:
            break;
        }
    }
}
