#! python3
# sequencer.py

import os
import pygame
import sys
from pygame.locals import *

# Set up pygame
pygame.mixer.pre_init(44100, -16, 2, 2048)
pygame.mixer.init()
pygame.init()
window_width = 720
window_height = 320
main_clock = pygame.time.Clock()
fps = 60
window_surface = pygame.display.set_mode((window_width, window_height))
pygame.display.set_caption('Sequencer')

# Colors
black = (0, 0, 0)
white = (255, 255, 255)

# Set up font
font = pygame.font.SysFont(None, 18)

# Time bar
time_bar_tempo = 5
time_bar_image = pygame.image.load('assets/time_bar.png').convert()
time_bar = time_bar_image.get_rect()

# Set up sounds
sounds_list = []
sound_directory = 'assets/sounds'
for file in os.listdir(sound_directory):
    sounds_list.append(file)


# Sound Square - left mouse click to change state
class SoundSquare:
    def __init__(self, audio_file, x_pos, y_pos, track_num):
        self.size = 80
        self.off = pygame.image.load('assets/sound_square_off.png').convert_alpha()
        self.on = pygame.image.load('assets/sound_square_on.png').convert_alpha()
        self._state = False
        self.rect = pygame.Rect(x_pos, y_pos, self.size, self.size)
        self.sound = pygame.mixer.Sound('assets/sounds' + '/' + audio_file)

    # get state
    def get_state(self):
        return self._state

    # toggle state
    def toggle_state(self):
        self._state = not self._state

    # render
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
    x = 40
    y = 40
    for sound_file in sounds_list:
        render_text = font.render(sound_file, True, white)
        render_text_rect = render_text.get_rect(center=(x, y))
        window_surface.blit(render_text, render_text_rect)
        y += (window_height / 4)


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
track_list = [[], [], [], []]
x_pos = 80
y_pos = 0
for j in range(len(track_list)):
    for i in range(0, 8):
        sound_square = SoundSquare(sounds_list[j], (x_pos * i) + x_pos, y_pos, j)
        track_list[j].append(sound_square)
    y_pos += 80


while True:
    main_clock.tick(fps)
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
    if time_bar.right > window_width - 6:
        time_bar.right = 75
    time_bar.move_ip( 1 * time_bar_tempo, 0)

    # Draw black background onto the window surface
    window_surface.fill(black)

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
    main_clock.tick(fps)
