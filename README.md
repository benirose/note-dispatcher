# note-dispatcher
A basic MIDI Note Dispatcher for Arduino. It simply takes in any notes on channel one and spreads them across channels, starting on 1 and increasing until reaching the `totalVoices` const.

I initially built this so I could use my Electribe EMX as a polyphonic synth, but it should work for any multi-channel synthesizer. This is a proof of concept I never finished, future enhancements might include:
* Note stealing
* Parameter control
* MIDI Thru
