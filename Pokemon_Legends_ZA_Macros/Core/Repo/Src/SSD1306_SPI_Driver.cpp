/*
 * SSD1306_SPI_Driver.cpp
 *
 *  Created on: Oct 28, 2024
 *      Author: LogMa
 */


#include "main.h"
#include <cstdint>
//#include "stm32l4xx_hal.h"
//#include "stm32l4xx_ll_spi.h"

//custom includes
#include "SSD1306_SPI_Driver.h"
#include "characters.h"


OLED::OLED(queue* qM, queue* qSM){ // @suppress("Class members should be properly initialized")
	qMacro = qM;
	qSetMacro = qSM;
	SPI_CS_count = 0;
	SPI_RST_Count = 0;

	Macro.CurrentMacro = ZONE1;
	Macro.CurrentState = START;

	MacroDisplayed.length = strlen(macroList[Macro.CurrentMacro]);
	memcpy(MacroDisplayed.data_buf, macroList[Macro.CurrentMacro], MacroDisplayed.length);
	MacroDisplayed.start_col = 12;
	MacroDisplayed.end_col = MacroDisplayed.start_col + 4;
	MacroDisplayed.page = 2;


	StateDisplayed.length = strlen(currentState[Macro.CurrentState]);
	memcpy(StateDisplayed.data_buf, currentState[Macro.CurrentState], StateDisplayed.length);
	StateDisplayed.start_col = 39;
	StateDisplayed.end_col = StateDisplayed.start_col + 4;
	StateDisplayed.page = 4;

	SSD1306_init();
	set_OLED();

}



void OLED::set_OLED()
{
	clear_display();
	PrintData title;
	title.length = TITLE_LENGTH;

	memcpy(title.data_buf, legendsZATitle, title.length);
//	memcpy(title.data_buf, scarletVioletTitle, title.length);

	title.start_col = 15;
	title.end_col = title.start_col + 4;
	title.page = 0;
	print(title);

	print(MacroDisplayed);

	print(StateDisplayed);

	return;
}

void OLED::print(PrintData text)
{
	for (uint8_t i = 0; i < text.length; i++)
	{
		uint8_t index = text.data_buf[i] - 0x20;
		set_column_address(text.start_col + (i * CHARACTER_OFFSET), text.end_col + (i * CHARACTER_OFFSET));
		set_page_address(text.page,text.page);
		send_data(ssd1306xled_font5x7[index]);
	}
	return;
}

void OLED::clear_display_macro(uint8_t page)
{

	set_column_address(0,127);
	set_page_address(page,page);
	uint8_t row_clear[128] = {0};
	SET(PA,3);

	for(uint32_t i = 0; i < 128; i++)
	{
		LL_SPI_TransmitData8(SPI1, row_clear[i]);
		for(uint32_t i = 0; i < 0xFFFFFFFF ; i++)
				if(LL_SPI_IsActiveFlag_TXE(SPI1))
					break;
	}
	return;
}

void OLED::Update()
{
	void* data_ptr;
	StateChange* value_ptr;
	StateChange PreviousMacro;
	PreviousMacro.CurrentMacro = Macro.CurrentMacro;
	PreviousMacro.CurrentState = Macro.CurrentState;

	if (qMacro->dequeue(&data_ptr) == false)
		return;

	value_ptr = (StateChange*)data_ptr;
	Macro = *value_ptr;

	if (Macro.CurrentMacro != PreviousMacro.CurrentMacro)
	{
		clear_display_macro(2);

		PreviousMacro.CurrentMacro = Macro.CurrentMacro;
		switch(Macro.CurrentMacro)
		{
			case ZONE1:
			{
				MacroDisplayed.length = strlen(macroList[ZONE1]);
				memcpy(MacroDisplayed.data_buf, macroList[ZONE1], MacroDisplayed.length);
				MacroDisplayed.start_col = 12;
				MacroDisplayed.end_col = MacroDisplayed.start_col + 4;
				print(MacroDisplayed);
				break;
			}

			case ZONE2:
			{
				MacroDisplayed.length = strlen(macroList[ZONE2]);
				memcpy(MacroDisplayed.data_buf, macroList[ZONE2], MacroDisplayed.length);
				MacroDisplayed.start_col = 12;
				MacroDisplayed.end_col = MacroDisplayed.start_col + 4;
				print(MacroDisplayed);
				break;
			}

			case ZONE3:
			{
				MacroDisplayed.length = strlen(macroList[ZONE3]);
				memcpy(MacroDisplayed.data_buf, macroList[ZONE3], MacroDisplayed.length);
				MacroDisplayed.start_col = 12;
				MacroDisplayed.end_col = MacroDisplayed.start_col + 4;
				print(MacroDisplayed);
				break;
			}

			case ZONE4:
			{
				MacroDisplayed.length = strlen(macroList[ZONE4]);
				memcpy(MacroDisplayed.data_buf, macroList[ZONE4], MacroDisplayed.length);
				MacroDisplayed.start_col = 12;
				MacroDisplayed.end_col = MacroDisplayed.start_col + 4;
				print(MacroDisplayed);
				break;
			}

			case ZONE5:
			{
				MacroDisplayed.length = strlen(macroList[ZONE5]);
				memcpy(MacroDisplayed.data_buf, macroList[ZONE5], MacroDisplayed.length);
				MacroDisplayed.start_col = 12;
				MacroDisplayed.end_col = MacroDisplayed.start_col + 4;
				print(MacroDisplayed);
				break;
			}

			case ZONE6:
			{
				MacroDisplayed.length = strlen(macroList[ZONE6]);
				memcpy(MacroDisplayed.data_buf, macroList[ZONE6], MacroDisplayed.length);
				MacroDisplayed.start_col = 12;
				MacroDisplayed.end_col = MacroDisplayed.start_col + 4;
				print(MacroDisplayed);
				break;
			}

			case ZONE7:
			{
				MacroDisplayed.length = strlen(macroList[ZONE7]);
				memcpy(MacroDisplayed.data_buf, macroList[ZONE7], MacroDisplayed.length);
				MacroDisplayed.start_col = 12;
				MacroDisplayed.end_col = MacroDisplayed.start_col + 4;
				print(MacroDisplayed);
				break;
			}

			case ZONE8:
			{
				MacroDisplayed.length = strlen(macroList[ZONE8]);
				memcpy(MacroDisplayed.data_buf, macroList[ZONE8], MacroDisplayed.length);
				MacroDisplayed.start_col = 12;
				MacroDisplayed.end_col = MacroDisplayed.start_col + 4;
				print(MacroDisplayed);
				break;
			}

			case ZONE9:
			{
				MacroDisplayed.length = strlen(macroList[ZONE9]);
				memcpy(MacroDisplayed.data_buf, macroList[ZONE9], MacroDisplayed.length);
				MacroDisplayed.start_col = 12;
				MacroDisplayed.end_col = MacroDisplayed.start_col + 4;
				print(MacroDisplayed);
				break;
			}

			case ZONE10:
			{
				MacroDisplayed.length = strlen(macroList[ZONE10]);
				memcpy(MacroDisplayed.data_buf, macroList[ZONE10], MacroDisplayed.length);
				MacroDisplayed.start_col = 12;
				MacroDisplayed.end_col = MacroDisplayed.start_col + 4;
				print(MacroDisplayed);
				break;
			}

			case ZONE11:
			{
				MacroDisplayed.length = strlen(macroList[ZONE11]);
				memcpy(MacroDisplayed.data_buf, macroList[ZONE11], MacroDisplayed.length);
				MacroDisplayed.start_col = 12;
				MacroDisplayed.end_col = MacroDisplayed.start_col + 4;
				print(MacroDisplayed);
				break;
			}

			case ZONE12:
			{
				MacroDisplayed.length = strlen(macroList[ZONE12]);
				memcpy(MacroDisplayed.data_buf, macroList[ZONE12], MacroDisplayed.length);
				MacroDisplayed.start_col = 12;
				MacroDisplayed.end_col = MacroDisplayed.start_col + 4;
				print(MacroDisplayed);
				break;
			}

			case ZONE13:
			{
				MacroDisplayed.length = strlen(macroList[ZONE13]);
				memcpy(MacroDisplayed.data_buf, macroList[ZONE13], MacroDisplayed.length);
				MacroDisplayed.start_col = 12;
				MacroDisplayed.end_col = MacroDisplayed.start_col + 4;
				print(MacroDisplayed);
				break;
			}

			case ZONE14:
			{
				MacroDisplayed.length = strlen(macroList[ZONE14]);
				memcpy(MacroDisplayed.data_buf, macroList[ZONE14], MacroDisplayed.length);
				MacroDisplayed.start_col = 12;
				MacroDisplayed.end_col = MacroDisplayed.start_col + 4;
				print(MacroDisplayed);
				break;
			}

			case ZONE15:
			{
				MacroDisplayed.length = strlen(macroList[ZONE15]);
				memcpy(MacroDisplayed.data_buf, macroList[ZONE15], MacroDisplayed.length);
				MacroDisplayed.start_col = 12;
				MacroDisplayed.end_col = MacroDisplayed.start_col + 4;
				print(MacroDisplayed);
				break;
			}

			case ZONE16:
			{
				MacroDisplayed.length = strlen(macroList[ZONE16]);
				memcpy(MacroDisplayed.data_buf, macroList[ZONE16], MacroDisplayed.length);
				MacroDisplayed.start_col = 12;
				MacroDisplayed.end_col = MacroDisplayed.start_col + 4;
				print(MacroDisplayed);
				break;
			}

			case ZONE17:
			{
				MacroDisplayed.length = strlen(macroList[ZONE17]);
				memcpy(MacroDisplayed.data_buf, macroList[ZONE17], MacroDisplayed.length);
				MacroDisplayed.start_col = 12;
				MacroDisplayed.end_col = MacroDisplayed.start_col + 4;
				print(MacroDisplayed);
				break;
			}

			case ZONE18:
			{
				MacroDisplayed.length = strlen(macroList[ZONE18]);
				memcpy(MacroDisplayed.data_buf, macroList[ZONE18], MacroDisplayed.length);
				MacroDisplayed.start_col = 12;
				MacroDisplayed.end_col = MacroDisplayed.start_col + 4;
				print(MacroDisplayed);
				break;
			}

			case ZONE19:
			{
				MacroDisplayed.length = strlen(macroList[ZONE19]);
				memcpy(MacroDisplayed.data_buf, macroList[ZONE19], MacroDisplayed.length);
				MacroDisplayed.start_col = 12;
				MacroDisplayed.end_col = MacroDisplayed.start_col + 4;
				print(MacroDisplayed);
				break;
			}

			case ZONE20:
			{
				MacroDisplayed.length = strlen(macroList[ZONE20]);
				memcpy(MacroDisplayed.data_buf, macroList[ZONE20], MacroDisplayed.length);
				MacroDisplayed.start_col = 12;
				MacroDisplayed.end_col = MacroDisplayed.start_col + 4;
				print(MacroDisplayed);
				break;
			}

			case BENCHRESET:
			{
				MacroDisplayed.length = strlen(macroList[BENCHRESET]);
				memcpy(MacroDisplayed.data_buf, macroList[BENCHRESET], MacroDisplayed.length);
				MacroDisplayed.start_col = 12;
				MacroDisplayed.end_col = MacroDisplayed.start_col + 4;
				print(MacroDisplayed);
				break;
			}

			case AUTOBATTE:
			{
				MacroDisplayed.length = strlen(macroList[AUTOBATTE]);
				memcpy(MacroDisplayed.data_buf, macroList[AUTOBATTE], MacroDisplayed.length);
				MacroDisplayed.start_col = 12;
				MacroDisplayed.end_col = MacroDisplayed.start_col + 4;
				print(MacroDisplayed);
				break;
			}

			case TURBOA:
			{
				MacroDisplayed.length = strlen(macroList[TURBOA]);
				memcpy(MacroDisplayed.data_buf, macroList[TURBOA], MacroDisplayed.length);
				MacroDisplayed.start_col = 34;
				MacroDisplayed.end_col = MacroDisplayed.start_col + 4;
				print(MacroDisplayed);
				break;
			}

			default:
			{
				break;
			}
		}
	}

//	if (Macro.CurrentState != PreviousMacro.CurrentState)
//	{
		clear_display_macro(4);
//		PreviousMacro.CurrentState = Macro.CurrentState;

		switch(Macro.CurrentState)
		{
			case START:
			{
				StateDisplayed.length = strlen(currentState[START]);
				memcpy(StateDisplayed.data_buf, currentState[START], StateDisplayed.length);
				StateDisplayed.start_col = 39;
				StateDisplayed.end_col = StateDisplayed.start_col + 4;
				StateDisplayed.page = 4;
				print(StateDisplayed);
				break;
			}

			case RUNNING:
			{
				StateDisplayed.length = strlen(currentState[RUNNING]);
				memcpy(StateDisplayed.data_buf, currentState[RUNNING], StateDisplayed.length);
				StateDisplayed.start_col = 39;
				StateDisplayed.end_col = StateDisplayed.start_col + 4;
				StateDisplayed.page = 4;
				print(StateDisplayed);
				break;
			}

			default:
			{
				StateDisplayed.length = strlen(currentState[START]);
				memcpy(StateDisplayed.data_buf, currentState[START], StateDisplayed.length);
				StateDisplayed.start_col = 39;
				StateDisplayed.end_col = StateDisplayed.start_col + 4;
				StateDisplayed.page = 4;
				print(StateDisplayed);
				break;
			}
		}
//	}

	qSetMacro->enqueue((void*)&Macro);



	return;
}


void OLED::send_command(uint8_t command)
{
	CLEAR(PA,3);
	LL_SPI_TransmitData8(SPI1, command);
	for(uint32_t i = 0; i < 0xFFFFFFFF ; i++)
			if(LL_SPI_IsActiveFlag_TXE(SPI1))
				break;
	return;
}

void OLED::send_data(const uint8_t* data)
{
	SET(PA,3);

	for(uint32_t i = 0; i < CHARACTER_SIZE; i++)
	{
		LL_SPI_TransmitData8(SPI1, data[i]);
		for(uint32_t i = 0; i < 0xFFFFFFFF ; i++)
				if(LL_SPI_IsActiveFlag_TXE(SPI1))
					break;
	}
	return;

}

void OLED::send_clear(const uint8_t* data)
{
	SET(PA,3);

	for(uint32_t i = 0; i < 1024; i++)
	{
		LL_SPI_TransmitData8(SPI1, data[i]);
		for(uint32_t i = 0; i < 0xFFFFFFFF ; i++)
				if(LL_SPI_IsActiveFlag_TXE(SPI1))
					break;
	}
	return;

}


void OLED::SSD1306_init()
{
	LL_SPI_Enable(SPI1);
	if(SPI_RST_Count == 0)
	{
		SET(PA,8);
		SPI_RST_Count = 1;
	}

	if(SPI_CS_count == 0)
	{
		CLEAR(PA,6);
		SPI_CS_count = 1;
	}

	assert(SPI_CS_count == 1);

    send_command(SSD1306_COMMAND_DISPLAY_OFF); //set display off

    send_command(SSD1306_COMMAND_ADDRESSING_MODE); //Set addressing mode
    send_command(0x00); //horizontal addressing mode

    send_command(SSD1306_COMMAND_SET_OFFSET); //Display offset
    send_command(0x00); //no offset

    send_command(SSD1306_COMMAND_START_LINE); //set display start line

    send_command(SSD1306_COMMAND_CONTRAST_CONTROL);// set contrast
    send_command(0xFF);//max contrast

    send_command(SSD1306_COMMAND_SEG_INVERSE);//set segment remap, col address SEG0 = 127
    send_command(0xA4);

    send_command(SSD1306_COMMAND_SET_MUX); //set MUX Ratio
    send_command(0x3F);

    send_command(SSD1306_COMMAND_COM_SCAN_INVERSE); //set com scan mode, C8 = from COM[N - 1] to COM[0]

    send_command(SSD1306_COMMAND_SET_COM_Hardware);  //set COM pins hardware configuration
    send_command(0x12);

    send_command(0xA4); //set output with RAM contents TODO make a define

    send_command(SSD1306_COMMAND_SET_PRECHARGE_PERIOD); //set precharge value
    send_command(0x22);

    send_command(SSD1306_COMMAND_CLOCK_DIIVDER); //Set frequency (Tentatively)
    send_command(0x80);

    send_command(SSD1306_COMMAND_VCOMH_DSEL_LEVEL);//set vcomh
    send_command(0x20); //0x20,0.77xVcc

    send_command(SSD1306_COMMAND_SET_DC_DC_ENABLE);//set DC-DC enable
    send_command(0x14);

    send_command(SSD1306_COMMAND_DISPLAY_ON); //set display on
    clear_display();
    return;
}

void OLED::set_column_address(uint8_t begin, uint8_t end)
{
    //Horizontal addressing mode (ONE I'LL USE)
    send_command(SSD1306_SET_COLUMN_ADDR); //set Column address (make a function for this)
    send_command(begin); //column address/position start
    send_command(end); //column address/position end
    return;
}

void OLED::set_page_address(uint8_t begin, uint8_t end)
{
    //Horizontal addressing mode (ONE I'LL USE)
    send_command(SSD1306_SET_PAGE_ADDR); //set Column address (make a function for this)
    send_command(begin); //column address/position start
    send_command(end); //column address/position end
    return;
}

void OLED::clear_display()
{
	set_column_address(0,127);
	set_page_address(0,7);

	uint8_t clear_display[] =
	{
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	};

	send_clear(clear_display);
//	for(int32_t i = 0; i < 8; i++)
//	{
//		//For one page
//		for(int32_t j = 0; j < 8; j++)
//		{
//			send_data(clear[j]);
//		}
//
//	}
	return;
}
