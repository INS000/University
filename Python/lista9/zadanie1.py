import matplotlib.pyplot as plt
import matplotlib.animation as animation
import numpy as np
import random

# Parametry gry
GRID_SIZE = 20
SQUARE_COUNT = 2
SNAKE_LENGTH = 20
DIRECTION_CHANGE_PROBABILITY = 0.7


obstacles = set()
while len(obstacles) < SQUARE_COUNT:
    obstacles.add((random.randint(0, GRID_SIZE - 1), random.randint(0, GRID_SIZE - 1)))

snake = [(GRID_SIZE // 2, GRID_SIZE // 2)]
direction = random.choice([(0, 1), (1, 0), (0, -1), (-1, 0)])


def update_snake():
    global direction, snake

    directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    directions.remove((-direction[0], -direction[1]))

    if random.random() < DIRECTION_CHANGE_PROBABILITY:
        direction = random.choice(directions)

    new_head = (snake[0][0] + direction[0], snake[0][1] + direction[1])

    if (new_head in obstacles or
            new_head in snake or
            not (0 <= new_head[0] < GRID_SIZE and 0 <= new_head[1] < GRID_SIZE)):
        return False

    snake.insert(0, new_head)

    if len(snake) > SNAKE_LENGTH:
        snake.pop()

    return True


def draw(frame):
    if not update_snake():
        ani.event_source.stop()
        plt.title("Koniec gry!", fontsize=16)
        return

    ax.clear()
    ax.set_xlim(0, GRID_SIZE)
    ax.set_ylim(0, GRID_SIZE)
    ax.set_xticks(range(GRID_SIZE))
    ax.set_yticks(range(GRID_SIZE))
    ax.grid(True)

    for (x, y) in obstacles:
        ax.add_patch(plt.Rectangle((x, y), 1, 1, color="red"))

    for (x, y) in snake:
        ax.add_patch(plt.Rectangle((x, y), 1, 1, color="green"))

    head_x, head_y = snake[0]
    ax.add_patch(plt.Rectangle((head_x, head_y), 1, 1, color="blue"))


fig, ax = plt.subplots(figsize=(14, 14))
ani = animation.FuncAnimation(fig, draw, frames=100, interval=250)
plt.show()

