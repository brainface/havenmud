#include <mudlib.h>
#include <types.h>
#include <material.h>
inherit WEAPON;

void reset(int arg) {
  if (!is_clone(this_object())) return;
  ::reset(arg);
  if (arg) return;
  set_name("a rusty short sword");
  set_alias("sword");
  set_new_type(SMALL|SLASH|PIERCE);
  set_damage_type(WEAPON_SLASH|WEAPON_PIERCE);
  set_class(5 + random(3));
  set_material(MAT_STEEL);
  set_short("a rusty short sword");
  set_long("A short sword that has seen to many years of service.\n");
  set_weight(1);
  set_value(-1);
  replace_program(WEAPON);
}
