#define GAIN_1_2X 0xF
#define GAIN_1X   0x0
#define GAIN_2X   0x1
#define GAIN_4X   0x2
#define GAIN_8X   0x3
#define GAIN_16X  0x4

#define PIN_ADC_POSITIVE A0
#define PIN_ADC_NEGATIVE A1



void setup() {
  Serial.begin(921600);
  
  while (!Serial) {}

  analogReadResolution(12); // 12-bit resolution

  // configure the ADC for differential mode
  ADC->CTRLB.bit.DIFFMODE = 0x1;
  ADC->CTRLB.bit.FREERUN = 0x1;
  ADC->INPUTCTRL.bit.MUXPOS = 0x00; 
  ADC->INPUTCTRL.bit.MUXNEG = 0x03;
  ADC->INPUTCTRL.bit.GAIN = 0x0;
  //ADC->AVGCTRL.bit.SAMPLENUM = 1; // No averaging

  // disable the internal VREF
  ADC->REFCTRL.bit.REFSEL = 0; // set the reference selection to 0 (internal VREF off)
  ADC->CTRLA.reg = ADC_CTRLA_ENABLE; // enable the ADC
}

void loop() {
  int16_t adcValue = ADC->RESULT.reg; // read the ADC result register

  Serial.print(millis());
  Serial.print(", ");
  Serial.println(adcValue);

  delay(3);
}
