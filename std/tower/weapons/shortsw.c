#include <mudlib.h>
#include <types.h>
#include <material.h>
inherit WEAPON;

void reset(int arg) {
  if (!is_clone(this_object())) return;
  ::reset(arg);
  if (arg) return;
  set_name("shortsword");
  set_alias("sword");
  set_alt_name("short");
  set_class(11);
  set_short("a sharp edged shortsword");
  set_long("\
This is a shortsword of the type normally used by\n\
Rath-Khan's foot soldiers.\n");
  set_weight(1);
  set_new_type(MEDIUM|SLASH|PIERCE);
  set_material(MAT_STEEL|MAT_SILVER);
  set_value(-1);
  replace_program(WEAPON);
}
