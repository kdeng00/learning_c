/*
 *
 * This program briefly demonstrates usage of bitwise operators.
 *
 * Author: Kun Deng
 *
 */

#include <stdio.h>


int main()
{
    // 500 in binary is 111110100
    int n = 500;

    printf("n is %d\n", n);

    int n_temp = n;
    // Octal value 0177 is 127 in numerical form or 001111111 in binary
    int nb = 0177;
    // The result is 116 or 001110100 in binary
    // Bits are compared and if both aren't on then they get turned off
    // 500 - 111110100
    // 127 - 001111111
    // ---------------
    // 116 - 001110100
    n = n & nb;

    printf("%d & 0177 = %d\n", n_temp,  n);

    n = n_temp;
    // 63 in binary is 0111111
    int nc = 63;

    // The result is 511 or 111111111 in binary
    // Bits are compared and if any are on then the result gets turned on
    // 500 - 111110100
    //  63 -    111111
    // ---------------
    // 511 - 111111111
    n = n | nc;

    printf("%d | %d = %d\n", n_temp, nc, n);

    n = n_temp;
    // The result is 459 or 111111111 in binary
    // Bits are compared and if they differ then they are turned on. If
    // they are the same then they are turned off
    // 500 - 111110100
    //  63 -    111111
    // ---------------
    // 459 - 111001011
    n = n ^ nc;

    printf("%d ^ %d = %d\n", n_temp, nc, n);

    n = n_temp;
    // 6 is 110 in binary
    int nd = 6;

    // The result is 32000 or 111110100000000 in binary
    // The bits were shifted left by 6 positions and the vacancies
    // were populated with zeros
    //   500 -       111110100
    //     6 -             110
    // -----------------------
    // 32000 - 111110100000000
    n = n << nd;

    printf("%d << %d = %d\n", n_temp, nd, n);

    n = n_temp;
    // 3 is 11 in binary
    int ne = 3;

    // The result is 62 or 111110 in binary
    // The bits were shifted right by 3 positions
    //   500 -       111110100
    //     3 -              11
    // -----------------------
    //    62 -          111110
    n = n >> ne;

    printf("%d >> %d = %d\n", n_temp, ne, n);

    n = n_temp;
    // Octal value 025 is 21 in numerical form and 10101 in binary
    int nf = 025;

    // The result is 480 or 111110000 in binary
    // After the one's complement of octal value 025 was taken,
    // the one's complement of that was compared with 500, bit by
    // bit. When bits didn't match, they got turned off.
    //   500 -       111110100
    //   ~21 -            1010
    // -----------------------
    //   480 -       111110000
    n = n & ~nf;

    printf("%d & ~025 = %d\n", n_temp, n);

    return 0;
}
