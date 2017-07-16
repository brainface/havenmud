// modified version of zeddicus & syra's burlap bag
//  by mahkefel ~ 2010
// further changed for a bottle by torak ~ 2012
//
// turned into a lobster cage torak@haven 6/june/2017
//

#include <lib.h>
inherit LIB_TRAP;

static void create() {
  mapping inventory = ([]);
  trap::create();
  SetKeyName("cage");
  SetOpacity(0);
  SetId( "cage" );
  SetAdjectives( ({ 
    "lobster","wooden" 
  }) );
  SetShort("a wooden lobster cage");
  SetMass(150);
  SetMaterial("wood");
  SetValue(500);
  SetLong(
    "This is a wooden cage with a flat bottom and convex "
    "top with metal reinforcements at the cross sections. "
    "Durable and built to last, this lobster cage can "
    "comfortably fit one lobster. "
    "You could use it to 'capture' a lobster, 'look "
    "in' it to see what it cages and 'close' or 'open' it."
  );
  SetEscapeChance(2);
  SetMaxCapture(1);
  SetCanClose(1);
}

int CanCapture (object who, object target) {
  if (target->GetRace() != "lobster") {
    (who)->eventPrint("The cage is only meant for"
      " traping lobsters!");
    return 0;
  }
  if ((target)->GetLevel() > 10) {
    (who)->eventPrint("This lobster is far too wily"
      " to be captured by such a simple trap.");
    return 0;
  }
  else {
//    who->eventPrint(
//      nominative(who) +
//      " naively scuttles into the lobster cage!"
//      "The lobster barely evades your attempt to capture it!"
//    );
    return 1;
  }
}


// inventory always visible to look in
int inventory_visible() {
    return 1;
}

// append internal desc to external desc
//  (so display case is "transparent")

string GetExternalDesc() {
  string desc;
  desc = ::GetExternalDesc();
  desc += ::GetInternalDesc();
  return desc;
} 
