#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;
int Charges = 15;

static void create() {
  item::create();
  SetKeyName("stick");
  AddSave( ({ "Charges" }) );
  SetShort("a small stick");
  SetId( ({ "wand", "stick" }) );
  SetAdjectives( ({ "magic", "small" }) );
  SetDamagePoints(100);
  SetMass(10);
  SetVendorType(VT_MAGIC);
  SetLong("This eight inch piece of wood has a thin layer of bark "
    "covering it and making it appear to be a dull white in colour"
    ".  It is not very straight but appears to be able to be "
    "aimed at someone.");
  SetProperty("magic",
      "Use this wand to zap people.");
  SetValue(1600);
  }

mixed eventUse(object me, string args) {
   int damage = (50+random(75));
   string what, who;
   object victim;
  sscanf(args, "%s %s", what, who);
  if (!what || !(what == "zap")) {
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
  if ( (Charges < 1) || (userp(me) && (!random(2)))) {
     send_messages("fizzle",
      "$agent_possessive_noun wand fizzles with a SPUTTER.",
       me, 0, environment(me) );
     return 1;
     }

   if (victim->GetMagicResistance() > 75) {
     send_messages("ignore",
       "$target_name $target_verb $agent_possessive_noun attack.",
         me, victim, environment(me));
      return 1;
    }
  send_messages("zap",
    "$agent_name $agent_verb $target_name with a bolt of lightning.",
      me, victim, environment(me) );
    victim->eventReceiveDamage(victim,SHOCK,damage,0);
   if (!Charges) { SetValue(20); }
    return 1;
  }

int GetCharges() { 
   return Charges;
  }
