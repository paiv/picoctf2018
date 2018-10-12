#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;


#define BRUTE 1


u8
check_valid_char(char x) {
    if (x >= '0' && x <= '9') {
        return 1;
    }
    if (x >= 'A' && x <= 'Z') {
        return 1;
    }
    return 0;
}


u8
check_valid_key(char* key) {
    u32 i = 0;
    while (key[i] != '\0') {
        if (!check_valid_char(key[i])) {
            return 0;
        }
        i++;
    }
    return i == 16;
}


u8
ord(char x) {
    if (x <= '9') {
        return x - '0';
    }
    return x - '7';
}


u32
mod(i32 x, i32 m) {
    // return x % m;
    i32 a = x % m;
    return (a < 0) ? m + a : a;
}


u8
key_constraint_01(char* key, u32 key_len) {
    u32 b = ord(key[0]);
    u32 a = ord(key[1]);
    return mod(a + b, 0x24) == 0x0e;
}


u8
key_constraint_02(char* key, u32 key_len) {
    u32 b = ord(key[2]);
    u32 a = ord(key[3]);
    return mod(a + b, 0x24) == 0x18;
}


u8
key_constraint_03(char* key, u32 key_len) {
    u32 b = ord(key[2]);
    u32 a = ord(key[0]);
    return mod(b - a, 0x24) == 0x06;
}


u8
key_constraint_04(char* key, u32 key_len) {
    u32 c = ord(key[1]);
    u32 b = ord(key[3]);
    u32 a = ord(key[5]);
    return mod(c + b + a, 0x24) == 0x04;
}


u8
key_constraint_05(char* key, u32 key_len) {
    u32 c = ord(key[2]);
    u32 b = ord(key[4]);
    u32 a = ord(key[6]);
    return mod(c + b + a, 0x24) == 0x0d;
}


u8
key_constraint_06(char* key, u32 key_len) {
    u32 c = ord(key[3]);
    u32 b = ord(key[4]);
    u32 a = ord(key[5]);
    return mod(c + b + a, 0x24) == 0x16;
}


u8
key_constraint_07(char* key, u32 key_len) {
    u32 c = ord(key[6]);
    u32 b = ord(key[8]);
    u32 a = ord(key[10]);
    return mod(c + b + a, 0x24) == 0x1f;
}


u8
key_constraint_08(char* key, u32 key_len) {
    u32 c = ord(key[1]);
    u32 b = ord(key[4]);
    u32 a = ord(key[7]);
    return mod(c + b + a, 0x24) == 0x07;
}


u8
key_constraint_09(char* key, u32 key_len) {
    u32 c = ord(key[9]);
    u32 b = ord(key[12]);
    u32 a = ord(key[15]);
    return mod(c + b + a, 0x24) == 0x14;
}


u8
key_constraint_10(char* key, u32 key_len) {
    u32 c = ord(key[13]);
    u32 b = ord(key[14]);
    u32 a = ord(key[15]);
    return mod(c + b + a, 0x24) == 0x0c;
}


u8
key_constraint_11(char* key, u32 key_len) {
    u32 c = ord(key[8]);
    u32 b = ord(key[9]);
    u32 a = ord(key[10]);
    return mod(c + b + a, 0x24) == 0x1b;
}


u8
key_constraint_12(char* key, u32 key_len) {
    u32 c = ord(key[7]);
    u32 b = ord(key[12]);
    u32 a = ord(key[13]);
    return mod(c + b + a, 0x24) == 0x17;
}


u8
validate_key(char* key) {
    u32 key_len = strlen(key);

    if (!key_constraint_01(key, key_len)) {
        return 0;
    }

    if (!key_constraint_02(key, key_len)) {
        return 0;
    }

    if (!key_constraint_03(key, key_len)) {
        return 0;
    }

    if (!key_constraint_04(key, key_len)) {
        return 0;
    }

    if (!key_constraint_05(key, key_len)) {
        return 0;
    }

    if (!key_constraint_06(key, key_len)) {
        return 0;
    }

    if (!key_constraint_07(key, key_len)) {
        return 0;
    }

    if (!key_constraint_08(key, key_len)) {
        return 0;
    }

    if (!key_constraint_09(key, key_len)) {
        return 0;
    }

    if (!key_constraint_10(key, key_len)) {
        return 0;
    }

    if (!key_constraint_11(key, key_len)) {
        return 0;
    }

    if (!key_constraint_12(key, key_len)) {
        return 0;
    }

    return 1;
}


#if BRUTE

u8
validate_brute(char* key) {
    u32 key_len = strlen(key);

    if (!key_constraint_01(key, key_len)) {
        return 1;
    }

    if (!key_constraint_03(key, key_len)) {
        return 3;
    }

    if (!key_constraint_02(key, key_len)) {
        return 2;
    }

    if (!key_constraint_04(key, key_len)) {
        return 4;
    }

    if (!key_constraint_06(key, key_len)) {
        return 6;
    }

    if (!key_constraint_05(key, key_len)) {
        return 5;
    }

    if (!key_constraint_08(key, key_len)) {
        return 8;
    }

    if (!key_constraint_07(key, key_len)) {
        return 7;
    }

    if (!key_constraint_11(key, key_len)) {
        return 11;
    }

    if (!key_constraint_09(key, key_len)) {
        return 9;
    }

    if (!key_constraint_12(key, key_len)) {
        return 12;
    }

    if (!key_constraint_10(key, key_len)) {
        return 10;
    }

    return 0;
}


int
main(int argc, char* argv[]) {

    u8 constrait_chars[13][3] = {
        {255, 255, 255}, // 0
        {0, 1, 255}, // 1
        {255, 3, 255}, // 2
        {255, 2, 255}, // 3
        {255, 255, 5}, // 4
        {255, 255, 6}, // 5
        {255, 4, 255}, // 6
        {255, 8, 10}, // 7
        {255, 255, 7}, // 8
        {9, 12, 15}, // 9
        {255, 14, 15}, // 10
        {255, 9, 255}, // 11
        {255, 12, 13}, // 12
    };

    u8 progress[13][3] = {};

    char key[] = "00000000000X0000";
    static const char abc[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const u8 abclen = sizeof(abc) - 1;

    while (1) {
        u8 failed = validate_brute(key);

        if (failed == 0) {
            if (!validate_key(key)) {
                printf("** failed to validate: %s\n", key);
            }
            else {
                puts(key);
                return 0;
            }
        }
        else {
            #if 0
            if (failed > 5) {
                printf("trying %s: ", key);
                printf("failed on %d\n", failed);
            }
            #endif

            for (; failed >= 0; failed--) {
                if (failed == 0) {
                    puts("pooop");
                    return 1;
                }

                u8* ix = progress[failed];
                u8 change[3] = {};
                for (u32 i = 0; i < 3; i++) {
                    if (constrait_chars[failed][i] != 255) {
                        ix[i]++;
                        change[i] = 1;
                        if (ix[i] >= abclen) {
                            ix[i] = 0;
                            change[i] = 0;
                        }
                        else {
                            break;
                        }
                    }
                }

                for (u32 j = 0; j < 3; j++) {
                    if (constrait_chars[failed][j] == 255) continue;
                    for (u32 k = failed + 1; k < 13; k++) {
                        for (u32 i = 0; i < 3; i++) {
                            if (constrait_chars[k][j] == 255) continue;
                            if (constrait_chars[k][i] == constrait_chars[failed][j]) {
                                progress[k][i] = progress[failed][j];
                            }
                        }
                    }
                }

                for (u32 k = 1; k < 13; k++) {
                    for (u32 j = 0; j < 3; j++) {
                        if (constrait_chars[k][j] == 255) continue;
                        key[constrait_chars[k][j]] = abc[progress[k][j]];
                    }
                }

                if (!(change[0] || change[1] || change[2])) {
                    continue;
                }

                break;
            }
        }
    }

    puts("poop");
    return 1;
}

#else

int
main(int argc, char* argv[]) {
    if (argc < 2) {
        puts("Usage: ./activate <PRODUCT_KEY>");
        return -1;
    }

    char* key = argv[1];

    if (!check_valid_key(key)) {
        puts("Please Provide a VALID 16 byte Product Key.");
        return -1;
    }

    if (!validate_key(key)) {
        puts("INVALID Product Key.");
        return -1;
    }

    printf("Product Activated Successfully: ");
    puts("flag");
}

#endif
