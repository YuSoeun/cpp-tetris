#include <iostream>
using namespace std;

#include <cstdlib>
#include <cstring>
#include <ctime>

#include "block.hpp"
#include "Console.h"

enum BlockType
{
    b1, b2, b3, b4, b5
};

enum Turn
{
    left_turn = -1, right_turn = 1
};

/*1번 블럭*/
const int block1[4][4][4] = {
        {
                        {0, 0, 0, 0},
                        {0, 0, 0, 0},
                        {2, 2, 2, 2},
                        {0, 0, 0, 0}
        },
        {
                        {0, 0, 2, 0},
                        {0, 0, 2, 0},
                        {0, 0, 2, 0},
                        {0, 0, 2, 0}
        },
        {
                        {0, 0, 0, 0},
                        {0, 0, 0, 0},
                        {2, 2, 2, 2},
                        {0, 0, 0, 0}
        },
        {
                        {0, 0, 2, 0},
                        {0, 0, 2, 0},
                        {0, 0, 2, 0},
                        {0, 0, 2, 0}
        },
};
/*2번 블럭*/
const int block2[4][4][4] = {
        {
                        {0, 0, 0, 0},
                        {0, 2, 2, 0},
                        {0, 2, 2, 0},
                        {0, 0, 0, 0}
        },
        {
                        {0, 0, 0, 0},
                        {0, 2, 2, 0},
                        {0, 2, 2, 0},
                        {0, 0, 0, 0}
        },
        {
                        {0, 0, 0, 0},
                        {0, 2, 2, 0},
                        {0, 2, 2, 0},
                        {0, 0, 0, 0}
        },
        {
                        {0, 0, 0, 0},
                        {0, 2, 2, 0},
                        {0, 2, 2, 0},
                        {0, 0, 0, 0}
        },
};
/*3번 블럭*/
const int block3[4][4][4] = {
        {
                        {0, 2, 0, 0},
                        {0, 2, 0, 0},
                        {0, 2, 2, 0},
                        {0, 0, 0, 0}
        },
        {
                        {0, 0, 0, 0},
                        {0, 2, 2, 2},
                        {0, 2, 0, 0},
                        {0, 0, 0, 0}
        },
        {
                        {0, 2, 2, 0},
                        {0, 0, 2, 0},
                        {0, 0, 2, 0},
                        {0, 0, 0, 0}
        },
        {
                        {0, 0, 0, 0},
                        {0, 0, 2, 0},
                        {2, 2, 2, 0},
                        {0, 0, 0, 0}
        },
};
/*4번 블럭*/
const int block4[4][4][4] = {
        {
                        {0, 0, 0, 0},
                        {0, 2, 0, 0},
                        {0, 2, 2, 0},
                        {0, 0, 2, 0}
        },
        {
                        {0, 0, 0, 0},
                        {0, 2, 2, 0},
                        {2, 2, 0, 0},
                        {0, 0, 0, 0}
        },
        {
                        {0, 0, 0, 0},
                        {0, 2, 0, 0},
                        {0, 2, 2, 0},
                        {0, 0, 2, 0}
        },
        {
                        {0, 0, 0, 0},
                        {0, 2, 2, 0},
                        {2, 2, 0, 0},
                        {0, 0, 0, 0}
        },
};
/*5번 블럭*/
const int block5[4][4][4] = {
        {
                        {0, 0, 0, 0},
                        {0, 2, 2, 2},
                        {0, 0, 2, 0},
                        {0, 0, 0, 0}
        },
        {
                        {0, 0, 2, 0},
                        {0, 2, 2, 0},
                        {0, 0, 2, 0},
                        {0, 0, 0, 0}
        },
        {
                        {0, 0, 2, 0},
                        {0, 2, 2, 2},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0}
        },
        {
                        {0, 0, 2, 0},
                        {0, 0, 2, 2},
                        {0, 0, 2, 0},
                        {0, 0, 0, 0}
        },
};

Block & newBlock(int x_in, int y_in)         
{
    Block * newblock = new Block;
    int block_type;
    srand(time(0));

    newblock->rotation = rand() % 4 + 0;
    block_type = rand() % 5 + 0;
    setShape(block_type, newblock->shape, newblock->rotation);

    newblock->x = x_in;
    newblock->y = y_in;

    return *newblock;
}



void setShape(int b_type, int ** shape, int rotation)
{
    switch (b_type)
    {
    case b1:
        memcpy(shape, block1[rotation], sizeof(int) * 4 * 4);
        break;

    case b2:
        memcpy(shape, block2[rotation], sizeof(int) * 4 * 4);
        break;

    case b3:
        memcpy(shape, block3[rotation], sizeof(int) * 4 * 4);
        break;

    case b4:
        memcpy(shape, block4[rotation], sizeof(int) * 4 * 4);
        break;

    case b5:
        memcpy(shape, block5[rotation], sizeof(int) * 4 * 4);
        break;
    
    default:
        cout << "rotation is not true. rotation is: " << rotation << '\n';
        break;
    }
}

void delBlock(Block * delBlock)
{
    delete delBlock;
}

void Block::down()
{
    pre_x = x;
    pre_y = y--;
}

void Block::left()
{
    pre_x = x--;
    pre_y = y;
}

void Block::right()
{
    pre_x = x++;
    pre_y = y;
}

void Block::rotate(int direction)
{
    memcpy(pre_shape, shape, sizeof(int) * 4 * 4);

    switch (direction)
    {
    case right_turn:
        rotation++;
        if (rotation > 3) {
            direction %= 4;
        }
        break;

    case left_turn:
        rotation--;
        if (rotation < 0) {
            direction += 4;
        }
        break;
    
    default:
        cout << "directon is not true. direction: " << direction << '\n';
        break;
    }

    setShape(block_type, shape, rotation);
}