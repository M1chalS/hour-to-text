#include <stdio.h>
#include <ctype.h>
#include <string.h>

int checkTimeIsValid(char *time) {
    if (!isdigit(time[0]) || !isdigit(time[1]) || !isdigit(time[3]) || !isdigit(time[4]) || time[2] != ':') {
        return 0;
    }

    if (((int) (time[0] - '0') >= 1 && (int) (time[1] - '0') > 2) ||
        ((int) (time[3] - '0') > 5 && (int) (time[4] - '0') > -1)) {
        return 0;
    }
    return 1;
}

char *convertToWritten(const char *time) {
    char *text;

    int hours = (time[0] - '0') * 10 + (time[1] - '0');

    switch (hours) {
        case 0:
            strcpy(text, "zerowa ");
            break;
        case 1:
            strcpy(text, "pierwsza ");
            break;
        case 2:
            strcpy(text, "druga ");
            break;
        case 3:
            strcpy(text, "trzecia ");
            break;
        case 4:
            strcpy(text, "czwarta ");
            break;
        case 5:
            strcpy(text, "piata ");
            break;
        case 6:
            strcpy(text, "szosta ");
            break;
        case 7:
            strcpy(text, "siodma ");
            break;
        case 8:
            strcpy(text, "osma ");
            break;
        case 9:
            strcpy(text, "dziewiata ");
            break;
        case 10:
            strcpy(text, "dziesiata ");
            break;
        case 11:
            strcpy(text, "jedenasta ");
            break;
        case 12:
            strcpy(text, "dwunasta ");
            break;
        default:
            strcpy(text, "Nieprawidlowa godzina ");
            break;
    }

    int minutes1 = (time[3] - '0');
    int minutes2 = (time[4] - '0');

    switch (minutes1) {
        case 0:
            break;
        case 1:
            switch (minutes2) {
                case 0:
                    strcat(text, "dziesiec ");
                    break;
                case 1:
                    strcat(text, "jedenascie ");
                    break;
                case 2:
                    strcat(text, "dwanascie ");
                    break;
                case 3:
                    strcat(text, "trzynascie ");
                    break;
                case 4:
                    strcat(text, "czternascie ");
                    break;
                case 5:
                    strcat(text, "pietnascie ");
                    break;
                case 6:
                    strcat(text, "szesnascie ");
                    break;
                case 7:
                    strcat(text, "siedemnascie ");
                    break;
                case 8:
                    strcat(text, "osiemnascie ");
                    break;
                case 9:
                    strcat(text, "dziewietnascie ");
                    break;
                default:
                    strcat(text, "Nieprawidlowa minuta ");
                    break;
            }
            break;
        case 2:
            strcat(text, "dwadziescia ");
            break;
        case 3:
            strcat(text, "trzydziesci ");
            break;
        case 4:
            strcat(text, "czterdziesci ");
            break;
        case 5:
            strcat(text, "piecdziesiat ");
            break;
        default:
            strcat(text, "Nieprawidlowa minuta ");
            break;
    }

    if (minutes1 != 1) {
        switch (minutes2) {
            case 0:
                break;
            case 1:
                strcat(text, "jeden");
                break;
            case 2:
                strcat(text, "dwa");
                break;
            case 3:
                strcat(text, "trzy");
                break;
            case 4:
                strcat(text, "cztery");
                break;
            case 5:
                strcat(text, "piec");
                break;
            case 6:
                strcat(text, "szesc");
                break;
            case 7:
                strcat(text, "siedem");
                break;
            case 8:
                strcat(text, "osiem");
                break;
            case 9:
                strcat(text, "dziewiec");
                break;
            default:
                strcat(text, "Nieprawidlowa minuta ");
                break;
        }
    }

    return text;
}

int main() {
    char time[] = "09:15"; // 21:15

    printf("Podaj godzine w formacie 12-godzinnym (HH:MM): ");
    scanf("%s", time);

    if (!checkTimeIsValid(time)) {
        printf("Nieprawidlowy format godziny.");
        return 0;
    }

    printf("\nWejscie: %s\n", time);
    printf("Wyjscie: %s", convertToWritten(time));
    return 0;
}
