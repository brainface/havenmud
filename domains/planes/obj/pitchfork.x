/*
* mahkefel 3/22
* pit fiend weapon
*/
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("immense fiery pitchfork");
  SetShort("an immense fiery pitchfork");
  SetLong(
    "This pitchfork appears to be a simple farmer's pitchfork writ large,"
    " except for the black flames that flow from the tines, and the deep"
    " sense of corruption that seems to emanate from it."
  );

  SetId( ({"pitchfork"}) );
  SetAdjectives(({"fiery","pitchfork","immense"}));
  SetClass(50);
  SetDamagePoints(9000);
  SetDamageType(HEAT|PIERCE);
  SetHands(2);
  SetMass(400);
  SetMaterial("metal");
  SetRadiantLight(-10);
  SetRepairDifficulty(100);
  SetValue(8000);
  SetVendorType(VT_WEAPON);
  SetWeaponType("pole");
}

// throw nubbin outta the way.
int eventStrike(object who) {
  object wielder = environment();
  object room = environment(wielder);
  string *Exits;
  string NewLocation, OldLocation;
  int Strength, TargetStrength;
  // if wielder is 2x target's level, bump them,
  // but only if bumping is allowed.
  if (who->GetLevel() < wielder->GetLevel() / 2 )
  {
    if (room->GetProperty("no bump") || who->GetProperty("no bump")) {
      // bumping illegal, but target noob. no damage from weapon.
      return 0;
    }

    Strength = (int)wielder->GetStatLevel("strength") +
      random((int)wielder->GetStatLevel("agility") / 2);
    TargetStrength = (int)who->GetStatLevel("strength") +
      random( (int)who->GetStatLevel("agility") / 2 );
    if (Strength - TargetStrength > 5 + random(20)) {
      Exits = (string *)room->GetExits();
      Exits = filter(Exits,
        (: !(object)$(room)->GetDoor($1) ||
          !(object)$(room)->GetDoor($1)->GetClosed() :) );
      if( !sizeof(Exits) ) {
        message("system", "There is nowhere for "+(string)who->GetCapName()
        +" to go!", wielder );
          return item::eventStrike(who);
      }
      NewLocation = Exits[ random(sizeof(Exits)) ];
      NewLocation = room->GetExit(NewLocation);
      OldLocation = base_name(room);
      message("my_action", "You hurl "+(string)who->GetCapName()+" into "
        "the air!",
        wielder );
      message("other_action", "You are hurled into the air by "+
        (string)wielder->GetCapName()+"!",
        who);
      message("other_action", (string)wielder->GetCapName()+" hurls "+
        (string)who->GetCapName()+" into the air!",
        room, ({ who, wielder }) );
      if( !(int)who->eventMove(NewLocation) ) {
        message("other_action", (string)who->GetCapName()+" is bounced "
          "back into the room.", room, who);
        message("my_action", "You are bounced back to your original "
          "location.",
          who);
      } else {
        who->eventDescribeEnvironment(0);      
      }
    }
    return 0; // no damage.
  }
  return item::eventStrike(who);
}
