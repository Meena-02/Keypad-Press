# Keypad Based projects
Items used:
1. 4X4 Matrix keypad
2. STM32F407G-DISC1 Discovery board
3. Jumper wires

![keypad (1)](https://github.com/Meena-02/Keypad-Press/assets/91966206/10702fc7-091d-4e88-bbb2-73784ab766a9)

The above picture shows the connections between stm32 and keypad.
The red lines are connected to pins:
1. PD0
2. PD1
3. PD2
4. PD3

The blue lines are connected to pins:
1. PD8
2. PD9
3. PD10
4. PD11


## 012 ReadKeypad
![keypad_explanation](https://github.com/Meena-02/Keypad-Press/assets/91966206/16ba630a-b0f0-4db3-a713-d7374dbd6c26)

A 4x4 matrix keyboard has 16 push buttons connected to rows and column lines. The row lines are set to output mode while the column lines are set to input mode with a pull-up resistor. So by default, all the column lines will be high. In this project, all the rows are set to high initially. Then row 1 (PD0) is set to low and all the columns are scanned to check if the button is pressed. If the button is pressed, then that particular column will be low. So when that row and that column reads low value, the number pressed can be identified.

## 013 KeypadPassword

KeypadPassword project is an extension of ReadKeypad project. In this project, a default password is set.
```
	char password[5] = "1234";
```

The user is then asked to enter their password. The password entered by the user is checked against the default password. If it is correct, then it displays "Correct password" else it displays "You have entered incorrect password. Please try again.". 

## Setting up header file
```
typedef struct {
	uint32_t gpioa_en: 1;
	uint32_t gpiob_en: 1;
	uint32_t gpioc_en: 1;
	uint32_t gpiod_en: 1;
	uint32_t gpioe_en: 1;
	uint32_t gpiof_en: 1;
	uint32_t gpiog_en: 1;
	uint32_t gpioh_en: 1;
	uint32_t gpioi_en: 1;
	uint32_t reserved_1: 3;
	uint32_t crc_en: 1;
	uint32_t reserved_2: 5;
	uint32_t bkpsram_en: 1;
	uint32_t reserved_3: 1;
	uint32_t ccmdataram_en: 1;
	uint32_t dma1_en: 1;
	uint32_t dma2_en: 1;
	uint32_t reserved_4: 2;
	uint32_t ethmac_en: 1;
	uint32_t ethmactx_en: 1;
	uint32_t ethmacrx_en: 1;
	uint32_t ethmacptp_en: 1;
	uint32_t otghs_en: 1;
	uint32_t otghsulpi_en: 1;
	uint32_t reserved_5: 1;
} RCC_AHB1ENR_t;
```


