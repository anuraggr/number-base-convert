#include <math.h>
#include <stdio.h>
#include <string.h>

int DecimalToBinary();
int DecimalToOctal();
int DecimalToHexa();
int BinaryToDecimal();
int OctalToDecimal();
int HexaToDecimal();

int BinaryToOctal();
int BinaryToHexa();
int OctalToBinary();
int HexaToBinary();
int OctalToHexa();
int HexaToOctal();

int UserChoice();

int main() {

  UserChoice();

  return 0;
}

int UserChoice() 
{
  int n;
  printf("Please choose the conversion you want to do:\n 1. Binary to Octal\n "
         "2. Binary to Decimal\n 3. Binary to Hexadecimal \n\n 4. Octal to "
         "Binary\n 5. Octal to Decimal\n 6. Octal to Hexadecimal \n\n 7. "
         "Decimal to Binary\n 8. Decimal to Octal\n 9. Decimal to Hexadecimal "
         "\n\n 10. Hexadecimal to Binary\n 11. Hexadecimal to Octal\n 12. "
         "Hexadecimal to Decimal\n");

  scanf(" %d", &n);

  switch (n) {
  case 1:
    BinaryToOctal();
    break;
  case 2:
    BinaryToDecimal();
    break;
  case 3:
    BinaryToHexa();
    break;
  case 4:
    OctalToBinary();
    break;
  case 5:
    OctalToDecimal();
    break;
  case 6:
    OctalToHexa();
    break;
  case 7:
    DecimalToBinary();
    break;
  case 8:
    DecimalToOctal();
    break;
  case 9:
    DecimalToHexa();
    break;
  case 10:
    HexaToBinary();
    break;
  case 11:
    HexaToOctal();
    break;
  case 12:
    HexaToDecimal();
    break;
  default:
    printf("Invalid Choice");
    break;
  }

  return 0;
}

int HexaToOctal() {
  char hexa[100];
  printf("Enter a hexadecimal value: ");
  scanf("%s", hexa);

  int DecimalNum[32] = {0};

  for (int i = 0; i < strlen(hexa); i++) {
    switch (hexa[i]) {
    case 'A':
      DecimalNum[i] = 10;
      break;
    case 'B':
      DecimalNum[i] = 11;
      break;
    case 'C':
      DecimalNum[i] = 12;
      break;
    case 'D':
      DecimalNum[i] = 13;
      break;
    case 'E':
      DecimalNum[i] = 14;
      break;
    case 'F':
      DecimalNum[i] = 15;
      break;
    default:
      DecimalNum[i] = hexa[i] - '0';
    }
  }

  int decimal = 0;
  for (int i = 0; i < strlen(hexa); i++) {
    decimal += DecimalNum[i] * pow(16, strlen(hexa) - 1 - i);
  }

  printf("Octal is: ");

  if (decimal == 0) {
    printf("0");
  }

  int OctalNum[32] = {0};
  int i = 0;

  while (decimal > 0) {
    OctalNum[i] = decimal % 8;
    decimal = decimal / 8;
    i++;
  }

  for (int j = i - 1; j >= 0; j--) {
    printf("%d", OctalNum[j]);
  }

  return 0;
}

int OctalToHexa() {
  int n, digit_count = 0, digit, decimal = 0;
  printf("Enter a octal number: ");
  scanf("%d", &n);

  int temp_n = n;
  while (temp_n >= 1) {
    temp_n /= 10;
    digit_count++;
  }

  temp_n = n;

  for (int i = 0; i < digit_count; i++) {
    digit = temp_n % 10;
    decimal += digit * pow(8, i);
    temp_n /= 10;
  }

  printf("Hexadecimal is: ");

  if (decimal == 0) {
    printf("0");
  }

  char HexaNum[32] = {0};
  int i = 0, r;

  while (decimal > 0) {

    r = decimal % 16;
    decimal = decimal / 16;

    switch (r) {
    case 10:
      HexaNum[i] = 'A';
      i++;
      break;
    case 11:
      HexaNum[i] = 'B';
      i++;
      break;
    case 12:
      HexaNum[i] = 'C';
      i++;
      break;
    case 13:
      HexaNum[i] = 'D';
      i++;
      break;
    case 14:
      HexaNum[i] = 'E';
      i++;
      break;
    case 15:
      HexaNum[i] = 'F';
      i++;
      break;
    default:
      r = r + '0';
      HexaNum[i] = r;
      i++;
    }
  }

  for (int j = i - 1; j >= 0; j--) {
    printf("%c", HexaNum[j]);
  }
  return 0;
}

int HexaToBinary() {
  char hexa[100];
  printf("Enter a hexadecimal value: ");
  scanf("%s", hexa);

  int DecimalNum[32] = {0};

  for (int i = 0; i < strlen(hexa); i++) {
    switch (hexa[i]) {
    case 'A':
      DecimalNum[i] = 10;
      break;
    case 'B':
      DecimalNum[i] = 11;
      break;
    case 'C':
      DecimalNum[i] = 12;
      break;
    case 'D':
      DecimalNum[i] = 13;
      break;
    case 'E':
      DecimalNum[i] = 14;
      break;
    case 'F':
      DecimalNum[i] = 15;
      break;
    default:
      DecimalNum[i] = hexa[i] - '0';
    }
  }

  int decimal = 0;
  for (int i = 0; i < strlen(hexa); i++) {
    decimal += DecimalNum[i] * pow(16, strlen(hexa) - 1 - i);
  }

  printf("Binary is: ");

  if (decimal == 0) {
    printf("0");
  }

  int binaryNum[32] = {0};
  int i = 0;

  while (decimal > 0) {
    binaryNum[i] = decimal % 2;
    decimal = decimal / 2;
    i++;
  }

  for (int j = i - 1; j >= 0; j--) {
    printf("%d", binaryNum[j]);
  }
  return 0;
}

int OctalToBinary() {
  int n, digit_count = 0, digit, decimal = 0;
  printf("Enter a octal number: ");
  scanf("%d", &n);

  int temp_n = n;
  while (temp_n >= 1) {
    temp_n /= 10;
    digit_count++;
  }

  temp_n = n;

  for (int i = 0; i < digit_count; i++) {
    digit = temp_n % 10;
    decimal += digit * pow(8, i);
    temp_n /= 10;
  }

  printf("Binary is: ");

  if (decimal == 0) {
    printf("0");
  }

  int binaryNum[32] = {0};
  int i = 0;

  while (decimal > 0) {
    binaryNum[i] = decimal % 2;
    decimal = decimal / 2;
    i++;
  }

  for (int j = i - 1; j >= 0; j--) {
    printf("%d", binaryNum[j]);
  }

  return 0;
}

int BinaryToHexa() {
  int n, digit_count = 0, digit, decimal = 0;
  printf("Enter a binary number: ");
  scanf("%d", &n);

  int temp_n = n;
  while (temp_n >= 1) {
    temp_n /= 10;
    digit_count++;
  }

  temp_n = n;

  for (int i = 0; i < digit_count; i++) {
    digit = temp_n % 10;
    decimal += digit * pow(2, i);
    temp_n /= 10;
  }

  printf("Hexadecimal is: ");

  if (decimal == 0) {
    printf("0");
  }

  char HexaNum[32] = {0};
  int i = 0, r;

  while (decimal > 0) {

    r = decimal % 16;
    decimal = decimal / 16;

    switch (r) {
    case 10:
      HexaNum[i] = 'A';
      i++;
      break;
    case 11:
      HexaNum[i] = 'B';
      i++;
      break;
    case 12:
      HexaNum[i] = 'C';
      i++;
      break;
    case 13:
      HexaNum[i] = 'D';
      i++;
      break;
    case 14:
      HexaNum[i] = 'E';
      i++;
      break;
    case 15:
      HexaNum[i] = 'F';
      i++;
      break;
    default:
      r = r + '0';
      HexaNum[i] = r;
      i++;
    }
  }

  for (int j = i - 1; j >= 0; j--) {
    printf("%c", HexaNum[j]);
  }
  return 0;
}

int BinaryToOctal() {
  int n, digit_count = 0, digit, decimal = 0;
  printf("Enter a binary number: ");
  scanf("%d", &n);

  int temp_n = n;

  while (temp_n >= 1) {
    temp_n /= 10;
    digit_count++;
  }

  temp_n = n;

  for (int i = 0; i < digit_count; i++) {
    digit = temp_n % 10;
    decimal += digit * pow(2, i);
    temp_n /= 10;
  }

  printf("Octal is: ");

  if (decimal == 0) {
    printf("0");
  }

  int OctalNum[32] = {0};
  int i = 0;

  while (decimal > 0) {
    OctalNum[i] = decimal % 8;
    decimal = decimal / 8;
    i++;
  }

  for (int j = i - 1; j >= 0; j--) {
    printf("%d", OctalNum[j]);
  }
  return 0;
}

int HexaToDecimal() {
  char hexa[100];
  printf("Enter a hexadecimal value: ");
  scanf("%s", hexa);
  printf("Decimal is: ");

  int DecimalNum[32] = {0};

  for (int i = 0; i < strlen(hexa); i++) {
    switch (hexa[i]) {
    case 'A':
      DecimalNum[i] = 10;
      break;
    case 'B':
      DecimalNum[i] = 11;
      break;
    case 'C':
      DecimalNum[i] = 12;
      break;
    case 'D':
      DecimalNum[i] = 13;
      break;
    case 'E':
      DecimalNum[i] = 14;
      break;
    case 'F':
      DecimalNum[i] = 15;
      break;
    default:
      DecimalNum[i] = hexa[i] - '0';
    }
  }

  int decimal = 0;
  for (int i = 0; i < strlen(hexa); i++) {
    decimal += DecimalNum[i] * pow(16, strlen(hexa) - 1 - i);
  }

  printf("%d", decimal);

  return 0;
}

int OctalToDecimal() {
  int n, digit_count = 0, digit, decimal = 0;
  printf("Enter a binary number: ");
  scanf("%d", &n);
  printf("Decimal is: ");

  int temp_n = n;
  while (temp_n >= 1) {
    temp_n /= 10;
    digit_count++;
  }

  temp_n = n;

  for (int i = 0; i < digit_count; i++) {
    digit = temp_n % 10;
    decimal += digit * pow(8, i);
    temp_n /= 10;
  }
  printf("%d", decimal);

  return 0;
}

int BinaryToDecimal() {
  int n, digit_count = 0, digit, decimal = 0;
  printf("Enter a binary number: ");
  scanf("%d", &n);
  printf("Decimal is: ");

  int temp_n = n;
  while (temp_n >= 1) {
    temp_n /= 10;
    digit_count++;
  }

  temp_n = n;

  for (int i = 0; i < digit_count; i++) {
    digit = temp_n % 10;
    decimal += digit * pow(2, i);
    temp_n /= 10;
  }
  printf("%d", decimal);

  return decimal;
}

int DecimalToHexa() {
  int n;
  printf("Enter a decimal number: ");
  scanf("%d", &n);

  printf("Hexadecimal is: ");

  if (n == 0) {
    printf("0");
  }

  char HexaNum[32] = {0};
  int i = 0, r;

  while (n > 0) {

    r = n % 16;
    n = n / 16;

    switch (r) {
    case 10:
      HexaNum[i] = 'A';
      i++;
      break;
    case 11:
      HexaNum[i] = 'B';
      i++;
      break;
    case 12:
      HexaNum[i] = 'C';
      i++;
      break;
    case 13:
      HexaNum[i] = 'D';
      i++;
      break;
    case 14:
      HexaNum[i] = 'E';
      i++;
      break;
    case 15:
      HexaNum[i] = 'F';
      i++;
      break;
    default:
      r = r + '0';
      HexaNum[i] = r;
      i++;
    }
  }

  for (int j = i - 1; j >= 0; j--) {
    printf("%c", HexaNum[j]);
  }
  return 0;
}

int DecimalToOctal() {
  int n;
  printf("Enter a decimal number: ");
  scanf("%d", &n);

  printf("Octal is: ");

  if (n == 0) {
    printf("0");
  }

  int OctalNum[32] = {0};
  int i = 0;

  while (n > 0) {
    OctalNum[i] = n % 8;
    n = n / 8;
    i++;
  }

  for (int j = i - 1; j >= 0; j--) {
    printf("%d", OctalNum[j]);
  }
  return 0;
}

int DecimalToBinary() {
  int n;
  printf("Enter a decimal number: ");
  scanf("%d", &n);

  printf("Binary is: ");

  if (n == 0) {
    printf("0");
  }

  int binaryNum[32] = {0};
  int i = 0;

  while (n > 0) {
    binaryNum[i] = n % 2;
    n = n / 2;
    i++;
  }

  for (int j = i - 1; j >= 0; j--) {
    printf("%d", binaryNum[j]);
  }
  return 0;
}
