#include <mudlib.h>
#include <types.h>
#include <material.h>
inherit GEN_ARMOUR;

void reset(int arg) {
  if (!is_clone(this_object())) return;
  ::reset(arg);
  if (arg) return;
  set_name("crown");
  set_alias("rath_crown");
  set_new_type(HELMET);
  set_color("|CK0");
  set_ac(7);
  set_material(MAT_GOLD|MAT_SILVER|MAT_NATURAL);
  set_arm_light(1);
  set_short("a glowing crown");
  set_long("\
This is the mystical crown of Rath-Khan.\n\
It glows with an eerie blue light.\n");
  set_warmth(2);
  set_value(-1);
  replace_program(GEN_ARMOUR);
}
