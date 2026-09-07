# Smart-Extension-Box

This is a smart extension box, aimed to serve as a protection equipment.
A common practise is to connect one extension to another and so on. This is called daisy chaining.
Despite it looking harmless, it creates room to connect more devices to the extension sockets. Even though the sockets are many, they all connect together to a single
5A, 230V power source. The maximum power that can be delivered is 5 x 230 = 1150 W
With a few phone chargers and light loads, this limit isnt surpassed.
But, if multiple high power devices are connected together, this limit is broken and it poses a fire risk
In such a case, the MCB cannot act on time to cut power to the circuit, as it takes time to react to these cases.

To prevent such an incident, we have made an extension box, with a current sensor and a relay
The current sensor senses current and calculates power draw.
If it surpasses the set limit (70W in this case for simulation), the relay trips and the buzzer beeps. The relay can be reset using a pushbutton to its original position 
to allow conduction.
