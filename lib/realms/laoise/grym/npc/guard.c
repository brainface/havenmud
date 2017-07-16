#include <lib.h>
inherit LIB_NPC;
#include "../grymxoria.h"
#include "../wanted.h"

int CheckWanted();

static void create() {
  ::create();
  SetKeyName("brute");
  SetShort("a member of the brute squad");
  SetId( ({ "member", "grym_npc", "guard", "brute" }) );
  SetAdjectives( ({ "member", "of", "the", "brute", }) );
  SetLong(
    "This is a member of the Grymxoria brute squad. He looks very "
    "strong, well motivated, and ready for anything. He has "
    "a very bored look on his face."
  );
  SetRace("human");
  SetGender("male");
  RemoveLanguage("Enlan");
  SetLanguage("Blaodric", 100, 1);
  SetClass("fighter");
  SetLevel(25);
  SetMorality(-750);
  SetInventory( ([
    G_OBJ + "blood_sword"   : "wield sword",
    G_OBJ + "wall_shield"   : "wear shield on left arm",
    G_OBJ + "guard_armour"  : "wear chain mail"
    ]) );
  SetAction(5, ({ 
    "!speak I'm on the brute squad.",
    "!speak We don't want any trouble here in town.",
    "!emote looks around with a bored expression.",
    "!yawn",
    "!emote stifles a yawn.",
  }) );
  SetCurrency("bloodgems", 100 );
  SetEncounter( (: CheckWanted :) );
  SetFriends( ({ "grym_npc" }) );
}

int CheckWanted() {
  object who = this_player();
  if (who->GetInvis()) return 0;
  if (member_array(who->GetKeyName(), keys(Wanted)) != -1) {
    eventForce("follow" + who->GetKeyName());
    eventForce("yell You there! " + capitalize(who->GetKeyName()) + ", Stop!");
    return 1;
  }
  if (who->GetProperty("invader")) {
    eventForce("yell Invaders!");
    return 1;
  }
  return 0;
}
