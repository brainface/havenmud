/* A wand of paralysis
 * To be used by Bandit Mage
 */
#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;
int Charges = 3;

static void create() {
  item::create();
  SetKeyName("stick");
  AddSave( ({ "Charges" }) );
  SetShort("a small stick");
  SetId( ({ "wand", "stick" }) );
  SetAdjectives( ({ "magic", "stick" }) );
  SetMass(20);
  SetVendorType(VT_MAGIC);
  SetLong("This foot long tree branch seems to be a rather useless piece "
         "of dead foliage.  Its component pieces seem paralyzed by age "
        "and lack of effective or constructive use.");
  SetProperty("special",
      "Use this wand to paralyze people.");
  SetValue(600);
  }

mixed eventUse(object me, string args) {
   string what, who;
   object victim;
  sscanf(args, "%s %s", what, who);
  if (!what || !(what == "paralyze")) {
    return "Use the wand for what?";
    }
  if (!who) {
     return "Use the wand against who?";
    }
  victim = present(who, environment(me));
  if (!victim) {
     return "No such person.";
    }
  send_messages("aim",
   "$agent_name $agent_verb $agent_possessive wand at $target_name.",
    me, victim, environment(me));
  if (Charges < 1) {
     send_messages("fizzle",
      "$agent_possessive_noun wand fizzles with a SPUTTER.",
       me, 0, environment(me) );
     return 1;
     }

  Charges--;
  send_messages("paralyze",
    "$agent_name $agent_verb $target_name.",
      me, victim, environment(me) );
    victim->SetParalyzed(10);
    return 1;
  }

int GetCharges() { 
   return Charges;
  }
