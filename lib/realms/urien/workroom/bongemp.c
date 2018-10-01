// The remainder of a really good time, man
// source from ~urien/workroom/bong.c

#include <lib.h>

inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("bong");
  SetId( ({ "bong" }) );
  SetAdjectives( ({ "giant", "mithril", "empty" }) );
  SetShort("an empty giant mithril bong");
  SetLong( "Once upon a time ago this bong had catnip in it. The "
           "charred remains of catnip lines the interior which "
           "leaves a quite pungeant odor. This thing is useless.");
  SetMass(2);
  SetValue(1);
 }