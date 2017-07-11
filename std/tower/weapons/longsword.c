#include <mudlib.h>
#include "../rooms.h"
#include <types.h>
#include <material.h>
inherit WEAPON;

void reset(int arg) {
  ::reset(arg);
  if (arg) return;
  set_name("longsword");
  set_short("a gleaming longsword");
  set_long("\
A finely crafted sword made during the golden age.\n");
  set_class(15 + random(3));
  set_new_type(MEDIUM|SLASH|PIERCE);
  set_material(MAT_STEEL|MAT_SILVER);
  set_weight(3);
  set_alias("sword");
  set_alt_name("longsword");
  set_hit_func(this_object());
  set_value(-1);
}

int weapon_hit(object attacker) {
  int spam;
  int dam;
  spam = random(2);
  if (random(100)> 92) {
    switch (spam) {
    case 0 :
      write("|RKBYour sword gleams in the light.\n");
      say("|RKB"+TP->NAME+"'s sword gleams with pride.\n");
      dam = 1 + random(2);
      break;
    case 1:
      write("|RKBYou feel Rath-Khan's rage in your swing.\n");
      say("|RKBEvil glistens from "+TP->NAME+"'s sword-edge.\n");
      dam = 2 + random(3);
      break;
    }
  }
  return dam;
}
