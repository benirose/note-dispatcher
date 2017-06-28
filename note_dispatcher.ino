#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE();

const int totalVoices = 5;

boolean notes[127];
boolean voices[totalVoices];

void handleNoteOn(byte oldChannel, byte pitch, byte velocity)
{
	int channel = false;
	// check to see if we have any channels available
	for (int i = 0; i < totalVoices; i++)
	{
		if (!voices[i] && channel == false)
		{
			channel = i+1;
			break;
		}
	}
	// if we didn't find a voice, get outta here
	if (!channel)
		return;

	// send note on
	MIDI.sendNoteOn(pitch, velocity, channel);
	// mark channel as in use
	voices[channel-1] = pitch;
	// mark note by channel
	notes[pitch] = channel;

}

void handleNoteOff(byte oldChannel, byte pitch, byte velocity)
{
	// check to see what channel we are freeing up
	int channel = notes[pitch];
	// mark channel as available
	voices[channel-1] = false;

	// turn note off
	MIDI.sendNoteOff(pitch, 0, channel);
}

void setup()
{
	MIDI.setHandleNoteOn(handleNoteOn);
	MIDI.setHandleNoteOff(handleNoteOff);

	for (int i = 0; i < totalVoices; i++)
	{
		voices[i] = false;
	}

	MIDI.begin(1);	
        MIDI.turnThruOff();
}

void loop()
{
	MIDI.read();
}

