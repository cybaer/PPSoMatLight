/*
 * PPSoMatLight.cpp
 *
 *  Created on: 01.02.2021
 *      Author: cybaer
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "avrlib/gpio.h"
#include "avrlib/base.h"


static const int PRESCALER = 1024;

int main(void)
{
  // Fast PWM (https://wolles-elektronikkiste.de/timer-und-pwm-teil-2-16-bit-timer1)
  //TCCR1A = (1<<COM1A1) + (1<<WGM11);  // Pin 9 (PB1)
  TCCR1A = (1<<COM1B1) + (1<<WGM11);
  TCCR1B = (1<<WGM13) + (1<<WGM12) + (1<<CS10) + (1<<CS12); // prescaler = 1024;
  ICR1 = 15623; //16000000 / PRESCALER / 1Hz - 1;
  //OCR1A = 1562;   //Pin9 (PB1)
  OCR1B = 1562;     // Pin10 (PB2)
  DDRB |= (1<<PB2); //set PBx as output
}

