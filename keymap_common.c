/*
Copyright 2016 Mathieu Bolla <mathieu.bolla@gmail.com>
*/

#include "keymap_common.h"

/* translates key to keycode */
uint8_t actionmap_key_to_action(uint8_t layer, keypos_t key)
{
    return pgm_read_word(&keymaps[(layer)][(key.row)][(key.col)]);
}

/* translates key to keycode */
uint8_t keymap_key_to_keycode(uint8_t layer, keypos_t key)
{
    return pgm_read_byte(&keymaps[(layer)][(key.row)][(key.col)]);
}

/* translates Fn keycode to action */
action_t keymap_fn_to_action(uint8_t keycode)
{
    return (action_t){ .code = pgm_read_word(&fn_actions[FN_INDEX(keycode)]) };
}

void bootloader() {
  clear_keyboard();
  print("\n\nJump to bootloader... ");
  _delay_ms(250);
  cli();
  UDCON = 1;
  USBCON = (1<<FRZCLK);  // disable USB
  UCSR1B = 0;
  _delay_ms(5);
  EIMSK = 0; PCICR = 0; SPCR = 0; ACSR = 0; EECR = 0; ADCSRA = 0;
  TIMSK0 = 0; TIMSK1 = 0; TIMSK2 = 0; TIMSK3 = 0; UCSR1B = 0; TWCR = 0;
  DDRA = 0; DDRB = 0; DDRC = 0; DDRD = 0; DDRE = 0; DDRF = 0;
  PORTA = 0; PORTB = 0; PORTC = 0; PORTD = 0; PORTE = 0; PORTF = 0;
  asm volatile("jmp 0x1FC00");
}
