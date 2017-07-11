// modified version of zeddicus & syra's burlap bag
//  by mahkefel ~ 2010
// further changed for a bottle by torak ~ 2012

#include <lib.h>
inherit LIB_TRAP;

static void create() {
  mapping inventory = ([]);
  trap::create();
  SetKeyName("bottle");
  SetOpacity(0);
  SetId( "bottle" );
  SetAdjectives( ({"clear","small", "crystal"}) );
  SetShort("a small clear crystal bottle");
  SetMass(10);
  SetMaterial("natural");
  SetValue(25);
  SetLong("This is a small clear crystal bottle.  "
    "You could use it to 'capture' a bug, or 'look "
    "in' it to see what it cages."
  );
  SetEscapeChance(2);
  SetMaxCapture(1);
  SetCanClose(1);
}

int CanCapture (object who, object target) {
  if (target->GetShort() != "a lightning bug") {
    (who)->eventPrint("The bottle is only meant for"
      " traping lightning bugs!");
    return 0;
  }
  if ((target)->GetLevel() > 10) {
    (who)->eventPrint("The bug is far too wily"
      " to be captured by such a simple trap.");
    return 0;
  }
  else {
    //who->eventPrint(nominative(who) +
    //  " naively flies into the birdcage, and the door slams"
    //  " shut with a clang!");
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
