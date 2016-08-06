/*
Copyright 2016 Mathieu Bolla <mathieu.bolla@gmail.com>
*/

/*
 * scan matrix
 */
#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>
#include "print.h"
#include "debug.h"
#include "util.h"
#include "matrix.h"


#ifndef DEBOUNCE
#   define DEBOUNCE	5
#endif
static uint8_t debouncing = DEBOUNCE;

/* matrix state(1:on, 0:off) */
static matrix_row_t matrix[MATRIX_ROWS];
static matrix_row_t matrix_debouncing[MATRIX_ROWS];

static matrix_row_t read_cols(void);
static void init_cols(void);
static void unselect_rows(void);
static void select_row(uint8_t row);


inline
uint8_t matrix_rows(void)
{
    return MATRIX_ROWS;
}

inline
uint8_t matrix_cols(void)
{
    return MATRIX_COLS;
}

void matrix_init(void)
{
    // initialize row and col
    unselect_rows();
    init_cols();

    // initialize matrix state: all keys off
    for (uint8_t i=0; i < MATRIX_ROWS; i++) {
        matrix[i] = 0;
        matrix_debouncing[i] = 0;
    }
}

uint8_t matrix_scan(void)
{
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        select_row(i);
        _delay_us(50);  // without this wait read unstable value.
        matrix_row_t cols = read_cols();
        if (matrix_debouncing[i] != cols) {
            matrix_debouncing[i] = cols;
            if (debouncing) {
                debug("bounce!: "); debug_hex(debouncing); debug("\n");
            }
            debouncing = DEBOUNCE;
        }
        unselect_rows();
    }

    if (debouncing) {
        if (--debouncing) {
            _delay_ms(1);
        } else {
            for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
                matrix[i] = matrix_debouncing[i];
            }
        }
    }

    return 1;
}

bool matrix_is_modified(void)
{
    if (debouncing) return false;
    return true;
}

inline
bool matrix_is_on(uint8_t row, uint8_t col)
{
    return (matrix[row] & ((matrix_row_t)1<<col));
}

inline
matrix_row_t matrix_get_row(uint8_t row)
{
    return matrix[row];
}

void matrix_print(void)
{
    print("\nr/c 0123456789ABCDEF\n");
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        phex(row); print(": ");
        pbin_reverse16(matrix_get_row(row));
        print("\n");
    }
}

uint8_t matrix_key_count(void)
{
    uint8_t count = 0;
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        count += bitpop16(matrix[i]);
    }
    return count;
}

/* Column pin configuration
 * col: 0   1   2   3   4   5   6   7   8   9   10  11  12  13
 * pin: C0  C1  C2  C3  C4  C5  C6  C7  F0  F1  F2  F3  F4  F5
 */
static void  init_cols(void)
{
    DDRB = 255;
    PORTB = 255;

    DDRF = DDRC = 0;
    PORTF = PORTC = 255;
}

static matrix_row_t read_cols(void)
{
    return (PINC&(1<<0) ? 0 : (1<<0))  | // Column 0 on PIN-C-0
           (PINC&(1<<1) ? 0 : (1<<1))  |
           (PINC&(1<<2) ? 0 : (1<<2))  |
           (PINC&(1<<3) ? 0 : (1<<3))  |
           (PINC&(1<<4) ? 0 : (1<<4))  |
           (PINC&(1<<5) ? 0 : (1<<5))  |
           (PINC&(1<<6) ? 0 : (1<<6))  |
           (PINC&(1<<7) ? 0 : (1<<7))  | // Column 7 on PIN-C-7
           (PINF&(1<<0) ? 0 : (1<<8))  | // Column 8 on PIN-F-0
           (PINF&(1<<1) ? 0 : (1<<9))  |
           (PINF&(1<<2) ? 0 : (1<<10)) |// Column 10 on PIN-F-2
           (PINF&(1<<3) ? 0 : (1<<11)) |
           (PINF&(1<<4) ? 0 : (1<<12)) | // For full matrix, add 3 columns
           (PINF&(1<<5) ? 0 : (1<<13));
}

/* Row pin configuration
 * row: 0   1   2   3
 * pin: B6  B5  B4  B3
 */
static void unselect_rows(void)
{
  PORTB = 255;
}

int rows[MATRIX_ROWS] = {6, 5, 4, 3};

static void select_row(uint8_t row)
{
  PORTB = ~(1 << rows[row]);
}
