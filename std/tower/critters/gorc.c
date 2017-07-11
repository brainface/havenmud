#include <mudlib.h>
#include <race.h>
#include <types.h>
#include "../rooms.h"
inherit MONSTER;

void reset(int arg) {
  if (!is_clone(this_object())) return;
  ::reset(arg);
  if (arg) return;
  set_name("constable");
  set_level(10+random(11));
  set_alias("orc");
  set_friends("orc");
  add_money(random(50)*TO->query_level());
  set_al(random(400)-200,random(400));
  set_wander(50,50);
  set_short("a lunar orc constable");
  set_random_pick(20);
  set_long("\
This is an orc constable, charged with keeping the peace.\n");
set_race("orc");
enable_player_commands();
  load_cmd(1, ({
    "rsay Orc Orc Orc!!!",
    "rsay Waaaaaaaaagggggggghhhhh!!!!!",
    "rsay Oi, der's some skummy gits dat need to learn some zoggin manners!",
    "rsay We're huuuuuuuuuge!",
    "dance",
    "swear",
    "rsay Oi ya skummy git!",
    "grin" }) );
  set_gender(random(2)+1);
  add_attack(2,75,0,12,WEAPON_SLASH|WEAPON_BLUNT,0, ({
({ "really hard","really hard","thumping","thumping" }),
({ "into the ground","into the ground","pounds","pounds" }),
({ "like wildfire","like wildfire","tears into","tears into" }),
({ "from shoulder to groin","from shoulder to groin","slashing","slashing"}),
({ "black and blue","black and blue","battering","battering" }),
({ "the finer points of orky know-wots","the finer points of orky know-wots",
"teaching","teaching" }) }) );
  replace_program(MONSTER);
}
