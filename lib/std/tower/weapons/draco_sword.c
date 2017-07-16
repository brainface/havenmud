#include <mudlib.h>
#include <types.h>
#include <material.h>
inherit WEAPON;

void reset(int arg) {
  if (!is_clone(this_object())) return;
  ::reset(arg);
  if (arg) return;
  set_name("scimitar");
  set_class(11);
  set_material(MAT_STEEL|MAT_BONE);
  set_new_type(MEDIUM|SLASH);
  set_damage_type(WEAPON_SLASH);
  set_short("a broken edged scimitar");
  set_long("\
This is a draconian scimitar with a toothed edge to it.\n");
  set_value(-1);
  replace_program(WEAPON);
}
