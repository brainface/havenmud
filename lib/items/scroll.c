/*  A scroll lib */
#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;
int eventRead();
string SetSpell(string);
string GetSpell();
private string Spell = "missile";

static void create() {
  item::create();
  SetKeyName("scroll");
  SetShort("a scroll");
  SetLong("This is a coiled piece of parchment with Arcane "
          "looking words on it.");
  SetRead("default", (: eventRead :) );
}

string SetSpell(string x) {
  Spell = x;
  SetProperty("magic", "This is a spell scroll of " + Spell + ".");
  return Spell;
  }

string GetSpell() { return Spell; }

int eventRead() {
  if (this_player()->eventLearnSpell(GetSpell())) {
    message("system", 
       "As you read the scroll, you gain knowledge of " + Spell + ".",
        this_player() );
   eventDestruct();
   return 1;
   }
  message("system",
      "You fail to gain any knowledge from " + GetShort() + ".",
       this_player() );
  return 0;
  }
