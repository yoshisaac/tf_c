#ifndef ENTITY_H
#define ENTITY_H

#include "../math/vec3.h"

#include <stdbool.h>
#include <stdint.h>

__int32_t get_ent_flags(void *entity);
__int32_t get_ent_health(void *entity);
__int32_t get_ent_max_health(void *entity);
__int32_t get_ent_team(void *entity);
__int32_t get_ent_class(void *entity);
struct vec3_t get_ent_origin(void *entity);
struct vec3_t get_ent_eye_pos(void *entity);
struct vec3_t get_ent_angles(void *entity);
struct vec3_t get_ent_velocity(void *entity);
__int32_t setup_bones(void *entity, void *bone_to_world_out, __int32_t max_bones, __int32_t bone_mask, float current_time);
struct vec3_t get_bone_pos(void *entity, int bone_num);
bool is_ent_dormant(void *entity);
bool get_ent_lifestate(void *entity);
__int32_t get_active_weapon(void *entity);
struct vec3_t *get_collideable_mins(void *entity);
struct vec3_t *get_collideable_maxs(void *entity);
int get_tick_base(void *entity);
int get_best_aim_bone(void *localplayer, void *entity);
bool can_attack(void *localplayer);

enum
{
    TF_CLASS_UNDEFINED = 0,
    TF_CLASS_SCOUT,
    TF_CLASS_SNIPER,
    TF_CLASS_SOLDIER,
    TF_CLASS_DEMOMAN,
    TF_CLASS_MEDIC,
    TF_CLASS_HEAVYWEAPONS,
    TF_CLASS_PYRO,
    TF_CLASS_SPY,
    TF_CLASS_ENGINEER
};

struct player_info_t
{
    char name[32];
    int userID;
    char guid[33];
    unsigned long friendsID;
    char friendsName[32];
    bool fakeplayer;
    bool ishltv;
    unsigned long customFiles[4];
    unsigned char filesDownloaded;
};

#endif // ENTITY_H
