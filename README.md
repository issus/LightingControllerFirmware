
## Prerequisites

You'll need the following to run this project:

-   Infineon's XMC4700 Relax Kit dev board
-   Infineon DAVE IDE (latest version)

## Installation

1.  Clone the repository.
2.  Open the project in the Infineon DAVE IDE.
3.  Build the project.
4.  Debug the project to run the code on the microcontroller.
    

## Configuration

The code includes a setup for GDB Semi-Hosting, which allows the console from the microcontroller to be handed over to the computer. This gives easy access to printf. Check the provided code for the exact setup.

You will need to set the IP settings to match the subnet of your computer. The static IP is set to `10.0.0.100`.

## Functionality

The main functionality of the code is to:

-   Initialize the microcontroller's peripherals.
-   Set up an IP stack with the microcontroller's ethernet MAC.
-   Provide trailing edge lighting dimming for 18 channels.
-	Provide RMS current measurement for the power board.
-	Control the power board with SCPI commands.

## Testing

To test the microcontroller, you can use any VISA application. In the tutorial, Rohde & Schwarz's VISA Tester was used.

For debugging, the Infineon DAVE IDE has a console for monitoring the state of the microcontroller.

## License

This project is licensed under the MIT License - see the `LICENSE.md` file for details.

## Acknowledgments

-   Special thanks to Jan Breuer for the SCPI-Parser library used in this project.