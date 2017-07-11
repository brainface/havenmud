// Undead invasion of Haven
// Created when a vampire's target dies
// Duuk
// Edited: Laoise, 2005

#include <lib.h>
inherit LIB_INVADER;

static void create() {
  invader::create();
  SetKeyName("vampyre");
  SetShort("a vampyre");
  SetId( ({ "vampyre", "undead_inv" }) );
  SetLong(
    "A vampyre is a newly dead corpse raised by a vampire."
  );
  SetRace("human");
  SetGender("male");
  SetClass("fighter");
  SetLevel(5);
  SetUndead(1); 
  SetNoCorpse(1);
  SetMorality(-100);
  SetFriends( ({ "undead_inv" }) );
}
