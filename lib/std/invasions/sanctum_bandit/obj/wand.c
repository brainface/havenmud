/* A wand of paralysis
 * To be used by Bandit Leader
 */

#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;
int Charges = 4;

static void create() {
  item::create();
  SetKeyName("stick");
  SetShort("a small stick");
  SetId( ({ "wand", "stick" }) );
  SetAdjectives( ({ "magic", "small" }) );
  SetLong(
    "This foot long tree branch seems to be a rather useless piece "
    "of dead foliage.  Its component pieces seem paralyzed by age "
    "and lack of effective or constructive use."
  );
  AddSave( ({ "Charges" }) );
  SetDamagePoints(300);
  SetMass(20);
  SetValue(60);
  SetMaterial("natural");
  SetRepairDifficulty(99);
  SetVendorType(VT_MAGIC);
  SetProperty("magic",
      "Use this wand to paralyze people.");
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
  Charges--;
  if ( (Charges < 1) || (userp(me) && (!random(3)))) {
     send_messages("fizzle",
      "$agent_possessive_noun wand fizzles with a SPUTTER.",
       me, 0, environment(me) );
     return 1;
     }

   if (victim->GetMagicResistance() > random(50)) {
     send_messages("ignore",
       "$target_name $target_verb $agent_possessive_noun attack.",
         me, victim, environment(me));
      return 1;
    }
  send_messages("paralyze",
    "$agent_name $agent_verb $target_name.",
      me, victim, environment(me) );
    victim->SetParalyzed(10);
   if (!Charges) { SetValue(20); }
    return 1;
  }

int GetCharges() { 
   return Charges;
  }
