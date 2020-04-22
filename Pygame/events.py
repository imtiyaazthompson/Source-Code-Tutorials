import pygame
from pygame.locals import *
from sys import exit

pygame.init()
scr = pygame.display.set_mode((800,600),0,32)

font = pygame.font.SysFont("arial",16)
fh = font.get_linesize()
event_text = []

render_bounds = ((10,10),(790,590))

while True:
	event = pygame.event.wait()
	event_text.append(str(event))

	if event.type == QUIT:
		exit()

	scr.fill((255,255,255))

	y = render_bounds[0][1]
	x = render_bounds[0][0]
	for text in event_text:
		scr.blit(font.render(text,True,(0,0,0)),(x,y))
		y += fh
		if y >= render_bounds[1][1]:
			scr.fill((255,255,255))
			y = render_bounds[0][1]
	pygame.display.update()
