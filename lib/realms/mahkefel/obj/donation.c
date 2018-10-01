/*
 * A charity donation box
 *
 * Players can leave things for poor noobs
 * to use. It has a level limit to prevent
 * highbies from getting things from it,
 * as well as a value limit to prevent
 * Arcturus's weapons from going in there.
 *
 * It checks wealth and WC. Some hilarious items (unicorn horns)
 *  will perfectly bypass this check.
 * It ain't perfect, I'm not checking every eventuality.
 *
 * Mahkefel 2012 something
 */
#include <lib.h>
inherit LIB_STORAGEBOX;

mixed CanPutInto(object who, object item);
mixed CanGetFrom(object who, object item);

private int MaxLevel = 10;
private int MaxValue = 800;
private int MaxWC = 20;

int SetMaxWC(int value) {MaxWC=value;}
int SetMaxLevel(int value) {MaxLevel=value;}
int SetMaxValue(int value) {MaxValue=value;}

int GetMaxWC() {return MaxWC;}
int GetMaxLevel() {return MaxLevel;}
int GetMaxValue() {return MaxValue;}


static void create() {
  ::create();
  SetKeyName("donation box");
  SetId( ({ "box" }) );
  SetAdjectives( ({ "donation" }) );
  SetShort("a donation box");
  SetLong(
    "A heavy steel-framed box with an open top, it seems to have "
    "taken some abuse over the years judging from the many "
    "dents and rust climbing up the sides. "
    "A note on the side warns against abusing the charity or "
    "storing anything too valuable here."

  );
  SetBoxID("mahk_charity"); // CHANGE THIS IF COPYING.
  SetPreventGet("The box seems to be affixed to the ground.");
  SetMass(5000);
  SetMaterial( ({ "metal" }) );
  SetCanClose(0);
  SetMaxCarry(1000000);
  
  SetMaxWC(20);
  SetMaxValue(800);
  SetMaxLevel(10);
}

mixed CanGetFrom(object who, object item) {
  // Highbies can't use, but imms can
  if (!creatorp(who)) {
    if (who->GetLevel() > MaxLevel) {
      return "You are much too experienced to need charity!";
    }
  }
  // ZOMBIES GO AWAY.
  if (!creatorp(who) && !playerp(who) ) {
    who->eventForce("emote looks confused.");
  }
  return ::CanGetFrom(who,item);
}

mixed CanPutInto(object who, object item) {
    object env;
    object array items = all_inventory();
       
    if( item == this_object() ) {
        return "You cannot change the laws of physics.";
    }

    if (sizeof(items) > 24) {
      return "The box is already crammed full of junk!";
    }    
    
    // refuse elemental longswords
    if( item->GetValue() > GetMaxValue() ) {
      return "That is far too valuable to just give away!";
    }
    
    if (item->GetClass() && item->GetClass() > GetMaxWC() ) {
      return "They'll poke their eyes out with that! It's unsafe!";
    }
    
    env = environment();
    if( env != this_player() && env != environment(this_player()) ) {
        return "It is not within reach.";
    }
    return ::CanPutInto(who,item);
}

int CanReceive(object ob) {
    object array items = all_inventory();
    if (sizeof(items) > 24) {
      return 0;
    }    
    return ::CanReceive(ob);
}

