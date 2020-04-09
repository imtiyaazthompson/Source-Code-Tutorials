import pygame
from pygame.locals import *
from sys import exit

bgname = 'bg.jpg'
msname = 'mouse.png'

pygame.init()

dimensions = (640,480)
scr = pygame.display.set_mode(dimensions,0,32)
pygame.display.set_caption('Hello, World!')

bg = pygame.image.load(bgname).convert()
ms = pygame.image.load(msname).convert_alpha()

while True:
	for event in pygame.event.get():
		if event.type == QUIT:
			exit()

	scr.blit(bg,(0,0))

	x,y = pygame.mouse.get_pos()
	x -= ms.get_width() / 2
	y -= ms.get_height() / 2
	scr.blit(ms,(x,y))

	pygame.display.update()
