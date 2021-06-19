#! python3
# jungle98.py

import os
import pygame
import sys
from pygame.locals import *

# system variables
title = 'jungle98'
audioSettings = {"frequency": 44100, "size": -16, "channels": 2, "buffer": 2048}
window_size = {"width": 720, "height": 640}
system_fps = 60
# objects
blockSize = 80
# sounds sequences
project_name = "Solar_Glide"
sequence_number = 8
tempo = 150
# s_tempo = ((3600.0 * system_fps) /  (float(blockSize) * float(sequence_number))) * tempo

s_tempo = 8
print(s_tempo, "LEARN")
# mixer inits
pygame.mixer.pre_init(
    audioSettings["frequency"],
    audioSettings["size"],
    audioSettings["channels"],
    audioSettings["buffer"],
)
pygame.mixer.init()
pygame.init()
# Colors
black_color = (24, 24, 24)
white_color = (200, 200, 200)
main_clock = pygame.time.Clock()
window_surface = pygame.display.set_mode((
    window_size["width"],
    window_size["height"]))
pygame.display.set_caption(title)
# font settings
font = pygame.font.SysFont(None, 18)
# _empty_bar =  pygame.Rect(2, window_size["height"] - blockSize, 0, 0) # pygame.image.load("images/bar.png").convert()
# time_bar = pygame.draw.rect(window_surface, white_color, _empty_bar, 0)
time_bar_image = pygame.image.load('images/bar.png').convert()
time_bar = time_bar_image.get_rect()
# drum memories
_jsonPath = "./" + project_name + "/breaks/meta.json"
with open(_jsonPath, encoding="utf-8", mode="r") as f:
    import json
    d = json.load(f)
# load sounds
break_list = []
for json in d:
    break_list.append("./" + project_name + "/breaks/" + json["data"])
print(break_list)

class SoundSquare:
    def __init__(self, audio_file, x_pos, y_pos, track_num):
        self.size = blockSize
        self.off = pygame.image.load("images/off.png").convert_alpha()
        self.on = pygame.image.load("images/on.png").convert_alpha()
        self._state = False
        self.rect = pygame.Rect(x_pos, y_pos, self.size, self.size)
        self.sound = pygame.mixer.Sound(audio_file)

    def get_state(self):
        return self._state

    def toggle_state(self):
        self._state = not self._state

    def render(self):
        if self._state is False:
            window_surface.blit(self.off, self.rect)
        else:
            window_surface.blit(self.on, self.rect)

def change_state(sound_square):
    mouse_pos = pygame.mouse.get_pos()
    if sound_square.rect.collidepoint(mouse_pos):
        sound_square.toggle_state()

# Text rendering
def render_text():
    x = blockSize / 2
    y = blockSize / 2
    for i in range(len(break_list)):
        render_text = font.render("b" + str(i), True, white_color)
        render_text_rect = render_text.get_rect(center=(x, y))
        window_surface.blit(render_text, render_text_rect)
        y += window_size["height"] / len(break_list)

def terminate():
    pygame.quit()
    sys.exit()

def wait_for_player_to_press_key():
    while True:
        for event in pygame.event.get():
            if event.type == QUIT:
                terminate()
            if event.type == KEYDOWN:
                if event.key == K_ESCAPE:
                    terminate()
                return


# Check for collision between time bar and 'on' sound square
def collide(time_bar, track_list):
    for track in track_list:
        for sound_square in track:
            if time_bar.right == sound_square.rect.left and sound_square._state == True:
                sound_square.sound.play()


# Set up sound squares
track_list = []

x_pos = blockSize
y_pos = 0
for j in range(len(break_list)):
    track_list.append([])
    for i in range(0, sequence_number):
        sound_square = SoundSquare(break_list[j], (x_pos * i) + x_pos, y_pos, j)
        track_list[j].append(sound_square)
    y_pos += blockSize

time_bar.right = blockSize


while True:
    main_clock.tick(system_fps)
    on_list = []

    # Check for the QUIT event
    for event in pygame.event.get():
        if event.type == QUIT:
            terminate()
        if event.type == KEYDOWN:
            if event.key == K_ESCAPE:
                terminate()
        if event.type == MOUSEBUTTONDOWN and event.button == 1:
            for track in track_list:
                for sound_square in track:
                    change_state(sound_square)

    # Move time bar across screen
    if time_bar.right > window_size["width"] - 6:
        time_bar.right = blockSize -5
    time_bar.move_ip(1 * s_tempo, 0)

    # Draw black background onto the window surface
    window_surface.fill(black_color)

    # Draw sound square to screen
    for track in track_list:
        for sound_square in track:
            sound_square.render()

    render_text()

    # Check for collision and play sound if collision
    collide(time_bar, track_list)

    # Draw time bar to screen
    window_surface.blit(time_bar_image, time_bar)

    pygame.display.update()
    main_clock.tick(system_fps)