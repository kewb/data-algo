#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

struct BankInfo {
    char bankCode[6];
    long long totalCommission;
};

struct ClientInfo {
    char bankCode[6];
    char clientCode[11];
    char operationDate[11];
    long long operationAmount;
};

int main() {
    FILE *inputFile = fopen("input.txt", "r");
    FILE *outputFile = fopen("output.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        perror("Error opening files");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    struct BankInfo currentBank = {"", 0};
    struct ClientInfo currentClient = {"", "", "", 0};
    char currentMonth[3];

    while (fgets(line, sizeof(line), inputFile)) {
        char *bankCode = strtok(line, ";");
        char *clientCode = strtok(NULL, ";");
        char *operationDate = strtok(NULL, ";");
        char *operationAmountStr = strtok(NULL, ";");

        long long operationAmount = atoll(operationAmountStr);

        // Extract the month from the operation date
        strncpy(currentMonth, operationDate + 3, 2);
        currentMonth[2] = '\0';

        // Calculate commission (if applicable)
        long long commission = (operationAmount > 5000) ? (operationAmount - 5000) / 200 : 0;

        if (strcmp(bankCode, currentBank.bankCode) != 0) {
            // New bank encountered, write out the previous bank info
            if (currentBank.totalCommission > 0) {
                fprintf(outputFile, "%s|%s|%s;%lld,%03lld\n", currentBank.bankCode, currentClient.clientCode, currentMonth, currentBank.totalCommission / 1000, currentBank.totalCommission % 1000);
            }

            // Update the current bank code
            strcpy(currentBank.bankCode, bankCode);
            currentBank.totalCommission = 0;
        } else if (strcmp(clientCode, currentClient.clientCode) != 0 || strcmp(currentMonth, operationDate + 3) != 0) {
            // New client or new month encountered, write out the previous commission
            if (currentBank.totalCommission > 0) {
                fprintf(outputFile, "%s|%s|%s;%lld,%03lld\n", currentBank.bankCode, currentClient.clientCode, currentMonth, currentBank.totalCommission / 1000, currentBank.totalCommission % 1000);
            }

            // Update the current client and month
            strcpy(currentClient.clientCode, clientCode);
            strcpy(currentMonth, operationDate + 3);
        }

        // Accumulate the commission for the current bank
        currentBank.totalCommission += commission;
    }

    // Write out the last bank info
    if (currentBank.totalCommission > 0) {
        fprintf(outputFile, "%s|%s|%s;%lld,%03lld\n", currentBank.bankCode, currentClient.clientCode, currentMonth, currentBank.totalCommission / 1000, currentBank.totalCommission % 1000);
    }

    fclose(inputFile);
    fclose(outputFile);

    // Display the total commission for each bank
    printf("BANCA %s: total venit din comisioane - %lld\n", currentBank.bankCode, currentBank.totalCommission);

    return 0;
}
