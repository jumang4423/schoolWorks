# mr. pydub
from pydub import AudioSegment
import simpleaudio
import time

from simpleaudio.shiny import PlayObject


def seqToBuffer(sequences, sounds):
    _playlist = AudioSegment.empty()
    for sec in sequences:
        if sec["id"] >= 0 and len(sounds) > sec["id"]:
            if sec["reverse"] == True:
                _playlist += sounds[sec["id"]].reverse()
            else:
                _playlist += sounds[sec["id"]]
    return _playlist


def playSa(_playlist):

    return simpleaudio.play_buffer(
        audio_data = _playlist.raw_data,
        num_channels=_playlist.channels,
        bytes_per_sample=_playlist.sample_width,
        sample_rate=_playlist.frame_rate,
    )

def main():
    # init vars
    break_kind = 1

    # drum memories
    _jsonPath = "./samples/drums/break" + str(break_kind) + "/meta.json"
    with open(_jsonPath, encoding="utf-8", mode="r") as f:
        import json

        d = json.load(f)

    sounds = []
    for json in d:
        sounds.append(
            AudioSegment.from_mp3(
                "samples/drums/break" + str(break_kind) + "/" + json["data"]
            ),
        )

    # next channel midis
    sequences = [
        {"id": 0, "vol": 1, "pan": 0, "speed": 1, "reverse": False},
        {"id": 7, "vol": 1, "pan": 0, "speed": 1, "reverse": False},
        {"id": 2, "vol": 1, "pan": 0, "speed": 1, "reverse": False},
        {"id": 3, "vol": 1, "pan": 0, "speed": 1, "reverse": False},
        {"id": 1, "vol": 1, "pan": 0, "speed": 1, "reverse": False},
        {"id": 2, "vol": 1, "pan": 0, "speed": 1, "reverse": False},
        {"id": 3, "vol": 1, "pan": 0, "speed": 1, "reverse": True},
        {"id": 2, "vol": 1, "pan": 0, "speed": 1, "reverse": False},
    ]

    record = AudioSegment.empty() # recorder

    _timed = 100 / 60
    _from_sec = time.time()
    _delay_time = 0
    _delay_start = time.time()

    objPlay = []

    for i in range(5):
        _delay_start = time.time()
        _playlist = seqToBuffer(sequences, sounds)
        record += _playlist
        objPlay.append(playSa(_playlist))
        _delay_time = time.time() - _delay_start

        time.sleep(_timed - _delay_time)


        # elif _timed == 0:
        #     play_obj.wait_done()
        #     _timed = time.time() - _from_sec
    


if __name__ == "__main__":
    main()
