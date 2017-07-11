/*  The first Lamrani NPC for the temple */
#include <lib.h>
#include "../temple.h"
#include <std.h>
inherit LIB_SENTIENT;
int eventLamrani(object who);

static void create() {
  ::create();
  SetKeyName("lamrani apprentice");
  SetRace("lamrani");
  SetShort("a lamrani apprentice");
  SetFriends( ({ "lamrani_temple_npc" }) );
  SetMorality(400);
  SetId( ({ "apprentice", "lamrani", "lamrani_temple_npc" }) );
  SetAdjectives( ({ "lamrani" }) );
  SetClass("evoker");
  SetSkill("shock magic",1,1);
  SetLevel(random(60) + 50);
  SetLong("This young lamrani is merely an apprentice of the "
          "Great Lamrani mages, but that belies his power with "
          "magic that rivals the greatest of the mages of Kailie. "
          "A lamrani is a small, intelligent looking creature with "
          "pasty white skin over a thin frame. His hairless head and "
          "seemingly timeless face and eyes give the impression of "
          "power.");
  SetSpellBook( ([
      "chain lightning"   : 100,
      "mesmer barrier"    : 100,
      "disintegrate"      : 100,
      "bolt"              : 100,
      "planar durability" : 100,
      "planar strength"   : 100,
      ]) );
  SetAction(5, ({ 
      "!emote seems to sway in place.",
      "!emote chants deeply and somberly.",
      "!say Ohhh, our fate, to be banished here forever!",
      "!yell Why have you forsaken us, mighty Lord?",
      "!emote mutters a little prayer.",
    }) );
  SetCombatAction(80, ({
      "!cast chain lightning",
      "!cast disintegrate",
      "!yell Brethren, we are under attack!",
      }) );
  SetInventory( ([
      STD_CLOTHING "body/black_robe" : "wear robe",
      TEMPLE_OBJ    "app_staff"       : "wield staff",
    ]) );
  SetGender("male");
  SetWander(10);
  SetMessage("leave", "$N floats $D effortlessly.");
  SetMessage("come", "$N floats in effortlessly.");
  SetEncounter( (: eventLamrani :) );
  SetFirstCommands( ({
  	"cast mesmer barrier",
  	"cast mesmer barrier",
  	"cast mesmer barrier",
  	"cast mesmer barrier",
  	"cast mesmer barrier",
  	"cast planar strength",
  	"cast planar durability",
    }) );
 }

int eventLamrani(object who) {
	if (who->id("lamrani_temple_npc")) return 0;
        if (who->GetStatLevel("charisma") < 100) {
		SetAttack(who);
		return 1;
  }
  return 0;
}

void heart_beat() {
  ::heart_beat();
  if (sizeof(GetMagicProtectionNames()) < 5) {
    eventForce("cast mesmer barrier");
  }
}
