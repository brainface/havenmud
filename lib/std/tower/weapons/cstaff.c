#include <mudlib.h>
#include <types.h>
#include <material.h>
inherit WEAPON;

void reset(int arg) {
 if (!is_clone(this_object())) return;
 ::reset(arg);
 if (arg) return;
 set_name("keeper's staff");
 set_alias("staff");
 set_alt_name("cstaff");
 set_new_type(LARGE|BLUNT|POLE);
 set_damage_type(WEAPON_BLUNT);
 set_class(15);
 set_weight(3);
 set_material(MAT_BONE);
 set_short("a large bone staff");
 set_long("\
This staff is the traditional Staff of Rank for the\n\
Crypt Guards of Rath - Khan, an order devoted to \n\
death.\n");
 set_hit_bonus(5);
 set_value(-1);
 replace_program(WEAPON);
}
