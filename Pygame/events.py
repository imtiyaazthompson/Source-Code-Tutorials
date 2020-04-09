import pygame
from pygame.locals import *
form sys import exit

pygame.init()
scr = pygame.display.set_mode((800,600),0,32)

font = pygame.font.SysFont("arial",16)
fh = font.get_linesize()
event_text = []

render_bounds = ((10,10),(790,590))
