#include <lib.h>
#include "../grymxoria.h"
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("recruiter");
  SetShort("a recruiter for the brute squad");
  SetId( ({ "recruiter", "brute", "grym_npc" }) );
  SetLong(
    "This recruiter is wearing the regalia of the Grymxorian "
    "brute squad. The recruiter wanders about Gryxmoria spreading the "
    "news about the brute squad defending the town. "
    "Given time the recruiter could tell one about all the "
    "benefits of being a member."
  );
  SetAdjectives( ({ "recruiter", "for", }) );
  if(random(10) > 4)  SetGender("male");
    else SetGender("female");
  SetRace("nosferatu");
  RemoveLanguage("Enlan");
  SetLanguage("Blaodric", 100, 1);
  SetClass("fighter");
  SetLevel(30);
  SetMorality(-500);
  SetWander(25);
  SetCurrency("bloodgems", 100);
  SetLimit(1);
  SetAction(10, ({
    "!shout Join the Grymxorian brute squad!",
    "!shout Looking for Excitement and Adventure?  Then join "
    "the Grymxorian brute squad",
    "!shout Spoils and Plunder for every member of the Grymxorian "
    "squad!",
    "!shout Be a part of the winning team and Join the Grymxorian "
    "squad!",
    "!shout This isn't your father's brute squad!",
    "!shout Quick promotion and leadership opportunites available "
    "in the Grymxorian brute squad!",
    "!shout Join today before your town is sacked!",
    "!shout Weapon training available to all members of the "
    "Grymxorian brute squad!",
    "!shout Learn to be a soldier!",
  }) );
  SetInventory(  ([
    G_OBJ "guard_armour" : "wear mail",
    G_OBJ "blood_sword"  : "wield sword",
    G_OBJ "wall_shield"  : "wear shield on left arm",
  ]) );
}
