#include <mudlib.h>
#include <treasure.h>
#include <material.h>
inherit TREASURE;

void reset(int arg) {
  ::reset(arg);
  if (arg) return;
  set_name("gem");
  set_short("a glittering opal");
  set_long("\
This is a fist-sized opal from the hoards of Rath-Khan.\n");
  set_alias("gem");
  set_alt_name("opal");
  set_treasure_type(TYP_GEM);
  set_material(MAT_GEM);
  set_weight(1);
  set_value(500+random(500));
}
