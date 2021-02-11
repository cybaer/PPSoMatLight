#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

VERSION        = 0.1
MCU_NAME       = 328
F_CPU          = 16000000
TARGET         = PPSoMatLight
PACKAGES       = avrlib avrlib/devices ./

SYSEX_FLAGS    = --page_size=64 --device_id=3

EXTRA_DEFINES  = -DDISABLE_DEFAULT_UART_RX_ISR -DUSE_SH_SEQUENCER

LFUSE          = ff
HFUSE          = d1
EFUSE          = ff
LOCK           = ff

include avrlib/makefile.mk

include $(DEP_FILE)


bake_all: build/PPSoMatLight.hex
#	make -f bootloader/makefile
#		$(AVRDUDE) $(AVRDUDE_COM_OPTS) $(AVRDUDE_ISP_OPTS) -B 10 -u -e \
			-U efuse:w:0x$(EFUSE):m \
			-U hfuse:w:0x$(HFUSE):m \
			-U lfuse:w:0x$(LFUSE):m
		$(AVRDUDE) $(AVRDUDE_COM_OPTS) $(AVRDUDE_ISP_OPTS) -B 1 \
			-U flash:w:build/derTempomat.hex:i \
#		$(AVRDUDE) $(AVRDUDE_COM_OPTS) $(AVRDUDE_ISP_OPTS) -B 1 \
#			-U lock:w:0x$(LOCK):m

