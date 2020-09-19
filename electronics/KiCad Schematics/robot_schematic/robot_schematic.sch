EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Device:Battery BT1
U 1 1 5F666CC3
P 1850 2250
F 0 "BT1" H 1958 2296 50  0000 L CNN
F 1 "Battery" H 1958 2205 50  0000 L CNN
F 2 "" V 1850 2310 50  0001 C CNN
F 3 "~" V 1850 2310 50  0001 C CNN
	1    1850 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	1850 2050 1850 1900
Wire Wire Line
	1850 2450 1850 2650
Wire Wire Line
	3050 2000 3300 2000
Wire Wire Line
	3050 2000 3050 2100
Wire Wire Line
	3050 2100 3300 2100
Wire Wire Line
	3050 2400 3300 2400
Wire Wire Line
	3050 2400 3050 2300
Wire Wire Line
	3050 2300 3300 2300
$Comp
L power:GND #PWR08
U 1 1 5F671208
P 4350 2400
F 0 "#PWR08" H 4350 2150 50  0001 C CNN
F 1 "GND" H 4355 2227 50  0000 C CNN
F 2 "" H 4350 2400 50  0001 C CNN
F 3 "" H 4350 2400 50  0001 C CNN
	1    4350 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	4350 2300 4100 2300
Wire Wire Line
	4350 2300 4350 2400
Wire Wire Line
	4350 2400 4100 2400
Connection ~ 4350 2400
Wire Wire Line
	4350 2100 4100 2100
Wire Wire Line
	4350 2100 4350 2000
Wire Wire Line
	4350 2000 4100 2000
$Comp
L power:+5V #PWR07
U 1 1 5F6786C9
P 4350 2000
F 0 "#PWR07" H 4350 1850 50  0001 C CNN
F 1 "+5V" H 4365 2173 50  0000 C CNN
F 2 "" H 4350 2000 50  0001 C CNN
F 3 "" H 4350 2000 50  0001 C CNN
	1    4350 2000
	1    0    0    -1  
$EndComp
Connection ~ 4350 2000
$Comp
L power:+BATT #PWR03
U 1 1 5F67A480
P 1850 1900
F 0 "#PWR03" H 1850 1750 50  0001 C CNN
F 1 "+BATT" H 1865 2073 50  0000 C CNN
F 2 "" H 1850 1900 50  0001 C CNN
F 3 "" H 1850 1900 50  0001 C CNN
	1    1850 1900
	1    0    0    -1  
$EndComp
$Comp
L power:-BATT #PWR04
U 1 1 5F67A93C
P 1850 2650
F 0 "#PWR04" H 1850 2500 50  0001 C CNN
F 1 "-BATT" H 1865 2823 50  0000 C CNN
F 2 "" H 1850 2650 50  0001 C CNN
F 3 "" H 1850 2650 50  0001 C CNN
	1    1850 2650
	-1   0    0    1   
$EndComp
$Comp
L power:-BATT #PWR02
U 1 1 5F67B1D2
P 3050 2400
F 0 "#PWR02" H 3050 2250 50  0001 C CNN
F 1 "-BATT" H 3065 2573 50  0000 C CNN
F 2 "" H 3050 2400 50  0001 C CNN
F 3 "" H 3050 2400 50  0001 C CNN
	1    3050 2400
	-1   0    0    1   
$EndComp
Connection ~ 3050 2400
$Comp
L power:+BATT #PWR01
U 1 1 5F67B38D
P 3050 2000
F 0 "#PWR01" H 3050 1850 50  0001 C CNN
F 1 "+BATT" H 3065 2173 50  0000 C CNN
F 2 "" H 3050 2000 50  0001 C CNN
F 3 "" H 3050 2000 50  0001 C CNN
	1    3050 2000
	1    0    0    -1  
$EndComp
Connection ~ 3050 2000
$Comp
L power:+BATT #PWR011
U 1 1 5F683142
P 7600 4800
F 0 "#PWR011" H 7600 4650 50  0001 C CNN
F 1 "+BATT" H 7615 4973 50  0000 C CNN
F 2 "" H 7600 4800 50  0001 C CNN
F 3 "" H 7600 4800 50  0001 C CNN
	1    7600 4800
	1    0    0    -1  
$EndComp
$Comp
L power:-BATT #PWR012
U 1 1 5F68410A
P 7600 5950
F 0 "#PWR012" H 7600 5800 50  0001 C CNN
F 1 "-BATT" H 7615 6123 50  0000 C CNN
F 2 "" H 7600 5950 50  0001 C CNN
F 3 "" H 7600 5950 50  0001 C CNN
	1    7600 5950
	-1   0    0    1   
$EndComp
Wire Wire Line
	7600 4800 7600 4900
Wire Wire Line
	7600 5850 7600 5950
$Comp
L Motor:Motor_DC M1
U 1 1 5F685987
P 9000 5000
F 0 "M1" H 9158 4996 50  0000 L CNN
F 1 "Motor_DC" H 9158 4905 50  0000 L CNN
F 2 "" H 9000 4910 50  0001 C CNN
F 3 "~" H 9000 4910 50  0001 C CNN
	1    9000 5000
	1    0    0    -1  
$EndComp
$Comp
L Motor:Motor_DC M2
U 1 1 5F686429
P 9000 5700
F 0 "M2" H 9158 5696 50  0000 L CNN
F 1 "Motor_DC" H 9158 5605 50  0000 L CNN
F 2 "" H 9000 5610 50  0001 C CNN
F 3 "~" H 9000 5610 50  0001 C CNN
	1    9000 5700
	1    0    0    -1  
$EndComp
Wire Wire Line
	9000 5300 9000 5350
Wire Wire Line
	9000 5350 7950 5350
Wire Wire Line
	8550 5250 8550 4650
Wire Wire Line
	8550 4650 9000 4650
Wire Wire Line
	9000 4650 9000 4800
Wire Wire Line
	7950 5250 8550 5250
Wire Wire Line
	9000 5500 9000 5450
Wire Wire Line
	9000 5450 7950 5450
Wire Wire Line
	7950 5550 8550 5550
Wire Wire Line
	8550 5550 8550 6150
Wire Wire Line
	8550 6150 9000 6150
Wire Wire Line
	9000 6150 9000 6000
Wire Wire Line
	7250 5250 7000 5250
Wire Wire Line
	7250 5350 7000 5350
Wire Wire Line
	7250 5450 7000 5450
Wire Wire Line
	7250 5550 7000 5550
Text Label 7000 5250 0    50   ~ 0
M1_A
Text Label 7000 5350 0    50   ~ 0
M1_B
Text Label 7000 5450 0    50   ~ 0
M2_A
Text Label 7000 5550 0    50   ~ 0
M2_B
$Comp
L ComponentsLibrary:MP1584EN U2
U 1 1 5F6BAB36
P 3700 2150
F 0 "U2" H 3700 2525 50  0000 C CNN
F 1 "MP1584EN" H 3700 2434 50  0000 C CNN
F 2 "" H 3700 2150 50  0001 C CNN
F 3 "" H 3700 2150 50  0001 C CNN
	1    3700 2150
	1    0    0    -1  
$EndComp
$Comp
L ComponentsLibrary:MX1508 U3
U 1 1 5F6BC73B
P 7600 5450
F 0 "U3" H 7800 5950 50  0000 C CNN
F 1 "MX1508" H 7800 5100 50  0000 C CNN
F 2 "" H 7600 5450 50  0001 C CNN
F 3 "" H 7600 5450 50  0001 C CNN
	1    7600 5450
	1    0    0    -1  
$EndComp
$Comp
L ComponentsLibrary:ESP32-DEVKITC-32D U4
U 1 1 5F6D6257
P 8200 2200
F 0 "U4" H 8200 3367 50  0000 C CNN
F 1 "ESP32-DEVKITC-32D" H 8200 3276 50  0000 C CNN
F 2 "MODULE_ESP32-DEVKITC-32D" H 8200 2200 50  0001 L BNN
F 3 "None" H 8200 2200 50  0001 L BNN
F 4 "None" H 8200 2200 50  0001 L BNN "Field4"
F 5 "ESP32-DEVKITC-32D" H 8200 2200 50  0001 L BNN "Field5"
F 6 "Unavailable" H 8200 2200 50  0001 L BNN "Field6"
F 7 "Espressif Systems" H 8200 2200 50  0001 L BNN "Field7"
F 8 "Eval Board For Esp-Wroom-32" H 8200 2200 50  0001 L BNN "Field8"
	1    8200 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	7250 3050 7250 3100
Wire Wire Line
	7250 3100 7400 3100
$Comp
L power:GND #PWR013
U 1 1 5F6DF1F4
P 9200 1300
F 0 "#PWR013" H 9200 1050 50  0001 C CNN
F 1 "GND" H 9205 1127 50  0000 C CNN
F 2 "" H 9200 1300 50  0001 C CNN
F 3 "" H 9200 1300 50  0001 C CNN
	1    9200 1300
	-1   0    0    1   
$EndComp
Wire Wire Line
	9000 1300 9200 1300
NoConn ~ 9000 2600
NoConn ~ 9000 2500
NoConn ~ 9000 2700
NoConn ~ 9000 2200
NoConn ~ 7400 2500
NoConn ~ 9000 2800
Wire Wire Line
	9000 1800 9300 1800
Wire Wire Line
	9000 1500 9300 1500
Text Label 9300 1800 2    50   ~ 0
SDA
Text Label 9300 1500 2    50   ~ 0
SCL
NoConn ~ 9000 3000
NoConn ~ 9000 2900
NoConn ~ 7400 2900
NoConn ~ 7400 2800
NoConn ~ 7400 3000
$Comp
L power:+5V #PWR010
U 1 1 5F700422
P 7250 3050
F 0 "#PWR010" H 7250 2900 50  0001 C CNN
F 1 "+5V" H 7265 3223 50  0000 C CNN
F 2 "" H 7250 3050 50  0001 C CNN
F 3 "" H 7250 3050 50  0001 C CNN
	1    7250 3050
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR09
U 1 1 5F7071D4
P 7200 1300
F 0 "#PWR09" H 7200 1150 50  0001 C CNN
F 1 "+3V3" H 7215 1473 50  0000 C CNN
F 2 "" H 7200 1300 50  0001 C CNN
F 3 "" H 7200 1300 50  0001 C CNN
	1    7200 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	7200 1300 7400 1300
Wire Wire Line
	9000 2000 9300 2000
Wire Wire Line
	9000 2100 9300 2100
Wire Wire Line
	9000 2300 9300 2300
Wire Wire Line
	9000 2400 9300 2400
Text Label 9300 2400 2    50   ~ 0
M1_A
Text Label 9300 2300 2    50   ~ 0
M1_B
Text Label 9300 2100 2    50   ~ 0
M2_A
Text Label 9300 2000 2    50   ~ 0
M2_B
$Comp
L ComponentsLibrary:TCS-34725 U?
U 1 1 5F6BE0D1
P 2900 5100
F 0 "U?" H 2900 5265 50  0000 C CNN
F 1 "TCS-34725" H 2900 5174 50  0000 C CNN
F 2 "" H 2900 5100 50  0001 C CNN
F 3 "" H 2900 5100 50  0001 C CNN
	1    2900 5100
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR?
U 1 1 5F6ADCEF
P 3450 5200
F 0 "#PWR?" H 3450 5050 50  0001 C CNN
F 1 "+3V3" H 3465 5373 50  0000 C CNN
F 2 "" H 3450 5200 50  0001 C CNN
F 3 "" H 3450 5200 50  0001 C CNN
	1    3450 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	3250 5200 3450 5200
Text Label 2200 5650 0    50   ~ 0
SCL
Text Label 2200 5500 0    50   ~ 0
SDA
Text Label 2200 5200 0    50   ~ 0
TCS_LED
$Comp
L power:GND #PWR?
U 1 1 5F69DD01
P 3450 5350
F 0 "#PWR?" H 3450 5100 50  0001 C CNN
F 1 "GND" H 3455 5177 50  0000 C CNN
F 2 "" H 3450 5350 50  0001 C CNN
F 3 "" H 3450 5350 50  0001 C CNN
	1    3450 5350
	1    0    0    -1  
$EndComp
Wire Wire Line
	3250 5350 3450 5350
Wire Wire Line
	2550 5650 2200 5650
Wire Wire Line
	2550 5500 2200 5500
Wire Wire Line
	2550 5200 2200 5200
NoConn ~ 2550 5350
Wire Wire Line
	6950 2300 7400 2300
Text Label 6950 2300 0    50   ~ 0
TCS_LED
$EndSCHEMATC
