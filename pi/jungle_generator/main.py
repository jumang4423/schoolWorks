# mr. pydub
from pydub import AudioSegment
from pydub.playback import play


def seqToBuffer(sequences, sounds):
    _playlist = AudioSegment.empty()
    for sec in sequences:
        if sec["id"] >= 0 and len(sounds) > sec["id"]:
            if sec["reverse"] == True:
                _playlist += sounds[sec["id"]].reverse()
            else:
                _playlist += sounds[sec["id"]]
    return _playlist


def musicLoop(_playlist):

    play(_playlist)

    # from pygame import mixer
    # mixer.init()
    # mixer.music.load(_playlist)
    # mixer.music.play(1)


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
            AudioSegment.from_wav(
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
        {"id": 0, "vol": 1, "pan": 0, "speed": 1, "reverse": False},
        {"id": 7, "vol": 1, "pan": 0, "speed": 1, "reverse": False},
        {"id": 2, "vol": 1, "pan": 0, "speed": 1, "reverse": False},
        {"id": 3, "vol": 1, "pan": 0, "speed": 1, "reverse": False},
        {"id": 1, "vol": 1, "pan": 0, "speed": 1, "reverse": False},
        {"id": 2, "vol": 1, "pan": 0, "speed": 1, "reverse": False},
        {"id": 3, "vol": 1, "pan": 0, "speed": 1, "reverse": True},
        {"id": 2, "vol": 1, "pan": 0, "speed": 1, "reverse": False},
    ]

    record = AudioSegment.empty()
    while True:
        _playlist = seqToBuffer(sequences, sounds)
        record += _playlist
        musicLoop(_playlist)


if __name__ == "__main__":
    main()
