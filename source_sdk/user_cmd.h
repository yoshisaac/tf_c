#ifndef USER_CMD_H
#define USER_CMD_H
#include "math/vec3.h"

struct user_cmd
{
    void *something;
    int command_number;
    int tick_count;
    struct vec3_t viewangles;
    float forwardmove;
    float sidemove;
    float upmove;
    int buttons;
    unsigned char impulse;
    int weapon_select;
    int weapon_subtype;
    int random_seed;
    short mouse_dx;
    short mouse_dy;
    bool has_been_predicted;
};

enum in_buttons 
{
    IN_ATTACK = (1 << 0),
    IN_JUMP = (1 << 1),
    IN_DUCK = (1 << 2),
    IN_FORWARD = (1 << 3),
    IN_BACK = (1 << 4),
    IN_USE = (1 << 5),
    IN_CANCEL = (1 << 6),
    IN_LEFT = (1 << 7),
    IN_RIGHT = (1 << 8),
    IN_MOVELEFT = (1 << 9),
    IN_MOVERIGHT = (1 << 10),
    IN_ATTACK2 = (1 << 11),
    IN_RUN = (1 << 12),
    IN_RELOAD = (1 << 13),
    IN_ALT1 = (1 << 14),
    IN_ALT2 = (1 << 15),
    IN_SCORE = (1 << 16),
    IN_SPEED = (1 << 17),
    IN_WALK = (1 << 18),
    IN_ZOOM = (1 << 19),
    IN_WEAPON1 = (1 << 20),
    IN_WEAPON2 = (1 << 21),
    IN_BULLRUSH = (1 << 22),
    IN_GRENADE1 = (1 << 23),
    IN_GRENADE2 = (1 << 24),
    IN_ATTACK3 = (1 << 25),
};

#endif