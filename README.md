# QT Py SAMD21 Controlled Sample Rate Differential ADC Arduino Code
## Description
This Arduino code will enable the MCU to utilize two ADC inputs for differential input with zero gain by default. The delay portion of code helps maintain the sample rate, however, with 3us the ADC oversamples a bit.

<img src="https://github.com/dustinlaroche/QT-Py-SAMD21-Controlled-ADC-Differential/blob/main/plot.png" />

<b><u>To Do List</u></b>
<ol>
  <li>Work on interrupt to have a finer control over the sample rate to match the 350 ksps.</li>
</ol>


