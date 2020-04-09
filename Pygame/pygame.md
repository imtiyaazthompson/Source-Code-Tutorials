### Pygame
## Starting Up
+ `display` module in the `pygame` namespace is an essential module to import

## Hello World!
```python
1	background_image_filename = 'sushiplate.jpg'
2	mouse_image_filename = 'fugu.png'
3
4	import pygame
5	from pygame.locals import *
6	from sys import exit
7
8	pygame.init()
9	screen = pygame.display.set_mode((640, 480), 0, 32)
10	pygame.display.set_caption("Hello, World!")
11
12	background = pygame.image.load(background_image_filename).convert()
13	mouse_cursor = pygame.image.load(mouse_image_filename).convert_alpha()
14
15	while True:
16		for event in pygame.event.get():
17			if event.type == QUIT:
18				exit()
19			screen.blit(background, (0,0))
20			x, y = pygame.mouse.get_pos()
21			x-= mouse_cursor.get_width() / 2
22			y-= mouse_cursor.get_height() / 2
23			screen.blit(mouse_cursor, (x, y))
24			pygame.display.update()
```

### Line for Line
1. Set file name for bg image
2. Set file name for the mouse cursor image

4. Import relevant modules and classes such as sound and image in the pygame namespace
5. Import constants that are frequently used, like QUIT

8. Init all submodules in pygame, does hardware checks etc
9. Create a display surface with given dimensions, bitwise flags and color depth (bits), returns a `Surface` object
10. Set the caption of the screen

12. Load image for the bg from the file name and returns an `Surface` object
13. Load image fot the mouse cursor from the file name and returns a `Surface` object, convert is used to convert the image to the same format as the screen. `Surface.convert()`

15. Start of the main game loop, repeats once per screen refresh
16. Event loop, events such as key presses are Queued up and wait for you to handle them. `pygame.event.get()` returns the list of events that need to be reacted to

19. Render an image to the screen. `Surface.blit(Surface,(x,y))`
20. Get the mouse position relatice to the bounds of the screen, then set the images to move from the middle when moving the mouse

24. Displays all updates to the screen stored in the `back buffer`, if this is not called it will result in flickering

## Events
+ `pygame.event.get()` returs the entire event queue so you can handle all the events that have been queued before moving on to the next iteration of the game loop
+ `pygame.event.wait()` waits for some event to occur, blocking the script until an event occurs so it can be handled
+ `Event.type` allows us to react to certain events like `Event.type = QUIT`

```python
	import pygame
from pygame.locals import *
from sys import exit
pygame.init()
SCREEN_SIZE = (800, 600)
screen = pygame.display.set_mode(SCREEN_SIZE, 0, 32)
font = pygame.font.SysFont("arial", 16);
font_height = font.get_linesize()
event_text = []
while True:
	event = pygame.event.wait()
	event_text.append(str(event))
	event_text = event_text[-SCREEN_SIZE[1]/font_height:]
	if event.type == QUIT:
		exit()
	screen.fill((255, 255, 255))
	y = SCREEN_SIZE[1]-font_height
	for text in reversed(event_text):
		screen.blit( font.render(text, True, (0, 0, 0)), (0, y) )
		y-=font_height
	pygame.display.update()
```
