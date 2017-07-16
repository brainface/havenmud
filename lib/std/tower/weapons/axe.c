#include <mudlib.h>
#include <material.h>
#include <types.h>
inherit WEAPON;

void reset(int arg) {
  if (!is_clone(this_object())) return;
  ::reset(arg);
  if (arg) return;
  set_name("axe");
  set_short("a woodsman's axe");
  set_class(10);
  set_material(MAT_NATURAL|MAT_STEEL);
  set_weight(2);
  set_long("This is an axe of the type normally used to chop wood.\n");
  set_new_type(LARGE|SLASH);
  set_damage_type(WEAPON_SLASH);
  set_value(-1);
  replace_program(WEAPON);
}
