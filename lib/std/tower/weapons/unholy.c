
#include <mudlib.h>
#include <types.h>
#include <material.h>
#include "../rooms.h"
inherit WEAPON;

void reset(int arg) {
  ::reset(arg);
  if (arg) return;
  set_name("avenger");
  set_short("a glistening black blade");
  set_steal(1);
  set_alias("sword");
  set_alt_name("blade");
  set_color("|WKB");
  set_class(17);
  set_long("\
This gleamingly dark black blade is inlaid with the symbols \n\
of the Commander of Rath-Khan's guards.  The personal deeds \n\
of each commander are inscribed on the hilt.  This sword \n\
eminates a powerful aura of evil which chills you to the \n\
bone.  You get a skittish feeling that only the most evil \n\
of people would dare to wield this blade. \n\
Inscribed on the hilt is a short phrase: \n\
In honor of Lord Rommel, first to wield the Unholy Avenger. \n");
  set_read("\
Talon Bloodbane, Knight of Rath Khan, \n\
Lord Ixian Bloodbane, Knight Souvraeli of Rath Khan, \n\
ArchDuke Bene Bloodbane, Knight Kerei of Rath Khan, \n\
HighLord Gesser Bloodbane, Hero of Rath Khan.\n");
  set_info("\
This weapon is Avenger, the unholy sword of Rath-Khan's\n\
heroes.  People who walk in the light will be destroyed\n\
by it's rage if they attempt to use it.\n");
  set_weight(2);
  set_hit_func(TO);
  set_wield_func(TO);
  set_new_type(MEDIUM|SLASH|PIERCE);
  set_damage_type(DAM_EVIL|WEAPON_SLASH);
  set_material(MAT_STEEL);
  set_hit_bonus(10);
  set_value(-1);
}

status wield_func(object ob) {
  if (this_player()->query_alignment() > 0) {
    write("The weapon despises you!\n");
    say("Avenger sprays "+this_player()->query_cap_name()+" in a gush of power.\n");
    this_player()->receive_damage(200,DAM_EVIL);
    return 0;
  }
  return 1;
}

int weapon_hit(object attacker) {
  int dam;
  object me, foe;
  me = ENV(TO);
  foe = me->query_attack();
  if (foe->query_alignment() < -100) {
    write("|RKBAvenger voices its disapproval of this foe!\n");
    say("|RKBAvenger scorches "+me->query_name()+" with evil!\n");
    dam = -(foe->query_alignment())/10;
    if (dam > 75) dam = 75;
    me->hit_player(dam,DAM_EVIL);
    dam =0;
  }

  if (random(3)) {
    if (foe->query_alignment() > 0) {
      write("|RKBAvenger slices into "+foe->query_name()+" with delight.\n");
      say("|RKBAvenger slices into "+foe->query_name()+" with delight.\n");
      dam = foe->query_alignment() / 15;
      if (dam >= 75) dam = 75; 
    }
  }
  return dam;
}
