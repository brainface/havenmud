#include <mudlib.h>
#include <treasure.h>
#include <types.h>
inherit TREASURE;

void reset(int arg) {
  ::reset(arg);
  if (arg) return;
  set_name("diamond");
  set_alias("gem");
  set_short("a flawless diamond");
  set_long("\
This is a flawless diamond from the pits of Thrax.\n");
  set_treasure_type(TYP_GEM);
  set_value(2500+random(1000));
}
