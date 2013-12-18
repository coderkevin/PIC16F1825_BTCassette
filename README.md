PIC16F1825 - Bluetooth Cassette
===============================
#### By: Kevin Killingsworth

### Bluetooth Music Streaming Cassette Tape

This is a project that is intended to create a Bluetooth Streaming
Cassette Tape.  It requires the following items:

 * Cassette Tape Adapter
 * Bluetooth Media Streaming Device (with li-po battery)
 * [PIC16F1825][1] microcontroller (and associated circuitry)

The basic idea is that you house the entire setup within the cassette tape
adapter.  You wire the streaming device's output to the cassette adapter,
then you power the microcontroller (uC) from the Bluetooth device's battery,
and you connect the Bluetooth device's buttons to the GPIOs of the
uC to drive it.  Also, the uC has a hall effect sensor connected to it.
By attaching a small magnet to the motorized spool within the cassette adapter,
you can wake up the uC when the cassette player starts to turn the motor.
The uC then can press the buttons on the Bluetooth device to wake it up
and start playing audio.

### Prerequisites:

I created this project using the free versions of the following tools:
 * [Microchip MPLAB X][2] (v1.95)
 * [Microchip XC8 Compiler][3] (v1.21)
 * [MPLAB Code Configurator][4] (installed as plugin within MPLAB X)

You will need to download and install these tools appropriately before you
can open this project and build it.

Also, I use the [Microchip MPLAB ICD3 In-Circuit Debugger][5] to program
the chip and debug it.  I have tried line-by-line debugging and it works
in this configuration.  If you use a different compatible debugger, it should
work just fine as well.

[1]: http://www.microchip.com/wwwproducts/Devices.aspx?dDocName=en546902 "PIC 16F1825"
[2]: http://www.microchip.com/pagehandler/en-us/family/mplabx/ "MPLAB X"
[3]: http://www.microchip.com/pagehandler/en_us/devtools/mplabxc/ "MPLAB XC Compilers"
[4]: http://www.microchip.com/pagehandler/en-us/press-release/microchips-free-code-configura.html "MPLAB Code Configurator"
[5]: http://www.microchip.com/stellent/idcplg?IdcService=SS_GET_PAGE&nodeId=1406&dDocName=en537580 "MPLAB ICD 3 In-Circuit Debugger"


